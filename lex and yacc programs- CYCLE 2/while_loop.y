%{
    #include<stdio.h>
    void yyerror(const char *str);
    int yylex();
%}

%token WHILE RELOP SEMI DIGIT ID

%%
input: WHILE '(' condition ')' '{' '}'  {printf("Valid\n");}
;
condition : ID RELOP ID
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