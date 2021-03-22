/*
 *Name         : Madhusudan Rathi
 *Date         : 22/09/2020
 *Description  : Copy one file content to another
 *Ex. Input & output : 
 emertxe@ubuntu:~/C_assignment$ cat file1.txt 
 Arun sir , How are you?
 emertxe@ubuntu:~/C_assignment$ cat file2.txt 
 Am absolutely fine ! What about you?
 emertxe@ubuntu:~/C_assignment$ cat file3.txt 
 emertxe@ubuntu:~/C_assignment$ gcc concat.c 
 emertxe@ubuntu:~/C_assignment$ ./a.out 
 madhusudan rathi
 madhusudan rathi
 emertxe@ubuntu:~/C_assignment$ ./a.out file1.txt 
 Arun sir , How are you?
 emertxe@ubuntu:~/C_assignment$ ./a.out file2.txt 
 Am absolutely fine ! What about you?
 emertxe@ubuntu:~/C_assignment$ ./a.out file1.txt file2.txt 
 Arun sir , How are you?
 Am absolutely fine ! What about you?
 emertxe@ubuntu:~/C_assignment$ ./a.out file1.txt file2.txt file3.txt 
 emertxe@ubuntu:~/C_assignment$ cat file3.txt 
 Arun sir , How are you?
 Am absolutely fine ! What about you?
 emertxe@ubuntu:~/C_assignment$ 
 */

#include<stdio.h>                                                           //preprocessor directives
#include<string.h>
#include<stdlib.h>
void copy(FILE *fptr_src,FILE *fptr_dest);
int main(int argc , char **argv)                                            //start of main function
{
    FILE *fptr_src;                                                         //FILE ptr declaration and variables
    FILE *fptr_src2;                                                        //FILE ptr declaration and variables
    FILE *fptr_dest;  
    char *src_file_name;                                                    //charecter pointer declaration for storing file name
    char *src2_file_name;
    char *dest_file_name;
    if(argc == 1)                                                           //if no argument passed take from stdin and print it on stdout                                                      
    {               
        int i = 0;
        char str[100];
        fgets(str,100,stdin);
        puts(str);
    }
    if(argc == 2)                                                           //if only 1 file is passed print contect of it in stdout
    {
        src_file_name = (char *)malloc(10);                                 
        strcpy(src_file_name , argv[1]);                                    //taking file name
        fptr_src = fopen(src_file_name,"r");                                //Opening the file in read mode
        copy(fptr_src,stdout);                                              //function call
        fclose(fptr_src);                                                   //closing file
    }
    if(argc == 3)                                                           //if 2 files are passed then print content of both file to stdout
    {
        src_file_name = (char *)malloc(10);                                 
        dest_file_name = (char *)malloc(10);
        strcpy(src_file_name , argv[1]);
        strcpy(dest_file_name , argv[2]);
        fptr_src = fopen(src_file_name,"r");                                //Opening the file in read mode
        fptr_dest = fopen(dest_file_name,"r");                              //opening the file in write mode
        copy(fptr_src,stdout);                                              //function call twice because of 2 files
        copy(fptr_dest,stdout);
        fclose(fptr_src);                                                   //closing the files
        fclose(fptr_dest);
    }
    if(argc == 4)
    {
        src_file_name = (char *)malloc(10);                                 //memory allocation for storing file names to ptr
        src2_file_name = (char *)malloc(10);
        dest_file_name = (char *)malloc(10);
        strcpy(src_file_name , argv[1]);                                    //taking file names from CL to ptr variable
        strcpy(src2_file_name , argv[2]);
        strcpy(dest_file_name , argv[3]);
        fptr_src = fopen(src_file_name,"r");                                //Opening the file in read mode
        fptr_src2 = fopen(src2_file_name,"r");                              //Opening the file in read mode
        fptr_dest = fopen(dest_file_name,"a");                              //opening the file in append mode
        copy(fptr_src,fptr_dest);                                           //function call to print
        copy(fptr_src2,fptr_dest);
        fclose(fptr_src);                                                   //closing the files
        fclose(fptr_src2);
        fclose(fptr_dest);
    }
    return 0;
}


void copy(FILE *fptr_src,FILE *fptr_dest)                                   //function defination
{
    fseek(fptr_src,0,SEEK_END);                                             //logic for calculating size of file
    int size = ftell(fptr_src);                                         
    char str[size];
    fseek(fptr_src,0,SEEK_SET);
    fread(str,size,1,fptr_src);                                             //logic for copying the file
    fwrite(str,size,1,fptr_dest);
}
