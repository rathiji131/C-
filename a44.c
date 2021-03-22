/*
 *Name         : Madhusudan Rathi
 *Date         : 11/09/2020
 *Description  : Calculate the mean of given array of any datatype
 *Ex. Input    : 
 1.Int
 2.Short
 3.Float
 4.Double
 Enter choice : 1
 Enter number of elememts : 5
 [0] -> 10
 [1] -> 20
 [2] -> 30
 [3] -> 40
 [4] -> 50
 *Ex. output   : Mean of given int numbers is 30
 */

#include<stdio.h>
#include<stdlib.h>
float _mean_(void *vptr , int size,int choice);
int main()                                                                 //start of main function
{
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    {
        int choice , size;
        printf("1.Int\n2.Short\n3.Float\n4.Double\nEnter choice : ");     //printing menu
        scanf("%d",&choice);                                                //storing users choice
        printf("Enter number of elememts : ");                              //asking for number of elememts
        scanf("%d",&size);                                                  //storing it in size variable
        void *ptr;                                                         //declaring pointer
        switch(choice)                                                      //switch case to take data of different datatype
        {
            case 1:                                                         //case is for integer
                {
                    ptr = malloc(size*4);
                    float mean = 0;
                    for(int i = 0 ; i < size ; i++)                         //taking input array
                    {
                        printf("[%d] -> ",i);
                        scanf("%d",((int *)ptr + i));
                    }
                    mean = _mean_(ptr,size,1);                              //function call
                    printf("Mean of given int numbers is %g",mean);         //printing mean of given array
                    break;                                                  //breaking statement
                }
            case 2:                                                         //for short datatype
                {
                    ptr = malloc(size*2);
                    float mean = 0;
                    for(int i = 0 ; i < size ; i++)
                    {
                        printf("[%d] -> ",i);
                        scanf("%hd",((short *)ptr + i));
                    }
                    mean = _mean_(ptr,size,2);
                    printf("Mean of given short numbers is %g",mean);
                    break;
                }
            case 3:                                                         //for float datatype
                {
                    ptr = malloc(size*4);
                    float mean = 0;
                    for(int i = 0 ; i < size ; i++)
                    {
                        printf("[%d] -> ",i);
                        scanf("%f",(float *)ptr+i);
                    }
                    mean = _mean_(ptr,size,3);
                    printf("Mean of given float numbers is %g",mean);
                    break;
                }
            case 4:                                                         //for double datatype
                {
                    ptr = malloc(size*8);
                    double mean = 0;
                    for(int i = 0 ; i < size ; i++)
                    {
                        printf("[%d] -> ",i);
                        scanf("%lf",(double *)ptr+i);
                    }
                    mean = _mean_(ptr,size,4);
                    printf("Mean of given double numbers is %g",mean);
                    break;
                }
            default :                                                       //if invalid choice default sms
                printf("Please enter correct choice!!");
        }
        getchar();                                                         //Gets single charecter from std input device
        printf("\nDo you want to continue yY/nN : ");                              //Asking user for continuation option
        scanf("%c",&ch);                                                   //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                                       //Validating users response for continuation
    return 0;                                                              //End of main function

}
float _mean_(void *vptr,int size,int choice_datatype)                       //function defination
{
    double sum = 0, mean = 0 ;
    switch(choice_datatype)                                                 //start of switch case according to datatype
    {
        case 1:                                                             //case 1 is for calculating mean of int array
            {
                for(int i = 0 ; i < size ; i++)                             //for loop for calculating sum of elements
                    sum = sum + (*((int *)vptr)+i);
                mean = sum / size;                                          //calculating mean
                return mean;                                                //returning mean
            }
        case 2:                                                             //case 2 is for calculating mean of short array
            {
                for(int i = 0 ; i < size ; i++)
                    sum = sum + ((*(short *)vptr) + i);
                mean = sum / size;
                return mean;
            }
        case 3:                                                             //case 3 is for calculating mean of float array
            {
                for(int i = 0 ; i < size ; i++)
                    sum = sum + ((*(float *)vptr) + i);
                mean = sum / size;
                return mean;
            }
        case 4:                                                             //case 4 is for calculating mean of double array
            {
                for(int i = 0 ; i < size ; i++)
                    sum = sum + ((*(double *)vptr) + i);
                mean = sum / size;
                return mean;
            }
    }

}
