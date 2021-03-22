/*
    *Name         : Madhusudan Rathi
    *Date         : 06/08/2020
    *Description  : print the decimal numbers from 0 to 127 in octal, hexdecimal and i ASCII representation.
    *Ex. Input    : No input
    *Ex. output   : Dec       Oct         Hex       ASCII
                    1         001          00       Non printable .......  
*/

#include <stdio.h>        // preprocessor directives
int main()                // start of main function
{
   printf("Dec\tOct\tHex\tCharecter\n"); 
   printf("_______________________________________\n");

   for (int i = 0 ; i <= 32 ; i++) // printing first 33 dec, oct, hex and their charecter equivalent
   {
        printf("%d\t%.3o\t%.2X\tNon Printable\n",i,i,i);
   }   
   for (int i = 33 ; i <= 127 ; i++) //printing remaining dec, oct, hex and charecter equivalent 
   {    
       if(i != 127)
           printf("%d\t%.3o\t%.2X\t%c\n",i,i,i,i);
       else
           printf("%d\t%.3o\t%.2X\tNon Printable\n",i,i,i);
   }
   return 0; //end of main function
}

