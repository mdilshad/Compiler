
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DIGIT = 258,
     VARIABLE = 259,
     READ = 260,
     WRITE = 261,
     BGIN = 262,
     END = 263,
     DECL = 264,
     ENDDECL = 265,
     INTEGER = 266,
     BOOLEAN = 267,
     AND = 268,
     OR = 269,
     NOT = 270,
     GT = 271,
     GE = 272,
     LT = 273,
     LE = 274,
     EQ = 275,
     NE = 276,
     FALS = 277,
     TRU = 278,
     IF = 279,
     ELSE = 280,
     THEN = 281,
     ENDIF = 282,
     WHILE = 283,
     DO = 284,
     ENDWHILE = 285,
     RETURN = 286,
     MAIN = 287,
     NQ = 288
   };
#endif
/* Tokens.  */
#define DIGIT 258
#define VARIABLE 259
#define READ 260
#define WRITE 261
#define BGIN 262
#define END 263
#define DECL 264
#define ENDDECL 265
#define INTEGER 266
#define BOOLEAN 267
#define AND 268
#define OR 269
#define NOT 270
#define GT 271
#define GE 272
#define LT 273
#define LE 274
#define EQ 275
#define NE 276
#define FALS 277
#define TRU 278
#define IF 279
#define ELSE 280
#define THEN 281
#define ENDIF 282
#define WHILE 283
#define DO 284
#define ENDWHILE 285
#define RETURN 286
#define MAIN 287
#define NQ 288




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 11 "compiler.y"

	int Num;
	char ch,*chp;
	struct tnode* Node;



/* Line 1676 of yacc.c  */
#line 126 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


