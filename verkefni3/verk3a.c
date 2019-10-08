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
|*                           - Dual Joystick Control with Arm, Claw and button -                      *|
|*                                      ROBOTC on VEX 2.0 Cortex                                      *|
|*                                                                                                    *|
|*  This program uses the Left Ch3 and the Right Ch2 joysticks on Remote to run the robot using       *|
|*  "tank control". We use the bottuns on 8 U to lift the arm, D to lower the arm, L to open the Claw *|
|*  and R to close the Claw. Then we use the button in front to disable the wheels when it is pushed  *|
|*  and we use threshold to stop the noice that comes from the R and LMotor.                          *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Ch2 moves the RMotor and Ch3 moves the LMotor.                                              *|
|*    2)  Btn 8 U and L to move the arm, Btn 8 L and R to open and close the Claw.                    *|
|*    3)  SensorValue[FruntButton] to stop Robot when it is pushed                                    *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]              [Name]              [Type]              [Description]                   *|
|*    Motor - Port 10         RMotor               tmotorVex393           Right motor                 *|
|*    Motor - Port 1          LMotor               tmotorVex393           Left motor                  *|
|*    Motor - Port 6          CraneArm             tmotorVex269           Arm motor                   *|
|*    Motor - Port 7          Claw                 tmotorVex393           Claw motor                  *|
|*    Sensor - Dgt 11         FruntButton          sensorTouch            Stoping the robot           *|
\*----------------------------------------------------------------------------------------------------*/


task main()
{
	// til ad stopa hljod
	int threshold = 10;


  while(1 == 1)
  {
  	if(abs(vexRT[Ch2]) > threshold)
  	{
  			motor[RMotor] = vexRT[Ch2];
  	}
  	else
  	{
  		motor[RMotor] = 0
  	}

		if(abs(vexRT[Ch3]) > threshold)
  	{
   	 		motor[LMotor] = vexRT[Ch3];
   	}
   	else
  	{
  		motor[LMotor] = 0
  	}

    if(sensorValue[FruntButton] == 1)
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
  }
}
