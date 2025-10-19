%{
    #include<stdio.h>
    #include<string.h>
    int yylex();
    void yyerror(const char *str);
%}
%union{
    char *str;
}

%token <str> VALID INVALID
%type <str> line
%%
input:
     | input line
     ;
line: VALID '\n' {printf("Valid:%s\n",$1);}
    | INVALID '\n' {printf("Invalid:%s\n",$1);}
    ;
%%
int main()
{
    printf("Enter the identifier:");
    yyparse();
    return 0;
}
void yyerror(const char *str)
{
    printf("Invalid\n");
}