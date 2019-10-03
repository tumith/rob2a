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


task main()
{
  while(1 == 1)
  {
  	//Dekk
    //Right side of the robot is controlled by the right joystick, Y-axis
    motor[RMotor] = vexRT[Ch2];
    //Left side of the robot is controlled by the left joystick, Y-axis
    motor[LMotor] = vexRT[Ch3];
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
