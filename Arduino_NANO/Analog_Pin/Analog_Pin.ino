int val = 0;
//int A_0 = 0, A_1, A_2, A_3, A_4, A_5, A_6 = 0;
void setup() {/*
  A_0 = 10; //1024*0.01;
  A_1 = 133 + 1024*0.02;
  A_2 = 133 + 1024*0.015;
  A_3 = 259 + 1024*0.04;
  A_4 = 259 + 1024*0.025;
  A_5 = 375 + 1024*0.02;
  A_6 = 375 + 1024*0.005;*/
  
  Serial.begin(1000000);
  pinMode(A7, INPUT);
}

void loop()
{
  val = analogRead(A7);
  delayMicroseconds(100);
  //Serial.println(val);
  
  switch (val)
  {
    case   0 ... 10: 
    {
      break;
    }
    case 112 ... 148:
    {
      break;
    }
    case 218 ... 254:
    {
      break;
    }
    case 354 ... 380:
    {
      break;
    }
  }

  Serial.println(val);
  
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
