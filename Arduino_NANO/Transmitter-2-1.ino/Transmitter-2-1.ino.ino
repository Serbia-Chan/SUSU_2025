#include <stdint.h>

bool  Flad_Rattle_INT0      = 0;

uint8_t D_Time, Time_Rattle_INT0   = 0;
uint8_t Chek = 0;

uint16_t My_Time         = 2500;

void Start()
{
  digitalWrite(10, 1);
  digitalWrite(11, 1);
  digitalWrite(12, 1);
  delayMicroseconds(My_Time);
  
  digitalWrite(10, 0);
  digitalWrite(11, 1);
  digitalWrite(12, 1);
  delayMicroseconds(My_Time);
  
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(12, 1);
  delayMicroseconds(My_Time);
  
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(12, 0);
  delayMicroseconds(My_Time);
}

void Trigger()
{
  if (Flad_Rattle_INT0){
    
    Chek ++;

    switch (Chek%12)
    {
      case 0 ... 2:
      {
        //Serial.println("case 0..2");
        My_Time = 2500;
        break;
      }
      case 3 ... 5:
      {
        //Serial.println("case 3..5");
        My_Time = 1000;
        break;
      }
      case 6 ... 8:
      {              
        //Serial.println("case 6..8");
        My_Time = 500;
        break;
      }
      case 9 ... 11:
      {              
        //Serial.println("case 6..8");
        My_Time = 100;
        break;
      }
    }
    /*
    Serial.print("Chek = ");              
    Serial.println(Chek);
    Serial.print("My_Time = ");              
    Serial.println(My_Time);*/
    
    Flad_Rattle_INT0 = 0;
    Time_Rattle_INT0 = millis();
  } 
}

void setup() {
  Serial.begin(500000); // открыли порт для связи
  
  pinMode(2, INPUT_PULLUP);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  //pinMode(LED_BUILTIN, OUTPUT);
  attachInterrupt(0, Trigger, FALLING);

  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(12, 0);

  Flad_Rattle_INT0 = 1;
}

void loop() {
  D_Time = millis() - Time_Rattle_INT0;
  if ( ( D_Time > 250 ) && ( D_Time < 255 ) && !Flad_Rattle_INT0 )
  {
    Flad_Rattle_INT0 = 1;
  }
  
  switch (Chek%3)
  {
    case 0:
    {      
      digitalWrite(10, 0);
      digitalWrite(11, 0);
      digitalWrite(12, 0);
      break;
    }
    case 1:
    {
      
      digitalWrite(10, 1);
      digitalWrite(11, 1);
      digitalWrite(12, 1);
      break;
    }
    case 2:
    {
      Start();
      break;
    }
  }

}
