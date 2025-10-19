%{
    #include<stdio.h>
    #include<string.h>
    #include "ast1.h"
    int yylex();
    void yyerror(const char *str);
%}
%union{
    int num;
    Node* node;
}

%token <num> NUMBER
%type <node> exprn

%left '+' '-'
%left '*' '/'
%right UMINUS

%%
input:

    |input line 
    ;

line: '\n'
    |exprn '\n' {PrintNode($1);}
    ;
exprn: NUMBER {$$=makenum($1);}
    | exprn '+' exprn {$$=makeop("+",$1,$3);}
    | exprn '-' exprn {$$=makeop("-",$1,$3);}
    | exprn '*' exprn {$$=makeop("*",$1,$3);}
    | exprn '/' exprn {$$=makeop("/",$1,$3);}
    | '-' exprn %prec UMINUS {$$=makeop("-",$2,NULL);}
    | '('exprn')' {$$=$2;}
    ;
%%
int main()
{
    printf("Enter the expression:");
    yyparse();
    return 0;
}
void yyerror(const char *str)
{
    printf("Invalid\n");
}
Node* makenum(int value)
{
    Node *newnode=malloc(sizeof(Node));
    newnode->operator=NULL;
    newnode->left=newnode->right=NULL;
    newnode->num=value;
    return newnode;
}
Node* makeop(char *op,Node *l,Node *r)
{
    Node *newnode=malloc(sizeof(Node));
    newnode->num=0;
    newnode->operator=strdup(op);
    newnode->left=l;
    newnode->right=r;
    return newnode;
}
void PrintNode(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->operator!=NULL)
        printf("%s",root->operator);
    else
        printf("%d",root->num);
    PrintNode(root->left);
    PrintNode(root->right);    
}