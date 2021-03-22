/*
    *Name         : Madhusudan Rathi
    *Date         : 18/08/2020
    *Description  : Implementing pre increment and post increment
    *Ex. Input    : Enter a number :12
                    Enter the option : 
                    1.Pre Increment
                    2.Post Increment
                    choice : 1
    *Ex. output   : Pre increment i = 13 and num = 13. 
*/
#include<stdio.h>
int pre_increment(int *);
int post_increment(int *);
int main()                                                                 //start of main function
{
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    {   
        int n,op,i,*nptr;
        printf("Enter a number : ");                                       //Asking user for number
        scanf("%d",&n);                                                    //storing number 
        printf("Enter the option :\n1.Pre Increment\n2.Post In crement\nchoice : ");//printing menue
        scanf("%d",&op);                                                   //storing it in op
        nptr = &n;                                                         //storing address of variable 
        if(op == 2)                                                        //checking according to user input
        {
            printf("After post increment i = %d ",n);                   
            i = post_increment(nptr);                                      //function call for post increment
            printf("num = %d\n",i);                                        //printing post incremented
        }
        else
        {
            i = pre_increment(nptr);                                       //calling pre incremented function
            printf("After pre increment i = %d num = %d\n",i,n);           //Printing after preincrement function call
        }
        getchar();                                                         //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                        //Asking user for continuation option
        scanf("%c",&ch);                                                   //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                        //Validating users response for continuation
    return 0;                                                              //End of main function
}
int pre_increment(int *nptr)                                               //logic for preincrement
{   int y = 1;                                                             //variable declaration
    while(y != 0 )                                                         
    {
        int carry;
        carry = *nptr & 1;
        *nptr = *nptr ^ 1;
        y = carry << 1;
    }
    return *nptr;
}
int post_increment(int *nptr)                                             //logic for post incrememt
{   int y = 1;
   
    while(y != 0 )
    {
        int carry = *nptr & 1;
        *nptr = *nptr ^ 1;
        y = carry << 1;
    }
    return *nptr;
}
