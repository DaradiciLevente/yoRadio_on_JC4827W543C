# yoRadio MOD for GUITION JC4827W543C.

This project is based on the original yoRadio project which you can find [here](https://github.com/e2002/yoradio) and based on the modifications made to this project to adapt it for the NV3041A display with which the original yoRadio project is not compatible.

I would like to thank the users [@CoolmdXi](https://github.com/CoolmdXi) and [@bobcroft](https://github.com/bobcroft)
who provided me with working code for this board.
The discussion that helped me get yoRadio working can be seen [here.](https://github.com/e2002/yoradio/issues/105)

Here I also received the working code with the working graphics driver, with the working touchscreen and with the DAC set correctly.

### For correct operation you must use:
- AsyncTCP version 1.1.3
- ESP Async Webserver 2.9.0
- GFX Arduino 1.4.7
- ESP32 boards 3.0.1

The only problem was that one of my fonts didn't initialize, so everything that was displayed with that font wasn't displayed on the screen. (In reality, several fonts didn't work for me, even though everything was in place.)
This way the clock doesn't appear on the display, the volume doesn't appear in the middle of the display when I adjust the volume on the touchscreen, etc.
So I added small changes to correct these.
Instead of the fonts used, I used the default font from the library, but that meant that I had to move everything on the display so that everything would appear in its place.

![image](https://github.com/user-attachments/assets/33d490fb-beec-4558-ac61-773df08958cb)

After the changes, I managed to display everything necessary with the default font, and I replaced the icons at the sound level and at the RSSI level with text.

![TTRR](https://github.com/user-attachments/assets/9dcf861a-cdf0-4b13-8958-604f3bdf259e)

I bought the microcontroller from [here](https://www.aliexpress.com/item/1005006729377800.html) the version with capacitive touchscreen.

I changed the boot logo to a custom one.

![ver2 2](https://github.com/user-attachments/assets/ea266052-0179-47a4-a38c-c418438a7dc8)

It is recommended for those who want to make a yoRadio and who do not have a minimum of electrical knowledge, because this board contains everything you need to make a yoRadio at home.

You do not need to solder anything, add anything.
Just upload the code to the microcontroller and connect a speaker to the audio output of the board.

Attention! The audio output has the smaller connector! (SH 1.0)
The connector has 2P and I bought it from [here](https://www.aliexpress.com/item/32921127444.html)
This connector is perfect for audio output.

The display has beautiful colors and wide viewing angles.
The capacitive touchscreen is extremely responsive.
The sound on the audio output is good.

In the next few days I will make a video showing how I uploaded the firmware to the microcontroller and how it works.
