/*
 *Name         : Madhusudan Rathi
 *Date         : 1/10/2020
 *Description  : implement binary search
 *Ex. Input & output :
 Enter number of elements : 4
 Enter 4 integers : 3 8 1 9
 Enter the value to find : 1
 1 is present at index 1.

 */
#include<stdio.h>                                                           //preprocessor directives
#include<stdlib.h>
int sa(const void *a,const void *b);                                        
int sf(const void *a,const void *b);
int sd(const void *a,const void *b);
int main()                                                                 //start of main function
{
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    {
        int n,op;
        printf("Enter number of elements : ");
        scanf("%d",&n); 
        printf("1.int\n2.float\n3.double\nEnter a choice : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1 :
                {
                    int array[n];
                    int c, first, last, middle, search;
                    printf("Enter %d integers : ", n);
                    for (c = 0; c < n; c++)
                        scanf("%d",&array[c]); 
                    printf("Enter the value to find : ");
                    scanf("%d", &search);
                    qsort(array,n,4,sa);   
                    printf("Sorted array is : ");
                    for (c = 0; c < n; c++)
                        printf("%d  ",array[c]); 
                    first = 0;
                    last = n - 1;
                    middle = (first+last)/2;
                    while (first <= last) {
                        if (array[middle] < search)
                            first = middle + 1;    
                        else if (array[middle] == search) {
                            printf("\n%d is present at index %d.\n", search, middle+1);
                            break;
                        }
                        else
                            last = middle - 1;
                        middle = (first + last)/2;
                    }
                    if (first > last)
                        printf("Not found! %d is not present in the list.\n", search);
                    break;
                }
            case 2 :
                {
                    float array[n];
                    int c, first, last, middle;
                    float search;
                    printf("Enter %d float integers : ", n);
                    for (c = 0; c < n; c++)
                        scanf("%f",&array[c]); 
                    printf("Enter the value to find : ");
                    scanf("%f", &search);
                    qsort(array,n,4,sf);   
                    printf("Sorted array is : ");
                    for (c = 0; c < n; c++)
                        printf("%f  ",array[c]); 
                    first = 0;
                    last = n - 1;
                    middle = (first+last)/2;
                    while (first <= last) {
                        if (array[middle] < search)
                            first = middle + 1;    
                        else if (array[middle] == search) {
                            printf("\n%f is present at index %d.\n", search, middle+1);
                            break;
                        }
                        else
                            last = middle - 1;
                        middle = (first + last)/2;
                    }
                    if (first > last)
                        printf("Not found! %f is not present in the list.\n", search);
                    break;
                }
            case 3 :
                {
                    double array[n];
                    int  c, first, last, middle;
                    double search;
                    printf("Enter %d double integers : ", n);
                    for (c = 0; c < n; c++)
                        scanf("%lf",&array[c]); 
                    printf("Enter the value to find : ");
                    scanf("%lf", &search);
                    qsort(array,n,4,sd);   
                    printf("Sorted array is : ");
                    for (c = 0; c < n; c++)
                        printf("%lf  ",array[c]); 
                    first = 0;
                    last = n - 1;
                    middle = (first+last)/2;
                    while (first <= last) {
                        if (array[middle] < search)
                            first = middle + 1;    
                        else if (array[middle] == search) {
                            printf("\n%lf is present at index %d.\n", search, middle+1);
                            break;
                        }
                        else
                            last = middle - 1;
                        middle = (first + last)/2;
                    }
                    if (first > last)
                        printf("Not found! %lf is not present in the list.\n", search);
                    break;
                }
        }
        getchar();                                                         //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                              //Asking user for continuation option
        scanf("%c",&ch);                                                   //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                                       //Validating users response for continuation
    return 0;                                                              //End of main function

}
//function defination
int sa(const void *a,const void *b)
{
    return *(int *)a > *(int *)b;
}
int sf(const void *a,const void *b)
{
    return *(float *)a > *(float *)b;
}
int sd(const void *a,const void *b)
{
    return *(double *)a > *(double *)b;
}
