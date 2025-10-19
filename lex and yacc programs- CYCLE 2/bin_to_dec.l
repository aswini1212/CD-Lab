%{
    #include "bin_to_dec.tab.h"
    #include<string.h>
%}
%%
[0-1]+ {yylval.str=strdup(yytext);return BINARY;}
\n {return '\n';}
%%
int yywrap()
{
    return 1;
}