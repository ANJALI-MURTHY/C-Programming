#include<stdio.h>
#include<stdlib.h>
#include "header.h"
#include<string.h>

extern struct address_t *head; //Extern variable head

//Function to delete the address/alias pair
void deleteAddress(char str[11])
{
	char alias[30];
    int status;
    printf("\nEnter the alias name to delete :");
    scanf("%s",alias);
    struct address_t *ptr = head;
    struct address_t *temp;
    while(ptr != NULL){
        if(strcmp(ptr->alias,alias)==0){
            printf("\nAddress for %s is %d.%d.%d.%d\n",ptr->alias,ptr->octet[0],ptr->octet[1],ptr->octet[2],ptr->octet[3]);
            printf("\nAre you sure you want to delete this address ? (1/0)\n");
            scanf("%d",&status);
            if(status){
                if(strcmp(head->alias,alias)==0){
                    temp = head;    
                    head = (head)->next;
                    free(temp);
                }else{
                    struct address_t *current  = head;
                    while(current->next != NULL){
                        if(strcmp(current->next->alias,alias)==0){
                          temp = current->next;
                          current->next = current->next->next;
                          free(temp);
                          break;
                        }else
                            current = current->next;
                    }
                }
                printf("Address successfully deleted");
            }else{
                printf("Address is not deleted");
            }
            return;
        }else{
            ptr = ptr->next; 
        }
    }
    printf("\nAddress not found\n");
    displayList();
    return; 
}
