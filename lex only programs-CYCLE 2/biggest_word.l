%{
    #include<stdio.h>
    #include<string.h>
    int maxlen=0;
    char word[100][100];
    int i=0;
%}
%%
[a-zA-Z]+ {if(strlen(yytext)>=maxlen)
            {
                strcpy(word[i],yytext);
                maxlen=strlen(yytext);
                i++;
            }
          }
\n {return 0;}
%%
int main()
{
    printf("Enter the text:")'
    yylex()'
    printf("The length of the biggest word is:%d\n",maxlen);
    printf("The biggest word/words are:\n");
    for(int j=0;j<10;j++)
    {
        if(strlen(word[j])==maxlen)
        {
            printf("%s\n",word[j]);
        }
    }

}
int yywrap()
{
    return 1;
}