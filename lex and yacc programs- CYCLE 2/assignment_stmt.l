%{
    #include "assignment_stmt.tab.h"
%}
%%
[a-zA-Z] {return ALPHA;}
[0-9]+ {return DIGIT;}
[+\-*/();] {return yytext[0];}
. {return yytext[0];}
\n {return '\n';}
%%
int yywrap()
{
    return 1;
}