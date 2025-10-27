#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char postfix[100];
char stack[100],stack1[50][50];
int top=-1,top1=-1,tcount=0;

void push(char inp)
{
    top++;
    stack[top]=inp;
}

char pop()
{
    if(top!=-1)
    {
        char c=stack[top];
        top--;
        return c;
    }
}
char peek()
{
    if(top!=-1)
    {
        return stack[top];
    }
}
int prec(char inp)
{
    if(inp=='+'||inp=='-') return 1;
    else if(inp=='*'||inp=='/') return 2;

}
void infixtopostfix(char infix[100],char postfix[100])
{
    int k=0;
    for(int i=0;i<strlen(infix);i++)
    {
        if(isalnum(infix[i]))
        {
            postfix[k]=infix[i];
            k++;
        }
        else if(infix[i]=='(')
        {
            push(infix[i]);
        }
        else if(infix[i]==')')
        {
            while(top!=-1 && peek()!='(')
            {
                postfix[k]=pop();
                k++;
            }
            pop();
        }
        else
        {
            while(top!=-1 && prec(peek())>=prec(infix[i])&&peek()!='(')
            {
                postfix[k]=pop();
                k++;
            }
            push(infix[i]);
        }
    }
    while(top!=-1)
    {
        postfix[k]=pop();
        k++;
    }
    postfix[k]='\0';
}
void push1(char str[100])
{
    top1++;
    strcpy(stack1[top1],str);
}
char* pop1()
{
    if(top1!=-1)
    {
        return stack1[top1--];
        
    }
}
char* peek1()
{
    return stack1[top1];
}

void converttoTAC(char postfix[100],char lhs)
{
    char op2[100],op1[100],temp[100];
    for(int i=0;i<strlen(postfix);i++)
    {
        if(isalnum(postfix[i]))
        {
            char s[100]={postfix[i],'\0'};
            push1(s);
        }
        else
        {
            strcpy(op2,pop1());
            strcpy(op1,pop1());
            sprintf(temp,"t%d",tcount++);
            printf("%s = %s %c %s\n",temp,op1,postfix[i],op2);
            push1(temp);
        }
    }
    printf("%c = %s\n",lhs,peek1());
}

void main()
{
    char lhs,rhs[100];
    printf("Enter the infix expression(x=a+b*c):");
    scanf(" %c=%s",&lhs,rhs);

    infixtopostfix(rhs,postfix);
    printf("Postfix Expression: %s\n",postfix);

    converttoTAC(postfix,lhs);
}