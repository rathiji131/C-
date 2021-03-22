/*
    *Name         : Madhusudan Rathi
    *Date         : 20/08/2020
    *Description  : Calculate the factorial of given number by recursively calling of main function
    *Ex. Input    : Enter a number : 5
    *Ex. output   : Factorial of 5 is : 120
*/
#include<stdio.h>
int main()                                                                 //start of main function
{
    char ch;                                                               //variable declaration         
    static int n, flag = 1,fact = 1,temp;
    do
    {
        if(flag == 1)                                                      //this if condition is for executing onece while recursion of main function
        {
            printf("Enter a number : ");
            scanf("%d",&n);
            temp = n;
            flag = 0;
        }
        if(n > 0)                                                          //validating condition as factorial is calculated for only +ve num
        {
            fact = fact * n;                                               //logic of factorial
            n = n - 1;
            return main();                                                 //calling main function
        }
        printf("factorial of %d is  %d\n",temp,fact);                      //Printing factorial of given  number
        flag = 1;                                                          //assigning values to variable 
        n = 0 ; 
        fact = 1;
        temp = 0;
        getchar();                                                         //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                        //Asking user for continuation option
        scanf("%c",&ch);                                                   //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                        //Validating users response for continuation
    return 0;                                                              //End of main function
}
