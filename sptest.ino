#define NUM_BUTTONS 3
int buttonlist[NUM_BUTTONS] = {0,1,2};

void setup() {
  Joystick.useManualSend(true);

  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttonlist[i], INPUT_PULLUP);
    }
  }
void loop() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    if (digitalRead(buttonlist[i]) == HIGH) {
      Joystick.button(i + 1, 0);
      } else {
        Joystick.button(i + 1, 1);
        }
    }

  Joystick.send_now();
  delay(5);
  
  }
 
