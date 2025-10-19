%{
    #include "ast1.h"
    #include "abstract1.tab.h"
    #include<stdlib.h>
%}
%%
[0-9]+ {yylval.num=atoi(yytext); return NUMBER;}
[+\-*/()] {return yytext[0];}
\n {return '\n';}
%%
int yywrap()
{
    return 1;
}