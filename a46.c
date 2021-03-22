/*
 * Name         :  Madhusudan Rathi
 * Date         :  29/09/2020
 * Description  :  Implement own my_scanf function
 * Ex output    :
 Enter an integer : 12
 The entered number is  12
 Enter a character : A
 The entered charecter is'A'
 Enter a double number: 12.233
 Entered double number is 12.233000
 Enter a string: Madhu
 Entered string is "Madhu"
 Enter a float number: 34.0192
 Entered float number is 34.019199
 */

#include <stdio.h>                                              //preprocessor directives
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <string.h>

int my_scanf(char *s, ...);                                     //function prototype

int main()                                                      //start of program
{
    int num;                                                    //variable declaration
    float fnum;
    double dnum;
    char ch, charac;
    char str[200];
    //calling scanf function for different inputs
    printf("Enter an integer : ");           
    my_scanf("%d", &num);                       
    printf("The entered number is  %d\n", num);

    printf("Enter a character : ");                
    my_scanf("%c", &charac);                      
    printf("The entered charecter is\'%c\'\n", charac);

    printf("Enter a double number: ");                  
    my_scanf("%g", &dnum);
    printf("Entered double number is %lf\n", dnum);

    printf("Enter a string: ");                  
    my_scanf("%s", &str);
    printf("Entered string is \"%s\"\n", str);

    printf("Enter a float number: ");                   
    my_scanf("%f", &fnum);
    printf("Entered float number is %f\n", fnum);

    return 0;
}

int my_scanf(char *s, ...) //function definition for my_scanf
{
    va_list ap;            //declaring the pointer ap
    va_start(ap, s);       //initializing the pointer ap to point to the starting
    int i;

    for(i = 0; s[i]; i++)   
    {
        if(s[i] == '%')     
        {
            i++;           
            switch(s[i])   
            {
                case 'd':                              //logic for reading integers 
                    {
                        char ch, str[10];              
                        int *iptr = NULL, j;          
                        iptr= va_arg(ap, int *);     
                        __fpurge(stdin);
                        ch = getchar();            
                        for(j = 0; isdigit(ch); j++)   
                        {
                            str[j] = ch;               
                            ch = getchar();
                        }
                        if(isdigit(str[0]))            
                            *iptr = atoi(str);             
                        else
                        {
                            printf("Please enter integers only\n");  
                            iptr = NULL;
                            break;
                        }
                    }
                    break;

                case 'c':                                   //logic for reading character
                    {
                        char *cptr = NULL, ch;
                        cptr= va_arg(ap, char *);    
                        __fpurge(stdin);    
                        ch = getchar();            
                        *cptr = ch;                 
                    }
                    break; 

                case 's':                                   //logic for reading string
                    {
                        char *sptr = NULL;
                        char st[200];               
                        char ch;
                        int i;
                        sptr = va_arg(ap, char *);
                        __fpurge(stdin);
                        ch = getchar();
                        for (i = 0; ((ch != ' ') && (ch != '\t') && (ch != '\n')) ; i++) 
                        {
                            st[i] = ch;       
                            ch = getchar();
                        }
                        st[i] = '\0';         
                        strcpy(sptr, st);     
                    }
                    break;

                case 'f':                                       //logic for reading float value
                    {

                        char ch, str[10];             
                        int j;
                        float *fptr = NULL;           
                        fptr= va_arg(ap, float *);       
                        __fpurge(stdin);
                        ch = getchar();            
                        for(j = 0; isdigit(ch) || ch == '.'; j++)   
                        {
                            str[j] = ch;               
                            ch = getchar();
                        }
                        if(isdigit(str[0]))           
                        {
                            *fptr = (float) atof(str);             
                        }
                        else
                        {
                            printf("Please enter float numbers only\n"); 
                            fptr = NULL;
                            break;
                        }
                    }
                    break;

                case 'g':                                       //logic for reading double
                    {
                        char ch, str[10];               
                        int j;
                        double *dptr = NULL;           
                        dptr= va_arg(ap, double *);       
                        __fpurge(stdin);
                        ch = getchar();            
                        for(j = 0; isdigit(ch) || ch == '.'; j++)   
                        {
                            str[j] = ch;            
                            ch = getchar();
                        }
                        if(isdigit(str[0]))           
                        {
                            *dptr = (double) atof(str);             
                        }
                        else
                        {
                            printf("Please enter decimal numbers only\n");  
                            dptr = NULL;
                            break;
                        }
                    }
                    break;
                default:
                    printf("Invalid input");
            }
        }
        else
        {
            printf("Invalid %% format specifier\n");
        }
    }
    va_end(ap);
}
