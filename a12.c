/*
    *Name         : Madhusudan Rathi
    *Date         : 11/08/2020
    *Description  : To print bits of signed and unsigned types of given number check for 2's compliment. 
    *Ex. Input    : Enter a number : 12
    *Ex. output   : 12 -> 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0
                   -12 -> 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 0 0
 */
#include<stdio.h>
int main()                                                 //start of main function
{
    char ch;                                               //Declaration of variables
    int num,temp,op;
    do                                                     //Start of do while loop
    {   
        printf("Enter a number : ");                       //Taking input from user                           
        scanf("%d",&num);                                  //Storing users response 
        temp=num;                                          //copying  num to temp
        op=0;                                              //initialing op to 0
        do                                                 //Start of do while loop
        { 
            printf("\n%d\t-> ",num);                       
            for(int i = 0 ; i < 8 * sizeof(num) ; i++)          //for loop of sizeof(num)
            {
                if(num & 0x80000000)                       //checking MSB , if 1 --> print 1 else --> 0
                    printf("%d ",1);
                else            
                    printf("%d ",0);
                num = num << 1;                            //left shift num by 1
            }
            num=-temp;                                     //Storing negation of number
            op++;                                          //increment op 
        }while(op == 1);                                   //if op==1 then goto do else come out of loop
        getchar();                                         //get single charecter as input from std input device
        printf("\nDo you want to continue yY/nN : ");      //Asking user for continuation option
        scanf("%c",&ch);                                   //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                        //Validating users response for continuation
    return 0;                                              //End of main function
}


