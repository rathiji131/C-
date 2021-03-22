/*
 *Name         : Madhusudan Rathi
 *Date         : 22/09/2020
 *Description  : implement my_printf() function
 *Ex. Input & output : 
 int     => 25
 float   => 12.340000
 char    => M
 double  => 1234.876000f
 string  => Madhu
 */
#include<stdio.h>                                                          //preprocessor directives
#include<stdarg.h>
void my_printf(const char *format, ...);                                    //function protocol
int main()                                                                 //start of main function
{
    char ch;                                                               //Declaration of variables
    do                                                                     //Start of do while loop
    {
        int num ;                                                      //varibale declaration
        float f ;
        char c ;
        double d ; char s[100];                                  //calling  own printf function
        my_printf("Enter int , float , char , double , string : ");
        scanf("%d %f %c %lf %s",&num,&f,&c,&d,s);
        my_printf("int       => %d\nfloat     => %f\nchar      => %c\ndouble    => %lf\nstring    => %s\n",num,f,c,d,s);    
        getchar();                                                         //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                        //Asking user for continuation option
        scanf("%c",&ch);                                                   //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                        //Validating users response for continuation
    return 0;                                                              //End of main function
}
void my_printf(const char *format, ...)                                     //function defination
{
    va_list ap;
    va_start(ap,format);
    while(*format != '\0')                                                 //loop till we get \0
    {
        if(*format == '%')                                                 //checking for format specifier
        {
            format++;
            switch(*format)                                                //according to format specifier data will printed
            {
                case 'd':
                    {
                        int i;
                        i = va_arg(ap,int);
                        fprintf(stdout,"%d",i);
                        break;
                    }
                case 'f':
                    {
                        float f;
                        f = va_arg(ap,double);
                        fprintf(stdout,"%f",f);
                        break;
                    }
                case 'c':
                    {
                        char c;
                        c = va_arg(ap,int);
                        fprintf(stdout,"%c",c);
                        break;
                    }
                case 'l':
                    {
                        double d;
                        d = va_arg(ap,double);
                        fprintf(stdout,"%lf",d);
                        break;
                    }
                case 's':
                    {
                        char *str;
                        str = va_arg(ap,char *);
                        fprintf(stdout,"%s",str);
                        break;
                    }
            }
        }
        else
            putchar(*format);
        format++;
    }
    va_end(ap);
}

