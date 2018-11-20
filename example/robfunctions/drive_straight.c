#pragma config(Sensor, dgtl1,  left_encoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  right_encoder,  sensorQuadEncoder)
#pragma config(Motor,  port2,           left_motor,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           right_motor,   tmotorVex393, openLoop)


typedef enum{left=-1,right=1}mytype;
int avg_encoder(){
	return (abs(SensorValue[left_encoder])+abs(SensorValue[right_encoder]))/2;
};

void reset_encoder(){
	SensorValue[left_encoder]=0;
	SensorValue[right_encoder]=0;
}
void drive(int dist,int left_or_right){
	reset_encoder();
	int correction;
	while(dist>avg_encoder()){
		correction= sensorValue[left_encoder] - sensorValue[right_encoder];
		motor[left_motor]=127	-correction*0.5;
		motor[left_motor]=127	+correction*0.5;
	}
}

task main()
{
	drive(10,left);
}
