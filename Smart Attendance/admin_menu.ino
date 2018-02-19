void admin_menu()
{
//  Serial.println("1.Add Admin");
//  Serial.println("2.Delete Admin");
//  Serial.println("1.Enroll Student");
//  Serial.println("2.Delete Student");
//  Serial.println("3.Take Attendance");
//  Serial.println("4.Exit");
  
  lcd.clear();
  lcd.print("1.New"); lcd.setCursor(11,0); lcd.print("2.Del"); lcd.setCursor(0,1);
  lcd.print("3.Att"); lcd.setCursor(6,1); lcd.print("4.Ex"); lcd.setCursor(11,1); lcd.print("5.Get");

  long opening_time = millis();
  long ellapsed_time;
  char key = keypad.getKey();
  while(!key)
  {
    ellapsed_time = millis()-opening_time;
    key = keypad.getKey();
    if(ellapsed_time>=30000)
    {
     // Serial.println("TimeOut");
      lcd.clear();
      lcd.print("Timeout");
      delay(2000);
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("AC~DC Labs");
      return;
    }
  }
  if (key){
    switch(key)
    {
//      case '1':
////        Serial.println("Add Admin");
//        add_admin();
//        break;
//      case '2':
////        Serial.println("2.Delete Admin");
//        delete_admin();
//        break;
      case '1':
//        Serial.println("3.Enroll Student");
        enroll_student();
        break;
      case '2':
//        Serial.println("4.Delete Student");
        delete_student();
        break;
      case '3':
//        Serial.println("5.Take Attendance");
        take_attendance();
        break;
      case '4':
       // Serial.println("AC~DC Labs");
        lcd.clear();
        lcd.setCursor(2,0);
        lcd.print("AC~DC Labs");
        return;
        break; 
      case '5':
        lcd.clear();
        lcd.setCursor(1,0);
        lcd.print("Uploading..");
//        while(1)
//        {
//          if(Serial.available()>0)
//          {
//            char ch = Serial.read();
//            if(ch == 'h')
//              break;
//          }
//        }
        char myCh;
        do
        {
          if(Serial.available()>0)
          {
            myCh = Serial.read();            
          }
        }while(myCh!='h');
        
        sendData();
        break;
      default:
       // Serial.println("Invalid");
        lcd.clear();
        lcd.print("Invalid");
        delay(2000);
        admin_menu();
        break;
    }
  }
}

