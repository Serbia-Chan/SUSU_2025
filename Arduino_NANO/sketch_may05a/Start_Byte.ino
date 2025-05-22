void Start_B()
{
  D_Time = micros() - Messages_Time;

  if ( D_Time == Time_Cnst )
  {
    Serial.println("Отправка стартого Бита.");
    Serial.print("\t Время: ");
    
    Messages_Time = micros();
    Serial.println(Messages_Time);
    
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
        digitalWrite(11, 0);
        digitalWrite(12, 1);
        bitX2++;
        break;
      }
      case 2:
      {
        digitalWrite(10, 0);
        digitalWrite(11, 1);
        digitalWrite(12, 1);
        bitX2++;
        break;
      }
      case 3:
      {
        digitalWrite(10, 0);
        digitalWrite(11, 0);
        digitalWrite(12, 0);
        Flag_Start  = 0;
        Flag_Packet = 1;
        
        bitX2 = 0;
        break;
      }
      
    }
  }
}
