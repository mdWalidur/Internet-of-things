// Lab 5 - Exercise 13: Pot controls cursor, button writes character
// Potentiometer on A0, Button on pin 2, LCD on I2C

#include <LiquidCrystal_I2C.h>

#define POT_PIN    A0
#define BUTTON_PIN 2

LiquidCrystal_I2C lcd(0x27, 16, 2);

int cursorPos   = 0;
int lastButton  = HIGH;
char character  = 'A';  // character to write each press

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Press btn=write");
  lcd.setCursor(0, 1);
  lcd.print("                ");  // blank row 2
  lcd.blink();  // show blinking cursor
  Serial.begin(9600);
}

void loop() {
  // --- Read potentiometer → map to cursor position 0–15 ---
  int potValue = analogRead(POT_PIN);
  cursorPos    = map(potValue, 0, 1023, 0, 15);

  // Move cursor to new position on row 2
  lcd.setCursor(cursorPos, 1);

  // --- Read button ---
  int buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW && lastButton == HIGH) {
    // Button pressed → write character at cursor position
    lcd.setCursor(cursorPos, 1);
    lcd.print(character);

    Serial.print("Wrote '");
    Serial.print(character);
    Serial.print("' at position ");
    Serial.println(cursorPos);

    // Move to next character A→B→C...
    character++;
    if (character > 'Z') character = 'A';  // reset after Z

    delay(200); // debounce
  }

  lastButton = buttonState;

  // Keep cursor blinking at current position
  lcd.setCursor(cursorPos, 1);
  delay(50);
}