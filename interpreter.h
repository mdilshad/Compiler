int Evaluate(struct Lsymbol *LTable,Tnode* Node){
	if(Node == NULL)
		return;
	struct Lsymbol *Lentry = NULL;
	switch(Node->NODETYPE){
			
			case Function:
				T = Glookup(Node->NAME);
				installArgs(&Lentry,LTable,T->ARGLIST,Node->ArgList);
				Traverse(&Lentry,T->FNode->Ptr1); 
				Traverse(&Lentry,T->FNode->Ptr2);
				return Traverse(&Lentry,T->FNode->Ptr3);

			case Addition: 
				return (Evaluate(LTable,Node->Ptr1))+(Evaluate(LTable,Node->Ptr2));
				
			case Subtraction: 
				return (Evaluate(LTable,Node->Ptr1))-(Evaluate(LTable,Node->Ptr2));
				
			case Multiplacation: 
				return (Evaluate(LTable,Node->Ptr1))*(Evaluate(LTable,Node->Ptr2));
				
			case Division: 
				return (Evaluate(LTable,Node->Ptr1))/(Evaluate(LTable,Node->Ptr2));
				
			case Remainder: 
				return (Evaluate(LTable,Node->Ptr1))%(Evaluate(LTable,Node->Ptr2));
				
			case And:
				return (Evaluate(LTable,Node->Ptr1))&&(Evaluate(LTable,Node->Ptr2));
				
			case Or:
				return (Evaluate(LTable,Node->Ptr1))||(Evaluate(LTable,Node->Ptr2));
				
			case Equal:
				return (Evaluate(LTable,Node->Ptr1))==(Evaluate(LTable,Node->Ptr2));
				
			case NotEqual:
				return (Evaluate(LTable,Node->Ptr1))!=(Evaluate(LTable,Node->Ptr2));	
				
			case GreaterThen:
				return (Evaluate(LTable,Node->Ptr1))>(Evaluate(LTable,Node->Ptr2));
			
			case GreaterThenEqual:
				return (Evaluate(LTable,Node->Ptr1))>=(Evaluate(LTable,Node->Ptr2));
				
			case LessThen:
				return (Evaluate(LTable,Node->Ptr1))<(Evaluate(LTable,Node->Ptr2));
				
			case LessThenEqual:
				return (Evaluate(LTable,Node->Ptr1))<=(Evaluate(LTable,Node->Ptr2));
				
			case True:
				return 1;
				
			case False:
				return 0;
				
			case Digit:
					return Node->VALUE;
			
			case Variable:
					L = Llookup(LTable,Node->NAME);
	 				if(L != NULL)
	 					return L->BINDING[Node->VALUE];
	 				else {
    					T = Glookup(Node->NAME);
    					return T->BINDING[Node->VALUE];
    				}
    					
    		case ArrayVariable:
    				L = Llookup(LTable,Node->NAME);
	 				if(L != NULL)
	 					return L->BINDING[Evaluate(LTable,Node->Ptr1)];
	 				else{
    					T = Glookup(Node->NAME);
    					return T->BINDING[Evaluate(LTable,Node->Ptr1)];
    				}
		}
}
int Traverse(struct Lsymbol **LTable,Tnode *Root){
	if(Root==NULL)
		return;	
	struct Lsymbol *Lentry;
	switch(Root->NODETYPE) {
		
		case Continue:
		case Main:
			Traverse(LTable,Root->Ptr1);
			Traverse(LTable,Root->Ptr2);
			Traverse(LTable,Root->Ptr3);
			break;
	
		case Decl:
		case Array:
			LinstallDynamic(LTable,Root->NAME,Root->TYPE,Root->VALUE);
    		Traverse(LTable,Root->Ptr1);
			break;
			
		case Return:
			return Evaluate(*LTable,Root->Ptr1);
				 	
	 	case Read:
	 		L = Llookup(*LTable,Root->NAME);
	 		if(L != NULL)
	 			scanf("%d",&L->BINDING[0]);
	 		else {
    			T = Glookup(Root->NAME);
    			scanf("%d",&T->BINDING[0]);
    		}
    		break;
    		
    	case ArrayRead:
    		L = Llookup(*LTable,Root->NAME);
	 		if(L != NULL)
	 			scanf("%d",&L->BINDING[Evaluate(*LTable,Root->Ptr1)]);
	 		else {
    			T = Glookup(Root->NAME);
    			scanf("%d",&T->BINDING[Evaluate(*LTable,Root->Ptr1)]);
    		}
    		break;
    		
    	case Conditional:
    		if(Evaluate(*LTable,Root->Ptr1))
    			Traverse(LTable,Root->Ptr2);
    		else
    			Traverse(LTable,Root->Ptr3);
    		break;
    			
    	case Iterative:
    		while(Evaluate(*LTable,Root->Ptr1))
    			Traverse(LTable,Root->Ptr2);
    		break;
    	
    	case Write:
    		printf("%d\n",Evaluate(*LTable,Root->Ptr1));
   		break;
    	
    	case Expression:
    		Evaluate(*LTable,Root->Ptr2);
    		break;
    	
    	case Initialize:
    		L = Llookup(*LTable,Root->NAME);
	 		if(L != NULL)
	 			L->BINDING[0] = Evaluate(*LTable,Root->Ptr2);
	 		else {
    			T = Glookup(Root->NAME);
    			T->BINDING[0] = Evaluate(*LTable,Root->Ptr2);
    		}
    		break;
    		
    	case ArrayInitialize:
    		L = Llookup(*LTable,Root->NAME);
	 		if(L != NULL)
	 			L->BINDING[Evaluate(*LTable,Root->Ptr1)] = Evaluate(*LTable,Root->Ptr2);
	 		else {
    			T = Glookup(Root->NAME);
    			T->BINDING[Evaluate(*LTable,Root->Ptr1)] = Evaluate(*LTable,Root->Ptr2);
    		}
    		break;
    		  	    
	}    
}
