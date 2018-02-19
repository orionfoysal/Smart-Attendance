//this function first checks whether there is a fingerprint previously stored with the ID number
//if not, then it Enrolls a fingerprint with the ID number
//returns false if it cannot enroll the ID by any means
//returns true if it successfully enroll the ID
bool Enroll(int ID)
{
  bool usedid;
  usedid = fps.CheckEnrolled(ID);
  if (usedid == true)
  {
//    Serial.print(ID-2);
//    Serial.println("  has been Used Once");

    lcd.clear();
    lcd.print(ID-2);
    lcd.setCursor(3, 0);
    lcd.print("used once");

    fps.SetLED(false);
    return false;
  }
  fps.SetLED(true);
  fps.EnrollStart(ID);
  // enroll
 // Serial.print("Press finger to Enroll");

  lcd.clear();
  lcd.print("press finger:");

  //  Serial.println(ID);
  long opening_time = millis();
  long ellapsed_time;
  while (fps.IsPressFinger() == false)
  {
    ellapsed_time = millis() - opening_time;
    if (ellapsed_time >= 25000)
    {
   //   Serial.println("TimeOut");

      lcd.clear();
      lcd.print("Timeout");
      fps.SetLED(false);
      delay(2000);
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("AC~DC Labs");
      

      return false;
    }
    delay(100);
  }
  bool bret = fps.CaptureFinger(true);
  int iret = 0;
  if (bret != false)
  {
    //Serial.println("Remove finger");
    lcd.clear();
    lcd.print("Remove");

    fps.Enroll1();
    while (fps.IsPressFinger() == true) delay(100);
    //Serial.println("Press same finger again");

    lcd.clear();
    lcd.print("Press again:");

    while (fps.IsPressFinger() == false) delay(100);
    bret = fps.CaptureFinger(true);
    if (bret != false)
    {
     // Serial.println("Remove finger");

      lcd.clear();
      lcd.print("Remove");

      fps.Enroll2();
      while (fps.IsPressFinger() == true) delay(100);
     // Serial.println("Press same finger yet again");

      lcd.clear();
      lcd.print("Press yet again:");


      while (fps.IsPressFinger() == false) delay(100);
      bret = fps.CaptureFinger(true);
      if (bret != false)
      {
       // Serial.println("Remove finger");

        lcd.clear();
        lcd.print("Remove");

        iret = fps.Enroll3();
        if (iret == 0)
        {
         // Serial.println("Enrolling Successfull");

          lcd.clear();
          lcd.print("Successful");
          fps.SetLED(false);
          delay(1000);
          fps.SetLED(true);
          delay(1000);
          fps.SetLED(false);
          return true;
        }
        else
        {
          if (iret == 3)
          {
           // Serial.println("Finger already exists!");
            lcd.clear();
            lcd.print("Finger exists!");
          }
          else
          {
//            Serial.print("Enrolling Failed with error:");
//            Serial.println(iret);

            lcd.clear();
            lcd.print("Failed");
            lcd.setCursor(0, 1);
            lcd.print(iret);
          }
        }
      }
      else
      {
  //      Serial.println("Failed to capture 3rd finger");

        lcd.clear();
        lcd.print("Failed");
      }
    }
    else
    {
    //    Serial.println("Failed to capture 2nd finger");
        lcd.clear();
        lcd.print("Failed");
    }
  }
  else
  {
  //  Serial.println("Failed to capture 1st finger");
    lcd.clear();
    lcd.print("Failed");
  }

  fps.SetLED(false);
  return false;
}
