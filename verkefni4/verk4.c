#pragma config(Sensor, in1,    LightSensor,    sensorReflection)
#pragma config(Sensor, in2,    LineFollow1,    sensorLineFollower)
#pragma config(Sensor, in3,    LineFollow2,    sensorLineFollower)
#pragma config(Sensor, in4,    LineFollow3,    sensorLineFollower)
#pragma config(Sensor, in5,    Potatometer,    sensorPotentiometer)
#pragma config(Sensor, in6,    GyroSensor,     sensorGyro)
#pragma config(Sensor, dgtl1,  FruntButton,    sensorTouch)
#pragma config(Sensor, dgtl2,  CraneStoper,    sensorTouch)
#pragma config(Sensor, dgtl6,  LEncoder,       sensorQuadEncoder)
#pragma config(Sensor, dgtl8,  REncoder,       sensorQuadEncoder)
#pragma config(Sensor, dgtl10, SonarCM,        sensorSONAR_cm)
#pragma config(Motor,  port1,           LMotor,        tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           CraneArm,      tmotorVex393, openLoop)
#pragma config(Motor,  port7,           Claw,          tmotorVex269, openLoop)
#pragma config(Motor,  port10,          RMotor,        tmotorVex393, openLoop)


/*----------------------------------------------------------------------------------------------------*\
|*                                    - light and sonar sensors -                                     *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*                                                                                                    *|
|*                                                                                                    *|
|*                                                                                                    *|
|*                                                                                                    *|
|*                                                                                                    *|
|*                                                                                                    *|
|*                                                                                                    *|
|*                                                                                                    *|
|*                                                                                                    *|
|*                                                                                                    *|
|*                                                                                                    *|
|*                                                                                                    *|
|*                                                                                                    *|
|*                                                                                                    *|
|*                                                                                                    *|
\*----------------------------------------------------------------------------------------------------*/

#include "..\include\header\movingForwardHeder.h"
#include "..\include\functions\myfunctions.c"

task main()
{
	StartTask(emergency_stop);
	StartTask(startBot);
	while(true)
	{
		if(SensorValue(SonarCM) > 40)		// Loop while robot's Ultrasonic sensor is further than 20 inches away from an object
		{                                                                         // || (or) it is '-1'.  (-1 is the value returned when nothing is in it's visable range)
			motor[RMotor] = 63;			// Motor on port2 is run at half (63) power forward
			motor[LMotor]  = 63;			// Motor on port3 is run at half (63) power forward
		}
		else if(SensorValue(SonarCM) == -1){
			motor[RMotor] = 63;
			motor[LMotor] = 63;
		}

		else {
			stopMotors();
		}
	}
}

task emergencys_stop(){
	while(true){
		if (SensorValue(FruntButton) == 1){
			suspendTask(main);
			stopMotors();
		}
	}
}

task startBot(){
	while(true){
		if (vexRT[BTn7U] == 1){
			StartTask(main);
		}
	}
}
