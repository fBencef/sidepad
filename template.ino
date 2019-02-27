/*

  This code is for a teensy 3.1 used in my green russian control board
  You must select the teensy board in Tools and change USB Type to Joystick

*/


//How many buttons I'm using, must equal amount of values in following array
#define NUM_BUTTONS 14  
//Which pins I have attached to my buttons
int buttonList[NUM_BUTTONS] = {2,3,4,5,6,7,8,9,10,11,12,14,15,16};

//Led intensity, so super bright LEDS aren't shining in our eyes
#define INTENSITY 200


void setup() {
  //This makes it so the states are send by us manually
  Joystick.useManualSend(true);
  
  //Declare button pins as input with the internal pullup resistor on
  for (int i = 0; i < NUM_BUTTONS; i++)  {
    pinMode(buttonList[i], INPUT_PULLUP);
  }
  
  //Declare our LED pins as outputs
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(20, OUTPUT);
}


void loop() {
  //Read our analogue pots
  //Remember that the analogue pin numbers are different than the digital ones!
  Joystick.sliderLeft(analogRead(7));
  Joystick.sliderRight(analogRead(8));
  
  //Read our button states
  for (int i = 0; i < NUM_BUTTONS; i++) {
    if (digitalRead(buttonList[i]) == HIGH) {  //Check to see if pin is HIGH
      Joystick.button(i + 1, 0);  //If pin is HIGH, button isn't pressed, so send 0
    } else {
      Joystick.button(i + 1, 1);  //If pin is LOW, button is pressed, so send 1
    }
  }
  
  
  //Special case for LED status lights
  //Check status of button and change LED accordingly
  
  if (digitalRead(12) == LOW)  //Check if button is pressed/switch flipped
    analogWrite(17, INTENSITY);  //Set corresponding LED pin to intensity level  
    else 
    analogWrite(17, 0);  //Otherwise turn off
  
  if (digitalRead(7) == LOW)  //Same for other pins
    analogWrite(18, INTENSITY);
    else
    analogWrite(18, 0);
  
  if (digitalRead(9) == LOW) 
    analogWrite(19, INTENSITY);
    else
    analogWrite(19, 0);
  
  if (digitalRead(11) == LOW) 
    analogWrite(20, INTENSITY);
    else
    analogWrite(20, 0);
  
  Joystick.send_now();  //Send control states
  delay(5);  //Slow things down a bit
}
