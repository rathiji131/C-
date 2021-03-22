/*
    *Name         : Madhusudan Rathi
    *Date         : 6/8/2020
    *Description  : Print fibonacci series till given number
    *Ex. Input    : -13
    *Ex. output   : 0 1 -1 2 -3 5 -8 13
*/


#include <stdio.h>                      // Preprocessor Directives

int main()                              // main function
{
    signed int n,n1=0,n2=1,next=0;      // declaration of variables
    char ch;
    do                                  // Start of do while loop   
    {
        n1=0;
        n2=1;
        next=0;
        printf("Enter a number : ");    // Asking user to enter n number 
        scanf("%d",&n);                 // Storing it in n
        printf("%d %d",n1,n2);          // printing first 2 numbers
        if(n > 0)                       // validating n > 0 or not 
        while(next <= n)                // validating next terms <= n
        {   
            next=n1+n2;                 // logic of fibonacci series
            n1=n2;
            n2=next;
            if(next <= n)
                 printf(" %d",next);    //printing the terms of series
            else
                 break;                // if next>n then breaking whileloop
        }
        else                           // for negavtive number series
        {
            while(next >= n || next >= -n) // checking next >= n and next <= -n
            {
                next=n1-n2;               //logic for nehgative numbers series
                n1=n2;
                n2=next;
                if(next >= n && next <= -n) // checking condition
                    printf(" %d",next);   // printing the terms
                else
                    break;                // break loop
            }    
        }
        getchar();             //code for repetation if program
        printf("\nDo you want to continue : ");  
        scanf("%c",&ch);
        getchar();
    }while(ch=='y');
    return 0;                 // end of main function
} 
