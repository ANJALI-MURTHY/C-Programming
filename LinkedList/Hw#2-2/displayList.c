#include<stdio.h>
#include "header.h"

extern struct address_t *head;  //Value of global variable head can be accessed as a external variable

//Function to display the singly linked list
void displayList(){
    struct address_t *temp;
	int count =0;
    temp = head;
    printf("\nThe contents of list:\n");
    if(head == NULL )
        printf("\nEmpty List");
    else
    {
        while (temp != NULL)
        {
            printf("\n%d.%d.%d.%d %s->", temp ->octet[0],temp->octet[1],temp->octet[2],temp->octet[3], temp->alias);
			count++;
            temp = temp -> next;
        }
    }
    printf("X");
	//printf("\nThe number of address/alias pairs present : %d",count);
}




