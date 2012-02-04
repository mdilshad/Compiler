%{
    int yylex(void);
    int yyerror(char *);
    #include<stdio.h>
    #include"Action.h"
   int i,expval;
   Tnode *temp1,*temp2,*MainNode;
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
%type <Node> E BE SList Statement DStatement DStatementI DStatementB SDecl Rstat Func Args ArgsI ArgsB ArgsEnd ElseStmt GDStatement GDStatementI GDStatementB
%token READ WRITE BGIN END DECL ENDDECL INTEGER BOOLEAN AND OR NOT GT GE LT LE EQ NE FALS TRU IF ELSE THEN ENDIF WHILE DO ENDWHILE RETURN MAIN
%right '='
%left '+' '-' 
%left '%'
%left '*' '/' 
%left AND OR EQ NQ LT LE GE GT
%right NOT
%%

//############################### START CFG ############################################################

Program : DECL  GDStatement ENDDECL  Func{ };

//############################### GLOBEL DECL STATEMENTS ENDDECL ####################################################


GDStatement:INTEGER VARIABLE GDStatementI GDStatement		{
								temp1 = TreeCreate(Integer,1,$2,NULL,NULL,NULL,NULL,GDecl);
								$$=TreeCreate(Integer,0,'\0',NULL,temp1,$3,$4,Continue);};

	|INTEGER VARIABLE '[' DIGIT ']' GDStatementI GDStatement {
										temp1 = TreeCreate(Integer,$4,$2,NULL,NULL,NULL,NULL,GArray);
										$$=TreeCreate(Integer,0,'\0',NULL,temp1,$6,$7,Continue);};
										
	|INTEGER VARIABLE '(' Args ')' GDStatementI GDStatement		{
								temp1 = TreeCreate(Integer,0,$2,$4,NULL,NULL,NULL,FunctionDecl);
								$$=TreeCreate(Integer,0,'\0',NULL,temp1,$6,$7,Continue);};
										
	|BOOLEAN VARIABLE GDStatementB GDStatement		{
								temp1 = TreeCreate(Boolean,1,$2,NULL,NULL,NULL,NULL,GDecl);
								$$=TreeCreate(Boolean,0,'\0',NULL,temp1,$3,$4,Continue);};

	| BOOLEAN VARIABLE '[' DIGIT ']' GDStatementB GDStatement {
										temp1 = TreeCreate(Boolean,$4,$2,NULL,NULL,NULL,NULL,Array);
										$$=TreeCreate(Boolean,0,'\0',NULL,temp1,$6,$7,Continue);};
										
	|BOOLEAN VARIABLE '(' Args ')' GDStatementB GDStatement		{
								temp1 = TreeCreate(Boolean,0,$2,$4,NULL,NULL,NULL,FunctionDecl);
								$$=TreeCreate(Boolean,0,'\0',NULL,temp1,$6,$7,Continue);};

	|							{ $$ = NULL; };
	

//############################### MORE GLOBAL INTEGER DECLARETION ####################################################

GDStatementI: ',' VARIABLE GDStatementI				{	$$=TreeCreate(Integer,1,$2,NULL,$3,NULL,NULL,GDecl);};

	| ',' VARIABLE '[' DIGIT ']' GDStatementI 		{ $$=TreeCreate(Integer,$4,$2,NULL,$6,NULL,NULL,GArray);};
	
	| ',' VARIABLE '(' Args ')' GDStatementI			{	$$=TreeCreate(Integer,0,$2,$4,$6,NULL,NULL,FunctionDecl);};

	| ';'  			{$$ = NULL; };
	

//############################### MORE GLOBAL BOOLEAN DECLARETION ####################################################

GDStatementB: ',' VARIABLE GDStatementB				{	$$=TreeCreate(Boolean,1,$2,NULL,$3,NULL,NULL,GDecl);};

	| ',' VARIABLE '[' DIGIT ']' GDStatementB 		{ $$=TreeCreate(Boolean,$4,$2,NULL,$6,NULL,NULL,GArray);};
	
	| ',' VARIABLE '(' Args ')' GDStatementB			{	$$=TreeCreate(Boolean,0,$2,$4,$6,NULL,NULL,FunctionDecl);};

	| ';'  			{$$ = NULL; };



//############################### FUNCTION PROTOTYPE ####################################################

Func :	INTEGER VARIABLE '(' Args ')' '{' DECL SDecl ENDDECL  BGIN  SList  Rstat  END '}'  Func {
																temp1 = TreeCreate(Integer,0,$2,$4,$8,$11,$12,Function);
																$$=TreeCreate(Void,0,'\0',NULL,temp1,$15,NULL,Continue);};

		| BOOLEAN VARIABLE '(' Args ')' '{' DECL SDecl ENDDECL  BGIN  SList  Rstat  END '}'  Func {
																temp1 = TreeCreate(Boolean,0,$2,$4,$8,$11,$12,Function);
																$$=TreeCreate(Void,0,'\0',NULL,temp1,$15,NULL,Continue);};
	
		|INTEGER MAIN '(' ')' '{' DECL SDecl ENDDECL  BGIN  SList  Rstat  END '}'  {
																$$=TreeCreate(Integer,0,"main",NULL,$7,$10,$11,Main);
							    								MainNode=$$;};
		
//############################### FUNCTION ARGUMENTS ####################################################		

Args:INTEGER VARIABLE ArgsI ';' Args  ArgsEnd		{$$=TreeCreate(Integer,0,$2,NULL,$3,$5,$6,Argument);};

	| BOOLEAN VARIABLE ArgsB ';' Args ArgsEnd		{$$=TreeCreate(Boolean,0,$2,NULL,$3,$5,$6,Argument);};
	
	|	ArgsEnd		{$$=$1;};

   |					{$$ = NULL;};
    
    
ArgsEnd:INTEGER VARIABLE ArgsI		{$$=TreeCreate(Integer,0,$2,NULL,$3,NULL,NULL,Argument);};

	| 	  BOOLEAN VARIABLE ArgsB		{$$=TreeCreate(Boolean,0,$2,NULL,$3,NULL,NULL,Argument);};
    
    
    
ArgsI:',' VARIABLE ArgsI				{$$=TreeCreate(Integer,0,$2,NULL,$3,NULL,NULL,Argument);};
     
     |				{  $$ = NULL;	}
     

ArgsB:',' VARIABLE ArgsB				{$$=TreeCreate(Boolean,0,$2,NULL,$3,NULL,NULL,Argument);};
     
     |				{  $$ = NULL;	}  ;



//############################### LOCAL DECL STATEMENTS ENDDECL ##########################################

SDecl:DStatement		{$$=$1;};


DStatement:INTEGER VARIABLE DStatementI DStatement		{
								temp1 = TreeCreate(Integer,1,$2,NULL,NULL,NULL,NULL,Decl);
								$$=TreeCreate(Integer,0,'\0',NULL,temp1,$3,$4,Continue);};

	| INTEGER VARIABLE '[' DIGIT ']' DStatementI DStatement {
										temp1 = TreeCreate(Integer,$4,$2,NULL,NULL,NULL,NULL,Array);
										$$=TreeCreate(Integer,0,'\0',NULL,temp1,$6,$7,Continue);};
										
	|BOOLEAN VARIABLE DStatementB DStatement		{
								temp1 = TreeCreate(Boolean,1,$2,NULL,NULL,NULL,NULL,Decl);
								$$=TreeCreate(Boolean,0,'\0',NULL,temp1,$3,$4,Continue);};

	| BOOLEAN VARIABLE '[' DIGIT ']' DStatementB DStatement {
										temp1 = TreeCreate(Boolean,$4,$2,NULL,NULL,NULL,NULL,Array);
										$$=TreeCreate(Boolean,0,'\0',NULL,temp1,$6,$7,Continue);};

	|							{ $$ = NULL; };
	

//############################### MORE LOCAL INTEGER VARIABLE DECLARETION ####################################################

DStatementI: ',' VARIABLE DStatementI				{	$$=TreeCreate(Integer,1,$2,NULL,$3,NULL,NULL,Decl);};

	| ',' VARIABLE '[' DIGIT ']' DStatementI { $$=TreeCreate(Integer,$4,$2,NULL,$6,NULL,NULL,Decl);};

	| ';'  			{$$ = NULL; };
	

//############################### MORE LOCAL BOOLEAN VARIABLE DECLARETION ####################################################

DStatementB: ',' VARIABLE DStatementB				{	$$=TreeCreate(Boolean,1,$2,NULL,$3,NULL,NULL,Decl);};

	| ',' VARIABLE '[' DIGIT ']' DStatementB { $$=TreeCreate(Boolean,$4,$2,NULL,$6,NULL,NULL,Decl);};

	| ';'  			{$$ = NULL; };



//############################### BEGIN STATEMENTS END ####################################################

SList: SList Statement		{ $$ = TreeCreate(Void,0,'\0',NULL,$1,$2,NULL,Continue); };

	|Statement		{ $$ = TreeCreate(Void,0,'\0',NULL,$1,NULL,NULL,Continue); };

	|				{$$ = NULL;};
	
	
//############################### SINGLE STATEMENT OF BODY ####################################################

Statement: 	READ '(' VARIABLE ')' ';'     	{ $$ = TreeCreate(Integer,0,$3,NULL,NULL,NULL,NULL,Read); };

	|READ '(' VARIABLE '[' E ']' ')' ';'     	{ $$ = TreeCreate(Integer,0,$3,NULL,$5,NULL,NULL,ArrayRead); };
							
	|WRITE '(' E ')' ';'    { $$ = TreeCreate(Integer,0,0,NULL,$3,NULL,NULL,Write); };
	
	|VARIABLE '=' E ';' 	{ $$ = TreeCreate(Integer,0,$1,NULL,NULL,$3,NULL,Initialize); };
	
	|VARIABLE '[' E ']' '=' E ';' 	{ $$ = TreeCreate(Integer,0,$1,NULL,$3,$6,NULL,ArrayInitialize); };
	
	|VARIABLE '=' BE ';' 	{ $$ = TreeCreate(Boolean,0,$1,NULL,NULL,$3,NULL,Initialize); };
	
	|VARIABLE '[' E ']' '=' BE ';' 	{ $$ = TreeCreate(Boolean,0,$1,NULL,$3,$6,NULL,ArrayInitialize); };
	
	|IF '(' BE ')' THEN  SList  ElseStmt  ENDIF  {$$ = TreeCreate(Void,0,0,NULL,$3,$6,$7,Conditional);};

	|WHILE '(' BE ')' DO  SList  ENDWHILE  {$$ = TreeCreate(Void,0,0,NULL,$3,$6,NULL,Iterative);};
	
	
ElseStmt: ELSE SList {$$ = $2;};

	| {$$ = NULL;};


//############################### Arithmatic Expression ####################################################


E:	DIGIT  		{ $$ = TreeCreate(Integer,$1,'\0',NULL,NULL,NULL,NULL,Digit); };

	|E '+' E     	{ $$ = TreeCreate(Integer,0,'\0',NULL,$1,$3,NULL,Addition); }; 

	|E '-' E     	{ $$ = TreeCreate(Integer,0,'\0',NULL,$1,$3,NULL,Subtraction); };

	|E '*' E     	{ $$ = TreeCreate(Integer,0,'\0',NULL,$1,$3,NULL,Multiplacation); };

	|E '/' E 	{ $$ = TreeCreate(Integer,0,'\0',NULL,$1,$3,NULL,Division); };
	
	|E '%' E 	{ $$ = TreeCreate(Integer,0,'\0',NULL,$1,$3,NULL,Remainder); };

	|'(' E ')'	{ $$ = $2; };

	|VARIABLE 	 { $$ = TreeCreate(Integer,0,$1,NULL,NULL,NULL,NULL,Variable); };
	
	|VARIABLE '[' E ']'	 { $$ = TreeCreate(Integer,0,$1,NULL,$3,NULL,NULL,ArrayVariable); };
	
	


//############################### BOOLEAN Expression ####################################################

BE:BE AND BE     	{ $$ = TreeCreate(Boolean,0,'\0',NULL,$1,$3,NULL,And); }; 

	|BE OR BE     	{ $$ = TreeCreate(Boolean,0,'\0',NULL,$1,$3,NULL,Or); };

	|NOT BE     	{ $$ = TreeCreate(Boolean,0,'\0',NULL,$2,NULL,NULL,Not); };

	|E GT E 	{ $$ = TreeCreate(Boolean,0,'\0',NULL,$1,$3,NULL,GreaterThen); };
	
	|E GE E 	{ $$ = TreeCreate(Boolean,0,'\0',NULL,$1,$3,NULL,GreaterThenEqual); };
	
	|E LT E 	{ $$ = TreeCreate(Boolean,0,'\0',NULL,$1,$3,NULL,LessThen); };
	
	|E LE E 	{ $$ = TreeCreate(Boolean,0,'\0',NULL,$1,$3,NULL,LessThenEqual); };
	
	|E EQ E 	{ $$ = TreeCreate(Boolean,0,'\0',NULL,$1,$3,NULL,Equal); };
	
	|E NE E 	{ $$ = TreeCreate(Boolean,0,'\0',NULL,$1,$3,NULL,NotEqual); };
	
	|TRU 	{ $$ = TreeCreate(Boolean,0,'\0',NULL,NULL,NULL,NULL,True); };
	
	|FALS 	{ $$ = TreeCreate(Boolean,0,'\0',NULL,NULL,NULL,NULL,False); };

	|'(' BE ')'	{ $$ = $2; };
		


//############################### RETURN STATEMENT ####################################################	
	
Rstat :	RETURN E ';'  {$$ = TreeCreate(Integer,0,'\0',NULL,$2,NULL,NULL,Return);};	
	
	|RETURN BE ';'  {$$ = TreeCreate(Boolean,0,'\0',NULL,$2,NULL,NULL,Return);};	



//############################### END OF CFG ####################################################	
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
