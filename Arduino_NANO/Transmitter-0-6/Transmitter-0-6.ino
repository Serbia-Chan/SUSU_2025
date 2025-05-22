#include <stdint.h>

bool A_10 = 0;
bool A_11 = 0;
bool A_12 = 0;

bool B_10 = 0;
bool B_11 = 0;
bool B_12 = 0;

bool C_10 = 0;
bool C_11 = 0;
bool C_12 = 0;

bool D_10 = 0;
bool D_11 = 0;
bool D_12 = 0;

bool  Flag_Message = 0;
bool  Flag_Start   = 0;
bool  Flag_Packet  = 0;
bool  Flag_End     = 0;

bool  Flag_Message_Time     = 0;
bool  Flad_Rattle_INT0      = 0;

//unsigned long Time_Rattle_INT0  = 0;
unsigned long Messages_Time     = 0;

uint8_t _Byte           = 255;
uint8_t Byte_For_Packet = 146;
uint8_t D_Time          = 0;

uint16_t Time_Cnst       = 0;
uint16_t My_Time         = 2000;
uint16_t g = 0;


void A(uint8_t B)
{
  switch( B )
    {
      case 0:
      {
        A_10 = 0;
        A_11 = 0;
        A_12 = 0;        
        break;
      }
      case 1:
      {
        A_10 = 0;
        A_11 = 0;
        A_12 = 1;         
        break;
      }
      case 2:
      {
        
        A_10 = 0;
        A_11 = 1;
        A_12 = 1;        
        break;
      }
      case 3:
      {
        A_10 = 1;
        A_11 = 1;
        A_12 = 1; 
        break;
      }
    }
}

void B(uint8_t B)
{
  switch( B )
    {
      case 0:
      {
        B_10 = 0;
        B_11 = 0;
        B_12 = 0;        
        break;
      }
      case 1:
      {
        B_10 = 0;
        B_11 = 0;
        B_12 = 1;         
        break;
      }
      case 2:
      {
        
        B_10 = 0;
        B_11 = 1;
        B_12 = 1;        
        break;
      }
      case 3:
      {
        B_10 = 1;
        B_11 = 1;
        B_12 = 1; 
        break;
      }
    }
}

void C(uint8_t B)
{
  switch( B )
    {
      case 0:
      {
        C_10 = 0;
        C_11 = 0;
        C_12 = 0;        
        break;
      }
      case 1:
      {
        C_10 = 0;
        C_11 = 0;
        C_12 = 1;         
        break;
      }
      case 2:
      {
        
        C_10 = 0;
        C_11 = 1;
        C_12 = 1;        
        break;
      }
      case 3:
      {
        C_10 = 1;
        C_11 = 1;
        C_12 = 1; 
        break;
      }
    }
}

void D(uint8_t B)
{
  switch( B )
    {
      case 0:
      {
        D_10 = 0;
        D_11 = 0;
        D_12 = 0;        
        break;
      }
      case 1:
      {
        D_10 = 0;
        D_11 = 0;
        D_12 = 1;         
        break;
      }
      case 2:
      {
        
        D_10 = 0;
        D_11 = 1;
        D_12 = 1;        
        break;
      }
      case 3:
      {
        D_10 = 1;
        D_11 = 1;
        D_12 = 1; 
        break;
      }
    }
}


void Trigger()
{
  if (Flad_Rattle_INT0){
    _Byte = 0;
    Byte_For_Packet ++;
    
    uint8_t D_Byte      = 0b00000011 & Byte_For_Packet;    
    A(D_Byte);

    D_Byte      = 0b00000011 & (Byte_For_Packet >> 2);
    B(D_Byte);

    D_Byte      = 0b00000011 & (Byte_For_Packet >> 4);
    C(D_Byte);

    D_Byte      = 0b00000011 & (Byte_For_Packet >> 6);
    D(D_Byte);

    
    
    Flad_Rattle_INT0 = 0;
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

  Flad_Rattle_INT0 = 1;
  Time_Cnst = My_Time / 100;
}

void loop() {
  
  switch (_Byte)
  {
    case 0:
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
  
      _Byte++;
      break;
    }
    case 1:
    {
      digitalWrite(10, A_10);
      digitalWrite(11, A_11);
      digitalWrite(12, A_12);
      delayMicroseconds(My_Time);
      
      digitalWrite(10, B_10);
      digitalWrite(11, B_11);
      digitalWrite(12, B_12);
      delayMicroseconds(My_Time);
      
      digitalWrite(10, C_10);
      digitalWrite(11, C_11);
      digitalWrite(12, C_12);
      delayMicroseconds(My_Time);
      
      digitalWrite(10, D_10);
      digitalWrite(11, D_11);
      digitalWrite(12, D_12);
      delayMicroseconds(My_Time);
  
      
      _Byte++;
      break;
    }
    case 2:
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
  
      _Byte++;
      break;
    }
    case 3:
    {
      Flad_Rattle_INT0 = 1;
      _Byte=255;
      break;
    }
  }
  
}
