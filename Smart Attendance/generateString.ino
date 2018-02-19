void generateString()
{
  mainString = "";
  for(int i = 1; i<=255; i++){
    int stat = EEPROM.read(i);
    if(stat == 1)
      mainString += "1,";
    else 
      mainString += ",";
  }
}

