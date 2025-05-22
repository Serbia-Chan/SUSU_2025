void Packet_B( uint8_t Byte )
{
  D_Time = micros() - Messages_Time;

  if ( D_Time == Time_Cnst )
  {
    Serial.println("Отправка пакета.");
    Serial.print("\t Время: ");
    
    Messages_Time = micros();
    Serial.println(Messages_Time);
    
    uint8_t Bytes_bitX2 = 0;
    uint8_t D_Byte      = 0;
    D_Byte      = 0b00000011 << ( bitX2 * 2 );
    Bytes_bitX2 = Byte & D_Byte;
    
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

    if (bitX2)
    {
      Flag_Packet = 0;
      Flag_End    = 1;
      bitX2       = 0;
    }
  
  }

}
