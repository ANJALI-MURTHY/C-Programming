#include<stdio.h>
#include<stdlib.h>
#include "header.h"
extern struct address_t* head;

//Function to create a singly linked list
void createLList(){
	FILE *fp;
	struct address_t *new_address;
	struct address_t *temp;
	int i1,i2,i3,i4;
	char s1[30],s2[11];
	fp = fopen("CS531_Inet.txt","r");
	
	while (fscanf(fp, "%s %s", s1,s2) !=EOF)  //To scan everything in the file until the eof is reached
	{
		new_address=newnode(s1,s2);  //create new node for each line
		if(head == NULL)
		{
			head = new_address; //if the list was an empty list
		}
		else
		{
			temp = head;
			while(temp -> next != NULL)
				temp = temp -> next;
			
			temp -> next = new_address; //To add new node at the end of the list
		}
	}
	fclose(fp);
}