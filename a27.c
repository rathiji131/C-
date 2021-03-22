/*
 *Name         : Madhusudan Rathi
 *Date         : 11/08/2020
 *Description  : Swap the numbers using macro
 *Ex. Input    : Hardcoded values
 *Ex. output   : Before swapping : i1 = 2 and  i2 = 3
After Swapping  : i1 = 3 and  i2 = 2
Before swapping : f1 = 51.34 and  f2 = 62.74
After swapping  : f1 = 62.74 and  f2 = 51.34
Before swapping : d1 = 34.54 and  d2 = 98.43
After swapping  : d1 = 98.43 and  d2 = 34.54
Before swapping : c1 = a and  c2 = d
After Swapping  : c1 = d and  c2 = a

 */
#include<stdio.h>                           //macro defination
#define SWAP(t,x,y)                   \
{                                     \
    t temp;                           \
    temp = x;                         \
    x = y;                            \
    y = temp;                         \
}                                     \ 

int main()                                                                 //start of main function
{
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    {
        int i1 = 2, i2 = 3;                                                //variable declaration and initialisation
        float f1 = 51.34, f2 = 62.74;
        double d1 = 34.54 , d2 = 98.43;
        char c1 = 'a', c2 = 'd';
        printf("Before swapping : i1 = %d and  i2 = %d\n",i1,i2);           //printing before swapping
        SWAP(int,i1,i2);                                                    //macro call
        printf("After Swapping  : i1 = %d and  i2 = %d\n",i1,i2);           //printing after swapping
        printf("Before swapping : f1 = %g and  f2 = %g\n",f1,f2);           
        SWAP(float ,f1,f2);
        printf("After swapping  : f1 = %g and  f2 = %g\n",f1,f2);                    
        printf("Before swapping : d1 = %g and  d2 = %g\n",d1,d2);                          
        SWAP(double ,d1,d2);       
        printf("After swapping  : d1 = %g and  d2 = %g\n",d1,d2);
        printf("Before swapping : c1 = %c and  c2 = %c\n",c1,c2);            
        SWAP(char ,c1,c2);
        printf("After Swapping  : c1 = %c and  c2 = %c\n",c1,c2);
        getchar();                                                         //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                        //Asking user for continuation option
        scanf("%c",&ch);                                                   //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                        //Validating users response for continuation
    return 0;                                                              //End of main function
}


