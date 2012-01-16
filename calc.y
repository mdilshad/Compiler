%{
    int yylex(void);
    int yyerror(char *);
    #include<stdio.h>
    #include"Function.h"
   int i,expval;
   Tnode *temp1,*temp2;
   extern FILE *yyin;
%}
%union
{
	int Num;
	char ch;
	struct tnode* Node;
};
%token <Num> DIGIT
%type <Node> E SList SB BE SA S1 SDecl
%token <ch> VARIABLE
%token READ WRITE BGIN END DECL ENDDECL INTEGER AND OR NOT GT GE LT LE EQ NE FALS TRU
%right '='
%left '+' '-' 
%left '*' '/' 

%%

S:DECL '\n' SDecl ENDDECL '\n' BGIN '\n' SB  END '\n' {Traverse($8);};


SDecl:SA		{Traverse($1);};


SA:INTEGER VARIABLE S1 SA		{
								temp1=TreeCreate(Integer,0,0,$2,NULL,NULL,NULL,NULL,Decl);
								temp2=TreeCreate(Integer,0,0,'\0',NULL,temp1,$3,NULL,Continue);
								$$=TreeCreate(Integer,0,0,'\0',NULL,temp2,$4,NULL,Continue);};

	| INTEGER VARIABLE '[' DIGIT ']' S1 SA {
										temp1=TreeCreate(Integer,0,$2,$4,NULL,NULL,NULL,NULL,Array);
										temp2=TreeCreate(Integer,0,0,'\0',NULL,temp1,$6,NULL,Continue);
										$$=TreeCreate(Integer,0,0,'\0',NULL,temp2,$7,NULL,Continue);};

	|							{ $$ = NULL; };

S1: ',' VARIABLE S1				{
									temp1=TreeCreate(Integer,0,0,$2,NULL,NULL,NULL,NULL,Decl);
									$$=TreeCreate(Integer,0,0,'\0',NULL,temp1,$3,NULL,Continue);};

	| ',' VARIABLE '[' DIGIT ']' S1 {
									temp1=TreeCreate(Integer,0,$2,$4,NULL,NULL,NULL,NULL,Array);
									$$=TreeCreate(Integer,0,0,'\0',NULL,temp1,$6,NULL,Continue);};

	| ';' '\n' 			{$$ = NULL; };



SB: SList SB		{ $$ = TreeCreate(0,0,0,'\0',NULL,$1,$2,NULL,Continue); };

	|				{$$ = NULL;};
	
	


SList: 	READ '(' VARIABLE ')' ';' '\n'    	{ $$ = TreeCreate(0,0,0,$3,NULL,NULL,NULL,NULL,Read); };
							
	|WRITE '(' E ')' ';' '\n'   { $$ = TreeCreate(Integer,0,0,0,NULL,$3,NULL,NULL,Write); };
							
	|WRITE '(' BE ')' ';' '\n'  { $$ = TreeCreate(Boolean,0,0,0,NULL,$3,NULL,NULL,Write);};
	
	|VARIABLE '=' E ';''\n' 	{ $$ = TreeCreate(0,0,0,$1,NULL,NULL,$3,NULL,Initialize); };
	
	


E:	DIGIT  		{ $$ = TreeCreate(Integer,0,$1,'\0',NULL,NULL,NULL,NULL,Digit); };

	|E '+' E     	{ $$ = TreeCreate(Integer,0,0,'\0',NULL,$1,$3,NULL,Addition); }; 

	|E '-' E     	{ $$ = TreeCreate(Integer,0,0,'\0',NULL,$1,$3,NULL,Subtraction); };

	|E '*' E     	{ $$ = TreeCreate(Integer,0,0,'\0',NULL,$1,$3,NULL,Multiplacation); };

	|E '/' E 	{ $$ = TreeCreate(Integer,0,0,'\0',NULL,$1,$3,NULL,Division); };

	|'(' E ')'	{ $$ = $2; };

	|VARIABLE 	 { $$ = TreeCreate(Integer,0,0,$1,NULL,NULL,NULL,NULL,Variable); };
	
	


BE:	DIGIT  		{ $$ = TreeCreate(0,0,$1,'\0',NULL,NULL,NULL,NULL,Digit); };

	|BE AND BE     	{ $$ = TreeCreate(0,0,0,'\0',NULL,$1,$3,NULL,And); }; 

	|BE OR BE     	{ $$ = TreeCreate(0,0,0,'\0',NULL,$1,$3,NULL,Or); };

	|NOT BE     	{ $$ = TreeCreate(0,0,0,'\0',NULL,$2,NULL,NULL,Not); };

	|BE GT BE 	{ $$ = TreeCreate(0,0,0,'\0',NULL,$1,$3,NULL,GreaterThen); };
	
	|BE GE BE 	{ $$ = TreeCreate(0,0,0,'\0',NULL,$1,$3,NULL,GreaterThenEqual); };
	
	|BE LT BE 	{ $$ = TreeCreate(0,0,0,'\0',NULL,$1,$3,NULL,LessThen); };
	
	|BE LE BE 	{ $$ = TreeCreate(0,0,0,'\0',NULL,$1,$3,NULL,LessThenEqual); };
	
	|BE EQ BE 	{ $$ = TreeCreate(0,0,0,'\0',NULL,$1,$3,NULL,Equal); };
	
	|BE NE BE 	{ $$ = TreeCreate(0,0,0,'\0',NULL,$1,$3,NULL,NotEqual); };
	
	|TRU 	{ $$ = TreeCreate(0,0,0,'\0',NULL,NULL,NULL,NULL,True); };
	
	|FALS 	{ $$ = TreeCreate(0,0,0,'\0',NULL,NULL,NULL,NULL,False); };

	|'(' BE ')'	{ $$ = $2; };

	|VARIABLE 	 { $$ = TreeCreate(0,0,0,$1,NULL,NULL,NULL,NULL,Variable); };



%%

int yyerror(char *s) 
{
	fprintf(stderr, "%s\n", s);
	return 1;
}

int main(int argc,char **argv) 
{
	yyin=fopen(argv[1],"r");
  	yyparse();
	fclose(yyin);
	return 1;
}
