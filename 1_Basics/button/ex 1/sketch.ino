#define BUTTON_PIN 2

int buttonState;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // INPUT_PULLUP — no extra resistor needed
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);
  Serial.println(buttonState);  // prints 1 = not pressed, 0 = pressed
  delay(100);
}