#pragma config(Motor,  port2,           leftMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Sensor, dgtl2,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl4,  rightEncoder,   sensorQuadEncoder)
const int BASEDEG=3;

void turn(int degrees,int left_or_right){
	//while(degrees*BASEDEG > abs(SensorValue[leftEncoder])){
	motor[leftMotor]=-127*left_or_right;
	motor[rightMotor]=127*left_or_right;
	//}
}
typedef enum {left =1,right=-1}turning;
task main()
{
	turn(90,left);//med enum getum vid sett left inn  fallid istad 1 eda -1 sem er mun laesilegra
	writeDebugStream("turning left :%d",left);
	turn(90,right);
	writeDebugStream("turning right :%d",right);

}
