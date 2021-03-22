/*
 *Name         : Madhusudan Rathi
 *Date         : 11/09/2020
 *Description  : Calculating varience
 *Ex. Input    : Enter number of elements : 10
 Enter 10 elememts : 
 [0] -> 9
 [1] -> 12
 [2] -> 15
 [3] -> 18
 [4] -> 20
 [5] -> 22
 [6] -> 23
 [7] -> 24
 [8] -> 26
 [9] -> 31

 *Ex. output    :
 x(input)	D = X - Mean	D2
 9		    -11		        121
 12		    -8      		64
 15		    -5	        	25
 18		    -2	        	4
 20	         0	        	0
 22		     2      		4
 23		     3	        	9
 24		     4      		16
 26		     6      		36
 31		     11     		121
 sum = 200			        sum = 400
 The varience of the entered numbers is 40
 */
#include<stdio.h>                                                           //preprocessor directives
#include<stdlib.h>
#include<math.h>
float varience(int *iptr,int size,int choice);                                         //function prototype
int main()                                                                 //start of main function
{
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    {
        int sum = 0 , size,choice;                                                 //varable declaration
        float var = 0;
        printf("Enter number of elements : ");                              //asking user or number of elements
        scanf("%d",&size);
        int arr[size];
        printf("Enter %d elememts : \n",size);                      
        for(int i = 0 ; i < size ; i++)                                       //taking input from user
        {
            printf("[%d] -> ",i);
            scanf("%d",&arr[i]);
        }
        printf("1.static\n2.Dynamic\nEnter choice : ");
        scanf("%d",&choice);
        if (choice == 1 || choice == 2)
        {
            var = varience(arr , size , choice); 
            printf("The varience of the entered numbers is %g\n",var);          //printing varience
        }
        else
            printf("Please enter valid choice!!");
        getchar();                                                          //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                         //Asking user for continuation option
        scanf("%c",&ch);                                                    //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                         //Validating users response for continuation
    return 0;                                                               //End of main function

}


float varience(int *iptr,int size,int choice)                                          //function defination
{
    int sum = 0,*temp = iptr;                                               //variable declaration
    float sum_D2 = 0 , var = 0 , mean = 0,*D,*D2;
    switch(choice)
    {
        case 1:
            {
                float d[100];
                float d2[100];
                for(int i = 0 ; i < size ; i++)                                         //for loop calculating sum
                {
                    sum = sum + *iptr++;
                }
                mean = sum/(float)size;                                                 //calculating mean
                iptr = temp;
                for(int i = 0 ; i < size ; i++)                                         //calculating D and D2
                {
                    d[i] =(float) (*iptr - mean);
                    d2[i] =(float) (d[i])*(d[i]);
                    iptr++;
                    sum_D2 = sum_D2 + d2[i];
                }
                var = sum_D2/(float) size;                                              //calculating varience
                printf("x(input)\tD = Mean - x\tD2\n");
                iptr = temp;
                for(int i = 0 ; i < size ; i++)                                           //printing data in tabular format
                {
                    printf("%d\t\t%g\t\t%g\n",*iptr++,d[i],d2[i]);
                }
                printf("sum = %d\t\t\t\tsum = %g\n",sum,sum_D2);
                break;
            }
        case 2:
            {
                D = (float *)malloc(sizeof(float) * size);
                D2 = (float *)malloc(sizeof(float) * size);
                for(int i = 0 ; i < size ; i++)                                         //for loop calculating sum
                {
                    sum = sum + *iptr++;
                }
                mean = sum/(float)size;                                                 //calculating mean
                iptr = temp;
                for(int i = 0 ; i < size ; i++)                                         //calculating D and D2
                {
                    D[i] =(float) (*iptr - mean);
                    D2[i] =(float) (D[i])*(D[i]);
                    iptr++;
                    sum_D2 = sum_D2 + D2[i];
                }
                var = sum_D2/(float) size;                                              //calculating varience
                printf("x(input)\tD = Mean - x\tD2\n");
                iptr = temp;
                for(int i = 0 ; i < size ; i++)                                           //printing data in tabular format
                {
                    printf("%d\t\t%g\t\t%g\n",*iptr++,D[i],D2[i]);
                }
                printf("sum = %d\t\t\t\tsum = %g\n",sum,sum_D2);
                break;
            }
    }
    return var;
}
/*
   float varience_dynamic(int *iptr,int size)                                          //function defination
   {
   int sum = 0,*temp = iptr;                                               //variable declaration
   float *D,sum_D2 = 0;
   float *D2,var = 0;
   float mean = 0;
   D = (float *)malloc(sizeof(float) * size);
   D2 = (float *)malloc(sizeof(float) * size);
   for(int i = 0 ; i < size ; i++)                                         //for loop calculating sum
   {
   sum = sum + *iptr++;
   }
   mean = sum/(float)size;                                                 //calculating mean
   iptr = temp;
   for(int i = 0 ; i < size ; i++)                                         //calculating D and D2
   {
   D[i] =(float) (*iptr - mean);
   D2[i] =(float) (D[i])*(D[i]);
   iptr++;
   sum_D2 = sum_D2 + D2[i];
   }
   var = sum_D2/(float) size;                                              //calculating varience
   printf("x(input)\tD = X - Mean\tD2\n");
   iptr = temp;
   for(int i = 0 ; i < 10 ; i++)                                           //printing data in tabular format
   {
   printf("%d\t\t%g\t\t%g\n",*iptr++,D[i],D2[i]);
   }
   printf("sum = %d\t\t\tsum = %g\n",sum,sum_D2);
   return var;
   }*/
