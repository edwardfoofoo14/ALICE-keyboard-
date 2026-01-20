#include <Arduino.h>
#include <USB.h>
#include <USBHIDKeyboard.h>
#include <USBCDC.h>

const uint16_t SCAN_RATE_HZ = 1000;
const uint16_t DEBOUNCE_MS = 5;
#define LED_PIN 10
#define NUM_ROWS 6
#define NUM_COLS 17

const uint8_t COL_PINS[NUM_COLS] = { 
  48, 35, 36, 37, 38, 2, 1, 4, 5, 6, 7, 15, 16, 12, 17, 18, 11 
};

const uint8_t ROW_PINS[NUM_ROWS] = { 
  9, 3, 8, 13, 21, 47 
};


#define FN_KEY_VAL 0xFF  // internal marker
const uint8_t KEY_MAP[NUM_ROWS][NUM_COLS] = {
  // ROW1 (GPIO9)
  {KEY_ESC, KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11, KEY_F12, 0, 0, KEY_DELETE, 0},
  
  // ROW2 (GPIO3)
  {'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 0, KEY_BACKSPACE, KEY_PAGE_UP, 0},
  
  // ROW3 (GPIO8)
  {KEY_TAB, 'q', 'w', 'e', 'r', 't', 0, 'y', 'u', 'i', 'o', 'p', '[', ']', '\\', KEY_PAGE_DOWN, 0},
  
  // ROW4 (GPIO13)
  {KEY_CAPS_LOCK, 'a', 's', 'd', 'f', 'g', 0, 'h', 'j', 'k', 'l', ';', '\'', 0, KEY_RETURN, 0xCE, 0},
  
  // ROW5 (GPIO21)
  {KEY_LEFT_SHIFT, 'z', 'x', 'c', 'v', 'b', 0, 'n', 'm', ',', '.', '/', KEY_RIGHT_ALT, 0, KEY_RIGHT_SHIFT, KEY_UP_ARROW, 0},
  
  // ROW6 (GPIO47)
  {KEY_LEFT_CTRL, 0, KEY_LEFT_ALT, 0, ' ', KEY_LEFT_GUI, 0, 0, ' ', 0, KEY_RIGHT_CTRL, 0, FN_KEY_VAL, 0, KEY_LEFT_ARROW, KEY_DOWN_ARROW, KEY_RIGHT_ARROW}
};

USBHIDKeyboard Keyboard;

uint8_t keyState[NUM_ROWS][NUM_COLS] = {0}; 
uint8_t prevKeyState[NUM_ROWS][NUM_COLS] = {0};
uint32_t lastScanTime = 0;
uint32_t scanIntervalUs;
void scanMatrix();
void processKeyChanges();


void setup() {
  Serial.begin(115200);
  // Keep LED pin pulled low when not in use
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  scanIntervalUs = 1000000 / SCAN_RATE_HZ;
  
  for (uint8_t col = 0; col < NUM_COLS; col++) {
    pinMode(COL_PINS[col], OUTPUT);
    digitalWrite(COL_PINS[col], LOW);
  }
  
  for (uint8_t row = 0; row < NUM_ROWS; row++) {
    pinMode(ROW_PINS[row], INPUT_PULLDOWN);
  }

  Keyboard.begin();
  USB.begin();
  delay(100);
  lastScanTime = micros();
}

void loop() {
  uint32_t currentTime = micros();
  if (currentTime - lastScanTime >= scanIntervalUs) {
    lastScanTime = currentTime;
    scanMatrix();
    processKeyChanges();
  }
}


void scanMatrix() {
  for (uint8_t col = 0; col < NUM_COLS; col++) {
    digitalWrite(COL_PINS[col], HIGH);
    delayMicroseconds(4); // Wait till signal stabilize due to line capacitance
    
    for (uint8_t row = 0; row < NUM_ROWS; row++) {
      bool pressed = digitalRead(ROW_PINS[row]);
      
      if (pressed) {
        // debouncing increment counter limited at 255 to prevent overflow
        if (keyState[row][col] < 255) keyState[row][col]++;
      } else {
        keyState[row][col] = 0;
      }
    }
    digitalWrite(COL_PINS[col], LOW);
  }
}

void processKeyChanges() {
  uint8_t debounceThreshold = (DEBOUNCE_MS * SCAN_RATE_HZ) / 1000;
  if (debounceThreshold < 1) debounceThreshold = 1;
  
  for (uint8_t row = 0; row < NUM_ROWS; row++) {
    for (uint8_t col = 0; col < NUM_COLS; col++) {
      uint8_t keyCode = KEY_MAP[row][col];
      if (keyCode == 0) continue;
      bool currentPressed = (keyState[row][col] >= debounceThreshold);
      bool previousPressed = prevKeyState[row][col];
      
      if (currentPressed && !previousPressed) {
        if (keyCode == FN_KEY_VAL) {
            // FN placeholder for LED
            Serial.println(F("FN pressed"));
        } else {
            Keyboard.press(keyCode);
        }
        prevKeyState[row][col] = 1;
      }
      else if (!currentPressed && previousPressed) {
        if (keyCode == FN_KEY_VAL) {
        } else {
            Keyboard.release(keyCode);
        }
        prevKeyState[row][col] = 0;
      }
    }
  }
}