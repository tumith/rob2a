//-------------------------------Verk6---------------------------------------------------------------
void pick_up_glass(int speed)
{
	wait1Msec(1000);

	while(true)
	{
		// CENTER sensor sees dark:
    if(SensorValue(LineFollow2) > Line_THRESHOLD)
    {
      // go straight
      motor[LMotor] = 127;
      motor[RMotor] = 127;
    }
 		// RIGHT sensor sees dark:
    if(SensorValue(LineFollow3) > Line_THRESHOLD)
    {
      // counter-steer right:
      motor[LMotor] = speed;
      motor[RMotor] = 0;
    }

    // LEFT sensor sees dark:
    if(SensorValue(LineFollow1) > Line_THRESHOLD)
    {
      // counter-steer left:
      motor[LMotor] = 0;
      motor[RMotor] = speed;
    }
    if(SensorValue(LineFollow1) < Line_THRESHOLD && SensorValue(LineFollow2) < Line_THRESHOLD && SensorValue(LineFollow3) < Line_THRESHOLD)
  {
  	motor[LMotor] = 0;
    motor[RMotor] = 0;
  	break;
  }
  }
}



/*void find(int speed)
{
	wait1Msec(1000);

  int THRESHOLD = 2875;
	// RIGHT sensor sees dark:
  if(SensorValue(LineFollow3) > THRESHOLD)
  {
    // counter-steer right:
    motor[LMotor] = speed;
    motor[RMotor] = 0;
  }

  // LEFT sensor sees dark:
  else if(SensorValue(LineFollow1) > THRESHOLD)
  {
    // counter-steer left:
    motor[LMotor] = 0;
    motor[RMotor] = speed;
  }
}


void driving_back_forw(bool b_f)
{
  SensorValue[REncoder] = 0;    // Clear the encoders for
  SensorValue[LEncoder]  = 0;    // consistancy and accuracy.
	find(63);
	  while(abs(SensorValue[REncoder]) < BASE_DIST)
	  {
	  	int dir =(b_f)?(1):(-1);
	    motor[RMotor] = dir*63;
	    motor[LMotor]  = dir*63;
	  }
  motor[RMotor] = 0;
  motor[LMotor]  = 0;
}

 void Turn1(int deg,bool right_left)
{
  SensorValue[REncoder] = 0;
  SensorValue[LEncoder]  = 0;
	int dir =(right_left)?(1):(-1);
  while(abs(SensorValue[REncoder]) < (deg * BASE_ROTATION) && abs(SensorValue[LEncoder]) < (deg * BASE_ROTATION))
  {
    motor[RMotor] = dir*63;
    motor[LMotor]  = dir*-63;
  }
  motor[RMotor] = 0;
  motor[LMotor]  = 0; */


//---------------------------------------------------------------------------------------------------

//-------------------------------Verk5---------------------------------------------------------------
void drive_line(int speed)
{
	wait1Msec(1000);
	int dig= -1
	while(true)
	{
		// CENTER sensor sees dark:
    if((SensorValue(LineFollow2)) > Line_THRESHOLD)
    {
      // go straight
      motor[LMotor] = speed;
      motor[RMotor] = speed;
    }
 		// RIGHT sensor sees dark:
    else if((SensorValue(LineFollow3)) > Line_THRESHOLD)
    {
      // counter-steer right:
      motor[LMotor] = speed;
      motor[RMotor] = 0;
    }

    // LEFT sensor sees dark:
    else if((SensorValue(LineFollow1)) > Line_THRESHOLD)
    {
      // counter-steer left:
      motor[LMotor] = 0;
      motor[RMotor] = speed;
    }

  }
}


//---------------------------------------------------------------------------------------------------

//-------------------------------Verk4---------------------------------------------------------------
task joydrive()
{
	if(abs(vexRT[Ch2]) > THRESHOLD /*THRESHOLD stoppar hljod*/)
	{
			motor[RMotor] = vexRT[Ch2];
	}
	else
	{
		motor[RMotor] = 0;
	}

	if(abs(vexRT[Ch3]) > THRESHOLD)
	{
 	 		motor[LMotor] = vexRT[Ch3];
 	}
 	else
	{
		motor[LMotor] = 0;
	}

  if(SensorValue[FruntButton] == 1)
  {
  	motor[LMotor] = 0;
  	motor[RMotor] = 0;
  }

 //Claw
  if(vexRT[Btn8L] == 1)
  {
  	motor[Claw] = 47;
  }
  else if(vexRT[Btn8R] == 1)
  {
  	motor[Claw] = -47;
  }

  else
  {
  	motor[Claw] = 0;
  }

  // craneArm
  if(vexRT[Btn8U] == 1)
  {
  	motor[CraneArm] = -50;
  }
  else if(vexRT[Btn8D] == 1)
  {
  	motor[CraneArm] = 50;
	}
  else
  {
  	motor[CraneArm] = 0;
  }
  if (vexRT[Btn7L] == 1){
			stopMotors();
		  suspendTask(joydrive);
	}
}


/*task emergency_stop(){
	while(true){
		if (SensorValue(FruntButton) == 1 || vexRT[Btn7D] == 1){
			suspendTask(main);
			stopMotors();
		}
	}
}*/

task startBot(){
	while(true){
		if (vexRT[Btn7U] == 1){
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
	motor[Claw] = 0;
	motor[CraneArm] = 0;
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
