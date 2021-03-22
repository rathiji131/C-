/*
    *Name         : Madhusudan Rathi
    *Date         : 09/08/2020
    *Description  : Program to print AP , GP, HP 
    *Ex. Input    : Enter first number 'a' : 2
                    Enter comon difference/ratio 'r' : 3
                    Enter number of terms 'n' : 5
    *Ex. output   : AP : 2 5 8 11 14
                    GP : 2 6 18 54 162
                    HP : 0.5 0.2 0.125 0.0909091 0.0714285
*/

#include <stdio.h>              //Preprocessor directives
#include <math.h>

int main()
{
    int a,r,n,next_term=0;      //Declaration of variables
    char ch;
    do                          //start of do while loop for continuation
    {
        printf("Enter first Number 'a' : ");        //taking first number , common difference and number of terms from user
        scanf("%d",&a);   
        printf("Enter commmon difference/ratio 'r' : ");
        scanf("%d",&r);   
        printf("Enter Number of terms :'n' : ");
        scanf("%d",&n);
        if(a > 0 && r > 0 && n > 0)           //validating inputs are positive or  not
        {
            if(a < 1024 && r < 1024&& n < 1024) //validating inputs are in range or not
            {
                printf("\nAP : ");          // lofic gor generating AP
                for(int i = 1 ; i <= n ; i++)   
                {
                    next_term=a+(i-1)*r;
                    if(i == n)
                        printf("%d",next_term);
                    else
                        printf("%d, ",next_term);
                }
                printf("\nGP : ");          // logic for gfenerating GP
                next_term=a;
                for(int j = 1 ; j <= n ; j++)   
                {
                    next_term = next_term * r;
                    if(j == n)
                        printf("%d",next_term);
                    else 
                        printf("%d, ",next_term);
                }
                printf("\nHP : ");          // logic for generating HP
                next_term = 0;
                for(int i = 1 ; i <= n ; i++)   
                {
                    next_term = a + (i-1) * r;
                    if(i == n)
                        printf("%g", (1/(float)next_term));
                    else
                        printf("%g, ",(1/(float)next_term));
                } 
            }
            else                                                          printf("Inputs outof range ! "); 
            
        }
        else
               printf("Invalid Inputs !"); 
        printf("\n");
        getchar();                          //asking user for continuation
        printf("Do you want to continue(y/n) : ");
        scanf("%c",&ch);                    //saving his respnse
        getchar();
    }while(ch == 'y');                      //checking of condition
    return 0;                               //end if main function
}














