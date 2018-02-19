//returns date string entered after # is pressed.
//timeouts after 30s returns -420 
String get_date()
{
  lcd.setCursor(5,0);
  String date;
  long opening_time = millis();
  long ellapsed_time;
  int count = 1;
  while(1)
  {
    char key = keypad.getKey();
    while(!key)
    {
      key = keypad.getKey();
      ellapsed_time = millis()-opening_time;
      if(ellapsed_time>=30000)
      {
     //   Serial.println("TimeOut");
        lcd.clear();
        lcd.print("TimeOut");
        delay(2000);
        return "";
      }
    }
    if (key){
      if(key!='#')
      {
        if(count < 6 &&(count % 3 ==0 || count%5==0))
          date += "-";
        date += key ;
        count++;
        lcd.setCursor(5,0);
        lcd.print(date);
      }
      else if(key=='#')
      {
        return date;
      }
    }
  }
}
