
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
     Identifier = 259,
     READ = 260,
     WRITE = 261,
     NEW = 262,
     FREE = 263,
     TYPEDEF = 264,
     BGIN = 265,
     END = 266,
     DECL = 267,
     ENDDECL = 268,
     INTEGER = 269,
     BOOLEAN = 270,
     AND = 271,
     OR = 272,
     NOT = 273,
     GT = 274,
     GE = 275,
     LT = 276,
     LE = 277,
     EQ = 278,
     NE = 279,
     FALS = 280,
     TRU = 281,
     IF = 282,
     ELSE = 283,
     THEN = 284,
     ENDIF = 285,
     WHILE = 286,
     DO = 287,
     ENDWHILE = 288,
     RETURN = 289,
     MAIN = 290,
     NQ = 291
   };
#endif
/* Tokens.  */
#define DIGIT 258
#define Identifier 259
#define READ 260
#define WRITE 261
#define NEW 262
#define FREE 263
#define TYPEDEF 264
#define BGIN 265
#define END 266
#define DECL 267
#define ENDDECL 268
#define INTEGER 269
#define BOOLEAN 270
#define AND 271
#define OR 272
#define NOT 273
#define GT 274
#define GE 275
#define LT 276
#define LE 277
#define EQ 278
#define NE 279
#define FALS 280
#define TRU 281
#define IF 282
#define ELSE 283
#define THEN 284
#define ENDIF 285
#define WHILE 286
#define DO 287
#define ENDWHILE 288
#define RETURN 289
#define MAIN 290
#define NQ 291




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 9 "compiler.y"

	int Num;
	char* chp;
	struct tnode* Node;
	struct field* FNode;
	struct typeDef* TNode;
	struct ArgStruct* ArgNode;



/* Line 1676 of yacc.c  */
#line 135 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


