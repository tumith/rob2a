#include <structpointer.h>
Pos pos_array[10];

Pos *set_pos(int x, int y, int z){
		pos_array[0].x=x;
		pos_array[0].y=y;
		pos_array[0].z=z;
		return &pos_array;
}
task main()
{
	Pos *pointer_to_array=set_pos(1,2,3);
	writeDebugStream("value of x is =%d value of y is =%d value of z is =%d",
	pointer_to_array,pointer_to_array++,pointer_to_array++);
}
