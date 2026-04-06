// Lab 5 - Exercise 9: RGB LCD Display
// Shows "hello, world!" + seconds counter
// Uses LiquidCrystal_I2C (Wokwi compatible version of rgb_lcd)

#include <LiquidCrystal_I2C.h>

// LCD: 16 columns, 2 rows, I2C address 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();          // initialize LCD
  lcd.backlight();     // turn on backlight

  // Set background color (red = lab default)
  // LiquidCrystal_I2C uses backlight only, no RGB in Wokwi
  // but Grove RGB LCD uses: lcd.setRGB(255, 0, 0);

  // Print message on row 1
  lcd.setCursor(0, 0);
  lcd.print("hello, world!");

  delay(1000);
}

void loop() {
  // Print seconds since start on row 2
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
  lcd.print(" seconds   "); // spaces clear old digits

  delay(100);
}