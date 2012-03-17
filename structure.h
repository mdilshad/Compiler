struct ArgStruct{

	char *NAME; // Name of the Identifier

	struct tnode *EXP; // Expression Entry

	int TYPE; // TYPE can be INTEGER or BOOLEAN

	struct ArgStruct *NEXT;// Pointer to next Argument Entry 
};

typedef struct field {

	char *NAME; // Name of the Identifier

	char *TYPENAME; // Name of the typedef

	int TYPE; // Integer, Boolean or TYPEDEF

	struct field *NEXT; // Pointer to next field Entry */

}Field;


typedef struct tnode {

	int TYPE; // Integer, Boolean or Void (for statements)
	/* Must point to the type expression tree for user defined types */

	int NODETYPE;
	/* this field should carry following information:
	* a) operator : (+,*,/ etc.) for expressions
	* b) statement Type : (WHILE, READ etc.) for statements */

	char *NAME; // For Identifiers/Functions

	int VALUE; // for constants
	
	struct ArgStruct *ArgList; // List of arguments for functions

	struct tnode *Ptr1, *Ptr2, *Ptr3;
	/* Maximum of three subtrees (3 required for IF THEN ELSE */

}Tnode;

typedef struct typeDef {

	char *NAME; // Name of the Identifier

	Field *FLIST; // Argument List for functions

	/***field must store the name and type of each member ***/

	struct typeDef *NEXT; // Pointer to next Symbol Table Entry */

}TypeDef;

struct Gsymbol {

	char *NAME; // Name of the Identifier

	int TYPE; // TYPE can be INTEGER or BOOLEAN

	char *TYPENAME; // Name of the typedef

	int flag;

	int SIZE; // Size field for arrays

	int *BINDING; // Address of the Identifier in Memory

	struct tnode *FNode; // Address of the Function in Tree

	struct Gsymbol **Tentry;// Address of Nested Typedef in Memory

	struct ArgStruct *ARGLIST; // Argument List for functions

	/***Argstruct must store the name and type of each argument ***/

	struct Gsymbol *NEXT; // Pointer to next Symbol Table Entry */

}*GTable;


struct Lsymbol {

	char *NAME; // Name of the Identifier

	int TYPE; // TYPE can be INTEGER or BOOLEAN

	char *TYPENAME;

	int flag;

	int *BINDING; // Address of the Identifier in Memory

	struct ArgStruct *ARGLIST; // Argument List for functions

	struct tnode *FNode; // Address of the Function in Tree

	struct Lsymbol *Tentry;// Address of Nested Typedef in Memory

	struct Lsymbol *NEXT; // Pointer to next Symbol Table Entry */

};

typedef struct tsymbol {

	char *NAME; // Name of the Identifier

	int TYPE; // TYPE can be INTEGER or BOOLEAN or user defined

	char *TYPENAME;// Name of user defined type

	int *BINDING; // Address of the Identifier in Memory

	struct tsymbol *Tentry;// Address of Nested Typedef in Memory

	struct tsymbol *NEXT; // Pointer to next Symbol Table Entry */

}Tsymbol;


typedef struct ltable{

	struct Lsymbol *Lentry;// Address of Nested Local Table in Memory

	struct ltable *NEXT; // Pointer to next Local Table Entry */
}LTABLE;



TypeDef *TypeTable = NULL,*TD;
LTABLE *LHead = NULL;
struct Gsymbol *T,*TEMP;
struct ArgStruct *ArgTemp;
struct Lsymbol *L,*LTemp,*LTEMP;
Tnode *temp1,*temp2,*MainNode;
int flag,i,Aflag;
FILE *fp;
