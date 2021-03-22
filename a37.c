/*
 * Name:        Madhusudan Rathi
 * Date:        30/09/2020
 * Description: Implement fragments using Array of Pointers 
 * Ex input and output:
 Enter the number of rows: 3
 Enter number of columns in row [0]: 4
 Enter the 4 values of row[0]1 2 3 4
 Enter number of columns in row [1]: 3
 Enter the 3 values of row[1]2 5 9
 Enter number of columns in row [2]: 5
 Enter the 5 values of row[2]1 3 2 4 1

 Array before sorting:
 2 3 4 2.5 
 5 9 5.33333 
 3 2 4 1 2.2 

 Array after sorting:
 1 3 2 4 1 2.2 
 1 2 3 4 2.5 
 2 5 9 5.33333  
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    char ch;
    do
    {
        printf("Enter the no. of rows: ");       //read number of rows from the user
        scanf("%d", &n);
        float *ptr[n];                              //Variable declaration
        int i,j, sum;
        float avg[n];    
        int col_count[n];                          

        for(i = 0; i < n; i++)  
        { 
            sum = 0;
            printf("Enter number of columns in row [%d]: ", i);  
            scanf("%d", &col_count[i]);                              //reading no of elements in each row
            ptr[i] = malloc((col_count[i] + 1) * sizeof(float));     //memory allocation for each 1D array
            printf("Enter the %d values of row[%d]\n",col_count[i],i);
            for(j = 0; j < col_count[i]; j++)                        //calculating sum of row elemens
            {
                scanf("%f", &ptr[i][j]);
                sum = sum + ptr[i][j];
            }
            avg[i] = (float) sum/col_count[i];  //finding average and saving it in the array for average
            ptr[i][col_count[i]] = avg[i];       //storing the calculated average in the last position of each 1D array
        }
        printf("\nArray before sorting:\n");  //printing the array
        for(i = 0; i < n; i++)
        {
            for(j = 0; j <= col_count[i]; j++)
            {
                printf("%g ", ptr[i][j]);
            }
            printf("\n");
        }
        float *temp;                                                //variables to be used in sorting
        int size;
        for(i = 0; i < n-1; i++)                                    //loop for sorting the arrays according to the average value
        {
            for(j = 0; j < n - 1 - i; j++)
            {
                if(ptr[j][col_count[j]] > ptr[j+1][col_count[j+1]])  //comparing the average values
                {
                    temp = ptr[j];                                    //doing the swaping of the 1D address and size of each 1D array if the comparison is true
                    size = col_count[j];

                    ptr[j] = ptr[j+1];
                    col_count[j] = col_count[j+1];

                    ptr[j+1] = temp;
                    col_count[j+1] = size;
                }
            }
        }

        printf("\nArray after sorting:\n");                  //printing the array after sorting

        for(i = 0; i < n; i++)
        {
            for(j = 0; j <= col_count[i]; j++)
            {
                printf("%g ", ptr[i][j]);
            }
            printf("\n");
        }

        getchar();
        printf("\nDo you want to continue (yY/nN) : ");    //asking user to continue or not
        scanf("%c", &ch);
    }while(ch == 'y');

    return 0;
}


