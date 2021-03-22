/*
 *Name         : Madhusudan Rathi
 *Date         : 21/09/2020
 *Description  : Read n & n person names of maxlen 32. Sort and print the names
 *Ex. Input & output   : 
 Enter number of elements in array : 3
 Enter 3 elements of max length 32 charecter in each : 
 [0] ->  kajol
 [1] ->  madhu
 [2] ->  ajay

 Sorted array is
 [0] ->  ajay 
 [1] ->  kajol 
 [2] ->  madhu 
 Do you want to continue yY/nN :
 */
#include<stdio.h>                                                           //preprocessor directives
#include<stdlib.h>
#include<string.h>
#define SIZE 32                                                             //macro define
int sort(const void* a,const void* b); 
int my_strcmp(const char *,const char *);
int main()                                                                 //start of main function
{
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    {
        int n,i;                                                           //variable declaration
        printf("Enter number of elements in array : ");                    //asking user for number of strings
        scanf("%d",&n);
        printf("Enter %d elements of max length 32 charecter in each : \n",n);
        char *word[n];
        for(i=0;i<n;i++)                                                    //alloacting memory and reading it
        {
            word[i] = malloc(SIZE * sizeof(char)); /* allocates 32 bytes */
            printf("[%d] ->  ",i);
            scanf("%s", word[i]);
        }
        qsort(word, n, sizeof(const char*), sort);                          //inbuilt function call
        printf("\nSorted array is\n");                                      //printing sorted array
        for (i = 0; i < n; i++) 
            printf("[%d] ->  %s \n", i, word[i]);
        getchar();                                                         //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                        //Asking user for continuation option
        scanf("%c",&ch);                                                   //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                        //Validating users response for continuation
    return 0;                                                              //End of main function
}

int sort(const void* a,const void* b)                                       //function for sorting it alphabetically
{
    return my_strcmp(*(char**)a, *(char**)b);
} 

int my_strcmp(const char *a, const char *b)                         //function efination of my_strcmp function
{
    while (*a && *a == *b) 
    { 
        ++a; 
        ++b; 
    }
    return (int)(unsigned char)(*a) - (int)(unsigned char)(*b);
}
