/*
 *Name         : Madhusudan Rathi
 *Date         : 20/09/2020
 *Description  : Matrix multiplication  
 *Ex. Input & output : 
Enter value of row : 3
Enter value of col : 3
Enter elements of array 
1 2 3 
1 2 3
1 2 3
Transpose of matrix :
1	1	1	
2	2	2	
3	3	3	
Matrix Multiplication : 
14	14	14	
14	14	14	
14	14	14	
Do you want to continue yY/nN :     
 */

#include<stdio.h>
#include<stdlib.h>
int main()                                                                 //start of main function
{
    char ch;                                                               //Declaration of variables
    int m,n;
    do                                                                     //Start of do while loop
    {   
        printf("Enter value of row : ");                                   //taking row and col from user 
        scanf("%d",&m); 
        printf("Enter value of col : "); 
        scanf("%d",&n); 
        
        int matrix[m][n];                                                   //matrix array declartion
        int transpose[n][m];
        int mul_mat[m][m];
        
        printf("Enter elements of array \n");                               //asking user for input
        
        for (int i = 0 ; i < m ; i++)
            for (int j = 0 ; j < n ; j++)
                scanf("%d",&matrix[i][j]);

        for (int i = 0 ; i < m ; i++)                                       //calculating matrix 
            for (int j = 0 ; j < n ; j++)
                transpose[j][i] = matrix[i][j];
        
        printf("Transpose of matrix :\n");                                  //printing transpose matrix
        
        for (int i = 0 ; i < n ; i++)
        {
            for (int j = 0 ; j < m ; j++)
                printf("%d\t",transpose[i][j]);
            printf("\n");
        }

        for (int i = 0 ; i < m ; i++)                                       //matrix multiplication logic
            for (int j = 0 ; j < n ; j++)
            {  
                mul_mat[i][j] = 0 ;
                for(int k = 0 ; k < n  ; k++)
                    mul_mat[i][j] = mul_mat[i][j] + (matrix[i][k])*(transpose[k][j]);
            }
        
        printf("Matrix Multiplication : \n");                               //printing multiplied matrix
        
        for (int i = 0 ; i < m ; i++)
        {   
            for (int j = 0 ; j < m ; j++)
                printf("%d\t",mul_mat[i][j]);
            printf("\n");
        }

        getchar();                                                         //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                        //Asking user for continuation option
        scanf("%c",&ch);                                                   //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                        //Validating users response for continuation
    return 0;                                                              //End of main function
}


