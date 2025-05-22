
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

int Time_Cnst       = 0;
int My_Time         = 2000;
int g = 0;

void Trigger()
{
  if (Flad_Rattle_INT0){
    Flad_Rattle_INT0 = false;
    //Time_Rattle_INT0 = millis();
  } 
}

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);
  attachInterrupt(0, Trigger, FALLING);

  digitalWrite(10, 0);
  digitalWrite(11, 0);
  digitalWrite(12, 0);

  Time_Cnst = My_Time / 100;
}

void loop() {
  if ( g == Time_Cnst )
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
    g = 0;
    
  }
  delayMicroseconds(100);
  g ++;
}
