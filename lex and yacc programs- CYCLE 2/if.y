%{
    #include<stdio.h>
    int yylex();
    void yyerror(const char *str);
%}
%token IF ALPHA DIGIT RELOP ELSE ELSEIF
%%
input: IF '(' cond ')''{''}''\n' ELSEIF '(' cond ')''{''}''\n' ELSE '{''}''\n' {printf("Valid Syntax\n");}
    ;
cond : ALPHA RELOP ALPHA
    | ALPHA RELOP DIGIT
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
    printf("Invalid sntax\n");
}