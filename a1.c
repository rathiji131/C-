/*
    *Name         : Madhusudan Rathi
    *Date         : 06/08/2020
    *Description  : Check whether a given number is odd or even and its signedness
    *Ex. Input    : 2
    *Ex. output   : 2 is +ve even number
*/

#include <stdio.h>    /*# Preprocessor directives*/
#include <math.h>
int main()            /*# main function*/
{
    signed  int n;    /*# Declaring variable*/
    char ch;
    do                /*# Start of do loop*/
    {
        printf("Enter a number 'n' : ");       /*# Asking user to enter a number*/
        scanf("%d",&n);                        /*# Storing that number in n*/
       
        if(n > pow(2,20))                      /*# Checking n > 2^20 or not */
        {
            printf("Number out of range.\n");  /*# if yes printing sms*/
        }
        else if(n < -pow(2,20))                /*# checking  n<-(2^20)*/
        {
            printf("Number out of range.\n");  /*# if yes printing sms*/
        }
        else
        {
        if( n > 0 )                           /*# checking n > 0 ,if yes ,goes inside*/
        {
            if( n % 2 == 0 )                   /*# checking even or not*/
                printf("%d is +ve even number.\n",n); /*# if yes print +ve even*/
            else
                printf("%d is +ve odd number.\n",n);  /*# if no print +ve odd*/
        }
        else if(n < 0)
        {
            if( n % 2 == 0 )                   /*# checking even or not*/
                printf("%d is -ve even number.\n",n); /*#if yes pribt -ve even*/
            else
                printf("%d is -ve odd number.\n",n);  /*#if no print -ve odd*/
        }
        else
            printf("Neither Even nor odd.\n");
        }      
        getchar(); /*# is a function that reads single charecter from std i/p stream*/
        printf("Do you want to continue(y/n) : ");  /*# asking do you want to continue*/
        scanf("%c",&ch); /*# storing users reply*/
        getchar();
    }while(ch=='y'); /* # checking users wants to continue or not ,if yes again goes to do. */
    return 0; /*# end of function*/
}
