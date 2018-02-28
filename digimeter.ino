#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // Rx, Tx of Arduino

void setup()
{
  pinMode(2,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(7,OUTPUT);

  digitalWrite(7,LOW);

  Serial.begin(57600);
  while (!Serial) 
  {
    ;
  }

  delay(500);

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  
}

int nof_pulses = 0;
int initValue, currValue;
float data=0;
float temp;
int distance()
{
  Serial.println(nof_pulses * 5.44); //Least count of the position encoder used = 5.44
  
  while (Serial.available() >= 0) 
  {     
        data = (nof_pulses * 5.44);
        break;
  }
  initValue = digitalRead(2);
}


"""
This function takes in the value corresponding to the distance covered 
and compares it with the value entered by the user.
Produces a beeping sound in the buzzer if the two values are equal
i.e The required distance has been covered.
"""

int distance2(float check)
{

  Serial.println(nof_pulses * 5.44);
  float val=nof_pulses * 5.44;
  
  if(val>=check)
  {
    Serial.println("reached");
    Serial.println("buzzerbeep");
    tone(12,440);
    delay(500);
    tone(12,880);
    delay(1000);
    noTone(12);
    return 1;
  }
  initValue = digitalRead(2);
  return 0;
}


void loop()
{
    nof_pulses=0;
    String s = "";
    if (mySerial.available()) //Checking connection with the Bluetooth module
    {
      
      char c;
      while((c = mySerial.read()))
      {
        Serial.println("reading");
        s += c;
        Serial.println(s);
        delay(10);
        break;
      }

      Serial.println("Received: " + s);

      """
      Selecting Application 2 :
      The device would receive user input for the length to be measured.
      The buzzer present would produce a temporary beeping sound after the entered length was covered.
      
      """
      
      if(s.toInt()==2) 
      {

        Serial.println("in app 2");
        String tomeasure = "";
        int ch1;
        delay(20000);
        tone(12,440); //beeping sound to indicate beginning of measurement
        delay(500);
        noTone(12); 
        
        
        if (mySerial.available()) 
        {
          
          Serial.println("getting data");
          int ch;
          int cnt=0;
          while((ch = mySerial.read())) 
          {
            cnt++;
            Serial.println(cnt);
            Serial.println("hello");
            Serial.println(ch);
            tomeasure+= String(ch);
            delay(10);
            Serial.println("tomeasure"+tomeasure);
            break;
          }

          while((ch1 = mySerial.read())) 
          {
            break;
          }
          
        }

        Serial.println("gotwhat tomeasure");
        
        float final=tomeasure.toInt()+ch1*255+ch1; // Mapping the value received by the position encoder to actual distance traversed
        Serial.println(final);
        int res=0;
        while(res!=1)
        {

              while((currValue = digitalRead(2)) == initValue) 
                delay(5);
              
              while((currValue = digitalRead(2)) != initValue) 
                delay(5);
              ++nof_pulses;
              res=distance2(final); 
        }



        Serial.print("end");

      
      }
    }
    
}


       if(s.toInt()==1)
       {
            //APPLICATION 1
            
            Serial.println("in app 1");

            delay(15000);
            
            String numparam = "";
        
            if (mySerial.available()) 
            {
                Serial.println("taking numparam");
                char ch;
                while((ch = mySerial.read())) 
                {
                      numparam += ch;
                      delay(10);
                      break;
                }
          
            }

            Serial.println("numparam"+numparam);

            //------------------------------------------------------------------

            if(numparam.toInt()==1) //length
            {

                  Serial.println("in length");
                  tone(12,440);
                  delay(500);
                  noTone(12);

                  

                  int val=1;
                  

                  while(val!=50)
                  {
                         
                          
                          //Serial.println(val);

                          temp=data;
                          
                          while((currValue = digitalRead(2)) == initValue) 
                          {
                                delay(5);
                          }
          
                          while((currValue = digitalRead(2)) != initValue) 
                          {
                                delay(5);
                          }
        
                          
                          


                          if (mySerial.available()>0) 
                         {
                                Serial.println("ifkepppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppandr");
                                int ch;
                                while((ch=mySerial.read()))
                                {
                                      Serial.println("lklklk");
                                      val=ch;
                                      delay(10);
                                      break;
                                }
                                Serial.println("ch");
                                Serial.println(val);
          
                          }

                          if(val==50)
                          {
                            Serial.print("kooooooooooooooooooo");
                            break;
                          }

                          ++nof_pulses;
                          distance();
                          

                         

                  }
                  tone(12,440);
                  delay(500);
                  noTone(12);
                  mySerial.println(temp);

            }

            //---------------------------------------------------------------------------------------------------------------------------------------
        
        

            else if(numparam.toInt()==2)    //area
            {
                  Serial.println("in area");


                  delay(10000);
                  
                  
                  int x=5;
                  if (mySerial.available()>=0) 
                  {
          
                      int ch;
                      while((ch = mySerial.read())) 
                      {
                           x=ch;
                          delay(10);
                          break;
                      }
          
                  }
                  Serial.print("x is");
                  Serial.println(x);
                  
                  if(x==49) //circle
                  {

                        Serial.println("in circle");
                        delay(2000);
                        int z;
                        if (mySerial.available()>=0) 
                        {
          
                            int ch;
                            while((ch = mySerial.read())) 
                            {
                                z=ch;
                                delay(10);
                                break;
                            }
          
                        }

                        Serial.print("z is");
                        Serial.println(z);

                        if(z==49)    //circumference
                        {
                          

                             Serial.println("in circumference");
                             tone(12,440);
                             delay(500);
                             noTone(12);

                             
                             int val=1;
                            
                             while(val!=50)
                          {
                         
                               temp=data;     // Temp is data again


                          
                              while((currValue = digitalRead(2)) == initValue) 
                              {
                                  delay(5);
                              }
          
                              while((currValue = digitalRead(2)) != initValue) 
                              {
                                  delay(5);
                              }

                              
                             if (mySerial.available()>0) 
                         {
                                Serial.println("ifkepppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppandr");
                                int ch;
                                while((ch=mySerial.read()))
                                {
                                      Serial.println("lklklk");
                                      val=ch;
                                      delay(10);
                                      break;
                                }
                                Serial.println("ch");
                                Serial.println(val);
          
                          }

                          if(val==50)
                          {
                            Serial.print("kooooooooooooooooooo");
                            break;
                          }
        
                              ++nof_pulses;
                              distance();  
                        }
                        tone(12,440);
                        delay(500);
                        noTone(12);
                        mySerial.println(temp);
                  }
                  }

                  //-----------------------------------------------------------------------------------------------------------------------------------------------------------


                  else if(x==50)   //triangle
                  {
                        Serial.println("in triangle");
                        delay(5000);
                        int z1;
                        if (mySerial.available()>=0) 
                        {
          
                            int ch;
                            while((ch = mySerial.read())) 
                            {
                                z1=ch;
                                delay(10);
                                break;
                            }
          
                        }

                        Serial.print("z1 is");
                        Serial.print(z1);

                        if(z1==48)
                        {

                          tone(12,440);
                          delay(500);
                          noTone(12);
                            
                             int val=1;
                            
                             while(val!=50)
                          {
                         
                               temp=data;     // Temp is data again


                          
                              while((currValue = digitalRead(2)) == initValue) 
                              {
                                  delay(5);
                              }
          
                              while((currValue = digitalRead(2)) != initValue) 
                              {
                                  delay(5);
                              }

                              
                             if (mySerial.available()>0) 
                         {
                                Serial.println("ifkepppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppandr");
                                int ch;
                                while((ch=mySerial.read()))
                                {
                                      Serial.println("lklklk");
                                      val=ch;
                                      delay(10);
                                      break;
                                }
                                Serial.println("ch");
                                Serial.println(val);
          
                          }

                          if(val==50)
                          {
                            Serial.print("kooooooooooooooooooo");
                            break;
                          }
        
                              ++nof_pulses;
                              distance();  
                        }
                        tone(12,440);
                        delay(500);
                        noTone(12);
                        
                        mySerial.println(temp);
                         
                        }

                        
                        nof_pulses=0;
                        delay(5000);
                        
                        int z2;
                        if (mySerial.available()>=0) 
                        {
          
                            int ch;
                            while((ch = mySerial.read())) 
                            {
                                z2=ch;
                                delay(10);
                                break;
                            }
          
                        }

                        Serial.println("z2 is");
                        Serial.println(z2);
                        
                        if(z2==49)
                        {
                               //reset
                        Serial.println("in triangle side 2");
                        tone(12,440);
                        delay(500);
                        noTone(12);
                        
                             int val=1;
                            
                             while(val!=50)
                            {
                         
                               temp=data;     // Temp is data again


                          
                              while((currValue = digitalRead(2)) == initValue) 
                              {
                                  delay(5);
                              }
          
                              while((currValue = digitalRead(2)) != initValue) 
                              {
                                  delay(5);
                              }

                              
                             if (mySerial.available()>0) 
                         {
                                Serial.println("ifkepppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppandr");
                                int ch;
                                while((ch=mySerial.read()))
                                {
                                      Serial.println("lklklk");
                                      val=ch;
                                      delay(10);
                                      break;
                                }
                                Serial.println("ch");
                                Serial.println(val);
          
                          }

                          if(val==50)
                          {
                            Serial.print("kooooooooooooooooooo");
                            break;
                          }
        
                              ++nof_pulses;
                              distance();  
                        }
                        
                        //-----------------------------


                        tone(12,440);
                        delay(500);
                        noTone(12);
                         mySerial.println(temp);
                         
                         
                        }


                        nof_pulses=0;
                        delay(5000);
                        
                        int z3;
                        if (mySerial.available()>=0) 
                        {
          
                            int ch;
                            while((ch = mySerial.read())) 
                            {
                                z3=ch;
                                delay(10);
                                break;
                            }
          
                        }


                        if(z3==50)
                        {
                              //reset
                              //side3 of triangle

                              //in next text box

                              Serial.println("in triangle side 3");

                              tone(12,440);
                              delay(500);
                              noTone(12);
                  
                             int val=1;
                            
                             while(val!=50)
                            {
                         
                               temp=data;     // Temp is data again


                          
                              while((currValue = digitalRead(2)) == initValue) 
                              {
                                  delay(5);
                              }
          
                              while((currValue = digitalRead(2)) != initValue) 
                              {
                                  delay(5);
                              }

                              
                             if (mySerial.available()>0) 
                         {
                                Serial.println("ifkepppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppandr");
                                int ch;
                                while((ch=mySerial.read()))
                                {
                                      Serial.println("lklklk");
                                      val=ch;
                                      delay(10);
                                      break;
                                }
                                Serial.println("ch");
                                Serial.println(val);
          
                          }

                          if(val==50)
                          {
                            Serial.print("kooooooooooooooooooo");
                            break;
                          }
        
                              ++nof_pulses;
                              distance();  
                        }


                        tone(12,440);
                        delay(500);
                        noTone(12);
                         mySerial.println(temp);

                        
                  }

                  //--------------------------------------------------------------------------------------------------------------------------------------------------------------
              }
                  else if(x==51)   //rectangle
                  {

                        Serial.println("in rectangle");
                        delay(5000);
                        tone(12,440);
                        delay(500);
                        noTone(12);
                        
                        int z1;
                        
                        if (mySerial.available()>=0) 
                        {
          
                            int ch;
                            while((ch = mySerial.read())) 
                            {
                                z1=ch;
                                delay(10);
                                break;
                            }
          
                        }

                        Serial.print("z1 is");
                        Serial.print(z1);



                        if(z1==48)
                        {
                            
                             int val=1;
                            
                             while(val!=50)
                          {
                         
                               temp=data;     // Temp is data again


                          
                              while((currValue = digitalRead(2)) == initValue) 
                              {
                                  delay(5);
                              }
          
                              while((currValue = digitalRead(2)) != initValue) 
                              {
                                  delay(5);
                              }

                              
                             if (mySerial.available()>0) 
                         {
                                Serial.println("ifkepppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppandr");
                                int ch;
                                while((ch=mySerial.read()))
                                {
                                      Serial.println("lklklk");
                                      val=ch;
                                      delay(10);
                                      break;
                                }
                                Serial.println("ch");
                                Serial.println(val);
          
                          }

                          if(val==50)
                          {
                            Serial.print("kooooooooooooooooooo");
                            break;
                          }
        
                              ++nof_pulses;
                              distance();  
                        }
                        tone(12,440);
                        delay(500);
                        noTone(12);
                        
                        mySerial.println(temp);
                         
                        }

                        
                        nof_pulses=0;
                        delay(5000);
                        
                        int z2;
                        if (mySerial.available()>=0) 
                        {
          
                            int ch;
                            while((ch = mySerial.read())) 
                            {
                                z2=ch;
                                delay(10);
                                break;
                            }
          
                        }

                        Serial.println("z2 is");
                        Serial.println(z2);
                        
                        if(z2==49)
                        {
                               //reset
                        Serial.println("in breadth");
                              tone(12,440);
                              delay(500);
                              noTone(12);
                             int val=1;
                            
                             while(val!=50)
                            {
                         
                               temp=data;     // Temp is data again


                          
                              while((currValue = digitalRead(2)) == initValue) 
                              {
                                  delay(5);
                              }
          
                              while((currValue = digitalRead(2)) != initValue) 
                              {
                                  delay(5);
                              }

                              
                             if (mySerial.available()>0) 
                         {
                                Serial.println("ifkepppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppandr");
                                int ch;
                                while((ch=mySerial.read()))
                                {
                                      Serial.println("lklklk");
                                      val=ch;
                                      delay(10);
                                      break;
                                }
                                Serial.println("ch");
                                Serial.println(val);
          
                          }

                          if(val==50)
                          {
                            Serial.print("kooooooooooooooooooo");
                            break;
                          }
        
                              ++nof_pulses;
                              distance();  
                        }
                        
                        


                        tone(12,440);
                        delay(500);
                        noTone(12);
                         mySerial.println(temp);
                         
                         
                        }
                 }
          }



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
        
          else if(numparam.toInt()==3)
          {

                  Serial.println("in volume");
                  delay(10000);
                  
                  int x;
                  if (mySerial.available()>=0) 
                  {
          
                      int ch;
                      while((ch = mySerial.read())) 
                      {
                           x=ch;
                          delay(10);
                          break;
                      }
          
                  }
                  Serial.print("x is");
                  Serial.println(x);
               


                  if(x==49)   //cuboid
                  {
                        Serial.println("in cuboid");
                        delay(5000);
                        tone(12,440);
                        delay(500);
                        noTone(12);


                        
                        int z1;
                        if (mySerial.available()>=0) 
                        {
          
                            int ch;
                            while((ch = mySerial.read())) 
                            {
                                z1=ch;
                                delay(10);
                                break;
                            }
          
                        }

                        Serial.print("z1 is");
                        Serial.print(z1);

                        if(z1==48)
                        {
                            
                             int val=1;
                            
                             while(val!=50)
                          {
                         
                               temp=data;     // Temp is data again


                          
                              while((currValue = digitalRead(2)) == initValue) 
                              {
                                  delay(5);
                              }
          
                              while((currValue = digitalRead(2)) != initValue) 
                              {
                                  delay(5);
                              }

                              
                             if (mySerial.available()>0) 
                         {
                                Serial.println("ifkepppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppandr");
                                int ch;
                                while((ch=mySerial.read()))
                                {
                                      Serial.println("lklklk");
                                      val=ch;
                                      delay(10);
                                      break;
                                }
                                Serial.println("ch");
                                Serial.println(val);
          
                          }

                          if(val==50)
                          {
                            Serial.print("kooooooooooooooooooo");
                            break;
                          }
        
                              ++nof_pulses;
                              distance();  
                        }
                        tone(12,440);
                        delay(500);
                        noTone(12);
                        
                        mySerial.println(temp);
                         
                        }

                        
                        nof_pulses=0;
                        delay(5000);
                        
                        int z2;
                        if (mySerial.available()>=0) 
                        {
          
                            int ch;
                            while((ch = mySerial.read())) 
                            {
                                z2=ch;
                                delay(10);
                                break;
                            }
          
                        }

                        Serial.println("z2 is");
                        Serial.println(z2);
                        
                        if(z2==49)
                        {
                               //reset
                        Serial.println("breadthhhhhhh of cuboid");
                              tone(12,440);
                              delay(500);
                              noTone(12);
                             int val=1;
                            
                             while(val!=50)
                            {
                         
                               temp=data;     // Temp is data again


                          
                              while((currValue = digitalRead(2)) == initValue) 
                              {
                                  delay(5);
                              }
          
                              while((currValue = digitalRead(2)) != initValue) 
                              {
                                  delay(5);
                              }

                              
                             if (mySerial.available()>0) 
                         {
                                Serial.println("ifkepppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppandr");
                                int ch;
                                while((ch=mySerial.read()))
                                {
                                      Serial.println("lklklk");
                                      val=ch;
                                      delay(10);
                                      break;
                                }
                                Serial.println("ch");
                                Serial.println(val);
          
                          }

                          if(val==50)
                          {
                            Serial.print("kooooooooooooooooooo");
                            break;
                          }
        
                              ++nof_pulses;
                              distance();  
                        }
                        
                        //-----------------------------


                        tone(12,440);
                        delay(500);
                        noTone(12);
                         mySerial.println(temp);
                         
                         
                        }


                        nof_pulses=0;
                        delay(5000);
                        
                        int z3;
                        if (mySerial.available()>=0) 
                        {
          
                            int ch;
                            while((ch = mySerial.read())) 
                            {
                                z3=ch;
                                delay(10);
                                break;
                            }
          
                        }


                        if(z3==50)
                        {

                              //in next text box

                              Serial.println("heightttt");
                              tone(12,440);
                              delay(500);
                              noTone(12);
                              
                             int val=1;
                            
                             while(val!=50)
                            {
                         
                               temp=data;     // Temp is data again


                          
                              while((currValue = digitalRead(2)) == initValue) 
                              {
                                  delay(5);
                              }
          
                              while((currValue = digitalRead(2)) != initValue) 
                              {
                                  delay(5);
                              }

                              
                             if (mySerial.available()>0) 
                         {
                                Serial.println("ifkepppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppandr");
                                int ch;
                                while((ch=mySerial.read()))
                                {
                                      Serial.println("lklklk");
                                      val=ch;
                                      delay(10);
                                      break;
                                }
                                Serial.println("ch");
                                Serial.println(val);
          
                          }

                          if(val==50)
                          {
                            Serial.print("kooooooooooooooooooo");
                            break;
                          }
        
                              ++nof_pulses;
                              distance();  
                        }


                        tone(12,440);
                        delay(500);
                        noTone(12);
                         mySerial.println(temp);

                        
                  }
                  }



                  else if(x==50)   //cylinder
                  {

                        Serial.println("in cylinder");
                        delay(5000);
                        tone(12,440);
                        delay(500);
                        noTone(12);
                        
                        int z1;
                        
                        if (mySerial.available()>=0) 
                        {
          
                            int ch;
                            while((ch = mySerial.read())) 
                            {
                                z1=ch;
                                delay(10);
                                break;
                            }
          
                        }

                        Serial.print("z1 is");
                        Serial.print(z1);



                        if(z1==48)
                        {
                            
                             int val=1;
                            
                             while(val!=50)
                          {
                         
                               temp=data;     // Temp is data again


                          
                              while((currValue = digitalRead(2)) == initValue) 
                              {
                                  delay(5);
                              }
          
                              while((currValue = digitalRead(2)) != initValue) 
                              {
                                  delay(5);
                              }

                              
                             if (mySerial.available()>0) 
                         {
                                Serial.println("ifkepppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppandr");
                                int ch;
                                while((ch=mySerial.read()))
                                {
                                      Serial.println("lklklk");
                                      val=ch;
                                      delay(10);
                                      break;
                                }
                                Serial.println("ch");
                                Serial.println(val);
          
                          }

                          if(val==50)
                          {
                            Serial.print("kooooooooooooooooooo");
                            break;
                          }
        
                              ++nof_pulses;
                              distance();  
                        }
                        tone(12,440);
                        delay(500);
                        noTone(12);
                        
                        mySerial.println(temp);
                         
                        }

                        
                        nof_pulses=0;
                        delay(5000);
                        
                        int z2;
                        if (mySerial.available()>=0) 
                        {
          
                            int ch;
                            while((ch = mySerial.read())) 
                            {
                                z2=ch;
                                delay(10);
                                break;
                            }
          
                        }

                        Serial.println("z2 is");
                        Serial.println(z2);
                        
                        if(z2==49)
                        {
                               //reset
                        Serial.println("in height of cyl");
                              tone(12,440);
                              delay(500);
                              noTone(12);
                             int val=1;
                            
                             while(val!=50)
                            {
                         
                               temp=data;     // Temp is data again


                          
                              while((currValue = digitalRead(2)) == initValue) 
                              {
                                  delay(5);
                              }
          
                              while((currValue = digitalRead(2)) != initValue) 
                              {
                                  delay(5);
                              }

                              
                             if (mySerial.available()>0) 
                         {
                                Serial.println("ifkepppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppandr");
                                int ch;
                                while((ch=mySerial.read()))
                                {
                                      Serial.println("lklklk");
                                      val=ch;
                                      delay(10);
                                      break;
                                }
                                Serial.println("ch");
                                Serial.println(val);
          
                          }

                          if(val==50)
                          {
                            Serial.print("kooooooooooooooooooo");
                            break;
                          }
        
                              ++nof_pulses;
                              distance();  
                        }
                        
                        


                        tone(12,440);
                        delay(500);
                        noTone(12);
                         mySerial.println(temp);
                         
                         
                        }
                 }



                 else if(x==51)   //cone
                 {

                        Serial.println("in cone");
                        delay(5000);
                        tone(12,440);
                        delay(500);
                        noTone(12);
                        
                        int z1;
                        
                        if (mySerial.available()>=0) 
                        {
          
                            int ch;
                            while((ch = mySerial.read())) 
                            {
                                z1=ch;
                                delay(10);
                                break;
                            }
          
                        }

                        Serial.print("z1 is");
                        Serial.print(z1);



                        if(z1==48)
                        {
                            
                             int val=1;
                            
                             while(val!=50)
                          {
                         
                               temp=data;     // Temp is data again


                          
                              while((currValue = digitalRead(2)) == initValue) 
                              {
                                  delay(5);
                              }
          
                              while((currValue = digitalRead(2)) != initValue) 
                              {
                                  delay(5);
                              }

                              
                             if (mySerial.available()>0) 
                         {
                                Serial.println("ifkepppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppandr");
                                int ch;
                                while((ch=mySerial.read()))
                                {
                                      Serial.println("lklklk");
                                      val=ch;
                                      delay(10);
                                      break;
                                }
                                Serial.println("ch");
                                Serial.println(val);
          
                          }

                          if(val==50)
                          {
                            Serial.print("kooooooooooooooooooo");
                            break;
                          }
        
                              ++nof_pulses;
                              distance();  
                        }
                        tone(12,440);
                        delay(500);
                        noTone(12);
                        
                        mySerial.println(temp);
                         
                        }

                        
                        nof_pulses=0;
                        delay(5000);
                        
                        int z2;
                        if (mySerial.available()>=0) 
                        {
          
                            int ch;
                            while((ch = mySerial.read())) 
                            {
                                z2=ch;
                                delay(10);
                                break;
                            }
          
                        }

                        Serial.println("z2 is");
                        Serial.println(z2);
                        
                        if(z2==49)
                        {
                               //reset
                        Serial.println("in height of cone");
                              tone(12,440);
                              delay(500);
                              noTone(12);
                             int val=1;
                            
                             while(val!=50)
                            {
                         
                               temp=data;     // Temp is data again


                          
                              while((currValue = digitalRead(2)) == initValue) 
                              {
                                  delay(5);
                              }
          
                              while((currValue = digitalRead(2)) != initValue) 
                              {
                                  delay(5);
                              }

                              
                             if (mySerial.available()>0) 
                         {
                                Serial.println("ifkepppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppandr");
                                int ch;
                                while((ch=mySerial.read()))
                                {
                                      Serial.println("lklklk");
                                      val=ch;
                                      delay(10);
                                      break;
                                }
                                Serial.println("ch");
                                Serial.println(val);
          
                          }

                          if(val==50)
                          {
                            Serial.print("kooooooooooooooooooo");
                            break;
                          }
        
                              ++nof_pulses;
                              distance();  
                        }
                        
                        


                        tone(12,440);
                        delay(500);
                        noTone(12);
                         mySerial.println(temp);
                         
                         
                        }
                 }
            
            
            }
            
        }
}      
