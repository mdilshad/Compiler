struct ArgStruct{

	char *NAME; // Name of the Identifier

	int TYPE; // TYPE can be INTEGER or BOOLEAN

	struct ArgStruct *NEXT;// Pointer to next Argument Entry 
};
union BINDING{
	int * IBINDING;
	//Tnode *NBINDING;
};
struct Gsymbol {

	char *NAME; // Name of the Identifier

	int TYPE; // TYPE can be INTEGER or BOOLEAN

	/***The TYPE field must be a TypeStruct if user defined types are allowed***/

	int SIZE; // Size field for arrays

	int *BINDING; // Address of the Identifier in Memory
	
	struct tnode *FNode; // Address of the Function in Tree

	struct ArgStruct *ARGLIST; // Argument List for functions

	/***Argstruct must store the name and type of each argument ***/

	struct Gsymbol *NEXT; // Pointer to next Symbol Table Entry */

}*GTable;

struct Lsymbol {

	char *NAME; // Name of the Identifier

	int TYPE; // TYPE can be INTEGER or BOOLEAN

	/***The TYPE field must be a TypeStruct if user defined types are allowed***/

	int SIZE; // Size field for arrays

	int *BINDING; // Address of the Identifier in Memory

	struct Lsymbol *NEXT; // Pointer to next Symbol Table Entry */

};

typedef struct tnode {

	int TYPE; // Integer, Boolean or Void (for statements)
	/* Must point to the type expression tree for user defined types */

	int NODETYPE;
	/* this field should carry following information:
	* a) operator : (+,*,/ etc.) for expressions
	* b) statement Type : (WHILE, READ etc.) for statements */

	char *NAME; // For Identifiers/Functions

	int VALUE; // for constants
	
	struct tnode *ArgList; // List of arguments for functions

	struct tnode *Ptr1, *Ptr2, *Ptr3;
	/* Maximum of three subtrees (3 required for IF THEN ELSE */

	//struct Gsymbol *Gentry; // For global identifiers/functions

	//struct Lsymbol *Lentry; // For Local variables

}Tnode;

struct Gsymbol *T;
struct Lsymbol *L;
Tnode *temp1,*temp2,*MainNode;
int flag;
