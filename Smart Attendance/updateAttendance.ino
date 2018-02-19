void updateAttendance(String attendance)
{
  myFile = SD.open("arduino_101_season_4_attendance.csv", FILE_WRITE);
  if (myFile) {
    myFile.println(attendance);
    // close the file:
    myFile.close();
  //  Serial.println("Successfully written");
    lcd.clear();
    lcd.print("Writing ...");
  } else {
    // if the file didn't open, print an error:
  //  Serial.println("error opening file");
    lcd.clear();
    lcd.print("SD Error");
  }

  for (int i = 0 ; i < EEPROM.length() ; i++) 
    EEPROM.write(i, 0);
}
