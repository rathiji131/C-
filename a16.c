/*
    *Name         : Madhusudan Rathi
    *Date         : 16/08/2020
    *Description  : Shift the given number by given number of bits
    *Ex. Input    : Enter a number : 12
                    Enter number of bits to be shifted : 2
                    1 .Right shift
                    2 .Left shift 
                    Choose your option : 1
    *Ex. output   : i/p    -> 00000000000000000000000000001100
                    o/p    -> 00000000000000000000000000000011   
     
*/
#include<stdio.h>
int main()                                                                 //start of main function
{
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    {
        int bits,op,temp,pbit,temp1;                                       //Declaration of variables
        int num,flag = 0;
        printf("Enter a number : " );                                     //taking input from user
        scanf("%d",&num);  
        printf("Enter number of bits to be shifted : ");                  //Number of bits to be shifted
        scanf("%d",&bits);
        printf("1 .Right Shift\n2 .Left Shift\nChoose your option : ");   //menufor shifting
        scanf("%d",&op);                                                  //taking input in variable
        temp1=num;                                                        //storing num in temp
        printf("%d\t-> ",num);
        for(int i = 0 ; i <= 31 ; i++)                                    //printing given number in binary
        {
            if(num & 0x80000000)
                 printf("1");
            else         
                printf("0");
            num = num << 1;
        }                
        switch(op)                                                          //Start of switch case
        {
            case 1 :                                                        //case 1 is for right shift
                {
                    num = temp1;
                    flag = 1;
                    for(int i = 1 ; i <= bits ; i++)
                    {
                        temp = num & 0x00000001;
                        num = num >> 1;
                        if(temp)
                            num = num | 0x80000000;
                        else
                            num = num & 0x7FFFFFFF;
                        temp = 0;
                    }
                    break;
                }
            case 2 : 
                {
                    num = temp1;                                            //case 2 is for left shift
                    flag = 1; 
                    for(int i = 1 ; i <= bits ; i++)
                    {
                        temp = num & 0x80000000;
                        num = num << 1;
                        if(temp)
                            num = num | 0x00000001;
                        else
                            num = num & 0xFFFFFFFE;                   
                        temp = 0;
                    }
                    break;
                }
            default :                                                       //if none of the case default will be executed
                {
                    printf("\nEnter correct choice.");
                }
        }
        if(flag == 1)                                               
        {
            printf("\no/p\t-> ");                                           //printing shifted number in binary
            for(int i = 1 ; i <= 32 ; i++)
            {
                if(num & 0x80000000)
                    printf("1");
                else
                    printf("0");
                num = num << 1; 
            }
        }
        getchar();                                                             //Gets single charecter from std input device
        printf("\nDo you want to continue : ");                                  //Asking user for continuation option
        scanf("%c",&ch);                                                       //taking users input in char variable    
        getchar();
    }while(ch=='y');                                                       //Validating users response for continuation
    return 0;                                                              //End of main function
}


