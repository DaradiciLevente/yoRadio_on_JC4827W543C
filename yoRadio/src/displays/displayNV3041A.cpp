#include "../core/options.h"
#if DSP_MODEL==DSP_NV3041A

#include "displayNV3041A.h"
#include "fonts/bootlogo.h"
#include "../core/spidog.h"
#include "../core/config.h"
#include "../core/network.h"

#include "Arduino_GFX.h"

#define TAKE_MUTEX() sdog.takeMutex()
#define GIVE_MUTEX() sdog.giveMutex()

Arduino_DataBus *bus = new Arduino_ESP32QSPI(TFT_CS, TFT_SCK, TFT_D0, TFT_D1, TFT_D2, TFT_D3);

DspCore::DspCore(): Arduino_NV3041A(bus, GFX_NOT_DEFINED /* RST */, 0 /* rotation */, true /* IPS */) {}

#include "tools/utf8RusGFX.h"

void DspCore::initDisplay() {
  begin();
  init();
  flip();
  setTextWrap(false);
  setTextSize(1);
  fillScreen(0x0000);
  invert();
  
  plItemHeight = playlistConf.widget.textsize*(CHARHEIGHT-1)+playlistConf.widget.textsize*4;
  plTtemsCount = round((float)height()/plItemHeight);
  if(plTtemsCount%2==0) plTtemsCount++;
  plCurrentPos = plTtemsCount/2;
  plYStart = (height() / 2 - plItemHeight / 2) - plItemHeight * (plTtemsCount - 1) / 2 + playlistConf.widget.textsize*2;
}

void DspCore::drawLogo(uint16_t top) 
    { 
	digitalWrite(GFX_BL, LOW);
	drawBitmap(0, 0, bootlogo2, 480, 272); 
	digitalWrite(GFX_BL, HIGH);	
	delay(3000);
	}

void DspCore::printPLitem(uint8_t pos, const char* item, ScrollWidget& current){
  setTextSize(playlistConf.widget.textsize);
  if (pos == plCurrentPos) {
    current.setText(item);
  } else {
    uint8_t plColor = (abs(pos - plCurrentPos)-1)>4?4:abs(pos - plCurrentPos)-1;
    setTextColor(config.theme.playlist[plColor], config.theme.background);
    setCursor(TFT_FRAMEWDT, plYStart + pos * plItemHeight);
    fillRect(0, plYStart + pos * plItemHeight - 1, width(), plItemHeight - 2, config.theme.background);
    print(utf8Rus(item, false));
  }
}

void DspCore::drawPlaylist(uint16_t currentItem) {
  uint8_t lastPos = config.fillPlMenu(currentItem - plCurrentPos, plTtemsCount);
  if(lastPos<plTtemsCount){
    fillRect(0, lastPos*plItemHeight+plYStart, width(), height()/2, config.theme.background);
  }
}

void DspCore::clearDsp(bool black) { fillScreen(black?0:config.theme.background); }

uint8_t DspCore::_charWidth(unsigned char c){
  GFXglyph *glyph = pgm_read_glyph_ptr(&DS_DIGI56pt7b, c - 0x20);
  return pgm_read_byte(&glyph->xAdvance);
}

uint16_t DspCore::textWidth(const char *txt){
  uint16_t w = 0, l=strlen(txt);
  for(uint16_t c=0;c<l;c++) w+=_charWidth(txt[c]);
  return w;
}

void DspCore::_getTimeBounds() {
  _timewidth = textWidth(_timeBuf);
  char buf[4];
  strftime(buf, 4, "%H", &network.timeinfo);
  _dotsLeft=textWidth(buf);
}

void DspCore::_clockSeconds(){
  setTextSize(4);
  setTextColor(config.theme.seconds, config.theme.background);
  setCursor(width() + 20 - clockRightSpace - CHARWIDTH*4*2, clockTop-clockTimeHeight+68);
  sprintf(_bufforseconds, "%02d", network.timeinfo.tm_sec);
  print(_bufforseconds);                                      /* print seconds */
  setTextSize(9);
  //setFont(&DS_DIGI56pt7b);
  setFont(NULL);
  setTextSize(9);
  setTextColor((network.timeinfo.tm_sec % 2 == 0) ? config.theme.clock : (CLOCKFONT_MONO?config.theme.clockbg:config.theme.background), config.theme.background);
  setCursor(_timeleft+_dotsLeft +1, clockTop-CHARHEIGHT+10);
  print(":");                                     /* print dots */
  setFont();
}

void DspCore::_clockDate(){
  if(_olddateleft>0)
    dsp.fillRect(_olddateleft,  clockTop+79, _olddatewidth, CHARHEIGHT*2, config.theme.background);
  setTextColor(config.theme.date, config.theme.background);
  setCursor(_dateleft+32, clockTop+78);
  setTextSize(2);
  print(_dateBuf);                                            /* print date */
  strlcpy(_oldDateBuf, _dateBuf, sizeof(_dateBuf));
  _olddatewidth = _datewidth;
  _olddateleft = _dateleft;
  setTextSize(4);
  setTextColor(config.theme.dow, config.theme.background);
  setCursor(width() + 8 - clockRightSpace - CHARWIDTH*4*2+13, clockTop-CHARHEIGHT+44);
  print(utf8Rus(dow[network.timeinfo.tm_wday], false));       /* print dow */
}

void DspCore::_clockTime(){
  if(_oldtimeleft>0 && !CLOCKFONT_MONO) dsp.fillRect(_oldtimeleft, clockTop-clockTimeHeight+1, _oldtimewidth, clockTimeHeight, config.theme.background);
  _timeleft = width()-clockRightSpace-CHARWIDTH*4*2-24-_timewidth;
  setTextSize(9);
  //setFont(&DS_DIGI56pt7b); 
  setFont(NULL); // Folosește fontul implicit
  
  if(CLOCKFONT_MONO) {
    //setCursor(_timeleft, clockTop);
    //(config.theme.clockbg, config.theme.background);
    //print("88:88");
  }
  setTextColor(config.theme.clock, config.theme.background);
  setCursor(_timeleft, clockTop);
  print(_timeBuf);
  setFont();
  strlcpy(_oldTimeBuf, _timeBuf, sizeof(_timeBuf));
  _oldtimewidth = _timewidth;
  _oldtimeleft = _timeleft;
  drawFastVLine(width()-clockRightSpace-CHARWIDTH*4*2+10, clockTop -2, clockTimeHeight-3, config.theme.div);  /*divider vert*/
  drawFastHLine(width()-clockRightSpace-CHARWIDTH*4*2+10, clockTop+32, 62, config.theme.div);              /*divider hor*/
  sprintf(_buffordate, "%2d %s %d", network.timeinfo.tm_mday,mnths[network.timeinfo.tm_mon], network.timeinfo.tm_year+1900);
  strlcpy(_dateBuf, utf8Rus(_buffordate, true), sizeof(_dateBuf));
  _datewidth = strlen(_dateBuf) * CHARWIDTH*2;
  _dateleft = width() - 10 - clockRightSpace - _datewidth;
}

void DspCore::printClock(uint16_t top, uint16_t rightspace, uint16_t timeheight, bool redraw){
  clockTop = top;
  clockRightSpace = rightspace;
  clockTimeHeight = timeheight;
  strftime(_timeBuf, sizeof(_timeBuf), "%H:%M", &network.timeinfo);
  if(strcmp(_oldTimeBuf, _timeBuf)!=0 || redraw){
    _getTimeBounds();
    _clockTime();
    if(strcmp(_oldDateBuf, _dateBuf)!=0 || redraw) _clockDate();
  }
  _clockSeconds();
}

void DspCore::clearClock(){
  dsp.fillRect(_timeleft,  clockTop-clockTimeHeight, _timewidth+CHARWIDTH*3*2+24, clockTimeHeight+12+CHARHEIGHT, config.theme.background);
}

void DspCore::startWrite(void) {
  TAKE_MUTEX();
  //ILI9486_SPI::startWrite();
}

void DspCore::endWrite(void) { 
  //ILI9486_SPI::endWrite();
  GIVE_MUTEX();
}
  
void DspCore::loop(bool force) {

}

void DspCore::charSize(uint8_t textsize, uint8_t& width, uint16_t& height){
  width = textsize * CHARWIDTH;
  height = textsize * CHARHEIGHT;
}

void DspCore::setTextSize(uint8_t s){
  Arduino_GFX::setTextSize(s);
}

void DspCore::flip(){
  TAKE_MUTEX();
  setRotation(config.store.flipscreen?0:2);
  GIVE_MUTEX();
}

void DspCore::invert(){
  TAKE_MUTEX();
  invertDisplay(config.store.invertdisplay);
  GIVE_MUTEX();
}

void DspCore::sleep(void) { 
  Serial.println("DspCore::sleep");
  TAKE_MUTEX();
  displayOff();
  GIVE_MUTEX();
  //sendCommand(ILI9488_SLPIN); delay(150); sendCommand(ILI9488_DISPOFF); delay(150);
}

void DspCore::wake(void) {
  Serial.println("DspCore::wake");
  TAKE_MUTEX();
  displayOn();
  GIVE_MUTEX();
  //sendCommand(ILI9488_DISPON); delay(150); sendCommand(ILI9488_SLPOUT); delay(150);
}

void DspCore::writePixel(int16_t x, int16_t y, uint16_t color) {
  if(_clipping){
    if ((x < _cliparea.left) || (x > _cliparea.left+_cliparea.width) || (y < _cliparea.top) || (y > _cliparea.top + _cliparea.height)) return;
  }
  Arduino_GFX::drawPixel(x, y, color);
}

void DspCore::writeFillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
  if(_clipping){
    if ((x < _cliparea.left) || (x >= _cliparea.left+_cliparea.width) || (y < _cliparea.top) || (y > _cliparea.top + _cliparea.height))  return;
  }
  Arduino_GFX::writeFillRect(x, y, w, h, color);
}

void DspCore::setClipping(clipArea ca){
  _cliparea = ca;
  _clipping = true;
}

void DspCore::clearClipping(){
  _clipping = false;
}

void DspCore::setNumFont(){
  //setFont(&DS_DIGI56pt7b);
  //setTextSize(1);
    setFont(NULL);
    setTextSize(12);
}
#endif
