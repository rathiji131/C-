/*
 *Name         : Madhusudan Rathi
 *Date         : 11/09/2020
 *Description  : Print bits of folat and double
 *Ex. Input    : Enter the choice : 
 1.float
 2.double
Choice : 1
Enter value : 2.3
 *Ex. output   : 
 Sign	Exponent	Mentissa
 0	    10000000	00100110011001100110011
 */
#include<stdio.h>                                                           //Preprocessor directives
int print_bit_float(int num, int i)                                         //print bit float defination
{
    int ret = num & (1 << i);

    if (ret == 0) 
        return 0;
    else 
        return 1; 
}
int print_bit_double(long int num, int i)                                   //print bit double defination
{
    int ret = num & (1 << i);

    if (ret == 0) 
        return 0;
    else 
        return 1; 
}
int main()                                                                 //start of main function
{
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    {
        float num;                                                          //variable declaration 
        int *iptr,choice;
        printf("Enter the choice : \n1. Float\n2. Double\nChoice : ");      //printing menu and asking for choice
        scanf("%d",&choice);
        switch(choice)                                                      //switch for float and double according to choice
        {
            case 1:                                                         //case 1 is for float
                {
                    printf("Enter value : ");                               //asking for input and storing it 
                    scanf("%f",&num);
                    iptr = &num;                                            //give addrss to pointer
                    printf("Sign\tExponent\tMentissa\n");
                    for (int i = 31; i >= 0; i--)                           //float is 4 bytes so that loop for 32 times
                    {
                        if(i == 31 || i == 23)
                            printf("%d\t",print_bit_float(*iptr,i));        //function call
                        else
                            printf("%d",print_bit_float(*iptr,i));          //function call
                    }
                    break;                                                  //break statement
                }
            case 2 :
                {
                    double  num;                                            //variable declaration
                    printf("Enter double value : ");                        //asking user for number
                    scanf("%lf",&num);
                    long int *iptr;
                    iptr =  &num;
                    printf("Sign\tExponent\tMentissa\n");
                    for (int i = 61; i >= 0; i--)                           //64 times because of size of double is 8 bytes
                    {
                        if(i == 61 || i == 50)
                            printf("%d\t",print_bit_double(*iptr,i));       //function call
                        else
                            printf("%d",print_bit_double(*iptr,i));         //function call
                    }
                    break;
                }
            default :
                printf("Enter valid choice!!");
        }
        getchar();                                                         //Gets single charecter from std input device
        printf("\nDo you want to continue yY/nN : ");                              //Asking user for continuation option
        scanf("%c",&ch);                                                   //taking users input in char variable    
    }while(ch == 'y' || ch == 'Y');                                                       //Validating users response for continuation
    return 0;                                                              //End of main function
}


