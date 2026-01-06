#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_SCL_PIN 43
#define OLED_SDA_PIN 44

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int COL_COUNT = 17;
const int ROW_COUNT = 6;

int colPins[COL_COUNT] = {48, 35, 36, 37, 38, 2, 1, 4, 5, 6, 7, 15, 16, 12, 17, 18, 11};
int rowPins[ROW_COUNT] = {9, 3, 8, 13, 21, 47};

unsigned long lastScanTime = 0;
const unsigned long SCAN_INTERVAL_MICROS = 2000; 

bool lastWasPressed = false;
int lastColIndex = -1;
int lastRowIndex = -1;

void setup() {
  Wire.begin(OLED_SDA_PIN, OLED_SCL_PIN);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    for(;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Idle");
  display.display();
  for (int i = 0; i < COL_COUNT; i++) {
    pinMode(colPins[i], OUTPUT);
    digitalWrite(colPins[i], LOW);
  }
  for (int i = 0; i < ROW_COUNT; i++) {
    pinMode(rowPins[i], INPUT_PULLDOWN);
  }
}

void loop() {
  unsigned long currentTime = micros();
  if (currentTime - lastScanTime >= SCAN_INTERVAL_MICROS) {
    lastScanTime = currentTime;
    scanMatrix();
  }
}

void scanMatrix() {
  bool currentIsPressed = false;
  int currentCol = -1;
  int currentRow = -1;
  for (int c = 0; c < COL_COUNT; c++) {
    digitalWrite(colPins[c], HIGH);
    delayMicroseconds(5); 
    for (int r = 0; r < ROW_COUNT; r++) {
      if (digitalRead(rowPins[r]) == HIGH) {
        currentIsPressed = true;
        currentCol = c;
        currentRow = r;
      }
    }
    digitalWrite(colPins[c], LOW);
  }

  bool stateChanged = false;
  
  if (currentIsPressed != lastWasPressed) {
    stateChanged = true;
  }
  else if (currentIsPressed && (currentCol != lastColIndex || currentRow != lastRowIndex)) {
    stateChanged = true;
  }
  if (stateChanged) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextSize(1);

    if (currentIsPressed) {
      display.println("Key Pressed:");
      display.setTextSize(2);
      display.setCursor(0, 20);
      display.print("C");
      display.print(currentCol);
      display.print(" R");
      display.print(currentRow);
      display.setTextSize(1);
      display.setCursor(0, 45);
      display.print("GPIO: ");
      display.print(colPins[currentCol]);
      display.print(" / ");
      display.print(rowPins[currentRow]);
    } else {
      display.println("Idle");
    }
    display.display();
  }
  lastWasPressed = currentIsPressed;
  lastColIndex = currentCol;
  lastRowIndex = currentRow;
}