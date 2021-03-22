/*
 *Name         : Madhusudan Rathi
 *Date         : 01/09/2020
 *Description  : Implement getword,atoi,itoa function
 *Ex. Input    : 1.Getword
 2.atoi
 3.itoa
 Enter your choice : 1
 Enter a string : madhusudan rathi
 *Ex. output   : madhusudan
 */
#include<stdio.h>                                                           //Preprocessor directives
#include<string.h>
#include<ctype.h>
int my_getword(char *);                                                     //function prototype
int my_atoi(char *);
int my_itoa(int ,char *);
int main()                                                                 //start of main function
{
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    {
        int choice;
        printf("1.Getword\n2.atoi\n3.itoa\n");                              //printing menu
        printf("Enter your choice : ");
        scanf("%d",&choice);                                                //taking choice for function
        getchar();
        switch(choice)                                                      //to execute according to choice
        {
            case 1 :                                                        //case 1 is for getword function
                {
                    char str[20];
                    printf("Enter a string : ");
                    scanf("%20[^\n]",str);
                    my_getword(str);
                    break;
                }
            case 2 :                                                        //case 2 is for atoi function
                {
                    char str[20];
                    int number = 0;
                    printf("Enter a neumeric string : ");
                    scanf("%20[^\n]",str);
                    number = my_atoi(str);
                    printf("String to integer %d\n",number);
                    break;
                }
            case 3 :                                                        //case 3 is itoa function
                {
                    char str[20];
                    int n,len = 0;
                    printf("Enter a number : ");
                    scanf("%d",&n);
                    len = my_itoa(n,str);
                    printf("Integer to string : %s\n",str);
                    break;
                }
            default :
                printf("Please enter correct choice!!\n");
        }

        getchar();                                                         //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                              //Asking user for continuation option
        scanf("%c",&ch);                                                   //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                                       //Validating users response for continuation
    return 0;                                                              //End of main function

}

int my_getword(char *str)                                                   //logic for getword function
{
    int len = 0;
    char *temp = str;
    while(*str++ != ' ' && *str != '\0')
    {
        len++;
    }
    *str = '\0';
    printf("%s \n",temp);
    return len;
}

int my_atoi(char *str)                                          //logic  or defination of atoi() function
{
    int num = 0,i = 0,count=0,sign;
    char temp = *str;

    while(str[i] != '\0')
    {
        if(isdigit(str[i]))
        {
            num = (num * 10) + (str[i] - '0');
            i++;
        }
        else if(str[i] == 45)
        {
            count++;
            if (count == 1)
            {
                sign = -1;
                i++;
            }
            else 
                return 0;
        }
        else if(str[i] == 43)
        {
            count++;
            if(count == 1)
            {
                sign = 1;
                i++;
            }
            else
                return 0;
        }
        else
            break;
    }
    if(str[i-1] == 45)
        sign = 1;
    return num*sign;
}

int my_itoa(int n,char *s)                                          //logic or defination of itoa function 
{
    int rem = 0,len = 0,i = 1;
    char *temp = s;
    while(n > 0)
    {
        rem = (n % 10)+ 48;
        s[i] = rem ;
        n = n / 10;
        i++;
        len++;
    }
    s[i] = '\0';
    char s1[100];
    int j;
    for(j = 0,i=0; j <= len-1; j++,i++)
    {
        s1[j] = s[len-i];
    }
    s1[j] = '\0';
    printf("Integer to string : %s\n",s1);
    return len;
}


