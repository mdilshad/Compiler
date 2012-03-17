int regcount=0,labelcount=1,loccount,argloc,registers,vars,args;

int getreg(){
	return regcount++;
}

void freereg(){
	regcount--;
}

int getlabel(){
	return labelcount++;
}

int getloc(){
	return loccount++;
}

void setcounters(){
	loccount = 1;
	argloc = -1;
	registers = 0;
	vars = 0;
	args = 0;
}

int getargloc(){
	return argloc--;
}

void LinstallConvert(char *NAME,int TYPE,struct ArgStruct *ARGLIST){
	struct Lsymbol *Node = malloc(sizeof(struct Lsymbol));
	Node->NAME = NAME;
	Node->TYPE = TYPE;
	Node->flag = 0;
	Node->ARGLIST = ARGLIST;
	Node->BINDING = malloc(sizeof(int));
	Node->NEXT = LHead->Lentry;
	LHead->Lentry = Node;
}


void Glocation(){
	struct Gsymbol *Node=GTable;
	for(;Node;Node = Node->NEXT){

		switch(Node->TYPE){

			case Integer:
			case Boolean:
				Node->BINDING = malloc(sizeof(int));
				if(Node->ARGLIST == NULL){
					Node->BINDING[0] = getloc();
					loccount += Node->SIZE-1;
				}
				else
					Node->BINDING[0] = getlabel();
				break;

			case Typedef:
				break;

		}

	}
}

void LocalInstallConvert(Tnode* Node)
{
	if(Node == NULL)
		return;

	switch(Node->NODETYPE)
	{
		case Continue:
			LocalInstallConvert(Node->Ptr1);
			LocalInstallConvert(Node->Ptr2);
			LocalInstallConvert(Node->Ptr3);
			break;

		case Dstatement:
			temp1 = Node->Ptr1;
			LocalInstallConvert(Node->Ptr2);
			break;

		case Decl:
			LinstallConvert(Node->NAME,temp1->TYPE,NULL);
			LHead->Lentry->BINDING[0] = getloc();
			vars++;
			fprintf(fp,"MOV R0 0\n");
			fprintf(fp,"PUSH R0\n");
			break;

		case FunctionDecl:
			break;
	}
}
