%{
    #include<stdio.h>
    int count=0;
%}
%%
[+\-*/] {count++;}
. {}
\n {return 0;}

%%
int main()
{
    printf("Enter the expression:");
    yylex();
    printf("The count is:%d",count);
    return 0;
}
int yywrap()
{
    return 1;
}