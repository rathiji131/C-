/*
    *Name         : Madhusudan Rathi
    *Date         : 01/01/2020
    *Description  : Alternative version of squeeze(s1,s2) that deletes each charecter in s1 that matches any vcharecter in s2
    *Ex. Input    : Enter first string  : Madhusudan rathi
                    Enter second string : aui
    *Ex. output   : mdhsdn rth
*/
#include<stdio.h>
#include<stdio_ext.h>
void my_squeeze(char str1[20],char str2[20]);
int main()                                                                 //start of main function
{
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    {
        char str1[20],str2[20];                                             //variable declaration
        printf("Enter first string : ");                                    //asking user input
        scanf("%20[^\n]",str1);                                             //storing it in varible
        __fpurge(stdin);                                                    //clearing buffer
        printf("Enter second string : ");                                   //asking user 2nd input
        scanf("%20[^\n]",str2);                                             //storing it in another variable
        my_squeeze(str1,str2);                                              //function call squeeze
        getchar();                                                          //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                         //Asking user for continuation option
        scanf("%c",&ch);                                                    //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                         //Validating users response for continuation
    return 0;                                                               //End of main function

}

void my_squeeze(char str1[20],char str2[20])                                //function defination
{                                                                           //logic for squeezing 
    int i = 0 , j = 0 , k = 0 ;
    while(str2[k] != '\0')
    {
        for(i = j = 0; str1[i] != '\0' ; i++)
        {
            if(str2[k]  != str1[i])
            {
                str1[j++] = str1[i] ;
            }    
        }
        k++;
        str1[j] = '\0';
    }
    printf("After Squeez s1 : %s\n",str1);                                  //printing after squeezing string
}

