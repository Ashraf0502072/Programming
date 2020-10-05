//How to send a diagnostic request on the bus

includes
{

}

variables
{

diagRequest ABC0T.checkProgConditions_Start chkProgstart;
diagRequest ABC0T.checkProgConditions_Stop chkProgstop;

}

void MainTest()
{

 char DiagTargetName[16] = "ABC0T";
 DiagSetTarget(DiagTargetName);
 Diagsendrequset(chkprogstart);

}
//How to give a delay between command execution in CAPL

//Note: A delay command can be used in a CAPL Test module but not in a CAPL Network Node

 

includes
{

}

variables
{

diagRequest ABC0T.checkProgConditions_Start chkProgstart;
diagRequest ABC0T.checkProgConditions_Stop chkProgstop;

}

void MainTest()
{

 char DiagTargetName[16] = "ABC0T";
 DiagSetTarget(DiagTargetName);
 Diagsendrequset(chkprogstart);
 testwaitfortimeout(5000); //in ms
 Diagsendrequset(chkprogstop);
}



//How to enable/disable Tester Present after setting ECU Terget

includes
{

}

variables
{
diagrequest ABC0T.Default_Session def;
diagrequest ABC0T.Extended_Session ext;

}

void MainTest()
{

 char DiagTargetName = "ABC0T";
 DiagSetTarget (DiagTargetName);
 diagsendrequest(ext);
 diagStartTesterPresent(DiagTargetname);
 testwaifortimeout(10000);
 diagStopTesterPresent(DiagTargetName); 
}
