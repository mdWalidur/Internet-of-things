// Lab 5 - Exercise 12: LCD shows rotary angle sensor value
// Potentiometer on A0, LCD on I2C

#include <LiquidCrystal_I2C.h>

#define POT_PIN A0

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Rotary Sensor:");
}

void loop() {
  int value = analogRead(POT_PIN);  // 0–1023

  lcd.setCursor(0, 1);
  lcd.print("Value: ");
  lcd.print(value);
  lcd.print("   ");  // clear leftover digits

  delay(100);
}