/*
 *Name         : Madhusudan Rathi
 *Date         : 11/09/2020
 *Description  : read_int function which exactly behave like scanf("%d",%i);
 *Ex. Input and Ex. output   : 
 Enter a neumeric string : 123     
 The Entered number is  123
 Do you want to continue yY/nN : y
 Enter a neumeric string : -123
 The Entered number is  -123
 Do you want to continue yY/nN : y
 Enter a neumeric string : +123
 The Entered number is  123
 Do you want to continue yY/nN : y
 Enter a neumeric string : as123
 The Entered number is  0

 */
#include<stdio.h>
#include<math.h>
#include<ctype.h>
int read_int(char *str);
int main()                                                                 //start of main function
{
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    {
        char str[20];                                                      //variable declaration
        int number = 0;
        printf("Enter a neumeric string : ");                              //asking user for input
        scanf("%20[^\n]",str);
        number = read_int(str);                                            //function call
        printf("The Entered number is  %d\n",number);
        getchar();                                                         //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                        //Asking user for continuation option
        scanf("%c",&ch);                                                   //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                        //Validating users response for continuation
    return 0;                                                              //End of main function
}

int read_int(char *str)                                                    //function defination
{
    int num = 0,i = 0,count=0,sign=1;                                       //variable declaration
    char temp = *str;
    while(str[i] != '\0')                                                   //while loop run till end of loop
    {
        if(isdigit(str[i]))                                                 //logic for converting it into string
        {
            num = (num * 10) + (str[i] - '0');
            i++;
        }
        else if(str[i] == 45)                                               //chaecking signness of string
        {
            count++; 
            if(i > 3)
                sign = 1;
            if(count == 1)
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
    return num*sign;                                                    //returning a value
}

