#include<stdio.h>
#include<stdlib.h>

char data[32];
char checkValue[28];
char crckey[10];
int dataLength;

void xor(){
    for(int j=1;j<strlen(crckey);j++)
    checkValue[j]=checkValue[j]==crckey[j]?'0':'1';
}
void crc(){
    printf("\n");

    int i;
    for(i=0;i<strlen(crckey);i++)
    checkValue[i]=data[i];
    do{
        if(checkValue[0]=='1')
        xor();
        int j;
        for(j=0;j<strlen(crckey)-1;j++)
        checkValue[j]=checkValue[j+1];
        checkValue[j]=data[i++];
        printf("Check value:%s\n",checkValue);
    }while(i<=dataLength+strlen(crckey)-1);
    printf("\n");
}

int main(){
    while(1){
        printf("Choose one of the options:\n");
        printf("1.Set CRC Key.\n");
        printf("2.Generate CRC key from data.\n");
        printf("3.Check validity of data.\n");
        printf("4.Exit from the program.\n");
        printf("\n");
        printf("Choose your option:");

        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter CRC key:");
            scanf("%s",crckey);
            break;
            case 2:
            printf("Enter data:");
            scanf("%s",data);
            dataLength=strlen(data);
            for(int i=0;i<strlen(crckey)-1;i++)
            data[i+dataLength]='0';
            printf("Data after appending zeros:%s\n",data);
            crc();
            printf("CRC Value:%s\n",checkValue);
            for(int i=0;i<strlen(crckey)-1;i++)
            data[i+dataLength]=checkValue[i];
            printf("Data sent:%s\n",data);
            break;
            case 3:
             printf("Enter data to check:");
             scanf("%s",data);
             crc();
             int i;
             for(i=0;(i<strlen(crckey)-1)&& (checkValue[i]!='1');i++);
             if(i<strlen(crckey)-1)
             printf("Error detected!\n");
             else
             printf("No error detected\n");
             break;
             case 4:
             return 0;
             default:
             printf("Invalid option selected");
        }
        printf("\n\n");
    }
    return 0;
}


// Input
/*
1
101
2
110101
3
011010111
3
011010110
4
*/

/*
gcc crc.c
./a.out
*/
