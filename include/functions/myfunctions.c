
//--------------------------------------------| verk 3 |---------------------------------------------

task emergency_stop(){
	while(true){
		if (SensorValue[Frontbutton] == 1){
			suspendTask(main);
			wait1Msec(1000);
			StartTask(main);
		}
	}
}

//----------------------------------------------------------------------------------------------------


void driveS(int dist, bool b_f){
	int dir = (b_f)? (1):(-1);
	while(dist>abs(SensorValue[REncoder])){
		if(abs(SensorValue[REncoder]) == abs(SensorValue[LEncoder])) // If rightEncoder has counted the same amount as leftEncoder:
			{
				// Move Forward
				motor[RMotor] = 100*dir;		    // Right Motor is run at power level 80
				motor[LMotor] = 80*dir;		    // Left Motor is run at power level 80
			}
		else	// Only runs if leftEncoder has counted more encoder counts
			{
				motor[RMotor] = 100*dir;
				motor[LMotor] = 80*dir;
			}
	}
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


//--------------------------------------------| FORWARD |---------------------------------------------
void drivec()
{
  SensorValue[REncoder] = 0;    /* Clear the encoders for    */
  SensorValue[LEncoder]  = 0;    /* consistancy and accuracy. */

  while(abs(SensorValue[REncoder]) < BASE_DIST)
  {
    motor[RMotor] = 63;         /* Run both motors        */
    motor[LMotor]  = 63;         /* forward at half speed. */
  }
  motor[RMotor] = 0;            /* Stop both motors!  This is important so that each function          */
  motor[LMotor]  = 0;            /* can act independantly as a "chunk" of code, without any loose ends. */
}
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| TURN |--------------------------------------------
void Turn(int deg,bool right_left)
{
  SensorValue[REncoder] = 0;    /* Clear the encoders for    */
  SensorValue[LEncoder]  = 0;    /* consistancy and accuracy. */
	int dir =(right_left)?(1):(-1);
  // While the encoders have not yet met their goal: (left is compared negativly since it will in reverse)
  while(abs(SensorValue[REncoder]) < (deg * BASE_ROTATION) && abs(SensorValue[LEncoder]) < (deg * BASE_ROTATION))
  {
    motor[RMotor] = dir*63;         // Run the right motor forward at half speed
    motor[LMotor]  = dir*-63;        // Run the left motor backward at half speed
  }
  motor[RMotor] = 0;            /* Stop both motors!  This is important so that each function          */
  motor[LMotor]  = 0;            /* can act independantly as a "chunk" of code, without any loose ends. */
}
//----------------------------------------------------------------------------------------------------
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void resetEncoder(){
	SensorValue[REncoder] = 0;
	SensorValue[LEncoder] = 0;
}

void stopMotors(){
	motor[LMotor] = 0;
	motor[RMotor] = 0;
	wait1Msec(1000);
}

void drive(int drivetime, bool b_f){
	int dir = (b_f)? (1):(-1);
	motor[RMotor] = FULL_POWER*dir;
	motor[LMotor] = FULL_POWER*dir;
	wait1Msec(drivetime);
	motor[LMotor] = 0;
  motor[RMotor] = 0;
  wait1Msec(1000);
}

task display(){
			bLCDBacklight = true;
		string mainBattery;

		while(true)
		{
			 clearLCDLine(0);
			 clearLCDLine(1);

			 displayLCDString(0, 0, "Primary: ");
			 sprintf(mainBattery, "%1.2%c", nImmediateBatteryLevel/1000.0,'V');
			 displayNextLCDString(mainBattery);

			 wait1Msec(100);
		}
}
