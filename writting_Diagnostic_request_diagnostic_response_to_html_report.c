// how to write UDS diagnostic request and diagnostic response to html report

includes
{

}

variables

{

 diagrequset ABC0T.Software_Ver_Read SWver;
 char DiagTargetName[16] = "ABC0T";

}

void MainTest()

{

 DiagSetTarget(DiagTargetname);
 Diagnostic_SW_Version_Read();

}


testcase Diagnostic_SW_Version_Read()
{

 diagSendRequest(SWver);
 
 if(TestWaitforDiagResponse(SWver, 5000) == 1)
 {
   if (DiagGetlastResponseCode()==-1)
   {
      testStepPass("1", "Positive Response");
      testReportWriteDiagObject(SWver);
      testReportWriteDiagResponse(SWver);

   }
  else
      testStepFail("2", "Negative Response");
      testReportWriteDiagObject(SWver);
      testReportWriteDiagResponse(SWver);

 }
 else
 {
 
  testStepFail("3", "Timeout Happend")

 } 
}


//How to send a diagnostic request and validate its response each byte of its positive Response-
//E.g. Validating the byte response SW version Read
//Usecase: Read SW version : 22 F5 01 == > 62 F5 01 15 2F 07


includes
{

}

variables

{

  diagrequset ABC0T.Software_Ver_Read SWver;
  char DiagTargetName[16] = "ABC0T";

}


void MainTest()

{

 DiagSetTarget(DiagTargetname);
 Diagnostic_SW_Version_Read();

}

testcase Diagnostic_SW_Version_Read()
{

 diagSendRequest(SWver);
 
 if(TestWaitforDiagResponse(SWver, 5000) == 1) //Response is available or not
 {
   if (DiagGetlastResponseCode()==-1)  // Response is +ve or not
   {
      testStepPass("1", "Positive Response");
      if(DiagGetRespPrimitiveByte(SWver,3) == 0x15) &&
        (DiagGetRespPrimitiveByte(SWver,4) == 0x2F) &&
        (DiagGetRespPrimitiveByte(SWver,5) == 0x07) // Validating +ve response byte are correct or not
        {
        
           TestStepPass("2", "Response Byte are also correct");


        } 
      else
      {
      
      TestStepPass("2", "Response Byte are not correct");

      }

   }
  else
      testStepFail("1", "Negative Response");
     

 }
 else
 {
 
  testStepFail("3", "Timeout Happend")

 } 
}



//How to send a diagnostic request without using .cdd file
//Usecase Send 22 F4 01 on diagnostic request ID 0x15F17cF2


includes
{

}


variables
{

  message 0x15F17cF2 msg1;

}

void Maintest()

{

  msg1.DLC = 8;
  msg1.byte(0) = 0x03;
  msg1.byte(1) = 0x22;
  msg1.byte(2) = 0xF4;
  msg1.byte(3) = 0x01;
  msg1.byte(4) = 0x00;
  msg1.byte(5) = 0x00;
  msg1.byte(6) = 0x00;
  msg1.byte(7) = 0x00;
  output(msg1);


}

//How to validate UDS Negative Response in CAPL
//UseCase : We are in default session and is sending ECU Serial Write and need to check whether NRC7E is available as NRC or notd

includes
{

}

variables
{
  
 diagrequset ABC0T.ECUSerial_Write ecuserial_write;
 char DiagTargetName[16] = "ABC0T";
}

void MainTest()

{

 DiagSetTarget(DiagTargetname);
 Diagnostic_ECU_Version_write();


}

testcase Diagnostic_ECU_Version_write()
{

 TestCaseTitle("Diagnosis Validation", "VAlidating NRC7E")
 diagSendRequest(ecuserial_write);


if(TestWaitforDiagResponse(ecuserial_write, 5000) == 1) //Response is available or not
 {
   if (DiagGetlastResponseCode()==-1)  // Response is +ve or not
   {
      testStepFail("1", "Positive Response");
      testReportwriteDiagResponse(ecuserial_write);
    
   }
  else
  {
      testStepPass("1", "Negative Response");
      testReportwriteDiagResponse(ecuserial_write);
      if(DiagGetRespPrimitiveByte(ecuserial_write,2) == 0x7E)
      {
     
         TestStepPass("2", "Correct NRC Received");

      }   
      else
      {
        TestStepFail("2", "Wrong NRC Received");
      }   

 }
 else
 {
 
  testStepFail("3", "Timeout Happend: No Response Received");

 } 
}

