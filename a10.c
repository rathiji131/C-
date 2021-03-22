/*
    *Name         : Madhusudan Rathi
    *Date         : 08/08/2020
    *Description  : Given the number from 1 to 365,WAP to find which day of the year
    *Ex. Input    : Enter value of 'n' : 9
                    choose First day:
                    1. Sunday
                    2. Monday
                    3. Thesday
                    4. Wednesday
                    5. Thursday
                    6. Friday
                    7. Saturday
                    Enter the option to set the first day : 2

    *Ex. output   :The 9th day is Tuesday. 
*/
#include <stdio.h>                                               //preprocessor directives
int main()                                                       //start of main function
{
    int n_th_day,remainder,first_day;                            //declaration of variables
    char ch;
    do                                                           //start of do while loop
    {
        printf("Enter the value of 'n' : ");                     // asking user to nth day of year
        scanf("%d",&n_th_day);                                   //storing users response
        printf("Choose first day : \n1. Sunday\n2. Monday\n3. Thesday\n4. Wednesday\n5. Thursday\n6. Friday\n7. Saturday\n");                               //printing options for selection of first day
        printf("Enter the option to set the first day : ");
        scanf("%d",&first_day);                                  //taking first day of year from user
        if(first_day <= 7 && n_th_day <= 365)                    //validating conditions
            switch(remainder = (n_th_day % 8 + first_day) % 7)   //using condition in switch case finding the day of n_th_day 
            {
                case 1:
                {   
                    printf("The %dth is Sunday\n",n_th_day);
                    break;
                }
                case 2:
                {
                    printf("The %dth is Monday\n",n_th_day);
                    break;
                }
         
                case 3:
                {
                    printf("The %dth is Tuesday\n", n_th_day);
                    break;
                }
                case 4:
                {
                    printf("The %dth is Wednesday\n",n_th_day);
                    break;
                }
                case 5:
                {
                    printf("The %dth is Thursday\n",n_th_day);
                    break;
                }
                case 6:
                {
                    printf("The %dth is Friday\n",n_th_day);
                    break;
                }
                case 0:
                {
                    printf("The %dth is Saturday\n",n_th_day);
                    break;
                }
        }
        else
            printf("Invalid Input\n");                               //If invalid inputs prints this sms
        getchar();                                                   //reads a single charecter from std input stream               
        printf("Do u want to continue : ");                          //asking user for continuaion of program               
        scanf("%c",&ch);                                             //storing users response   
        getchar();
        }while(ch=='y');                                             //checking users reponse for continuation if yes again go to start of do
    return 0;                                                        //end of main function
}


