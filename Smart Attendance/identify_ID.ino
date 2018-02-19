// Identify fingerprint test
//this function waits until a finger is pressed or 20s whichever is less
//returns id if identified
//and -420 if finger not found
//turns off the led
int identify_ID()
{
  long LED_on_time;
  long LED_time;
  int id;
  String student_name;
  
  fps.SetLED(true);
  LED_on_time = millis();
  
  while(!fps.IsPressFinger())
  {
    LED_time = millis()-LED_on_time; 
    if(LED_time>=20000)
    {
//      Serial.println("TimeOut");
      
      lcd.clear();
      lcd.print("TimeOut");
      delay(2000);
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("AC~DC Labs");
      
      fps.SetLED(false);
      return -420;
    }
    delay(100);
  }
  if (fps.IsPressFinger())
  {
  //    Serial.println("in Identify_ID finger is pressed");
      fps.CaptureFinger(false);
      id = fps.Identify1_N();
      if (id <200)
      {
//        Serial.print("Verified ID:");
//        Serial.println(id);
        if(id>2)
        {
          student_name = returnName(id-2);
//          Serial.print("Thank you ");
//          Serial.println(id);
//          Serial.print(student_name);
          savetoEEPROM(id-2);

          lcd.clear();
          lcd.print("Thank you ");
          lcd.setCursor(0,1);
          lcd.print(student_name);
        }
        fps.SetLED(false);
        delay(500);
        fps.SetLED(true);
        delay(500);
        fps.SetLED(false);
//        Serial.println("before return");
        return id;
      }
      else
      {
   //     Serial.println("Finger not found");

        lcd.clear();
        lcd.print("Not Found");
        
        fps.SetLED(false);
        return -420;
      }
//      Serial.println("after else");
   }
   return -420;
}
