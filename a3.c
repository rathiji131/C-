/*
    *Name         : Madhusudan Rathi
    *Date         : 06/08/2020
    *Description  : To check whether a given number is perfect or not.
    *Ex. Input    : 6
    *Ex. output   : Yes, entered number is perfect number.
*/
#include<stdio.h>                         // Preprocessor directives
#include<math.h>
int main()                                // main function
{  
    int num;                              // Declaration of variables
    int sum=0;
    char ch;
    do                                    // start of do while loop
    {
        printf("Enter a number : ");       
        scanf("%d",&num);                // Taking input from user
        if(num < pow(2,20) && num > 0)
        {
            for(int i=1;i<num;i++)       // logic for checking number is perfect or not
            {
                if(num % i == 0)
                {
                    sum = sum + i;
                }
            }   
            if(sum == num)              // if perfect print below sms
            {
                printf("Yes,entered number is perfect number.\n");
            }
            else 
            {
                printf("No,entered number is not a perfect number.\n");
            }
        }
        else if(num > pow(2,20))       // validating  out of range conditon
            printf("Number out of range.\n");
        else
            printf("Invalid input!!\n"); //if input is not in fitting in our conditions then invalid input
        getchar();                     //code for redoing the same program
        printf("Do you want to continue : ");
        scanf("%c",&ch);
        getchar();
    }while(ch=='y');
    return 0;
}


