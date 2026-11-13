# B1TWatch
### A low power, Li-ion/LiPo battery powered binary watch with an exposed PCB, automatic brightness, and interactive settings based on a Seeed Studio XIAO MG24 Sense
<img width="509" height="433" alt="image" src="https://github.com/user-attachments/assets/1a8aa88f-2b9a-4127-970f-969d3fdcbb0a" />

## 🛠️ Size and design:
The board is 5 cm wide and 4.25 cm tall, with chamfered corners, and is meant to be press-fitted into a strap with a battery. For customization purposes it has an empty space on its bottom left corner reserved for graphics or extra components. By default the board has no silkscreen besides settings markings in "Silkscreen" font.

## ⚡ Power:
Because the board is using a Seeed Studio XIAO MG24 Sense, any battery that complies with [this guide](https://wiki.seeedstudio.com/xiao_mg24_getting_started/#battery-usage) can be connected to the JST connector present on the board.

**However the user needs to make sure that the positive and negative terminals on the female JST connector of the battery are in the right orientation by confirming that the side of the male JST connector on the board that will be connected to the positive wire has a trace connecting it to the XIAO. Otherwise permanent damage may be caused**

## 🎨 Customization:
The provided .ino file has lots of comments that explain what each part does and what values to change for customization. Along software, the PCB can be customized as well, mainly by using the reserved empty space. However if extra electronic components are added, the XIAO's current limits have to be accounted for.

## ⚙️ Manual:
In this manual, the rotary encoder will be referred to as a watch crown.
### Overview:
B1TWatch has 4 modes: Idle, Time, Configuration, and Calibration.
* Idle mode puts the XIAO into a power saving sleep mode and keeps its RTC active.
* Time mode shows time and opens access to Configuration and Calibration modes.
* Configuration mode lets you manage timers, alarms, and stopwatches, and change watch settings.
* Calibration mode lets you calibrate the watch manually or via Bluetooth connection to a smartphone, laptop, or a PC.

### Configuration Mode and Labels:
To access the Configuration mode, press the crown once. You will see a lit up bar indicating the chosen setting menu.

<img width="1604" height="91" alt="image" src="https://github.com/user-attachments/assets/22839109-b601-4f11-a585-07ea4179cb71" />

Every configuration setting is labeled with its initial from left to right in this order:
* **T**imer
* **A**larm
* **S**topwatch
* **V**olume/**F**requency
* **B**rightness
* **F**ormat

To open any setting menu, rotate the crown either way until the lit up LED bar is in line with the corresponding setting label, and press the crown once.

To exit out of any setting menu at any moment and discard all changes, press and hold the crown for 1 second by default.

### Timer:
To set a timer, enter the Configuration mode and select the Timer menu, then press the crown once. The bottom row of LEDs will light up indicating that the current selected time option is seconds. Rotate the crown either way to adjust desired time in the selected row. Press the crown once to confirm changes and select the row above, or press 2 times to select the row below. Once the desired time is set, select the hour row and press the crown once to start the timer. When the timer is active, its countdown will be displayed by default in Time mode until it is triggered or canceled. Rotate the crown in either direction to switch between viewing the current time and the timer countdown.

To change the active timer length, open the Timer menu and follow timer setup steps and set the new desired time, the active timer will keep counting down to the new time without restarting. To cancel the active timer, change its length to 0 seconds.

Note: If the new timer length is equal to or smaller than the time which it has already been active for, it will be triggered immediately.

### Alarm:
The Alarm menu has multiple steps. To revert any step past the 1st one and return to the previous step, double press the crown on the lowest selected row (if applicable).

#### Step 1:
Enter the Configuration mode and open the Alarm menu. The first step of alarm setup will be selected in this step select one out of 64 possible alarms using the crown and the bottom row of the matrix, counting in binary. If a selected alarm exists, the leftmost LED on the top row will light up. Press the crown to continue.

#### Step 2:
The bottom row of LEDs will light up indicating that the current selected time option is seconds. Rotate the crown either way to adjust desired time in the selected row. Press the crown once to confirm changes and select the row above, or press 2 times to select the row below. Once the desired time is set, select the hour row and press the crown once to continue.

#### Step 3:
Add the active weekdays for the alarm by rotating the crown and counting in binary to the corresponding weekday number, with Monday being 1 and Sunday being 7. Press the crown once to add an active day. When selecting an already active weekday, the leftmost LED on the top row will light up. Press the crown once to remove the weekday. To start will all weekdays active and subtract them instead, select weekday 0 and press the crown once. All LEDs will light up and counting will be indicated by LEDs that are off. Select weekday 0 again and press the crown once to switch back to the addition mode. Switching between these 2 modes discards changes on this step.

To apply the alarm, rotate the crown past weekday 7, an indication bar on the middle row will be displayed. Press the crown once to confirm all changes. If the bar flashes and nothing else happens, it means no weekdays are active. Otherwise an animation will be played and B1TWatch will switch to Time mode, indicating a successful operation.

To delete an alarm, select an alarm following instructions from [step 1](#step-1), set its time to 0 seconds and press the crown once. Setting selection menu will then be opened.

### Stopwatch:
To start a stopwatch, enter the Configuration mode and select the Stopwatch menu, then press the crown once. First, set a desired countdown after which the stopwatch will start. The bottom row of LEDs will light up indicating that the current selected time option is seconds. Rotate the crown either way to adjust desired countdown time in the selected row. Press the crown once to confirm changes and select the row above, or press 2 times to select the row below. Once the desired countdown time is set, select the hour row and press the crown once to start the countdown. To pause or resume the stopwatch, press the crown once. To reset the stopwatch and go back to countdown selection, double press the crown while the stopwatch is paused.

### Volume/Frequency:
To change volume and/or frequency of the piezo buzzer, enter the Configuration mode and select the Volume/Frequency menu, then press the crown once. Rotate the crown either way to adjust desired volume in increments of 10%. Once the desired time is set, select the hour row and press the crown once to continue. Then rotate the crown either way to adjust desired frequency in hHz, and press the crown once to apply changes, or twice to return to volume setting.

### Brightness:
To change the minimum and maximum brightness, enter the Configuration mode and select the Brightness menu, then press the crown once. Rotate the crown either way to adjust desired minimum brightness in increments of 10% and press the crown once to continue. Then rotate the crown either way to adjust desired maximum brightness in increments of 10%, and press the crown once to apply changes, or twice to return to minimum brightness setting.

### Format:
To change the time format, enter the Configuration mode and select the Format menu, then press the crown once. The middle row will then show a binary 12 or 24, indicating the corresponding current time format. Rotate the crown either way to change it, and press it once to confirm changes.

## BOM:
| Reference | Qty | Value | Exclude from Board | Footprint | Description | MPN | Datasheet | DigiKey link | Unit price in USD as of November 13, 2026 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| BT1 | 1 |  | Excluded from board |  | 3.7 V Lithium-Ion Battery Rechargeable (Secondary) 500mAh | 1578 | https://cdn-shop.adafruit.com/product-files/1578/C1854+PKCell+Datasheet+Li-Polymer+503035+500mAh+3.7V+with+PCM.pdf | https://www.digikey.com/en/products/detail/adafruit-industries-llc/1578/5054539 | 7.95000 |
| BZ1 | 1 |  |  | Buzzer_Beeper:Buzzer_Murata_PKLCS1212E | Buzzers Transducer, Externally Driven Piezo 1.5 V 4kHz 84dB @ 1.5V, 10cm Surface Mount Solder Pads | PKLCS1212E4001-R1 | https://pim.murata.com/asset/pim4/piezoelectricSounderBuzzer/SPEC_PKLCS1212E4001-R1_PDF_PIEZOELECTRICSOUNDERBUZZER?lastModifiedDatetime=20250707192319 | https://www.digikey.com/en/products/detail/murata-electronics/PKLCS1212E4001-R1/1219314 | 1.24000 |
| D1-D18 | 18 |  |  | LED_SMD:LED_0603_1608Metric | Yellow 590nm LED Indication - Discrete 2V 0603 (1608 Metric) | APT1608SYC/J3-AMT | https://www.kingbrightusa.com/images/catalog/SPEC/APT1608SYC-J3-AMT.pdf | https://www.digikey.com/en/products/detail/kingbright/APT1608SYC-J3-AMT/17969017 | 0.60800 |
| J1 | 1 |  |  | Connector_JST:JST_PH_S2B-PH-SM4-TB_1x02-1MP_P2.00mm_Horizontal | Connector Header Surface Mount, Right Angle 2 position 0.079" (2.00mm) | S2B-PH-SM4-TB | https://www.jst-mfg.com/product/pdf/eng/ePH.pdf | https://www.digikey.com/en/products/detail/jst-sales-america-inc/S2B-PH-SM4-TB/926655 | 0.49000 |
| Q1-Q3 | 3 |  |  | Package_TO_SOT_SMD:SOT-23 | N-Channel 20 V 2.3A (Ta) 500mW (Ta) Surface Mount PG-SOT23 | BSS806NEH6327XTSA1 | https://www.infineon.com/assets/row/public/documents/24/49/infineon-bss806ne-ds-en.pdf | https://www.digikey.com/en/products/detail/infineon-technologies/BSS806NEH6327XTSA1/5959969 | 0.42000 |
| R1-R6 | 6 | 56 |  | Resistor_SMD:R_0603_1608Metric | 56 Ohms ±1% 0.1W, 1/10W Chip Resistor 0603 (1608 Metric) Moisture Resistant Thick Film | RC0603FR-0756RL | https://yageogroup.com/content/datasheet/asset/file/PYU-RC_GROUP_51_ROHS_L | https://www.digikey.com/en/products/detail/yageo/RC0603FR-0756RL/727301 | 0.02800 |
| R7 | 1 | 10k |  | Resistor_SMD:R_0603_1608Metric | 10 kOhms ±5% 0.1W, 1/10W Chip Resistor 0603 (1608 Metric) Moisture Resistant Thick Film | RC0603JR-0710KL | https://yageogroup.com/content/datasheet/asset/file/PYU-RC_GROUP_51_ROHS_L | https://www.digikey.com/en/products/detail/yageo/RC0603JR-0710KL/726700 | 0.10000 |
| R8 | 1 |  |  | OptoDevice:R_LDR_5.1x4.3mm_P3.4mm_Vertical | Photo cell (CdS photoresistor) | 161 | https://cdn-learn.adafruit.com/downloads/pdf/photocells.pdf | https://www.digikey.com/en/products/detail/adafruit-industries-llc/161/7244927 | 0.98000 |
| R9 | 1 | 1k |  | Resistor_SMD:R_0603_1608Metric | 1 kOhms ±1% 0.1W, 1/10W Chip Resistor 0603 (1608 Metric) Moisture Resistant Thick Film | RC0603FR-071KL | https://yageogroup.com/content/datasheet/asset/file/PYU-RC_GROUP_51_ROHS_L | https://www.digikey.com/en/products/detail/yageo/RC0603FR-071KL/726843 | 0.11000 |
| SW1 | 1 |  |  | KiCad_PEC11S:PEC11S9213KS0015 | Rotary Encoder Mechanical 15 Quadrature (Incremental) Vertical | PEC11S-9213K-S0015 | https://www.bourns.com/docs/Product-Datasheets/PEC11S.pdf | https://www.digikey.com/en/products/detail/bourns-inc/PEC11S-9213K-S0015/3780156 | 3.64000 |
| U1 | 1 |  |  | New_XIAO_Series_Footprints:XIAO-MG24-SMD | Seeed Studio XIAO MG24 Sense | 102010610 | https://files.seeedstudio.com/Bazaar/product_pdf/102010590.pdf | https://www.digikey.com/en/products/detail/seeed-technology-co-ltd/102010610/25835832 | 10.90000 |
