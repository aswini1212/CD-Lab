%{
    #include<stdio.h>
    int lines=0;
    int words=0;
    int c=0;
%}
%%
\n {++lines;
    words++; }
" " {++words;}
. {++c;}
%%
void main()
{
    printf("Enter the text:");
    yylex();
    printf("The no of characters are:%d\n",c);
    printf("The no of words are:%d\n",words);
    printf("The no of lines are:%d\n",lines);
}
int yywrap()
{
    return 1;
}