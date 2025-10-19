%{
    #include<stdio.h>
    #include<string.h>
    int arr[26]={0};
    char ch;
%}
%%
[a-zA-Z] {  char ch=yytext[0];
            if(ch>='A' && ch<='Z')
            {
                ch=ch+32;
            }   
            arr[ch-97]++; 
        }
" "|\t {}
\n {return 0;}
%%
int main()
{
    printf("Enter the string:");
    yylex();
    for(int i=0;i<26;i++)
    {
        if(arr[i]!=0)
        {
            printf("%c-->%d\n",97+i,arr[i]);
        }
    }
    return 0;
}
int yywrap()
{
    return 1;
}