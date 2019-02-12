int *array_function(){
	int myarray[10]={0,1,2,3,4,5,6,7,8,9};
	return &myarray;
}

int array[10]={0,1,2,3,4,5,6,7,8,9};
task main()
{
	int *pnt = &array;
	for(int i =0;i<10;i++){
			writeDebugStream("This is the %d value of an arry = %d \n",i,*pnt);
			pnt++;
	}
	int *pnt2 = array_function();
	for(int i =0;i<10;i++){
			writeDebugStream("This is the %d value of an arry = %d \n",i,*pnt2);
			pnt2++;
}


}
