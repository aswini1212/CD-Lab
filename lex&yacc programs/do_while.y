%{
    #include<stdio.h>
    void yyerror(const char *str);
    int yylex();
%}

%token DO WHILE ID RELOP DIGIT SEMI

%%
input: DO '{' '}' WHILE '(' cond ')' SEMI {printf("Valid\n");}
;

cond: ID RELOP ID
    | ID RELOP DIGIT
    ;
%%

int main()
{
    printf("Enter the syntax:");
    yyparse();
    return 0;
}
void yyerror(const char *str)
{
    printf("Invalid\n");
}