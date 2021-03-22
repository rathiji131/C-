/*
 *Name         : Madhusudan Rathi
 *Date         : 11/08/2020
 *Description  : All possible combinations of given string 
 *Ex. Input & output : 
 Enter a string : qqw
Error : Please enter distinct charecter!!
Do you want to continue yY/nN : y
Enter a string : qwe
All possible combinations of given string are : 
weq
wqe
eqw
ewq
qew
qwe
Do you want to continue yY/nN : n

 */
#include<stdio.h>                                                           //preprocessor directives
#include<string.h>
void combination(char * , int , int );                                      //function protocol
int main()                                                                 //start of main function
{
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    {
        int flag = 0;
        char str[10];                                                       //vaiable declaration
        printf("Enter a string : ");                                        //asking user for string
        scanf("%s",str);                                                    //stroring it in string
        int n =strlen(str);                                                 //measuring string length
        char *temp = str;
        for(int i = 0; i < n ; i++ )                                        //checking any repeadted charecter
        {
            for (int j = i+1; j < n ; j++)
            {
                if(str[i] == str[j])
                {    
                    printf("Error : Please enter distinct charecter!!\n");
                    flag = 1;   
                }
            }
        }
        if(flag == 0)
        {
            printf("All possible combinations of given string are : \n");
            combination(str,0,n);                                              //function call
        }
        getchar();                                                         //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                        //Asking user for continuation option
        scanf("%c",&ch);                                                   //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                        //Validating users response for continuation
    return 0;                                                              //End of main function
}

void combination(char *str, int first, int last)                            //function defination
{  
    char temp;                                                              //variable declaration
    for(int i = first; i < last-1; ++i){                                    //logic for combinations
        for(int j = i+1; j < last; ++j)  
        {  
            temp = str[i];  
            str[i] = str[j];  
            str[j] = temp;  
            combination(str , i+1 ,last);  
            temp = str[i];  
            str[i] = str[j];  
            str[j] = temp;  
        }  
    }  
    printf("%s\n",str);                                                     //printing combinations
}  
