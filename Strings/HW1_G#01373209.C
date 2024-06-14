//Created by Anjali J Murthy.
//G# 01373209
//Program to sort 10 input strings


#include <stdio.h>
#include <string.h>
#include<stdbool.h>

//Function to check for duplicates in the input array
const char* chkfordup(char str[10][25],int i)
{
    if(i>0)
    {
        for(int k=i-1; k>=0;k--)
        {
            if(strcmp(str[k],str[i]) ==0 )
            {
                printf("Err:%s is a duplicate string",str[i]);
                return "Match";
                break;
            }
        }
    }
    return "No match";
}

//Function to print the highest and the lowest ascii values
void ASCIIReturn(char str[10][25],bool result)
{
    if(result == true)
        {
            printf("String with highest ASCII Value is %s \n", str[9]);
            printf("String with lowest ASCII Value is %s \n", str[0]);
        }
}

//Function to Sort in Ascending or Descending order
bool Sort(char str[10][25])
{
    bool result = false;
    printf("Enter the sorting method 'A' or 'D':");
        char select;
        scanf("%s", &select);
        switch(select){
            case 'A':
                result = true;
                printf("Ascending order sorting: \n");
                for(int i=0;i<10;i++){
                    printf("%s",str[i]);
                }
                break;
            case 'D':
                result=true;
                printf("Descending order sorting: \n");
                for(int i=9;i>=0;i--){
                    printf("%s",str[i]);
                }
                break;
            default:
                result = false;
                printf("Err: Invalid character. Please select only 'A' or 'D'.");
        }
    return result;
}

//Function to perform sorting of the input array
void sorting(char str[10][25])
{
    //For sorting array
        char temp[30];
    for(int i=0; i<10; i++){
        for(int j=0; j<9-i; j++){
            if(strcmp(str[j], str[j+1]) > 0){
                strcpy(temp, str[j]);
                strcpy(str[j], str[j+1]);
                strcpy(str[j+1], temp);
            }
        }
    }
    //Call to function to sort in ascending or descending order
    bool result = Sort(str);
    //Call to function that prints the ASCII Value
    ASCIIReturn(str,result);
}



int main() {
    char str[10][25];
    int i=0;
    printf("Enter the 10 strings\n");
    while(i<10)
    {
        printf("Enter the %d string :", i);
        fgets(str[i],250,stdin);
        
        //Check for empty string
        if(strlen(str[i])==1){
            printf("Empty string error.Please re-enter");
            continue;
        }
        
        //Checking for string length exceeding 25
        if(strlen(str[i])>25){
            printf("String length exceeding.Please re-enter");
            continue;
        }
        
        //Checking for special characters
        if(((strstr(str[i],"$"))||(strstr(str[i],"#"))||(strstr(str[i],"%"))||(strstr(str[i],"^"))||(strstr(str[i],"@"))||(strstr(str[i],"("))||(strstr(str[i],")"))))
        {
                    char *ret;
                    char *charecters = "@ $  # %  ^ ( )";
                    //To throw error if the special character exists
                    ret = strpbrk(charecters,str[i]);
                    printf("%c is an illegal character. Please re-enter \n", ret[0]);
                    continue;
        }
        //Call the string duplicate function
        const char *value = chkfordup(str,i);
        if(strcmp(value,"Match")== 0 )
        {
            printf("Please re-enter %d string",i);
            continue;
        }
        i++;
    }
    
    //Call the sort function
     sorting(str);
    
    return 0;
}
