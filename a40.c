/*
 *Name         : Madhusudan Rathi
 *Date         : 1/09/2020
 *Description  : Reverse string using recursive and  non recursive function
 *Ex. Input    : Enter a string : Madhu rathi
 *Ex. output   : Recursion reverse string is : ihtar uhdam
                 Non recursion reverse string is : ihtar uhdam
 */
#include<stdio.h>
void my_reverse_recursion(char *str);                                      //function prototype
void my_reverse_non_recursion(char *str);
int main()                                                                 //start of main function
{
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    {
        char str[20];                                                      //variable declaration
        printf("Enter a string : ");                                       //asking user for string input
        scanf("%20[^\n]",str);                                             //storing it in str
        printf("recursion reverse string is : ");
        my_reverse_recursion(str);                                         //calling recursive function
        my_reverse_non_recursion(str);                                     //calling non recursive function
        getchar();                                                         //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                        //Asking user for continuation option
        scanf("%c",&ch);                                                   //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                        //Validating users response for continuation
    return 0;                                                              //End of main function
}

void my_reverse_recursion(char *str)                                       //recursive function defination
{
    if(*str)
        my_reverse_recursion(str+1);
    printf("%c",*str);
}
void my_reverse_non_recursion(char *str)                                   //non recursive function defination
{
    int len = 0,i = 0;
    char *str1,temp;
    str1 = str;
    while(*str1)
    {  
        len++;
        str1++;
    }
    len = len -1 ;
    while(i < len)
    {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        i++;
        len--;
    }
    printf("\nNon recursion reverse string is : %s\n",str);
}
