***********************************************************
02-04-2025
***********************************************************
Added infrared sensor for remote control.
The sensor works on pin 17.

#define IR_PIN 17

I used this infrared sensor model:
https://www.aliexpress.com/item/1005005779308163.html

The precompiled binary file with the added infrared sensor is called JC4827W54C_IRremote.bin

And you can download it from here: 
https://github.com/DaradiciLevente/yoRadio_on_JC4827W543C/blob/main/bin/JC4827W54C_IRremote.bin
***********************************************************
25-03-2025
***********************************************************
I connected an external DAC PCM5102A and compiled the binary file. It is named JC4827W543C_PCM5102.bin and can be downloaded from here: https://github.com/DaradiciLevente/yoRadio_on_JC4827W543C/blob/main/bin/JC4827W54C_PCM5102.bin

The PCM5102 was connected to the JC4827W543C and was connected like this:
JC4827W543C -- PCM5102A
---------------------------------
3.3V → VCC
GND → GND
GPIO14 → BCK
GPIO5 → LCK
GPIO9 → DIN
---------------------------------

The sound is very good! It's stereo! It's PCM5102A quality!

Soon I will make a short video on my Youtube channel:
https://www.youtube.com/@LeventeDaradici/videos
***********************************************************
JC4827W543C + PCM5102A the easiest touchscreen yoRadio with external DAC!
https://youtu.be/vJsdyrAH3n0
***********************************************************
Please make your own key for the weather part. OpenWeatherMap will block the key you find in the firmware, due to too many data requests.
https://openweathermap.org/appid
***********************************************************
21-03-2025
***********************************************************
I fixed the weather section where coordinates couldn't be saved. Now it works!
https://github.com/DaradiciLevente/yoRadio_on_JC4827W543C/blob/main/bin/JC4827W543WeatherOK_02.bin
After entering one of the coordinates, press the APPLY button, then enter the second coordinate and press APPLY again, then the DONE button.
Restart the microcontroller to display the weather data for the new coordinates entered!
Please make your own key for the weather part. OpenWeatherMap will block the key you find in the firmware, due to too many data requests.
https://openweathermap.org/appid
***********************************************************
04-03-2025
***********************************************************
Added SD card reader functionality for playing MP3 files.
https://github.com/DaradiciLevente/yoRadio_on_JC4827W543C/blob/main/bin/JC4827W543CfirmwareSDcard2.bin
***********************************************************

The file is the compiled firmware of yoRadio for the JC4827W543C board. It is the one with the capacitive touchscreen!

You can see a short tutorial on how to upload the code to the microcontroller:
https://youtu.be/828zJZ32_Bs

Flash Download Tools can be downloaded from here:
https://dl.espressif.com/public/flash_download_tool.zip
***********************************************************
