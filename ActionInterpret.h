#include<malloc.h>
#include<stdio.h>
#include<string.h>
#include"macro.h"
#include"structure.h"
#include"createnode.h"
#include"typedef.h"
#include"global.h"
#include"dynamic.h"
#include"semanticfunction.h"
#include"semantic.h"
#include"local.h"
#include"interpreter.h"

void Compile(Tnode *Global,Tnode *Root,Tnode *MainNode){
	flag = 1;
	LTABLE *LTable = NULL;
	GlobalInstall(Global);
	SemanticAnalysis(Root);
	SemanticAnalysis(MainNode);
	if(flag){
		Gallocate();
		ALLOCATE(&LTable);
		//Traverse(LTable,MainNode);
		DEALLOCATE(LTable);
	}
}
