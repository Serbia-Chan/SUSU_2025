void Packet_B( uint8_t Byte )
{
  D_Time = micros() - Messages_Time;

  if ( D_Time == Time_Cnst )
  {    
    Messages_Time = micros();
    
    uint8_t Bytes_bitX2 = Byte >> ( bitX2 * 2 );
    uint8_t D_Byte      = 0b00000011;
    
    Bytes_bitX2 = D_Byte & Bytes_bitX2;
    
    switch(Bytes_bitX2)
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
        digitalWrite(10, 0);
        digitalWrite(11, 0);
        digitalWrite(12, 1);
        
        break;
      }
      case 2:
      {
        digitalWrite(10, 0);
        digitalWrite(11, 1);
        digitalWrite(12, 1);
        
        break;
      }
      case 3:
      {
        digitalWrite(10, 1);
        digitalWrite(11, 1);
        digitalWrite(12, 1);
        
        break;
      }
    }

    bitX2++;

    if (bitX2 == 4)
    {
      Flag_Packet = 0;
      //Flag_End    = 1;
      
      Flag_Message  = 0;
      Flad_Rattle_INT0 = true;
      
      bitX2       = 0;
      delayMicroseconds(100);
      Trigger();
    }
  
  }

}
