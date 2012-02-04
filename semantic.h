void LocalSemanticAnalysis(Tnode* Node)
{
	switch(Node->NODETYPE)
	{
	
		case Continue:
			LocalSemanticAnalysis(Node->Ptr1);
			LocalSemanticAnalysis(Node->Ptr2);
			LocalSemanticAnalysis(Node->Ptr3);
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
   		if(Glookup(Node->NAME))
   			printf("Variable %s already Exist ",Node->NAME);
   		else
   			Node->Lentry = Linstall(Node->NAME,Node->TYPE,Node->VALUE);
   		break;    	    
	}    
}
void GlobalSemanticAnalysis(Tnode* Node)
{
	struct ArgStruct *ArgList;
	switch(Node->NODETYPE)
	{
		case Continue:
			GlobalSemanticAnalysis(Node->Ptr1);
			GlobalSemanticAnalysis(Node->Ptr2);
			GlobalSemanticAnalysis(Node->Ptr3);
			break;
				
		case GDecl:
    	case GArray:
    		if(Glookup(Node->NAME))
    			printf("Variable %s already Exist ",Node->NAME);
    		else
    			Node->Gentry = Ginstall(Node->NAME,Node->TYPE,Node->VALUE,NULL);
    		GlobalSemanticAnalysis(Node->Ptr1);
    		break;
    	
    	case FunctionDecl:
    		if(Glookup(Node->NAME))
    			printf("Function %s already Exist ",Node->NAME);
    		else
    		{
    			ArgList = Arginstall(Node->ArgList);
    			Node->Gentry = Ginstall(Node->NAME,Node->TYPE,Node->VALUE,ArgList);
    		}
    		GlobalSemanticAnalysis(Node->Ptr1);
    		break;
	}
}
