typedef struct Cords{
	int row;
	int col;
	char letter1;
	float number;

}Cords;



task main()
{
	Cords r[10];
	for(int i =0;i<10;i++){
			r[i].row=i;
			r[i].col=i+11;
			r[i].letter1 = 'a'+i;
			r[i].number = 2.345+i;
	}
	Cords *ptr = &r;
	for(int k=0;k<10;k++){
	writeDebugStream(" (x,y):%d,%d,%c,%f \n",ptr->row,ptr->col,ptr->letter1,ptr->number);
	*ptr++;
	}
	*ptr--
	for(int k=10;k>0;k--){
	writeDebugStream(" (x,y):%d,%d,%c,%f \n",ptr->row,ptr->col,ptr->letter1,ptr->number);
	*ptr--;
	}
	ptr = NULL;
	writeDebugStream("%d",(int)'a');
}
