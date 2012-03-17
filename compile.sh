lex compiler.l
yacc -d compiler.y
gcc lex.yy.c y.tab.c -ll -o compiler

