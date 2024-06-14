#include<stdio.h>
#include<string.h>
#include "header.h"

extern struct address_t *head; //extern is used to access global variable head

//Function to search an Alias
int lookUp(char str[11]){

	struct address_t *temp;
	int index = 0;
	for(temp=head; temp!=NULL ; temp=temp->next,index+=1){
		if (strcasecmp(temp->alias,str)==0){
			printf("\nAlias:%s", temp->alias);
			printf("\nAddress : %d.%d.%d.%d", temp ->octet[0],temp->octet[1],temp->octet[2],temp->octet[3]);
			return index;
		}
		
	}
	printf("\nAlias NOT Found.");
	return -1;
}

