# SELENE

This is my SELENE, my project for the Blueprint Hack Club event!

The board uses an ALICE layout with added F rows, inspired by Dante from Devil May Cry (my favourite character). The case follows a stacked acrylic design, taking inspiration from Adelheid and Arisu, both ALICE style keyboards.

The stacked acrylic case consists of 10 machine cut acrylic plates, each 3 mm thick and A3 sized, screwed together. I chose this construction because acrylic produces a clackier sound profile and is more cost effective than many alternative case materials.

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
- Cut plates 1–10 from the 3 mm acrylic
- Cut the main plate from the 2 mm acrylic

---

## Assembly Instructions
1. Stack the numbered plates from bottom to top  
   - Plate 1 goes first, followed by plate 2, and so on
2. On plate 2:
   - Secure the daughterboard
   - Add Poron gaskets to the protruding sections
3. Place the keyboard plate on top with the PCB attached
4. Apply Poron gaskets again on the top surface
5. Continue stacking plates 3–10
6. Secure the entire assembly using the screws, ideally with the nuts on the bottom side

---

## Important Notes
- Attach stabilisers and switches to the plate and PCB before assembly, as there is no direct mounting mechanism between them
- Plates 2 and 10 include my personal designs  
  - You may replace these with your own or remove them entirely if desired

---

## Simulation
The Wokwi simulation follows the exact ESP32 pinout shown in the KiCad schematic:

https://github.com/user-attachments/assets/cd191653-9d43-4bff-b9b6-e710f8436f32
