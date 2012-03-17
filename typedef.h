
TypeDef *Tlookup(char *NAME){// Look up for a typedef
	TypeDef *Node=TypeTable;
	while(Node){
		if(strcmp(Node->NAME,NAME) == 0)
			return Node;
		Node = Node->NEXT;
	}
	return NULL;
}

struct Gsymbol *TypeLookupG(struct Gsymbol **GNode,struct ArgStruct *VNode,int POSITION){
	struct Gsymbol *GTemp;
	GTemp = GNode[POSITION];
	while(GTemp){
		if(!strcmp(GTemp->NAME,VNode->NAME))
			break;
		GTemp = GTemp->NEXT;
	}
	if(VNode->NEXT != NULL)
		return TypeLookupG(GTemp->Tentry,VNode->NEXT,0);
	return GTemp;
}

struct Lsymbol *TypeLookupL(struct Lsymbol *LNode,struct ArgStruct *VNode){
	struct Lsymbol *LTemp;
	LTemp = LNode;
	while(LTemp){
		if(!strcmp(LTemp->NAME,VNode->NAME))
			break;
		LTemp = LTemp->NEXT;
	}
	if(VNode->NEXT != NULL)
		return TypeLookupL(LTemp->Tentry,VNode->NEXT);
	return LTemp;
}


struct Gsymbol *FieldInstallG(Field *FNode){
	if(FNode == NULL)
		return NULL;
	struct Gsymbol *Node;
	Node = malloc(sizeof(struct Gsymbol));
	Node->NAME = FNode->NAME;
	Node->TYPE = FNode->TYPE;
	Node->TYPENAME = FNode->TYPENAME;
	Node->SIZE = 1;
	Node->ARGLIST = NULL;
	if(FNode->TYPE != Typedef){
		Node->BINDING = malloc(sizeof(int));
		Node->Tentry = NULL;
	}
	else{
		Node->BINDING = NULL;
		Node->Tentry = malloc(sizeof(*Node->Tentry));
		TD = Tlookup(FNode->TYPENAME);
		Node->Tentry[0] = FieldInstallG(TD->FLIST);
	}
	Node->NEXT = FieldInstallG(FNode->NEXT);
	return Node;
}


void GinstallType(struct Gsymbol *Node){
	TD = Tlookup(Node->TYPENAME);
	Node->Tentry = malloc(sizeof(struct Gsymbol *)*Node->SIZE);
	for(i=0;i<Node->SIZE;i++){
		Node->Tentry[i] = FieldInstallG(TD->FLIST);
	}
	Node->BINDING = NULL;
}

struct Lsymbol *FieldInstallL(Field *FNode){
	if(FNode == NULL)
		return NULL;
	struct Lsymbol *Node;
	Node = malloc(sizeof(struct Lsymbol));
	Node->NAME = FNode->NAME;
	Node->TYPENAME = FNode->TYPENAME;
	Node->TYPE = FNode->TYPE;
	Node->ARGLIST = NULL;
	if(FNode->TYPE != Typedef){
		Node->BINDING = malloc(sizeof(int));
		Node->Tentry = NULL;
	}
	else{
		Node->BINDING = NULL;
		Node->Tentry = malloc(sizeof(*Node->Tentry));
		TD = Tlookup(FNode->TYPENAME);
		Node->Tentry = FieldInstallL(TD->FLIST);
	}
	Node->NEXT = FieldInstallL(FNode->NEXT);
	return Node;
}

void LinstallType(LTABLE *LTList,Tnode *TypeNode,Tnode *TNode){
	struct Lsymbol *Node;
	Node = malloc(sizeof(struct Lsymbol));
	TD = Tlookup(TypeNode->NAME);
	Node->NAME = TNode->NAME;
	Node->TYPE = Typedef;
	Node->TYPENAME = TypeNode->NAME;
	Node->Tentry = FieldInstallL(TD->FLIST);
	Node->BINDING = NULL;
	Node->NEXT = LTList->Lentry;
	LTList->Lentry = Node;
}

void LcopyL(struct Lsymbol *Node1,struct Lsymbol *Node2){
	while(Node1){
		if(Node1->TYPE != Typedef)
			Node1->BINDING[0] = Node2->BINDING[0];
		else
			LcopyL(Node1->Tentry,Node2->Tentry);
		Node1 = Node1->NEXT;
		Node2 = Node2->NEXT;
	}
}

void LcopyG(struct Lsymbol *Node1,struct Gsymbol *Node2){
	while(Node1){
		if(Node1->TYPE != Typedef)
			Node1->BINDING[0] = Node2->BINDING[0];
		else
			LcopyG(Node1->Tentry,Node2->Tentry[0]);
		Node1 = Node1->NEXT;
		Node2 = Node2->NEXT;
	}
}

void GcopyL(struct Gsymbol *Node1,struct Lsymbol *Node2){
	while(Node1){
		if(Node1->TYPE != Typedef)
			Node1->BINDING[0] = Node2->BINDING[0];
		else
			GcopyL(Node1->Tentry[0],Node2->Tentry);
		Node1 = Node1->NEXT;
		Node2 = Node2->NEXT;
	}
}

void GcopyG(struct Gsymbol *Node1,struct Gsymbol *Node2){
	while(Node1){
		if(Node1->TYPE != Typedef)
			Node1->BINDING[0] = Node2->BINDING[0];
		else
			GcopyG(Node1->Tentry[0],Node2->Tentry[0]);
		Node1 = Node1->NEXT;
		Node2 = Node2->NEXT;
	}
}

