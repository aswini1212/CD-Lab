#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
    char stack[50],inp[50],opt[10][10][2],ter[10];
    int top=-1,col=-1,row=-1,n;

    for(int i=0;i<50;i++)
    {
        stack[i]='\0';
        inp[i]='\0';
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            opt[i][j][0]='\0';
        }
    }
    printf("Enter the no of terminals:");
    scanf("%d",&n);
    printf("Enter the terminals as string:");
    scanf("%s",ter);

    printf("Enter the table values:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Enter the value of %c %c:",ter[i],ter[j]);
            scanf(" %c",&opt[i][j][0]);
        }
    }

    printf("__OPERATOR PRECEDENCE TABLE__\n");
    for(int i=0;i<n;i++)
    {
        printf("\t%c",ter[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%c\t",ter[i]);
        for(int j=0;j<n;j++)
        {
            printf("%c\t",opt[i][j][0]);
        }
        printf("\n");
    }
    printf("Enter the input string with $ at end:");
    scanf("%s",inp);
    top++;
    stack[top]='$';
    printf("STACK\t\tINPUT\t\tACTION\n");
    for(int k=0;k<=top;k++)
    {
        printf("%c",stack[k]);
    }
    printf("\t\t");
    printf("%s",inp);

    int i=0;
    while(i<=strlen(inp))
    {
        row=-1,col=-1;
        for(int k=0;k<n;k++)
        {
            if(stack[top]==ter[k])
            {
                row=k;
            }
            else if(ter[k]==inp[i])
            {
                col=k;
            }
        }

        if(opt[row][col][0]=='<'||opt[row][col]=="=")
        {
            top++;
            stack[top]='<';
            top++;
            stack[top]=inp[i];
            i++;
            printf("Shift\n");
        }
        else if(opt[row][col][0]=='>')
        {
            while(top>0&&stack[top]!='<')
            {
                top--;
            }
            top--;
            printf("Reduce\n");
        }
        else if(row==-1 && col==-1)
        {
            printf("Invalid input\n");
            break;
        }
        else if(stack[top]=='$'&&inp[i]=='$')
        {
            printf("Accepted\n");
            break;
        }
        else 
        {
            printf("Rejected\n");
            break;
        }
        for(int k=0;k<=top;k++)
        {
            printf("%c",stack[k]);
        }
        printf("\t\t");
        for(int j=i;j<strlen(inp);j++)
        {
            printf("%c",inp[j]);
        }
        printf("\t\t");
    } 



}