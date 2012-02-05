int regcount=0,labelcount=0;
int getreg(){
	return regcount++;
}
void freereg(){
	regcount--;
}
int getlabel(){
	return labelcount++;
}

int calculate(Tnode* Temp)
{
	int r,loc,r1;
		switch(Temp->OpType)
		{
			case Addition:
				r =  calculate(Temp->Ptr1);
				calculate(Temp->Ptr2);
				fprintf(fp,"ADD R%d R%d\n",r,r+1);
				freereg();
				return r;
				
			case Subtraction: 
				r =  calculate(Temp->Ptr1);
				calculate(Temp->Ptr2);
				fprintf(fp,"SUB R%d R%d\n",r,r+1);
				freereg();
				return r;
				
			case Multiplacation: 
				r =  calculate(Temp->Ptr1);
				calculate(Temp->Ptr2);
				fprintf(fp,"MUL R%d R%d\n",r,r+1);
				freereg();
				return r;
				
			case Division: 
				r =  calculate(Temp->Ptr1);
				calculate(Temp->Ptr2);
				fprintf(fp,"DIV R%d R%d\n",r,r+1);
				freereg();
				return r;
				
			case Remainder: 
				r =  calculate(Temp->Ptr1);
				calculate(Temp->Ptr2);
				fprintf(fp,"MOD R%d R%d\n",r,r+1);
				freereg();
				return r;
				
			case And:
				return (calculate(Temp->Ptr1))&&(calculate(Temp->Ptr2));
				break;
				
			case Or:
				return (calculate(Temp->Ptr1))||(calculate(Temp->Ptr2));
				break;
				
			case Equal:
				r =  calculate(Temp->Ptr1);
				calculate(Temp->Ptr2);
				fprintf(fp,"EQ R%d R%d\n",r,r+1);
				freereg();
				return r;
				
			case NotEqual:
				r =  calculate(Temp->Ptr1);
				calculate(Temp->Ptr2);
				fprintf(fp,"NE R%d R%d\n",r,r+1);
				freereg();
				return r;
				
			case GreaterThen:
				r =  calculate(Temp->Ptr1);
				calculate(Temp->Ptr2);
				fprintf(fp,"GT R%d R%d\n",r,r+1);
				freereg();
				return r;
				
			case GreaterThenEqual:
				r =  calculate(Temp->Ptr1);
				calculate(Temp->Ptr2);
				fprintf(fp,"GE R%d R%d\n",r,r+1);
				freereg();
				return r;
				
			case LessThen:
				r =  calculate(Temp->Ptr1);
				calculate(Temp->Ptr2);
				fprintf(fp,"LT R%d R%d\n",r,r+1);
				freereg();
				return r;
				
			case LessThenEqual:
				r =  calculate(Temp->Ptr1);
				calculate(Temp->Ptr2);
				fprintf(fp,"LE R%d R%d\n",r,r+1);
				freereg();
				return r;
				
			case True:
				return 1;
				break;
				
			case False:
				return 0;
				break;
				
			case Digit:
				r = getreg();
    			fprintf(fp,"MOV R%d %d\n",r,Temp->VALUE);
				return r;
				
			case Variable:
				loc = Temp->NAME - 'a';
    			r = getreg();
    			fprintf(fp,"MOV R%d [%d]\n",r,loc);
    			return r;
		}
}
int Traverse(Tnode *Root)
{
	if(Root==NULL)
		return;
	int r,loc,r1;
	struct Gsymbol *Temp;	
	switch(Root->OpType)
	{
		case Continue:
			Traverse(Root->Ptr1);
			Traverse(Root->Ptr2);
			break;
    
    	case Read:
    		loc = Root->NAME-'a';
    		r = getreg();
    		fprintf(fp,"IN R%d\n",r);
    		fprintf(fp,"MOV [%d] R%d\n\n",loc,r);
    		freereg();
    		return -1;
    	
    	case Write:
    		r = calculate(Root->Ptr1);
    		fprintf(fp,"OUT R%d\n\n",r);
    		freereg();
    		return -1;
    		
    	case Conditional:
    			if(calculate(Root->Ptr1))
    				Traverse(Root->Ptr2);
    			else
    				Traverse(Root->Ptr3);
    			break;
    			
    	case Iterative:
    			r=getlabel();
    			fprintf(fp,"LABEL%d\n",r);
    			r1=calculate(Root->Ptr1);
    			fprintf(fp,"JZ R%d LABEL%d\n",r1,r+1);
    			Traverse(Root->Ptr2);
    			fprintf(fp,"JMP LABEL%d\n",r);
    			fprintf(fp,"LABEL%d\n",r+1);
    			return -1;
    	
    	case Initialize:
    		r = calculate(Root->Ptr2);
    		loc = Root->NAME - 'a';
    		fprintf(fp,"MOV [%d] R%d\n\n",loc,r);
    		freereg();
    		return -1;
    		     
	}    
}
