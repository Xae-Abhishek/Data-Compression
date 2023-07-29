#include<stdio.h>
#include<string.h>
#include<math.h>


struct node
{
    char character;
    int frequency;
    int symbol[8];
};

struct node2
{
    char character;
    int symbol[8];
};

struct node array[100];
int digit;
int count=-1;

// for ascii
struct node2 array2[100];
int count2=-1;



int sentdata[1000];
int size=0;

int asciidata[1000];
int size99=0;

char string[10];

void fixed(char data[100]);
void displaysymbol();
void displaysentdata(char data[100]);
void decoding();
void ascii(char data[100]);
int main()
{
    system("cls");

    printf("\n\n\t Enter the Data : ");

    char data[100];
    fflush(stdin);
    gets(data);

    // /Generating ascii data (data is stored in global variables)

    ascii(data);

    int choice;
    
    printf("\n\n\t Enter 1 for Fixed length Encoding");
    printf("\n\n\t Enter 2 TO Exit");
    printf("\n\n\t Choice : ");
    scanf("%d",&choice);
    system("cls");
    

    if(choice==1)
    {
        fixed(data);
    }
    else if(choice==2)
    {
        printf("\n\n\t CLosing the Program");
        return 0;
    }

    else{
        printf("\n\n\t Enter From Given Choices only");
    }
    int ch2;

    for(;;)
    {
    system("cls");
    printf("\n\n\t Enter 1 to See the Generated Data");
    printf("\n\n\t Enter 2 for Decoding the Sended Data");
    printf("\n\n\t Enter 3 to exit");
    printf("\n\n\t choice : ");
    scanf("%d",&choice);
    system("cls");

    
    switch (choice)
    {

    case 1:
        printf("\n\n\t Enter 1 To see Designated symbols for given characters");
        printf("\n\n\t Enter 2 to see the data To be Sent");
        
        printf("\n\n\t Choice : ");
        scanf("%d",&ch2);
        if(ch2==1)
        {
            displaysymbol();
        }
        else{
            displaysentdata(data);
        }

        break;


    case 2:
        decoding();
        break;

    case 3:
            break;
    default:
    printf("\n\n\t enter from given choices only");
    printf("\n\n");
    fflush(stdin);
    gets(string);
    break;


    }

    if(choice==3)
    {
        break;
    }
    }
    }

void fixed(char data[100])
{
    
//	removing the duplicate symbols and storing the chracter in array of structure
    int length=strlen(data);
   
    int flag=0;

    int i,j,k,l,m;
// removing the duplicat symbols
    for(i=0;i<length;i++)
    {
        flag=0;
        for(j=0;((j<=count)&&(count>=0));j++)
        {
            if(array[j].character==data[i])
            {
                array[j].frequency=array[j].frequency+1;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            count++;
            array[count].character=data[i];
            array[count].frequency=1;
        }
        
    }
    
//	deciding the number of digits required to store this much data

    int count2=count+1;

    for(i=0;;i++)
    {
        if(pow(2,i)>=count2)
        {
            digit=i;
            break;
        }
    }
// setting all the digits of array in array of structure to avoi dgarbage values
    for(i=0;i<=count;i++)
    {
        for(j=0;j<digit;j++)
        {
            array[i].symbol[j]=0;
        }
    }
// using an temp array to make the task simple
// Note : Here we do not reset the array we just simply add 1 for each new element and then set it up for binary
    int temp[10]={0,0,0,0,0,0,0,0,0,0};

    for(i=0;i<=count;i++)
    {
        if(i==0)
        {
            continue;
        }
        
        j=digit-1;
        temp[j]=temp[j]+1;

        for(j=digit-1;j>=0;j--)
        {
            if(temp[j]>1)
            {
                temp[j-1]=temp[j-1]+1;
                temp[j]=0;
            }
        }

        for(j=0;j<digit;j++)
        {
            array[i].symbol[j]=temp[j];
        }

    }
    system("cls");
    printf("\n\n");
    

    
}

void displaysymbol()
{
    int i,j;
    
    for(i=0;i<=count;i++)
    {
        printf("\n\t symbol of %c : ",array[i].character);
        for(j=0;j<digit;j++)
        {
            printf("%d",array[i].symbol[j]);
        }
    }
    printf("\n\n");
    fflush(stdin);
    gets(string);
}

void displaysentdata(char data[100])
{
    int i,j,k;
    int length=strlen(data);
    

    printf("\n\n\n\t sent Data : ");
    for(i=0;i<length;i++)
    {
        for(j=0;j<=count;j++)
        {
            if(array[j].character==data[i])
            {
                for(k=0;k<digit;k++)
                {
                    printf("%d",array[j].symbol[k]);
                    sentdata[size]=array[j].symbol[k];
                    size++;
                }
            }
        }
    }
    printf("\n\n");
    fflush(stdin);
    gets(string);

}

void decoding()
{
    int i,j,k;
    int flag=0;
    system("cls");
    printf("\n\n\t Recived Data : ");
    for(i=0;i<size;i++)
    {
        printf("%d",sentdata[i]);
    }
    printf("\n\n\t Length : %d Bits",size);


    printf("\n\n\t ASCII Data : ");

    for(i=0;i<size99;i++)
    {
        printf("%d",asciidata[i]);
    }
    printf("\n\n\t Length : %d Bits",size99);
    

    printf("\n\n\t After Decoding : ");
    
    for(i=0;i<size;i=i+digit)
    {
        
        for(k=0;k<=count;k++)
        {
            flag=0;

            for(j=0;j<digit;j++)
            {
                if(array[k].symbol[j]!=sentdata[i+j])
                {
                    flag=1;
                    break;
                }
            }

            if(flag==0)
            {
                printf("%c",array[k].character);
            }
        }
    }
    printf("\n\n");
    fflush(stdin);
    gets(string);
}

void ascii(char data[100])
{

    int length=strlen(data);

    int i,j,k;
    int flag=0;
    
// Removing the duplicate symbols and storing the symbols in array of structure

    for(i=0;i<length;i++)
    {
        flag=0;
        for(j=0;(j<=count2)&&(count2>=0);j++)
        {
            if(data[i]==array2[count2].character)
            {
                flag=1;
            }
        }
        if(flag==0)
        {
            count2++;
            array2[count2].character=data[i];
        }
    }

    int temp[8]={0,0,0,0,0,0,0,0};

    char alphabet;
    int num;
    int x;

    for(i=0;i<=count2;i++)
    {
        // Resetting for binary
        for(j=0;j<8;j++)
        {
            temp[j]=0;
        }
//  	finding the ascii value of the character
        alphabet=array2[i].character;
        for(j=0;j<=126;j++)
        {
            if(j==alphabet)
            {
                num=j;
                break;
            }
        }
        
        
        x=999;
// 		generating the binary[as per ascii] value corresponding to the chracter
        for(j=7;j>=0;j--)
        {
            
            

            x=num%2;
            num=num/2;
            temp[j]=x;
            
            if(num==0)
            {
                temp[j]=1;
                break;
            }
        }
// 		copying the generated binary in array of structure
        for(j=0;j<8;j++)
        {
            array2[i].symbol[j]=temp[j];
        }
    }

    
    length=strlen(data);

// genrating the data to be sent for ascii[binaray of the input]
    for(i=0;i<length;i++)
    {
        

        for(j=0;j<=count2;j++)
        {
            
            if(array2[j].character==data[i])
            {
                
                for(k=0;k<=7;k++)
                {
                    
                    asciidata[size99]=array2[j].symbol[k];
                    size99++;
                    
                }
                
                break;
                
            }
        }
    }
    
}
