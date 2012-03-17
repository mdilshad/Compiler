
void Linstall(char *NAME,int TYPE,struct ArgStruct *ARGLIST){
	struct Lsymbol *Node = malloc(sizeof(struct Lsymbol));
	Node->NAME = NAME;
	Node->TYPE = TYPE;
	Node->flag = 0;
	Node->ARGLIST = ARGLIST;
	Node->BINDING = NULL;
	Node->NEXT = LHead->Lentry;
	LHead->Lentry = Node;
}

void ArgumentAnalysis(struct ArgStruct *Node,struct ArgStruct *ANode){
	if(Node == NULL)
		return;
	if(strcmp(Node->NAME,ANode->NAME))
		Aflag=0;
	if(Node->TYPE != ANode->TYPE)
		Aflag=0;
	ArgumentAnalysis(Node->NEXT,ANode->NEXT);
}

void ParameterAnalysis(struct ArgStruct *PNode,struct ArgStruct *ANode){
	if(PNode == NULL)
		return;
	else{
		if(SemanticAnalysis(PNode->EXP) != ANode->TYPE)
			i=0;
		ParameterAnalysis(PNode->NEXT,ANode->NEXT);
	}
}

struct Lsymbol *LTlookupSem(struct Lsymbol *Node,char *NAME){// Look up for a Local identifier Semantic Analysis
	while(Node){
		if(strcmp(Node->NAME,NAME) == 0)
			return Node;
		Node = Node->NEXT;
	}
	return NULL;
}

struct Lsymbol *LlookupSem(char *NAME){// Look up for a Local identifier Semantic Analysis
	LTABLE *Node = LHead;
		struct Lsymbol *Temp;
	while(Node){
		Temp = LTlookupSem(Node->Lentry,NAME);
		if(Temp != NULL)
			return Temp;
		Node = Node->NEXT;
	}
	return NULL;
}


void FreeArgs(struct ArgStruct *Args){
	struct ArgStruct *Temp;
	while(Args){
		Temp = Args;
		Args = Args->NEXT;
		free(Temp);
	}
}

void FreeTable(struct Lsymbol *Lentry){
	struct Lsymbol *Temp;
	while(Lentry){
		Temp = Lentry;
		if(Lentry->ARGLIST != NULL)
			FreeArgs(Lentry->ARGLIST);
		Lentry = Lentry->NEXT;
		free(Temp);
	}
}

void PUSH(){
	LTABLE *Node = malloc(sizeof(LTABLE));
	Node->NEXT = LHead;
	LHead = Node;
}

void POP(){
	LTABLE *Node = LHead;
	LHead = LHead->NEXT;
	FreeTable(Node->Lentry);
	free(Node);
}

void LocalInstall(Tnode* Node)
{
	if(Node == NULL)
		return;

	switch(Node->NODETYPE)
	{
		case Continue:
			LocalInstall(Node->Ptr1);
			LocalInstall(Node->Ptr2);
			LocalInstall(Node->Ptr3);
			break;

		case Dstatement:
			temp1 = Node->Ptr1;
			LocalInstall(Node->Ptr2);
			break;

		case Decl:
			if(LlookupSem(Node->NAME))
				printf("Variable %s already Exist \n",Node->NAME);
			else
				Linstall(Node->NAME,temp1->TYPE,NULL);
			break;

		case FunctionDecl:
			if(LlookupSem(Node->NAME))
				printf("Function %s already Exist \n",Node->NAME);
			else{
				Linstall(Node->NAME,temp1->TYPE,Node->ArgList);
			}
			LocalInstall(Node->Ptr1);
			break;
	}
}
