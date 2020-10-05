


//How to send a diagnostic request and validate whether the response is Positive or Negative (E.g. Reading SW version using UDS)

includes
{

}

variables
{

 diagrequset ABC0T.Software_Version swver;
 char DiagTargetName[16] = "ABC0T";
 
}


void MainTest()

{

 DiagSetTarget(DiagTargetname);
 Diagnostic_Read_Software_Version();

}

testcase Diagnostic_Read_Software_Version()
{

 diagSendRequest(swver);
 
 if(TestWaitforDiagResponse(swver, 5000) == 1)
 {
   if (DiagGetlastResponseCode()==-1)
   {
      testStepPass("1", "Positive Response");
   }
  else
      testStepFail("1", "Negative Response");

 

 }
 else
 {
 
  testStepFail("1", "Timeout Happend")

 } 
}
