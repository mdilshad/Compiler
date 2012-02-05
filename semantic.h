void LocalSemanticAnalysis(struct Lsymbol **LTable,Tnode* Node)
{
	if(Node == NULL)
		return;
	switch(Node->NODETYPE)
	{	
		case Continue:
			LocalSemanticAnalysis(LTable,Node->Ptr1);
			LocalSemanticAnalysis(LTable,Node->Ptr2);
			LocalSemanticAnalysis(LTable,Node->Ptr3);
			break;
		
		case Addition: 
					
		case Subtraction: 
		
		case Multiplacation: 
	
		case Division: 
		
		case Remainder: 
					
		case And:
						
		case Or:
					
		case Equal:
						
		case NotEqual:
						
		case GreaterThen:
					
		case GreaterThenEqual:
						
		case LessThen:
						
		case LessThenEqual:
						
		case True:
						
		case False:
			
		case Digit:
					
		case Variable:
		    					
   	case ArrayVariable:
		
   	case Read:
    	  		
   	case ArrayRead:
    	   		
   	case Conditional:
    	    			
   	case Iterative:
    	    	
   	case Write:
    	   	
   	case Initialize:
    	    		
   	case ArrayInitialize:break;
    	
   	case Decl:
   	case Array:
   		if(Llookup(*LTable,Node->NAME))
   			printf("Variable %s already Exist ",Node->NAME);
   		else
   			Linstall(LTable,Node->NAME,Node->TYPE);
   		break;    	    
	}    
}
void GlobalSemanticAnalysis(Tnode* Node)
{
	if(Node == NULL)
		return;
	struct ArgStruct *ArgList;
	switch(Node->NODETYPE)
	{
		case Continue:
			GlobalSemanticAnalysis(Node->Ptr1);
			GlobalSemanticAnalysis(Node->Ptr2);
			GlobalSemanticAnalysis(Node->Ptr3);
			break;
				
		case Decl:
    	case Array:
    		if(Glookup(Node->NAME))
    			printf("Variable %s already Exist ",Node->NAME);
    		else
    		Ginstall(Node->NAME,Node->TYPE,Node->VALUE,NULL);
    		GlobalSemanticAnalysis(Node->Ptr1);
    		break;
    	
    	case FunctionDecl:
    		if(Glookup(Node->NAME))
    			printf("Function %s already Exist ",Node->NAME);
    		else
    		{
    			ArgList = Arginstall(Node->ArgList);
    			Ginstall(Node->NAME,Node->TYPE,Node->VALUE,ArgList);
    		}
    		GlobalSemanticAnalysis(Node->Ptr1);
    		break;
	}
}
