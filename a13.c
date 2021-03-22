/*
    *Name         : Madhusudan Rathi
    *Date         : 26/08/2020
    *Description  : implement own c-type library
    *Ex. Input    : Enter a charecter : a
                    Select any option :
                    1 - isalpha
                    2 - isalnum
                    3 - isascii
                    4 - isblank
                    Enter your choice : 4
    *Ex. output   : The charecter '4' is not blank.
*/
#include<stdio.h>
void isalpha1(char);                                                       //function prototypes
void isalnum1(char);
void isascii1(char);
void isblank1(char);
int main()                                                                 //start of main function
{
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    {
        char charecter;                                                    //variable declaration
        int choice;
        printf("Enter a charecter : ");                                    //asking use for input
        scanf("%c",&charecter);                                            //storing it in variable
        printf("1 - isalpha\n2 - isalnum\n3 - isascii\n4 - isblank\nSelect any option : ");//printing menu for operation
        scanf("%d",&choice);                                               //storing choice
        switch(choice)                                                     //start of switch case
        {
           case 1 :                                                        //case 1 is for checking isalpha1 
                {
                    isalpha1(charecter);                                   //calling isalpha1 function
                    break;                                                 //breaking else will execute till next break
                }
            case 2 :                                                       //case 2 is for checking number
                {
                    isalnum1(charecter);                                   //calling isalnum1 function
                    break;                                                 //breaking
                
                } 
            case 3 :                                                       //case 3 is for checking ascii or not 
                {
                    isascii1(charecter);                                   //calling isascii1 function
                    break;                                                 //breaking
                
                }
            case 4 :                                                       //case 4 is checking blank or not 
                {
                    isblank1(charecter);                                   //calling isblank1 function
                    break;                                                 //breaking
                }
            default :                                                      //if none case executed then default will execute
                {
                    printf("Enter correct charecter.");
                }
        }
        getchar();                                                         //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                        //Asking user for continuation option
        scanf("%c",&ch);                                                   //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                        //Validating users response for continuation
    return 0;                                                              //End of main function

}

void isalpha1(char ch)                                                     //function to check entered charecter is alphabet or not
{
    switch(ch)
    {
       case 'a'...'z':
       {
            printf("The charecter %c is alpha charecter.\n",ch);
            break;
       } 
       case 'A'...'Z' :
       {
            printf("The charecter %c is alpha charecter.\n",ch);
            break;
       } 
        default : 
       {
            printf("The charecter %c is not alpha charecter.\n",ch);
            break;
       }
    }
}

void isalnum1(char ch)                                                    //function to check enterd charecter is number/alphabet or not  
{
    switch(ch)
    {
       case '0'...'9':
       {
            printf("The charecter %c is alnum charecter.\n",ch);
            break;
       } 
       case 'a'...'z':
       {
            printf("The charecter %c is alnum charecter.\n",ch);
            break;
       } 
       case 'A'...'Z' :
       {
            printf("The charecter %c is alnum charecter.\n",ch);
            break;
       } 
        default : 
       {
            printf("The charecter %c is not alnum charecter.\n",ch);
            break;
       }
    }
}
void isascii1(char ch)                                                  //function to check entered charecter is ascii or not
{
    if(ch >= 0 && ch <=127)
        printf("The charecter %c is ascii charecter.\n",ch);
    else
        printf("The charecter is not ascii charecter.\n");
}
void isblank1(char ch)                                                  //function to check entered charecter is blank or not
{
    if(ch == 9 || ch == 32)
        printf("The charecter is blank charecter.\n");
    else
        printf("The charecter is not blank charecter.\n");

}
