# SELENE

This is my SELENE, my project for the Blueprint Hack Club event!

The board uses an ALICE layout with added F rows, it is inspired by Dante from Devil May Cry (my favourite character). It uses a stacked acrylic format which I took inspiration from Adelheid, and Arisu which are both Alice keyboards. The stacked acrylic mentioned is a collection of 10, 3mm, A3 sized, machine cut acrylic plates screwed together, I chose this method in particular because the material will generate a "clackier" sound profile and is also more cost effective that other methods.

---

## Files Included
- PCB  
- Plate  
- Case 
- Simulation code and diagram 

Cool graphics showing each layers of the acrylic
![kbgif](https://github.com/user-attachments/assets/0bb15f28-e83b-459c-93e2-d73cd470ae87)

---

## PCB

Note: it is quite rudimentary because a keyboard isn't the most complicated thing in the world.

![PCB Layout](https://github.com/user-attachments/assets/88e76a02-d105-4d6d-bdbd-e832759f43a7)

Overview of the schematic

![Schematic](https://github.com/user-attachments/assets/82593646-6d9b-4115-b2e0-ee5dc3088dde)

---

## Plate

Note: The plate will be shinier in real life :D

![Plate](https://github.com/user-attachments/assets/3d7f8136-6c32-4ebe-b1a6-5192f934c024)

---

## Case

![Case](https://github.com/user-attachments/assets/3a69d9f0-f8ed-49b9-bae0-51f5bfe891f6)

Note:
- Both the plate and case are provided as DXF files, and dimensions may still be adjusted.

---

## Parts Required
- 10x A3 acrylic sheets (3 mm)
- 1x A3 acrylic sheet (2 mm)
- Poron gaskets (3 mm thickness)
- 6x M5 x 35 mm screws
- 6x M5 nuts

---

## Cutting Instructions
- Use the DXF files located in the dxf folder
- Cut plates 1 to 10 from the 3 mm acrylic
- Cut the main plate from the 2 mm acrylic

---

## Assembly Instructions
1. Stack the numbered plates from bottom to top  
2. On plate 2:
   - Secure the USB C breakout board
   - Add Poron gaskets to the protruding sections
3. Place the keyboard plate on top with the PCB already attached (switches snapped into respective holes in the plate)
4. Apply adhesive Poron gaskets again on the top surface
5. Continue stacking plates 3 to 10
6. Secure the entire assembly using the screws, ideally with the nuts on the bottom side. The screws should skewer through the whole width of the keyboard.

---

## Important Notes
An important thing to note would be to afix your stabilisers switches to the plate and PCB before assembly as there is nothing to join the pcb and plate together. Also for plate 2 and 10 there are my personal designs, you can add your own if you want or just make sure you remove it if you don't want my design.

---

## Simulation
The Wokwi simulation follows the exact ESP32 pinout shown in the KiCad schematic:

https://github.com/user-attachments/assets/cd191653-9d43-4bff-b9b6-e710f8436f32

---

## Wiring
The wiring is extremely simple. Just connect the cables between the keyboard PCB and USB-C breakout board following the labels on the silkscreen

Depending on the type of USB-C breakout boards used, CC1 and CC2 pins may or may not require 5.1kΩ pull down. The Sparkfun boards have two resistors that are already soldered.
![Wiring Diagram](/misc/wiringDiagram.png)

## Bill of Material

Note: The prices in USD are converted as of 7 January 2026 and prices may fluctuate

| Category | Item Name | Part Number / File Name | Link | Vendor | Quantity | Total Price (USD) |
|---|---|---|---|---|---|---|
| Electronics | ESP32-S3-WROOM-1-N16-R2 | ESP32-S3-WROOM-1-N16-R2 | [Link](https://shopee.com.my/ESP32-S3-ESP32-S3-WROOM-1-1U-ESP32-S3-MINI-1U-4MB-8MB-16MB-N4-N4R2-N4R8-N8-N8R2-N8R8-N16-N16R2-N16R8-WiFi-Ble-5.0-Module-i.1649836180.43173884048) | Shopee | 1x | 6.53 |
| Electronics | SK6812 MINI-E | | [Link](https://shopee.com.my/100PCS-SK6812-MINI-E-RGB-(Similar-WS2812B)-SK6812-3228-SMD-Pixels-LED-Chip-Individually-Addressable-Full-Color-DC-5V-i.201200871.29163981070) | Shopee | 100x | 2.80 |
| Electronics | 1206 100nF Capacitor | | [Link](https://shopee.com.my/100pcs-1206-3216-SMD-Chip-Ceramic-Capacitor-1NF-2.2NF-10NF-22NF-100NF-1uF-2.2uF-4.7uF-10uF-22uF-47uF-100uF-6.3V-10V-16V-25V-50V-i.1649836180.51152484650) | Shopee | 100x | 0.35 |
| Electronics | Hotswap Sockets | | [Link](https://shopee.com.my/redsunaa-Hot-Swap-Socket-For-Kailh-CPG151101S11-for-Mechanical-Keyboard-Switch-Pcb-Base-i.1336977141.27113734076) | Shopee | 100x | 9.95 |
| Electronics | USB-C Breakout Board | | [Link](https://shopee.com.my/Pcbfun-USB-Type-C-Connector-Board-DIY-3.1-Serial-Basic-Breakout-Female-Connector-Type-C-Breakout-Board-for-Data-Line-Wire-Cable-Transfer-i.175472467.29872006322) | Shopee | 1x | 0.80 |
| Production | PCB | gerbers.zip | | JLCPCB | 1x | 23.00 |
| Fasteners | M5*35mm Hex Screws | | [Link](https://shopee.com.my/Button-Head-Screw-Black-304-Stainless-Steel-SHINY-SURFACE-Allen-Bolt-DIN7380-Skru-Ellenkey-Hex-Socket-Button-Head-Screw-ISO7380-SUS-Black-304-Stainless-Steel-Allen-Key-Screw-Mushroom-Skru-M2-M2.5-M3-M4-M5-M6-M8-*-L3-60mm-(ZHX-LD-MY-1)-i.1617822917.41220311575) | Shopee | 10x | 3.55 |
| Fasteners | M5 Nuts | | [Link](https://shopee.com.my/-HKH-Hexagon-Nut-M2-M2.5-M2.6-M3-M3.5-M4-M5-M6-M8-M10-M12-Black-arbon-Steel-Hexagon-Nut-Screw-Cap-i.1435573023.27623483039) | Shopee | 50x | 0.55 |
| Misc | Stabilisers | | [Link](https://shopee.com.my/Kelowna-Link-Studio-PCB-Screw-in-Stabilizers-Mechanical-Keyboard-i.71961069.12272946569) | Shopee | 1x | 7.40 |
| Misc | Gaskets | | [Link](https://shopee.com.my/Gasket-Strip-Poron-black-only-i.1034684783.25753214842) | Shopee | 1x | 3.20 |
| Misc | Switches | | [Link](https://shopee.com.my/Outemu-Honey-Peach-Silent-Linear-Switch-for-Mechanical-Keyboards-i.72068395.11794425429) | Shopee | 82x | 22.90 |
| Shipping | PCB Shipping | E-POST | | JLCPCB | 1x | 9.87 |
| Shipping | Switches Shipping | SPX Express International | | Shopee | 1x | 0.00 |
| Shipping | Electronics Shipping | SPX Express International | | Shopee | 4x | 5.20 |
| Shipping | Fasteners Shipping | SPX Express International | | Shopee | 2x | 2.60 |
| Shipping | Gaskets Shipping | SPX Express | | Shopee | 1x | 1.30 |
| | | | *Do take note this list excludes some parts that hack club isn't paying for, required parts to build the keyboard is in the excluded list in the readme* | | **Grand Total:** | **100.00** |


## Excluded Items

- Keycaps
- Diodes
- 4.7k resistor
- 10uF capacitors
- A3 3mm acrylic plates