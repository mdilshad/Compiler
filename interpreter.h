int Evaluate(LTABLE *LTList,Tnode* Node){
	if(Node == NULL)
		return 0;
	
	LTABLE *LTable = NULL;
	struct Gsymbol *T;
	struct Lsymbol *L;
	int temp;
	switch(Node->NODETYPE){

		case Function:
			LTEMP = LTlookup(LTList,Node->NAME);
			if(LTEMP != NULL){
				ALLOCATE(&LTable);
				LTable->NEXT = LTList;
				installArgs(LTable,LTList,LTEMP->ARGLIST,Node->ArgList);
				Traverse(LTable,LTEMP->FNode->Ptr1);
				Traverse(LTable,LTEMP->FNode->Ptr2);
				temp = Evaluate(LTable,LTEMP->FNode->Ptr3);
				DEALLOCATE(LTable);
			}
			else{
				TEMP = Glookup(Node->NAME);
				ALLOCATE(&LTable);
				installArgs(LTable,LTList,TEMP->ARGLIST,Node->ArgList);
				Traverse(LTable,TEMP->FNode->Ptr1); 
				Traverse(LTable,TEMP->FNode->Ptr2);
				temp = Evaluate(LTable,TEMP->FNode->Ptr3);
				DEALLOCATE(LTable);
			}
			return temp;

		case Addition:
			return (Evaluate(LTList,Node->Ptr1))+(Evaluate(LTList,Node->Ptr2));

		case Subtraction:
			return (Evaluate(LTList,Node->Ptr1))-(Evaluate(LTList,Node->Ptr2));

		case Multiplacation:
			return (Evaluate(LTList,Node->Ptr1))*(Evaluate(LTList,Node->Ptr2));

		case Division:
			return (Evaluate(LTList,Node->Ptr1))/(Evaluate(LTList,Node->Ptr2));

		case Remainder: 
			return (Evaluate(LTList,Node->Ptr1))%(Evaluate(LTList,Node->Ptr2));

		case And:
			return (Evaluate(LTList,Node->Ptr1))&&(Evaluate(LTList,Node->Ptr2));

		case Or:
			return (Evaluate(LTList,Node->Ptr1))||(Evaluate(LTList,Node->Ptr2));

		case Equal:
			return (Evaluate(LTList,Node->Ptr1))==(Evaluate(LTList,Node->Ptr2));

		case NotEqual:
			return (Evaluate(LTList,Node->Ptr1))!=(Evaluate(LTList,Node->Ptr2));	

		case GreaterThen:
			return (Evaluate(LTList,Node->Ptr1))>(Evaluate(LTList,Node->Ptr2));

		case GreaterThenEqual:
			return (Evaluate(LTList,Node->Ptr1))>=(Evaluate(LTList,Node->Ptr2));

		case LessThen:
			return (Evaluate(LTList,Node->Ptr1))<(Evaluate(LTList,Node->Ptr2));

		case LessThenEqual:
			return (Evaluate(LTList,Node->Ptr1))<=(Evaluate(LTList,Node->Ptr2));

		case True:
			return 1;

		case False:
			return 0;

		case Digit:
			return Node->VALUE;

		case Variable:
			L = LTlookup(LTList,Node->NAME);
			if(L != NULL){
				if(L->TYPE == Typedef)
					L = TypeLookupL(L->Tentry,Node->ArgList);
				return L->BINDING[0];
			}
			else {
				T = Glookup(Node->NAME);
				if(T->TYPE == Typedef)
					T = TypeLookupG(T->Tentry,Node->ArgList,0);
				return T->BINDING[0];
			}

		case ArrayVariable:
			T = Glookup(Node->NAME);
				if(T->TYPE == Typedef){
					T = TypeLookupG(T->Tentry,Node->ArgList,Evaluate(LTList,Node->Ptr1));
					return T->BINDING[0];
				}
			return T->BINDING[Evaluate(LTList,Node->Ptr1)];

		}

}

void Dinstall(LTABLE *LTList,Tnode *TypeNode,Tnode *DNode){
	if(DNode==NULL)
		return;
	switch(DNode->NODETYPE) {

		case Continue:
			Dinstall(LTList,TypeNode,DNode->Ptr1);
			Dinstall(LTList,TypeNode,DNode->Ptr2);
			break;

		case Decl:
		case FunctionDecl:
			if(TypeNode->TYPE == Typedef)
				LinstallType(LTList,TypeNode,DNode);
			else
				LinstallDynamic(&(LTList->Lentry),DNode->NAME,TypeNode->TYPE,DNode->ArgList);
			break;

	}
}

int Traverse(LTABLE *LTList,Tnode *Root){
	if(Root==NULL)
		return;

	struct Gsymbol *GTemp,*T = NULL;
	struct Lsymbol *LTemp,*L = NULL;

	switch(Root->NODETYPE) {

		case Continue:
		case Main:
			Traverse(LTList,Root->Ptr1);
			Traverse(LTList,Root->Ptr2);
			Traverse(LTList,Root->Ptr3);
			break;

		case Dstatement:
			Dinstall(LTList,Root->Ptr1,Root->Ptr2);
			break;

		case FunctionDef:
			LTEMP = LTlookup(LTList,Root->NAME);
			LTEMP->FNode = Root;
			break;


		case Read:
			L = LTlookup(LTList,Root->Ptr1->NAME);
			if(L != NULL){
				if(L->TYPE == Typedef)
					L = TypeLookupL(L->Tentry,Root->Ptr1->ArgList);
					scanf("%d",&L->BINDING[0]);
				}
			else {
				T = Glookup(Root->Ptr1->NAME);
				if(T->TYPE == Typedef){
					T = TypeLookupG(T->Tentry,Root->Ptr1->ArgList,Evaluate(LTList,Root->Ptr1->Ptr1));
					scanf("%d",&T->BINDING[0]);
				}
				else
					scanf("%d",&T->BINDING[Evaluate(LTList,Root->Ptr1->Ptr1)]);
			}
			break;

		case Conditional:
			if(Evaluate(LTList,Root->Ptr1))
				Traverse(LTList,Root->Ptr2);
			else
				Traverse(LTList,Root->Ptr3);
			break;

		case Iterative:
			while(Evaluate(LTList,Root->Ptr1)) 
				Traverse(LTList,Root->Ptr2);
			break;

		case Write:
			printf("%d\n",Evaluate(LTList,Root->Ptr1));
			break;

		case Function:
			Evaluate(LTList,Root);
			break;

		case Initialize:
			L = LTlookup(LTList,Root->Ptr1->NAME);
			if(L != NULL){
				if(L->TYPE == Typedef && Root->Ptr1->ArgList)
					L = TypeLookupL(L->Tentry,Root->Ptr1->ArgList);
				if(L->TYPE != Typedef)
					L->BINDING[0] = Evaluate(LTList,Root->Ptr2);
				else{
					LTemp = LTlookup(LTList,Root->Ptr2->NAME);
					if(LTemp != NULL){
						if(Root->Ptr2->ArgList)
							LTemp = TypeLookupL(L->Tentry,Root->Ptr2->ArgList);
						LcopyL(L->Tentry,LTemp->Tentry);
					}
					else{
						T = Glookup(Root->Ptr2->NAME);
						if(Root->Ptr2->ArgList)
							T = TypeLookupG(T->Tentry,Root->Ptr2->ArgList,Evaluate(LTList,Root->Ptr2->Ptr1));
						LcopyG(L->Tentry,T->Tentry[Evaluate(LTList,Root->Ptr2->Ptr1)]);
					}
				}
			}
			else {
				T = Glookup(Root->Ptr1->NAME);
				if(T->TYPE == Typedef && Root->Ptr1->ArgList)
					T = TypeLookupG(T->Tentry,Root->Ptr1->ArgList,Evaluate(LTList,Root->Ptr1->Ptr1));
				if(T->TYPE != Typedef)
					T->BINDING[Evaluate(LTList,Root->Ptr1->Ptr1)] = Evaluate(LTList,Root->Ptr2);
				else{
					LTemp = LTlookup(LTList,Root->Ptr2->NAME);
					if(LTemp != NULL){
						if(Root->Ptr2->ArgList)
							LTemp = TypeLookupL(L->Tentry,Root->Ptr2->ArgList);
						GcopyL(T->Tentry[Evaluate(LTList,Root->Ptr1->Ptr1)],LTemp->Tentry);
					}
					else{
						GTemp = Glookup(Root->Ptr2->NAME);
						if(Root->Ptr2->ArgList)
							GTemp = TypeLookupG(GTemp->Tentry,Root->Ptr2->ArgList,Evaluate(LTList,Root->Ptr2->Ptr1));
						GcopyG(T->Tentry[Evaluate(LTList,Root->Ptr1->Ptr1)],GTemp->Tentry[Evaluate(LTList,Root->Ptr2->Ptr1)]);
					}
				}
			}
			break;

	}

}
