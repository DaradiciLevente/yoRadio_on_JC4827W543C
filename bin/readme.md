***********************************************************
02-04-2025
***********************************************************
Added infrared sensor for remote control.

![IMG_20250403_152844144_HDR_AE](https://github.com/user-attachments/assets/154df16c-6e46-4d13-9529-25e6eaca213f)

![IMG_20250403_152228514_HDR_AE](https://github.com/user-attachments/assets/3bab8da7-2b16-40e8-a799-f509ae510dcf)

The sensor works on pin 17.

#define IR_PIN 17

![IMG_20250403_152549508_HDR_AE](https://github.com/user-attachments/assets/733a715f-6eff-4a1f-9fa5-4c708d237941)


![IMG_20250403_152501209_HDR_AE](https://github.com/user-attachments/assets/0b95cc90-5c3e-4ba9-afc1-92487a1b0129)

I used this infrared sensor model:
https://www.aliexpress.com/item/1005005779308163.html

The precompiled binary file with the added infrared sensor is called JC4827W54C_IRremote.bin

And you can download it from here: 
https://github.com/DaradiciLevente/yoRadio_on_JC4827W543C/blob/main/bin/JC4827W54C_IRremote.bin

If you are using this type of remote control, you will not need to add the remote control from the web interface. The remote control is already added in the precompiled binary file.
![IMG_20250403_152756212_HDR_AE](https://github.com/user-attachments/assets/be65b847-e66c-4a81-ba61-3f02ece159b1)

I bought the remote control from here:
https://www.aliexpress.com/item/32315435973.html
But I used a different infrared sensor, because the one that comes with the remote control is not as good as the one I used.

If you are using another remote control model, you will need to add it from the web interface.
![Screenshot 2025-04-03 154519](https://github.com/user-attachments/assets/2e67b725-98fd-43ba-b1d0-96e5a3fae242)

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
