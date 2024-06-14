/*******************************************************************************************
Author:       Anjali Murthy
Date:         November 28, 2022
Affiliation:  George Mason Univerisity, CS 531 Fall 2022 Graduate Course in systems Programing
Purpose: To create a binary search tree to store data and perform operations such as add , lookup , delete data. To create file and save the data
Last Modification: December 1, 2022
*******************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#define FALSE 0
#define TRUE 1

typedef int bool;

struct address_t
{
        int addr[4];
        char alias[11];
        struct address_t *leftChild, *rightChild, *parent;
        int depth, height;
};

typedef struct address_t node;



// Function prototype declarations
bool checkIfIPExists(node**head,int ip[],int *flag);
int matchAlias(char *str1,char *str2,int len1,int len2);
bool lookupforIPAliasPair(node**head,char*alias,int *flag);
bool root_alias(char *str1,char* str2);
void insert(node ** tree, int val[],char alias[], int dep);
node* lookupUsingAlias(node**head,char*alias);
void updateNode(node**head,int ip[],char*alias);
void depth_correct(node *head);
void height_correct(node *head);
void displayTree(node*tree);
struct address_t* minNodeValue(struct address_t* node);
void lookupUsingLoc(node **head);
void findusingloc(node**head,int loc[],int *flag);
void writeNodes(node*tree,char filename[]);




//Function to check IP address
bool checkIfIPExists(node**head,int *flag, int lctn[])
{
	if(*head)
	{
		checkIfIPExists((&(*head)->leftChild),lctn,&(*flag));

		if((*head)->addr[0]==lctn[0] && (*(head))->addr[1]==lctn[1] && (*(head))->addr[2]==lctn[2] && (*(head))->addr[3]==lctn[3])
		{
			//Updates flag value to 1 if Ip exists
			*flag=1;
			return 1;
		}
		checkIfIPExists((&(*head)->rightChild),lctn,&(*flag));
	}
	return 0;
}

//Function to compare if two aliases are same
int matchAlias(char *str1, char *str2, int len1, int len2)
{
	if(len1!=len2)
	{
		return 0;
	}
//Caseconversion is handleded
	for (int i=0; i<len1; i++)
	{
		char x=toupper(str1[i]);
		char y=toupper(str2[i]);

		if(x!=y)
		{
			return 0;
		}
	}
	return 1;
}

//Function to check alias names
bool lookupforIPAliasPair(node**head,char*alias,bool * flag)//check if alias exists in bst and change the flag to 1 if exists else 0
{
    if (*head)
    {
        lookupforIPAliasPair(&((*head)->leftChild),alias,&(*flag));
        int l1=strlen((*(head))->alias);
        int l2=strlen(alias);

        if(matchAlias((*(head))->alias,alias,l1,l2)== 1)
        {
           *flag=1;
           return 1;
        }
        lookupforIPAliasPair(&((*head)->rightChild),alias,&(*flag));
    }
    return 0;
}

//To fetch the root(assuming it has greater value among the 2 nodes)
bool root_alias(char *str1, char *str2)
{
	int i,len1;
	len1 = strlen(str1);
	for(i=0;i<len1;i++)
	{
		if(str1[i]>str2[i])
		{
			return 1;
		}
		if(str1[i]<str2[i])
		{
			return 0;
		}
	}
	return 0;

}

//Function to insert a node in BST
void insert(node ** tree, int val[],char alias[], int dep)
{


	node *temp = NULL;
    if((*tree)==NULL)
    {

    	temp = (node *)malloc(sizeof(node));
        temp->leftChild = temp->rightChild = NULL;
        for(int i=0;i<4;i++)
        {
        	temp->addr[i]=val[i];
        }

        strcpy(temp->alias,alias);
        *tree = temp;
        temp->depth = dep;
        temp->height = 0;

        return;
    }


    if(root_alias((*tree)->alias,alias))
    {
        insert(&(*tree)->leftChild, val,alias ,dep+1);

    }
    else
    {
        insert(&(*tree)->rightChild, val,alias, dep+1);
    }


    if(((*tree)->leftChild != NULL) && ((*tree)->rightChild != NULL))
    {
    	(*tree)->rightChild->parent = (*tree);
    	(*tree)->leftChild->parent = (*tree);

    	if((*tree)->leftChild->height < (*tree)->rightChild->height)
    	{
    		(*tree)->height=(*tree)->rightChild->height + 1;
    	}
    	else
    	{
    		(*tree)->height = (*tree)->leftChild->height + 1;
    	}

    }
    else if((*tree)->leftChild != NULL)
    {
    	(*tree)->height=(*tree)->leftChild->height +1;
    	(*tree)->leftChild->parent = (*tree);
    }
    else if((*tree)->rightChild != NULL)
    {
    	(*tree)->height=(*tree)->rightChild->height +1;
    	(*tree)->rightChild->parent = (*tree);
    }

}

//Function to add address
int addAddress(node**root)
{
	char alias[11],ip[25],dot;
	int IP[4];

	//struct address_t *add=NULL;
	bool flag=0;

	// take user input for ip address
	printf("Enter address : ");
	scanf("%s",ip);

	// converts the string to int
	sscanf(ip,"%d%c%d%c%d%c%d", &IP[0],&dot,&IP[1],&dot,&IP[2],&dot,&IP[3]);
	//struct address_t *t;

	// check if ip address  already exist
	flag=0;
	checkIfIPExists(&(*(root)),IP,&flag);

	if(flag==1)
	{
		// if ip address is already present we cannot use it again
		printf("IP Address already exists\n");
		return -1;
	}
	// check if ip address are vaild
	if(IP[0]<0 || IP[0]>255)
	{
		printf("address must be in range [0-255]\n");
		return -1;
	}
	if(IP[0]<0 || IP[0]>255)
	{
		printf("address must be in range [0-255]\n");
		return -1;
	}
	if(IP[0]<0 || IP[0]>255)
	{
		printf("address must be in range [0-255]\n");
		return -1;
	}
	if(IP[0]<0 || IP[0]>255)
	{
		printf("address must be in range [0-255]\n");
		return -1;
	}
	printf("Enter alias name: ");
	scanf("%s",alias);
	flag=0;
	lookupforIPAliasPair(root,alias,&flag);

	if(flag==1)
	{
		// as alias does  exist . return the function
		printf("%s already exists\n" ,alias);
		return -1;
	}
	//printf("%d.%d.%d.%d %s\n",IP[0],IP[1],IP[2],IP[3],alias);
	insert(&(*root),IP,alias, 0);
	return 0;

}

//Function to find needed node using alias
node* lookupUsingAlias(node**head,char*alias)
{
	if (*head)
	{
		lookupUsingAlias((&(*head)->leftChild),alias);
		int len1=strlen((*(head))->alias);
		int len2=strlen(alias);


		if(matchAlias((*(head))->alias,alias,len1,len2)== 1)
		{
			printf("%s %d.%d.%d.%d\n",(*head)->alias,(*head)->addr[0],(*head)->addr[1],(*head)->addr[2],(*head)->addr[3]);
			return ((*head));
		}
		lookupUsingAlias((&(*head)->rightChild),alias);
	}
	return NULL;
}

//Function to update the node address after finding it using alias
int updateAddress(node ** head)
{
	char alias[11];
	printf("Enter alias name:");
	scanf("%s",alias);
	int IP[4];

	bool flag=0;
	lookupforIPAliasPair(&(*(head)),alias,&flag);

	if(flag!=1) //Flag is not 1 only when no match was found
	{
		printf("%s does not exists\n" ,alias);
		return -1;
	}
	//if match was found, user is prompted to enter the updated location
	for(int i=0;i<4;i++)
	{
		while(1)  // loops until four valid inputs are recieved
		{
			printf("Enter Location #%d\n",i+1);
			while(getchar() != '\n');
			scanf("%d",&IP[i]);
			if(IP[i]>=0 && IP[i]<=255) // if valid input is received stop loop
			{
				break;
			}
			else // if not valid input
			{
				printf("Invalid Entry\n");
			}
		}
	}

	// check if ip address  already exist
	flag=0;
	checkIfIPExists(&(*(head)),IP,&flag);

	 if(flag==1)
	 {
		 // if ip address is already present we cannot use it again
		 printf("Ip Address already exists\n");
		 return -1;
	 }
	 //call helper function to update the address
	 updateNode(&(*head),IP,alias);

	 return 0;

}

//helper function for update values of the node
void updateNode(node**head,int ip[],char*alias)
{
    if (*head)
    {
        updateNode((&(*head)->leftChild),ip,alias);
        int len1=strlen((*(head))->alias);
        int len2=strlen(alias);

        if(matchAlias((*(head))->alias,alias,len1,len2)== 1)
        {
           //updating values
          for(int i=0;i<4;i++)
            ((*head))->addr[i]=ip[i];
        }
        updateNode((&(*head)->rightChild),ip,alias);
    }

}

//Helper function to delete the node 
void depth_correct(node *head){

	  if (head != NULL) {
	    if (head -> parent == NULL) {
	      head -> depth = 0;
	    } else {
	      head -> depth = head -> parent -> depth + 1;
	    }
	    if (head -> leftChild != NULL) {
	      head -> leftChild -> depth = head -> depth + 1;
	      depth_correct(head -> leftChild);
	    }
	    if (head -> rightChild != NULL) {
	      head -> rightChild -> depth = head -> depth + 1;
	      depth_correct(head -> rightChild);
	    }
	  }
}
//Helper function to delete node
void height_correct(node *head){

	  if (head != NULL) {
	    if ((head -> leftChild != NULL) && (head -> rightChild != NULL)) {
	      if (head -> leftChild -> height < head -> rightChild -> height)
	        head -> height = head -> rightChild -> height + 1;
	      else {
	        head -> height = head -> leftChild -> height + 1;
	      }
	    } else if (head -> rightChild != NULL) {
	      head -> height = head -> rightChild -> height + 1;
	    } else if (head -> leftChild != NULL) {
	      head -> height = head -> leftChild -> height + 1;
	    } else {
	      head -> height = 0;
	    }
	    height_correct(head -> parent);
	  }

}

//Function to delete a node
struct address_t* deleteAliasIP(struct address_t*head,char* alias,int cont)
{
	// base case
	if(head == NULL)
	{
		printf("%s not found\n",alias);
		return head;
	}

	// If the aliases to be deleted is smaller than the head alias, then it lies in left subtree
	if (root_alias(head->alias,alias)==1)//find greater alias/key
	{
		head->leftChild = deleteAliasIP(head->leftChild, alias,1);
		depth_correct(head);
		height_correct(head);
	}

	// If the alias to be deleted is greater than the head's alias, then it lies in right subtree
	else if (root_alias(alias,head->alias)==1)
	{
		head->rightChild = deleteAliasIP(head->rightChild, alias,1);
		depth_correct(head);
		height_correct(head);
	}

	else
	{
		if(cont)
		{
			char conf;
			int a=head->addr[0];
			int b=head->addr[1];
			int c=head->addr[2];
			int d=head->addr[3];

		}
		// if node has only one child or no child
		if (head->leftChild == NULL)
		{
			struct address_t* temp = head->rightChild;
			free(head);
			return temp;
		}
		else if(head->rightChild == NULL)
		{
			struct address_t* temp = head->leftChild;
			free(head);
			return temp;
		}

		// if node has two children then get the in order susccessor
		// minimum in the right subtree
		struct address_t* temp = minNodeValue(head->rightChild);

		// Copy the successor's content to this node
		strcpy(head->alias,temp->alias);

		// Delete the in order successor
		head->rightChild = deleteAliasIP(head->rightChild, temp->alias,0);
		depth_correct(head);
		height_correct(head);

	}
	return head;
}

//Function to read the file and store in the form of a Binary tree
int readFile(node ** tree,char *file_path)
{
	char ip[15];
	int IP[4];
	char alias[32];
	int a,b,c,d;
	char dot;

	// opening the file in read mode
	FILE *fptr=fopen(file_path,"r");

	if(fptr==NULL)
	{
		printf("error: file cannot be opened\n");
		return -1;
	}
	while (!feof(fptr))
	{
		// reading formatted file
		fscanf(fptr,"%d%c%d%c%d%c%d %s", &a,&dot,&b,&dot,&c,&dot,&d,alias);

		// if data is read
		if(strlen(alias)!=0)
		{
			IP[0]=a;
			IP[1]=b;
			IP[2]=c;
			IP[3]=d;

			// passing the last argument 0 to indicate no user input
			insert(&(*tree),IP,alias, 0);

		}
		// clearing the buffers
		strcpy(ip,"");
		strcpy(alias,"");
	}
	// closing the file
	fclose(fptr);

	return 0;
}


//Function to display tree
void displayTree(node *tree)
{
	if(tree==NULL)
	{
		return;
	}
	displayTree(tree->leftChild);

	if(tree->parent == NULL)
	{
		printf("%d.%d.%d.%d %s\n",tree->addr[0],tree->addr[1],tree->addr[2],tree->addr[3],tree->alias);
	}
	else
	{
		printf("%d.%d.%d.%d %s\n",tree->addr[0],tree->addr[1],tree->addr[2],tree->addr[3],tree->alias);
	}
	displayTree(tree->rightChild);
}


// Helper function to find minimum value node in the subtree rooted at `curr`
struct address_t* minNodeValue(struct address_t* node)
{
	struct address_t* current = node;
	while (current && current->leftChild != NULL)
	{
		current = current->leftChild;
	}

	return current;
}


//find the alias and IP using location
void lookupUsingLoc(node **head)
{
	int lctn[2];

	// getting the loc octets
	for(int i=0;i<2;i++)
	{
		// loop until valid inputs are reviewed
		while(1)
		{
			printf("enter location # %d\n",i+1);
			scanf("%d",&lctn[i]);
			if(lctn[i]>=0 && lctn[i]<=255)
			{
				break;
			}
			else
			{
				printf("invalid entry\n");
			}
		}
	}

	int flag=0;
	findusingloc(head,lctn,&flag);

	if(!flag)
	{
		printf("no matching location  exists\n");
	}


}

//helper function for find_by_loc
void findusingloc(node**head,int lctn[],int *flag)
{
   if (*head)
    {
        findusingloc(&((*head)->leftChild),lctn,flag);
        if((*head)->addr[0]==lctn[0] && (*head)->addr[1]==lctn[1])
        {   *flag=1;
            //printf("%s %d.%d.%d.%d\n",(*head)->alias,(*head)->addr[0],(*head)->addr[1],(*head)->addr[2],(*head)->addr[3]);
            printf("%s\n",(*head)->alias);
        }
        findusingloc((&(*head)->rightChild),lctn,flag);
    }
}

void save_list(node*head)
{
    char filename[100]={"output.txt"};
    //printf("Enter file name >> ");
   // scanf("%s",filename);
    FILE *fptr=fopen(filename,"w");
    //if file cannot be opened
   if(fptr==NULL){

        printf("cannot open output file\n");
        return ;
   }
   //if list is emtpy
   if(head==NULL){
        printf("tree is empty\n");
        return ;
   }
    fclose(fptr);
   // printing to file
    writeNodes(head,filename);
   /// closing the file


 return ;
}

//Function to write the data into the file 
void writeNodes(node*tree,char filename[])
{
	if(tree==NULL)
	{
		return;
	}

	writeNodes(tree->leftChild,filename);
	//Appending the each node one at a time in file
	FILE *fptr;

	/*  Open all file in append mode. */
	fptr = fopen(filename, "a");

	fprintf(fptr,"%s %d.%d.%d.%d \n",tree->alias,tree->addr[0],tree->addr[1],tree->addr[2],tree->addr[3]);
	fclose(fptr);

	writeNodes(((tree))->rightChild,filename);
}

int main()
{
	struct   address_t *root;
	root = NULL;
	int choice;

	//Read the contents of the file
	readFile(&root,"CS531_Inet.txt");
	while(1)
	{
		printf("\n**************************************************\n");
		printf("1)Add address\n");
		printf("2)Look up address\n");
		printf("3)Update address\n");
		printf("4)Delete address\n");
		printf("5)Display Tree\n");
		printf("6)Display aliases for location\n");
		printf("7)Save to file\n");
		printf("8)Quit\n");
		printf("\n**************************************************\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		while(getchar() != '\n');

		switch(choice)
		{

		case 1:
		{
			addAddress(&root);
			break;
		}

		case 2:
		{
			char alias[11];
			printf("Enter Alias Name ");
			scanf("%s",alias);
			bool flag=0;
		    lookupforIPAliasPair(&root,alias,&flag); 

		    if(flag==1)
		    {
		    	lookupUsingAlias(&root,alias);

		    }
		    else
		    {
		    	printf("%s does not exists\n",alias);
		    }

		    break;
		}

		case 3:
		{
			updateAddress(&root);
			break;
		}

		case 4:
		{
			char alias[11];
			char confirm=0;
			printf("Enter Alias to delete:  ");
			scanf("%s",alias);


			lookupUsingAlias(&root,alias);
			printf("Confirm to delete? (y/n)\n");
			scanf(" %c",&confirm);
			if(confirm=='y')
			{
				// y means yes. Node can only be deleted after chosing yes
				deleteAliasIP(root,alias,1);
			}
			break;
		}

		case 5:
		{
			displayTree(root);
			break;
		}

		case 6:
		{
			lookupUsingLoc(&root);
			break;
		}

		case 7:
		{
			char file[100];
			printf("Enter file name: ");
			scanf("%s",file);
			fclose(fopen(file, "w"));//creates a new file if the file does not exist
			writeNodes(root,file);//Writes data into the created file
			break;
		}

		case 8:
		{
			printf("EXIT!\n");
			return 0;
			break;

		}

		default:
		{
			//If the option chosen is not a valid option from the menu
			printf("error: invalid input.Please select menu options only \n");
			break;
		}

		}
	}
	return 0;
}
