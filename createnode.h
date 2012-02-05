int Evaluate(struct Lsymbol *LTable,Tnode* Node);

struct Gsymbol *Glookup(char *NAME){// Look up for a global identifier
	struct Gsymbol *Node=GTable;
	while(Node){
		if(strcmp(Node->NAME,NAME) == 0)
			return Node;
		Node = Node->NEXT;
	}
	return NULL;
} 

struct Lsymbol *Llookup(struct Lsymbol *LTable,char *NAME){// Look up for a Local identifier
	struct Lsymbol *Node=LTable;
	while(Node){
		if(strcmp(Node->NAME,NAME) == 0)
			return Node;
		Node = Node->NEXT;
	}
	return NULL;
}

void Ginstall(char *NAME,int TYPE,int SIZE,struct ArgStruct *ARGLIST){
	struct Gsymbol *Node = malloc(sizeof(struct Gsymbol));
	Node->NAME = malloc(sizeof(strlen(NAME)));
	strcpy(Node->NAME,NAME);
	Node->TYPE = TYPE;
	Node->SIZE = SIZE;
	Node->ARGLIST = ARGLIST;
	if(SIZE > 0)
		Node->BINDING = malloc(sizeof(int)*SIZE);
	else
		Node->BINDING = NULL;
	Node->NEXT = GTable;
	GTable = Node;
}

void LinstallArgs(struct Lsymbol **LTable,struct ArgStruct *ARGLIST,int VALUE){
	struct Lsymbol *Node = malloc(sizeof(struct Lsymbol));
	Node->NAME = malloc(sizeof(strlen(ARGLIST->NAME)));
	strcpy(Node->NAME,ARGLIST->NAME);
	Node->SIZE = 1;
	Node->TYPE = ARGLIST->TYPE;
	Node->BINDING = malloc(sizeof(int));
	Node->BINDING[0] = VALUE;
	Node->NEXT = *LTable;
	*LTable = Node;
}

void LinstallRefArgs(struct Lsymbol **LTable,struct ArgStruct *ARGLIST,int *BINDING){
	struct Lsymbol *Node = malloc(sizeof(struct Lsymbol));
	Node->NAME = malloc(sizeof(strlen(ARGLIST->NAME)));
	strcpy(Node->NAME,ARGLIST->NAME);
	Node->SIZE = 1;
	if(ARGLIST->TYPE == RefInt)
		Node->TYPE = Integer;
	else
		Node->TYPE = Boolean;
	Node->BINDING = BINDING;
	Node->NEXT = *LTable;
	*LTable = Node;
}

void installArgs(struct Lsymbol **LTable,struct Lsymbol *LTableP,struct ArgStruct *ARGLIST,Tnode *Root){
	if(Root == NULL )
		return;
	if(ARGLIST->TYPE == RefInt || ARGLIST->TYPE == RefBool){
		L = Llookup(LTableP,Root->NAME);
		if(L != NULL)
			LinstallRefArgs(LTable,ARGLIST,L->BINDING);
		else{
			T = Glookup(Root->NAME);
			//LinstallRefArgs(LTable,ARGLIST,T->BINDING);
		}
	}
	else
		LinstallArgs(LTable,ARGLIST,Evaluate(LTableP,Root->Ptr1));
	installArgs(LTable,LTableP,ARGLIST->NEXT,Root->Ptr2);
}

void Linstall(struct Lsymbol **LTable,char *NAME,int TYPE){
	struct Lsymbol *Node = malloc(sizeof(struct Lsymbol));
	Node->NAME = malloc(sizeof(strlen(NAME)));
	strcpy(Node->NAME,NAME);
	Node->TYPE = TYPE;
	Node->SIZE = 0;
	Node->BINDING = NULL;
	Node->NEXT = *LTable;
	*LTable = Node;
}

void LinstallDynamic(struct Lsymbol **LTable,char *NAME,int TYPE,int SIZE){
	struct Lsymbol *Node = malloc(sizeof(struct Lsymbol));
	Node->NAME = malloc(sizeof(strlen(NAME)));
	strcpy(Node->NAME,NAME);
	Node->TYPE = TYPE;
	Node->SIZE = SIZE;
	Node->BINDING = malloc(sizeof(int)*SIZE);
	Node->NEXT = *LTable;
	*LTable = Node;
}

struct ArgStruct *Arginstall(Tnode *FNode){
	if(FNode == NULL)
		return NULL;
	struct ArgStruct *Node = malloc(sizeof(struct ArgStruct));
	Node->NAME = malloc(sizeof(strlen(FNode->NAME)));
	strcpy(Node->NAME,FNode->NAME);
	Node->TYPE = FNode->TYPE;
	Node->NEXT = Arginstall(FNode->Ptr1);
	return Node;
}

Tnode *TreeCreate(int TYPE,int VALUE,char *NAME,Tnode *ArgList,Tnode *Ptr1,Tnode *Ptr2,Tnode *Ptr3,int NODETYPE){
	Tnode *Node=malloc(sizeof(Tnode));
	Node->TYPE = TYPE;
	Node->NODETYPE = NODETYPE;
	Node->VALUE = VALUE;
	if(NAME != NULL){
		Node->NAME = malloc(sizeof(strlen(NAME)));
		strcpy(Node->NAME,NAME);
	}
	else
		Node->NAME = NULL;
	Node->ArgList = ArgList;
	Node->Ptr1 = Ptr1;
	Node->Ptr2 = Ptr2;
	Node->Ptr3 = Ptr3;
	return Node;
}

 
