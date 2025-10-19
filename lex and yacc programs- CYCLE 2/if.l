%{
    #include "if.tab.h"
%}
%%
"if" {return IF;}
"else" {return ELSE;}
"elseif" {return ELSEIF;}
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