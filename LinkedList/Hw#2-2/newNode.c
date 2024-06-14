#include<stdio.h>
#include<stdlib.h>
#include "header.h"
#include<string.h>

//Function to create a struct address_t type node in the singly linked list 
struct address_t* newnode(char str1[30], char str2[11]){
		struct address_t *new_address;
		int i1,i2,i3,i4;

		sscanf(str1,"%d.%d.%d.%d",&i1,&i2,&i3,&i4);
		new_address = (struct address_t*)malloc(sizeof(struct address_t)); //Allocating memory to each of the node

		new_address->octet[0] = i1;
		new_address->octet[1] = i2;
		new_address->octet[2] = i3;
		new_address->octet[3] = i4;

		strcpy(new_address->alias,str2);
		new_address->next=NULL;
		return new_address; //returns the node 
}