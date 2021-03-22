/*
 *Name         : Madhusudan Rathi
 *Date         : 11/09/2020
 *Description  : Calculating size of different datatypes using MACRO
 *Ex. Input    : No input
 *Ex. output   : Size of int           : 4
                 Size of char          : 1
                 Size of float         : 4
                 Size of double        : 8
                 Size of unsigned int  : 4
                 Size of long int      : 8
 */
#include<stdlib.h>
#include<stdio.h>
#define SIZEOF(ptr) ((char *)(ptr+1)-(char *)ptr)                       //defined MACRO for sizeof operator
int main()                                                              //start of main function
{
    int i;                                                              //variable declaration
    float f;
    char ch;
    double d;
    unsigned int ui;
    long int li;

    printf("Size of int           : %zu\n",SIZEOF(&i));                 //calculating size of different datatypes using macro
    printf("Size of char          : %zu\n",SIZEOF(&ch));
    printf("Size of float         : %zu\n",SIZEOF(&f));
    printf("Size of double        : %zu\n",SIZEOF(&d));
    printf("Size of unsigned int  : %zu\n",SIZEOF(&ui));
    printf("Size of long int      : %zu\n",SIZEOF(&li));
    return 0;
}


