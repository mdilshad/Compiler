
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
	#include"ActionConvert.h"
	//#include"ActionInterpret.h"
	extern FILE *yyin;


/* Line 189 of yacc.c  */
#line 82 "y.tab.c"

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

/* Line 214 of yacc.c  */
#line 9 "compiler.y"

	int Num;
	char* chp;
	struct tnode* Node;
	struct field* FNode;
	struct typeDef* TNode;
	struct ArgStruct* ArgNode;



/* Line 214 of yacc.c  */
#line 201 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 213 "y.tab.c"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   369

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  227

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    39,    49,     2,
      47,    48,    40,    37,    45,    38,    53,    41,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    46,
       2,    36,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,    50,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    12,    19,    20,    24,    28,    32,
      36,    39,    41,    42,    45,    46,    61,    76,    90,    92,
      93,    98,   104,   109,   115,   118,   119,   123,   128,   129,
     133,   138,   139,   142,   143,   147,   149,   151,   153,   157,
     159,   161,   164,   169,   174,   177,   180,   181,   187,   193,
     198,   204,   214,   223,   229,   232,   233,   235,   239,   243,
     247,   251,   255,   259,   263,   267,   271,   275,   279,   283,
     287,   290,   292,   294,   299,   301,   305,   308,   314,   318,
     319,   321,   322,   326,   331,   333,   336
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    57,    56,    61,    63,    -1,    12,    69,
      13,    -1,    57,     9,     4,    43,    58,    44,    -1,    -1,
      14,     4,    59,    -1,     4,     4,    59,    -1,    15,     4,
      59,    -1,    45,     4,    59,    -1,    46,    60,    -1,    58,
      -1,    -1,    61,    62,    -1,    -1,    14,     4,    47,    64,
      48,    43,    12,    69,    13,    10,    74,    83,    11,    44,
      -1,    15,     4,    47,    64,    48,    43,    12,    69,    13,
      10,    74,    83,    11,    44,    -1,    14,    35,    47,    48,
      43,    12,    69,    13,    10,    74,    83,    11,    44,    -1,
      65,    -1,    -1,    14,     4,    67,    66,    -1,    14,    49,
       4,    67,    66,    -1,    15,     4,    68,    66,    -1,    15,
      49,     4,    68,    66,    -1,    46,    65,    -1,    -1,    45,
       4,    67,    -1,    45,    49,     4,    67,    -1,    -1,    45,
       4,    68,    -1,    45,    49,     4,    68,    -1,    -1,    69,
      70,    -1,    -1,    71,    72,    46,    -1,    14,    -1,    15,
      -1,     4,    -1,    72,    45,    73,    -1,    73,    -1,     4,
      -1,    50,     4,    -1,     4,    51,     3,    52,    -1,     4,
      47,    64,    48,    -1,    61,    75,    -1,    75,    76,    -1,
      -1,     5,    47,    79,    48,    46,    -1,     6,    47,    78,
      48,    46,    -1,    79,    36,    78,    46,    -1,     4,    47,
      81,    48,    46,    -1,    27,    47,    78,    48,    29,    75,
      77,    30,    46,    -1,    31,    47,    78,    48,    32,    75,
      33,    46,    -1,     8,    47,     4,    48,    46,    -1,    28,
      75,    -1,    -1,     3,    -1,    78,    37,    78,    -1,    78,
      38,    78,    -1,    78,    40,    78,    -1,    78,    41,    78,
      -1,    78,    39,    78,    -1,    78,    19,    78,    -1,    78,
      20,    78,    -1,    78,    21,    78,    -1,    78,    22,    78,
      -1,    78,    23,    78,    -1,    78,    24,    78,    -1,    78,
      16,    78,    -1,    78,    17,    78,    -1,    18,    78,    -1,
      26,    -1,    25,    -1,     4,    47,    81,    48,    -1,    79,
      -1,    47,    78,    48,    -1,     4,    80,    -1,     4,    51,
      78,    52,    80,    -1,    53,     4,    80,    -1,    -1,    82,
      -1,    -1,    78,    45,    82,    -1,    49,     4,    45,    82,
      -1,    78,    -1,    49,     4,    -1,    34,    78,    46,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    41,    41,    43,    47,    49,    54,    56,    58,    63,
      65,    68,    70,    75,    77,    79,    82,    85,    90,    92,
      95,    97,    99,   101,   105,   107,   110,   112,   114,   117,
     119,   121,   126,   128,   131,   135,   137,   139,   143,   145,
     150,   152,   154,   156,   160,   162,   164,   169,   171,   173,
     175,   177,   179,   181,   186,   188,   193,   195,   197,   199,
     201,   203,   205,   207,   209,   211,   213,   215,   217,   219,
     221,   223,   225,   227,   229,   231,   236,   238,   241,   243,
     248,   250,   252,   254,   256,   258,   263
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DIGIT", "Identifier", "READ", "WRITE",
  "NEW", "FREE", "TYPEDEF", "BGIN", "END", "DECL", "ENDDECL", "INTEGER",
  "BOOLEAN", "AND", "OR", "NOT", "GT", "GE", "LT", "LE", "EQ", "NE",
  "FALS", "TRU", "IF", "ELSE", "THEN", "ENDIF", "WHILE", "DO", "ENDWHILE",
  "RETURN", "MAIN", "'='", "'+'", "'-'", "'%'", "'*'", "'/'", "NQ", "'{'",
  "'}'", "','", "';'", "'('", "')'", "'&'", "'^'", "'['", "']'", "'.'",
  "$accept", "Program", "GDefblock", "STypedef", "FIELD", "FStateMore",
  "FStatement", "Fdeflist", "FDef", "Mainblock", "ArgList", "Args",
  "ArgEnd", "ArgsInt", "ArgsBool", "DefList", "DStatement", "TYPE",
  "VARList", "VARNAME", "FBody", "SList", "Statement", "ElseStmt", "E",
  "VARIABLE", "TVAR", "ParaList", "Parameter", "Rstat", 0
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
     285,   286,   287,   288,   289,   290,    61,    43,    45,    37,
      42,    47,   291,   123,   125,    44,    59,    40,    41,    38,
      94,    91,    93,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    57,    57,    58,    58,    58,    59,
      59,    60,    60,    61,    61,    62,    62,    63,    64,    64,
      65,    65,    65,    65,    66,    66,    67,    67,    67,    68,
      68,    68,    69,    69,    70,    71,    71,    71,    72,    72,
      73,    73,    73,    73,    74,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    77,    77,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    79,    79,    80,    80,
      81,    81,    82,    82,    82,    82,    83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     6,     0,     3,     3,     3,     3,
       2,     1,     0,     2,     0,    14,    14,    13,     1,     0,
       4,     5,     4,     5,     2,     0,     3,     4,     0,     3,
       4,     0,     2,     0,     3,     1,     1,     1,     3,     1,
       1,     2,     4,     4,     2,     2,     0,     5,     5,     4,
       5,     9,     8,     5,     2,     0,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     4,     1,     3,     2,     5,     3,     0,
       1,     0,     3,     4,     1,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     1,     0,    33,    14,     0,     0,     0,
       0,    37,     3,    35,    36,    32,     0,     0,     0,    13,
       2,     0,     0,     0,     0,    40,     0,     0,    39,     0,
       0,     0,     0,     0,     0,     4,    19,     0,    41,     0,
      34,    19,     0,    19,     0,    12,     7,     6,     8,     0,
       0,     0,    18,     0,    38,     0,     0,     0,     0,    11,
      10,    28,     0,    31,     0,    43,    42,     0,     0,     0,
       9,     0,    25,    28,     0,    25,    31,     0,    33,     0,
      28,     0,     0,    20,    25,    31,     0,    22,    25,    33,
       0,    33,    26,    28,    24,    21,    29,    31,    23,     0,
       0,     0,    27,    30,     0,    14,     0,    14,    46,     0,
      14,     0,     0,    44,     0,     0,     0,     0,    79,     0,
       0,     0,     0,     0,    45,     0,    56,    79,     0,    72,
      71,     0,     0,    74,     0,     0,     0,    81,     0,     0,
      76,     0,     0,     0,     0,     0,     0,    81,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    17,     0,    15,     0,    84,     0,
      80,     0,    79,    79,     0,     0,     0,     0,     0,     0,
       0,    75,    68,    69,    62,    63,    64,    65,    66,    67,
      57,    58,    61,    59,    60,    16,    85,     0,     0,    79,
      78,     0,     0,     0,     0,     0,    49,    73,     0,    82,
      50,    77,    47,    48,    53,    46,    46,    83,    55,     0,
      46,     0,     0,    54,     0,    52,    51
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     6,     2,    24,    46,    60,   108,    19,    20,
      51,    52,    83,    72,    75,     8,    15,    16,    27,    28,
     109,   113,   124,   221,   168,   133,   140,   169,   170,   115
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -192
static const yytype_int16 yypact[] =
{
    -192,    13,   110,  -192,    -3,  -192,  -192,   -21,   175,    73,
      66,  -192,  -192,  -192,  -192,  -192,     1,     0,    55,  -192,
    -192,    90,   100,   114,    95,    56,   143,   131,  -192,   102,
     144,   154,   135,   135,   135,  -192,   123,   158,  -192,     1,
    -192,   123,   130,   123,   200,    66,  -192,  -192,  -192,     3,
       4,   170,  -192,   167,  -192,   172,   178,   180,   135,  -192,
    -192,   184,   238,   204,   246,  -192,  -192,   217,   249,   221,
    -192,     5,   219,   184,     6,   219,   204,   256,  -192,   268,
     184,   285,   123,  -192,   219,   204,   291,  -192,   219,  -192,
     243,  -192,  -192,   184,  -192,  -192,  -192,   204,  -192,   283,
     278,   302,  -192,  -192,   289,  -192,   290,  -192,   197,   279,
    -192,   279,   310,   240,    53,   307,   279,   319,   -26,   274,
     286,   287,   292,   293,  -192,   296,  -192,   284,    53,  -192,
    -192,    53,   176,  -192,   294,   325,   297,    11,    53,   338,
    -192,   339,    53,   340,    53,    53,    53,    11,   321,    92,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,  -192,  -192,   304,  -192,   342,   214,   299,
    -192,    45,   298,    24,   301,   104,   305,   134,   146,   186,
     306,  -192,   321,   321,   321,   321,   321,   321,   321,   253,
     262,   262,   288,   303,   303,  -192,   311,    11,   309,   298,
    -192,   312,   313,   314,   323,   318,  -192,  -192,    11,  -192,
    -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,   235,    68,
    -192,   327,   315,   240,   316,  -192,  -192
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -192,  -192,  -192,  -192,   320,    59,  -192,   357,  -192,  -192,
      93,   282,    14,   -62,   -73,    57,  -192,  -192,  -192,   328,
     -87,   -56,  -192,  -192,  -112,  -113,  -109,   222,  -191,   -20
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
     125,     7,   132,    88,    29,    25,   209,    61,    63,    80,
      85,    84,    96,     3,   126,   127,   148,   217,    92,   149,
     111,   137,    10,   116,   103,   138,   171,   139,   174,   128,
     175,   102,   177,   178,   179,    30,   129,   130,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,    26,    62,    64,    81,    86,   126,   127,   131,    31,
     167,   150,   151,   200,   152,   153,   154,   155,   156,   157,
      21,   128,   118,   119,   120,   138,   121,   139,   129,   130,
      22,    23,   158,   159,   160,   161,   162,    17,    18,    87,
     211,   117,    47,    48,    32,   122,   135,   199,    95,   123,
     131,   222,    98,    36,    33,   125,   125,    37,   150,   151,
     125,   152,   153,   154,   155,   156,   157,    70,    34,     4,
     150,   151,     5,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,    55,    90,    57,    49,    50,    35,
     181,   158,   159,   160,   161,   162,    99,    38,   101,    41,
     150,   151,   202,   152,   153,   154,   155,   156,   157,   218,
     219,    53,   150,   151,   223,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,    39,    40,    56,    11,
      44,    45,   204,   158,   159,   160,   161,   162,    12,    13,
      14,    42,   150,   151,   205,   152,   153,   154,   155,   156,
     157,    43,   150,   151,    58,   152,   153,   154,   155,   156,
     157,   112,    18,   158,   159,   160,   161,   162,    65,    66,
      67,    68,   163,   158,   159,   160,   161,   162,    69,    71,
     150,   151,   206,   152,   153,   154,   155,   156,   157,   118,
     119,   120,    73,   121,   118,   119,   120,    11,   121,    74,
      76,   158,   159,   160,   161,   162,   100,    13,    14,   197,
      77,    78,   122,   220,    79,    82,   123,   122,    89,   150,
     151,   123,   152,   153,   154,   155,   156,   157,   150,   151,
      91,   152,   153,   154,   155,   156,   157,    11,   105,    93,
     158,   159,   160,   161,   162,    97,   104,    13,    14,   107,
     110,   160,   161,   162,   150,   151,    11,   152,   153,   154,
     155,   156,   157,   114,    29,   106,    13,    14,   134,   150,
     151,   141,   152,   153,   154,   155,   156,   157,   161,   162,
     136,   147,   146,   142,   143,   138,   165,   139,   164,   144,
     145,   166,   172,   173,   176,   157,   196,   198,   195,   201,
     216,   139,   215,   203,   207,   210,   208,   224,   212,   213,
     214,   225,   226,     9,    94,    59,     0,    54,     0,   180
};

static const yytype_int16 yycheck[] =
{
     113,     4,   114,    76,     4,     4,   197,     4,     4,     4,
       4,    73,    85,     0,     3,     4,   128,   208,    80,   131,
     107,    47,    43,   110,    97,    51,   138,    53,   141,    18,
     142,    93,   144,   145,   146,    35,    25,    26,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,    50,    49,    49,    49,    49,     3,     4,    47,     4,
      49,    16,    17,   172,    19,    20,    21,    22,    23,    24,
       4,    18,     4,     5,     6,    51,     8,    53,    25,    26,
      14,    15,    37,    38,    39,    40,    41,    14,    15,    75,
     199,   111,    33,    34,     4,    27,   116,    52,    84,    31,
      47,    33,    88,    47,     4,   218,   219,    51,    16,    17,
     223,    19,    20,    21,    22,    23,    24,    58,     4,     9,
      16,    17,    12,    19,    20,    21,    22,    23,    24,    37,
      38,    39,    40,    41,    41,    78,    43,    14,    15,    44,
      48,    37,    38,    39,    40,    41,    89,     4,    91,    47,
      16,    17,    48,    19,    20,    21,    22,    23,    24,   215,
     216,     3,    16,    17,   220,    19,    20,    21,    22,    23,
      24,    37,    38,    39,    40,    41,    45,    46,    48,     4,
      45,    46,    48,    37,    38,    39,    40,    41,    13,    14,
      15,    47,    16,    17,    48,    19,    20,    21,    22,    23,
      24,    47,    16,    17,     4,    19,    20,    21,    22,    23,
      24,    14,    15,    37,    38,    39,    40,    41,    48,    52,
      48,    43,    46,    37,    38,    39,    40,    41,    48,    45,
      16,    17,    46,    19,    20,    21,    22,    23,    24,     4,
       5,     6,     4,     8,     4,     5,     6,     4,     8,    45,
       4,    37,    38,    39,    40,    41,    13,    14,    15,    45,
      43,    12,    27,    28,    43,    46,    31,    27,    12,    16,
      17,    31,    19,    20,    21,    22,    23,    24,    16,    17,
      12,    19,    20,    21,    22,    23,    24,     4,    10,     4,
      37,    38,    39,    40,    41,     4,    13,    14,    15,    10,
      10,    39,    40,    41,    16,    17,     4,    19,    20,    21,
      22,    23,    24,    34,     4,    13,    14,    15,    11,    16,
      17,    47,    19,    20,    21,    22,    23,    24,    40,    41,
      11,    47,    36,    47,    47,    51,    11,    53,    44,    47,
      47,    44,     4,     4,     4,    24,     4,    48,    44,    48,
      32,    53,    29,    48,    48,    46,    45,    30,    46,    46,
      46,    46,    46,     6,    82,    45,    -1,    39,    -1,   147
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,    57,     0,     9,    12,    56,     4,    69,    61,
      43,     4,    13,    14,    15,    70,    71,    14,    15,    62,
      63,     4,    14,    15,    58,     4,    50,    72,    73,     4,
      35,     4,     4,     4,     4,    44,    47,    51,     4,    45,
      46,    47,    47,    47,    45,    46,    59,    59,    59,    14,
      15,    64,    65,     3,    73,    64,    48,    64,     4,    58,
      60,     4,    49,     4,    49,    48,    52,    48,    43,    48,
      59,    45,    67,     4,    45,    68,     4,    43,    12,    43,
       4,    49,    46,    66,    67,     4,    49,    66,    68,    12,
      69,    12,    67,     4,    65,    66,    68,     4,    66,    69,
      13,    69,    67,    68,    13,    10,    13,    10,    61,    74,
      10,    74,    14,    75,    34,    83,    74,    83,     4,     5,
       6,     8,    27,    31,    76,    79,     3,     4,    18,    25,
      26,    47,    78,    79,    11,    83,    11,    47,    51,    53,
      80,    47,    47,    47,    47,    47,    36,    47,    78,    78,
      16,    17,    19,    20,    21,    22,    23,    24,    37,    38,
      39,    40,    41,    46,    44,    11,    44,    49,    78,    81,
      82,    78,     4,     4,    79,    78,     4,    78,    78,    78,
      81,    48,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    44,     4,    45,    48,    52,
      80,    48,    48,    48,    48,    48,    46,    48,    45,    82,
      46,    80,    46,    46,    46,    29,    32,    82,    75,    75,
      28,    77,    33,    75,    30,    46,    46
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
#line 41 "compiler.y"
    {TypeTable = (yyvsp[(1) - (4)].TNode);Compile((yyvsp[(2) - (4)].Node),(yyvsp[(3) - (4)].Node),(yyvsp[(4) - (4)].Node)); }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 43 "compiler.y"
    {(yyval.Node) = (yyvsp[(2) - (3)].Node);}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 47 "compiler.y"
    { (yyval.TNode) = Tcreate((yyvsp[(3) - (6)].chp),(yyvsp[(5) - (6)].FNode));(yyval.TNode)->NEXT = (yyvsp[(1) - (6)].TNode);}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 49 "compiler.y"
    {(yyval.TNode) = NULL;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 54 "compiler.y"
    { (yyval.FNode) = Fcreate((yyvsp[(2) - (3)].chp),NULL,Integer); (yyval.FNode)->NEXT = (yyvsp[(3) - (3)].FNode);}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 56 "compiler.y"
    { (yyval.FNode) = Fcreate((yyvsp[(2) - (3)].chp),(yyvsp[(1) - (3)].chp),Typedef); (yyval.FNode)->NEXT = (yyvsp[(3) - (3)].FNode);}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 58 "compiler.y"
    { (yyval.FNode) = Fcreate((yyvsp[(2) - (3)].chp),NULL,Boolean); (yyval.FNode)->NEXT = (yyvsp[(3) - (3)].FNode); }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 63 "compiler.y"
    { (yyval.FNode) = Fcreate((yyvsp[(2) - (3)].chp),NULL,Void); (yyval.FNode)->NEXT = (yyvsp[(3) - (3)].FNode);}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 65 "compiler.y"
    {(yyval.FNode) = (yyvsp[(2) - (2)].FNode); }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 68 "compiler.y"
    {(yyval.FNode) = (yyvsp[(1) - (1)].FNode);}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 70 "compiler.y"
    { (yyval.FNode) = NULL; }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 75 "compiler.y"
    {(yyval.Node)=TreeCreate(Void,0,NULL,NULL,(yyvsp[(1) - (2)].Node),(yyvsp[(2) - (2)].Node),NULL,Continue);}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 77 "compiler.y"
    {(yyval.Node) = NULL;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 79 "compiler.y"
    {
																(yyval.Node) = TreeCreate(Integer,0,(yyvsp[(2) - (14)].chp),(yyvsp[(4) - (14)].ArgNode),(yyvsp[(8) - (14)].Node),(yyvsp[(11) - (14)].Node),(yyvsp[(12) - (14)].Node),FunctionDef);}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 82 "compiler.y"
    {
																(yyval.Node) = TreeCreate(Boolean,0,(yyvsp[(2) - (14)].chp),(yyvsp[(4) - (14)].ArgNode),(yyvsp[(8) - (14)].Node),(yyvsp[(11) - (14)].Node),(yyvsp[(12) - (14)].Node),FunctionDef);}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 85 "compiler.y"
    {
																(yyval.Node)=TreeCreate(Integer,0,"main",NULL,(yyvsp[(7) - (13)].Node),(yyvsp[(10) - (13)].Node),(yyvsp[(11) - (13)].Node),Main);}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 90 "compiler.y"
    {(yyval.ArgNode)=(yyvsp[(1) - (1)].ArgNode);}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 92 "compiler.y"
    { (yyval.ArgNode) = NULL; }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 95 "compiler.y"
    { (yyval.ArgNode) = Argcreate((yyvsp[(2) - (4)].chp),Integer,NULL); if((yyvsp[(3) - (4)].ArgNode) != NULL){(yyval.ArgNode)->NEXT = (yyvsp[(3) - (4)].ArgNode);(yyvsp[(3) - (4)].ArgNode) = (yyvsp[(4) - (4)].ArgNode);}else (yyval.ArgNode)->NEXT = (yyvsp[(4) - (4)].ArgNode);}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 97 "compiler.y"
    { (yyval.ArgNode) = Argcreate((yyvsp[(3) - (5)].chp),RefInt,NULL); if((yyvsp[(4) - (5)].ArgNode) != NULL){(yyval.ArgNode)->NEXT = (yyvsp[(4) - (5)].ArgNode);(yyvsp[(4) - (5)].ArgNode) = (yyvsp[(5) - (5)].ArgNode);}else (yyval.ArgNode)->NEXT = (yyvsp[(5) - (5)].ArgNode);}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 99 "compiler.y"
    { (yyval.ArgNode) = Argcreate((yyvsp[(2) - (4)].chp),Boolean,NULL); if((yyvsp[(3) - (4)].ArgNode) != NULL){(yyval.ArgNode)->NEXT = (yyvsp[(3) - (4)].ArgNode);(yyvsp[(3) - (4)].ArgNode) = (yyvsp[(4) - (4)].ArgNode);}else (yyval.ArgNode)->NEXT = (yyvsp[(4) - (4)].ArgNode);}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 101 "compiler.y"
    { (yyval.ArgNode) = Argcreate((yyvsp[(3) - (5)].chp),RefBool,NULL); if((yyvsp[(4) - (5)].ArgNode) != NULL){(yyval.ArgNode)->NEXT = (yyvsp[(4) - (5)].ArgNode);(yyvsp[(4) - (5)].ArgNode) = (yyvsp[(5) - (5)].ArgNode);}else (yyval.ArgNode)->NEXT = (yyvsp[(5) - (5)].ArgNode);}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 105 "compiler.y"
    {(yyval.ArgNode)=(yyvsp[(2) - (2)].ArgNode);}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 107 "compiler.y"
    {(yyval.ArgNode) = NULL;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 110 "compiler.y"
    { (yyval.ArgNode) = Argcreate((yyvsp[(2) - (3)].chp),Integer,NULL);(yyval.ArgNode)->NEXT = (yyvsp[(3) - (3)].ArgNode);}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 112 "compiler.y"
    { (yyval.ArgNode) = Argcreate((yyvsp[(3) - (4)].chp),RefInt,NULL);(yyval.ArgNode)->NEXT = (yyvsp[(4) - (4)].ArgNode);}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 114 "compiler.y"
    { (yyval.ArgNode) = NULL;	}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 117 "compiler.y"
    { (yyval.ArgNode) = Argcreate((yyvsp[(2) - (3)].chp),Boolean,NULL);(yyval.ArgNode)->NEXT = (yyvsp[(3) - (3)].ArgNode);}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 119 "compiler.y"
    { (yyval.ArgNode) = Argcreate((yyvsp[(3) - (4)].chp),RefBool,NULL);(yyval.ArgNode)->NEXT = (yyvsp[(4) - (4)].ArgNode);}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 121 "compiler.y"
    {  (yyval.ArgNode) = NULL;	}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 126 "compiler.y"
    {(yyval.Node)=TreeCreate(Void,0,NULL,NULL,(yyvsp[(1) - (2)].Node),(yyvsp[(2) - (2)].Node),NULL,Continue);}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 128 "compiler.y"
    {(yyval.Node) = NULL;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 131 "compiler.y"
    {(yyval.Node)=TreeCreate(Void,0,NULL,NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(2) - (3)].Node),NULL,Dstatement);}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 135 "compiler.y"
    {(yyval.Node)=TreeCreate(Integer,0,NULL,NULL,NULL,NULL,NULL,Type);}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 137 "compiler.y"
    {(yyval.Node)=TreeCreate(Boolean,0,NULL,NULL,NULL,NULL,NULL,Type);}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 139 "compiler.y"
    {(yyval.Node)=TreeCreate(Typedef,0,(yyvsp[(1) - (1)].chp),NULL,NULL,NULL,NULL,Type);}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 143 "compiler.y"
    {(yyval.Node)=TreeCreate(Void,0,NULL,NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,Continue);}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 145 "compiler.y"
    {(yyval.Node)=TreeCreate(Void,0,NULL,NULL,(yyvsp[(1) - (1)].Node),NULL,NULL,Continue);}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 150 "compiler.y"
    {(yyval.Node)=TreeCreate(Void,1,(yyvsp[(1) - (1)].chp),NULL,NULL,NULL,NULL,Decl);}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 152 "compiler.y"
    {(yyval.Node)=TreeCreate(Void,0,(yyvsp[(2) - (2)].chp),NULL,NULL,NULL,NULL,Pointer);}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 154 "compiler.y"
    {(yyval.Node)=TreeCreate(Void,(yyvsp[(3) - (4)].Num),(yyvsp[(1) - (4)].chp),NULL,NULL,NULL,NULL,Array);}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 156 "compiler.y"
    {(yyval.Node)=TreeCreate(Void,0,(yyvsp[(1) - (4)].chp),(yyvsp[(3) - (4)].ArgNode),NULL,NULL,NULL,FunctionDecl);}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 160 "compiler.y"
    {(yyval.Node) = TreeCreate(Void,0,NULL,NULL,(yyvsp[(1) - (2)].Node),(yyvsp[(2) - (2)].Node),NULL,Continue);}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 162 "compiler.y"
    { (yyval.Node) = TreeCreate(Void,0,NULL,NULL,(yyvsp[(1) - (2)].Node),(yyvsp[(2) - (2)].Node),NULL,Continue); }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 164 "compiler.y"
    {(yyval.Node) = NULL;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 169 "compiler.y"
    { (yyval.Node) = TreeCreate(Void,0,NULL,NULL,(yyvsp[(3) - (5)].Node),NULL,NULL,Read); }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 171 "compiler.y"
    { (yyval.Node) = TreeCreate(Void,0,NULL,NULL,(yyvsp[(3) - (5)].Node),NULL,NULL,Write); }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 173 "compiler.y"
    { (yyval.Node) = TreeCreate(Void,0,NULL,NULL,(yyvsp[(1) - (4)].Node),(yyvsp[(3) - (4)].Node),NULL,Initialize); }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 175 "compiler.y"
    { (yyval.Node) = TreeCreate(Void,0,(yyvsp[(1) - (5)].chp),(yyvsp[(3) - (5)].ArgNode),NULL,NULL,NULL,Function); }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 177 "compiler.y"
    {(yyval.Node) = TreeCreate(Void,0,NULL,NULL,(yyvsp[(3) - (9)].Node),(yyvsp[(6) - (9)].Node),(yyvsp[(7) - (9)].Node),Conditional);}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 179 "compiler.y"
    {(yyval.Node) = TreeCreate(Void,0,NULL,NULL,(yyvsp[(3) - (8)].Node),(yyvsp[(6) - (8)].Node),NULL,Iterative);}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 181 "compiler.y"
    { (yyval.Node) = TreeCreate(Void,0,(yyvsp[(3) - (5)].chp),NULL,NULL,NULL,NULL,Free);}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 186 "compiler.y"
    {(yyval.Node) = (yyvsp[(2) - (2)].Node);}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 188 "compiler.y"
    {(yyval.Node) = NULL;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 193 "compiler.y"
    { (yyval.Node) = TreeCreate(Integer,(yyvsp[(1) - (1)].Num),NULL,NULL,NULL,NULL,NULL,Digit); }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 195 "compiler.y"
    { (yyval.Node) = TreeCreate(Integer,0,NULL,NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,Addition); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 197 "compiler.y"
    { (yyval.Node) = TreeCreate(Integer,0,NULL,NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,Subtraction); }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 199 "compiler.y"
    { (yyval.Node) = TreeCreate(Integer,0,NULL,NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,Multiplacation); }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 201 "compiler.y"
    { (yyval.Node) = TreeCreate(Integer,0,NULL,NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,Division); }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 203 "compiler.y"
    { (yyval.Node) = TreeCreate(Integer,0,NULL,NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,Remainder); }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 205 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,NULL,NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,GreaterThen); }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 207 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,NULL,NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,GreaterThenEqual); }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 209 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,NULL,NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,LessThen); }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 211 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,NULL,NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,LessThenEqual); }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 213 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,NULL,NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,Equal); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 215 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,NULL,NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,NotEqual); }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 217 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,NULL,NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,And); }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 219 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,NULL,NULL,(yyvsp[(1) - (3)].Node),(yyvsp[(3) - (3)].Node),NULL,Or); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 221 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,NULL,NULL,(yyvsp[(2) - (2)].Node),NULL,NULL,Not); }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 223 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,NULL,NULL,NULL,NULL,NULL,True); }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 225 "compiler.y"
    { (yyval.Node) = TreeCreate(Boolean,0,NULL,NULL,NULL,NULL,NULL,False); }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 227 "compiler.y"
    { (yyval.Node) = TreeCreate(Void,0,(yyvsp[(1) - (4)].chp),(yyvsp[(3) - (4)].ArgNode),NULL,NULL,NULL,Function); }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 229 "compiler.y"
    {(yyval.Node) = (yyvsp[(1) - (1)].Node);}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 231 "compiler.y"
    { (yyval.Node) = (yyvsp[(2) - (3)].Node); }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 236 "compiler.y"
    {(yyval.Node) = TreeCreate(Void,0,(yyvsp[(1) - (2)].chp),(yyvsp[(2) - (2)].ArgNode),NULL,NULL,NULL,Variable); }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 238 "compiler.y"
    {(yyval.Node) = TreeCreate(Void,0,(yyvsp[(1) - (5)].chp),(yyvsp[(5) - (5)].ArgNode),(yyvsp[(3) - (5)].Node),NULL,NULL,ArrayVariable); }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 241 "compiler.y"
    { (yyval.ArgNode) = Argcreate((yyvsp[(2) - (3)].chp),Boolean,NULL);(yyval.ArgNode)->NEXT = (yyvsp[(3) - (3)].ArgNode);}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 243 "compiler.y"
    {(yyval.ArgNode) = NULL;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 248 "compiler.y"
    {(yyval.ArgNode) = (yyvsp[(1) - (1)].ArgNode);}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 250 "compiler.y"
    { (yyval.ArgNode) = NULL; }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 252 "compiler.y"
    { (yyval.ArgNode) = Argcreate(NULL,Void,(yyvsp[(1) - (3)].Node)); (yyval.ArgNode)->NEXT = (yyvsp[(3) - (3)].ArgNode);}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 254 "compiler.y"
    { (yyval.ArgNode) = Argcreate((yyvsp[(2) - (4)].chp),RefBool,NULL); (yyval.ArgNode)->NEXT = (yyvsp[(4) - (4)].ArgNode); }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 256 "compiler.y"
    { (yyval.ArgNode) = Argcreate(NULL,Void,(yyvsp[(1) - (1)].Node)); }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 258 "compiler.y"
    { (yyval.ArgNode) = Argcreate((yyvsp[(2) - (2)].chp),RefBool,NULL); }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 263 "compiler.y"
    {(yyval.Node) = (yyvsp[(2) - (3)].Node);}
    break;



/* Line 1455 of yacc.c  */
#line 2213 "y.tab.c"
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


int yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
	return 1;
}

int main(int argc,char **argv) {
	yyin=fopen(argv[1],"r");
	yyparse();
	fclose(yyin);
	return 1;
}

