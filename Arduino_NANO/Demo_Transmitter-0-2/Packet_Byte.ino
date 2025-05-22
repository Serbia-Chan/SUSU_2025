void Packet_B( uint8_t Byte )
{
  D_Time = micros() - Messages_Time;

  if ( D_Time == Time_Cnst )
  {
    Serial.print("\t\t Пакет: ");
    Serial.println(Byte);
    
    Serial.println("\t\t\t Отправка пакета.");
    Serial.print("\t\t\t Время: ");
    
    Messages_Time = micros();
    Serial.println(Messages_Time);
    
    uint8_t Bytes_bitX2 = Byte >> ( bitX2 * 2 );
    Serial.print("\t\t\t 1-Bytes_bitX2: ");
    Serial.println(Bytes_bitX2);
    uint8_t D_Byte      = 0b00000011;
    Serial.print("\t\t\t D_Byte: ");
    Serial.println(D_Byte);
    Bytes_bitX2 = D_Byte & Bytes_bitX2;
    Serial.print("\t\t\t 2-Bytes_bitX2: ");
    Serial.println(Bytes_bitX2);
    
    Serial.print("\t\t\t bitX2: ");
    Serial.println(bitX2);
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
      Flag_End    = 1;
      bitX2       = 0;
    }
    
      Serial.print("\t\t\t 10: ");
      Serial.print(digitalRead(10));
      Serial.print("  11: ");
      Serial.print(digitalRead(11));
      Serial.print("  12: ");
      Serial.println(digitalRead(12));
  
  }

}
