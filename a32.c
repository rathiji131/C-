/*
 *Name         : Madhusudan Rathi
 *Date         : 11/09/2020
 *Description  : Generate a n*n magic square 
 *Ex. Input    : Enter number for creating n x n magic square : 3
 *Ex. output   : 
 Magic Square for is
 8    1    6  
 3    5    7  
 4    9    2  
 */
#include<stdio.h>
int main()                                                                 //start of main function
{
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    {
        int i,j,row,col,n;                                                 //variable declaration
        printf("Enter Number for creating n x n magic square : ");
        scanf("%d",&n);
        if(n%2!=0)                                                         //checaking number is odd or not 
        {
            int a[n][n];                                                   
            row=0;                                                          //logic for magic box
            col=n/2;
            for(i=1;i<=n*n;i++)
            {
                a[row][col]=i;
                row--;
                col++;
                if(i%n==0)
                {
                    row=row+2;
                    col=col-1;
                    if(row==n)
                        row=row-n;
                }
                else
                {
                    if(col==n)
                        col=col-n;
                    if(row<0)
                        row=row+n;
                }
            }
            printf("Magic Square for is : \n");
            for(i=0;i<n;i++)                                               //printing magic box
            {
                for(j=0;j<n;j++)
                    printf("%3d  ",a[i][j]);
                printf("\n");
            }
        }
        else
            printf("Please Enter Odd Number to get Magic Square\n");
        getchar();                                                         //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                        //Asking user for continuation option
        scanf("%c",&ch);                                                   //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                        //Validating users response for continuation
    return 0;                                                              //End of main function
}

