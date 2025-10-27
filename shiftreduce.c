#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char symbol;
    char expression[20];
}ProductionRule;

typedef struct
{
    char start;
    int nump;
    ProductionRule rules[20];
}Grammar;

typedef struct Stack
{
    char symbol;
    struct Stack *next;
}Stack;

Grammar g;
Stack *outputstack=NULL,*inputstack=NULL;
char input[20];
void read_grammar()
{
    char sta;
    printf("Enter the starting state:");
    scanf("%c",&sta);
    g.start=sta;

    printf("Enter the no of productions:");
    scanf("%d",&(g.nump));

    char lhs,rhs[20];
    printf("Enter the productions:\n");
    for(int i=0;i<g.nump;i++)
    {
        scanf(" %c->%s",&lhs,rhs);
        g.rules[i].symbol=lhs;
        strcpy(g.rules[i].expression,rhs);
    }

}
Stack* push(Stack *st,char inp)
{
    Stack *node=(Stack*)malloc(sizeof(Stack));
    node->symbol=inp;
    node->next=st;
    return node;
}
char pop(Stack *st)
{
    if(st)
    {
        char symbol=st->symbol;
        return symbol;
    }
    return '$';
}
void printstack(Stack *st)
{
    while(st)
    {
        printf("%c",st->symbol);
        st=st->next;
    }
    printf("\t\t");
}
int shift()
{
    if(inputstack)
    {
        char symbol = pop(inputstack);
        outputstack = push(outputstack, symbol);
        inputstack = inputstack->next;
        printf("$");
        printstack(outputstack);
        printstack(inputstack);
        
        printf("$");
        printf("SHIFT\n");
        return 1;
    }
    if(!inputstack)
    {
        printf("$");
    }
    return 0;
}
int reduce()
{
    for(int i=0;i<g.nump;i++)
    {
        ProductionRule rule=g.rules[i];
        Stack *ptr=outputstack;
        int flag=1;
        int len=strlen(rule.expression);

        for(int i=len-1;i>=0;i--)
        {
            if(ptr==NULL||ptr->symbol!=rule.expression[i])
            {
                flag=0;
                break;
            }
            ptr=ptr->next;
        }
        if(flag==0) continue;

        printf("$");
        printstack(outputstack);
        printstack(inputstack);
        printf("$");
        printf("REDUCE(%c->%s)\n",rule.symbol,rule.expression);
        for(int k=0;k<len;k++)
        {
            pop(outputstack);
            outputstack=outputstack->next;
        }
        outputstack=push(outputstack,rule.symbol);
        return 1;
    }
    
    return 0;
    
}
void parse()
{
    for(int j=strlen(input)-1;j>=0;j--)
    {
        inputstack=push(inputstack,input[j]);
    }
    printf("OUTPUT\t\tINPUT\t\tACTION\n");
    while(1)
    {
        if(reduce()) continue;
        if(shift()) continue;
        if(inputstack==NULL&&outputstack!=NULL&&outputstack->symbol==g.start)
        {
            printf("$");
            printstack(outputstack);
            printstack(inputstack);
            printf("$");
            printf("ACCEPTED\n");
            break;
        }
        else
        {
            printf("$");
            printstack(outputstack);
            printstack(inputstack);
            printf("$");
            printf("\tREJECTED\n");
            break;
        }
    }
}

void main()
{
    read_grammar();
    printf("Enter the string:");
    scanf("%s",input);
    parse();
}