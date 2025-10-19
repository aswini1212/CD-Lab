%{
    #include<stdio.h>
    #include<string.h>
    #include<math.h>
    int yylex();
    void yyerror (const char *str);
    int dec;
    int bit;
%}
%union{char *str;}
%token <str> BINARY
%%
input: BINARY'\n' {
                    dec=0;
                    int len=strlen($1);
                    for(int i=len-1;i>=0;i--)
                    {
                        bit=$1[i]-'0';
                        dec+=bit*pow(2,len-i-1);
                    }
                    printf("%d\n",dec);
                  }
        ;
%%
int main()
{
    printf("Enter the binary string:");
    yyparse();
    return 0;
}          
void yyerror(const char *str)
{
    printf("An error occured\n");
}