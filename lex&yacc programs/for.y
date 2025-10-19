%{
    #include<stdio.h>
    int yylex();
    void yyerror(const char *str);
%}

%token FOR ALPHA DIGIT RELOP INCDEC

%%
input:
    | input line
    ;
line: FOR '(' init ';' cond ';' upd ')''{''}''\n' {printf("Valid Syntax\n");}
    ;
init: ALPHA '=' ALPHA
    | ALPHA '=' DIGIT
    ;
cond: ALPHA RELOP ALPHA
    | ALPHA RELOP DIGIT
    ;
upd: ALPHA INCDEC
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
    printf("Invalid Syntax\n");
}