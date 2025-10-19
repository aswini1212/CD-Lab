%{
    #include "do_while.tab.h"
%}
%%
"do" {return DO;}
"while" {return WHILE;}
[a-zA-Z][a-zA-Z]* {return ID;}
"<"|">"|"="|"<="|">="|"==" {return RELOP;}
[0-9]+ {return DIGIT;}
";" {return SEMI;}
. {return yytext[0];}
\n|" " {}
%%
int yywrap()
{
    return 1;
}