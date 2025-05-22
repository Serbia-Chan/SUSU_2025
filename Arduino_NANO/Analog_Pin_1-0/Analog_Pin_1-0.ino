#include <stdint.h>

int val = 0;
int Byte = 0;
int Flag = 0;

uint16_t _Start, _Packet, _End = 0;

uint16_t Type_Byte, B_0, B_1, B_2, B_3 = 0;

unsigned long Time = 0;

bool Flag_Message = 0;

void setup() {
  

  Serial.begin(1000000);
  pinMode(A7, INPUT);
  _Start = 0;
  _Packet = 0;
  _End = 0;
  Flag_Message = 0;
  Serial.print("\nFlag_Message = ");
  Serial.println(Flag_Message);
}

void loop()
{
  val = analogRead(A7);
  delayMicroseconds(100);
  
  if ( (val > 360) && (val < 450) && !Flag_Message )
  {
    //B_3 += 10;
    Flag_Message = 1;
  }
  else
  {
    if ( (Type_Byte < 4) && Flag_Message )
    {
      
      Flag++;
      
      B_0 = B_0 << 1;
      B_1 = B_1 << 1;
      B_2 = B_2 << 1;
      B_3 = B_3 << 1;
      
      Serial.print("\t Flag = ");
      Serial.print(Flag);
      Serial.print("\t\t val = ");
      Serial.println(val);
      
      switch (val)
      {
        case   0 ... 50: 
        {
          B_0 += 1;
          break;
        }
        case 122 ... 240:
        {
          B_1 += 1;
          break;
        }
        case 260 ... 340:
        {
          B_2 += 1;
          break;
        }
        case 360 ... 450:
        {
          B_3 += 1;
          break;
        }
      }
      /*      
      Serial.println(B_0, BIN);
      Serial.println(B_1, BIN);
      Serial.println(B_2, BIN); 
      Serial.println(B_3, BIN); */
      
      if( Flag == 3 )
      { 
        

        switch (B_0)
        {
          case  1: 
          {
            B_0 = 1;
            break;
          }
          case  3: 
          {
            _Start = (_Start >> (2)) ;
            Type_Byte ++;
            
            B_0 = 0;
            break;
          }
          case  6:
          {
            _Start = (_Start >> (2)) ;
            B_0 = 0;
            break;
          }
          case  7:
          {
            _Start = (_Start >> (2)) ;
            Type_Byte ++;
            
            B_0 = 0;
            break;
          }
          case  12:
          {
            _Start = (_Start >> (2)) ;
            Type_Byte ++;
            
            B_0 = 0;
            break;
          }
          default:
          {
            B_0 = 0;
            break;
          }
        }
        
        switch (B_1)
        {
          case  1: 
          {
            B_1 = 1;
            break;
          }
          case  3: 
          {
            _Start = (_Start >> (2)) ;
            Type_Byte ++;
            
            _Start += 64;
            B_1 = 0;
            break;
          }
          case  6:
          {
            _Start = (_Start >> (2)) ;
            Type_Byte ++;
            
            _Start += 64;
            B_1 = 0;
            break;
          }
          case  7:
          {
            _Start = (_Start >> (2)) ;
            Type_Byte ++;
            
            _Start += 64;
            B_1 = 0;
            break;
          }
          case  12:
          {
            _Start = (_Start >> (2)) ;
            Type_Byte ++;
            
            _Start += 64;
            B_1 = 0;
            break;
          }
          default:
          {
            B_1 = 0;
            break;
          }
        }
        
        switch (B_2)
        {
          case  1: 
          {
            B_2 = 1;
            break;
          }
          case  3: 
          {
            _Start = (_Start >> (2)) ;
            Type_Byte ++;
            
            _Start += 128;
            B_2 = 0;
            break;
          }
          case  6:
          {
            _Start = (_Start >> (2)) ;
            Type_Byte ++;
            
            _Start += 128;
            B_2 = 0;
            break;
          }
          case  7:
          {
            _Start = (_Start >> (2)) ;
            Type_Byte ++;
            
            _Start += 128;
            B_2 = 0;
            break;
          }
          case  12:
          {
            _Start = (_Start >> (2)) ;
            Type_Byte ++;
            
            _Start += 128;
            B_2 = 0;
            break;
          }
          default:
          {
            B_2 = 0;
            break;
          }
        }
        
        switch (B_3)
        {
          case  1: 
          {
            B_3 = 1;
            break;
          }
          case  3: 
          {
            _Start = (_Start >> (2)) ;
            Type_Byte ++;
            
            _Start += 192;
            B_3 = 0;
            break;
          }
          case  6:
          {
            _Start = (_Start >> (2)) ;
            Type_Byte ++;
            
            _Start += 192;
            B_3 = 0;
            break;
          }
          case  7:
          {
            _Start = (_Start >> (2)) ;
            Type_Byte ++;
            
            _Start += 192;
            B_3 = 0;
            break;
          }
          case  12:
          {
            _Start = (_Start >> (2)) ;
            Type_Byte ++;
            
            _Start += 192;
            B_3 = 0;
            break;
          }
          default:
          {
            B_3 = 0;
            break;
          }
        }
        Serial.print("\t _Start_bin = \t");
        Serial.print(_Start, BIN);
        Serial.print("\t _Start = \t");
        Serial.println(_Start);
        
        Flag = 0;
      }
      
      
    }
    else if ( (Type_Byte < 8) && Flag_Message )
    {
      Flag++;
      
      B_0 = B_0 << 1;
      B_1 = B_1 << 1;
      B_2 = B_2 << 1;
      B_3 = B_3 << 1;
      
      Serial.print("\t Flag = ");
      Serial.print(Flag);
      Serial.print("\t\t val = ");
      Serial.println(val);
      
      switch (val)
      {
        case   0 ... 50: 
        {
          B_0 += 1;
          break;
        }
        case 122 ... 240:
        {
          B_1 += 1;
          break;
        }
        case 260 ... 340:
        {
          B_2 += 1;
          break;
        }
        case 360 ... 450:
        {
          B_3 += 1;
          break;
        }
      }
      
      
      Serial.println(B_0, BIN);
      Serial.println(B_1, BIN);
      Serial.println(B_2, BIN); 
      Serial.println(B_3, BIN); 
      
      if( Flag == 2 )
      { 
        

        switch (B_0)
        {
          case  1: 
          {
            B_0 = 1;
            break;
          }
          case  3: 
          {
            _Packet = (_Packet >> (2)) ;
            Type_Byte ++;
            
            B_0 = 0;
            break;
          }
          case  6:
          {
            _Packet = (_Packet >> (2)) ;
            B_0 = 0;
            break;
          }
          case  7:
          {
            _Packet = (_Packet >> (2)) ;
            Type_Byte ++;
            
            B_0 = 0;
            break;
          }
          case  12:
          {
            _Packet = (_Packet >> (2)) ;
            Type_Byte ++;
            
            B_0 = 0;
            break;
          }
          default:
          {
            B_0 = 0;
            break;
          }
        }
        
        switch (B_1)
        {
          case  1: 
          {
            B_1 = 1;
            break;
          }
          case  3: 
          {
            _Packet = (_Packet >> (2)) ;
            Type_Byte ++;
            
            _Packet += 64;
            B_1 = 0;
            break;
          }
          case  6:
          {
            _Packet = (_Packet >> (2)) ;
            Type_Byte ++;
            
            _Packet += 64;
            B_1 = 0;
            break;
          }
          case  7:
          {
            _Packet = (_Packet >> (2)) ;
            Type_Byte ++;
            
            _Packet += 64;
            B_1 = 0;
            break;
          }
          case  12:
          {
            _Packet = (_Packet >> (2)) ;
            Type_Byte ++;
            
            _Packet += 64;
            B_1 = 0;
            break;
          }
          default:
          {
            B_1 = 0;
            break;
          }
        }
        
        switch (B_2)
        {
          case  1: 
          {
            B_2 = 1;
            break;
          }
          case  3: 
          {
            _Packet = (_Packet >> (2)) ;
            Type_Byte ++;
            
            _Packet += 128;
            B_2 = 0;
            break;
          }
          case  6:
          {
            _Packet = (_Packet >> (2)) ;
            Type_Byte ++;
            
            _Packet += 128;
            B_2 = 0;
            break;
          }
          case  7:
          {
            _Packet = (_Packet >> (2)) ;
            Type_Byte ++;
            
            _Packet += 128;
            B_2 = 0;
            break;
          }
          case  12:
          {
            _Packet = (_Packet >> (2)) ;
            Type_Byte ++;
            
            _Packet += 128;
            B_2 = 0;
            break;
          }
          default:
          {
            B_2 = 0;
            break;
          }
        }
        
        switch (B_3)
        {
          case  1: 
          {
            B_3 = 1;
            break;
          }
          case  3: 
          {
            _Packet = (_Packet >> (2)) ;
            Type_Byte ++;
            
            _Packet += 192;
            B_3 = 0;
            break;
          }
          case  6:
          {
            _Packet = (_Packet >> (2)) ;
            Type_Byte ++;
            
            _Packet += 192;
            B_3 = 0;
            break;
          }
          case  7:
          {
            _Packet = (_Packet >> (2)) ;
            Type_Byte ++;
            
            _Packet += 192;
            B_3 = 0;
            break;
          }
          case  12:
          {
            _Packet = (_Packet >> (2)) ;
            Type_Byte ++;
            
            _Packet += 192;
            B_3 = 0;
            break;
          }
          default:
          {
            B_3 = 0;
            break;
          }
        }
        Serial.print("\t _Packet_bin = \t");
        Serial.print(_Packet, BIN);
        Serial.print("\t _Packet = \t");
        Serial.println(_Packet);
        
        Flag = 0;
      }
      
    }
    else if ( (Type_Byte < 12) && Flag_Message )
    {
      Flag++;
      
      B_0 = B_0 << 1;
      B_1 = B_1 << 1;
      B_2 = B_2 << 1;
      B_3 = B_3 << 1;
      
      Serial.print("\t Flag = ");
      Serial.print(Flag);
      Serial.print("\t\t val = ");
      Serial.println(val);
      
      switch (val)
      {
        case   0 ... 50: 
        {
          B_0 += 1;
          break;
        }
        case 122 ... 240:
        {
          B_1 += 1;
          break;
        }
        case 260 ... 340:
        {
          B_2 += 1;
          break;
        }
        case 360 ... 450:
        {
          B_3 += 1;
          break;
        }
      }
      
      
      Serial.println(B_0, BIN);
      Serial.println(B_1, BIN);
      Serial.println(B_2, BIN); 
      Serial.println(B_3, BIN); 
      
      if( Flag == 2 )
      { 
        

        switch (B_0)
        {
          case  1: 
          {
            B_0 = 1;
            break;
          }
          case  3: 
          {
            _End = (_End >> (2)) ;
            Type_Byte ++;
            
            B_0 = 0;
            break;
          }
          case  6:
          {
            _End = (_End >> (2)) ;
            B_0 = 0;
            break;
          }
          case  7:
          {
            _End = (_End >> (2)) ;
            Type_Byte ++;
            
            B_0 = 0;
            break;
          }
          case  12:
          {
            _End = (_End >> (2)) ;
            Type_Byte ++;
            
            B_0 = 0;
            break;
          }
          default:
          {
            B_0 = 0;
            break;
          }
        }
        
        switch (B_1)
        {
          case  1: 
          {
            B_1 = 1;
            break;
          }
          case  3: 
          {
            _End = (_End >> (2)) ;
            Type_Byte ++;
            
            _End += 64;
            B_1 = 0;
            break;
          }
          case  6:
          {
            _End = (_End >> (2)) ;
            Type_Byte ++;
            
            _End += 64;
            B_1 = 0;
            break;
          }
          case  7:
          {
            _End = (_End >> (2)) ;
            Type_Byte ++;
            
            _End += 64;
            B_1 = 0;
            break;
          }
          case  12:
          {
            _End = (_End >> (2)) ;
            Type_Byte ++;
            
            _End += 64;
            B_1 = 0;
            break;
          }
          default:
          {
            B_1 = 0;
            break;
          }
        }
        
        switch (B_2)
        {
          case  1: 
          {
            B_2 = 1;
            break;
          }
          case  3: 
          {
            _End = (_End >> (2)) ;
            Type_Byte ++;
            
            _End += 128;
            B_2 = 0;
            break;
          }
          case  6:
          {
            _End = (_End >> (2)) ;
            Type_Byte ++;
            
            _End += 128;
            B_2 = 0;
            break;
          }
          case  7:
          {
            _End = (_End >> (2)) ;
            Type_Byte ++;
            
            _End += 128;
            B_2 = 0;
            break;
          }
          case  12:
          {
            _End = (_End >> (2)) ;
            Type_Byte ++;
            
            _End += 128;
            B_2 = 0;
            break;
          }
          default:
          {
            B_2 = 0;
            break;
          }
        }
        
        switch (B_3)
        {
          case  1: 
          {
            B_3 = 1;
            break;
          }
          case  3: 
          {
            _End = (_End >> (2)) ;
            Type_Byte ++;
            
            _End += 192;
            B_3 = 0;
            break;
          }
          case  6:
          {
            _End = (_End >> (2)) ;
            Type_Byte ++;
            
            _End += 192;
            B_3 = 0;
            break;
          }
          case  7:
          {
            _End = (_End >> (2)) ;
            Type_Byte ++;
            
            _End += 192;
            B_3 = 0;
            break;
          }
          case  12:
          {
            _End = (_End >> (2)) ;
            Type_Byte ++;
            
            _End += 192;
            B_3 = 0;
            break;
          }
          default:
          {
            B_3 = 0;
            break;
          }
        }
        Serial.print("\t _End_bin = \t");
        Serial.print(_End, BIN);
        Serial.print("\t _End = \t");
        Serial.println(_End);
        
        Flag = 0;
      }
      
    }
    else if ( (Type_Byte < 13) && Flag_Message )
    {
      Flag_Message = 0;
      
      Serial.print("_Start = ");
      Serial.println(_Start);
      
      Serial.print("_Packet  = ");
      Serial.println(_Packet );
      
      Serial.print("_End = ");
      Serial.println(_End );

      if (_Start == _End)
      {
        Serial.print("Сообщение доставлено и равно ");
        Serial.println(_Packet );
      }
      else
      {
        Serial.println("ERROR");
      }
      Serial.print("\nFlag_Message = ");
      Serial.println(Flag_Message);

      _Start = 0;
      _Packet = 0;
      _End = 0;
      
      Type_Byte = 0;

      Serial.print("_Start = ");
      Serial.println(_Start);
      Serial.print("_Packet  = ");
      Serial.println(_Packet );
      Serial.print("_End = ");
      Serial.println(_End );
      Serial.print("\nFlag_Message = ");
      Serial.println(Flag_Message);
      Serial.print("Type_Byte = ");
      Serial.println(Flag_Message);
    }
    
    /*
    switch (val)
    {
      case   0 ... A_0: 
      {
        break;
      }
      case A_1 ... A_2:
      {
        break;
      }
      case A_3 ... A_4:
      {
        break;
      }
      case A_5 ... A_6:
      {
        break;
      }
    }
    */
  }
}
