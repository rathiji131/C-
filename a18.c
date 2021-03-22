/*
 *Name         : Madhusudan Rathi
 *Date         : 11/09/2020
 *Description  : To find the average of n numbers by taking input in 3 diferent ways.
 *Ex. Input and Ex output : 
 export array="1 2 3 4 5 6 7 8 9"
 ./a.out 1 2 3 4 5
 Select method to calculate average : 
 1.Scan from keyboard
 2.Proceed with environment variable argument
 3.Proceed with provided comand line argument
 Enter your choice : 1
 Enter total number of integers : 8
 Enter the elements : 1 2 3 4 5 6 7 8
 The average of entered number is 4.5
 Do you want to continue yY/nN : y
 Select method to calculate average : 
 1.Scan from keyboard
 2.Proceed with environment variable argument
 3.Proceed with provided comand line argument
 Enter your choice : 2
 The average of entered number is 5
 Do you want to continue yY/nN : y
 Select method to calculate average : 
 1.Scan from keyboard
 2.Proceed with environment variable argument
 3.Proceed with provided comand line argument
 Enter your choice : 3
 The average of entered number is 3
 Do you want to continue yY/nN : 
 */
#include<stdio.h>                                                          //preprocessor directives
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int my_atoi(char *str);                                                    //function prototype
int main(int argc , char *argv[])                                          //start of main function
{
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    {
        int choice,n,sum = 0;                                               //variable declaration
        float avg = 0 ;
        printf("Select method to calculate average : \n1.Scan from keyboard\n2.Proceed with environment variable argument\n3.Proceed with provided comand line argument\nEnter your choice : ");
        scanf("%d",&choice);                                                //taking users choice
        switch(choice)                                                      //execute according to choice
        {
            case 1:                                                         //normal user input 
                {
                    printf("Enter total number of integers : ");
                    scanf("%d",&n);
                    int arr[n];
                    printf("Enter the elements : ");
                    for(int i = 0 ; i < n ; i++)                            //logic for avg of numbers 
                    {
                        scanf("%d", &arr[i]);
                        sum = sum + arr[i];
                    }
                    avg = sum /(float) n;
                    printf("The average of entered number is %g\n",avg);    //printing the avg 
                    break;
                }
            case 2:                                                         //geting input from environment variable
                {
                    int count = 0;
                    if(getenv("array"))
                    {
                        char *ptr = getenv("array");
                        char *token = strtok(ptr," ");
                        while(token != NULL)                                    //calculating avg of environment variable
                        {
                            count++;
                            sum = sum + my_atoi(token);
                            token = strtok(NULL," ");
                        }
                        avg = sum /(float) count;
                        printf("The average of entered number is %g\n",avg);
                    }
                    else
                        printf("No such environment variable!!\n");
                    break;
                }
            case 3:
                {
                    if(argc > 1)
                    {
                        for (int i = 0 ; i < argc ; i++)                        //calculating avg from command line arg
                        {
                            sum = sum + atoi(argv[i]);
                        }
                        avg = (float)sum/(argc-1);
                        printf("The average of entered number is %g\n",avg);
                    }
                    else
                        printf("No command line arguments!!\n");
                    break;
                }
            default:
                printf("Please enter correct choice!!");
        }
        getchar();                                                         //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                        //Asking user for continuation option
        scanf("%c",&ch);                                                   //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                        //Validating users response for continuation
    return 0;                                                              //End of main function
}

int my_atoi(char *str)                                                     //logic  or defination of atoi() function
{
    int num = 0,i = 0;          
    while(str[i] != '\0')                                                  //convert ascii to integer
    {
        if(isdigit(str[i]))
        {
            num = (num * 10) + (str[i] - '0');
            i++;
        }
    }
    return num;
}

