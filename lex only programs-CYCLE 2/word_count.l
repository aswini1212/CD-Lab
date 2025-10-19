%{
    #include<stdio.h>
    #include<string.h>
    char str[100];
    int count=0;
%}
%%
[a-zA-Z]+ {if(strcmp(str,yytext)==0)
            {
                count++;
            }
            }
\n {return 0;}
%%
int main()
{
    printf("Enter the word:");
    scanf("%[^\n]",str);
    getchar();
    printf("Enter the string:");
    yylex();
    printf("The count is:%d\n",count);
    return 0;
}
int yywrap()
{
    return 1;
}
