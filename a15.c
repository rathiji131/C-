/*
    *Name         : Madhusudan Rathi
    *Date         : 28/08/2020
    *Description  : replace b-a+1 bits from position b of number by last b-a+1 bits of another number 
    *Ex. Input    : Enter the value of 'n' : 11
    *Ex. Input    : Enter the value of 'i' : 174
    *Ex. Input    : Enter the value of 'a' : 3
    *Ex. Input    : Enter the value of 'b' : 5
    *Ex. Input    : Enter the value of 'n' : 00000000000000000000000000001011
    *Ex. Output   : The binary form of 'i' : 00000000000000000000000010101110
                  : The new binary form of 'i' : 0000000000000000000000010011110 
*/
#include<stdio.h>                                                          //Preprocessor directives
int binary(int n);                                                         //function prototype
int set_nbits_from_pos(int ,int ,int ,int);                                
int get_nbits(int ,int);
int main()                                                                 //start of main function
{
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    {
        int n,i,a,b,res;                                                   //variable declaration
        printf("Enter the value of 'n' : ");                                //asking user for input and storing it in variables
        scanf("%d",&n);    
        printf("Enter the value of 'i' : ");
        scanf("%d",&i);    
        printf("Enter the value of 'a' : ");
        scanf("%d",&a);    
        printf("Enter the value of 'b' : ");
        scanf("%d",&b);    
        printf("The binary form of 'n' : ");
        binary(n);
        printf("New binary form of 'i' : ");
        binary(i);
        if( a > 0 && a<31 && b > a && b < 31)                             //validating condition
        {
             res = set_nbits_from_pos(i,b-a+1,b,n);                       //calling function
             printf("The new binary of 'i'  : ");
             binary(res);
        }
        else
        {
            printf("Value of a or b is out of range.\nIt should be between 0 to 31.\n ");
        }
        getchar();                                                         //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                        //Asking user for continuation option
        scanf("%c",&ch);                                                   //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                        //Validating users response for continuation
    return 0;                                                              //End of main function

}

int binary(int n)
{
            for(int i = 0 ; i < 8 * sizeof(n) ; i++)                         //for loop of sizeof(num)
            {   
                printf("%d",n & 0x80000000 ? 1 : 0) ;                        //checking MSB , if 1 --> print 1 else --> 0
                n = n << 1;                                                  //left shift num by 1
            }
            printf("\n");
            return 0;
}

int set_nbits_from_pos(int i ,int t ,int b ,int n)
{
   return ((i & ( ~0 << (b+1) | (1 << (b-t+1))-1)) | (get_nbits(n,t)) << (b-t+1)); 
}

int get_nbits(int num,int n)
{
    return ((1 << n) -1) & num ;
}
