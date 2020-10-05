//Working With system variables:For instance we creat two system variables named "send_msg" and " Voltage"
//inside namespace "demo" and will be using them to associate with switch and with a tracbar respectively.
// The "send_msg" is linked to switch which sends message cyclically when switch pressed and stops when switch unpressed
//The "Voltage" is linked to trackbar to increase/decrease the value of voltage signal in the message
//Write a part of network node or ECU
 
includes
{

}

variables

{

 message VehicleInfo vehinfo;
 msTimer t_vehinfo;

}

on timer t_vehinfo
{

 output(vehinfo);

}


void sendmessagecyclic()

{

 setTimerCyclic(t_vehinfo, 50);

}

void cancelmessagecyclic()
{

cancelTimer(t_vehinfo);

}

on sysVar_update sysvar::demo::send_msg
{

 if(sysGetVariableInt("demo", "send_msg") == 1)
    sendmessagecyclic();
 else
    cancelmessagecyclic();

}


on sysVar_update sysvar::demo::Voltage
{

 vehinfo.Voltage = sysGetvariableInt("demo", "Voltage");

}



//How to validate amessage ID

includes
{

}

variables
{

 message DOOR_Left door_l;

}

void MainTest()
{

 valID();

}

testcase valID()
{

 if valID(door_l) == 0x1F1)
    TeststepPass("1", "ID IS CORRECT")
 else 
    TeststepFail("1", "ID IS INCORRECT")

}

//How to validate signal is available in bus or not

includes
{

}

variables
{


}

void MainTest()

{

Signal_Value()

}

testcase Signal_Value()
{

 if(testWaitForSignal(EngineRunning,5000) == 1)
    TeststepPass("1", "Engine running signal is available")
 else 
    TeststepFail("1", "Engine running signal is available")

}

//Setting default values of Signals available in Database

includes
{


}


variables
{

 message Gateway_2 gw_2;
 msTimer gateway2;

}

on timer gateway2
{

 output(gw_2);

}


void MainTest()
{

 settimecyclic(gateway2, 50);
 setSignalStartvalues(gw_2);

}



//setting signal values and sending it over CAN Bus

includes
{


}


variables
{

 message Gateway_2 gw2;
 msTimer gateway2;

}

on timer gateway2
{

 output(gw2);

}


void MainTest()
{


 setTimerCyclic(gateway2, 50);
 send_msg_with_signal_value();
 testwaitfortimeout(20000);
 setsignalStartValues(gw2);


}

void send_msg_with_signal_value()
{

 gw2.CarSpeed = 20;
 gw2.EngineTemp = 5;

}



//Setting signal value in CAPL and also validate value of signal in message
//usecase : msg name is VehicleInfo and it has two signals EngineTemp and CarSpeed

includes
{


}

variables
{


 message VehicleInfo vehinfo;
 msTimer t_vehinfo;;

}


on timer t_vehinfo
{

 output(vehinfo);

}


void MainTest()
{

 setTimerCyclic(t_vehinfo, 50);
 send_msg_with_signal_value();
 testwaitfortimeout(5000);
 validate_Signal_Value();

}

void send_msg_with_signal_value()
{

 vehinfo.CarSpeed = 20;
 vehinfo.EngineTemp = 5;
}

testcase validate_Signal_Value()
{

 if(testWaitForSignal(vehinfo,5000) == 1)
 {
   if(getSignal(CarSpeed) == 20 && getSignal(EngineTemp) == 5)
   {
   TeststepPass("1", "Signal have correct information")
   }
   else 
    TeststepFail("1", "Signal have not correct information")

}
 else
  TeststepFail("2", "Message not received on CAN Bus")
      
}
