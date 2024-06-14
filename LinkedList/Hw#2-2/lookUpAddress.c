#include<stdio.h>
#include "header.h"

extern struct address_t *head; //extern variable is used to access the global variable head

//Function to search an address in the list
int lookUpAddress(char str[30]){

	int i1,i2,i3,i4;
	struct address_t *temp;
	sscanf(str, "%d.%d.%d.%d",&i1,&i2,&i3,&i4);
	for(temp=head; temp!=NULL ; temp=temp->next){
		if (temp->octet[0]==i1 && temp->octet[1]==i2 && temp->octet[2]==i3 && temp->octet[3]==i4){
			return 1;  //if match found returns 1
		}
	}
	return -1;
}