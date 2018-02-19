void delete_student()
{
//  Serial.println("Give Roll: ");
  
  lcd.clear();
  lcd.print("Give Roll:");
  
//  long opening_time = millis();
//  long ellapsed_time;
//  char key = keypad.getKey();
  int roll = get_roll()+2;
  
  if (roll){
//    Serial.println(key);
    if(roll<200 && roll>0)
    {
//      Serial.println(id);
      if(fps.DeleteID(roll))
      {
  //      Serial.println("Successfully deleted");
        
        lcd.clear();
        lcd.print("Deleted");
        delay(2000);
        
        admin_menu();
      }
      else
      {
    //    Serial.println("Not Successful");
        lcd.clear();
        lcd.print("Not Successful");
        delay(2000);
        admin_menu();
      }
    }
    else
    {
    //  Serial.println("Wrong Roll Number");
      lcd.clear();
      lcd.print("Wrong Roll");
      delay(2000);
      admin_menu();
    }
  }
}

