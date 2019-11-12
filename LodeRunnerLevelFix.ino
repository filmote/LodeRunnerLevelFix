#include <Arduboy2.h>
#include <ArduboyTones.h>

Arduboy2 arduboy;

#define EEPROM_START                  ((uint8_t *)175)
#define EEPROM_START_C1               ((uint8_t *)175)
#define EEPROM_START_C2               ((uint8_t *)176)
#define EEPROM_GAME_NO                ((uint8_t *)177)
#define EEPROM_LEVEL_NO               ((uint8_t *)178)
#define EEPROM_MEN_LEFT               ((uint8_t *)179)
#define EEPROM_SCORE                  ((uint16_t *)180)
#define EEPROM_GAME_NO_ORIG           ((uint8_t *)182)
#define EEPROM_LEVEL_NO_ORIG          ((uint8_t *)183)
#define EEPROM_MEN_LEFT_ORIG          ((uint8_t *)184)
#define EEPROM_SCORE_ORIG             ((uint16_t *)185)

void setup() {

  arduboy.boot();
  arduboy.flashlight();
  arduboy.systemButtons();
  arduboy.setFrameRate(25);
  arduboy.initRandomSeed();
  arduboy.audio.begin();

  eeprom_update_byte(EEPROM_START_C1, 76);
  eeprom_update_byte(EEPROM_START_C2, 82);

  eeprom_update_byte(EEPROM_GAME_NO, 3);
  eeprom_update_byte(EEPROM_LEVEL_NO, 114);
  eeprom_update_byte(EEPROM_MEN_LEFT, 5);

  eeprom_update_byte(EEPROM_GAME_NO_ORIG, 3);
  eeprom_update_byte(EEPROM_LEVEL_NO_ORIG, 114);
  eeprom_update_byte(EEPROM_MEN_LEFT_ORIG, 5);

}

void loop() {

  if (!(arduboy.nextFrame())) return;

  arduboy.setCursor(12, 25);
  arduboy.print("Update Complete");
  
  arduboy.display(CLEAR_BUFFER);

}