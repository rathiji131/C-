/*
 *Name         : Madhusudan Rathi
 *Date         : 11/08/2020
 *Description  : To check endianess of system 
 *Ex. Input    : Enter a number : 1234
 *Ex. output   : Your system is litte endian
 */
#include<stdio.h>
#include<math.h>
int endianess(int n);
int main()                                                                  //start of main function
{
    char ch1;                                                               //Declaration of variables
    do                                                                      //Start of do while loop
    {
        signed int n,ch;                                                    //variable declaration
        printf("Enter a number : ");                                        //asking user for input
        scanf("%d",&n);                                                     //storing it in variable
        ch =(((1 << 8)-1) & n);                                             //taking lsb bits of number
        if(ch ==  endianess(n))                                             //checking condition for endianess 
            printf("Your system little endian\n");
        else
            printf("Your system is big endian\n");  
        getchar();                                                          //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                         //Asking user for continuation option
        scanf("%c",&ch1);                                                   //taking users input in char variable    
        getchar();
    }while(ch1 == 'y' || ch1 == 'Y');                                        //Validating users response for continuation
    return 0;                                                                //End of main function
}
int endianess(int n)                                                        //definataioin of endianess function
{
    return n & 0xff; 
}
