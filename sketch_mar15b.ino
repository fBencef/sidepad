void setup()   {                
  Serial.begin(38400);
  pinMode(3, INPUT);
}

void loop()                     
{
  if (digitalRead(3) == HIGH) {
    Serial.println("Button is not pressed...");
  } else {
    Serial.println("Button pressed!!!");
  }
  delay(250);
}
