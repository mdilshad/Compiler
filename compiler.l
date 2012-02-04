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
"%"				return *yytext;
"&"				return *yytext;
"["				return *yytext;
"]"				return *yytext;
"main"			return MAIN;
"read"         return READ;
"write"        return WRITE;
"begin"			return BGIN;
"end"				return END;
"if"				return IF;
"else"			return ELSE;
"endif"			return ENDIF;
"then"			return THEN;
"while"			return WHILE;
"do"				return DO;
"endwhile"		return ENDWHILE;
"return"			return RETURN;
"decl"			return DECL;
"enddecl"		return ENDDECL;
"integer"		return INTEGER;
"boolean"		return BOOLEAN;
"true"         return TRU;
"false"        return FALS;
"OR"           return OR;
"AND"          return AND;
"NOT"          return NOT;
"=="           return EQ;
"!="				return NE;
"<"            return LT;
">"				return GT;
">="           return GE;
"<="				return LE;

            
[a-zA-Z]([a-zA-Z]|[0-9])*    { yylval.chp = malloc(strlen(yytext));
											strcpy(yylval.chp,yytext);
               						return VARIABLE;   }
               
[-+*/=();,{}]      return *yytext;
[\n]			{}
[ \t] 
.           yyerror("Please enter valid character");
%%
int yywrap(void) {
    return 1;
}

