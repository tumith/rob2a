
void drive(){
if(SensorValue[REncoder] == SensorValue[LEncoder]) // If rightEncoder has counted the same amount as leftEncoder:
		{
			// Move Forward
			motor[RMotor] = 80;		    // Right Motor is run at power level 80
			motor[LMotor]  = 80;		    // Left Motor is run at power level 80
		}
		else if(SensorValue[REncoder] > SensorValue[LEncoder])	// If rightEncoder has counted more encoder counts
		{
			// Turn slightly right
			motor[RMotor] = 60;		    // Right Motor is run at power level 60
			motor[LMotor]  = 80;		    // Left Motor is run at power level 80
		}
		else	// Only runs if leftEncoder has counted more encoder counts
		{
			// Turn slightly left
			motor[RMotor] = 80;		    // Right Motor is run at power level 80
			motor[LMotor]  = 60;		    // Left Motor is run at power level 60
		}
}


void stopMotors(){
	motor[LMotor] = 0;
	motor[RMotor] = 0;
	wait1Msec(1000);
}

void aframEinSec(){
 motor[RMotor] = 127;
 motor[LMotor] = 127;
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
