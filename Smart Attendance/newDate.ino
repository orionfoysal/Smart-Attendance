void newDate(String date)
{
  myFile = SD.open("arduino_101_season_4_attendance.csv", FILE_WRITE);
  if (myFile) {
    myFile.print(date + ",");
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
   // Serial.println("error opening test.txt");
    lcd.clear();
    lcd.print("SD Error");
  }
}
