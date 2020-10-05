// How to invoke a predefined .can file

includes
{

  #include "C\Users\........\Diag.cin"
  
}



variables
{

 
 
}




//How to send a raw message in CAPL

includes
{

  

}



variables
{

  message 0x1EEEF75Ax msg1; //This is our raw message ID

}

//env_Mute_Unmute is associated with the button panel

On envVar env_Mute_Unmute 
{

  if (getValue(env_Mute_Unmute == 1))
  {
  
  msg1.DLC=8;
  msg1.byte(0)=0x01;
  msg1.byte(1)=0x01;
  msg1.byte(2)=0x00;
  msg1.byte(3)=0x00;
  msg1.byte(4)=0x0A;
  msg1.byte(5)=0x01;
  msg1.byte(6)=0x00;
  msg1.byte(7)=0x0A;
  output(msg1);
  }
  else 
  {
  msg1.DLC=8;
  msg1.byte(0)=0x00; //byte 0 is different
  msg1.byte(1)=0x01;
  msg1.byte(2)=0x00;
  msg1.byte(3)=0x00;
  msg1.byte(4)=0x0A;
  msg1.byte(5)=0x01;
  msg1.byte(6)=0x00;
  msg1.byte(7)=0x0A;
  output(msg1);
  }
}
  

