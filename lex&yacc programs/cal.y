%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex();
    void yyerror(const char *str);
%}

%union{
    int num;
}

%token <num> DIGIT 
%type <num> exprn


%left '+' '-'
%left '*' '/'
%right UMINUS

%%
input:
    
     | input line
    ;
line:
    '\n'
    | exprn '\n' {printf("Result:%d\n",$1);}
    ;
exprn: DIGIT {$$=$1;}
    | exprn '+' exprn {$$=$1+$3;}
    | exprn '-' exprn {$$=$1-$3;}
    | exprn '*' exprn {$$=$1*$3;}
    | exprn '/' exprn {$$=$1/$3;}
    | '-' exprn %prec UMINUS {$$=-$2;}
    | '(' exprn ')' {$$=$2;}
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
    printf("An error occured\n");
}