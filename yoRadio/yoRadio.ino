/* must use AsyncTCP version 1.1.3
ESP Async Webserver 2.9.0
GFX Arduino 1.4.7
ESP32 boards 3.0.1 

[env:esp32]
platform = espressif32@~3.0.1
lib_deps =
    me-no-dev/AsyncTCP@1.1.3
    me-no-dev/ESPAsyncWebServer@2.9.0
    Arduino GFX Library@1.4.7
*/

#include "Arduino.h"
#include "src/core/options.h"
#include "src/core/config.h"
#include "src/core/telnet.h"
#include "src/core/player.h"
#include "src/core/display.h"
#include "src/core/network.h"
#include "src/core/netserver.h"
#include "src/core/controls.h"
#include "src/core/mqtt.h"
#include "src/core/optionschecker.h"

extern __attribute__((weak)) void yoradio_on_setup();

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("Initializing system...");
  pinMode(GFX_BL, OUTPUT);//#############################
  digitalWrite(GFX_BL, HIGH);//#############################
  //ts.begin();
 

  if (yoradio_on_setup) yoradio_on_setup();
  config.init();
  display.init();
  player.init();
  network.begin();
  if (network.status != CONNECTED && network.status != SDREADY) {
    netserver.begin();
    initControls();
    display.putRequest(DSP_START);
    while (!display.ready()) delay(10);
    return;
  }
  if (SDC_CS != 255) {
    display.putRequest(WAITFORSD, 0);
    Serial.print("##[BOOT]#\tSD search\t");
  }
  config.initPlaylistMode();
  netserver.begin();
  telnet.begin();
  initControls();
  display.putRequest(DSP_START);
  while (!display.ready()) delay(10);
#ifdef MQTT_ROOT_TOPIC
  mqttInit();
#endif
  if (config.getMode() == PM_SDCARD) player.initHeaders(config.station.url);
  player.lockOutput = false;
  if (config.store.smartstart == 1) player.sendCommand({PR_PLAY, config.store.lastStation});
}

#if 0
int loop_cnt;
#endif

#if 0
uint32_t loop_ts;
uint32_t delta;
#endif

void loop() {
  telnet.loop();
  if (network.status == CONNECTED || network.status == SDREADY) {
    player.loop();
    //loopControls();
  }
  loopControls();
  
  netserver.loop();

#if 0
  delta = millis() - loop_ts;
  if (delta > 30)
    Serial.printf("loop delta %d ms\n", delta);
  loop_ts = millis();
#endif

#if 0
  loop_cnt++;
  if (loop_cnt == 10000) {
    loop_cnt = 0;
    Serial.println("yoRadio on esp32-s3");

    /*
      static char __stats_buffer[1024];
      vTaskGetRunTimeStats(__stats_buffer);
      Serial.printf("%s\n", __stats_buffer);
      vTaskList(__stats_buffer);
      Serial.printf( "%s\n", __stats_buffer);
    */
  }
#endif
}

#include "src/core/audiohandlers.h"
