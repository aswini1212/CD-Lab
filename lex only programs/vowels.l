%{
    #include<stdio.h>
    int vow=0;
    int con=0;
%}
%%
[aeiouAEIOU] {vow++;}
[a-zA-Z]    {con++;}
\n {return 0;}
%%
int main()
{
    printf("Enter the string:");
    yylex();
    printf("The no of vowels are:%d\n",vow);
    printf("The no of consonants are:%d\n",con);
    return 0;
}
int yywrap()
{
    return 1;
}