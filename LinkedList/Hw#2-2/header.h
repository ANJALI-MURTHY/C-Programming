#include<stdio.h>
#include<stdlib.h>
//structure for address_t
struct address_t{
	int octet[4];
	char alias[11];
	struct address_t *next;
};

//To create a struct address_t type node in the list
struct address_t* newnode(char str1[30], char str2[11]);

void createLList();

int checkRange(char oct[30]);

//Function to add new Address/Alias pair
void addAddress(char oct[30], char str[11]);

int lookUp(char str[11]);

int lookUpAddress(char str[30]);

void updateAddress(char oct[30],char str[11]);

void deleteAddress(char str[11]);

int aliasForLocations(char oct[15]);

void saveToFile();

void displayList();