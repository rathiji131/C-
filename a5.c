/*
    *Name         : Madhusudan Rathi
    *Date         : 06/08/2020
    *Description  : Print size of all basic data types
    *Ex. Input    : No input
    *Ex. output   : size of int     : 4 bytes
*/


# include <stdio.h>                 // Preprocessor directives

int main()                          // main function
{                                   // printing size of datatypes
    printf("Size of int            : %zu  bytes\n",sizeof(int));
    printf("Size of float          : %zu  bytes\n",sizeof(float));
    printf("Size of char           : %zu  bytes\n",sizeof(char));
    printf("Size of double         : %zu  bytes\n",sizeof(double));
    printf("Size of short int      : %zu  bytes\n",sizeof(short int));
    printf("Size of long int       : %zu  bytes\n",sizeof(long int));
    printf("Size of long double    : %zu bytes\n",sizeof(long double));
    printf("Size of long long int  : %zu  bytes\n",sizeof(long long int));
    printf("Size of unsigned int   : %zu  bytes\n",sizeof(unsigned int));
    printf("Size of unsigned char  : %zu  bytes\n",sizeof(unsigned char));
    printf("Size of signed int     : %zu  bytes\n",sizeof(signed int));
    printf("Size of signed char    : %zu  bytes\n",sizeof(signed char));
    printf("Size of void           : %zu  bytes\n",sizeof(void));
    
    return 0; //end of main function
}

