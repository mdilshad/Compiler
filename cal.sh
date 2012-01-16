lex calc.l
yacc -d calc.y
gcc lex.yy.c y.tab.c -ll

