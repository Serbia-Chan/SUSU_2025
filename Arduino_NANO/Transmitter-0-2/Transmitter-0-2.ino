

bool  Flag_Message = 0;
bool  Flag_Start   = 0;
bool  Flag_Packet  = 0;
bool  Flag_End     = 0;

bool  Flag_Message_Time     = 0;
bool  Flad_Rattle_INT0      = 0;

//unsigned long Time_Rattle_INT0  = 0;
unsigned long Messages_Time     = 0;

uint8_t bitX2           = 0;
uint8_t Byte_For_Packet = 147;

uint8_t D_Time          = 0;
uint8_t Time_Cnst       = 1;

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
    
    Flag_Message = 1;
    
    Flag_Message_Time = 0;
    
    Messages_Time = millis();
    
    Flag_Start = 1;

    Byte_For_Packet = 147; //++;
    
    Flad_Rattle_INT0 = false;
    //Time_Rattle_INT0 = millis();
  } 
}

void  Go_Massage()
{
  if ( Flag_Message_Time == 1 )
  {
    Flag_Message_Time = 0;
    Messages_Time = millis();
    Flag_Start = 1;
  }

  if ( Flag_Start == 1 )
  {
    Start_B();
  }
  if ( Flag_Packet == 1 )
  {
    Packet_B( Byte_For_Packet );
  }
  if ( Flag_End == 1 )             
  {
    End_B();
  }
  
}


void setup() 
{
  

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

  
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if (Flag_Message)
  {
    Go_Massage();
  }
}
