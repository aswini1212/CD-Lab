%{
    #include "while_loop.tab.h"
%}
%%
"while" {return WHILE;}
[a-zA-Z]+ {return ALPHA;}
[0-9]+ {return DIGIT;}
"="|"<"|">"|"<="|">="|"==" {return RELOP;}
\n {return '\n';}
. {return yytext[0];}
%%
int yywrap()
{
    return 1;
}