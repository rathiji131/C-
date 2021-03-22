/*
 *Name         : Madhusudan Rathi.
 *Date         : 06/09/2020.
 *Description  : Implement wc function of linux in c.
 *Ex. Input    : Madhu rathi
                 Arun sir
                 Nithya  mam
 *Ex. output   : Charecter count : 32
                 Line count      : 3
                 Word Count      : 6
 */
#include<stdio.h>                                                           //preprocessor directives
#include<string.h>
#include<stdio_ext.h>
void wc(char *str);                                                         //function prototype
int main()                                                                  //start of main function
{
    char ch;                                                                //Declaration of variables
    do                                                                      //Start of do while loop
    {
        int i = 0;                                                          //variable declaration
        char str[100],ch1;
        printf("Enter a string : ");                                        //asking user for input 
        while(( ch1 = getchar()) != EOF)                                    //storing it in string
        {
            str[i]=ch1;
            i++;
        }
        str[i]='\0';
        wc(str);                                                            //function call 
        getchar();                                                          //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                         //Asking user for continuation option
        scanf("%c",&ch);                                                    //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                         //Validating users response for continuation
    return 0;                                                               //End of main function
}
void wc(char *str)                                                          //function defination
{
    int line = 0,word = 0,ch = 0;                                           //variable declaration
    char prev;
    while(*str)                                                             //logic for word line and charecter count
    {
        ch++; 
        if (*str=='\n') 
            line++; 
        if ((*str==' ' && prev!=' ') || (*str=='\n' && prev!='\n')) 
            word++; 
        prev=*str;
        str++;
    }
    printf("\ncharecter count : %d\nline count      : %d\nword count      : %d",ch,line,word);
}

