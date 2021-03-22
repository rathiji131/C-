/*
    *Name         : Madhusudan Rathi
    *Date         : 21/09/2020
    *Description  : WAP to demote the type of given float number to integer using bitwise operator and bitfeilds
    *Ex. Input    : Enter any float number : 12.43 
    *Ex. output   : Demoted value is 12.000000
*/
#include<stdio.h>                                                          //Preprocessor directives
typedef union                                                              //union defination
{
    float f;                                                               
    struct
    {
        unsigned int mentissa  : 23;
        unsigned int exponent  : 8;
        unsigned int sign     : 1;
    }bit_parts;
}float_cast;
int main()                                                                 //start of main function
{
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    {
        float num,res = 0;                                                 //variable declaration
        int men = 0, expo = 0,sign,n_bits,n_bits_men,red_num;               
        printf("Enter any float number : ");                               //asking user for input
        scanf("%f",&num);
        if(num < 1 && num >= 0)                                            //if its less than 1 and > 0 print 0.000000
        {
            printf("0.000000");
            return 0;
        }
        float_cast fc = {.f = num};                                        //taking instance of union
        sign = fc.bit_parts.sign;                                          //taking sign,memtissa and exponenet bits of number
        expo = fc.bit_parts.exponent;
        men  = fc.bit_parts.mentissa;
        n_bits = expo - 127;                                               //logic for getting only integer part of float value
        n_bits_men =  ((((1 << n_bits) - 1) << 22 - n_bits + 1) & men) >> 22 - n_bits + 1;
        red_num = (1 << n_bits) | n_bits_men;
        if(sign == 0)
            printf("Demoted value is %d.\n",red_num);
        else
            printf("Demoted value is %d.\n",-red_num);
        getchar();                                                         //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                        //Asking user for continuation option
        scanf("%c",&ch);                                                   //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                        //Validating users response for continuation
    return 0;                                                              //End of main function

}


