%{
    #include "valid_identifier.tab.h"
    #include<string.h>
%}
%%
[a-zA-Z][a-zA-Z0-9]* {yylval.str=strdup(yytext); return VALID;}
[0-9][a-zA-Z0-9]* {yylval.str=strdup(yytext);return INVALID;}
\n {return '\n';}
%%
int yywrap()
{
    return 1;
}