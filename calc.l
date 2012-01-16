%{
#include <stdlib.h>
#include<malloc.h>
int yyerror(char *);
#include "y.tab.h"
%}
%%
[0-9]+      {
                yylval.Num = atoi(yytext);
                return DIGIT;
            }
"["				return *yytext;
"]"				return *yytext;
"read"          return READ;
"write"         return WRITE;
"begin"			return BGIN;
"end"			return END;
"decl"			return DECL;
"enddecl"		return ENDDECL;
"integer"		return INTEGER;
"true"          return TRU;
"false"         return FALS;
"OR"            return OR;
"AND"           return AND;
"NOT"           return NOT;
"=="            return EQ;
"!="			return NE;
"<"             return LT;
">"				return GT;
">="            return GE;
"<="			return LT;


[a-z]        { yylval.ch = yytext[0];
               return VARIABLE;
	     }
[-+*/=();,\n]      return *yytext;
[ \t] 
.           yyerror("Please enter valid character");
%%
int yywrap(void) {
    return 1;
}

