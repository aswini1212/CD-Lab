#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
int iskeyword(char str[])
{
    char arr[11][10]={"int","void","main","char","float","do","while","if","else","for","break","continue"};
    for(int i=0;i<11;i++)
    {
        if(strcmp(arr[i],str)==0)
        {
            return 1;
        }
    }
    return 0;
}
void main()
{
    FILE *fp=fopen("input.txt","r");
    char c,buffer[10],operators[7]="+-*/%=",separator[7]="(){},;";
    int k=0;
    while((c=fgetc(fp))!=EOF)
    {
        for(int i=0;i<strlen(operators);i++)
        {
            if(operators[i]==c)
            {
                printf("OPERATOR:%c\n",c);
            }

        }
        for(int j=0;j<strlen(separator);j++)
        {
            if(separator[j]==c)
            {
                printf("SEPARATOR:%c\n",c);
            }

        }
        if(isalnum(c))
        {
            buffer[k]=c;
            k++;
        }
        if(c==' '||c=='\t'||c=='\n')
        {
            buffer[k]='\0';
            if(strlen(buffer)==0)
            {
                continue;
            }
            if(iskeyword(buffer))
            {
                printf("KEYWORD:%s\n",buffer);
            }
            else
            {
                printf("IDENTIFIER:%s\n",buffer);
            }
            k=0;
        }
    }
}