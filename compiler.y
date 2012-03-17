%{
	int yylex(void);
	int yyerror(char *);
	#include"ActionConvert.h"
	//#include"ActionInterpret.h"
	extern FILE *yyin;
%}
%union
{
	int Num;
	char* chp;
	struct tnode* Node;
	struct field* FNode;
	struct typeDef* TNode;
	struct ArgStruct* ArgNode;
};
%token <Num> DIGIT
%token <chp> Identifier

%type <Node> E SList FBody Statement VARIABLE Rstat Fdeflist FDef DefList VARList DStatement ElseStmt TYPE VARNAME GDefblock Mainblock

%type <ArgNode> ArgList Args ArgsInt ArgsBool ArgEnd ParaList Parameter TVAR

%type <TNode> STypedef

%type <FNode> FIELD FStatement FStateMore

%token READ WRITE NEW FREE TYPEDEF BGIN END DECL ENDDECL INTEGER BOOLEAN AND OR NOT GT GE LT LE EQ NE FALS TRU IF ELSE THEN ENDIF WHILE DO ENDWHILE RETURN MAIN

%right '='
%left '+' '-' 
%left '%'
%left '*' '/' 
%left AND OR EQ NQ LT LE GE GT
%right NOT

%%

//############################### START CFG ############################################################

Program : STypedef GDefblock Fdeflist Mainblock		{TypeTable = $1;Compile($2,$3,$4); };

GDefblock:DECL DefList ENDDECL{$$ = $2;};

//############################### TYPEDEF STATEMENTS ####################################################

STypedef: STypedef TYPEDEF Identifier '{' FIELD '}' 	{ $$ = Tcreate($3,$5);$$->NEXT = $1;};

	|{$$ = NULL;};


//############################### TYPEDEF STATEMENT  ##########################################

FIELD :INTEGER Identifier FStateMore					{ $$ = Fcreate($2,NULL,Integer); $$->NEXT = $3;};

	| Identifier Identifier FStateMore					{ $$ = Fcreate($2,$1,Typedef); $$->NEXT = $3;};

	| BOOLEAN Identifier FStateMore 					{ $$ = Fcreate($2,NULL,Boolean); $$->NEXT = $3; };


//############################### MORE TYPEDEF FIELD DECLARETION ####################################################

FStateMore: ',' Identifier FStateMore				{ $$ = Fcreate($2,NULL,Void); $$->NEXT = $3;};

	| ';' FStatement		{$$ = $2; };


FStatement : FIELD {$$ = $1;};

	|		{ $$ = NULL; };


//############################### FUNCTION DEFINITION ####################################################

Fdeflist: Fdeflist FDef {$$=TreeCreate(Void,0,NULL,NULL,$1,$2,NULL,Continue);};

	|{$$ = NULL;};

FDef :INTEGER Identifier '(' ArgList ')' '{' DECL DefList ENDDECL  BGIN  FBody  Rstat  END '}' {
																$$ = TreeCreate(Integer,0,$2,$4,$8,$11,$12,FunctionDef);};

		| BOOLEAN Identifier '(' ArgList ')' '{' DECL DefList ENDDECL BGIN  FBody  Rstat  END '}'  {
																$$ = TreeCreate(Boolean,0,$2,$4,$8,$11,$12,FunctionDef);};

Mainblock: INTEGER MAIN '(' ')' '{' DECL DefList ENDDECL  BGIN  FBody  Rstat  END '}'{
																$$=TreeCreate(Integer,0,"main",NULL,$7,$10,$11,Main);};

//############################### FUNCTION ARGUMENTS ####################################################

ArgList: Args	{$$=$1;};

	|	{ $$ = NULL; };


Args:INTEGER Identifier ArgsInt ArgEnd			{ $$ = Argcreate($2,Integer,NULL); if($3 != NULL){$$->NEXT = $3;$3 = $4;}else $$->NEXT = $4;};

	| INTEGER '&' Identifier ArgsInt ArgEnd		{ $$ = Argcreate($3,RefInt,NULL); if($4 != NULL){$$->NEXT = $4;$4 = $5;}else $$->NEXT = $5;};

	| BOOLEAN Identifier ArgsBool ArgEnd		{ $$ = Argcreate($2,Boolean,NULL); if($3 != NULL){$$->NEXT = $3;$3 = $4;}else $$->NEXT = $4;};

	| BOOLEAN '&' Identifier ArgsBool ArgEnd	{ $$ = Argcreate($3,RefBool,NULL); if($4 != NULL){$$->NEXT = $4;$4 = $5;}else $$->NEXT = $5;};



ArgEnd:';' Args		{$$=$2;};

	|	{$$ = NULL;}; 


ArgsInt: ',' Identifier  ArgsInt		{ $$ = Argcreate($2,Integer,NULL);$$->NEXT = $3;};

	| ',' '&' Identifier  ArgsInt		{ $$ = Argcreate($3,RefInt,NULL);$$->NEXT = $4;};

	|	{ $$ = NULL;	}


ArgsBool: ',' Identifier ArgsBool		{ $$ = Argcreate($2,Boolean,NULL);$$->NEXT = $3;};

	| ',' '&' Identifier ArgsBool		{ $$ = Argcreate($3,RefBool,NULL);$$->NEXT = $4;};

	|	{  $$ = NULL;	};


//###############################  DECL STATEMENTS ENDDECL ####################################################

DefList: DefList DStatement		{$$=TreeCreate(Void,0,NULL,NULL,$1,$2,NULL,Continue);};

	|{$$ = NULL;};


DStatement:TYPE VARList ';'	{$$=TreeCreate(Void,0,NULL,NULL,$1,$2,NULL,Dstatement);};

//############################### VARIABLE TYPES  ####################################################

TYPE: INTEGER 		{$$=TreeCreate(Integer,0,NULL,NULL,NULL,NULL,NULL,Type);};

	| BOOLEAN 		{$$=TreeCreate(Boolean,0,NULL,NULL,NULL,NULL,NULL,Type);};

	| Identifier 	{$$=TreeCreate(Typedef,0,$1,NULL,NULL,NULL,NULL,Type);};

//############################### VARIABLE LIST  ####################################################

VARList:VARList ',' VARNAME		{$$=TreeCreate(Void,0,NULL,NULL,$1,$3,NULL,Continue);};

	| VARNAME 					{$$=TreeCreate(Void,0,NULL,NULL,$1,NULL,NULL,Continue);};


//##################### VARIABLE AND FUNCTION IDENTIFIER  ###############################################

VARNAME: Identifier 				{$$=TreeCreate(Void,1,$1,NULL,NULL,NULL,NULL,Decl);};

	| '^' Identifier 				{$$=TreeCreate(Void,0,$2,NULL,NULL,NULL,NULL,Pointer);};

	| Identifier '[' DIGIT ']'		{$$=TreeCreate(Void,$3,$1,NULL,NULL,NULL,NULL,Array);};

	| Identifier '(' ArgList ')' 	{$$=TreeCreate(Void,0,$1,$3,NULL,NULL,NULL,FunctionDecl);};

//############################### BEGIN STATEMENTS END ####################################################

FBody: Fdeflist SList		{$$ = TreeCreate(Void,0,NULL,NULL,$1,$2,NULL,Continue);};

SList: SList Statement		{ $$ = TreeCreate(Void,0,NULL,NULL,$1,$2,NULL,Continue); };

	|	{$$ = NULL;};


//############################### SINGLE STATEMENT OF BODY ####################################################

Statement: 	READ '(' VARIABLE ')' ';'	{ $$ = TreeCreate(Void,0,NULL,NULL,$3,NULL,NULL,Read); };

	| WRITE '(' E ')' ';'		{ $$ = TreeCreate(Void,0,NULL,NULL,$3,NULL,NULL,Write); };

	| VARIABLE '=' E ';' 		{ $$ = TreeCreate(Void,0,NULL,NULL,$1,$3,NULL,Initialize); };

	| Identifier '(' ParaList ')' ';'	 { $$ = TreeCreate(Void,0,$1,$3,NULL,NULL,NULL,Function); };

	| IF '(' E ')' THEN  SList  ElseStmt ENDIF ';'	{$$ = TreeCreate(Void,0,NULL,NULL,$3,$6,$7,Conditional);};

	| WHILE '(' E ')' DO  SList  ENDWHILE ';'		{$$ = TreeCreate(Void,0,NULL,NULL,$3,$6,NULL,Iterative);};

	| FREE '(' Identifier ')' ';'	{ $$ = TreeCreate(Void,0,$3,NULL,NULL,NULL,NULL,Free);};

//	| Identifier '=' NEW '(' DIGIT ')' ';'	{$$ = TreeCreate(Void,$5,$1,NULL,NULL,NULL,NULL,New);};


ElseStmt: ELSE SList {$$ = $2;};

	| {$$ = NULL;};


//############################### Arithmatic And Boolean Expression ####################################################

E:	DIGIT 			{ $$ = TreeCreate(Integer,$1,NULL,NULL,NULL,NULL,NULL,Digit); };

	|E '+' E		{ $$ = TreeCreate(Integer,0,NULL,NULL,$1,$3,NULL,Addition); }; 

	|E '-' E		{ $$ = TreeCreate(Integer,0,NULL,NULL,$1,$3,NULL,Subtraction); };

	|E '*' E		{ $$ = TreeCreate(Integer,0,NULL,NULL,$1,$3,NULL,Multiplacation); };

	|E '/' E 		{ $$ = TreeCreate(Integer,0,NULL,NULL,$1,$3,NULL,Division); };

	|E '%' E 		{ $$ = TreeCreate(Integer,0,NULL,NULL,$1,$3,NULL,Remainder); };

	|E GT E 		{ $$ = TreeCreate(Boolean,0,NULL,NULL,$1,$3,NULL,GreaterThen); };

	|E GE E 		{ $$ = TreeCreate(Boolean,0,NULL,NULL,$1,$3,NULL,GreaterThenEqual); };

	|E LT E 		{ $$ = TreeCreate(Boolean,0,NULL,NULL,$1,$3,NULL,LessThen); };

	|E LE E 		{ $$ = TreeCreate(Boolean,0,NULL,NULL,$1,$3,NULL,LessThenEqual); };

	|E EQ E 		{ $$ = TreeCreate(Boolean,0,NULL,NULL,$1,$3,NULL,Equal); };

	|E NE E 		{ $$ = TreeCreate(Boolean,0,NULL,NULL,$1,$3,NULL,NotEqual); };

	|E AND E		{ $$ = TreeCreate(Boolean,0,NULL,NULL,$1,$3,NULL,And); }; 

	|E OR E			{ $$ = TreeCreate(Boolean,0,NULL,NULL,$1,$3,NULL,Or); };

	|NOT E			{ $$ = TreeCreate(Boolean,0,NULL,NULL,$2,NULL,NULL,Not); };

	|TRU 			{ $$ = TreeCreate(Boolean,0,NULL,NULL,NULL,NULL,NULL,True); };

	|FALS 			{ $$ = TreeCreate(Boolean,0,NULL,NULL,NULL,NULL,NULL,False); };

	|Identifier '(' ParaList ')' 	 { $$ = TreeCreate(Void,0,$1,$3,NULL,NULL,NULL,Function); };

	|VARIABLE	{$$ = $1;};

	|'(' E ')'	{ $$ = $2; };


//############################### VARIABLE NAME WITH '.' FIELD ####################################################

VARIABLE : Identifier TVAR					{$$ = TreeCreate(Void,0,$1,$2,NULL,NULL,NULL,Variable); };

	| Identifier '[' E ']' TVAR			{$$ = TreeCreate(Void,0,$1,$5,$3,NULL,NULL,ArrayVariable); };


TVAR: '.' Identifier TVAR			{ $$ = Argcreate($2,Boolean,NULL);$$->NEXT = $3;};

	|{$$ = NULL;};


//############################### PARAMETER ####################################################

ParaList: Parameter {$$ = $1;};

	|		 { $$ = NULL; };

Parameter:E ',' Parameter			{ $$ = Argcreate(NULL,Void,$1); $$->NEXT = $3;};

	| '&' Identifier ',' Parameter	{ $$ = Argcreate($2,RefBool,NULL); $$->NEXT = $4; };

	|E 	 { $$ = Argcreate(NULL,Void,$1); };

	|'&' Identifier 	 { $$ = Argcreate($2,RefBool,NULL); };


//############################### RETURN STATEMENT ####################################################	

Rstat :	RETURN E ';'  {$$ = $2;};


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
