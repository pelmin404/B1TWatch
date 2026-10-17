# B1TWatch
### A low power, Li-ion/LiPo battery powered binary watch with an exposed PCB, automatic brightness, and interactive settings based on a Seeed Studio XIAO MG24 Sense
<img width="509" height="433" alt="image" src="https://github.com/user-attachments/assets/1a8aa88f-2b9a-4127-970f-969d3fdcbb0a" />

## 🛠️ Size and design:
The board is 5 cm wide and 4.25 cm tall, with chamfered corners, and is meant to be press-fitted into a strap with a battery. For customization purposes it has an empty space on its bottom left corner reserved for graphics or extra components. By default the board has no silkscreen besides settings markings in "Silkscreen" font.

## ⚡ Power:
Because the board is using a Seeed Studio XIAO MG24 Sense, a battery that complies with [this guide](https://wiki.seeedstudio.com/xiao_mg24_getting_started/#battery-usage) can be connected to the JST connector present on the board.

**However the user needs to make sure that the positive and negative terminals on the female JST connector of the battery are in the right orientation by confirming that the side of the male JST connector on the board that will be connected to the positive wire has a trace connecting it to the XIAO. Otherwise permanent damage may be caused**

## 🎨 Customization:
The provided .ino file has lots of comments that explain what each part does and what values to change for customization for example. Along software you can customize the PCB mainly by using the reserved empty space.

You don't have to get into code, B1TWatch can not only manage alarms, and set timers or stopwatches, you can change its brightness limits, volume, frequency, and time format without writing a single lone of code. All navigation is done through a single rotary encoder with a momentary switch!
