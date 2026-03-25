/* recognize tokens for the calculator */

%{
#include "token.h"
%}

DIGIT    [0-9]
NUM      {DIGIT}+(\.{DIGIT}+)?

%%

{NUM}       { return NUM; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return TIMES; }
"/"         { return DIV; }
"\n"        { return EOL; }
[ \t]+      { /* ignora espaços e tabs */ }
.           { return ERROR; }

%%

int yywrap() {
    return 1;
}
