#define NUM_BUTTONS 3
int buttonlist[NUM_BUTTONS] = {2,3,4};

void setup() {
  Joystick.useManualSend(true);

  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttonlist[i], INPUT_PULLUP);
    }
  }
void loop() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    if (digitalRead(buttonlist[i]) == HIGH) {
      Serial.println("Button is not pressed...");
      } else {
        Serial.println("Button pressed!!!");
        }
    }

  Joystick.send_now();
  delay(250);
  
  }
 
