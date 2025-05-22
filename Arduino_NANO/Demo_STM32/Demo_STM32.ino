void setup() {
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(PC13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(PC13, LOW);    // turn the LED off by making the voltage low
  delay(1000);              // wait for a second
  
  digitalWrite(PC13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for a second
  digitalWrite(PC13, LOW);    // turn the LED off by making the voltage low
  delay(500);              // wait for a second
  digitalWrite(PC13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for a second
  digitalWrite(PC13, LOW);    // turn the LED off by making the voltage low
  delay(500);              // wait for a second
}
