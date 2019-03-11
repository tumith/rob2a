#include <structpointer.h>
/*
this is an array of type struct Pos , it keeps pointers to the structs
*/
Pos pos_array[10];
/*
this function is of type struct Pos and it makes and keeps data
of x,y and z positioning
*/
Pos *set_pos(){
	for(int i =0;i<10;i++){
		int _x = rand()%10;
		int _y = rand()%10;
		int _z = rand()%10;
		pos_array[i].x=_x;
		pos_array[i].y=_y;
		pos_array[i].z=_z;
	}
	return &pos_array;//retuns a pointer to the array
}

task main()
{
	Pos *pointer_to_array = set_pos();//a pointer to the first dataset in array
	for(int j =0;j<10;j++){
		writeDebugStream("value of x is =%d \n",pointer_to_array->x);
		writeDebugStream("value of y is =%d \n",pointer_to_array->y);
		writeDebugStream("value of z is =%d \n",pointer_to_array->z);
		writeDebugStream("rand of 2 =%d \n",rand()%2);
		pointer_to_array++;	//make the pointer point to the next dataset value
		}
}
