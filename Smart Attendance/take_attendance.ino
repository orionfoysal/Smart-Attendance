void take_attendance()
{
  String date;
  int id=-420;
 // Serial.println("Date: ");

  lcd.clear();
  lcd.print("Date:");
  
  date = get_date();
  if(date!= "")
  {
   // Serial.println(date);   //got the date
//    lcd.setCursor(5,0);
//    lcd.print(date);
    newDate(date);

   // Serial.println("Device Ready");
    lcd.setCursor(0,1);
    lcd.print("Device Ready");
    while(1)
    {
      char sw_key='\0';
      sw_key = keypad.getKey();
      while(sw_key!= '*')
      {
        sw_key = keypad.getKey();
        delay(30);
      }
      
      //while doing using switch
//      while(!digitalRead(sw));
//      delay(500);
     // Serial.println("in take attendance--> sw_key er while theke ber hoisi");
      id = identify_ID();
//      Serial.println(id);
      if(id>=0 && id<3)
      {
        generateString();
//        Serial.print("mainString: ");
//        Serial.println(mainString);
        updateAttendance(mainString);
        admin_menu();
      }
    }
  }
}
