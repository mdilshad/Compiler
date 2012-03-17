
int SemanticAnalysis(Tnode* Node)
{
	if(Node == NULL)
		return;

	struct Gsymbol *TEMP;
	struct Lsymbol *LTEMP;

	switch(Node->NODETYPE)
	{

		case Main:
			LHead = NULL;
			PUSH();
			LocalInstall(Node->Ptr1);
			SemanticAnalysis(Node->Ptr2);
			if(SemanticAnalysis(Node->Ptr3) != Integer){
					flag = 0;
					printf("Function %s's type is not Integer\n",LTEMP->NAME);
			}
			POP();
			break;

		case Continue:
			SemanticAnalysis(Node->Ptr1);
			SemanticAnalysis(Node->Ptr2);
			SemanticAnalysis(Node->Ptr3);
			break;

		case FunctionDef:
			LTEMP = LlookupSem(Node->NAME);
			if(LTEMP != NULL){
				if(LTEMP->flag == 1)
						printf("Function %s already declaired\n",LTEMP->NAME);
					else
						LTEMP->flag = 1;
					if(LTEMP->TYPE != Node->TYPE){
						printf("Function %s's type is not same as declaired\n",LTEMP->NAME);
						flag = 0;
					}
					Aflag = 1;
					ArgumentAnalysis(Node->ArgList,LTEMP->ARGLIST);
					if(Aflag == 0){
						printf("Function %s's arguments are not same as declaired\n",LTEMP->NAME);
						flag = 0;
					}
				PUSH();
				for(ArgTemp = LTEMP->ARGLIST;ArgTemp;ArgTemp = ArgTemp->NEXT)
					Linstall(ArgTemp->NAME,ArgTemp->TYPE,NULL);
				LocalInstall(Node->Ptr1);
				SemanticAnalysis(Node->Ptr2);
				if(SemanticAnalysis(Node->Ptr3) != LTEMP->TYPE){
					flag = 0;
					printf("Function %s's return type is not same as declaired\n",LTEMP->NAME);
				}
			}
			else{
				TEMP = Glookup(Node->NAME);
				if(TEMP == NULL){
					printf("Function not declaired previously\n");
					flag = 0;
				}
				else{
					if(TEMP->flag == 1)
						printf("Function %s already declaired\n",TEMP->NAME);
					else
						TEMP->flag = 1;
					if(TEMP->TYPE != Node->TYPE){
						printf("Function %s's type is not same as declaired\n",TEMP->NAME);
						flag = 0;
					}
					Aflag = 1;
					ArgumentAnalysis(Node->ArgList,TEMP->ARGLIST);
					if(Aflag == 0){
						printf("Function %s's arguments are not same as declaired\n",TEMP->NAME);
						flag = 0;
					}
				}
				TEMP->FNode = Node;
				LHead == NULL;
				PUSH();
				for(ArgTemp = TEMP->ARGLIST;ArgTemp;ArgTemp = ArgTemp->NEXT)
					Linstall(ArgTemp->NAME,ArgTemp->TYPE,NULL);
				LocalInstall(Node->Ptr1);
				SemanticAnalysis(Node->Ptr2);
				if(SemanticAnalysis(Node->Ptr3) != TEMP->TYPE){
					flag = 0;
					printf("Function %s's return type is not same as declaired\n",TEMP->NAME);
				}
			}
			POP();
			break;

		case Function:
			T = Glookup(Node->NAME);
			Aflag = 1;
			ParameterAnalysis(Node->ArgList,T->ARGLIST);
			if(Aflag == 0){
				printf("Function %s's parameter types are not same as declaired\n",T->NAME);
				flag = 0;
			}
			return T->TYPE;

		case Addition:
		case Subtraction:
		case Multiplacation:
		case Division:
		case Remainder:
			if(SemanticAnalysis(Node->Ptr1) != Integer || SemanticAnalysis(Node->Ptr2) != Integer){
				printf("Arithmatic Operation have boolean Expression\n");
				flag = 0;
			}
			return Integer;

		case And:
		case Or:
			if(SemanticAnalysis(Node->Ptr1) != Boolean || SemanticAnalysis(Node->Ptr2) != Boolean){
				printf("Boolean Operation have Arithmatic Expression\n");
				flag = 0;
				}
			return Boolean;

		case Not:
			if(SemanticAnalysis(Node->Ptr1) != Boolean){
				printf("Boolean Operation have Arithmatic Expression\n");
				flag = 0;
				}
			return Boolean;

		case Equal:
		case NotEqual:
		case GreaterThen:
		case GreaterThenEqual:
		case LessThen:
		case LessThenEqual:
			if(SemanticAnalysis(Node->Ptr1) != SemanticAnalysis(Node->Ptr2) ){
				printf("Boolean Operation have Different kind of Expression\n");
				flag = 0;
				}
			return Boolean;

		case True:
		case False:
			return Boolean;

		case Digit:
			return Integer;


		case ArrayVariable:
			if(SemanticAnalysis(Node->Ptr1) != Integer){
				printf("Array Position is not Arithmatic\n");
				flag = 0;
			}

		case Variable:
			LTEMP = LlookupSem(Node->NAME);
			if(LTEMP != NULL)
				return LTEMP->TYPE;
			else{
				TEMP = Glookup(Node->NAME);
				if(TEMP != NULL)
					return TEMP->TYPE;
				else{
					printf("Variable %s not Exist \n",Node->NAME);
					flag=0;
				}
			}break;

		case Read:
			LTEMP = LlookupSem(Node->Ptr1->NAME);
			if(LTEMP == NULL){
				TEMP = Glookup(Node->Ptr1->NAME);
				if(TEMP == NULL){
					printf("Variable %s not Exist \n",Node->Ptr1->NAME);
					flag=0;
				}
				else if(TEMP->TYPE != Integer){
					printf("Reading other then Integer variable\n");
					flag = 0;
				}
			}
			else if(LTEMP->TYPE != Integer){
				printf("Reading other then Integer variable\n");
				flag = 0;
			}
			break;

		case Conditional:
			if(SemanticAnalysis(Node->Ptr1) != Boolean){
				printf("Condition in conditional statement is not Boolean Expression\n");
				flag = 0;
			}
			SemanticAnalysis(Node->Ptr2);
			SemanticAnalysis(Node->Ptr3);
			break;

		case Iterative:
			if(SemanticAnalysis(Node->Ptr1) != Boolean){
				printf("Condition in loop is not Boolean Expression\n");
				flag = 0;
			}
			SemanticAnalysis(Node->Ptr2);
			break;

		case Write:
			if(SemanticAnalysis(Node->Ptr1) != Integer){
				printf("Writing Boolean Expression\n");
				flag = 0;
			}
			break;

		case Initialize:
			LTEMP = LlookupSem(Node->Ptr1->NAME);
			if(LTEMP == NULL){
				TEMP = Glookup(Node->Ptr1->NAME);
				if(TEMP == NULL){
					printf("Variable %s not Exist \n",Node->Ptr1->NAME);
					flag=0;
				}
				else if(SemanticAnalysis(Node->Ptr2) != TEMP->TYPE){
					printf("Initialization of different type of Expression and variable\n");
					flag = 0;
				}
			}
			else if(SemanticAnalysis(Node->Ptr2) != LTEMP->TYPE){
				printf("Initialization of different type of Expression and variable\n");
				flag = 0;
			}
			break;

	}
}

void GlobalInstall(Tnode* Node)
{
	if(Node == NULL)
		return;
	struct ArgStruct *ArgList;
	switch(Node->NODETYPE)
	{
		case Continue:
			GlobalInstall(Node->Ptr1);
			GlobalInstall(Node->Ptr2);
			GlobalInstall(Node->Ptr3);
			break;

		case Dstatement:
			temp1 = Node->Ptr1;
			GlobalInstall(Node->Ptr2);
			break;

		case Array:
			if(Node->VALUE < 1){
				flag = 0;
				printf("Array variable %s have less size \n",Node->NAME);
			}

		case Decl:
			if(Glookup(Node->NAME)){
				flag = 0;
				printf("Variable %s already Exist \n",Node->NAME);
			}
			else
				Ginstall(Node->NAME,temp1->NAME,temp1->TYPE,Node->VALUE,NULL);
			GlobalInstall(Node->Ptr1);
			break;

		case Pointer:
			if(Glookup(Node->NAME)){
				flag = 0;
				printf("Pointer variable %s already Exist \n",Node->NAME);
			}
			else
				Ginstall(Node->NAME,temp1->NAME,temp1->TYPE,Node->VALUE,NULL);
			break;

		case FunctionDecl:
			if(Glookup(Node->NAME)){
				flag =0;
				printf("Function %s already Exist \n",Node->NAME);
			}
			else{
				Ginstall(Node->NAME,temp1->NAME,temp1->TYPE,0,Node->ArgList);
			}
			break;
	}
}

