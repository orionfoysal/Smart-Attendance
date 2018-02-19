void sendData()
{
    myFile = SD.open("arduino_101_season_4_attendance.csv");
  if (myFile) {
   // Serial.println("test.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
      
    }
    // close the file:
    myFile.close();
    //Serial.println("Alhamdulillah");
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Complete!");
    delay(2000);
    admin_menu();
  } else {
    // if the file didn't open, print an error:
//    Serial.println("error opening test.txt");
  }
}

