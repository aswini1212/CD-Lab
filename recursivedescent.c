#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct ProductionRule
{
    char symbol;
    char expression[20];
    struct ProductionRule *next;
}ProductionRule;

typedef struct Grammar
{
    char start;
    int nump;
    ProductionRule *pr;
}Grammar;

Grammar g;
char input[50];

void read_grammar()
{
    char st;
    printf("Enter the start state:");
    scanf("%c",&(g.start));

    printf("Enter the no of productions:");
    scanf("%d",&(g.nump));

    char lhs,rhs[20];
    printf("Enter the productions:");
    for(int i=0;i<g.nump;i++)
    {
        scanf(" %c->%s",&lhs,rhs);
        ProductionRule *rule=(ProductionRule*)malloc(sizeof(ProductionRule));
        rule->symbol=lhs;
        strcpy(rule->expression,rhs);
        rule->next=g.pr;
        g.pr=rule;
    }
}

void print(char expansion[50],int expindex)
{
    printf("%.*s[%c]%s\t",expindex,expansion,expansion[expindex],expansion+expindex+1);
}
bool parse(char expansion[50],int expindex,char input[50],int inpindex)
{
    if(strlen(expansion)==expindex)
    {
        if(strcmp(expansion,input)==0)
        {
            return true;
        }
    }

    if(expansion[expindex]==input[inpindex])
    {
        print(expansion,expindex);
        printf("[%c matches with input]\n",expansion[expindex]);
        return parse(expansion,expindex+1,input,inpindex+1);
    }

    if(expansion[expindex]<'A'||expansion[expindex]>'Z')
    {
        print(expansion,expindex);
        printf("[%c mismatched with input]\n",expansion[expindex]);
        return false;
    }
    char nt=expansion[expindex];
    char temp[50];
    strcpy(temp,expansion);
    expansion[expindex]='\0';

    ProductionRule *rule=g.pr;
    while(rule)
    {
        if(nt==rule->symbol)
        {
            print(temp,expindex);
            printf("Expand:%c->%s\n",rule->symbol,rule->expression);
            
            strcat(expansion,rule->expression);
            strcat(expansion,temp+expindex+1);

            bool success=parse(expansion,expindex,input,inpindex);
            if(success)
            {
                return true;
            }
            printf("\n=====BACKTRACK=====\n");
            strcpy(expansion,temp);
            expansion[expindex]='\0';
        }
        rule=rule->next;
    }
    return false;

}

void main()
{
    read_grammar();
    char expansion[50];
    printf("Enter the input string:");
    scanf("%s",input);
    expansion[0]=g.start;
    expansion[1]='\0';

    bool final=parse(expansion,0,input,0);
    if(final)
    {
        printf("\nString is accepted\n");
    }
    else
    {
        printf("\nThe string is rejecetd\n");
    }

}