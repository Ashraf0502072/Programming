// How to output message cyclically on the bus on pressing a Button in Panel

includes
{

}



//Precondition: WE created the environment and have associated the variabl with the button in Panel
variables
{

 message BBV_CAN::ABC msgABC;
 msTimer t_ABC;
 
}

on envVar envtransmit_ABC
{
  if(getValue(envtransmit_ABC == 1))
  {
    setTimerCyclic(t_ABC, 100);
  }
  else
    cancelTimer(t_ABC);

  onTimer t_ABC
  {
  output(msgABC);
  }
}


//Reset the CAN Bus on Bus off condition

includes
{

}

//Precondition: Add this code as a Network node

variables
{

  msTimer t1;
}


on busoff
{
  setTimer (t1, 1000);
}

on timer t1
{
  resetCan();
}
