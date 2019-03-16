void setup() {
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
}

void loop() {
  // read analog inputs and set X-Y position
  Joystick.X(analogRead(0));
  Joystick.Y(analogRead(1));

  // read the digital inputs and set the buttons
  Joystick.button(1, digitalRead(0));
  Joystick.button(2, digitalRead(1));

  // a brief delay, so this runs 20 times per second
  delay(50);
}
