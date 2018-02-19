void enroll_student()
{
 // Serial.println("Press Roll Number: ");

  lcd.clear();
  lcd.print("Roll Number:");

  int roll = get_roll()+2;
  if (roll){
   // Serial.println(roll);
    
//    lcd.setCursor(13,0);
//    lcd.print(roll-2);
    
    if(!Enroll(roll))
    {
      delay(1000);
      Enroll(roll);
    }
    admin_menu();
  }
}
