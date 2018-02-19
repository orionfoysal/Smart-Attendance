void savetoEEPROM(int roll)
{
  if(EEPROM.read(roll) == 0)
     EEPROM.write(roll,1);
  else
     {
    //  Serial.println("Already Done");
      lcd.clear();
      lcd.print("Already Done");
     }
     
}
