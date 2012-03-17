#include<malloc.h>
#include<stdio.h>
#include<string.h>
#include"macro.h"
#include"structure.h"
#include"createnode.h"
#include"typedef.h"
#include"global.h"
//#include"dynamic.h"
#include"semanticfunction.h"
#include"semantic.h"
//#include"local.h"
#include"convertfunction.h"
#include"converter.h"

void Compile(Tnode *Global,Tnode *Root,Tnode *MainNode){
	flag = 1;
	GlobalInstall(Global);
	SemanticAnalysis(Root);
	if(flag){
		Glocation();
		fp = fopen("SIM","w");
		Generate(Root);
		Generate(MainNode);
		fclose(fp);
	}
}
