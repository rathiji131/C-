/*
Name         : Madhusudan Rathi
Date         : 11/09/2020
Description  : Implement own strtok function
Ex. Input & output :
Enter string1 = ::Bangalore;;::---Chennai:;Kolkata:;Delhi:-:Mumbai
Enter string2 = ;./-:
Tokens :
Bangalore
Chennai
Kolkata
Delhi
Mumbai
*/

#include<stdio.h>                               //preprocessor directives
#include<stdlib.h>
char * my_strtok(char * s, char *delimit);      //function prototype
void main()                                     //start of main function
{
    char str[100], *token, delimit[20];         //variable declaration
    int i=0, len=0;
    printf("Enter the input string : ");        //taking input from user
    scanf("%s",str);  
    printf("Enter the delimiter string : ");
    scanf("%s",delimit);
    printf("Tokens : \n");
    token = my_strtok(str,delimit);	            //logic for strtok function
    while(token != NULL)
    {
        printf("%s \n", token);
        token = my_strtok(NULL, delimit);			
    }
}

char * my_strtok(char * str, char *delimit)     //function defination
{
    static int pos;                             //variable declaration
    static char *s;	
    int i =0, start = pos,j = 0;

    // Copying the string for further calls of strtok
    if(str!=NULL)
        s = str;

    //While not end of string
    while(s[pos] != '\0')
    {
        j = 0;	
        //Comparing of one of the delimiter matches the character in the string
        while(delimit[j] != '\0')
        {		
            //Pos point to the next location in the string that we have to read
            if(s[pos] == delimit[j])
            {
                //Replace the delimter by \0 to break the string
                s[pos] = '\0';
                pos = pos+1;				
                //Checking for the case where there is no relevant string before the delimeter.
                //start specifies the location from where we have to start reading the next character
                if(s[start] != '\0')
                    return (&s[start]);
                else
                {
                    // Move to the next string after the delimiter
                    start = pos;
                    // Decrementing as it will be incremented at the end of the while loop
                    pos--;
                    break;
                }
            }
            j++;
        }
        pos++;		
    }//End of Outer while
    s[pos] = '\0';
    if(s[start] == '\0')
        return NULL;
    else
        return &s[start];
}
