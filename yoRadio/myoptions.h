#ifndef myoptions_h
#define myoptions_h

#define L10N_LANGUAGE     EN                /*  Language (EN, RU). More info in yoRadio/locale/displayL10n_(en|ru).h  */

#define DSP_MODEL         DSP_NV3041A
/*
 * !!! Important !!!
 * if you use colored TFT displays with the esp32 wroom, due to lack of memory, you must modify the file Arduino/libraries/AsyncTCP/src/AsyncTCP.cpp
 * replace the line 221
 * xTaskCreateUniversal(_async_service_task, "async_tcp", 8192 * 2, NULL, 3, &_async_service_task_handle, CONFIG_ASYNC_TCP_RUNNING_CORE);
 * with
 * xTaskCreateUniversal(_async_service_task, "async_tcp", 8192 / 2, NULL, 3, &_async_service_task_handle, CONFIG_ASYNC_TCP_RUNNING_CORE);
*/
/******************************************/

#define TFT_CS  45                /*  SPI CS pin  */    
#define TFT_RST -1                /*  SPI RST pin.  set to -1 and connect to Esp EN pin */
#define TFT_SCK 47                /*  SPI DC/RS pin  */
#define TFT_D0 21
#define TFT_D1 48
#define TFT_D2 40
#define TFT_D3 39
#define GFX_BL 1 

/******************************************/

#define PLAYER_FORCE_MONO true

/*        I2S DAC                 */
#define I2S_DOUT      41//  17                /*  DIN connection. Should be set to 255 if the board is not used */
#define I2S_BCLK       42 //  0              /*  BCLK Bit clock */
#define I2S_LRC        2 //   18            /*  WSEL Left Right Clock */2nd set 543 onboard dac
/******************************************/

#define RSSI_STEPS       -50,-60,-70,-80

/*  TOUCHSCREEN  */
#define  TS_MODEL   TS_MODEL_GT911

/*  Capacitive I2C touch screen  */

#define TS_SDA      8    
#define TS_SCL      4       
#define TS_INT      3    
#define TS_RST      38 

/******************************************/

//#define PLAYER_FORCE_MONO false             /*  mono option on boot - false stereo, true mono  */
//#define I2S_INTERNAL      false             /*  If true - use esp32 internal DAC  */

#define SD_SPIPINS    12, 13, 11      /* SCK, MISO, MOSI */
#define SDC_CS        10              /* Chip Select */

#endif
