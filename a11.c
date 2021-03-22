/*
    *Name         : Madhusudan Rathi
    *Date         : 09/08/2020
    *Description  : To find the number is odd or even using LSB
    *Ex. Input    : Enter number : 4
    *Ex. output   : 4 is +ve EVEN number.
*/
#include<stdio.h>                                                  //this is processed before c program process 
int main()                                                         //start of main function
{   
    int number;                                                    // declaration of variables
    char ch;    
    do                                                             //start of do while loop
    {
        printf("Enter number : ");                                 
        scanf("%d",&number);                                       //taking input from user
        if(number & 80000000)                                      //checking condition for positive number,if positive ->go inside if else go to else block
            if(number & 1)                                         //Checking LSB bit ->if 1 ->  prints odd , else prints even
                printf("%d is -ve ODD number.\n",number);
            else
                printf("%d is -ve EVEN number.\n",number);    
        else
            if(number & 1)                                         //Checking LSB bit ->if 1 ->  prints odd , else prints even
                printf("%d is +ve ODD number.\n",number);
            else
                printf("%d is +ve EVEN number.\n",number);    
        getchar();                                                 //gets single charecter fron std input device
        printf("Do you want to continue : ");                      //asking user for continuation
        scanf("%c",&ch);                                           //storing users input
        getchar();
        }while(ch=='y');                                           //checking users choice of continuation
    return 0;                                                      //end of main function
}


