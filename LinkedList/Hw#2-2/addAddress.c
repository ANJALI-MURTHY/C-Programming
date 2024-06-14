#include <stdio.h>
#include<stdlib.h>
#include "header.h"
extern struct address_t *head;


//Function to add new Address/Alias pair
void addAddress(char oct[30], char str[11]){
	int als,addr,i1,i2,i3,i4;
	als= lookUp(str);  //Function to check if Alias is already present
	addr= lookUpAddress(oct); //Function to check if address is already present
	
	if (als== -1 && addr == -1)
	{
		printf("\nNew address/alias can be added.");
		struct address_t *ptr;
    	struct address_t * p ;
		p=head;
    	ptr = newnode(oct,str);
    	while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
	ptr->next = NULL;
	printf("\n\nAddress added Successfully!!");
	}
	else{
		printf("\nError: Already present!!");
	
	}
}