%{
    #include<stdio.h>
    #include<stdlib.h>

%}
%%
[0-9]+"."[0-9]+ {printf("valid\n");}
\n {return 0;}
. {printf("Invalid\n");return 0;}
%%
int main()
{
    printf("Enter the number:");
    yylex();
    return 0;
}
int yywrap()
{
    return 1;
}