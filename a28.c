/*
 * Name: Madhusudan Rathi
 * Date:30/09/2020
 * Description: Implement student record using structure
 * Ex input and output : 
 Enter number of students : 2
 Enter number of subjects : 2
 Enter the name of subjects : 
 maths
 science
 --------------Enter the student details--------------
 Enter name of student 1 : madhu
 Enter roll number : 1
 Enter maths marks out of 100 : 90
 Enter scienc marks out of 100 : 89
 --------------Enter the student details--------------
 Enter name of student 2 : Ajay
 Enter roll number : 3
 Enter maths marks out of 100 : 87
 Enter scienc marks out of 100 : 99
 ---------Display Menu----------
 1. All student details.
 2. Particular student details.
 Enter your choice: 1
 -----All students detail-----

 Roll No.	  Name  	maths 	scienc	Average	Grade
 1  		madhu   	  90  	  89  	89	B
 3  		Ajay    	  87  	  99  	93	A
 Do you want to display menu again? (yY/nN): */
#include <stdio.h>                  //preprocessor directives
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>

struct student                    //structure definition
{
    char student_name[50];
    int rollno;
    char subject[10][10];
    float mark[10];
}s[10];                             //structure variable, array

int main()
{
    char ch;
    do
    {
        int i,j, num, sum,sub_n;
        printf("Enter number of students : ");
        scanf("%d", &num);                                                  //reading the number of students
        printf("Enter number of subjects : ");
        scanf("%d", &sub_n);                                                //reading the number of subjects
        printf("Enter the name of subjects : \n");
        for(j = 0; j < sub_n; j++)                                          //reading the subject names
        {
            __fpurge(stdin);
            scanf("%6s", s[0].subject[j]);
        }
        float *avg = calloc(num, sizeof(float));
        char *grade = calloc(num, sizeof(char));
        for(i = 0; i < num; i++)                                            //reading the student information using loop
        {
            printf("--------------Enter the student details--------------\n");
            sum = 0;
            printf("Enter name of student %d : ", i+1);
            __fpurge(stdin);
            scanf("%9[^\n]", s[i].student_name);
            printf("Enter roll number : ");
            scanf("%d", &s[i].rollno);
            for(j = 0; j < sub_n; j++)
            {
                printf("Enter %s marks out of 100 : ", s[0].subject[j]);    //reading the marks of each subject
                scanf("%f", &s[i].mark[j]);
                sum = sum + s[i].mark[j];
                avg[i] = sum/sub_n;
            }
        }
        for(i = 0; i < num; i++)                                             //Grading based on average
        {
            if(avg[i] >= 90)
                grade[i] = 'A';
            else if(avg[i] >= 80 && avg[i] <= 89.99)
                grade[i] = 'B';
            else if(avg[i] >= 70 && avg[i] <= 79.99)
                grade[i] = 'C';
            else
                grade[i] = 'D';
        }
        int opn;
        char ch1;
        do                                                                  //displaying the details using loop
        {
            printf("---------Display Menu----------\n1. All student details.\n2. Particular student details.\nEnter your choice: ");
            scanf("%d", &opn);
            switch(opn)
            {
                case 1:                                                      //displaying all students detail
                    {
                        printf("-----All students detail-----\n");
                        printf("\nRoll No.\t  Name  \t");
                        for(j = 0; j < sub_n; j++)
                        {
                            printf("%-6s\t", s[0].subject[j]);
                        }
                        printf("Average\tGrade\n");

                        for(i = 0; i < num; i++)                                //loop for printing the details
                        {
                            printf("  %-3d\t\t%-8s\t", s[i].rollno,s[i].student_name);
                            for(j = 0; j < sub_n; j++)
                            {
                                printf("  %g  \t",s[i].mark[j]);
                            }
                            printf("%g\t%c\n",avg[i],grade[i]);
                        }
                        break;
                    }
                case 2:                                                      //displaying a particular students detail
                    {
                        printf("-----Menu for Particular student-----\n");
                        int opn2;
                        char name[10];
                        printf("1. Name\n2. Roll no.\nEnter your choice: ");
                        scanf("%d", &opn2);
                        switch(opn2)
                        {
                            case 1:                                //searching based on name
                                {
                                    printf("Enter the name of the student: ");
                                    __fpurge(stdin);
                                    scanf("%[^\n]", name);
                                    for(i = 0; i < num; i++)
                                    {
                                        if(strcmp(name,s[i].student_name) == 0)
                                        {
                                            printf("\nRoll No.\t  Name  \t");
                                            for(j = 0; j < sub_n; j++)
                                            {
                                                printf("%-6s\t", s[0].subject[j]);
                                            }
                                            printf("Average\tGrade\n");

                                            printf("  %-3d\t\t%-8s\t", s[i].rollno,s[i].student_name);
                                            for(j = 0; j < sub_n; j++)
                                            {
                                                printf("  %g  \t",s[i].mark[j]);
                                            }
                                            printf("%5g\t%3c\n",avg[i],grade[i]);
                                        }
                                    }

                                    break;
                                }
                            case 2:                                             //searching based on roll number
                                {
                                    int rno;
                                    printf("Enter the roll number: ");
                                    scanf("%d", &rno);
                                    for(i = 0; i < num; i++)
                                    {
                                        if(rno == s[i].rollno)
                                        {
                                            printf("\nRoll No.\t  Name  \t");
                                            for(j = 0; j < sub_n; j++)
                                            {
                                                printf("%-6s\t", s[0].subject[j]);
                                            }
                                            printf("Average\tGrade\n");

                                            printf("%-3d\t\t%-8s\t", s[i].rollno,s[i].student_name);
                                            for(j = 0; j < sub_n; j++)
                                            {
                                                printf(" %g \t",s[i].mark[j]);
                                            }
                                            printf("%5g\t%3c\n",avg[i],grade[i]);
                                        }
                                    }
                                }
                                break;

                            default:
                                printf("Invalid choice.\n");
                        }
                    }
                    break;

                default:
                    printf("Invalid option\n");
            }
            printf("Do you want to display menu again? (yY/nN): ");
            __fpurge(stdin);
            scanf("%c", &ch);
        }while(ch == 'y' || ch == 'Y');
        printf("Do you want to continue? (yY/nN): ");
        __fpurge(stdin);
        scanf("%c", &ch);
    }while(ch == 'y' || ch == 'Y');
    return 0;
}
