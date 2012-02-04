struct Gsymbol *Ginstall(char *NAME,int TYPE,int SIZE,struct ArgStruct *ARGLIST)
{
	struct Gsymbol *Node = malloc(sizeof(struct Gsymbol));
	Node->NAME = malloc(sizeof(strlen(NAME)));
	strcpy(Node->NAME,NAME);
	Node->TYPE = TYPE;
	Node->SIZE = SIZE;
	Node->ARGLIST=ARGLIST;
	if(SIZE > 0)
		Node->BINDING = malloc(sizeof(int)*SIZE);
	else
		Node->BINDING = NULL;
	Node->NEXT = GTable;
	GTable = Node;
	return Node;
}

struct Lsymbol *Linstall(char *NAME,int TYPE,int SIZE)
{
	struct Lsymbol *Node = malloc(sizeof(struct Lsymbol));
	Node->NAME = malloc(sizeof(strlen(NAME)));
	strcpy(Node->NAME,NAME);
	Node->TYPE = TYPE;
	Node->SIZE = SIZE;
	Node->BINDING = malloc(sizeof(int)*SIZE);
	//Node->NEXT = GTable;
	//GTable = Node;
	return Node;
}

struct ArgStruct *Arginstall(Tnode *FNode)
{
	if(FNode != NULL)
		return NULL;
	struct ArgStruct *Node = malloc(sizeof(struct ArgStruct));
	Node->NAME = malloc(sizeof(strlen(FNode->NAME)));
	strcpy(Node->NAME,FNode->NAME);
	Node->TYPE = FNode->TYPE;
	Node->NEXT = Arginstall(FNode->Ptr1);
	return Node;
}

Tnode *TreeCreate(int TYPE,int VALUE,char *NAME,Tnode *ArgList,Tnode *Ptr1,Tnode *Ptr2,Tnode *Ptr3,int NODETYPE)
{
	Tnode *Node=malloc(sizeof(Tnode));
	Node->TYPE = TYPE;
	Node->NODETYPE = NODETYPE;
	Node->VALUE = VALUE;
	if(NAME != NULL)
	{
		Node->NAME = malloc(sizeof(strlen(NAME)));
		strcpy(Node->NAME,NAME);
	}
	else
		Node->NAME = NULL;
	Node->ArgList = ArgList;
	Node->Ptr1 = Ptr1;
	Node->Ptr2 = Ptr2;
	Node->Ptr3 = Ptr3;
	Node->Gentry = NULL;
	Node->Lentry = NULL;
	return Node;
}

struct Gsymbol *Glookup(char *NAME)// Look up for a global identifier
{
	struct Gsymbol *Node=GTable;
	while(Node)
	{
		if(strcmp(Node->NAME,NAME) == 0)
			return Node;
		Node = Node->NEXT;
	}
	return NULL;
} 
