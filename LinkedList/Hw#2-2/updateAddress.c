#include<stdio.h>
#include<stdlib.h>
#include "header.h"

extern struct address_t *head;//extern is used to access the global variable head

//Function to update the alias address in the list
void updateAddress(char oct[30],char str[11]){
	int alias, addr,p1,p2,p3,p4;
	addr= lookUpAddress(oct); //function to check if the address is already present
	alias = lookUp(str); //function to check if alias is present
	if (alias != -1 && addr != 1){
		struct address_t *p = head;
		sscanf(oct,"%d.%d.%d.%d",&p1,&p2,&p3,&p4);
		for (int i = 0; i != alias; i++)
		{
			printf("%d",i);
			p = p->next;
		}
		p->octet[0]=p1;
		p->octet[1]=p2;
		p->octet[2]=p3;
		p->octet[3]=p4;
		printf("\n\nAddress updated Successfully!!");
		displayList();
	}
	else if(addr == 1){
		printf("\nError: Duplicate Address");
	}
}