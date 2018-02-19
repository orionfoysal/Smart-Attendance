const char* returnName(int roll)
{
  char Roll[10]="";
  itoa(roll,Roll,10);

  myFile = SD.open("Data.csv");
  if (myFile) {
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      char ch[10] = "";
      int x = 0;
      char Name[25] = "";
      char myName[25] = "";
      do{
        ch[x] += myFile.read();
        x++;
      }while(ch[x-1]!=',');
      if(strstr(ch,Roll))
      { 
        x = 0;
        do{
        Name[x] +=myFile.read();
        x++;
        }while(Name[x-1] != '\n');
        int p =0;
        while(Name[p+1] != '\n')
        {
          myName[p]=Name[p];
          p++;
        }
        myFile.close();
        return myName;
      }
      else{
        x = 0;
        do{
        Name[x] +=myFile.read();
        x++;
        }while(Name[x-1] != '\n');
      }      
    }
    // close the file:
    myFile.close();
    return "Not Found";
  } 
  else {
    // if the file didn't open, print an error:
  //  Serial.println("error opening file");
    lcd.clear();
    lcd.print("SD Error");
  }
}
