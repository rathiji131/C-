/*
 *Name         : Madhusudan Rathi
 *Date         : 22/09/2020
 *Description  : Copy one file content to another
 *Ex. Input & output : 
 emertxe@ubuntu:~/C_assignment$ cat file1.txt 
 Arun sir , How are you?
 emertxe@ubuntu:~/C_assignment$ cat file2.txt 
 Hi , Am absolutely fine!!
 emertxe@ubuntu:~/C_assignment$ ./a.out file1.txt file2.txt 
 emertxe@ubuntu:~/C_assignment$ cat file1.txt 
 Arun sir , How are you?
 emertxe@ubuntu:~/C_assignment$ cat file2.txt 
 Arun sir , How are you?
 */

#include<stdio.h>                                                           //preprocessor directives
#include<string.h>

int main(int argc , char **argv)                                            //start of main function
{
    FILE *fptr_src;                                                     //FILE ptr declaration and variables
    FILE *fptr_dest;
    char *src_file_name;
    char *dest_file_name;
    if (argv[1] != NULL)                                                //validations for files
    {
        src_file_name = argv[1];
        if(argv[2] != NULL)
        {
            dest_file_name = argv[2];
        }
        else
        {
            printf("Destination file is missing!\n");
            return 1;
        }
    }
    else
    {
        printf("Please pass the 2 file names while executing.!!\n ");
        return 1;
    }
    fptr_src = fopen(src_file_name,"r");                                //Opening the file in read mode
    fptr_dest = fopen(dest_file_name,"w");                              //opening the file in write mode
    fseek(fptr_src,0,SEEK_END);                                         //calculating size of file
    int size = ftell(fptr_src);                                         
    char str[size];
    fseek(fptr_src,0,SEEK_SET);
    fread(str,size,1,fptr_src);                                         //logic for copying the file
    fwrite(str,size,1,fptr_dest);
    fclose(fptr_src);                                                   //closing the files
    fclose(fptr_dest);
    return 0;                                                              //End of main function
}


