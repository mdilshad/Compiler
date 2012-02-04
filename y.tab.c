
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "compiler.y"

    int yylex(void);
    int yyerror(char *);
    #include<stdio.h>
    #include"Action.h"
   int i,expval;
   Tnode *temp1,*temp2,*MainNode;
   extern FILE *yyin;
   extern int n;


/* Line 189 of yacc.c  */
#line 85 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 12 "compiler.y"

	int Num;
	char ch,*chp;
	struct tnode* Node;



/* Line 214 of yacc.c  */
#line 195 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 207 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   379

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNRULES -- Number of states.  */
#define YYNSTATES  257

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    36,     2,     2,
      42,    43,    37,    34,    44,    35,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    45,
       2,    33,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    13,    21,    29,    34,    42,    50,
      51,    55,    62,    69,    71,    75,    82,    89,    91,   107,
     123,   137,   144,   151,   153,   154,   158,   162,   166,   167,
     171,   172,   174,   179,   187,   192,   200,   201,   205,   212,
     214,   218,   225,   227,   230,   232,   233,   239,   248,   254,
     259,   267,   272,   280,   289,   297,   300,   301,   303,   307,
     311,   315,   319,   323,   327,   329,   334,   338,   342,   345,
     349,   353,   357,   361,   365,   369,   371,   373,   377,   381
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,     9,    50,    10,    53,    -1,    11,     4,
      51,    50,    -1,    11,     4,    40,     3,    41,    51,    50,
      -1,    11,     4,    42,    54,    43,    51,    50,    -1,    12,
       4,    52,    50,    -1,    12,     4,    40,     3,    41,    52,
      50,    -1,    12,     4,    42,    54,    43,    52,    50,    -1,
      -1,    44,     4,    51,    -1,    44,     4,    40,     3,    41,
      51,    -1,    44,     4,    42,    54,    43,    51,    -1,    45,
      -1,    44,     4,    52,    -1,    44,     4,    40,     3,    41,
      52,    -1,    44,     4,    42,    54,    43,    52,    -1,    45,
      -1,    11,     4,    42,    54,    43,    46,     9,    58,    10,
       7,    62,    67,     8,    47,    53,    -1,    12,     4,    42,
      54,    43,    46,     9,    58,    10,     7,    62,    67,     8,
      47,    53,    -1,    11,    32,    42,    43,    46,     9,    58,
      10,     7,    62,    67,     8,    47,    -1,    11,     4,    56,
      45,    54,    55,    -1,    12,     4,    57,    45,    54,    55,
      -1,    55,    -1,    -1,    11,     4,    56,    -1,    12,     4,
      57,    -1,    44,     4,    56,    -1,    -1,    44,     4,    57,
      -1,    -1,    59,    -1,    11,     4,    60,    59,    -1,    11,
       4,    40,     3,    41,    60,    59,    -1,    12,     4,    61,
      59,    -1,    12,     4,    40,     3,    41,    61,    59,    -1,
      -1,    44,     4,    60,    -1,    44,     4,    40,     3,    41,
      60,    -1,    45,    -1,    44,     4,    61,    -1,    44,     4,
      40,     3,    41,    61,    -1,    45,    -1,    62,    63,    -1,
      63,    -1,    -1,     5,    42,     4,    43,    45,    -1,     5,
      42,     4,    40,    65,    41,    43,    45,    -1,     6,    42,
      65,    43,    45,    -1,     4,    33,    65,    45,    -1,     4,
      40,    65,    41,    33,    65,    45,    -1,     4,    33,    66,
      45,    -1,     4,    40,    65,    41,    33,    66,    45,    -1,
      24,    42,    66,    43,    26,    62,    64,    27,    -1,    28,
      42,    66,    43,    29,    62,    30,    -1,    25,    62,    -1,
      -1,     3,    -1,    65,    34,    65,    -1,    65,    35,    65,
      -1,    65,    37,    65,    -1,    65,    38,    65,    -1,    65,
      36,    65,    -1,    42,    65,    43,    -1,     4,    -1,     4,
      40,    65,    41,    -1,    66,    13,    66,    -1,    66,    14,
      66,    -1,    15,    66,    -1,    65,    16,    65,    -1,    65,
      17,    65,    -1,    65,    18,    65,    -1,    65,    19,    65,
      -1,    65,    20,    65,    -1,    65,    21,    65,    -1,    23,
      -1,    22,    -1,    42,    66,    43,    -1,    31,    65,    45,
      -1,    31,    66,    45,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    31,    31,    36,    40,    44,    48,    52,    56,    60,
      65,    67,    69,    71,    76,    78,    80,    82,    88,    92,
      96,   102,   104,   106,   108,   111,   113,   117,   119,   122,
     124,   130,   133,   137,   141,   145,   149,   154,   156,   158,
     163,   165,   167,   173,   175,   177,   182,   184,   186,   188,
     190,   192,   194,   196,   198,   201,   203,   209,   211,   213,
     215,   217,   219,   221,   223,   225,   232,   234,   236,   238,
     240,   242,   244,   246,   248,   250,   252,   254,   260,   262
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIGIT", "VARIABLE", "READ", "WRITE",
  "BGIN", "END", "DECL", "ENDDECL", "INTEGER", "BOOLEAN", "AND", "OR",
  "NOT", "GT", "GE", "LT", "LE", "EQ", "NE", "FALS", "TRU", "IF", "ELSE",
  "THEN", "ENDIF", "WHILE", "DO", "ENDWHILE", "RETURN", "MAIN", "'='",
  "'+'", "'-'", "'%'", "'*'", "'/'", "NQ", "'['", "']'", "'('", "')'",
  "','", "';'", "'{'", "'}'", "$accept", "Program", "GDStatement",
  "GDStatementI", "GDStatementB", "Func", "Args", "ArgsEnd", "ArgsI",
  "ArgsB", "SDecl", "DStatement", "DStatementI", "DStatementB", "SList",
  "Statement", "ElseStmt", "E", "BE", "Rstat", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,    61,    43,    45,    37,    42,    47,   288,
      91,    93,    40,    41,    44,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    50,    50,    50,    50,    50,
      51,    51,    51,    51,    52,    52,    52,    52,    53,    53,
      53,    54,    54,    54,    54,    55,    55,    56,    56,    57,
      57,    58,    59,    59,    59,    59,    59,    60,    60,    60,
      61,    61,    61,    62,    62,    62,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    64,    64,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    67,    67
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     4,     7,     7,     4,     7,     7,     0,
       3,     6,     6,     1,     3,     6,     6,     1,    15,    15,
      13,     6,     6,     1,     0,     3,     3,     3,     0,     3,
       0,     1,     4,     7,     4,     7,     0,     3,     6,     1,
       3,     6,     1,     2,     1,     0,     5,     8,     5,     4,
       7,     4,     7,     8,     7,     2,     0,     1,     3,     3,
       3,     3,     3,     3,     1,     4,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     1,     1,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,     0,     0,     0,     0,     1,     0,     0,     0,
       0,    24,     0,    13,     9,     0,    24,     0,    17,     9,
       0,     0,     2,     0,     0,     0,     0,    23,     0,     3,
       0,     0,     0,     6,     0,     0,     0,     0,    28,    30,
       0,     0,    24,    10,     0,     0,     0,    24,    14,    24,
       0,    24,     9,     0,    25,     0,    26,     9,     0,     0,
       9,     9,     0,     0,     0,     0,     0,     4,    28,     0,
      30,     0,     5,     0,     0,     7,     8,     0,     0,     0,
       0,     0,    27,     0,    29,     0,    11,    12,    15,    16,
       0,    36,     0,     0,     0,    21,    22,    36,     0,     0,
       0,    31,    36,    28,    30,     0,     0,     0,     0,     0,
      25,    26,     0,     0,     0,    39,    36,     0,     0,    42,
      36,    45,     0,    45,     0,     0,    32,     0,     0,    34,
       0,     0,     0,     0,     0,     0,    44,    45,     0,     0,
       0,    37,     0,     0,    40,     0,     0,     0,     0,     0,
       0,     0,    43,     0,     0,     0,    36,     0,    36,     0,
      57,    64,     0,    76,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,     0,    35,     0,     0,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
       0,     0,    51,     0,     0,     0,     0,     0,     0,     0,
      78,    79,    20,     0,     0,    38,    41,     0,    63,    77,
      69,    70,    71,    72,    73,    74,    58,    59,    62,    60,
      61,    66,    67,     0,     0,    46,    48,    45,    45,     0,
      18,    65,     0,     0,     0,    56,     0,    19,    50,    52,
       0,    45,     0,    54,    47,    55,    53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    14,    19,    22,    26,    27,    54,    56,
     100,   101,   116,   120,   135,   136,   252,   172,   167,   153
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -144
static const yytype_int16 yypact[] =
{
      14,   155,    36,    55,    61,    99,  -144,   250,   256,   157,
      98,   176,   122,  -144,   155,   132,   176,   166,  -144,   155,
      24,   185,  -144,   118,   191,   230,   194,  -144,   262,  -144,
     197,   202,   268,  -144,   209,   210,   219,   158,   218,   220,
     158,   251,   176,  -144,   165,   165,   260,   176,  -144,   176,
     228,   176,   155,   249,   227,   275,   235,   155,   246,   245,
     155,   155,   252,   254,   266,   253,   280,  -144,   218,   176,
     220,   176,  -144,   158,   158,  -144,  -144,   165,   165,   257,
     282,   259,  -144,   195,  -144,   195,  -144,  -144,  -144,  -144,
     311,   207,   315,   321,   322,  -144,  -144,   207,   323,   324,
     319,  -144,   207,   218,   220,   320,    85,   271,   325,   326,
    -144,  -144,   327,   328,   329,  -144,   207,   332,   333,  -144,
     207,   211,   331,   211,   298,   274,  -144,   299,   277,  -144,
      59,   300,   301,   302,   303,   180,  -144,   211,   180,   184,
     338,  -144,   186,   343,  -144,    80,    54,   344,    54,    80,
      80,    80,  -144,   339,   180,   341,   207,   309,   207,   310,
    -144,   312,    80,  -144,  -144,    80,   120,    65,    54,   232,
      73,   212,   206,    84,    91,   126,    72,   306,   346,   308,
    -144,   184,  -144,   186,    54,  -144,   162,   110,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,  -144,
      80,    80,  -144,   222,   330,    54,   313,   314,   334,   335,
    -144,  -144,  -144,   318,   157,  -144,  -144,   240,  -144,  -144,
     114,   114,   114,   114,   114,   114,    95,    95,   183,  -144,
    -144,  -144,  -144,    80,   248,  -144,  -144,   211,   211,   157,
    -144,  -144,   156,    74,   336,   208,     7,  -144,  -144,  -144,
     316,   211,   340,  -144,  -144,   211,  -144
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,    20,   -13,    -2,  -132,    22,    35,   -59,   -64,
      -8,   -50,  -118,  -109,  -123,  -134,  -144,  -143,  -133,  -128
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     138,   152,   166,   169,   152,   171,    84,   141,   175,    82,
     155,   130,   131,   132,   154,    43,   173,   174,   176,   144,
     152,   156,   186,     1,    52,   203,   178,    57,    34,   185,
      48,   133,   187,   158,    29,   134,     6,   253,    31,    33,
     111,   217,    60,    61,   110,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,    35,   160,   161,     7,
      86,    87,   234,   215,    59,     8,   126,   231,   232,    63,
     129,    64,    67,    66,   216,    88,    89,    72,   200,   201,
      75,    76,   240,   160,   161,   200,   201,   200,   201,   105,
     242,    83,   145,    85,   109,   162,   168,   200,   201,   146,
     243,    23,   163,   164,   200,   201,   180,   247,   182,     9,
     202,   152,   152,   205,   245,   246,   206,   211,    95,   249,
      96,   152,   165,   200,   201,   113,    28,   208,   255,   114,
     115,   196,   197,   198,   209,    30,   188,   189,   190,   191,
     192,   193,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   219,   194,   195,   196,   197,   198,    37,
     194,   195,   196,   197,   198,   199,     3,     4,    20,    21,
      32,   210,   188,   189,   190,   191,   192,   193,   188,   189,
     190,   191,   192,   193,   130,   131,   132,    24,    25,    36,
     194,   195,   196,   197,   198,    38,   194,   195,   196,   197,
     198,   248,    12,    13,   133,   218,    93,    94,   134,    17,
      18,   151,   130,   131,   132,   130,   131,   132,    98,    99,
     197,   198,   188,   189,   190,   191,   192,   193,   114,   115,
     118,   119,   133,   251,    39,   133,   134,    40,    44,   134,
     194,   195,   196,   197,   198,    45,   194,   195,   196,   197,
     198,    49,    50,    68,    58,   207,   194,   195,   196,   197,
     198,    51,    53,    62,    55,   218,   194,   195,   196,   197,
     198,    65,    69,   204,   194,   195,   196,   197,   198,    70,
      71,   241,   194,   195,   196,   197,   198,    73,    74,   244,
      10,    91,    11,    77,    12,    13,    15,    78,    16,    80,
      17,    18,    41,    90,    42,    92,    12,    13,    46,    79,
      47,   117,    17,    18,   140,   118,   119,   143,   114,   115,
      97,   118,   119,    81,   102,   103,   104,   106,   107,   108,
     112,   124,   121,   125,   123,   127,   122,   128,   137,   139,
     142,   157,   147,   148,   149,   150,   159,   177,   170,   179,
     181,   183,   184,   212,   213,   214,     0,     0,   235,   236,
     237,   254,     0,   233,   238,   239,     0,   256,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   250
};

static const yytype_int16 yycheck[] =
{
     123,   135,   145,   146,   138,   148,    70,   125,   151,    68,
     138,     4,     5,     6,   137,    28,   149,   150,   151,   128,
     154,   139,   165,     9,    37,   168,   154,    40,     4,   162,
      32,    24,   165,   142,    14,    28,     0,    30,    16,    19,
     104,   184,    44,    45,   103,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,    32,     3,     4,     4,
      73,    74,   205,   181,    42,     4,   116,   200,   201,    47,
     120,    49,    52,    51,   183,    77,    78,    57,    13,    14,
      60,    61,   214,     3,     4,    13,    14,    13,    14,    97,
     233,    69,    33,    71,   102,    15,    42,    13,    14,    40,
     233,     3,    22,    23,    13,    14,   156,   239,   158,    10,
      45,   245,   246,    40,   237,   238,    43,    45,    83,    45,
      85,   255,    42,    13,    14,    40,     4,    43,   251,    44,
      45,    36,    37,    38,    43,     3,    16,    17,    18,    19,
      20,    21,    16,    17,    18,    19,    20,    21,    34,    35,
      36,    37,    38,    43,    34,    35,    36,    37,    38,    41,
      34,    35,    36,    37,    38,    45,    11,    12,    11,    12,
       4,    45,    16,    17,    18,    19,    20,    21,    16,    17,
      18,    19,    20,    21,     4,     5,     6,    11,    12,     4,
      34,    35,    36,    37,    38,     4,    34,    35,    36,    37,
      38,    45,    44,    45,    24,    43,    11,    12,    28,    44,
      45,    31,     4,     5,     6,     4,     5,     6,    11,    12,
      37,    38,    16,    17,    18,    19,    20,    21,    44,    45,
      44,    45,    24,    25,     4,    24,    28,    43,    41,    28,
      34,    35,    36,    37,    38,    43,    34,    35,    36,    37,
      38,    42,    42,     4,     3,    43,    34,    35,    36,    37,
      38,    42,    44,     3,    44,    43,    34,    35,    36,    37,
      38,    43,    45,    41,    34,    35,    36,    37,    38,     4,
      45,    41,    34,    35,    36,    37,    38,    41,    43,    41,
      40,     9,    42,    41,    44,    45,    40,    43,    42,    46,
      44,    45,    40,    46,    42,    46,    44,    45,    40,    43,
      42,    40,    44,    45,    40,    44,    45,    40,    44,    45,
       9,    44,    45,    43,     9,     4,     4,     4,     4,    10,
      10,     3,     7,     4,     7,     3,    10,     4,     7,    41,
      41,     3,    42,    42,    42,    42,     3,     8,     4,     8,
      41,    41,    40,    47,     8,    47,    -1,    -1,    45,    45,
      26,    45,    -1,    33,    29,    47,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    49,    11,    12,    50,     0,     4,     4,    10,
      40,    42,    44,    45,    51,    40,    42,    44,    45,    52,
      11,    12,    53,     3,    11,    12,    54,    55,     4,    50,
       3,    54,     4,    50,     4,    32,     4,    41,     4,     4,
      43,    40,    42,    51,    41,    43,    40,    42,    52,    42,
      42,    42,    51,    44,    56,    44,    57,    51,     3,    54,
      52,    52,     3,    54,    54,    43,    54,    50,     4,    45,
       4,    45,    50,    41,    43,    50,    50,    41,    43,    43,
      46,    43,    56,    54,    57,    54,    51,    51,    52,    52,
      46,     9,    46,    11,    12,    55,    55,     9,    11,    12,
      58,    59,     9,     4,     4,    58,     4,     4,    10,    58,
      56,    57,    10,    40,    44,    45,    60,    40,    44,    45,
      61,     7,    10,     7,     3,     4,    59,     3,     4,    59,
       4,     5,     6,    24,    28,    62,    63,     7,    62,    41,
      40,    60,    41,    40,    61,    33,    40,    42,    42,    42,
      42,    31,    63,    67,    62,    67,    60,     3,    61,     3,
       3,     4,    15,    22,    23,    42,    65,    66,    42,    65,
       4,    65,    65,    66,    66,    65,    66,     8,    67,     8,
      59,    41,    59,    41,    40,    66,    65,    66,    16,    17,
      18,    19,    20,    21,    34,    35,    36,    37,    38,    45,
      13,    14,    45,    65,    41,    40,    43,    43,    43,    43,
      45,    45,    47,     8,    47,    60,    61,    65,    43,    43,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    66,    66,    33,    65,    45,    45,    26,    29,    47,
      53,    41,    65,    66,    41,    62,    62,    53,    45,    45,
      43,    25,    64,    30,    45,    62,    27
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 31 "compiler.y"
    { }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 36 "compiler.y"
    {
								temp1 = TreeCreate(Integer,1,(yyvsp[(2) - (4)].chp),NULL,NULL,NULL,NULL,GDecl);
								(yyval.Node)=TreeCreate(Integer,0,'\0',NULL,temp1,(yyvsp[(3) - (4)].Node),(yyvsp[(4) - (4)].Node),Continue);}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 40 "compiler.y"
    {
										temp1 = TreeCreate(Integer,(yyvsp[(4) - (7)].Num),(yyvsp[(2) - (7)].chp),NULL,NULL,NULL,NULL,GArray);
										(yyval.Node)=TreeCreate(Integer,0,'\0',NULL,temp1,(yyvsp[(6) - (7)].Node),(yyvsp[(7) - (7)].Node),Continue);}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 44 "compiler.y"
    {
								temp1 = TreeCreate(Integer,0,(yyvsp[(2) - (7)].chp),(yyvsp[(4) - (7)].Node),NULL,NULL,NULL,FunctionDecl);
								(yyval.Node)=TreeCreate(Integer,0,'\0',NULL,temp1,(yyvsp[(6) - (7)].Node),(yyvsp[(7) - (7)].Node),Continue);}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 48 "compiler.y"
    {
								temp1 = TreeCreate(Boolean,1,(yyvsp[(2) - (4)].chp),NULL,NULL,NULL,NULL,GDecl);
								(yyval.Node)=TreeCreate(Boolean,0,'\0',NULL,temp1,(yyvsp[(3) - (4)].Node),(yyvsp[(4) - (4)].Node),Continue);}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 52 "compiler.y"
    {
										temp1 = TreeCreate(Boolean,(yyvsp[(4) - (7)].Num),(yyvsp[(2) - (7)].chp),NULL,NULL,NULL,NULL,Array);
										(yyval.Node)=TreeCreate(Boolean,0,'\0',NULL,temp1,(yyvsp[(6) - (7)].Node),(yyvsp[(7) - (7)].Node),Continue);}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 56 "compiler.y"
    {
								temp1 = TreeCreate(Boolean,0,(yyvsp[(2) - (7)].chp),(yyvsp[(4) - (7)].Node),NULL,NULL,NULL,FunctionDecl);
								(yyval.Node)=TreeCreate(Boolean,0,'\0',NULL,temp1,(yyvsp[(6) - (7)].Node),(yyvsp[(7) - (7)].Node),Continue);}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 60 "compiler.y"
    { (yyval.Node) = NULL; }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 65 "compiler.y"
    {	(yyval.Node)=TreeCreate(Integer,1,(yyvsp[(2) - (3)].chp),NULL,(yyvsp[(3) - (3)].Node),NULL,NULL,GDecl);}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 67 "compiler.y"
    { (yyval.Node)=TreeCreate(Integer,(yyvsp[(4) - (6)].Num),(yyvsp[(2) - (6)].chp),NULL,(yyvsp[(6) - (6)].Node),NULL,NULL,GArray);}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 69 "compiler.y"
    {	(yyval.Node)=TreeCreate(Integer,0,(yyvsp[(2) - (6)].chp),(yyvsp[(4) - (6)].Node),(yyvsp[(6) - (6)].Node),NULL,NULL,FunctionDecl);}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 71 "compiler.y"
    {(yyval.Node) = NULL; }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 76 "compiler.y"
    {	(yyval.Node)=TreeCreate(Boolean,1,(yyvsp[(2) - (3)].chp),NULL,(yyvsp[(3) - (3)].Node),NULL,NULL,GDecl);}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 78 "compiler.y"
    { (yyval.Node)=TreeCreate(Boolean,(yyvsp[(4) - (6)].Num),(yyvsp[(2) - (6)].chp),NULL,(yyvsp[(6) - (6)].Node),NULL,NULL,GArray);}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 80 "compiler.y"
    {	(yyval.Node)=TreeCreate(Boolean,0,(yyvsp[(2) - (6)].chp),(yyvsp[(4) - (6)].Node),(yyvsp[(6) - (6)].Node),NULL,NULL,FunctionDecl);}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 82 "compiler.y"
    {(yyval.Node) = NULL; }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 88 "compiler.y"
    {
																temp1 = TreeCreate(Integer,0,(yyvsp[(2) - (15)].chp),(yyvsp[(4) - (15)].Node),(yyvsp[(8) - (15)].Node),(yyvsp[(11) - (15)].Node),(yyvsp[(12) - (15)].Node),Function);
																(yyval.Node)=TreeCreate(Void,0,'\0',NULL,temp1,(yyvsp[(15) - (15)].Node),NULL,Continue);}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 92 "compiler.y"
    {
																temp1 = TreeCreate(Boolean,0,(yyvsp[(2) - (15)].chp),(yyvsp[(4) - (15)].Node),(yyvsp[(8) - (15)].Node),(yyvsp[(11) - (15)].Node),(yyvsp[(12) - (15)].Node),Function);
																(yyval.Node)=TreeCreate(Void,0,'\0',NULL,temp1,(yyvsp[(15) - (15)].Node),NULL,Continue);}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 96 "compiler.y"
    {
																(yyval.Node)=TreeCreate(Integer,0,"main",NULL,(yyvsp[(7) - (13)].Node),(yyvsp[(10) - (13)].Node),(yyvsp[(11) - (13)].Node),Main);
							    								MainNode=(yyval.Node);}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 102 "compiler.y"
    {(yyval.Node)=TreeCreate(Integer,0,(yyvsp[(2) - (6)].chp),NULL,(yyvsp[(3) - (6)].Node),(yyvsp[(5) - (6)].Node),(yyvsp[(6) - (6)].Node),Argument);}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 104 "compiler.y"
    {(yyval.Node)=TreeCreate(Boolean,0,(yyvsp[(2) - (6)].chp),NULL,(yyvsp[(3) - (6)].Node),(yyvsp[(5) - (6)].Node),(yyvsp[(6) - (6)].Node),Argument);}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 106 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 108 "compiler.y"
    {(yyval.Node) = NULL;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 111 "compiler.y"
    {(yyval.Node)=TreeCreate(Integer,0,(yyvsp[(2) - (3)].chp),NULL,(yyvsp[(3) - (3)].Node),NULL,NULL,Argument);}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 113 "compiler.y"
    {(yyval.Node)=TreeCreate(Boolean,0,(yyvsp[(2) - (3)].chp),NULL,(yyvsp[(3) - (3)].Node),NULL,NULL,Argument);}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 117 "compiler.y"
    {(yyval.Node)=TreeCreate(Integer,0,(yyvsp[(2) - (3)].chp),NULL,(yyvsp[(3) - (3)].Node),NULL,NULL,Argument);}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 119 "compiler.y"
    {  (yyval.Node) = NULL;	}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 122 "compiler.y"
    {(yyval.Node)=TreeCreate(Boolean,0,(yyvsp[(2) - (3)].chp),NULL,(yyvsp[(3) - (3)].Node),NULL,NULL,Argument);}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 124 "compiler.y"
    {  (yyval.Node) = NULL;	}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 130 "compiler.y"
    {(yyval.Node)=(yyvsp[(1) - (1)].Node);}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 133 "compiler.y"
    {
								temp1 = TreeCreate(Integer,1,(yyvsp[(2) - (4)].chp),NULL,NULL,NULL,NULL,Decl);
								(yyval.Node)=TreeCreate(Integer,0,'\0',NULL,temp1,(yyvsp[(3) - (4)].Node),(yyvsp[(4) - (4)].Node),Continue);}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 137 "compiler.y"
    {
										temp1 = TreeCreate(Integer,(yyvsp[(4) - (7)].Num),(yyvsp[(2) - (7)].chp),NULL,NULL,NULL,NULL,Array);
										(yyval.Node)=TreeCreate(Integer,0,'\0',NULL,temp1,(yyvsp[(6) - (7)].Node),(yyvsp[(7) - (7)].Node),Continue);}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 141 "compiler.y"
    {
								temp1 = TreeCreate(Boolean,1,(yyvsp[(2) - (4)].chp),NULL,NULL,NULL,NULL,Decl);
								(yyval.Node)=TreeCreate(Boolean,0,'\0',NULL,temp1,(yyvsp[(3) - (4)].Node),(yyvsp[(4) - (4)].Node),Continue);}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 145 "compiler.y"
    {
										temp1 = TreeCreate(Boolean,(yyvsp[(4) - (7)].Num),(yyvsp[(2) - (7)].chp),NULL,NULL,NULL,NULL,Array);
										(yyval.Node)=TreeCreate(Boolean,0,'\0',NULL,temp1,(yyvsp[(6) - (7)].Node),(yyvsp[(7) - (7)].Node),Continue);}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 149 "compiler.y"
    { (yyval.Node) = NULL; }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 154 "compiler.y"
    {	(yyval.Node)=TreeCreate(Integer,1,(yyvsp[(2) - (3)].chp),NULL,(yyvsp[(3) - (3)].Node),NULL,NULL,Decl);}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 156 "compiler.y"
    { (yyval.Node)=TreeCreate(Integer,(yyvsp[(4) - (6)].Num),(yyvsp[(2) - (6)].chp),NULL,(yyvsp[(6) - (6)].Node),NULL,NULL,Decl);}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 158 "compiler.y"
    {(yyval.Node) = NULL; }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 163 "compiler.y"
    {	(yyval.Node)=TreeCreate(Boolean,1,(yyvsp[(2) - (3)].chp),NULL,(yyvsp[(3) - (3)].Node),NULL,NULL,Decl);}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 165 "compiler.y"
    { (yyval.Node)=TreeCreate(Boolean,(yyvsp[(4) - (6)].Num),(yyvsp[(2) - (6)].chp),NULL,(yyvsp[(6) - (6)].Node),NULL,NULL,Decl);}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 167 "compiler.y"
    {(yyval.Node) = NULL; }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 173 "compiler.y"
    { (yyval.Node) = TreeCreate(Void,0,'\0',NULL,(yyvsp[(1) - (2)].Node),(yyvsp[(2) - (2)].Node),NULL,Continue); }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 175 "compiler.y"
    { (yyval.Node) = TreeCreate(Void,0,'\0',NULL,(yyvsp[(1) - (1)].Node),NULL,NULL,Continue); }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 177 "compiler.y"
    {(yyval.Node) = NULL;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 182 "compiler.y"
    { (yyval.Node) = TreeCreate(Integer,0,(yyvsp[(3) - (5)].chp),NULL,NULL,NULL,NULL,Read); }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 184 "compiler.y"
    { (yyval.Node) = TreeCreate(Integer,0,(yyvsp[(3) - (8)].chp),NULL,(yyvsp[(5) - (8)].Node),NULL,NULL,ArrayRead); }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 186 "compiler.y"
    { (yyval.Node) = TreeCreate(Integer,0,0,NULL,(yyvsp[(3) - (5)].Node),NULL,NULL,Write); }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 188 "compiler.y"
    { (yyval.Node) = TreeCreate(Integer,0,(yyvsp[(1) - (4)].chp),NULL,NULL,(yyvsp[(3) - (4)].Node),NULL,Initialize); }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 190 "compiler.y"
    { (yyval.Node) = TreeCreate(Integer,0,(yyvsp[(1) - (7)].chp),NULL,(yyvsp[(3) - (7)].Node),(yyvsp[(6) - (7)].Node),NULL,ArrayInitialize); }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 192 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,(yyvsp[(1) - (4)].chp),NULL,NULL,(yyvsp[(3) - (4)].Node),NULL,Initialize); }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 194 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,(yyvsp[(1) - (7)].chp),NULL,(yyvsp[(3) - (7)].Node),(yyvsp[(6) - (7)].Node),NULL,ArrayInitialize); }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 196 "compiler.y"
    {(yyval.Node) = TreeCreate(Void,0,0,NULL,(yyvsp[(3) - (8)].Node),(yyvsp[(6) - (8)].Node),(yyvsp[(7) - (8)].Node),Conditional);}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 198 "compiler.y"
    {(yyval.Node) = TreeCreate(Void,0,0,NULL,(yyvsp[(3) - (7)].Node),(yyvsp[(6) - (7)].Node),NULL,Iterative);}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 201 "compiler.y"
    {(yyval.Node) = (yyvsp[(2) - (2)].Node);}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 203 "compiler.y"
    {(yyval.Node) = NULL;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 209 "compiler.y"
    { (yyval.Node) = TreeCreate(Integer,(yyvsp[(1) - (1)].Num),'\0',NULL,NULL,NULL,NULL,Digit); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 211 "compiler.y"
    { (yyval.Node) = TreeCreate(Integer,0,'\0',NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,Addition); }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 213 "compiler.y"
    { (yyval.Node) = TreeCreate(Integer,0,'\0',NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,Subtraction); }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 215 "compiler.y"
    { (yyval.Node) = TreeCreate(Integer,0,'\0',NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,Multiplacation); }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 217 "compiler.y"
    { (yyval.Node) = TreeCreate(Integer,0,'\0',NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,Division); }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 219 "compiler.y"
    { (yyval.Node) = TreeCreate(Integer,0,'\0',NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,Remainder); }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 221 "compiler.y"
    { (yyval.Node) = (yyvsp[(2) - (3)].Node); }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 223 "compiler.y"
    { (yyval.Node) = TreeCreate(Integer,0,(yyvsp[(1) - (1)].chp),NULL,NULL,NULL,NULL,Variable); }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 225 "compiler.y"
    { (yyval.Node) = TreeCreate(Integer,0,(yyvsp[(1) - (4)].chp),NULL,(yyvsp[(3) - (4)].Node),NULL,NULL,ArrayVariable); }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 232 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,'\0',NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,And); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 234 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,'\0',NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,Or); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 236 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,'\0',NULL,(yyvsp[(2) - (2)].Node),NULL,NULL,Not); }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 238 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,'\0',NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,GreaterThen); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 240 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,'\0',NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,GreaterThenEqual); }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 242 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,'\0',NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,LessThen); }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 244 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,'\0',NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,LessThenEqual); }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 246 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,'\0',NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,Equal); }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 248 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,'\0',NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,NotEqual); }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 250 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,'\0',NULL,NULL,NULL,NULL,True); }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 252 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,'\0',NULL,NULL,NULL,NULL,False); }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 254 "compiler.y"
    { (yyval.Node) = (yyvsp[(2) - (3)].Node); }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 260 "compiler.y"
    {(yyval.Node) = TreeCreate(Integer,0,'\0',NULL,(yyvsp[(2) - (3)].Node),NULL,NULL,Return);}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 262 "compiler.y"
    {(yyval.Node) = TreeCreate(Boolean,0,'\0',NULL,(yyvsp[(2) - (3)].Node),NULL,NULL,Return);}
    break;



/* Line 1455 of yacc.c  */
#line 2187 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 267 "compiler.y"


int yyerror(char *s) 
{
	fprintf(stderr, "%s\n", s);
	return 1;
}

int main(int argc,char **argv) 
{
	yyin=fopen(argv[1],"r");
  	yyparse();
	fclose(yyin);
	return 1;
}

