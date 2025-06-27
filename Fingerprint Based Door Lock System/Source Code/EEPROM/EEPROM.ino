#include <EEPROM.h>

int x;

void setup() {
  Serial.begin(9600);
  for(int i=0, j=50; i<=50; i++, j--) {
    EEPROM.write(i, j);
  }
}

void loop() {
  for(int i=0; i<=50; i++) {
    Serial.println(EEPROM.read(i));
    delay(500);
  }
}
