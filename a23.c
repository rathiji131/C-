/*
 *Name         : Madhusudan Rathi
 *Date         : 11/09/2020
 *Description  : Removing extra spaces 
 *Ex. Input    : Enter text with spaces : Hi     Arun        Sir     How      are    you
 *Ex. output   : Hi Arun Sir How are you
 */
#include<stdio.h>                                                         //preprocessor directives
#include<stdlib.h>
int removed_space(char *str);
int main()                                                                //start of main function
{
    char ch;                                                              //Declaration of variables
    do                                                                    //Start of do while loop
    {
        char str[200];                                                    //string declaraion
        printf("Enter text with spaces : ");                              //taking string from user
        scanf("%[^\n]",str);
        removed_space(str);                                                //function call for removing spaces
        getchar();                                                         //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                        //Asking user for continuation option
        scanf("%c",&ch);                                                   //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                        //Validating users response for continuation
    return 0;                                                              //End of main function
}

int removed_space(char *str)                                                //function defination
{
    char *rep_str = malloc(200);                                            //another sting variable declaration
    int i = 0, j = 0;
    while (str[i] != '\0')                                                  //loop still end of string i.e null
    {
        if (!(str[i] == ' ' && str[i+1] == ' '))                            //logic for replacing extra spaces
        {
            rep_str[j] = str[i];
            j++;
        }
        i++;
    }
    rep_str[j] = '\0';
    printf("String  after removing blanks is : %s\n", rep_str);            //printing string without extra spaces
}
