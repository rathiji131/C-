/*
 *Name         : Madhusudan Rathi
 *Date         : 18/08/2020
 *Description  : Printing fibonacci series till given number
 *Ex. Input    : Enter the value n : 100
 *Ex. output   : Fibonacci series using recursive function is 
                 0 1 1 2 3 5 8 13 21 34 55 89
 */
#include<stdio.h>
#include<stdlib.h>
int fibo_recursion(int *n,int *n1,int *n2,int *next);
int main()                                                                 //start of main function
{
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    {
        int n,n1 = 0,n2 = 1,next = 0;                                      //Declaration of variable
        int *ptr,*ptr1,*ptr2,*ptr3;                     
        printf("Enter the value n : ");                                    //Asking user to take input
        scanf("%d",&n);                                                    //storing it in variable
        ptr = &n;                                                          //Storing addrrss of variable in pointers
        ptr1 = &n1;     
        ptr2 = &n2;
        ptr3 = &next;

        printf("Fibonacci series using recusive function is \n");          
        if ( n > 0)
        {
            while( next <= n )                                             //loop for positive number
            {
                printf("%d ",next);
                fibo_recursion(ptr,ptr1,ptr2,ptr3);
            }
        }
        else
        {
            while( next >= n && next <= -n )                               //loop for negative number  
            {
                printf("%d ",next);
                fibo_recursion(ptr,ptr1,ptr2,ptr3);
            }
        }
        getchar();                                                         //Gets single charecter from std input device
        printf("\nDo you want to continue yY/nN : ");                      //Asking user for continuation option
        scanf("%c",&ch);                                                   //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                        //Validating users response for continuation
    return 0;                                                              //End of main function
}
int fibo_recursion(int *n,int *n1,int *n2,int *next)                       //function defination 
{
    if(*n > 0)                                                             //logic for positive number 
    {
        *next = *n1 + *n2;
        *n1 = *n2;
        *n2 = *next;
    }
    if(*n < 0)                                                             //logic for negative number
    {
        *next = *n1 - *n2;
        *n1 = *n2;
        *n2 = *next;
    }
    return 0;
}
