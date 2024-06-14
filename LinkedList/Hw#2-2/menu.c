/*******************************************************************************************
Author:       Anjali Murthy
Date:         November 04, 2022
Affiliation:  George Mason Univerisity, CS 531 Fall 2022 Graduate Course in systems Programing
Purpose: To create a singly linked list to store data and perform operations such as add , lookup , delete data in the input file.
		You can also save changes into the file using the alias name.
Last Modification: November 04, 2022
*******************************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "header.h"

//Global variable head
struct address_t *head = NULL;


int main()
{
	int value, choice ;
	char str[11],oct[30],oct2[15];

	//Function to Create the list
	createLList();

	//Displays the content in the input file
    displayList();
	do{

		printf("\n****************************************************************************************************************");
		printf("\n\t\t\t\tMenu Options\n1) Add address\n2) Look up address\n3) Update address\n4) Delete address\n5) Display list\n6) Display aliases for location\n7) Save to file\n8) Quit: \nChoice - >  ");
		scanf("%d",&choice);
		printf("\n****************************************************************************************************************");
		switch (choice)
		{
			case 1: // Add Address function is invoked in this case
						do{
							printf("\nEnter new Address in the format (123.123.123.123):");
							scanf("%s",oct);
							value = checkRange(oct); //checkRange function checks if the entered input is in Range
						}while(value != 1);

						printf("\nEnter new Alias:");
						scanf(" %s",str);
						addAddress(oct,str); //Function to add the new address to the linked list
						break;
			
			case 2: //Look up Address function is invoked in this case
						printf("\nEnter Alias to be searched:");
						scanf(" %s",str);
						value=lookUp(str); //User defined look up function is called here
						break;
				
			case 3: //Update Address function is invoked in this case
						printf("\nEnter Alias to be updated:");
						scanf(" %s",str);
						int val;
						value = lookUp(str);
						if(value != -1)
						{
							printf("\nEnter new Address in the format (123.123.123.123):");
							scanf(" %s",oct);
							val = checkRange(oct);
							if(val != -1)
							{
							updateAddress(oct,str);
							}
						}
						break;
			
			case 4 ://Delete Address function is invoked in this case
						deleteAddress(str); //user defined delete function deletes the desired entry
						break;

			case 5 :// Function invokes transverse function used to transverse the list
						displayList();
						break;

			case 6: //Function Display alias of all locations mapped to a particular location

						printf("\nEnter Address to display all Aliases (123.123):");
						scanf("%s",oct2);
						value = aliasForLocations(oct2); //User defined function to display the alias for all the corresponding locations
						if (value == -1){
							printf("Error : No location found !!");
						}
						break;

			case 7: //Function to Save to a file
						saveToFile();
						break;
		}
     //Function terminated when the choice selected is 8
	}while(choice!=8);

}