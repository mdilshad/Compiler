void Gallocate(){
	struct Gsymbol *Node=GTable;
	for(;Node;Node = Node->NEXT){

		switch(Node->TYPE){

			case Integer:
			case Boolean:
				if(Node->ARGLIST == NULL)
					Node->BINDING = malloc(sizeof(int)*Node->SIZE);
				break;

			case Typedef:
				GinstallType(Node);
				break;

		}

	}
}

struct ArgStruct *Argcreate(char *NAME,int TYPE,Tnode *EXP){
	struct ArgStruct *Node = malloc(sizeof(struct ArgStruct));
	Node->NAME = NAME;
	Node->TYPE = TYPE;
	Node->EXP = EXP;
	return Node;
}

void Ginstall(char *NAME,char *TYPENAME,int TYPE,int SIZE,struct ArgStruct *ARGLIST){
	struct Gsymbol *Node = malloc(sizeof(struct Gsymbol));
	Node->NAME = NAME;
	Node->TYPENAME = TYPENAME;
	Node->TYPE = TYPE;
	Node->SIZE = SIZE;
	Node->ARGLIST = ARGLIST;
	Node->BINDING = malloc(sizeof(int));
	Node->BINDING = NULL;
	Node->NEXT = GTable;
	GTable = Node;
}

struct Gsymbol *Glookup(char *NAME){// Look up for a global identifier
	struct Gsymbol *Node=GTable;
	while(Node){
		if(strcmp(Node->NAME,NAME) == 0)
			return Node;
		Node = Node->NEXT;
	}
	return NULL;
}



