#include<stdio.h>
#include<stdlib.h>
#include "header.h"

extern struct address_t *head;

//Function to display all the alias for a location
int aliasForLocations(char oct[15]){
	int i1,i2,flag=-1;
	struct address_t *temp;
	sscanf(oct, "%d.%d" ,&i1,&i2);
	for(temp=head; temp!=NULL ; temp=temp->next){
		if (temp->octet[0]==i1 && temp->octet[1]==i2 ){
			
			printf("\nAlias : %s", temp ->alias);
			flag =1;
		}

	}
	return flag;
}
