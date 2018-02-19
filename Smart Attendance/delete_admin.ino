void delete_admin()
{
 // Serial.println("Give ID: ");
  long opening_time = millis();
  long ellapsed_time;
  char key = keypad.getKey();
  while(!key)
  {
    ellapsed_time = millis()-opening_time;
    key = keypad.getKey();
    if(ellapsed_time>=20000)
    {
   //   Serial.println("TimeOut");
      admin_menu();
      return;
    }
  }
  if (key){
   // Serial.println(key);
    if(key =='0' || key =='1' || key == '2')
    {
      int id = key -'0';
//      Serial.println(id);
      if(fps.DeleteID(id))
      {
     //   Serial.println("Successfully deleted");
        admin_menu();
      }
      else
      {
       // Serial.println("Not Successful");
        admin_menu();
      }
    }
    else
    {
     // Serial.println("There's only 3 admins");
      admin_menu();
    }
  }
  
}

