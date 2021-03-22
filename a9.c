/*
    *Name         : Madhusudan Rathi
    *Date         : 11/08/2020
    *Description  : To find median of two unsorted arrows 
    *Ex. Input    : Enter 'n' value for array A : 5
     and output     Enter elements one by one of Array A : 5 4 3 2 1
                    After sorting of  A : 1 2 3 4 5
                    Median of  A : 3
                    Enter 'n' value for array A : 6
                    Enter elements one by one of Array A :6 5 4 3 2 1
                    After sorting of  A : 1 2 3 4 5 6
                    Median of  A : 3.5
                    Median of both array : 3.25
 
*/
#include<stdio.h>
int main()                                                                 //start of main function
{
    int num,temp,op=65,flag=0;
    float sum=0,med=0,avg_med=0;
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    {
        do                                                                 //do while loop for taking 2 arrays
        {
            printf("\nEnter 'n' value for array %c : ", op);               //asking user to enter Number of elements 
            scanf("%d",&num);
            if(num < 10)
            {
                int array[num];                                                //Declaring array
                printf("Enter elements one by one of array %c: ",op);       
                for(int i = 0 ; i < num ; i++)                                 //Storing users input in array
                    scanf("%d",&array[i]);

                for(int i = num-2 ; i >= 0 ; i--)                              //Logic for bubble sort for ascending order
                    for(int j = 0 ; j <= i ; j++)
                        if(array[j] >= array[j + 1])
                        {
                            temp=array[j];
                            array[j]=array[j+1];
                            array[j+1]=temp;
                        }

                printf("After sorting of %c : ",op);                           //Printing array after sorting
                for(int i = 0 ; i < num ; i++)
                    printf("%d ",array[i]);

                if(num % 2 == 0)                                               //Calculating median by checking number of elements in array, printing it and adding it to sum for calculating avg median of both array
                {
                    med=((array[num/2]+array[(num/2)-1])/(float)2);
                    printf("\nMedian of array %c : %g",op,(double)med);
                    sum=sum+med;
                }
                else
                {
                    med=array[(num/2)];
                    printf("\nMedian of array %c is : %g" ,op,med);
                    sum=sum+med;
                }
                op++;
           }
           else
           {
                printf("Max array elements exceded .");
                flag=1;
                break;
           }
        }while(op == 65 || op == 66);                                     //Condition for taking two array 

        avg_med=sum/(float)2;                                             //calculating avg of two median and printing it
        if(flag != 1)
        printf("\nMedian of both array %g",avg_med);                                            
        getchar();                                                        //Gets single charecter from std input device
        printf("\nDo you want to continue yY/nN: ");                      //Asking user for continuation option
        scanf("%c",&ch);                                                  //taking users input in char variable    
        getchar();
    }while(ch=='y' || ch == 'Y');                                         //Validating users response for continuation
    return 0;                                                             //End of main function
}


