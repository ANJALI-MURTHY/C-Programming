#include<stdio.h>
#include<stdlib.h>
#include "header.h"

//Function to check range of the address entered by the user
int checkRange(char oct[30]){
	int i1,i2,i3,i4;
	sscanf(oct,"%d.%d.%d.%d",&i1,&i2,&i3,&i4);
	if(i1 < 0 || i1>255 ||i2 < 0 || i2>255 ||i3 < 0 || i3>255 ||i4 < 0 || i4>255 ) //if condition checks if the values of i1,i2,i3 &i4 are in range
	{
		printf("\nValue out of range (0-255)");
		return -1;
	}
	return 1;
}