/*
    *Name         : Madhusudan Rathi
    *Date         : 16/08/2020
    *Description  : Print prime number till given numer
    *Ex. Input    : 25
    *Ex. output   : 2 3 5 7 11 13 17 19 23
*/
#include<stdio.h>
#include<math.h>
int main()                                                                 //start of main function
{   
    int num,temp = 0;    
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    {
        printf("Enter value of num : ");                                  //Asking user a number till which user want to print prime number
        scanf("%d",&num);                                                 //storing it in num
        int arr[num],k = 1;                                               //Declaration of array
        for(int i = 0 ; i < num ;i++)                                     //start of for loop
            arr[i] = k++;                                                 //storing numbers from 1 to num
        if(num >= 2)                                                      //checking condition num is > 2
        {
            if(num < pow(2,20))                                           //checking condition provided
            {
                for(int i = 3 ; i < num ; i++)                           //the number which are not prime are replaced with zero
                    for(int j = 2 ; j < i ;j++)
                        if(arr[i] % j == 0)
                        {
                            arr[i] = 0;
                            break;
                        }
            printf("Prime numbers : ");                                  //printing prime numbers
            for(int i = 1 ; i < num ;i++)
                if(arr[i] != 0)
                    printf("%d ",arr[i]);
            }
            else
                printf("Number out of range.\n");                        //if given number is out of range, printd this sms
        }
        else
            printf("Invalid input.\n");                                  //validaring given condition
        getchar();                                                       //Gets single charecter from std input device
        printf("\nDo you want to continue yY/nN : ");                    //Asking user for continuation option
        scanf("%c",&ch);                                                 //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                      //Validating users response for continuation
    return 0;                                                            //End of main function
}


