%{
    #include<stdio.h>
    
%}
%%
"void"|"int"|"main"|"char" {printf("Keyword:%s\n",yytext);}
[_a-zA-Z0][_a-zA-Z0-9]* {printf("Identifier:%s\n",yytext);}
[,;(){}] {printf("Separator:%s\n",yytext);}
[+\-*/=] {printf("Operator:%s\n",yytext);}
\n {return 0;}
%%
int main()
{
    printf("Enter the string:");
    yylex();
    
    return 0;
}
int yywrap()
{
    return 1;
}