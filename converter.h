int Generate(Tnode* Node)
{
	if(Node == NULL)
		return;

	int r,r1,r2,loc;
	struct Gsymbol *TEMP;
	struct Lsymbol *LTEMP;

	switch(Node->NODETYPE)
	{

		case Main:
			fprintf(fp,"\nSTART\n");
			fprintf(fp,"MOV SP 100\n");
			fprintf(fp,"MOV BP SP\n");
			setcounters();
			PUSH();
			LocalInstallConvert(Node->Ptr1);
			Generate(Node->Ptr2);
			Generate(Node->Ptr3);
			while(vars > 0){
				fprintf(fp,"POP R0\n");
				vars --;
			}
			fprintf(fp,"HALT\n\n");
			POP();
			break;

		case Continue:
			Generate(Node->Ptr1);
			Generate(Node->Ptr2);
			Generate(Node->Ptr3);
			break;

		case FunctionDef:
			TEMP = Glookup(Node->NAME);
			fprintf(fp,"\nLABEL%d:\n",TEMP->BINDING[0]);
			fprintf(fp,"PUSH BP\n");
			fprintf(fp,"MOV BP SP\n");
			setcounters();
			PUSH();
			for(ArgTemp = TEMP->ARGLIST;ArgTemp;ArgTemp = ArgTemp->NEXT){
				LinstallConvert(ArgTemp->NAME,ArgTemp->TYPE,NULL);
				LHead->Lentry->BINDING[0] = getargloc();
			}
			LocalInstallConvert(Node->Ptr1);
			Generate(Node->Ptr2);
			r = Generate(Node->Ptr3);
			while(vars > 0){
				fprintf(fp,"POP R%d\n",r+1);
				vars --;
			}
			fprintf(fp,"POP BP\n");
			fprintf(fp,"RET\n\n");
			freereg();
			POP();
			break;

		case Function:
			while(regcount > 0){
				r = regcount-1;
				registers++;
				fprintf(fp,"PUSH R%d\n",r);
				freereg();
			}
			for(ArgTemp = Node->ArgList;ArgTemp;ArgTemp = ArgTemp->NEXT){
				args++;
				r = Generate(ArgTemp->EXP);
				fprintf(fp,"PUSH R%d\n",r);
			}
			TEMP = Glookup(Node->NAME);
			fprintf(fp,"CALL LABEL%d\n",TEMP->BINDING[0]);
			while(args > 0){
				fprintf(fp,"POP R%d\n",r+1);
				args--;
			}
			fprintf(fp,"MOV R%d R%d\n",registers,r);
			while(registers > 0){
				r = getreg();
				fprintf(fp,"POP R%d\n",registers-1);
				registers--;
			}
			break;

		case Addition:
			r = Generate(Node->Ptr1);
			Generate(Node->Ptr2);
			fprintf(fp,"ADD R%d R%d\n",r,r+1);
			freereg();
			return r;

		case Subtraction: 
			r =  Generate(Node->Ptr1);
			Generate(Node->Ptr2);
			fprintf(fp,"SUB R%d R%d\n",r,r+1);
			freereg();
			return r;

		case Multiplacation: 
			r = Generate(Node->Ptr1);
			Generate(Node->Ptr2);
			fprintf(fp,"MUL R%d R%d\n",r,r+1);
			freereg();
			return r;

		case Division: 
			r = Generate(Node->Ptr1);
			Generate(Node->Ptr2);
			fprintf(fp,"DIV R%d R%d\n",r,r+1);
			freereg();
			return r;

		case Remainder: 
			r =  Generate(Node->Ptr1);
			Generate(Node->Ptr2);
			fprintf(fp,"MOD R%d R%d\n",r,r+1);
			freereg();
			return r;

		case And:
			return (Generate(Node->Ptr1))&&(Generate(Node->Ptr2));

		case Or:
			return (Generate(Node->Ptr1))||(Generate(Node->Ptr2));

		case Equal:
			r = Generate(Node->Ptr1);
			Generate(Node->Ptr2);
			fprintf(fp,"EQ R%d R%d\n",r,r+1);
			freereg();
			return r;

		case NotEqual:
			r =  Generate(Node->Ptr1);
			Generate(Node->Ptr2);
			fprintf(fp,"NE R%d R%d\n",r,r+1);
			freereg();
			return r;

		case GreaterThen:
			r = Generate(Node->Ptr1);
			Generate(Node->Ptr2);
			fprintf(fp,"GT R%d R%d\n",r,r+1);
			freereg();
			return r;

		case GreaterThenEqual:
			r =  Generate(Node->Ptr1);
			Generate(Node->Ptr2);
			fprintf(fp,"GE R%d R%d\n",r,r+1);
			freereg();
			return r;

		case LessThen:
			r =  Generate(Node->Ptr1);
			Generate(Node->Ptr2);
			fprintf(fp,"LT R%d R%d\n",r,r+1);
			freereg();
			return r;

		case LessThenEqual:
			r =  Generate(Node->Ptr1);
			Generate(Node->Ptr2);
			fprintf(fp,"LE R%d R%d\n",r,r+1);
			freereg();
			return r;

		case True:
			r = getreg();
			fprintf(fp,"MOV R%d 1\n",r);
			return r;

		case False:
			r = getreg();
			fprintf(fp,"MOV R%d 0\n",r);
			return r;

		case Digit:
			r = getreg();
			fprintf(fp,"MOV R%d %d\n",r,Node->VALUE);
			return r;

		case ArrayVariable:
			r = Generate(Node->Ptr1);
			TEMP = Glookup(Node->NAME);
			r1 = getreg();
			fprintf(fp,"MOV R%d %d\n",r1,TEMP->BINDING[0]);
			fprintf(fp,"ADD R%d R%d\n",r,r1);
			fprintf(fp,"MOV R%d [R%d]\n",r1,r);
			freereg();
			return r1;

		case Variable:
			LTEMP = LlookupSem(Node->NAME);
			r = getreg();
			if(LTEMP != NULL){
				r1 = getreg();
				fprintf(fp,"MOV R%d BP\n",r1);
				r2 = getreg();
				fprintf(fp,"MOV R%d %d\n",r2,LTEMP->BINDING[0]);
				fprintf(fp,"ADD R%d R%d\n",r1,r2);
				freereg();
				fprintf(fp,"MOV R%d [R%d]\n",r,r1);
				freereg();
			}
			else{
				TEMP = Glookup(Node->NAME);
				fprintf(fp,"MOV R%d [%d]\n",r,TEMP->BINDING[0]);
			}
			return r;

		case Read:
			r = getreg();
			fprintf(fp,"IN R%d\n",r);
			LTEMP = LlookupSem(Node->Ptr1->NAME);
			if(LTEMP != NULL){
				r1 = getreg();
				fprintf(fp,"MOV R%d BP\n",r1);
				r2 = getreg();
				fprintf(fp,"MOV R%d %d\n",r2,LTEMP->BINDING[0]);
				fprintf(fp,"ADD R%d R%d\n",r1,r2);
				freereg();
				fprintf(fp,"MOV [R%d] R%d\n",r1,r);
				freereg();
			}
			else{
				TEMP = Glookup(Node->Ptr1->NAME);
				if(TEMP->SIZE > 1){
					r1 = Generate(Node->Ptr1->Ptr1);
					r2 = getreg();
					fprintf(fp,"MOV R%d %d\n",r2,TEMP->BINDING[0]);
					fprintf(fp,"ADD R%d R%d\n",r1,r2);
					freereg();
					fprintf(fp,"MOV [R%d] R%d\n",r1,r);
					freereg();
				}
				else
					fprintf(fp,"MOV [%d] R%d\n",TEMP->BINDING[0],r);
			}
			freereg();
			return -1;

		case Conditional:
			r = Generate(Node->Ptr1);
			r1=getlabel();
			r2=getlabel();
			fprintf(fp,"JZ R%d LABEL%d\n",r,r1);
			freereg();
			Generate(Node->Ptr2);
			fprintf(fp,"JMP LABEL%d\n",r2);
			fprintf(fp,"LABEL%d:\n",r1);
			Generate(Node->Ptr3);
			fprintf(fp,"LABEL%d:\n",r2);
			return -1;

		case Iterative:
			r = getlabel();
			r2 = getlabel();
			fprintf(fp,"LABEL%d:\n",r);
			r1=Generate(Node->Ptr1);
			fprintf(fp,"JZ R%d LABEL%d\n",r1,r2);
			freereg();
			Generate(Node->Ptr2);
			fprintf(fp,"JMP LABEL%d\n",r);
			fprintf(fp,"LABEL%d:\n",r2);
			return -1;

		case Write:
			r = Generate(Node->Ptr1);
			fprintf(fp,"OUT R%d\n",r);
			freereg();
			return -1;


		case Initialize:
			LTEMP = LlookupSem(Node->Ptr1->NAME);
			r = Generate(Node->Ptr2);
			if(LTEMP != NULL){
				r1 = getreg();
				fprintf(fp,"MOV R%d BP\n",r1);
				r2 = getreg();
				fprintf(fp,"MOV R%d %d\n",r2,LTEMP->BINDING[0]);
				fprintf(fp,"ADD R%d R%d\n",r1,r2);
				freereg();
				fprintf(fp,"MOV [R%d] R%d\n",r1,r);
				freereg();
			}
			else{
				TEMP = Glookup(Node->Ptr1->NAME);
				if(TEMP->SIZE > 1){
					r1 = Generate(Node->Ptr1->Ptr1);
					r2 = getreg();
					fprintf(fp,"MOV R%d %d\n",r2,TEMP->BINDING[0]);
					fprintf(fp,"ADD R%d R%d\n",r1,r2);
					freereg();
					fprintf(fp,"MOV [R%d] R%d\n",r1,r);
					freereg();
				}
				else
					fprintf(fp,"MOV [%d] R%d\n",TEMP->BINDING[0],r);
			}
			freereg();
			return -1;

	}
}

