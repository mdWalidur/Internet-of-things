#include <LiquidCrystal_I2C.h>

#define TOUCH_PIN A0

LiquidCrystal_I2C lcd(0x27, 16, 2);

int counter = 0;
int lastState = 0;  // 0 = not touched

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

  lcd.setCursor(0, 0);
  lcd.print("Touch Counter:");
  lcd.setCursor(0, 1);
  lcd.print("Count: 0");
}

void loop() {
  int value = analogRead(TOUCH_PIN);  // 0–1023

  // Simulate touch: slider RIGHT = touched (value > 512)
  int currentState = (value > 512) ? 1 : 0;

  // Count only when goes from NOT touched → touched
  if (currentState == 1 && lastState == 0) {
    counter++;

    lcd.setCursor(0, 1);
    lcd.print("Count: ");
    lcd.print(counter);
    lcd.print("   ");

    Serial.print("Touched! Count: ");
    Serial.println(counter);
  }

  lastState = currentState;
  delay(100);
}