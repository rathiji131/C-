/*
    *Name         : Madhusudan Rathi
    *Date         : 10/08/2020
    *Description  : To print heloo in X format
    *Ex. Input    : Enter number of lines : 5 
    *Ex. output   : Hello    Hello
                     Hello  Hello
                      HelloHello
                     Hello  Hello
                    Hello    Hello 
*/
#include<stdio.h>                                           //Preprocessor directives executes before program execution starts                  
int main()                                                  //Start of main function which returns int value
{   
    int n;                                                  //Declaration of variables
    char ch;
    do                                                      //Start of do while loop
    {
        printf("Enter number of lines : ");                 //Asking user to to enter number of lines
        scanf("%d",&n);                                     //Storing users response
        printf("\n");
        if(n > 0 && n < 32)                                 //Validating input
        for(int i = 1 ; i <= n ; i++)                       //loop for number of lines
        {
            for(int j = 1 ; j <= n+1 ; j++)                 //loop for row
            {   
                if(i == j || i==n + 1-j)                    //Logic for printing Hello in 'X' format 
                    printf("Hello");   
                else if (n % 2 == 0)
                    printf(" ");
                if(i == j && i==n + 1-j) 
                    printf("Hello");       
                else if(n % 2)
                    printf(" ");
            }
        printf("\n");
        }
        else
            printf("Number out of range .");                //if user enters -ve or >32 -->invalid input
        getchar();                                          //Get single charecter as input from std input device
        printf("Do you want to continue y/n : ");           //Continuation prompt
        scanf("%c",&ch);                                    //Storing users response if continuation
        getchar();
    }while(ch == 'y' || ch == 'Y');                         //Validation of users response
    return 0;                                               //End of main function
}

