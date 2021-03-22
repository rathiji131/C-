/*
 *Name         : Madhusudan Rathi
 *Date         : 11/09/2020
 *Description  : Implement solution for tower of honai
 *Ex. Input and output : 
 ./a.out 
Enter the number of disks : 3
Make the legal move from A to C
Make the legal move from A to B
Make the legal move from C to B
Make the legal move from A to C
Make the legal move from B to A
Make the legal move from B to C
Make the legal move from A to C 
 */
#include<stdio.h>
void tower_of_honai(int, char, char, char);
int main()                                                                 //start of main function
{
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    { 
        int num;
        printf("Enter the number of disks : ");
        scanf("%d", &num);
        tower_of_honai(num, 'A', 'C', 'B');
        getchar();                                                         //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                        //Asking user for continuation option
        scanf("%c",&ch);                                                   //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                        //Validating users response for continuation
    return 0;                                                              //End of main function
}

void tower_of_honai(int num, char from, char to, char aux)                  //logic for tower of honai
{
    if (num == 1)
    {
        printf("Make the legal move from %c to %c\n", from, to);
        return;
    }
    tower_of_honai(num - 1, from, aux, to);
    printf("Make the legal move from %c to %c\n", from, to);
    tower_of_honai(num - 1, aux, to, from);
}

