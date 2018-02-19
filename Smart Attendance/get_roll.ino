//returns int roll number entered after # is pressed.
//timeouts after 30s returns -420
int get_roll()
{
  String number;
  long opening_time = millis();
  long ellapsed_time;
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
        return -420;
      }
    }
    if (key){
      if(key!='#')
      {
        number += key ;
        lcd.setCursor(13,0);
        lcd.print(number);
      }
      else if(key=='#')
      {
        long num = number.toInt();
        number ="";
        return num;
      }
    }
  }
}
