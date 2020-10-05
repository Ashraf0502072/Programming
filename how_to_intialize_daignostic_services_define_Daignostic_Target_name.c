//Code for how to initialize diagnostic services and define Diagnostic Target Name

includes

{

}

variables

{

 //char DiagTargetName[32];
 diagrequest ABC0T.Check_ProgConditions_Start chkprogstart;
 diagrequest ABC0T.Check_ProgConditions_Stop chkprogstop;  

}


void MainTest()

{

 char DiagTargetName[32] = "ABC0T";
 DiagSetTarget(DiagTargetName);
}

