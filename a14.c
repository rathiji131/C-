/*
 *Name         : Madhusudan Rathi
 *Date         : 29/08/2020
 *Description  : Implementing bitwise function
 *Ex. Input    : Select bit operation from below list
                 1. get_nits
                 2. replace_nbits
                 3. get_nbits_from_pos
                 4. set_nbits_from_pos
                 5. toggle_nbits_from_pos
                 6. print_bits
                 Enter your choice : 1
                 Enter a number : 15
                 Enter number of bits : 2
 *Ex. output   : get_nbits value is : 3
 */
#include<stdio.h>
#include<math.h>
int get_nbits_from_pos(int num,int n,int pos);
int get_nbits(int num,int n);
int replace_nbits(int num,int n,int val);
int replace_nbits_from_pos(int num,int n,int pos,int val);
int toggle_bits_from_pos(int num,int n,int pos);
int print_bits(unsigned int num,int n);

int main()                                                 //start of main function
{
    int choice;
    char ch;                                               //Declaration of variables
    do                                                     //Start of do while loop
    {
        printf("Select bit operation from below list\n1. get_nits\n2. replace_nbits\n3. get_nbits_from_pos\n4. set_nbits_from_pos\n5. toggle_nbits_from_pos\n6. print_bits\nEnter your choice : ");  //Printing menue
        scanf("%d",&choice);                                //storing choice
        switch(choice)                                      //start of switch case  executes cases according to choice
        {
            case 1 :                                        //taking inputs for get_nbits function,validating it , calling function n printing the valuereturned by function 
                
                {
                    int num,n,res;
                    printf("Enter a number : ");
                    scanf("%d",&num);
                    printf("Enter number of bits : ");
                    scanf("%d",&n);
                    if(n <= 32 && num < pow(2,20))
                    { 
                        res = get_nbits(num,n);
                        printf("get_nbits value is  %d\n",res);
                    }
                    else
                        printf("Inputs out of range.");
                    break;
                }
            case 2 :                                        //taking inputs for replace_nbits function,validating it , calling function n printing the valuereturned by function 
                {
                    int num,n,val,res;
                    printf("Enter a number : ");
                    scanf("%d",&num);
                    printf("Enter number of bits : ");
                    scanf("%d",&n);
                    printf("Enter a value : ");
                    scanf("%d",&val);
                    if(n <= 32 && val < pow(2,20) && num < pow(2,20))
                    {
                        res = replace_nbits(num,n,val);
                        printf("replace_nbits value is  %d\n",res);
                    }
                    else
                        printf("Inputs out of range.");
                    break;
                }
            case 3 :                                      //taking inputs for get_nbits_from_fun function,validating it , calling function n printing the valuereturned by function 
                {
                    int num,n,pos,res;
                    printf("Enter a number : ");
                    scanf("%d",&num);
                    printf("Enter number of bits : ");
                    scanf("%d",&n);
                    printf("Enter a position : ");
                    scanf("%d",&pos);
                    if(n <= pos && pos <= 32 && num < pow(2,20))
                    {
                        res = get_nbits_from_pos(num,n,pos);
                        printf("get_nbits_from_position value is  %d\n",res);
                    }
                    else
                        printf("Inputs out of range.");
                    break;
                }
            case 5 :                                     //taking inputs for toggle_nbits_from_pos function,validating it , calling function n printing the valuereturned by function 
                {
                    int num,n,pos,res;
                    printf("Enter a number : ");
                    scanf("%d",&num);
                    printf("Enter number of bits : ");
                    scanf("%d",&n);
                    printf("Enter a position : ");
                    scanf("%d",&pos);
                    if(n <= pos && pos <= 32 && num < pow(2,20))
                    {
                        res = toggle_bits_from_pos(num,n,pos);
                        printf("toggle_nbits value is  %d\n",res);
                    }
                    else
                        printf("Inputs outof range.");
                    break;
                }
            case 4 :                                     //taking inputs for replce_nbits_from_pos function,validating it , calling function n printing the valuereturned by function 
                {
                    int num,n,val,pos,res;
                    printf("Enter a number : ");
                    scanf("%d",&num);
                    printf("Enter number of bits : ");
                    scanf("%d",&n);
                    printf("Enter position : ");
                    scanf("%d",&pos);
                    printf("Enter a value : ");
                    scanf("%d",&val);

                    if(n <= pos && val < pow(2,20) && pos <= 32 && num < pow(2,20))
                    {
                        res = replace_nbits_from_pos(num,n,pos,val);
                        printf("replace_nbits_from_pos value is  %d\n",res);
                    }
                    else
                        printf("Inputs out of range.");
                    break;
                }
            case 6 :                                        //taking inputs for print_nbits function,validating it , calling function n printing the valuereturned by function 
                {
                    int num,n,val;
                    printf("Enter a number : ");
                    scanf("%d",&num);
                    printf("Enter number of bits : ");
                    scanf("%d",&n);
                    if(n <= 32 && num < pow(2,20))
                        print_bits(num,n);
                    else
                        printf("Input is out of range.");
                    break;
                }
            default : 
                printf("Enter correct choice.\n");

        }   
        getchar();                                                         //Gets single charecter from std input device
        printf("Do you want to continue yY/nN : ");                        //Asking user for continuation option
        scanf("%c",&ch);                                                   //taking users input in char variable    
        getchar();
    }while(ch == 'y' || ch == 'Y');                                        //Validating users response for continuation
    return 0;                                                              //End of main function

}


int get_nbits_from_pos(int num,int n,int pos)                               //logic for get n bits from pos of a number
{
    return ((((1 << n) - 1) << pos - n + 1) & num) >> pos - n + 1;
}

int get_nbits(int num,int n)                                                //logc for get nibuts of a number from lsb
{
    return ((1 << n) - 1) & num ;
}

int replace_nbits(int num,int n,int val)                                    //logic for replacing nbits of a number from lsb by last n bits of another number
{
    return (((num >>n ) << n) | get_nbits(val ,n));
}

int replace_nbits_from_pos(int num,int n,int pos,int val)                   //logic for replacing nbits from pos of given number by last nbits of another number
{
    return ((num & ( ~0 << (pos + 1) | (1 << (pos - n + 1))-1 )) | (get_nbits(val , n) << (pos - n + 1)));
}

int toggle_bits_from_pos(int num,int n,int pos)                             //logic for toggling n bits of a number from pos 
{
    return ((replace_nbits_from_pos(0,n,pos,0XFFFFFFFF)) ^ num);
}

int print_bits(unsigned int num,int n)                                      //logic for printing last n  bits of a given number
{
    char arr[32];
    for(int i = 0; i < 8* sizeof(int) ; i++)
    {

        if(num & 0x80000000)
            arr[i] = 1;
        else
            arr[i] = 0;
        num = num << 1;
    }
    printf("The last %d bits of %d are : ",n,num);
    for(int i = 32 - n; i < 32 ; i++)
    {   
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
