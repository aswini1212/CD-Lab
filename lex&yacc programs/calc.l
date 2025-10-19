%{
    #include "calc.tab.h"
    #include<stdlib.h>
%}
%%
[0-9]+ {yylval.num=atoi(yytext); return DIGIT;}
[+\-*/] {return yytext[0];}
[()] {return yytext[0];}
\n {return '\n';}
%%
int yywrap()
{
    return 1;
}