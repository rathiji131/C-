/*
 *Name         : Madhusudan Rathi
 *Date         : 28/08/2020
 *Description  : Sorting float array without modifivation of array
 *Ex. Input    : Enter number of elements in array : 5
                 Enter elements of array : 12.5 -9.3 -1.2 23.5 1.3
 *Ex. output   : -9.3 -1.2 1.3 12.5 23.5
 */
#include<stdio.h>
#include<math.h>
void sort(float *store,int n);
int main()                                                                 //start of main function
{
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    {
        int n;                                                              //variables declaration
        printf("Enter number of elements in array : ");                     //asking user number of elements
        scanf("%d",&n);                                                     //storing it in n
        float store[n];
        printf("Enter elements of array : ");                               //taking array input
        for(int i = 0 ; i < n ; i++)
            scanf("%f",&store[i]);
        sort(store,n);                                                      //function call
        printf("\nArray After sorting : ");                                 //printing array after sorting
        for(int i = 0;i < n; i++)
            printf("%g ",store[i]);
        getchar();                                                             //Gets single charecter from std input device
        printf("\nDo you want to continue : ");                                  //Asking user for continuation option
        scanf("%c",&ch);                                                       //taking users input in char variable    
        getchar();
    }while(ch=='y');                                                       //Validating users response for continuation
    return 0;                                                              //End of main function
}
void sort(float *store,int n)                                               //sort function defination
{
    float small,large;                                                      //variable decalration
    small = large = *store;
    for(int i =0; i < n ; i++)                                              //logic for longest and smallest 
    {
        if(small > *(store+i))
            small = *(store+i);
        if(large < *(store+i))
            large = *(store+i);
    }
    float n_small;
    printf("%g ",small);                                                    //printing smallest number
    for(int i = 0 ; i < n-1; i++)                                           //logic for sorting aray in ascending order withoiut modification of orignal array
    {
        n_small = large;
        for(int j = 0 ; j < n ; j++)
        {
            if(*(store + j ) > small && (*(store + j) < n_small))
                n_small = *(store+j);
        }
        small = n_small;
        printf("%g ",small);
    /*    if(small == large)
            break;*/
    }
}
