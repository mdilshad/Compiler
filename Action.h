#include<malloc.h>
#include<stdio.h>
#include<string.h>
#include"macro.h"
#include"structure.h"
#include"createnode.h"
#include"semantic.h"
#include"interpreter.h"
void SemanticAnalysis(Tnode *Node)
{
	if(Node == NULL)
		return;
	struct Lsymbol *LTable = NULL;
	switch(Node->NODETYPE)
	{
	
		case Continue:
			SemanticAnalysis(Node->Ptr1);
			SemanticAnalysis(Node->Ptr2);
			break;
		
		case FunctionDecl:
			T = Glookup(Node->NAME);
			T->FNode = Node; 
			LocalSemanticAnalysis(&LTable,Node);
			break; 
	}
}

void Compile(Tnode *Global,Tnode *Node)
{
	flag = 1;
	struct Lsymbol *LTable = NULL;
	GlobalSemanticAnalysis(Global);
	SemanticAnalysis(Node);
	if(flag == 1);
		Traverse(&LTable,MainNode);
}
