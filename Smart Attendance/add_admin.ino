void add_admin()
{
  if(!fps.CheckEnrolled(1)) //if ID 1 is not in use
  {
    if(!Enroll(1)) //if enroll 1 is unsuccessful
    {
      delay(1000);
      Enroll(1); //try again
    }
    admin_menu(); //go to admin menu
  }
  else if(!fps.CheckEnrolled(2)) //if ID 2 is not in use
  {
    if(!Enroll(2)) //if enroll 2 is unsuccessful
    {
      delay(1000);
      Enroll(2); //try again
    }
    admin_menu();
  }
  else
  {
  //  Serial.println("All admins are enrolled.");
    admin_menu();
  }
}
