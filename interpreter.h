struct Gsymbol *T;
int calculate(Tnode* Temp)
{
		switch(Temp->NODETYPE)
		{
			case Addition: 
				return (calculate(Temp->Ptr1))+(calculate(Temp->Ptr2));
				
			case Subtraction: 
				return (calculate(Temp->Ptr1))-(calculate(Temp->Ptr2));
				
			case Multiplacation: 
				return (calculate(Temp->Ptr1))*(calculate(Temp->Ptr2));
				
			case Division: 
				return (calculate(Temp->Ptr1))/(calculate(Temp->Ptr2));
				
			case Remainder: 
				return (calculate(Temp->Ptr1))%(calculate(Temp->Ptr2));
				
			case And:
				return (calculate(Temp->Ptr1))&&(calculate(Temp->Ptr2));
				
			case Or:
				return (calculate(Temp->Ptr1))||(calculate(Temp->Ptr2));
				
			case Equal:
				return (calculate(Temp->Ptr1))==(calculate(Temp->Ptr2));
				
			case NotEqual:
				return (calculate(Temp->Ptr1))!=(calculate(Temp->Ptr2));	
				
			case GreaterThen:
				return (calculate(Temp->Ptr1))>(calculate(Temp->Ptr2));
			
			case GreaterThenEqual:
				return (calculate(Temp->Ptr1))>=(calculate(Temp->Ptr2));
				
			case LessThen:
				return (calculate(Temp->Ptr1))<(calculate(Temp->Ptr2));
				
			case LessThenEqual:
				return (calculate(Temp->Ptr1))<=(calculate(Temp->Ptr2));
				
			case True:
				return 1;
				
			case False:
				return 0;
				
			case Digit:
					return Temp->VALUE;
			
			case Variable:
					T = Glookup(Temp->NAME);
    				if(T == NULL)
    					printf("Variable %s Not Exist ",Temp->NAME);
    				else
    					return T->BINDING[Temp->VALUE];
    					
    		case ArrayVariable:
					T = Glookup(Temp->NAME);
    				if(T == NULL)
    					printf("Variable %s Not Exist ",Temp->NAME);
    				else
    					return T->BINDING[calculate(Temp->Ptr1)];
		}
}
int Traverse(Tnode *Root)
{
	if(Root==NULL)
		return;
	struct Gsymbol *Temp;	
	switch(Root->NODETYPE)
	{
		case Continue:
			Traverse(Root->Ptr1);
			Traverse(Root->Ptr2);
			Traverse(Root->Ptr3);
			break;
    
    	case Read:
    		Temp = Glookup(Root->NAME);
    		if(Temp == NULL)
    				printf("Variable %s Not Exist ",Root->NAME);
    		else
    				scanf("%d",&Temp->BINDING[0]);
    		break;
    		
    	case ArrayRead:
    		Temp = Glookup(Root->NAME);
    		if(Temp == NULL)
    				printf("Variable %s Not Exist ",Root->NAME);
    		else
    				scanf("%d",&Temp->BINDING[calculate(Root->Ptr1)]);
    		break;
    		
    	case Conditional:
    			if(calculate(Root->Ptr1))
    				Traverse(Root->Ptr2);
    			else
    				Traverse(Root->Ptr3);
    			break;
    			
    	case Iterative:
    			while(calculate(Root->Ptr1))
    				Traverse(Root->Ptr2);
    			break;
    	
    	case Write:
    		printf("%d\n",calculate(Root->Ptr1));
   			break;
    	
    	case Initialize:
    		Temp = Glookup(Root->NAME);
    		if(Temp == NULL)
    				printf("Variable %s Not Exist ",Root->NAME);
    		else
    				Temp->BINDING[0] = calculate(Root->Ptr2);
    		break;
    		
    	case ArrayInitialize:
    		Temp = Glookup(Root->NAME);
    		if(Temp == NULL)
    				printf("Variable %s Not Exist ",Root->NAME);
    		else
    				Temp->BINDING[calculate(Root->Ptr1)] = calculate(Root->Ptr2);
    		break;
    		  	    
	}    
}
