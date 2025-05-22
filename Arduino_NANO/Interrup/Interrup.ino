bool LED = true;
bool Flad_Rattle_INT0 = true;
unsigned long Time_Rattle_INT0 = 0;
uint8_t D = 0;

//  Отсчёт для отсечки дребезга
void Timer_Rattle()
{
  if ( millis() - Time_Rattle_INT0 == 200 )
  {
    Time_Rattle_INT0 = 0;
    Flad_Rattle_INT0 = 1;
    
  }
}

void Trigger()
{
  if (Flad_Rattle_INT0){
    //Serial.print("Было: "); 
    //Serial.print( D ); 
    LED = !LED; 
    D++;
    //Serial.print(". Стало: "); 
    //Serial.println( D ); 
    

    digitalWrite(10, (D & 1) ); 
    //Serial.print("10: ");
    //Serial.println( digitalRead(10) );
    
    digitalWrite(11, (D & 2) ); 
    //Serial.print("11: ");
    //Serial.println( digitalRead(11) );
    
    digitalWrite(12, (D & 4) ); 
    //Serial.print("12: ");
    //Serial.println( digitalRead(12) );
    
    
    Flad_Rattle_INT0 = false;
    Time_Rattle_INT0 = millis();
  }
  
}

void setup() {
  //Serial.begin(9600); // открыли порт для связи
  
  pinMode(2, INPUT_PULLUP);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);
  attachInterrupt(0, Trigger, FALLING);

  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(12, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, LED);
  Timer_Rattle();

}
