// How to check a particular message is available on bus or not

includes
{

 
}



variables
{

  
 
}

void MainTest()

{

  if(testWaitforMessage(NM_ABC, 5000) == 1)
 {
  write(""Message was received);
  Func_ABC();
 }
 else
  Func_ABC_Not;
}




//How to generate random value



includes
{

  

}



variables
{

 
}

void MainTest()

{

 int x;
 c =random(100);//interval here is 0 to 99 not 0 to 100


//How to execute an external application from CAPL


testwaitfortimeout(1000);
sysExecCmd("C:\\User\\.......\\Demovalues\\demo.py", "C:\\User\\.......\\Demovalues");



}
