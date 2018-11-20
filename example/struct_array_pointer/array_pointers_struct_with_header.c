#include <structpointer.h>

/*
Create a struct contaning x,y cordinates and a bool tf showing
true if way is open or closed.
*/

/*
function of type Cords pointer with 2D arry creating a grid that the robot
will follow tf way
*/
Cords *set_cords(){
	bool mase_array[ROW][COL] = {
		{1,1,1,0,0,0},
		{0,0,1,0,0,0},
		{0,0,1,1,1,0},
		{0,0,0,0,1,0},
		{0,0,0,0,1,0}};
	/*Create an array of type Cords and a pointer that points to addresses
	witch holds structs of type Cords and return it
	*/
	Cords cord_array_pointer[COL*ROW];
	int l=0;
	for(int k=0;k<ROW;k++){
		for(int j=0;j<COL;j++){
			cord_array_pointer[l].row =k;
			cord_array_pointer[l].col =j;
			cord_array_pointer[l].tf = mase_array[k][j];
			l++;
		}
	}
	return &cord_array_pointer;

};
bool drive(int x,int y,bool lr){
	writeDebugStream("Keyri afram x:%d,y:%d%d\n", x,y,lr);
	return lr;
}

void turn(bool left_right){
	if(left_right){
		writeDebugStream("Beygi til vinstri %d\n", left_right);
	}
		else{
			writeDebugStream("Beygi til haegri %d\n", left_right);
		}
	}
	bool turning =true;
	task main()
	{
		/*
		Pointer  of type Cords that points to an array of Cords
		*/
		Cords *ptr = set_cords();
		//showing the path to the end of the grid
		int last_col = 0;
		int last_row = 0;
		ptr++;
		for(int i=1;i<=30;i++){
			if(ptr->tf){
				if(last_row == ptr->row){
					if(!turning){
						turn(true);
						turning=true;
					}
					else{
						turning = drive(ptr->row,ptr->col,1);
					}
				}
				if(last_col == ptr->col){
					if(turning){
						turn(false);
						turning = drive(ptr->row,ptr->col,0);
					}
					else{
						turning = drive(ptr->row,ptr->col,0);
					}
				}
				last_col = ptr->col;
				last_row = ptr->row;

			}
			ptr++;
			// make the pointer travel throug  the array from one address to another
		}
		ptr=NULL;
	}
