/*
    *Name         : Madhusudan Rathi
    *Date         : 23/08/2020
    *Description  : Swapping of two numbers without using 3rd variable
    *Ex. Input    : Enter N1 : 12
                    Enter N2 : 34 
    *Ex. output   : After swapping.
                    N1 = 34
                    n2 = 12
*/
#include<stdio.h>
void swap(int *,int *);
int main()                                                          //start of main function
{
    char ch;                                                        //Declaration of variables
    do                                                              //Start of do while loop
    {
        int num1,num2;                                              //variable declaration                                            
        int *ptr1,*ptr2;                                                
        printf("Enter N1 : ");                                      //asking user for input
        scanf("%d",&num1);                                          //storing it in variable
        printf("Enter N2 : ");
        scanf("%d",&num2);
        ptr1 = &num1;                                               //giving address of variable to pointer variable
        ptr2 = &num2;
        swap(ptr1,ptr2);                                            //calling function
        printf("After swapping.\n");
        printf("N1 = %d\n", *ptr1);                                 //After swapping printing numbers
        printf("N2 = %d\n", *ptr2);
        getchar();                                                   //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                  //Asking user for continuation option
        scanf("%c",&ch);                                             //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                  //Validating users response for continuation
    return 0;                                                        //End of main function

}

void swap(int *ptr1,int *ptr2)                                      //defination of swap function
{
    int sum = 0;                                                    //variable declaration
    *ptr1 = *ptr1 + *ptr2;                                          //logic of swapping without temp variable
    *ptr2 = *ptr1 - *ptr2;
    *ptr1 = *ptr1 - *ptr2;
}
