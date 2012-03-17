
struct Lsymbol *Llookup(struct Lsymbol *LTable,char *NAME){// Look up for a Local identifier in Local Table
	struct Lsymbol *Node=LTable;
	while(Node){
		if(strcmp(Node->NAME,NAME) == 0)
			return Node;
		Node = Node->NEXT;
	}
	return NULL;
}

struct Lsymbol *LTlookup(LTABLE *LHead,char *NAME){// Look up for a Local identifier in Local Table List
	LTABLE *Node=LHead;
	struct Lsymbol *Temp;
	while(Node){
		Temp = Llookup(Node->Lentry,NAME);
		if(Temp)
			return Temp;
		Node = Node->NEXT;
	}
	return NULL;
}

void LinstallArgs(struct Lsymbol **LTable,struct ArgStruct *ARGLIST,int VALUE){
	struct Lsymbol *Node = malloc(sizeof(struct Lsymbol));
	Node->NAME = ARGLIST->NAME;
	Node->TYPE = ARGLIST->TYPE;
	Node->BINDING = malloc(sizeof(int));
	Node->BINDING[0] = VALUE;
	Node->NEXT = *LTable;
	*LTable = Node;
}

void LinstallRefArgs(struct Lsymbol **LTable,struct ArgStruct *ARGLIST,int *BINDING){
	struct Lsymbol *Node = malloc(sizeof(struct Lsymbol));
	Node->NAME = ARGLIST->NAME;
	if(ARGLIST->TYPE == RefInt)
		Node->TYPE = Integer;
	else
		Node->TYPE = Boolean;
	Node->BINDING = BINDING;
	Node->NEXT = *LTable;
	*LTable = Node;
}

void installArgs(LTABLE *LTable,LTABLE *LTableP,struct ArgStruct *ARGLIST,struct ArgStruct *PARALIST){
	if(ARGLIST == NULL )
		return;
	if(ARGLIST->TYPE == RefInt || ARGLIST->TYPE == RefBool){
		L = LTlookup(LTableP,PARALIST->NAME);
		if(L != NULL)
			LinstallRefArgs(&LTable->Lentry,ARGLIST,L->BINDING);
		else{
			T = Glookup(PARALIST->NAME);
			LinstallRefArgs(&LTable->Lentry,ARGLIST,T->BINDING);
		}
	}
	else
		LinstallArgs(&LTable->Lentry,ARGLIST,Evaluate(LTableP,PARALIST->EXP));
	installArgs(LTable,LTableP,ARGLIST->NEXT,PARALIST->NEXT);
}

void LinstallDynamic(struct Lsymbol **LTable,char *NAME,int TYPE,struct ArgStruct *ARGLIST){
	struct Lsymbol *Node = malloc(sizeof(struct Lsymbol));
	Node->NAME = NAME;
	Node->TYPE = TYPE;
	Node->ARGLIST = ARGLIST;
	Node->BINDING = malloc(sizeof(int));
	Node->NEXT = *LTable;
	*LTable = Node;
}

void ALLOCATE(LTABLE **LHead){
	*LHead = malloc(sizeof(LTABLE));
}

void DEALLOCATE(LTABLE *LHead){
	FreeTable(LHead->Lentry);
}

