#include "Arduino.h"
#include "uRTCLib.h"
#include <LiquidCrystal.h>

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// uRTCLib rtc;
uRTCLib rtc(0x68);

char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

void setup() {
  Serial.begin(9600);
  delay(3000); // wait for console opening

  lcd.begin(16, 2);

  URTCLIB_WIRE.begin();

//    rtc.update();
    rtc.set(0, 35, 8, 2, 9, 1, 23);
   // rtc.set(second, minute, hour, dayOfWeek, dayOfMonth, month, year)
  // set day of week (1=Sunday, 7=Saturday)
}

void loop() {
  rtc.refresh();

  Serial.print("Current Date & Time: ");
  Serial.print(rtc.year());
  lcd.print(rtc.year());
  Serial.print('/');
  lcd.print('/');
  
  Serial.print(rtc.month());
  Serial.print('/');
  lcd.print(rtc.month());
  lcd.print('/');
  
  Serial.print(rtc.day());
  lcd.print(rtc.day());
  
  Serial.print(" (");
  Serial.print(daysOfTheWeek[rtc.dayOfWeek()-1]);
  Serial.print(") ");

  lcd.print(" (");
  lcd.print(daysOfTheWeek[rtc.dayOfWeek()-1]);
  lcd.print(")");

  lcd.setCursor(0, 1);

  Serial.print(rtc.hour());
  Serial.print(':');
  lcd.print(rtc.hour());
  lcd.print(':');
  
  Serial.print(rtc.minute());
  Serial.print(':');
  lcd.print(rtc.minute());
  lcd.print(':');
  
  Serial.println(rtc.second());
  lcd.print(rtc.second());
  
  delay(1000);
  lcd.clear();
}
