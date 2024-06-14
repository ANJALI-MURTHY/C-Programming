#include <stdio.h>
#include <stdlib.h>
#include "header.h"
extern struct address_t *head;
//Function to save in a file
void saveToFile(){
	FILE *fp;
	struct address_t *temp;
	char file[20];
	printf("\nEnter File Name:");
	scanf("%s",file);

	fp = fopen(file,"w");

	temp=head;

	while(temp != NULL){
		fprintf(fp,"%d.%d.%d.%d %s\n",temp ->octet[0],temp->octet[1],temp->octet[2],temp->octet[3], temp->alias);
		temp=temp->next;
	}
	fclose(fp);
	printf("Saved to File Successfully!!");

}
