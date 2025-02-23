DOCUMENT IN PROGRESS...

# yoRadio MOD for GUITION JC4827W543C.

This project is based on the original yoRadio project which you can find [here](https://github.com/e2002/yoradio)

The hardware of this board contains a display that is not currently supported by yoRadio, but there are many people in the yoRadio community who offer to help you when a challenge arises.

But I was lucky that two yoRadio fans already had the solution for adapting this display and the DAC that is integrated into this board.

I would like to thank the users [@CoolmdXi](https://github.com/CoolmdXi) and [@bobcroft](https://github.com/bobcroft)
who provided me with working code for this board.
The discussion that helped me get yoRadio working can be seen [here.](https://github.com/e2002/yoradio/issues/105)

Here I also received the working code with the working graphics driver, with the working touchscreen and with the DAC set correctly.
Thanks again for the help!

The only problem was that one of my fonts didn't initialize, so everything that was displayed with that font wasn't displayed on the screen. (In reality, several fonts didn't work for me, even though everything was in place.)
This way the clock doesn't appear on the display, the volume doesn't appear in the middle of the display when I adjust the volume on the touchscreen, etc.
So I added small changes to correct these.
Instead of the fonts used, I used the default font from the library, but that meant that I had to move everything on the display so that everything would appear in its place.

![image](https://github.com/user-attachments/assets/33d490fb-beec-4558-ac61-773df08958cb)

After the changes, I managed to display everything necessary with the default font, and I replaced the icons at the sound level and at the RSSI level with text.

![TTRR](https://github.com/user-attachments/assets/9dcf861a-cdf0-4b13-8958-604f3bdf259e)

I bought the microcontroller from [here](https://www.aliexpress.com/item/1005006729377800.html) the version with capacitive touchscreen.


