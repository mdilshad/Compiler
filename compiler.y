%{
    int yylex(void);
    int yyerror(char *);
    #include<stdio.h>
    #include"Action.h"
   int i,expval;
   extern FILE *yyin;
   extern int n;
%}
%union
{
	int Num;
	char ch,*chp;
	struct tnode* Node;
};
%token <Num> DIGIT
%token <chp> VARIABLE
%type <Node> E SList Statement DStatement DStateInt DStateBool Rstat Func ParaList Parameter Args ArgsInt ArgsBool ArgEnd ElseStmt GDStatement GDStateInt GDStateBool
%token READ WRITE BGIN END DECL ENDDECL INTEGER BOOLEAN AND OR NOT GT GE LT LE EQ NE FALS TRU IF ELSE THEN ENDIF WHILE DO ENDWHILE RETURN MAIN
%right '='
%left '+' '-' 
%left '%'
%left '*' '/' 
%left AND OR EQ NQ LT LE GE GT
%right NOT
%%

//############################### START CFG ############################################################

Program : DECL  GDStatement ENDDECL  Func		{Compile($2,$4); };

//############################### GLOBEL DECL STATEMENTS ENDDECL ####################################################


GDStatement:INTEGER VARIABLE GDStateInt GDStatement		{
								temp1 = TreeCreate(Integer,1,$2,NULL,NULL,NULL,NULL,Decl);
								$$=TreeCreate(Integer,0,'\0',NULL,temp1,$3,$4,Continue);};

	|INTEGER VARIABLE '[' DIGIT ']' GDStateInt GDStatement {
										temp1 = TreeCreate(Integer,$4,$2,NULL,NULL,NULL,NULL,Array);
										$$=TreeCreate(Integer,0,'\0',NULL,temp1,$6,$7,Continue);};
										
	|INTEGER VARIABLE '(' Args ')' GDStateInt GDStatement		{
								temp1 = TreeCreate(Integer,0,$2,$4,NULL,NULL,NULL,FunctionDecl);
								$$=TreeCreate(Integer,0,'\0',NULL,temp1,$6,$7,Continue);};
										
	|BOOLEAN VARIABLE GDStateBool GDStatement		{
								temp1 = TreeCreate(Boolean,1,$2,NULL,NULL,NULL,NULL,Decl);
								$$=TreeCreate(Boolean,0,'\0',NULL,temp1,$3,$4,Continue);};

	|BOOLEAN VARIABLE '[' DIGIT ']' GDStateBool GDStatement {
										temp1 = TreeCreate(Boolean,$4,$2,NULL,NULL,NULL,NULL,Array);
										$$=TreeCreate(Boolean,0,'\0',NULL,temp1,$6,$7,Continue);};
										
	|BOOLEAN VARIABLE '(' Args ')' GDStateBool GDStatement		{
								temp1 = TreeCreate(Boolean,0,$2,$4,NULL,NULL,NULL,FunctionDecl);
								$$=TreeCreate(Boolean,0,'\0',NULL,temp1,$6,$7,Continue);};

	|							{ $$ = NULL; };
	

//############################### MORE GLOBAL INTEGER DECLARETION ####################################################

GDStateInt: ',' VARIABLE GDStateInt				{	$$=TreeCreate(Integer,1,$2,NULL,$3,NULL,NULL,Decl);};

	| ',' VARIABLE '[' DIGIT ']' GDStateInt 		{ $$=TreeCreate(Integer,$4,$2,NULL,$6,NULL,NULL,Array);};
	
	| ',' VARIABLE '(' Args ')' GDStateInt			{	$$=TreeCreate(Integer,0,$2,$4,$6,NULL,NULL,FunctionDecl);};

	| ';'  			{$$ = NULL; };
	

//############################### MORE GLOBAL BOOLEAN DECLARETION ####################################################

GDStateBool: ',' VARIABLE GDStateBool				{	$$=TreeCreate(Boolean,1,$2,NULL,$3,NULL,NULL,Decl);};

	| ',' VARIABLE '[' DIGIT ']' GDStateBool 		{ $$=TreeCreate(Boolean,$4,$2,NULL,$6,NULL,NULL,Array);};
	
	| ',' VARIABLE '(' Args ')' GDStateBool			{	$$=TreeCreate(Boolean,0,$2,$4,$6,NULL,NULL,FunctionDecl);};

	| ';'  			{$$ = NULL; };



//############################### FUNCTION DEFINITION ####################################################

Func :	INTEGER VARIABLE '(' Args ')' '{' DECL DStatement ENDDECL  BGIN  SList  Rstat  END '}'  Func {
																temp1 = TreeCreate(Integer,0,$2,$4,$8,$11,$12,FunctionDecl);
																$$=TreeCreate(Void,0,'\0',NULL,temp1,$15,NULL,Continue);};

		| BOOLEAN VARIABLE '(' Args ')' '{' DECL DStatement ENDDECL  BGIN  SList  Rstat  END '}'  Func {
																temp1 = TreeCreate(Boolean,0,$2,$4,$8,$11,$12,FunctionDecl);
																$$=TreeCreate(Void,0,'\0',NULL,temp1,$15,NULL,Continue);};
	
		|INTEGER MAIN '(' ')' '{' DECL DStatement ENDDECL  BGIN  SList  Rstat  END '}'  {
																$$=TreeCreate(Integer,0,"main",NULL,$7,$10,$11,Main);
							    								MainNode=$$;};
		
//############################### FUNCTION ARGUMENTS ####################################################		

Args:INTEGER VARIABLE ArgsInt ArgEnd	{$$=TreeCreate(Integer,0,$2,NULL,$3,$4,NULL,Argument);};

	| INTEGER '&' VARIABLE ArgsInt ArgEnd	{$$=TreeCreate(RefInt,0,$3,NULL,$4,$5,NULL,Argument);};

	| BOOLEAN VARIABLE ArgsBool ArgEnd		{$$=TreeCreate(Boolean,0,$2,NULL,$3,$4,NULL,Argument);};
	
	| BOOLEAN '&' VARIABLE ArgsBool ArgEnd		{$$=TreeCreate(RefBool,0,$3,NULL,$4,$5,NULL,Argument);};
	
   |					{$$ = NULL;};  
    
ArgEnd:';' Args		{$$=$2;};

   |					{$$ = NULL;}; 
    
ArgsInt: ArgsInt ',' VARIABLE 				{$$=TreeCreate(Integer,0,$3,NULL,$1,NULL,NULL,Argument);};

	| ArgsInt ',' '&' VARIABLE 				{$$=TreeCreate(RefInt,0,$4,NULL,$1,NULL,NULL,Argument);};
     
   |				{  $$ = NULL;	}
     

ArgsBool: ArgsBool ',' VARIABLE 				{$$=TreeCreate(Boolean,0,$3,NULL,$1,NULL,NULL,Argument);};

	| ArgsBool ',' '&' VARIABLE 				{$$=TreeCreate(RefBool,0,$4,NULL,$1,NULL,NULL,Argument);};
     
   |				{  $$ = NULL;	}  ;



//############################### LOCAL DECL STATEMENTS ENDDECL ##########################################



DStatement:INTEGER VARIABLE DStateInt DStatement		{
								temp1 = TreeCreate(Integer,1,$2,NULL,NULL,NULL,NULL,Decl);
								$$=TreeCreate(Integer,0,'\0',NULL,temp1,$3,$4,Continue);};

	| INTEGER VARIABLE '[' DIGIT ']' DStateInt DStatement {
										temp1 = TreeCreate(Integer,$4,$2,NULL,NULL,NULL,NULL,Array);
										$$=TreeCreate(Integer,0,'\0',NULL,temp1,$6,$7,Continue);};
										
	|BOOLEAN VARIABLE DStateBool DStatement		{
								temp1 = TreeCreate(Boolean,1,$2,NULL,NULL,NULL,NULL,Decl);
								$$=TreeCreate(Boolean,0,'\0',NULL,temp1,$3,$4,Continue);};

	| BOOLEAN VARIABLE '[' DIGIT ']' DStateBool DStatement {
										temp1 = TreeCreate(Boolean,$4,$2,NULL,NULL,NULL,NULL,Array);
										$$=TreeCreate(Boolean,0,'\0',NULL,temp1,$6,$7,Continue);};

	|							{ $$ = NULL; };
	

//############################### MORE LOCAL INTEGER VARIABLE DECLARETION ####################################################

DStateInt: ',' VARIABLE DStateInt				{	$$=TreeCreate(Integer,1,$2,NULL,$3,NULL,NULL,Decl);};

	| ',' VARIABLE '[' DIGIT ']' DStateInt { $$=TreeCreate(Integer,$4,$2,NULL,$6,NULL,NULL,Decl);};

	| ';'  			{$$ = NULL; };
	

//############################### MORE LOCAL BOOLEAN VARIABLE DECLARETION ####################################################

DStateBool: ',' VARIABLE DStateBool				{	$$=TreeCreate(Boolean,1,$2,NULL,$3,NULL,NULL,Decl);};

	| ',' VARIABLE '[' DIGIT ']' DStateBool { $$=TreeCreate(Boolean,$4,$2,NULL,$6,NULL,NULL,Decl);};

	| ';'  			{$$ = NULL; };



//############################### BEGIN STATEMENTS END ####################################################

SList: SList Statement		{ $$ = TreeCreate(Void,0,'\0',NULL,$1,$2,NULL,Continue); };

	|Statement		{ $$ = TreeCreate(Void,0,'\0',NULL,$1,NULL,NULL,Continue); };

	|				{$$ = NULL;};
	
	
//############################### SINGLE STATEMENT OF BODY ####################################################

Statement: 	READ '(' VARIABLE ')' ';'     	{ $$ = TreeCreate(Void,0,$3,NULL,NULL,NULL,NULL,Read); };

	|READ '(' VARIABLE '[' E ']' ')' ';'     	{ $$ = TreeCreate(Void,0,$3,NULL,$5,NULL,NULL,ArrayRead); };
							
	|WRITE '(' E ')' ';'    { $$ = TreeCreate(Void,0,0,NULL,$3,NULL,NULL,Write); };
	
	|VARIABLE '=' E ';' 		{ $$ = TreeCreate(Void,0,$1,NULL,NULL,$3,NULL,Initialize); };
	
	| E ';' 		{ $$ = TreeCreate(Void,0,NULL,NULL,NULL,$1,NULL,Expression); };
	
	|VARIABLE '[' E ']' '=' E ';' 	{ $$ = TreeCreate(Void,0,$1,NULL,$3,$6,NULL,ArrayInitialize); };
	
	|IF '(' E ')' THEN  SList  ElseStmt  ENDIF  {$$ = TreeCreate(Void,0,0,NULL,$3,$6,$7,Conditional);};

	|WHILE '(' E ')' DO  SList  ENDWHILE  {$$ = TreeCreate(Void,0,0,NULL,$3,$6,NULL,Iterative);};
	
	
ElseStmt: ELSE SList {$$ = $2;};

	| {$$ = NULL;};


//############################### Arithmatic And Boolean Expression ####################################################


E:	DIGIT  			{ $$ = TreeCreate(Integer,$1,'\0',NULL,NULL,NULL,NULL,Digit); };

	|E '+' E     	{ $$ = TreeCreate(Integer,0,'\0',NULL,$1,$3,NULL,Addition); }; 

	|E '-' E     	{ $$ = TreeCreate(Integer,0,'\0',NULL,$1,$3,NULL,Subtraction); };

	|E '*' E     	{ $$ = TreeCreate(Integer,0,'\0',NULL,$1,$3,NULL,Multiplacation); };

	|E '/' E 		{ $$ = TreeCreate(Integer,0,'\0',NULL,$1,$3,NULL,Division); };
	
	|E '%' E 		{ $$ = TreeCreate(Integer,0,'\0',NULL,$1,$3,NULL,Remainder); };
	
	|E GT E 			{ $$ = TreeCreate(Boolean,0,'\0',NULL,$1,$3,NULL,GreaterThen); };
	
	|E GE E 			{ $$ = TreeCreate(Boolean,0,'\0',NULL,$1,$3,NULL,GreaterThenEqual); };
	
	|E LT E 			{ $$ = TreeCreate(Boolean,0,'\0',NULL,$1,$3,NULL,LessThen); };
	
	|E LE E 			{ $$ = TreeCreate(Boolean,0,'\0',NULL,$1,$3,NULL,LessThenEqual); };
	
	|E EQ E 			{ $$ = TreeCreate(Boolean,0,'\0',NULL,$1,$3,NULL,Equal); };
	
	|E NE E 			{ $$ = TreeCreate(Boolean,0,'\0',NULL,$1,$3,NULL,NotEqual); };
	
	|E AND E     	{ $$ = TreeCreate(Boolean,0,'\0',NULL,$1,$3,NULL,And); }; 

	|E OR E     	{ $$ = TreeCreate(Boolean,0,'\0',NULL,$1,$3,NULL,Or); };

	|NOT E     		{ $$ = TreeCreate(Boolean,0,'\0',NULL,$2,NULL,NULL,Not); };

	|TRU 				{ $$ = TreeCreate(Boolean,0,'\0',NULL,NULL,NULL,NULL,True); };
	
	|FALS 			{ $$ = TreeCreate(Boolean,0,'\0',NULL,NULL,NULL,NULL,False); };

	|VARIABLE 	 	{ $$ = TreeCreate(Void,0,$1,NULL,NULL,NULL,NULL,Variable); };
	
	|VARIABLE '[' E ']'	 { $$ = TreeCreate(Void,0,$1,NULL,$3,NULL,NULL,ArrayVariable); };
	
	|'(' E ')'	{ $$ = $2; };
	
	|VARIABLE '(' ParaList ')' 	 { $$ = TreeCreate(Integer,0,$1,$3,NULL,NULL,NULL,Function); };
	
	
//############################### PARAMETER ####################################################

ParaList: Parameter {$$ = $1;};
	
	|		 { $$ = NULL; };

Parameter:E ',' Parameter   { $$ = TreeCreate(Integer,0,NULL,NULL,$1,$3,NULL,Argument); };

	| '&' VARIABLE ',' Parameter   { $$ = TreeCreate(Integer,0,$2,NULL,NULL,$4,NULL,Argument); };

	|E 	 { $$ = TreeCreate(Integer,0,NULL,NULL,$1,NULL,NULL,Argument); };
	
	|'&' VARIABLE 	 { $$ = TreeCreate(Integer,0,$2,NULL,NULL,NULL,NULL,Argument); };


//############################### RETURN STATEMENT ####################################################	
	
Rstat :	RETURN E ';'  {$$ = TreeCreate(Void,0,'\0',NULL,$2,NULL,NULL,Return);};		


//############################### END OF CFG ####################################################	
%%

int yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
	return 1;
}

int main(int argc,char **argv) {
	yyin=fopen(argv[1],"r");
  	yyparse();
	fclose(yyin);
	return 1;
}
