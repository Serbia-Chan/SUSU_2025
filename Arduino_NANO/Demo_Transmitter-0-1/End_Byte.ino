void End_B()
{
  D_Time = micros() - Messages_Time;

  if ( D_Time == Time_Cnst )
  {   
    Serial.println("Отправка конечного Бита.");
    Serial.print("\t Время: ");
    
    Messages_Time = micros();
    
    Serial.println(Messages_Time);

    Serial.println("bitX2: ");              Serial.println(bitX2);
    switch(bitX2)
    {
      case 0:
      {
        digitalWrite(10, 1);
        digitalWrite(11, 1);
        digitalWrite(12, 1);
        bitX2++;
        break;
      }
      case 1:
      {
        digitalWrite(10, 0);
        digitalWrite(11, 1);
        digitalWrite(12, 1);
        bitX2++;
        break;
      }
      case 2:
      {
        digitalWrite(10, 0);
        digitalWrite(11, 0);
        digitalWrite(12, 1);
        bitX2++;
        break;
      }
      case 3:
      {
        digitalWrite(10, 0);
        digitalWrite(11, 0);
        digitalWrite(12, 0);
        bitX2++;
        break;
      }
      case 4:
      {
        digitalWrite(10, 0);
        digitalWrite(11, 0);
        digitalWrite(12, 0);
        Flag_End      = 0;
        Flag_Message  = 0;
        Flad_Rattle_INT0 = true;
        bitX2 = 0;
        break;
      }
      Serial.print("10: ");
      Serial.println(digitalRead(10));
      Serial.print("11: ");
      Serial.println(digitalRead(11));
      Serial.print("12: ");
      Serial.println(digitalRead(12));
      
    }
  }
}
