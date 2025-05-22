

bool  Flag_Message = 0;
bool  Flag_Start   = 0;
bool  Flag_Packet  = 0;
bool  Flag_End     = 0;

bool  Flag_Message_Time     = 0;
bool  Flad_Rattle_INT0      = 0;

//unsigned long Time_Rattle_INT0  = 0;
unsigned long Messages_Time     = 0;

uint8_t bitX2           = 0;
uint8_t D_Time          = 0;
uint8_t Time_Cnst       = 100;
uint8_t Byte_For_Packet = 147;

/*void Timer_Rattle()
{
  if ( millis() - Time_Rattle_INT0 == 200 )
  {
    Time_Rattle_INT0 = 0;
    Flad_Rattle_INT0 = 1;
    
  }
}*/

void Trigger()
{
  if (Flad_Rattle_INT0){
    Serial.println("Сработало прерывание. ");
    
    Flag_Message = 1;
    Serial.println("\t Отправка сообщения - разрешено (1). ");
    
    Flag_Message_Time = 0;
    Serial.println("\t Флаг времени №0 - зепрет (0). ");
    
    Messages_Time = micros();
    Serial.print("\t Время №0 = определено (=");
    Serial.print(Messages_Time);
    Serial.println(").");
    
    Flag_Start = 1;
    Serial.println("\t Отправка стартого Бита - разрешено (1). ");

    Byte_For_Packet = 147; //++;
    Serial.print("\t Сообщение = определено (=");
    Serial.print(Byte_For_Packet);
    Serial.println(").");
    
    Flad_Rattle_INT0 = false;
    //Time_Rattle_INT0 = millis();
  } 
}

void  Go_Massage()
{
  if ( Flag_Message_Time == 1 )
  {
    Flag_Message_Time = 0;
    Messages_Time = micros();
    Flag_Start = 1;
  }

  if ( Flag_Start == 1 )
  {
    Start_B();
  }
  else
  {
    if ( Flag_Packet == 1 )
    {
      Packet_B( Byte_For_Packet );
    }
    else
    {
      if ( Flag_End == 1 )             
      {
        End_B();
      }
    }
  }
  
}


void setup() 
{
  
  Serial.begin(500000); // открыли порт для связи

  pinMode(2, INPUT_PULLUP);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);
  attachInterrupt(0, Trigger, FALLING);

  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(12, 0);

  Flad_Rattle_INT0 = 1;
  Serial.println("Сработало setup(). ");

  
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if (Flag_Message)
  {
    Go_Massage();
  }
}
