%{
    #include<stdio.h>
    int yylex();
    void yyerror(const char *str);
%}
%token ALPHA DIGIT

%left '+' '-'
%left '*' '/'

%%
input: 
    |input line
    ;
line: ALPHA '=' exprn ';''\n' {printf("Valid assignment\n");}
    ;
exprn: ALPHA
    |DIGIT  
    | exprn '+' exprn
    | exprn '-' exprn
    | exprn '*' exprn
    | exprn '/' exprn
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
    printf("An error occured");
}