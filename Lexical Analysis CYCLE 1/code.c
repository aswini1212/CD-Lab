#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int iskeyword(char buffer[10])
{
    char arr[32][10]={"int","char","float","double","void","break","continue","if","else","goto","while","do","for"};
    for(int i=0;i<13;i++)
    {
        if(strcmp(buffer,arr[i])==0)
        {
            return 1;
        }

    }
    return 0;
}
int main()
{
    FILE *fp=fopen("input.txt","r");
    char operator[6]="+-*/%=",c;
    char buffer[10];
    int i,j=0;
    if(fp==NULL)
    {
        printf("Error in opening the file\n");
        exit(0);
    }
    while((c=fgetc(fp))!=EOF)
    {
        for(i=0;i<6;i++)
        {
            if(operator[i]==c)
            {
                printf("Operator:%c\n",c);
            }
        }
        if(isalnum(c))
        {
            buffer[j]=c;
            j++;
        }
        else if((c==' '||c=='\n'||c=='\t')&&(j!=0))
        {
            buffer[j]='\0';
            if(iskeyword(buffer)==1)
            {
                printf("Keyword:%s\n",buffer);
            }
            else
            {
                printf("identifier:%s\n",buffer);
            }
            j=0;
        }
    }
    fclose(fp);
    return 0;
}