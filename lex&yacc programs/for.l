%{
    #include "for.tab.h"
%}
%%
"for" {return FOR;}
[a-zA-Z] {return ALPHA;}
"<"|">"|">="|"<="|"==" {return RELOP;}
[0-9]+ {return DIGIT;}
"++"|"--" {return INCDEC;}
. {return yytext[0];}
\n {return '\n';}
%%
int yywrap()
{
    return 1;
}