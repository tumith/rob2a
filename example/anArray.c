#define ROW 5
typedef struct My_bool_array{
	bool is_turning;
}My_bool_array;

My_bool_array *array_function(){
	My_bool_array myarray[ROW];
	myarray[0].is_turning=true;
	myarray[1].is_turning=false;
	myarray[2].is_turning=true;
	myarray[3].is_turning=false;
	myarray[4].is_turning=false;
	return &myarray;
}

int array[10]={0,1,2,3,4,5,6,7,8,9};
task main()
{
	clearDebugStream();
	int *pnt = &array;
	for(int i =0;i<10;i++){
			writeDebugStream("This is the %d value of an array = %d \n",i,*pnt);
			pnt++;
	}
	My_bool_array *pnt2=array_function();
	for(int i =0;i<5;i++){
			writeDebugStream("This is the %d value of an array = %d \n",i,*pnt2);
			pnt2++;
}


}
