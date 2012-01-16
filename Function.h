#include<malloc.h>
#include<stdio.h>
#include<string.h>
#define Integer 0
#define Boolean 1
#define Continue 2
#define Read 3
#define Write 4 
#define Initialize 5
#define Digit 6
#define Variable 7
#define Addition 8
#define Subtraction 9
#define Multiplacation 10
#define Division 11
#define And 12
#define Or 13
#define Not 14
#define Equal 15
#define NotEqual 16
#define LessThen 17
#define LessThenEqual 18
#define GreaterThen 19
#define GreaterThenEqual 20
#define True 21
#define False 22
#define Void 23
#define Array 24
#define Decl 25

struct Gsymbol {

	char *NAME; // Name of the Identifier

	int TYPE; // TYPE can be INTEGER or BOOLEAN

	/***The TYPE field must be a TypeStruct if user defined types are allowed***/

	int SIZE; // Size field for arrays

	int BINDING; // Address of the Identifier in Memory

	//ArgStruct *ARGLIST; // Argument List for functions

	/***Argstruct must store the name and type of each argument ***/

	struct Gsymbol *NEXT; // Pointer to next Symbol Table Entry */

}*GTable;

typedef struct tnode {

	int TYPE; // Integer, Boolean or Void (for statements)
	/* Must point to the type expression tree for user defined types */

	int NODETYPE,OpType;
	/* this field should carry following information:
	* a) operator : (+,*,/ etc.) for expressions
	* b) statement Type : (WHILE, READ etc.) for statements */

	char NAME; // For Identifiers/Functions

	int VALUE; // for constants
	
	struct tnode *ArgList; // List of arguments for functions

	struct tnode *Ptr1, *Ptr2, *Ptr3;
	/* Maximum of three subtrees (3 required for IF THEN ELSE */

	struct Gsymbol *Gentry; // For global identifiers/functions

	//Lsymbol *Lentry; // For Local variables

}Tnode;


struct Gsymbol *Glookup(char *NAME); // Look up for a global identifier

struct Gsymbol *Ginstall(char *NAME,int TYPE,int SIZE)
{
	struct Gsymbol *Node = malloc(sizeof(struct Gsymbol));
	Node->NAME = malloc(sizeof(strlen(NAME)));
	strcpy(Node->NAME,NAME);
	Node->TYPE = TYPE;
	Node->SIZE = SIZE;
	Node->NEXT = GTable;
	GTable = Node;
	return Node;
}

Tnode *TreeCreate(int TYPE,int NODETYPE,int VALUE,char NAME,Tnode *ArgList,Tnode *Ptr1,Tnode *Ptr2,Tnode *Ptr3,int Optype)
{
	Tnode *Node=malloc(sizeof(Tnode));
	Node->TYPE = TYPE;
	Node->NODETYPE = NODETYPE;
	Node->VALUE = VALUE;
	Node->NAME = NAME;
	Node->ArgList = ArgList;
	Node->Ptr1 = Ptr1;
	Node->Ptr2 = Ptr2;
	Node->Ptr3 = Ptr3;
	Node->OpType = Optype;
	return Node;
}

int A[26];

int calculate(Tnode* Temp)
{
		switch(Temp->OpType)
		{
			case Addition: 
				return (calculate(Temp->Ptr1))+(calculate(Temp->Ptr2));
				
			case Subtraction: 
				return (calculate(Temp->Ptr1))-(calculate(Temp->Ptr2));
				
			case Multiplacation: 
				return (calculate(Temp->Ptr1))*(calculate(Temp->Ptr2));
				
			case Division: 
				return (calculate(Temp->Ptr1))/(calculate(Temp->Ptr2));
				
			case And:
				return (calculate(Temp->Ptr1))&&(calculate(Temp->Ptr2));
				
			case Or:
				return (calculate(Temp->Ptr1))||(calculate(Temp->Ptr2));
				
			case Equal:
				return (calculate(Temp->Ptr1))==(calculate(Temp->Ptr2));
				
			case NotEqual:
				return (calculate(Temp->Ptr1))!=(calculate(Temp->Ptr2));	
				
			case GreaterThen:
				return (calculate(Temp->Ptr1))>(calculate(Temp->Ptr2));
			
			case GreaterThenEqual:
				return (calculate(Temp->Ptr1))>=(calculate(Temp->Ptr2));
				
			case LessThen:
				return (calculate(Temp->Ptr1))<(calculate(Temp->Ptr2));
				
			case LessThenEqual:
				return (calculate(Temp->Ptr1))<=(calculate(Temp->Ptr2));
				
			case True:
				return 1;
				
			case False:
				return 0;
				
			case Digit:
					return Temp->VALUE;
			
			case Variable:
					return A[Temp->NAME - 'a']; 
		}
}
int Traverse(Tnode *Root)
{
	if(Root==NULL)
		return;
	struct Gsymbol *Temp;	
	switch(Root->OpType)
	{
		case Continue:
			Traverse(Root->Ptr1);
			Traverse(Root->Ptr2);
			break;
    
    	case Read:
    		scanf("%d",&A[Root->NAME - 'a']);
    		break;
    	
    	case Write:
    		Root->TYPE == Integer?printf("\n%d\n",calculate(Root->Ptr1)):printf("\n%s\n",calculate(Root->Ptr1) == 1?"TRUE":"FALSE");
   			break;
    	
    	case Initialize:
    		A[Root->NAME - 'a'] = calculate(Root->Ptr2);
    		break;
    		
    	case Decl:
    			Temp;
    			break;     
	}    
}
