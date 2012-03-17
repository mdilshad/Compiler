int Evaluate(LTABLE *LTable,Tnode* Node);

Tnode *TreeCreate(int TYPE,int VALUE,char *NAME,struct ArgStruct *ArgList,Tnode *Ptr1,Tnode *Ptr2,Tnode *Ptr3,int NODETYPE){
	Tnode *Node=malloc(sizeof(Tnode));
	Node->TYPE = TYPE;
	Node->NODETYPE = NODETYPE;
	Node->VALUE = VALUE;
	Node->NAME = NAME;
	Node->ArgList = ArgList;
	Node->Ptr1 = Ptr1;
	Node->Ptr2 = Ptr2;
	Node->Ptr3 = Ptr3;
	return Node;
}

void ArrangeFList(Field *FLIST){
	Field *Node,*x;
	for(Node = FLIST;Node;Node = Node->NEXT){
		if(Node->TYPE != Void)
			x = Node;
		Node->TYPE = x->TYPE;
		Node->TYPENAME = x->TYPENAME;
	}
}

TypeDef *Tcreate(char *NAME,Field *FLIST){
	TypeDef *Node = malloc(sizeof(TypeDef));
	Node->NAME = NAME;
	Node->FLIST = FLIST;
	ArrangeFList(FLIST);
	return Node;
}

Field *Fcreate(char *NAME,char *TYPENAME,int TYPE){
	Field *Node = malloc(sizeof(Field));
	Node->NAME = NAME;
	Node->TYPE = TYPE;
	if(TYPE == Typedef){
		Node->TYPENAME = malloc(sizeof(strlen(TYPENAME)));
		strcpy(Node->TYPENAME,TYPENAME);
	}
	return Node;
}

