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
|*                                    - LineSensor / LineFollower -                          		  *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*    Thetta er programm til ad elta linu en ef thad er ekki sed linuna leingur tha er stopad.        *|
|*                                                                                                    *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*   1) Robot leitar af linu ef hann ser linu tha eltir hann linuna en ef hann ser einga linu tha er  *|
|*      hann kjur og bidur eftir thvi ad sja linu.									   			      *|
|*   2) Thegar robotin ser linu eltir hann linuna thangad til hann ser hana ekki leignur.			  *|
|*                                                                                                    *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]             [Name]              [Type]              [Description]                    *|
|*    Motor - Port 10        RMotor            tmotorVex393           Right motor                     *|
|*    Motor - Port 1         LMotor            tmotorVex393           Left motor                      *|
|*    Sensor - in2           LineFollow1  		 sensorLineFollower     Line detector				  *|
|*    Sensor - in3           LineFollow2  		 sensorLineFollower     Line detector				  *|
|*    Sensor - in4           LineFollow3  		 sensorLineFollower     Line detector				  *|
\*----------------------------------------------------------------------------------------------------*/

#include "..\include\header\movingForwardHeder.h"
#include "..\include\functions\myfunctions.c"

task main()
{
	StartTask(emergency_stop);
	while(true){
	if (vexRT[Btn6U] == true){
	drive_line(63);
	}
}
}

task emergency_stop(){
	while(true){
		if (SensorValue(FruntButton) == 1 || vexRT[Btn7D] == 1){
			suspendTask(main);
			stopMotors();
		}
	}
}
