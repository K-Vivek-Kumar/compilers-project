
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
#line 1 "parser.y"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

extern FILE * outFile;
extern FILE * yyin;
void yyerror(char *s);

bool intreg[10];
bool floatreg[10];
int switchglobal;
FILE*fp;
FILE*fil;
int canbreakarr[10][20];
int canbreakcount[10];
struct varrecord
{
	char varname[100];
	char vartype[100];
	char finalname[100];
	bool tag;
	int level;

	bool IsArr;
	int dimcount;
	int dim[100];
	int moddim[100];
};
struct funcrecord
{
	char name[100];
	char type[100];
	struct varrecord paramtable[100];
	struct varrecord vartable[100];
	int paramcount;
	int varcount;  
};


struct funcrecord functable[1000];
bool success=true;
int actfuncindex=0;
int canbreak=0;
int callfuncindex;
int globallevel=0;
void releasetemp(int i);
int newtemp();
int InArr(struct varrecord arr[],int size,char finder[]);
bool CheckVar (struct varrecord arr[],int size,char finder[],int level);
void PrintVars(struct varrecord a);
void PrintFuncs(struct funcrecord a);
void despace(char target[], char input[], int l);
void PrintFuncTable();
int stoi(char*s);
int nextquad=1;

char vars[100][100];
char types[100][100];
int sizes[100];
int totvars=0;



/* Line 189 of yacc.c  */
#line 140 "parser.tab.c"

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
     SELECT = 258,
     PRINT = 259,
     INT = 260,
     FLT = 261,
     ID = 262,
     FIVESTAR = 263,
     SC = 264,
     SP = 265,
     COMMA = 266,
     COLON = 267,
     EQ = 268,
     OR = 269,
     AND = 270,
     NOT = 271,
     LT = 272,
     LTE = 273,
     GT = 274,
     GTE = 275,
     EQEQ = 276,
     NEQ = 277,
     DEFENV = 278,
     PLUS = 279,
     MINUS = 280,
     MULT = 281,
     DIV = 282,
     MOD = 283,
     OPT = 284,
     CPT = 285,
     OCURLY = 286,
     CCURLY = 287,
     IF = 288,
     ELSE = 289,
     FORT = 290,
     WHILET = 291,
     VOID = 292,
     RET = 293,
     SWITCHT = 294,
     CASET = 295,
     BREAK = 296,
     DEFAULT = 297,
     CSQ = 298,
     OSQ = 299,
     NUM = 300,
     DOL = 301
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 124 "parser.y"

  struct attributes{
  	char vali[1000];
	char type[1000];
	
	int arr;
	int ind;

	int counter;
	int countor;
	int countand;
	bool caseallow;
	bool isarray;

	int bplist[1000];
	int bpcount;
	int tempreg;
	int quad;
	int begin;
	int bplist2[1000];
	int bpcount2;
	} vp;



/* Line 214 of yacc.c  */
#line 248 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 260 "parser.tab.c"

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   201

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNRULES -- Number of states.  */
#define YYNSTATES  217

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,    10,    13,    15,    16,    20,    23,
      26,    28,    31,    34,    35,    37,    42,    45,    47,    49,
      51,    53,    54,    58,    60,    63,    66,    69,    73,    76,
      80,    84,    86,    87,    90,    92,    94,    96,    98,   100,
     103,   106,   109,   111,   113,   116,   122,   123,   125,   128,
     133,   135,   137,   138,   142,   144,   147,   153,   154,   157,
     160,   167,   171,   172,   173,   176,   183,   184,   185,   190,
     194,   196,   198,   202,   204,   208,   210,   212,   215,   220,
     224,   226,   230,   234,   239,   244,   248,   250,   254,   256,
     258,   261,   265,   269,   273,   277,   281,   285,   287,   291,
     295,   297,   301,   305,   309,   311,   313,   315,   317,   321,
     323,   326,   331,   335,   340,   345,   349,   351,   355,   358,
     360,   364,   365,   370,   372,   373
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,    -1,    51,    52,    50,    53,    -1,
      50,    53,    -1,    55,    -1,    -1,    52,    46,    87,    -1,
      46,    87,    -1,    54,    53,    -1,    54,    -1,    56,    64,
      -1,     1,     9,    -1,    -1,    23,    -1,    57,    29,    59,
      30,    -1,    58,     7,    -1,     5,    -1,     6,    -1,    37,
      -1,    60,    -1,    -1,    60,    11,    61,    -1,    61,    -1,
      88,     7,    -1,    88,    62,    -1,     7,    63,    -1,    63,
      44,    43,    -1,    44,    43,    -1,    31,    65,    32,    -1,
      65,    66,    67,    -1,    67,    -1,    -1,     1,     9,    -1,
      87,    -1,    95,    -1,    83,    -1,    77,    -1,    74,    -1,
      68,    64,    -1,    70,     9,    -1,    69,     9,    -1,     8,
      -1,   105,    -1,    41,     9,    -1,     4,    29,    96,    30,
       9,    -1,    -1,    38,    -1,    38,    96,    -1,    71,    29,
      72,    30,    -1,     7,    -1,    73,    -1,    -1,    73,    11,
      96,    -1,    96,    -1,    75,    64,    -1,    36,    76,    29,
      96,    30,    -1,    -1,    78,    64,    -1,    79,    80,    -1,
      35,    29,    95,    81,    96,     9,    -1,    82,    94,    30,
      -1,    -1,    -1,    86,    64,    -1,    86,    64,    84,    34,
      85,    64,    -1,    -1,    -1,    33,    29,    96,    30,    -1,
      88,    89,     9,    -1,     5,    -1,     6,    -1,    89,    11,
      93,    -1,    93,    -1,    89,    11,    90,    -1,    90,    -1,
      91,    -1,     7,    92,    -1,    92,    44,    45,    43,    -1,
      44,    45,    43,    -1,     7,    -1,     7,    13,    96,    -1,
     103,    13,    96,    -1,     7,    13,    96,     9,    -1,   103,
      13,    96,     9,    -1,    96,    14,    97,    -1,    97,    -1,
      97,    15,    98,    -1,    98,    -1,    99,    -1,    16,    99,
      -1,    99,    17,   100,    -1,    99,    18,   100,    -1,    99,
      19,   100,    -1,    99,    20,   100,    -1,    99,    22,   100,
      -1,    99,    21,   100,    -1,   100,    -1,   100,    24,   101,
      -1,   100,    25,   101,    -1,   101,    -1,   101,    26,   102,
      -1,   101,    27,   102,    -1,   101,    28,   102,    -1,   102,
      -1,     7,    -1,    45,    -1,    70,    -1,    29,    96,    30,
      -1,   103,    -1,     7,   104,    -1,   104,    44,    96,    43,
      -1,    44,    96,    43,    -1,   106,    31,   107,    32,    -1,
      39,    29,    96,    30,    -1,   109,   114,   108,    -1,   109,
      -1,    42,    12,    65,    -1,   109,   110,    -1,   110,    -1,
     112,   111,   113,    -1,    -1,    40,   115,    96,    12,    -1,
      65,    -1,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   151,   151,   154,   155,   158,   162,   168,   169,   172,
     173,   176,   188,   192,   195,   197,   203,   214,   215,   216,
     218,   219,   220,   221,   223,   252,   280,   284,   285,   288,
     307,   316,   324,   326,   327,   328,   329,   337,   352,   366,
     374,   375,   379,   380,   396,   406,   428,   430,   439,   480,
     522,   547,   550,   554,   605,   658,   670,   694,   699,   714,
     729,   755,   757,   759,   765,   779,   800,   808,   810,   834,
     849,   850,   852,   853,   854,   855,   858,   861,   915,   940,
     968,  1013,  1111,  1178,  1276,  1344,  1413,  1425,  1495,  1505,
    1512,  1542,  1624,  1708,  1793,  1877,  1961,  2045,  2052,  2127,
    2202,  2209,  2287,  2362,  2437,  2445,  2545,  2585,  2598,  2607,
    2638,  2760,  2773,  2785,  2796,  2806,  2817,  2824,  2834,  2843,
    2853,  2869,  2870,  2889,  2896,  2897
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SELECT", "PRINT", "INT", "FLT", "ID",
  "FIVESTAR", "SC", "SP", "COMMA", "COLON", "EQ", "OR", "AND", "NOT", "LT",
  "LTE", "GT", "GTE", "EQEQ", "NEQ", "DEFENV", "PLUS", "MINUS", "MULT",
  "DIV", "MOD", "OPT", "CPT", "OCURLY", "CCURLY", "IF", "ELSE", "FORT",
  "WHILET", "VOID", "RET", "SWITCHT", "CASET", "BREAK", "DEFAULT", "CSQ",
  "OSQ", "NUM", "DOL", "$accept", "START", "INPUTGLOBAL", "NGL", "MGL",
  "GLIST", "INPUT", "FUNC_DECL", "ENVS", "FUNC_HEAD", "RESULT_ID",
  "RESULT", "DECLISTE", "DECLIST", "DEC", "ARRFUNC", "LISTFUNC", "BODY",
  "SLIST", "MSLIST", "S", "INCRLEVEL", "RETURN", "FUNC_CALL", "IDTEMP",
  "PARAMLIST", "PLIST", "WHILE", "WHILEXP", "MWHILE", "FOR", "FOREXP",
  "FORBACK1", "FORBACK2", "MFOR", "NFOR", "IFELSE", "NIF", "MIF", "IFEXP",
  "VAR_DECL", "TYPE", "L", "ARRS", "ARR", "BRLIST", "IDS", "FORASSIGN",
  "ASSIGN", "COR", "CAND", "CNOT", "ECOMP", "E", "T", "F", "ARRF",
  "ARRFLIST", "SWITCH", "SWITCHET", "CASES", "DEFAULTE", "CASELIST",
  "CASE", "CMARK", "CASETEMP", "CBODY", "MCASE", "NCASE", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    51,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    57,    58,    58,    58,
      59,    59,    60,    60,    61,    61,    62,    63,    63,    64,
      65,    65,    66,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    68,    69,    69,    70,
      71,    72,    72,    73,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    83,    84,    85,    86,    87,
      88,    88,    89,    89,    89,    89,    90,    91,    92,    92,
      93,    94,    94,    95,    95,    96,    96,    97,    97,    98,
      98,    99,    99,    99,    99,    99,    99,    99,   100,   100,
     100,   101,   101,   101,   101,   102,   102,   102,   102,   102,
     103,   104,   104,   105,   106,   107,   107,   108,   109,   109,
     110,   111,   112,   113,   114,   115
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     4,     2,     1,     0,     3,     2,     2,
       1,     2,     2,     0,     1,     4,     2,     1,     1,     1,
       1,     0,     3,     1,     2,     2,     2,     3,     2,     3,
       3,     1,     0,     2,     1,     1,     1,     1,     1,     2,
       2,     2,     1,     1,     2,     5,     0,     1,     2,     4,
       1,     1,     0,     3,     1,     2,     5,     0,     2,     2,
       6,     3,     0,     0,     2,     6,     0,     0,     4,     3,
       1,     1,     3,     1,     3,     1,     1,     2,     4,     3,
       1,     3,     3,     4,     4,     3,     1,     3,     1,     1,
       2,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     1,     1,     1,     3,     1,
       2,     4,     3,     4,     4,     3,     1,     3,     2,     1,
       3,     0,     4,     1,     0,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      13,    14,     0,     2,     0,     0,     5,     1,     0,    17,
      18,    19,     4,     0,     0,     0,     0,     0,    13,    12,
       9,     0,    11,    21,    16,    70,    71,     8,     0,     0,
       0,     0,     0,    50,    42,     0,     0,    57,    47,     0,
       0,    32,    31,     0,     0,     0,     0,    38,     0,    37,
       0,    63,    36,     0,    34,    35,     0,    43,     0,     0,
      20,    23,     0,    80,     0,    75,    76,    73,     7,     3,
      33,     0,     0,     0,   110,     0,     0,     0,   105,     0,
       0,   106,   107,    48,    86,    88,    89,    97,   100,   104,
     109,     0,    44,    29,     0,    39,    41,    40,    52,    55,
      58,    59,     0,    64,     0,     0,    15,     0,    24,    25,
       0,    77,    69,     0,     0,     0,     0,     0,     0,     0,
      62,     0,    90,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,     0,
      51,    54,     0,     0,     0,     0,     0,   125,     0,   116,
     119,   121,    22,     0,    26,     0,     0,    74,    72,     0,
      83,   112,     0,    68,     0,     0,   108,    85,    87,    91,
      92,    93,    94,    96,    95,    98,    99,   101,   102,   103,
     114,    49,     0,     0,    61,     0,    67,    84,     0,   113,
     118,     0,     0,    28,     0,    79,     0,    45,   111,     0,
      56,    53,    81,    82,     0,     0,     0,   115,    32,   120,
      27,    78,    60,    65,   122,     0,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,    18,    12,    13,     6,    14,
      15,    16,    59,    60,    61,   109,   154,    22,    41,    94,
      42,    43,    44,    82,    46,   139,   140,    47,    48,    77,
      49,    50,    51,   101,   164,   102,    52,   145,   204,    53,
      54,    28,    64,    65,    66,   111,    67,   143,    55,    83,
      84,    85,    86,    87,    88,    89,    90,    74,    57,    58,
     148,   207,   149,   150,   192,   151,   209,   191,   188
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -153
static const yytype_int16 yypact[] =
{
      16,  -153,    38,  -153,    20,    25,  -153,  -153,    66,  -153,
    -153,  -153,  -153,    27,   100,    49,   113,    90,    24,  -153,
    -153,    10,  -153,    90,  -153,  -153,  -153,  -153,   125,    90,
      20,    75,   104,   -10,  -153,   105,   106,  -153,    13,   107,
     128,   109,  -153,   100,   129,   130,   111,  -153,   100,  -153,
     100,  -153,  -153,   100,  -153,  -153,   131,  -153,   112,   115,
     135,  -153,   140,    98,   108,  -153,  -153,  -153,  -153,  -153,
    -153,    13,    13,    13,   110,    13,   141,   120,    48,    15,
      13,  -153,  -153,   136,   137,  -153,    81,    89,    84,  -153,
    -153,    13,  -153,  -153,    10,  -153,  -153,  -153,    13,  -153,
    -153,  -153,   144,   119,    13,   116,  -153,    90,   117,  -153,
     121,   118,  -153,   125,     5,    76,     9,    13,    39,   -10,
    -153,    13,    81,    42,    13,    13,    15,    15,    15,    15,
      15,    15,    15,    15,    15,    15,    15,    52,  -153,   127,
     147,   136,    17,   134,   142,   126,    77,  -153,   133,    85,
    -153,  -153,  -153,   124,   132,   138,   123,  -153,  -153,   150,
    -153,  -153,    22,  -153,    13,    53,  -153,   137,  -153,    89,
      89,    89,    89,    89,    89,    84,    84,  -153,  -153,  -153,
    -153,  -153,    13,    13,  -153,    13,  -153,  -153,    13,  -153,
    -153,   143,    10,  -153,   139,  -153,   145,  -153,  -153,    79,
    -153,   136,   136,   136,   100,   114,   157,  -153,    47,  -153,
    -153,  -153,  -153,  -153,  -153,    10,   146
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,  -153,   152,  -153,  -153,    46,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,    67,  -153,  -153,   -41,  -152,  -153,
      83,  -153,  -153,   -20,  -153,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,
      51,   -13,  -153,    60,  -153,  -153,    62,  -153,   103,   -67,
      56,    58,   122,   -22,    -3,   -12,   -21,  -153,  -153,  -153,
    -153,  -153,  -153,    35,  -153,  -153,  -153,  -153,  -153
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -125
static const yytype_int16 yytable[] =
{
      56,    45,    95,    72,   114,   115,   116,    99,   118,   100,
      62,    31,   103,   123,    32,    25,    26,    33,    34,   124,
      78,     8,    78,   124,   137,     9,    10,   -10,     8,    79,
     183,   141,     9,    10,    73,   159,   124,   146,     7,     1,
     208,   -46,    80,    35,    80,    36,    37,     1,    38,    39,
     162,    40,   161,   124,   165,    56,   124,    11,    81,    20,
      81,    73,    -6,   216,    11,   198,   124,   124,    27,   163,
      29,    17,   166,    56,    45,    19,    69,   -50,    23,  -123,
      68,   144,   180,   200,    70,   160,   187,  -123,   212,  -123,
     124,   124,    73,   124,    62,    25,    26,   199,   126,   127,
     128,   129,   130,   131,   169,   170,   171,   172,   173,   174,
     134,   135,   136,   132,   133,   201,   202,   112,   203,   113,
      24,   205,   177,   178,   179,   147,   214,  -124,   124,   175,
     176,    21,    63,    71,    75,    76,    91,    92,    96,    97,
      98,    93,   110,   105,   104,   106,   107,   108,   119,   121,
     124,   142,   125,   -66,   117,   185,   147,   181,   182,   197,
     186,   153,   156,   213,   184,   189,   155,   193,   196,   215,
      30,    56,    45,   157,   152,   158,   194,   138,  -117,   120,
     167,   195,   210,   168,   190,   206,     0,     0,   211,     0,
       0,     0,     0,     0,    56,    45,     0,     0,     0,     0,
       0,   122
};

static const yytype_int16 yycheck[] =
{
      21,    21,    43,    13,    71,    72,    73,    48,    75,    50,
      23,     1,    53,    80,     4,     5,     6,     7,     8,    14,
       7,     1,     7,    14,    91,     5,     6,     0,     1,    16,
      13,    98,     5,     6,    44,    30,    14,   104,     0,    23,
     192,    31,    29,    33,    29,    35,    36,    23,    38,    39,
     117,    41,    43,    14,   121,    76,    14,    37,    45,    13,
      45,    44,    46,   215,    37,    43,    14,    14,    17,    30,
      46,    46,    30,    94,    94,     9,    30,    29,    29,    32,
      29,   102,    30,    30,     9,     9,     9,    40,     9,    42,
      14,    14,    44,    14,   107,     5,     6,   164,    17,    18,
      19,    20,    21,    22,   126,   127,   128,   129,   130,   131,
      26,    27,    28,    24,    25,   182,   183,     9,   185,    11,
       7,   188,   134,   135,   136,    40,    12,    42,    14,   132,
     133,    31,     7,    29,    29,    29,    29,     9,     9,     9,
      29,    32,    44,    31,    13,    30,    11,     7,     7,    29,
      14,     7,    15,    34,    44,    13,    40,    30,    11,     9,
      34,    44,    44,   204,    30,    32,    45,    43,    45,    12,
      18,   192,   192,   113,   107,   113,    44,    94,    32,    76,
     124,    43,    43,   125,   149,    42,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    -1,   215,   215,    -1,    -1,    -1,    -1,
      -1,    79
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    23,    48,    49,    50,    51,    55,     0,     1,     5,
       6,    37,    53,    54,    56,    57,    58,    46,    52,     9,
      53,    31,    64,    29,     7,     5,     6,    87,    88,    46,
      50,     1,     4,     7,     8,    33,    35,    36,    38,    39,
      41,    65,    67,    68,    69,    70,    71,    74,    75,    77,
      78,    79,    83,    86,    87,    95,   103,   105,   106,    59,
      60,    61,    88,     7,    89,    90,    91,    93,    87,    53,
       9,    29,    13,    44,   104,    29,    29,    76,     7,    16,
      29,    45,    70,    96,    97,    98,    99,   100,   101,   102,
     103,    29,     9,    32,    66,    64,     9,     9,    29,    64,
      64,    80,    82,    64,    13,    31,    30,    11,     7,    62,
      44,    92,     9,    11,    96,    96,    96,    44,    96,     7,
      95,    29,    99,    96,    14,    15,    17,    18,    19,    20,
      21,    22,    24,    25,    26,    27,    28,    96,    67,    72,
      73,    96,     7,    94,   103,    84,    96,    40,   107,   109,
     110,   112,    61,    44,    63,    45,    44,    90,    93,    30,
       9,    43,    96,    30,    81,    96,    30,    97,    98,   100,
     100,   100,   100,   100,   100,   101,   101,   102,   102,   102,
      30,    30,    11,    13,    30,    13,    34,     9,   115,    32,
     110,   114,   111,    43,    44,    43,    45,     9,    43,    96,
      30,    96,    96,    96,    85,    96,    42,   108,    65,   113,
      43,    43,     9,    64,    12,    12,    65
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
        case 5:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    {
			actfuncindex=1;
		 ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 162 "parser.y"
    {
			strcpy(functable[0].name,"global");
			strcpy(functable[0].type,"int");
		;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 176 "parser.y"
    {
							actfuncindex++;  
							globallevel=0;
							 char printer[1000];
							 backpatch((yyvsp[(2) - (2)].vp).bplist,(yyvsp[(2) - (2)].vp).bpcount,nextquad);
							 
							 

							snprintf(printer,999,"func end");
							GenQuad(printer);
							
						;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 188 "parser.y"
    { yyerrok;;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 192 "parser.y"
    {
	CallWarning("You forgot to set an environment.\nDefault as 2-Dimensional\nAdd `@g2d` for removing this warning");
;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 197 "parser.y"
    {
										
										globallevel++;	

										;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 203 "parser.y"
    { functable[actfuncindex].paramcount=0;
						functable[actfuncindex].varcount=0;
						globallevel++;
						strcpy(functable[actfuncindex].name,(yyvsp[(2) - (2)].vp).vali);

						char printer[1000];
						snprintf(printer,999,"func begin %s",(yyvsp[(2) - (2)].vp).vali);
						GenQuad(printer);

					  ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 214 "parser.y"
    {strcpy(functable[actfuncindex].type,"int");;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 215 "parser.y"
    {strcpy(functable[actfuncindex].type,"float");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 216 "parser.y"
    {strcpy(functable[actfuncindex].type,"void");;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 223 "parser.y"
    {
								int finder;
								finder = InArr(functable[actfuncindex].paramtable,functable[actfuncindex].paramcount,(yyvsp[(2) - (2)].vp).vali); 
								if(finder!=-1)
								{
									char printer[1000];
									snprintf(printer,999,"Parameter with name %s already declared.",(yyvsp[(2) - (2)].vp).vali);
									CallError(printer);
								}
								else
								{
									struct varrecord new_record;
									strcpy(new_record.varname,(yyvsp[(2) - (2)].vp).vali);
									strcpy(new_record.vartype,(yyvsp[(1) - (2)].vp).type);
									new_record.tag=false;
									new_record.level = globallevel;
									new_record.IsArr = false;
									new_record.dimcount = 0;

									char finalname[1000];
									snprintf(finalname,999,"%s_%d_%s_%d",new_record.varname,globallevel,functable[actfuncindex].name,functable[actfuncindex].paramcount);

									strcpy(new_record.finalname,finalname);

									functable[actfuncindex].paramtable[functable[actfuncindex].paramcount++]=new_record;
								}
								
							;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 252 "parser.y"
    {
								int finder;
								finder = InArr(functable[actfuncindex].paramtable,functable[actfuncindex].paramcount,(yyvsp[(2) - (2)].vp).vali); 
								if(finder!=-1)
								{
									char printer[1000];
									snprintf(printer,999,"Parameter with name %s already declared.",(yyvsp[(2) - (2)].vp).vali);
									CallError(printer);
								}
								else
								{
									struct varrecord new_record;
									strcpy(new_record.varname,(yyvsp[(2) - (2)].vp).vali);
									strcpy(new_record.vartype,(yyvsp[(1) - (2)].vp).type);
									new_record.tag=false;
									new_record.level = globallevel;
									new_record.IsArr = true;
									new_record.dimcount = (yyvsp[(2) - (2)].vp).counter;

									char finalname[1000];
									snprintf(finalname,999,"%s_%d_%s_%d",new_record.varname,globallevel,functable[actfuncindex].name,functable[actfuncindex].paramcount);

									strcpy(new_record.finalname,finalname);

									functable[actfuncindex].paramtable[functable[actfuncindex].paramcount++]=new_record;
								}	
								;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 280 "parser.y"
    {strcpy((yyval.vp).vali,(yyvsp[(1) - (2)].vp).vali);
							(yyval.vp).counter=(yyvsp[(2) - (2)].vp).counter;;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 284 "parser.y"
    {(yyval.vp).counter=(yyvsp[(1) - (3)].vp).counter+1;;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 285 "parser.y"
    {(yyval.vp).counter=1;;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 288 "parser.y"
    {
								int counter=0;
								int i;
								for(i=functable[actfuncindex].varcount-1;i>=0;i--)
								{
									if(functable[actfuncindex].vartable[i].level==globallevel)
									counter++;
								}
								functable[actfuncindex].varcount -= counter;
								globallevel--;

								(yyval.vp).bpcount=0;
								for(int i=0;i<(yyvsp[(2) - (3)].vp).bpcount;i++)
								{
									(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(2) - (3)].vp).bplist[i];
								}

							;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 307 "parser.y"
    {
								backpatch((yyvsp[(1) - (3)].vp).bplist,(yyvsp[(1) - (3)].vp).bpcount,(yyvsp[(2) - (3)].vp).quad);

								(yyval.vp).bpcount=0;
								for(int i=0;i<(yyvsp[(3) - (3)].vp).bpcount;i++)
								{
									(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(3) - (3)].vp).bplist[i];
								}
							;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 316 "parser.y"
    {
								(yyval.vp).bpcount=0;
								for(int i=0;i<(yyvsp[(1) - (1)].vp).bpcount;i++)
								{
									(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(1) - (1)].vp).bplist[i];
								}
							;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 324 "parser.y"
    { (yyval.vp).quad=nextquad;;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 326 "parser.y"
    { yyerrok;;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 327 "parser.y"
    {;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 328 "parser.y"
    {;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 329 "parser.y"
    {
						(yyval.vp).bpcount=0;
						int i;
						for( i=0;i<(yyvsp[(1) - (1)].vp).bpcount;i++)
						{
							(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(1) - (1)].vp).bplist[i];
						}
				 ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 337 "parser.y"
    {

						(yyval.vp).bpcount=0;
						int i;
						for(i=0;i<canbreakcount[canbreak];i++)
						{
							(yyval.vp).bplist[(yyval.vp).bpcount++]=canbreakarr[canbreak][i];
						}
						canbreakcount[canbreak]=0;
						canbreak--;
						for( i=0;i<(yyvsp[(1) - (1)].vp).bpcount;i++)
						{
							(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(1) - (1)].vp).bplist[i];
						}
				 ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 352 "parser.y"
    {
						(yyval.vp).bpcount=0;
						int i;
						for(i=0;i<canbreakcount[canbreak];i++)
						{
							(yyval.vp).bplist[(yyval.vp).bpcount++]=canbreakarr[canbreak][i];
						}
						canbreakcount[canbreak]=0;
						canbreak--;
						for( i=0;i<(yyvsp[(1) - (1)].vp).bpcount;i++)
						{
							(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(1) - (1)].vp).bplist[i];
						}
				 ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 366 "parser.y"
    {
								(yyval.vp).bpcount=0;
								int i;
								for( i=0;i<(yyvsp[(2) - (2)].vp).bpcount;i++)
								{
									(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(2) - (2)].vp).bplist[i];
								}
							;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 374 "parser.y"
    {;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 375 "parser.y"
    {


					;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 380 "parser.y"
    {
						(yyval.vp).bpcount=0;

						int i;
						for(i=0;i<canbreakcount[canbreak];i++)
						{
							(yyval.vp).bplist[(yyval.vp).bpcount++]=canbreakarr[canbreak][i];
						}
						canbreakcount[canbreak]=0;
						canbreak--;
						for(i=0;i<(yyvsp[(1) - (1)].vp).bpcount;i++){
							(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(1) - (1)].vp).bplist[i];
						}
						releaseint(switchglobal);

				 ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 396 "parser.y"
    {
								if(canbreak==0)
								{
									CallError("Break can only occur within switch or loops.");
								}
								char printer[1000];
								snprintf(printer,999,"goto _____");
								canbreakarr[canbreak][canbreakcount[canbreak]++]=nextquad;
								GenQuad(printer);
							;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 406 "parser.y"
    {
								char printer[1000];
								backpatch((yyvsp[(3) - (5)].vp).bplist,(yyvsp[(3) - (5)].vp).bpcount,nextquad);
								if(!strcmp((yyvsp[(3) - (5)].vp).type,"errortype"))
								{
									CallError("Some error while calling print.");
								}
								else if(!strcmp((yyvsp[(3) - (5)].vp).type,"int"))
								{
									snprintf(printer,999,"print(t%d)",(yyvsp[(3) - (5)].vp).tempreg); 
									GenQuad(printer);
									releaseint((yyvsp[(3) - (5)].vp).tempreg);
								}
								else if(!strcmp((yyvsp[(3) - (5)].vp).type,"float"))
								{
									snprintf(printer,999,"print(f%d)",(yyvsp[(3) - (5)].vp).tempreg); 
									GenQuad(printer);
									releasefloat((yyvsp[(3) - (5)].vp).tempreg);
								}
							;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 428 "parser.y"
    {globallevel++;;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 430 "parser.y"
    {
							if(strcmp(functable[actfuncindex].type,"void"))
							{
								CallWarning("No return value in non-void function.");
							}
							char printer[1000];
							snprintf(printer,999,"return");
							GenQuad(printer);
						;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 439 "parser.y"
    {
							if(!strcmp(functable[actfuncindex].type,"void"))
							{
								CallWarning("Return value in a void function.");
							}
							backpatch((yyvsp[(2) - (2)].vp).bplist,(yyvsp[(2) - (2)].vp).bpcount,nextquad);
							char printer[1000];
							if(!strcmp(functable[actfuncindex].type,"float"))
							{
								int temp2=(yyvsp[(2) - (2)].vp).tempreg;
								if(!strcmp((yyvsp[(2) - (2)].vp).type,"int"))
								{
									temp2=newfloat();
									snprintf(printer,999,"f%d = ConvertToFloat(t%d)",temp2,(yyvsp[(2) - (2)].vp).tempreg);
									releaseint((yyvsp[(2) - (2)].vp).tempreg);
									GenQuad(printer);
								}
								snprintf(printer,999,"return f%d",temp2);
								GenQuad(printer);
								releasefloat(temp2);
								
							}
							else
							{
								int temp2=(yyvsp[(2) - (2)].vp).tempreg;
								if(!strcmp((yyvsp[(2) - (2)].vp).type,"float"))
								{
									temp2=newint();
									snprintf(printer,999,"t%d = ConvertToInt(f%d)",temp2,(yyvsp[(2) - (2)].vp).tempreg);
									releasefloat((yyvsp[(2) - (2)].vp).tempreg);
									GenQuad(printer);
								}
								snprintf(printer,999,"return t%d",temp2);
								GenQuad(printer);
								releaseint(temp2);

							}

						;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 480 "parser.y"
    {
										if(callfuncindex!=-1 && functable[callfuncindex].paramcount!=(yyvsp[(3) - (4)].vp).counter)
										{
											CallError("Number of parameters not matching.");
											strcpy((yyval.vp).type,"errortype");
										}
										else if(callfuncindex==-1)
										{
											strcpy((yyval.vp).type,"errortype");
										}
										else
										{
											strcpy((yyval.vp).type,functable[callfuncindex].type);
										}


										char printer[1000];
										snprintf(printer,999,"call %s,%d",(yyvsp[(1) - (4)].vp).vali,(yyvsp[(3) - (4)].vp).counter+1);
										GenQuad(printer);
										int gettemp;
										if(callfuncindex!=-1)
										{
										if(!strcmp(functable[callfuncindex].type,"int"))
										{	
											gettemp=newint();
											snprintf(printer,999,"refparam t%d",gettemp);
											GenQuad(printer);
										}
										else if(!strcmp(functable[callfuncindex].type,"float"))
										{
											gettemp=newfloat();
											snprintf(printer,999,"refparam f%d",gettemp);
											GenQuad(printer);
										}
										else
											gettemp=-1;

										(yyval.vp).tempreg=gettemp;
										}

									 ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 522 "parser.y"
    {
								int get=-1;
								int i=0;
								for(i=0;i<actfuncindex+1;i++)
								{
									if(!strcmp(functable[i].name,(yyvsp[(1) - (1)].vp).vali))
									{
											get=i;
											break;
									}
								}

								if(get==-1)
								{
									CallError("No such function exists.");
									callfuncindex=-1;
								}
								else
								{
									callfuncindex = get;
								}
								strcpy((yyval.vp).vali,(yyvsp[(1) - (1)].vp).vali);
	
							;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 547 "parser.y"
    {
							(yyval.vp).counter = (yyvsp[(1) - (1)].vp).counter;
						;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 550 "parser.y"
    {
							(yyval.vp).counter = 0;
						;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 554 "parser.y"
    {
							(yyval.vp).counter++;
							backpatch((yyvsp[(3) - (3)].vp).bplist,(yyvsp[(3) - (3)].vp).bpcount,nextquad);
							char checktype[100];
							if(callfuncindex!=-1)
							strcpy(checktype,functable[callfuncindex].paramtable[(yyval.vp).counter-1].vartype);
							else{
							strcpy(checktype,"errortype");
							}

							char printer[1000];
							if(!strcmp((yyvsp[(3) - (3)].vp).type,"int"))
							{
								if(!strcmp(checktype,"float"))
								{
									int gettemp = newfloat();
									
									snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp,(yyvsp[(3) - (3)].vp).tempreg);
									GenQuad(printer);
									releaseint((yyvsp[(3) - (3)].vp).tempreg);
									snprintf(printer,999,"param f%d",gettemp);
									releasefloat(gettemp);

								}
								else
								{
								snprintf(printer,999,"param t%d",(yyvsp[(3) - (3)].vp).tempreg);
								releaseint((yyvsp[(3) - (3)].vp).tempreg);
								}
							}
							if(!strcmp((yyvsp[(3) - (3)].vp).type,"float"))
							{
								if(!strcmp(checktype,"int"))
								{
									int gettemp = newint();
									snprintf(printer,999,"t%d = ConvertToInt(f%d)",gettemp,(yyvsp[(3) - (3)].vp).tempreg);
									GenQuad(printer);
									releasefloat((yyvsp[(3) - (3)].vp).tempreg);
									snprintf(printer,999,"param t%d",gettemp);
									releaseint(gettemp);
								}
								else
								{
								snprintf(printer,999,"param f%d",(yyvsp[(3) - (3)].vp).tempreg);
								releasefloat((yyvsp[(3) - (3)].vp).tempreg);
								}	
							}

							GenQuad(printer);

						;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 605 "parser.y"
    {
							(yyval.vp).counter=1;
							backpatch((yyvsp[(1) - (1)].vp).bplist,(yyvsp[(1) - (1)].vp).bpcount,nextquad);

							char checktype[100];
							if(callfuncindex!=-1)
							strcpy(checktype,functable[callfuncindex].paramtable[(yyval.vp).counter-1].vartype);
							else
							strcpy(checktype,"errortype");
							char printer[1000];
							if(!strcmp((yyvsp[(1) - (1)].vp).type,"int"))
							{
								if(!strcmp(checktype,"float"))
								{
									int gettemp = newfloat();
									
									snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp,(yyvsp[(1) - (1)].vp).tempreg);
									GenQuad(printer);
									releaseint((yyvsp[(1) - (1)].vp).tempreg);
									snprintf(printer,999,"param f%d",gettemp);
									releasefloat(gettemp);

								}
								else
								{
								snprintf(printer,999,"param t%d",(yyvsp[(1) - (1)].vp).tempreg);
								releaseint((yyvsp[(1) - (1)].vp).tempreg);
								}
							}
							if(!strcmp((yyvsp[(1) - (1)].vp).type,"float"))
							{
								if(!strcmp(checktype,"int"))
								{
									int gettemp = newint();
									snprintf(printer,999,"t%d = ConvertToInt(f%d)",gettemp,(yyvsp[(1) - (1)].vp).tempreg);
									GenQuad(printer);
									releasefloat((yyvsp[(1) - (1)].vp).tempreg);
									snprintf(printer,999,"param t%d",gettemp);
									releaseint(gettemp);
								}
								else
								{
								snprintf(printer,999,"param f%d",(yyvsp[(1) - (1)].vp).tempreg);
								releasefloat((yyvsp[(1) - (1)].vp).tempreg);
								}	
							}
							GenQuad(printer);

						;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 658 "parser.y"
    {
										
										char printer[1000];
										snprintf(printer,999,"goto %d",(yyvsp[(1) - (2)].vp).begin);
										GenQuad(printer);
										backpatch((yyvsp[(2) - (2)].vp).bplist,(yyvsp[(2) - (2)].vp).bpcount,(yyvsp[(1) - (2)].vp).begin);
										(yyval.vp).bpcount=0;
										int i;
										for(i=0;i<(yyvsp[(1) - (2)].vp).bpcount;i++)
											(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(1) - (2)].vp).bplist[i];
									;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 670 "parser.y"
    { 
									backpatch((yyvsp[(4) - (5)].vp).bplist,(yyvsp[(4) - (5)].vp).bpcount,nextquad);
									
									int temp2=(yyvsp[(4) - (5)].vp).tempreg;
									char printer[1000];
									if(!strcmp((yyvsp[(4) - (5)].vp).type,"float"))
									{
										temp2=newint();
										snprintf(printer,999,"t%d = ConvertToInt(f%d)",temp2,(yyvsp[(4) - (5)].vp).tempreg);
										releasefloat((yyvsp[(4) - (5)].vp).tempreg);
										GenQuad(printer);
									}

									snprintf(printer,999,"if(t%d == 0) goto _____",temp2);
									(yyval.vp).bpcount=0;
									(yyval.vp).bplist[(yyval.vp).bpcount++]=nextquad;
									GenQuad(printer);
									releaseint(temp2);
									(yyval.vp).begin=(yyvsp[(2) - (5)].vp).quad;

									globallevel++; canbreak++;
									
									;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 694 "parser.y"
    { (yyval.vp).quad=nextquad;;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 699 "parser.y"
    {		
						char printer[1000];
						snprintf(printer,999,"goto _____");
						(yyvsp[(2) - (2)].vp).bplist[(yyvsp[(2) - (2)].vp).bpcount++]=nextquad;
						GenQuad(printer);
						backpatch((yyvsp[(2) - (2)].vp).bplist,(yyvsp[(2) - (2)].vp).bpcount,(yyvsp[(1) - (2)].vp).quad);
						(yyval.vp).bpcount=0;
						int i;
						for(i=0;i<(yyvsp[(1) - (2)].vp).bpcount;i++)
						{
							(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(1) - (2)].vp).bplist[i];
						}	
					;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 714 "parser.y"
    {globallevel++;canbreak++;
								(yyval.vp).quad=(yyvsp[(2) - (2)].vp).quad;
								char printer[1000];
								snprintf(printer,999,"goto %d",(yyvsp[(1) - (2)].vp).quad);
								GenQuad(printer);

								backpatch((yyvsp[(1) - (2)].vp).bplist2,(yyvsp[(1) - (2)].vp).bpcount2,nextquad);
								(yyval.vp).bpcount=0;
								int i;
								for(i=0;i<(yyvsp[(1) - (2)].vp).bpcount;i++)
								{
									(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(1) - (2)].vp).bplist[i];
								}	
							;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 729 "parser.y"
    {
									backpatch((yyvsp[(5) - (6)].vp).bplist,(yyvsp[(5) - (6)].vp).bpcount,nextquad);
									int temp2=(yyvsp[(5) - (6)].vp).tempreg;
									char printer[1000];
									if(!strcmp((yyvsp[(5) - (6)].vp).type,"float"))
									{
										temp2=newint();
										snprintf(printer,999,"t%d = ConvertToInt(f%d)",temp2,(yyvsp[(5) - (6)].vp).tempreg);
										releasefloat((yyvsp[(5) - (6)].vp).tempreg);
										GenQuad(printer);
									}

									snprintf(printer,999,"if(t%d == 0) goto _____",temp2);
									(yyval.vp).bpcount=0;
									(yyval.vp).bplist[(yyval.vp).bpcount++]=nextquad;
									GenQuad(printer);
									releaseint(temp2);
									(yyval.vp).bpcount2=0;
									(yyval.vp).bplist2[(yyval.vp).bpcount2++]=nextquad;
									snprintf(printer,999,"goto _____");
									GenQuad(printer);
									(yyval.vp).quad=(yyvsp[(4) - (6)].vp).quad;

 									;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 755 "parser.y"
    { (yyval.vp).quad=(yyvsp[(1) - (3)].vp).quad;;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 757 "parser.y"
    { (yyval.vp).quad=nextquad;;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 759 "parser.y"
    {(yyval.vp).quad=nextquad;;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 765 "parser.y"
    {
											int i;
											(yyval.vp).bpcount=0;
											for(i=0;i<(yyvsp[(1) - (2)].vp).bpcount;i++)
											{
												(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(1) - (2)].vp).bplist[i];
											}
											for(i=0;i<(yyvsp[(2) - (2)].vp).bpcount;i++)
											{
												(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(2) - (2)].vp).bplist[i];
											}


										;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 779 "parser.y"
    { 
											backpatch((yyvsp[(1) - (6)].vp).bplist,(yyvsp[(1) - (6)].vp).bpcount,(yyvsp[(5) - (6)].vp).quad);
											(yyval.vp).bpcount=0;
											int i;
											for(i=0;i<(yyvsp[(2) - (6)].vp).bpcount;i++)
											{
												(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(2) - (6)].vp).bplist[i];
											}
											for(i=0;i<(yyvsp[(3) - (6)].vp).bpcount;i++)
											{
												(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(3) - (6)].vp).bplist[i];
											}
											for(i=0;i<(yyvsp[(6) - (6)].vp).bpcount;i++)
											{
												(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(6) - (6)].vp).bplist[i];
											}



										;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 800 "parser.y"
    {
											char printer[1000];
											snprintf(printer,999,"goto _____");
											(yyval.vp).bpcount=0;
											(yyval.vp).bplist[(yyval.vp).bpcount++]=nextquad;
											GenQuad(printer);
										;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 808 "parser.y"
    {(yyval.vp).quad=nextquad;globallevel++;;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 810 "parser.y"
    { 
									backpatch((yyvsp[(3) - (4)].vp).bplist,(yyvsp[(3) - (4)].vp).bpcount,nextquad);
									char printer[1000];
									globallevel ++;
									int temp2=(yyvsp[(3) - (4)].vp).tempreg;
									if(!strcmp((yyvsp[(3) - (4)].vp).type,"float"))
									{
										temp2=newint();
										snprintf(printer,999,"t%d = ConvertToInt(f%d)",temp2,(yyvsp[(3) - (4)].vp).tempreg);
										releasefloat((yyvsp[(3) - (4)].vp).tempreg);
										GenQuad(printer);
									}

									snprintf(printer,999,"if(t%d == 0) goto _____",temp2);
									(yyval.vp).bpcount=0;
									(yyval.vp).bplist[(yyval.vp).bpcount++]=nextquad;
									GenQuad(printer);
									releaseint(temp2);
								;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 834 "parser.y"
    {
										int i;
										int ct = 1;
										for(i=0;i<functable[actfuncindex].varcount;i++)
										{
											if(!strcmp(functable[actfuncindex].vartable[i].vartype,"-1"))
											{
												strcpy(functable[actfuncindex].vartable[i].vartype,(yyvsp[(1) - (3)].vp).type);
												strcpy(types[totvars-ct],(yyvsp[(1) - (3)].vp).type);
												ct--;

											}
										}
									;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 849 "parser.y"
    {strcpy((yyval.vp).type,"int");;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 850 "parser.y"
    {strcpy((yyval.vp).type,"float");;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 861 "parser.y"
    {
				int finder;
				int checker;
				finder = InArr(functable[actfuncindex].paramtable,functable[actfuncindex].paramcount,(yyvsp[(1) - (2)].vp).vali); 
				checker = InArr(functable[actfuncindex].vartable,functable[actfuncindex].varcount,(yyvsp[(1) - (2)].vp).vali);
				if(finder!=-1 && globallevel==2)
				{
					char printer[1000];
					snprintf(printer,999,"Parameter with name %s already exists",(yyvsp[(1) - (2)].vp).vali);
					CallError(printer);
				}
				else if(checker!=-1 && functable[actfuncindex].vartable[checker].level==globallevel)
				{
					char printer[1000];
					snprintf(printer,999,"Variable with name %s already exists in the current scope.",(yyvsp[(1) - (2)].vp).vali);
					CallError(printer);
				}
				else
				{
					strcpy(functable[actfuncindex].vartable[functable[actfuncindex].varcount].varname,(yyvsp[(1) - (2)].vp).vali);
					strcpy(functable[actfuncindex].vartable[functable[actfuncindex].varcount].vartype,"-1");	
					functable[actfuncindex].vartable[functable[actfuncindex].varcount].tag=true;
					functable[actfuncindex].vartable[functable[actfuncindex].varcount].level=globallevel;
					functable[actfuncindex].vartable[functable[actfuncindex].varcount].IsArr=true;

					char finalname[1000];
					snprintf(finalname,999,"%s_%d_%s",(yyvsp[(1) - (2)].vp).vali,globallevel,functable[actfuncindex].name);
					strcpy(vars[totvars],finalname);
					strcpy(types[totvars],functable[actfuncindex].vartable[functable[actfuncindex].varcount].vartype);

					int store = functable[actfuncindex].vartable[functable[actfuncindex].varcount].dimcount;

					functable[actfuncindex].vartable[functable[actfuncindex].varcount].moddim[store-1]=1;
					for(int j=store-2;j>=0;j--)
					{
						functable[actfuncindex].vartable[functable[actfuncindex].varcount].moddim[j] = functable[actfuncindex].vartable[functable[actfuncindex].varcount].moddim[j+1] * functable[actfuncindex].vartable[functable[actfuncindex].varcount].dim[j+1];
					}

					int prod=1;
					int i=0;
					for(i=0;i<functable[actfuncindex].vartable[functable[actfuncindex].varcount].dimcount;i++)
					{
						prod *= functable[actfuncindex].vartable[functable[actfuncindex].varcount].dim[i];
					}
					sizes[totvars]=prod;
					totvars++;



					strcpy(functable[actfuncindex].vartable[functable[actfuncindex].varcount].finalname,finalname);
					functable[actfuncindex].varcount++;
				}	
								;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 915 "parser.y"
    {
									int t = strlen((yyvsp[(3) - (4)].vp).vali);
									int i=0;
									bool isf=false;
									for(i=0;i<t;i++)
									{
										if((yyvsp[(3) - (4)].vp).vali[i]=='.')
										{
										isf=true;
										break;
										}
									}
									bool isn = ((yyvsp[(3) - (4)].vp).vali[0]=='-');
									if(isf)
									{
									CallError("Array dimensions should be an integer");
									}
									if(isn)
									{
									CallError("Array dimensions should be an positive integer");
									}

							functable[actfuncindex].vartable[functable[actfuncindex].varcount].dim[functable[actfuncindex].vartable[functable[actfuncindex].varcount].dimcount++]=stoi((yyvsp[(3) - (4)].vp).vali);
	
								;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 940 "parser.y"
    {
									int t = strlen((yyvsp[(2) - (3)].vp).vali);
									int i=0;
									bool isf=false;
									for(i=0;i<t;i++)
									{
										if((yyvsp[(2) - (3)].vp).vali[i]=='.')
										{
										isf=true;
										break;
										}
									}
									bool isn = ((yyvsp[(2) - (3)].vp).vali[0]=='-');
									if(isf)
									{
									CallError("Array dimensions should be an integer");
									}
									if(isn)
									{
									CallError("Array dimensions should be an positive integer");
									}

							functable[actfuncindex].vartable[functable[actfuncindex].varcount].dimcount=1;
							functable[actfuncindex].vartable[functable[actfuncindex].varcount].dim[0]=stoi((yyvsp[(2) - (3)].vp).vali);

					  ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 968 "parser.y"
    {
				int finder;
				int checker;
				finder = InArr(functable[actfuncindex].paramtable,functable[actfuncindex].paramcount,(yyvsp[(1) - (1)].vp).vali); 
				checker = InArr(functable[actfuncindex].vartable,functable[actfuncindex].varcount,(yyvsp[(1) - (1)].vp).vali);
				if(finder!=-1 && globallevel==2)
				{
					char printer[1000];
					snprintf(printer,999,"Parameter with name %s already exists",(yyvsp[(1) - (1)].vp).vali);
					CallError(printer);
				}
				else if(checker!=-1 && functable[actfuncindex].vartable[checker].level==globallevel)
				{
					char printer[1000];
					snprintf(printer,999,"Variable with name %s already exists in the current scope.",(yyvsp[(1) - (1)].vp).vali);
					CallError(printer);
				}
				else
				{
					struct varrecord new_record;
					strcpy(new_record.varname,(yyvsp[(1) - (1)].vp).vali);
					strcpy(new_record.vartype,"-1");
					new_record.tag=true;
					new_record.level = globallevel;
					new_record.IsArr = false;
					new_record.dimcount = 0;



					char finalname[1000];
					snprintf(finalname,999,"%s_%d_%s",new_record.varname,globallevel,functable[actfuncindex].name);
					strcpy(vars[totvars],finalname);
					strcpy(types[totvars],new_record.vartype);
					sizes[totvars]=0;
					totvars++;

					strcpy(new_record.finalname,finalname);
					functable[actfuncindex].vartable[functable[actfuncindex].varcount++]=new_record;

				}
			;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 1013 "parser.y"
    {
																backpatch((yyvsp[(3) - (3)].vp).bplist,(yyvsp[(3) - (3)].vp).bpcount,nextquad);
								int finder;
								int checker,gchecker;
								finder = InArr(functable[actfuncindex].paramtable,functable[actfuncindex].paramcount,(yyvsp[(1) - (3)].vp).vali); 
								checker = InArr(functable[actfuncindex].vartable,functable[actfuncindex].varcount,(yyvsp[(1) - (3)].vp).vali);
								gchecker = InArr(functable[0].vartable,functable[0].varcount,(yyvsp[(1) - (3)].vp).vali);

								if(checker==-1 && finder==-1 && gchecker==-1)
								{
									char printer[1000];
									snprintf(printer,999,"No such variable called %s exists",(yyvsp[(1) - (3)].vp).vali);
									CallError(printer);
								}
								if(checker!=-1)
									strcpy((yyvsp[(1) - (3)].vp).type,functable[actfuncindex].vartable[checker].vartype);
								else if (finder!=-1)
									strcpy((yyvsp[(1) - (3)].vp).type,functable[actfuncindex].paramtable[finder].vartype);
								else if(gchecker!=-1)
									strcpy((yyvsp[(1) - (3)].vp).type,functable[0].vartable[gchecker].vartype);


								if((yyvsp[(3) - (3)].vp).tempreg==-1)
								{
									CallError("Void function does not return anything.");
								}
								else if((yyvsp[(3) - (3)].vp).tempreg==-2)
								{
									CallError("Some error in assignment.");
								}
								else
								{
									char printer[1000];
									if(!strcmp((yyvsp[(3) - (3)].vp).type,"int"))
									{
										if(!strcmp((yyvsp[(1) - (3)].vp).type,"int"))
										{
											if(checker!=-1)
												snprintf(printer,999,"%s = t%d",functable[actfuncindex].vartable[checker].finalname,(yyvsp[(3) - (3)].vp).tempreg);
											else if(finder!=-1)
												snprintf(printer,999,"%s = t%d",functable[actfuncindex].paramtable[finder].finalname,(yyvsp[(3) - (3)].vp).tempreg);
											else
												snprintf(printer,999,"%s = t%d",functable[0].vartable[gchecker].finalname,(yyvsp[(3) - (3)].vp).tempreg);

											releaseint((yyvsp[(3) - (3)].vp).tempreg);

										}
										else
										{
											int gettemp=newfloat();
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp,(yyvsp[(3) - (3)].vp).tempreg);
											GenQuad(printer);
											releaseint((yyvsp[(3) - (3)].vp).tempreg);
											if(checker!=-1)
												snprintf(printer,999,"%s = f%d",functable[actfuncindex].vartable[checker].finalname,gettemp);
											else if(finder!=-1)
												snprintf(printer,999,"%s = f%d",functable[actfuncindex].paramtable[finder].finalname,gettemp);
											else
												snprintf(printer,999,"%s = f%d",functable[0].vartable[gchecker].finalname,gettemp);

											releasefloat(gettemp);
										}
									}
									if(!strcmp((yyvsp[(3) - (3)].vp).type,"float"))
									{
										if(!strcmp((yyvsp[(1) - (3)].vp).type,"float"))
										{
											if(checker!=-1)
												snprintf(printer,999,"%s = f%d",functable[actfuncindex].vartable[checker].finalname,(yyvsp[(3) - (3)].vp).tempreg);
											else if(finder!=-1)
												snprintf(printer,999,"%s = f%d",functable[actfuncindex].paramtable[finder].finalname,(yyvsp[(3) - (3)].vp).tempreg);
											else
												snprintf(printer,999,"%s = f%d",functable[0].vartable[gchecker].finalname,(yyvsp[(3) - (3)].vp).tempreg);

											releasefloat((yyvsp[(3) - (3)].vp).tempreg);

										}
										else
										{
											int gettemp=newint();
											snprintf(printer,999,"t%d = ConvertToInt(f%d)",gettemp,(yyvsp[(3) - (3)].vp).tempreg);
											GenQuad(printer);
											releasefloat((yyvsp[(3) - (3)].vp).tempreg);
											if(checker!=-1)
												snprintf(printer,999,"%s = t%d",functable[actfuncindex].vartable[checker].finalname,gettemp);
											else if(finder!=-1)
												snprintf(printer,999,"%s = t%d",functable[actfuncindex].paramtable[finder].finalname,gettemp);
											else
												snprintf(printer,999,"%s = t%d",functable[0].vartable[gchecker].finalname,gettemp);

											releaseint(gettemp);

										}										
									}
									GenQuad(printer);
								}

							;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 1111 "parser.y"
    {
								backpatch((yyvsp[(3) - (3)].vp).bplist,(yyvsp[(3) - (3)].vp).bpcount,nextquad);
									if((yyvsp[(1) - (3)].vp).arr!=-1 && (yyvsp[(1) - (3)].vp).ind!=-1)
									{
										if((yyvsp[(3) - (3)].vp).tempreg==-1)
										{
											CallError("Void function does not return anything.");
										}
										else if((yyvsp[(3) - (3)].vp).tempreg==-2)
										{
									CallError("Some error in assignment.");
										
										}
										else
										{
											char printer[1000];
											if(!strcmp((yyvsp[(3) - (3)].vp).type,"int"))
											{
												if(!strcmp((yyvsp[(1) - (3)].vp).type,"int"))
												{
													snprintf(printer,999,"t%d[t%d] = t%d",(yyvsp[(1) - (3)].vp).arr,(yyvsp[(1) - (3)].vp).ind,(yyvsp[(3) - (3)].vp).tempreg);
													releaseint((yyvsp[(3) - (3)].vp).tempreg);

												}
												else
												{
													int gettemp=newfloat();
													snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp,(yyvsp[(3) - (3)].vp).tempreg);
													GenQuad(printer);
													releaseint((yyvsp[(3) - (3)].vp).tempreg);
													
										
													snprintf(printer,999,"t%d[t%d] = f%d",(yyvsp[(1) - (3)].vp).arr,(yyvsp[(1) - (3)].vp).ind,gettemp);

													releasefloat(gettemp);
												}
											}
											if(!strcmp((yyvsp[(3) - (3)].vp).type,"float"))
											{
												if(!strcmp((yyvsp[(1) - (3)].vp).type,"float"))
												{
													
													snprintf(printer,999,"t%d[t%d] = f%d",(yyvsp[(1) - (3)].vp).arr,(yyvsp[(1) - (3)].vp).ind,(yyvsp[(3) - (3)].vp).tempreg);

													releasefloat((yyvsp[(3) - (3)].vp).tempreg);

												}
												else
												{
													int gettemp=newint();
													snprintf(printer,999,"t%d = ConvertToInt(f%d)",gettemp,(yyvsp[(3) - (3)].vp).tempreg);
													GenQuad(printer);
													releasefloat((yyvsp[(3) - (3)].vp).tempreg);
												
													snprintf(printer,999,"t%d[t%d] = t%d",(yyvsp[(1) - (3)].vp).arr,(yyvsp[(1) - (3)].vp).ind,gettemp);

													releaseint(gettemp);

												}										
											}
										GenQuad(printer);
										releaseint((yyvsp[(1) - (3)].vp).arr);
										releaseint((yyvsp[(1) - (3)].vp).ind);
									}
							}
							;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 1178 "parser.y"
    {
																backpatch((yyvsp[(3) - (4)].vp).bplist,(yyvsp[(3) - (4)].vp).bpcount,nextquad);
								int finder;
								int checker,gchecker;
								finder = InArr(functable[actfuncindex].paramtable,functable[actfuncindex].paramcount,(yyvsp[(1) - (4)].vp).vali); 
								checker = InArr(functable[actfuncindex].vartable,functable[actfuncindex].varcount,(yyvsp[(1) - (4)].vp).vali);
								gchecker = InArr(functable[0].vartable,functable[0].varcount,(yyvsp[(1) - (4)].vp).vali);

								if(checker==-1 && finder==-1 && gchecker==-1)
								{
									char printer[1000];
									snprintf(printer,999,"No such variable called %s exists",(yyvsp[(1) - (4)].vp).vali);
									CallError(printer);
								}
								if(checker!=-1)
									strcpy((yyvsp[(1) - (4)].vp).type,functable[actfuncindex].vartable[checker].vartype);
								else if (finder!=-1)
									strcpy((yyvsp[(1) - (4)].vp).type,functable[actfuncindex].paramtable[finder].vartype);
								else if(gchecker!=-1)
									strcpy((yyvsp[(1) - (4)].vp).type,functable[0].vartable[gchecker].vartype);


								if((yyvsp[(3) - (4)].vp).tempreg==-1)
								{
									CallError("Void function does not return anything.");
								}
								else if((yyvsp[(3) - (4)].vp).tempreg==-2)
								{
									CallError("Some error in assignment.");
								}
								else
								{
									char printer[1000];
									if(!strcmp((yyvsp[(3) - (4)].vp).type,"int"))
									{
										if(!strcmp((yyvsp[(1) - (4)].vp).type,"int"))
										{
											if(checker!=-1)
												snprintf(printer,999,"%s = t%d",functable[actfuncindex].vartable[checker].finalname,(yyvsp[(3) - (4)].vp).tempreg);
											else if(finder!=-1)
												snprintf(printer,999,"%s = t%d",functable[actfuncindex].paramtable[finder].finalname,(yyvsp[(3) - (4)].vp).tempreg);
											else
												snprintf(printer,999,"%s = t%d",functable[0].vartable[gchecker].finalname,(yyvsp[(3) - (4)].vp).tempreg);

											releaseint((yyvsp[(3) - (4)].vp).tempreg);

										}
										else
										{
											int gettemp=newfloat();
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp,(yyvsp[(3) - (4)].vp).tempreg);
											GenQuad(printer);
											releaseint((yyvsp[(3) - (4)].vp).tempreg);
											if(checker!=-1)
												snprintf(printer,999,"%s = f%d",functable[actfuncindex].vartable[checker].finalname,gettemp);
											else if(finder!=-1)
												snprintf(printer,999,"%s = f%d",functable[actfuncindex].paramtable[finder].finalname,gettemp);
											else
												snprintf(printer,999,"%s = f%d",functable[0].vartable[gchecker].finalname,gettemp);

											releasefloat(gettemp);
										}
									}
									if(!strcmp((yyvsp[(3) - (4)].vp).type,"float"))
									{
										if(!strcmp((yyvsp[(1) - (4)].vp).type,"float"))
										{
											if(checker!=-1)
												snprintf(printer,999,"%s = f%d",functable[actfuncindex].vartable[checker].finalname,(yyvsp[(3) - (4)].vp).tempreg);
											else if(finder!=-1)
												snprintf(printer,999,"%s = f%d",functable[actfuncindex].paramtable[finder].finalname,(yyvsp[(3) - (4)].vp).tempreg);
											else
												snprintf(printer,999,"%s = f%d",functable[0].vartable[gchecker].finalname,(yyvsp[(3) - (4)].vp).tempreg);

											releasefloat((yyvsp[(3) - (4)].vp).tempreg);

										}
										else
										{
											int gettemp=newint();
											snprintf(printer,999,"t%d = ConvertToInt(f%d)",gettemp,(yyvsp[(3) - (4)].vp).tempreg);
											GenQuad(printer);
											releasefloat((yyvsp[(3) - (4)].vp).tempreg);
											if(checker!=-1)
												snprintf(printer,999,"%s = t%d",functable[actfuncindex].vartable[checker].finalname,gettemp);
											else if(finder!=-1)
												snprintf(printer,999,"%s = t%d",functable[actfuncindex].paramtable[finder].finalname,gettemp);
											else
												snprintf(printer,999,"%s = t%d",functable[0].vartable[gchecker].finalname,gettemp);

											releaseint(gettemp);

										}										
									}
									GenQuad(printer);
								}

							;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 1276 "parser.y"
    {
									backpatch((yyvsp[(3) - (4)].vp).bplist,(yyvsp[(3) - (4)].vp).bpcount,nextquad);
									if((yyvsp[(1) - (4)].vp).arr!=-1 && (yyvsp[(1) - (4)].vp).ind!=-1)
									{
										if((yyvsp[(3) - (4)].vp).tempreg==-1)
										{
											CallError("Void function does not return anything.");
										}
										else if((yyvsp[(3) - (4)].vp).tempreg==-2)
										{
									CallError("Some error in assignment.");
										
										}
										else
										{
											char printer[1000];
											if(!strcmp((yyvsp[(3) - (4)].vp).type,"int"))
											{
												if(!strcmp((yyvsp[(1) - (4)].vp).type,"int"))
												{
													snprintf(printer,999,"t%d[t%d] = t%d",(yyvsp[(1) - (4)].vp).arr,(yyvsp[(1) - (4)].vp).ind,(yyvsp[(3) - (4)].vp).tempreg);
													releaseint((yyvsp[(3) - (4)].vp).tempreg);

												}
												else
												{
													int gettemp=newfloat();
													snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp,(yyvsp[(3) - (4)].vp).tempreg);
													GenQuad(printer);
													releaseint((yyvsp[(3) - (4)].vp).tempreg);
													
										
													snprintf(printer,999,"t%d[t%d] = f%d",(yyvsp[(1) - (4)].vp).arr,(yyvsp[(1) - (4)].vp).ind,gettemp);

													releasefloat(gettemp);
												}
											}
											if(!strcmp((yyvsp[(3) - (4)].vp).type,"float"))
											{
												if(!strcmp((yyvsp[(1) - (4)].vp).type,"float"))
												{
													
													snprintf(printer,999,"t%d[t%d] = f%d",(yyvsp[(1) - (4)].vp).arr,(yyvsp[(1) - (4)].vp).ind,(yyvsp[(3) - (4)].vp).tempreg);

													releasefloat((yyvsp[(3) - (4)].vp).tempreg);

												}
												else
												{
													int gettemp=newint();
													snprintf(printer,999,"t%d = ConvertToInt(f%d)",gettemp,(yyvsp[(3) - (4)].vp).tempreg);
													GenQuad(printer);
													releasefloat((yyvsp[(3) - (4)].vp).tempreg);
												
													snprintf(printer,999,"t%d[t%d] = t%d",(yyvsp[(1) - (4)].vp).arr,(yyvsp[(1) - (4)].vp).ind,gettemp);

													releaseint(gettemp);

												}										
											}
										GenQuad(printer);
										releaseint((yyvsp[(1) - (4)].vp).arr);
										releaseint((yyvsp[(1) - (4)].vp).ind);
									}
							}
							;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 1344 "parser.y"
    {
									backpatch((yyvsp[(3) - (3)].vp).bplist,(yyvsp[(3) - (3)].vp).bpcount,nextquad);
									if((yyvsp[(1) - (3)].vp).countor==0)
									{
										(yyval.vp).countor=1;

										int gettemp;
										gettemp=newint();
										char printer[1000];
										snprintf(printer,999,"t%d = 0 ",gettemp);
										GenQuad(printer);
										int temp2=(yyvsp[(1) - (3)].vp).tempreg;
										if(!strcmp((yyvsp[(1) - (3)].vp).type,"float"))
										{
											temp2=newint();
											snprintf(printer,999,"t%d = ConvertToInt(f%d)",temp2,(yyvsp[(1) - (3)].vp).tempreg);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);
											GenQuad(printer);
										}

										snprintf(printer,999,"if(t%d == 0) goto %d",temp2,nextquad+3);
										GenQuad(printer);
										snprintf(printer,999,"t%d = 1",gettemp);
										GenQuad(printer);
										snprintf(printer,999,"goto _____");
										(yyvsp[(1) - (3)].vp).bpcount=0;
										(yyvsp[(1) - (3)].vp).bplist[(yyvsp[(1) - (3)].vp).bpcount++]=nextquad;
										GenQuad(printer);
										releaseint(temp2);
										releaseint((yyvsp[(1) - (3)].vp).tempreg);
										(yyvsp[(1) - (3)].vp).tempreg=gettemp;
									}
									int getcase = GiveType((yyvsp[(1) - (3)].vp).type,(yyvsp[(3) - (3)].vp).type);
									if(getcase==0)
										strcpy((yyval.vp).type,"errortype");
									else
										strcpy((yyval.vp).type,"int");	
									(yyval.vp).caseallow=(yyvsp[(1) - (3)].vp).caseallow && (yyvsp[(3) - (3)].vp).caseallow;
									

									char printer[1000];
									int temp2=(yyvsp[(3) - (3)].vp).tempreg;
									if(!strcmp((yyvsp[(3) - (3)].vp).type,"float"))
									{
										temp2=newint();
										snprintf(printer,999,"t%d = ConvertToInt(f%d)",temp2,(yyvsp[(3) - (3)].vp).tempreg);
										releasefloat((yyvsp[(3) - (3)].vp).tempreg);
										GenQuad(printer);
									}

									snprintf(printer,999,"if(t%d == 0) goto %d",temp2,nextquad+3);
									GenQuad(printer);
									snprintf(printer,999,"t%d = 1",(yyvsp[(1) - (3)].vp).tempreg);
									GenQuad(printer);
									snprintf(printer,999,"goto _____");
									(yyval.vp).bpcount=0;

									for(int i=0;i<(yyvsp[(1) - (3)].vp).bpcount;i++)
									{
										(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(1) - (3)].vp).bplist[i];
									}
									(yyval.vp).bplist[(yyval.vp).bpcount++]=nextquad;

									GenQuad(printer);
									releaseint(temp2);
									releaseint((yyvsp[(3) - (3)].vp).tempreg);
									(yyval.vp).tempreg=(yyvsp[(1) - (3)].vp).tempreg;

								;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 1413 "parser.y"
    {
									
									backpatch((yyvsp[(1) - (1)].vp).bplist,(yyvsp[(1) - (1)].vp).bpcount,nextquad);
									(yyval.vp).bpcount=0;
									strcpy((yyval.vp).type,(yyvsp[(1) - (1)].vp).type);
									(yyval.vp).caseallow=(yyvsp[(1) - (1)].vp).caseallow;
									(yyval.vp).tempreg=(yyvsp[(1) - (1)].vp).tempreg;
									(yyval.vp).countor=0;


								;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 1425 "parser.y"
    {
									if((yyvsp[(1) - (3)].vp).countand==0)
									{
										(yyval.vp).countand=1;
										int gettemp;
										gettemp=newint();
										char printer[1000];
										snprintf(printer,999,"t%d = 1 ",gettemp);
										GenQuad(printer);

										int temp2=(yyvsp[(1) - (3)].vp).tempreg;
										if(!strcmp((yyvsp[(1) - (3)].vp).type,"float"))
										{
											temp2=newint();
											snprintf(printer,999,"t%d = ConvertToInt(f%d)",temp2,(yyvsp[(1) - (3)].vp).tempreg);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);
											GenQuad(printer);
										}


										snprintf(printer,999,"if(t%d != 0) goto %d",temp2,nextquad+3);
										GenQuad(printer);
										snprintf(printer,999,"t%d = 0",gettemp);
										GenQuad(printer);
										snprintf(printer,999,"goto _____");
										
										(yyvsp[(1) - (3)].vp).bpcount=0;
										(yyvsp[(1) - (3)].vp).bplist[(yyvsp[(1) - (3)].vp).bpcount++]=nextquad;
										GenQuad(printer);
										releaseint(temp2);
										releaseint((yyvsp[(1) - (3)].vp).tempreg);
										(yyvsp[(1) - (3)].vp).tempreg=gettemp;
									}
									int getcase = GiveType((yyvsp[(1) - (3)].vp).type,(yyvsp[(3) - (3)].vp).type);
									if(getcase==0)
										strcpy((yyval.vp).type,"errortype");
									else
										strcpy((yyval.vp).type,"int");
									(yyval.vp).caseallow=(yyvsp[(1) - (3)].vp).caseallow && (yyvsp[(3) - (3)].vp).caseallow;

									char printer[1000];
									int temp2=(yyvsp[(3) - (3)].vp).tempreg;
									if(!strcmp((yyvsp[(3) - (3)].vp).type,"float"))
									{
										temp2=newint();
										snprintf(printer,999,"t%d = ConvertToInt(f%d)",temp2,(yyvsp[(3) - (3)].vp).tempreg);
										releasefloat((yyvsp[(3) - (3)].vp).tempreg);
										GenQuad(printer);
									}

									snprintf(printer,999,"if(t%d != 0) goto %d",temp2,nextquad+3);
									GenQuad(printer);
									snprintf(printer,999,"t%d = 0",(yyvsp[(1) - (3)].vp).tempreg);
									GenQuad(printer);
									snprintf(printer,999,"goto _____");
									(yyval.vp).bpcount=0;
									for(int i=0;i<(yyvsp[(1) - (3)].vp).bpcount;i++)
									{
										(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(1) - (3)].vp).bplist[i];
									}
									(yyval.vp).bplist[(yyval.vp).bpcount++]=nextquad;

									GenQuad(printer);
									releaseint(temp2);
									releaseint((yyvsp[(3) - (3)].vp).tempreg);
									(yyval.vp).tempreg=(yyvsp[(1) - (3)].vp).tempreg;

									

								;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 1495 "parser.y"
    {
									(yyval.vp).bpcount=0;
									strcpy((yyval.vp).type,(yyvsp[(1) - (1)].vp).type);
									(yyval.vp).caseallow=(yyvsp[(1) - (1)].vp).caseallow;
									(yyval.vp).tempreg=(yyvsp[(1) - (1)].vp).tempreg;
									(yyval.vp).countand=0;


								;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 1505 "parser.y"
    {
									strcpy((yyval.vp).type,(yyvsp[(1) - (1)].vp).type);
									(yyval.vp).caseallow=(yyvsp[(1) - (1)].vp).caseallow;
									(yyval.vp).tempreg=(yyvsp[(1) - (1)].vp).tempreg;

								
								;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 1512 "parser.y"
    {
									if(!strcmp((yyvsp[(1) - (2)].vp).type,"errortype"))
									strcpy((yyval.vp).type,"errortype");
									else
									strcpy((yyval.vp).type,"int");
									(yyval.vp).caseallow=(yyvsp[(2) - (2)].vp).caseallow;

									int gettemp;
									gettemp=newint();
									char printer[1000];
									snprintf(printer,999,"t%d = 1 ",gettemp);
									GenQuad(printer);
									int temp2=(yyvsp[(2) - (2)].vp).tempreg;
									if(!strcmp((yyvsp[(2) - (2)].vp).type,"float"))
									{
										temp2=newint();
										snprintf(printer,999,"t%d = ConvertToInt(f%d)",temp2,(yyvsp[(2) - (2)].vp).tempreg);
										releasefloat((yyvsp[(2) - (2)].vp).tempreg);
										GenQuad(printer);
									}

									snprintf(printer,999,"if(t%d == 0) goto %d",temp2,nextquad+2);
									GenQuad(printer);
									snprintf(printer,999,"t%d = 0",gettemp);
									GenQuad(printer);
									releaseint(temp2);
									releaseint((yyvsp[(2) - (2)].vp).tempreg);
									(yyval.vp).tempreg=gettemp;
								;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 1542 "parser.y"
    {
									int getcase = GiveType((yyvsp[(1) - (3)].vp).type,(yyvsp[(3) - (3)].vp).type);
									if(getcase==0)
										strcpy((yyval.vp).type,"errortype");
									else
										strcpy((yyval.vp).type,"int");
									(yyval.vp).caseallow=(yyvsp[(1) - (3)].vp).caseallow && (yyvsp[(3) - (3)].vp).caseallow;
									int gettemp;
									if(getcase==1)
									{
										if(!strcmp((yyvsp[(1) - (3)].vp).type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,(yyvsp[(1) - (3)].vp).tempreg);
											GenQuad(printer);
											releaseint((yyvsp[(1) - (3)].vp).tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d < f%d) goto %d",gettemp2,(yyvsp[(3) - (3)].vp).tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat((yyvsp[(3) - (3)].vp).tempreg);
										}
										else if(!strcmp((yyvsp[(3) - (3)].vp).type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,(yyvsp[(3) - (3)].vp).tempreg);
											GenQuad(printer);
											releaseint((yyvsp[(3) - (3)].vp).tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d < f%d) goto %d",(yyvsp[(1) - (3)].vp).tempreg,gettemp2,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);
										}
										else
										{
											char printer[1000];
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d < f%d) goto %d",(yyvsp[(1) - (3)].vp).tempreg,(yyvsp[(3) - (3)].vp).tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);
											releasefloat((yyvsp[(3) - (3)].vp).tempreg);
										}
										
									
									}

									else if(getcase==2)
									{
											gettemp = newint();
											char printer[1000];
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(t%d < t%d) goto %d",(yyvsp[(1) - (3)].vp).tempreg,(yyvsp[(3) - (3)].vp).tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releaseint((yyvsp[(3) - (3)].vp).tempreg);
											releaseint((yyvsp[(1) - (3)].vp).tempreg);
									}
									(yyval.vp).tempreg=gettemp;
								;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 1624 "parser.y"
    {
									int getcase = GiveType((yyvsp[(1) - (3)].vp).type,(yyvsp[(3) - (3)].vp).type);
									if(getcase==0)
										strcpy((yyval.vp).type,"errortype");
									else
										strcpy((yyval.vp).type,"int");
									(yyval.vp).caseallow=(yyvsp[(1) - (3)].vp).caseallow && (yyvsp[(3) - (3)].vp).caseallow;

									int gettemp;
									if(getcase==1)
									{
										if(!strcmp((yyvsp[(1) - (3)].vp).type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,(yyvsp[(1) - (3)].vp).tempreg);
											GenQuad(printer);
											releaseint((yyvsp[(1) - (3)].vp).tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d <= f%d) goto %d",gettemp2,(yyvsp[(3) - (3)].vp).tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat((yyvsp[(3) - (3)].vp).tempreg);
										}
										else if(!strcmp((yyvsp[(3) - (3)].vp).type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,(yyvsp[(3) - (3)].vp).tempreg);
											GenQuad(printer);
											releaseint((yyvsp[(3) - (3)].vp).tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d <= f%d) goto %d",(yyvsp[(1) - (3)].vp).tempreg,gettemp2,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);
										}
										else
										{
											char printer[1000];
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d <= f%d) goto %d",(yyvsp[(1) - (3)].vp).tempreg,(yyvsp[(3) - (3)].vp).tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);
											releasefloat((yyvsp[(3) - (3)].vp).tempreg);
										}
										
									
									}

									else if(getcase==2)
									{
											gettemp = newint();
											char printer[1000];
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(t%d <= t%d) goto %d",(yyvsp[(1) - (3)].vp).tempreg,(yyvsp[(3) - (3)].vp).tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releaseint((yyvsp[(3) - (3)].vp).tempreg);
											releaseint((yyvsp[(1) - (3)].vp).tempreg);
									}
									(yyval.vp).tempreg=gettemp;
								
								;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 1708 "parser.y"
    {
									int getcase = GiveType((yyvsp[(1) - (3)].vp).type,(yyvsp[(3) - (3)].vp).type);
									if(getcase==0)
										strcpy((yyval.vp).type,"errortype");
									else
										strcpy((yyval.vp).type,"int");
									(yyval.vp).caseallow=(yyvsp[(1) - (3)].vp).caseallow && (yyvsp[(3) - (3)].vp).caseallow;

									int gettemp;
									if(getcase==1)
									{
										if(!strcmp((yyvsp[(1) - (3)].vp).type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,(yyvsp[(1) - (3)].vp).tempreg);
											GenQuad(printer);
											releaseint((yyvsp[(1) - (3)].vp).tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d > f%d) goto %d",gettemp2,(yyvsp[(3) - (3)].vp).tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat((yyvsp[(3) - (3)].vp).tempreg);
										}
										else if(!strcmp((yyvsp[(3) - (3)].vp).type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,(yyvsp[(3) - (3)].vp).tempreg);
											GenQuad(printer);
											releaseint((yyvsp[(3) - (3)].vp).tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d > f%d) goto %d",(yyvsp[(1) - (3)].vp).tempreg,gettemp2,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);
										}
										else
										{
											char printer[1000];
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d > f%d) goto %d",(yyvsp[(1) - (3)].vp).tempreg,(yyvsp[(3) - (3)].vp).tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);
											releasefloat((yyvsp[(3) - (3)].vp).tempreg);
										}

										
									
									}

									else if(getcase==2)
									{
											gettemp = newint();
											char printer[1000];
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(t%d > t%d) goto %d",(yyvsp[(1) - (3)].vp).tempreg,(yyvsp[(3) - (3)].vp).tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releaseint((yyvsp[(3) - (3)].vp).tempreg);
											releaseint((yyvsp[(1) - (3)].vp).tempreg);
									}
									(yyval.vp).tempreg=gettemp;
								
								;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 1793 "parser.y"
    {
									int getcase = GiveType((yyvsp[(1) - (3)].vp).type,(yyvsp[(3) - (3)].vp).type);
									if(getcase==0)
										strcpy((yyval.vp).type,"errortype");
									else
										strcpy((yyval.vp).type,"int");
									(yyval.vp).caseallow=(yyvsp[(1) - (3)].vp).caseallow && (yyvsp[(3) - (3)].vp).caseallow;

									int gettemp;
									if(getcase==1)
									{
										if(!strcmp((yyvsp[(1) - (3)].vp).type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,(yyvsp[(1) - (3)].vp).tempreg);
											GenQuad(printer);
											releaseint((yyvsp[(1) - (3)].vp).tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d >= f%d) goto %d",gettemp2,(yyvsp[(3) - (3)].vp).tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat((yyvsp[(3) - (3)].vp).tempreg);
										}
										else if(!strcmp((yyvsp[(3) - (3)].vp).type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,(yyvsp[(3) - (3)].vp).tempreg);
											GenQuad(printer);
											releaseint((yyvsp[(3) - (3)].vp).tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d >= f%d) goto %d",(yyvsp[(1) - (3)].vp).tempreg,gettemp2,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);
										}
										else
										{
											char printer[1000];
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d >= f%d) goto %d",(yyvsp[(1) - (3)].vp).tempreg,(yyvsp[(3) - (3)].vp).tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);
											releasefloat((yyvsp[(3) - (3)].vp).tempreg);
										}
										
									
									}

									else if(getcase==2)
									{
											gettemp = newint();
											char printer[1000];
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(t%d >= t%d) goto %d",(yyvsp[(1) - (3)].vp).tempreg,(yyvsp[(3) - (3)].vp).tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releaseint((yyvsp[(3) - (3)].vp).tempreg);
											releaseint((yyvsp[(1) - (3)].vp).tempreg);
									}
									(yyval.vp).tempreg=gettemp;
								
								;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1877 "parser.y"
    {
									int getcase = GiveType((yyvsp[(1) - (3)].vp).type,(yyvsp[(3) - (3)].vp).type);
									if(getcase==0)
										strcpy((yyval.vp).type,"errortype");
									else
										strcpy((yyval.vp).type,"int");
									(yyval.vp).caseallow=(yyvsp[(1) - (3)].vp).caseallow && (yyvsp[(3) - (3)].vp).caseallow;

									int gettemp;
									if(getcase==1)
									{
										if(!strcmp((yyvsp[(1) - (3)].vp).type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,(yyvsp[(1) - (3)].vp).tempreg);
											GenQuad(printer);
											releaseint((yyvsp[(1) - (3)].vp).tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d != f%d) goto %d",gettemp2,(yyvsp[(3) - (3)].vp).tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat((yyvsp[(3) - (3)].vp).tempreg);
										}
										else if(!strcmp((yyvsp[(3) - (3)].vp).type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,(yyvsp[(3) - (3)].vp).tempreg);
											GenQuad(printer);
											releaseint((yyvsp[(3) - (3)].vp).tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d != f%d) goto %d",(yyvsp[(1) - (3)].vp).tempreg,gettemp2,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);
										}
										else
										{
											char printer[1000];
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d != f%d) goto %d",(yyvsp[(1) - (3)].vp).tempreg,(yyvsp[(3) - (3)].vp).tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);
											releasefloat((yyvsp[(3) - (3)].vp).tempreg);
										}
										
									
									}

									else if(getcase==2)
									{
											gettemp = newint();
											char printer[1000];
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(t%d != t%d) goto %d",(yyvsp[(1) - (3)].vp).tempreg,(yyvsp[(3) - (3)].vp).tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releaseint((yyvsp[(3) - (3)].vp).tempreg);
											releaseint((yyvsp[(1) - (3)].vp).tempreg);
									}
									(yyval.vp).tempreg=gettemp;

								;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 1961 "parser.y"
    {
									int getcase = GiveType((yyvsp[(1) - (3)].vp).type,(yyvsp[(3) - (3)].vp).type);
									if(getcase==0)
										strcpy((yyval.vp).type,"errortype");
									else
										strcpy((yyval.vp).type,"int");
									(yyval.vp).caseallow=(yyvsp[(1) - (3)].vp).caseallow && (yyvsp[(3) - (3)].vp).caseallow;

									int gettemp;
									if(getcase==1)
									{
										if(!strcmp((yyvsp[(1) - (3)].vp).type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,(yyvsp[(1) - (3)].vp).tempreg);
											GenQuad(printer);
											releaseint((yyvsp[(1) - (3)].vp).tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d == f%d) goto %d",gettemp2,(yyvsp[(3) - (3)].vp).tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat((yyvsp[(3) - (3)].vp).tempreg);
										}
										else if(!strcmp((yyvsp[(3) - (3)].vp).type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,(yyvsp[(3) - (3)].vp).tempreg);
											GenQuad(printer);
											releaseint((yyvsp[(3) - (3)].vp).tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d == f%d) goto %d",(yyvsp[(1) - (3)].vp).tempreg,gettemp2,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);
										}
										else
										{
											char printer[1000];
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d == f%d) goto %d",(yyvsp[(1) - (3)].vp).tempreg,(yyvsp[(3) - (3)].vp).tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);
											releasefloat((yyvsp[(3) - (3)].vp).tempreg);
										}
										
									
									}

									else if(getcase==2)
									{
											gettemp = newint();
											char printer[1000];
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(t%d == t%d) goto %d",(yyvsp[(1) - (3)].vp).tempreg,(yyvsp[(3) - (3)].vp).tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releaseint((yyvsp[(3) - (3)].vp).tempreg);
											releaseint((yyvsp[(1) - (3)].vp).tempreg);
									}
									(yyval.vp).tempreg=gettemp;

								;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 2045 "parser.y"
    {
									strcpy((yyval.vp).type,(yyvsp[(1) - (1)].vp).type);
									(yyval.vp).tempreg=(yyvsp[(1) - (1)].vp).tempreg;
									(yyval.vp).caseallow=(yyvsp[(1) - (1)].vp).caseallow;

								;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 2052 "parser.y"
    {
									int gettemp;
									
									int getcase = GiveType((yyvsp[(1) - (3)].vp).type,(yyvsp[(3) - (3)].vp).type);
									if(getcase==0)
										strcpy((yyval.vp).type,"errortype");
									if(getcase==1){
										strcpy((yyval.vp).type,"float");
										if(!strcmp((yyvsp[(1) - (3)].vp).type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
									
											
									
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,(yyvsp[(1) - (3)].vp).tempreg);
											

											GenQuad(printer);
											
											releaseint((yyvsp[(1) - (3)].vp).tempreg);

											gettemp = newfloat();
											snprintf(printer,999,"f%d = f%d + f%d",gettemp,gettemp2,(yyvsp[(3) - (3)].vp).tempreg);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat((yyvsp[(3) - (3)].vp).tempreg);



										}
										else if(!strcmp((yyvsp[(3) - (3)].vp).type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,(yyvsp[(3) - (3)].vp).tempreg);
											GenQuad(printer);
											releaseint((yyvsp[(3) - (3)].vp).tempreg);

											gettemp = newfloat();

											snprintf(printer,999,"f%d = f%d + f%d",gettemp,(yyvsp[(1) - (3)].vp).tempreg,gettemp2);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);

										}
										else
										{
											gettemp=newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = f%d + f%d",gettemp,(yyvsp[(1) - (3)].vp).tempreg,(yyvsp[(3) - (3)].vp).tempreg);
											GenQuad(printer);
											releasefloat((yyvsp[(3) - (3)].vp).tempreg);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);
										}
									}
									if(getcase==2){
										strcpy((yyval.vp).type,"int");
										gettemp = newint();
										char printer[1000];

										snprintf(printer,999,"t%d = t%d + t%d",gettemp,(yyvsp[(1) - (3)].vp).tempreg,(yyvsp[(3) - (3)].vp).tempreg);
										GenQuad(printer);
										releaseint((yyvsp[(3) - (3)].vp).tempreg);
										releaseint((yyvsp[(1) - (3)].vp).tempreg);

									}
									(yyval.vp).tempreg = gettemp;
									(yyval.vp).caseallow=(yyvsp[(1) - (3)].vp).caseallow && (yyvsp[(3) - (3)].vp).caseallow;


								;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 2127 "parser.y"
    {
									int gettemp;
									
									int getcase = GiveType((yyvsp[(1) - (3)].vp).type,(yyvsp[(3) - (3)].vp).type);
									if(getcase==0)
										strcpy((yyval.vp).type,"errortype");
									if(getcase==1){
										strcpy((yyval.vp).type,"float");
										if(!strcmp((yyvsp[(1) - (3)].vp).type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
									
											
									
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,(yyvsp[(1) - (3)].vp).tempreg);
											

											GenQuad(printer);
											
											releaseint((yyvsp[(1) - (3)].vp).tempreg);

											gettemp = newfloat();
											snprintf(printer,999,"f%d = f%d - f%d",gettemp,gettemp2,(yyvsp[(3) - (3)].vp).tempreg);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat((yyvsp[(3) - (3)].vp).tempreg);



										}
										else if(!strcmp((yyvsp[(3) - (3)].vp).type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,(yyvsp[(3) - (3)].vp).tempreg);
											GenQuad(printer);
											releaseint((yyvsp[(3) - (3)].vp).tempreg);

											gettemp = newfloat();

											snprintf(printer,999,"f%d = f%d - f%d",gettemp,(yyvsp[(1) - (3)].vp).tempreg,gettemp2);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);

										}
										else
										{
											gettemp=newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = f%d - f%d",gettemp,(yyvsp[(1) - (3)].vp).tempreg,(yyvsp[(3) - (3)].vp).tempreg);
											GenQuad(printer);
											releasefloat((yyvsp[(3) - (3)].vp).tempreg);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);
										}
									}
									if(getcase==2){
										strcpy((yyval.vp).type,"int");
										gettemp = newint();
										char printer[1000];

										snprintf(printer,999,"t%d = t%d - t%d",gettemp,(yyvsp[(1) - (3)].vp).tempreg,(yyvsp[(3) - (3)].vp).tempreg);
										GenQuad(printer);
										releaseint((yyvsp[(3) - (3)].vp).tempreg);
										releaseint((yyvsp[(1) - (3)].vp).tempreg);

									}
									(yyval.vp).tempreg = gettemp;
									(yyval.vp).caseallow=(yyvsp[(1) - (3)].vp).caseallow && (yyvsp[(3) - (3)].vp).caseallow;


								;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 2202 "parser.y"
    {
									strcpy((yyval.vp).type,(yyvsp[(1) - (1)].vp).type);
									(yyval.vp).tempreg=(yyvsp[(1) - (1)].vp).tempreg;
									(yyval.vp).caseallow=(yyvsp[(1) - (1)].vp).caseallow;

								;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 2209 "parser.y"
    {
									int gettemp;
									
									int getcase = GiveType((yyvsp[(1) - (3)].vp).type,(yyvsp[(3) - (3)].vp).type);
									if(getcase==0)
										strcpy((yyval.vp).type,"errortype");
									if(getcase==1){
										strcpy((yyval.vp).type,"float");
										if(!strcmp((yyvsp[(1) - (3)].vp).type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
									
											
									
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,(yyvsp[(1) - (3)].vp).tempreg);
											

											GenQuad(printer);
											
											releaseint((yyvsp[(1) - (3)].vp).tempreg);

											gettemp = newfloat();
											snprintf(printer,999,"f%d = f%d * f%d",gettemp,gettemp2,(yyvsp[(3) - (3)].vp).tempreg);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat((yyvsp[(3) - (3)].vp).tempreg);



										}
										else if(!strcmp((yyvsp[(3) - (3)].vp).type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,(yyvsp[(3) - (3)].vp).tempreg);
											GenQuad(printer);
											releaseint((yyvsp[(3) - (3)].vp).tempreg);

											gettemp = newfloat();

											snprintf(printer,999,"f%d = f%d * f%d",gettemp,(yyvsp[(1) - (3)].vp).tempreg,gettemp2);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);

										}
										else
										{
											gettemp=newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = f%d * f%d",gettemp,(yyvsp[(1) - (3)].vp).tempreg,(yyvsp[(3) - (3)].vp).tempreg);
											GenQuad(printer);
											releasefloat((yyvsp[(3) - (3)].vp).tempreg);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);
										}
									}
									if(getcase==2){
										strcpy((yyval.vp).type,"int");
										gettemp = newint();
										char printer[1000];

										snprintf(printer,999,"t%d = t%d * t%d",gettemp,(yyvsp[(1) - (3)].vp).tempreg,(yyvsp[(3) - (3)].vp).tempreg);
										GenQuad(printer);
										releaseint((yyvsp[(3) - (3)].vp).tempreg);
										releaseint((yyvsp[(1) - (3)].vp).tempreg);

									}
									(yyval.vp).tempreg = gettemp;
									(yyval.vp).caseallow=(yyvsp[(1) - (3)].vp).caseallow && (yyvsp[(3) - (3)].vp).caseallow;

									



								;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 2287 "parser.y"
    {
									int gettemp;
									
									int getcase = GiveType((yyvsp[(1) - (3)].vp).type,(yyvsp[(3) - (3)].vp).type);
									if(getcase==0)
										strcpy((yyval.vp).type,"errortype");
									if(getcase==1){
										strcpy((yyval.vp).type,"float");
										if(!strcmp((yyvsp[(1) - (3)].vp).type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
									
											
									
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,(yyvsp[(1) - (3)].vp).tempreg);
											

											GenQuad(printer);
											
											releaseint((yyvsp[(1) - (3)].vp).tempreg);

											gettemp = newfloat();
											snprintf(printer,999,"f%d = f%d / f%d",gettemp,gettemp2,(yyvsp[(3) - (3)].vp).tempreg);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat((yyvsp[(3) - (3)].vp).tempreg);



										}
										else if(!strcmp((yyvsp[(3) - (3)].vp).type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,(yyvsp[(3) - (3)].vp).tempreg);
											GenQuad(printer);
											releaseint((yyvsp[(3) - (3)].vp).tempreg);

											gettemp = newfloat();

											snprintf(printer,999,"f%d = f%d / f%d",gettemp,(yyvsp[(1) - (3)].vp).tempreg,gettemp2);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);

										}
										else
										{
											gettemp=newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = f%d / f%d",gettemp,(yyvsp[(1) - (3)].vp).tempreg,(yyvsp[(3) - (3)].vp).tempreg);
											GenQuad(printer);
											releasefloat((yyvsp[(3) - (3)].vp).tempreg);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);
										}
									}
									if(getcase==2){
										strcpy((yyval.vp).type,"int");
										gettemp = newint();
										char printer[1000];

										snprintf(printer,999,"t%d = t%d / t%d",gettemp,(yyvsp[(1) - (3)].vp).tempreg,(yyvsp[(3) - (3)].vp).tempreg);
										GenQuad(printer);
										releaseint((yyvsp[(3) - (3)].vp).tempreg);
										releaseint((yyvsp[(1) - (3)].vp).tempreg);

									}
									(yyval.vp).tempreg = gettemp;
									(yyval.vp).caseallow=(yyvsp[(1) - (3)].vp).caseallow && (yyvsp[(3) - (3)].vp).caseallow;


								;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 2362 "parser.y"
    {
									int gettemp;
									
									int getcase = GiveType((yyvsp[(1) - (3)].vp).type,(yyvsp[(3) - (3)].vp).type);
									if(getcase==0)
										strcpy((yyval.vp).type,"errortype");
									if(getcase==1){
										strcpy((yyval.vp).type,"float");
										if(!strcmp((yyvsp[(1) - (3)].vp).type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
									
											
									
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,(yyvsp[(1) - (3)].vp).tempreg);
											

											GenQuad(printer);
											
											releaseint((yyvsp[(1) - (3)].vp).tempreg);

											gettemp = newfloat();
											snprintf(printer,999,"f%d = f%d %% f%d",gettemp,gettemp2,(yyvsp[(3) - (3)].vp).tempreg);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat((yyvsp[(3) - (3)].vp).tempreg);



										}
										else if(!strcmp((yyvsp[(3) - (3)].vp).type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,(yyvsp[(3) - (3)].vp).tempreg);
											GenQuad(printer);
											releaseint((yyvsp[(3) - (3)].vp).tempreg);

											gettemp = newfloat();

											snprintf(printer,999,"f%d = f%d %% f%d",gettemp,(yyvsp[(1) - (3)].vp).tempreg,gettemp2);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);

										}
										else
										{
											gettemp=newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = f%d %% f%d",gettemp,(yyvsp[(1) - (3)].vp).tempreg,(yyvsp[(3) - (3)].vp).tempreg);
											GenQuad(printer);
											releasefloat((yyvsp[(3) - (3)].vp).tempreg);
											releasefloat((yyvsp[(1) - (3)].vp).tempreg);
										}
									}
									if(getcase==2){
										strcpy((yyval.vp).type,"int");
										gettemp = newint();
										char printer[1000];

										snprintf(printer,999,"t%d = t%d %% t%d",gettemp,(yyvsp[(1) - (3)].vp).tempreg,(yyvsp[(3) - (3)].vp).tempreg);
										GenQuad(printer);
										releaseint((yyvsp[(3) - (3)].vp).tempreg);
										releaseint((yyvsp[(1) - (3)].vp).tempreg);

									}
									(yyval.vp).tempreg = gettemp;
									(yyval.vp).caseallow=(yyvsp[(1) - (3)].vp).caseallow && (yyvsp[(3) - (3)].vp).caseallow;

								;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 2437 "parser.y"
    {
									strcpy((yyval.vp).type,(yyvsp[(1) - (1)].vp).type);
									(yyval.vp).tempreg=(yyvsp[(1) - (1)].vp).tempreg;
									(yyval.vp).caseallow=(yyvsp[(1) - (1)].vp).caseallow;


								;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 2445 "parser.y"
    {
									int find = InArr(functable[actfuncindex].vartable,functable[actfuncindex].varcount,(yyvsp[(1) - (1)].vp).vali);
									int pfind = InArr(functable[actfuncindex].paramtable,functable[actfuncindex].paramcount,(yyvsp[(1) - (1)].vp).vali);
									int gfind = InArr(functable[0].vartable,functable[0].varcount,(yyvsp[(1) - (1)].vp).vali);

									if(find==-1 && pfind==-1 && gfind==-1)
									{
										char printer1[1000];
										snprintf(printer1,999,"No such variable called %s exists",(yyvsp[(1) - (1)].vp).vali);
										CallError(printer1);
										strcpy((yyval.vp).type,"errortype");

									}
									else
									{
										if(find!=-1 && functable[actfuncindex].vartable[find].dimcount>0)
										{
											CallError("Arrays can't be used directly like this.");
										}

										int gettemp;

										if(find!=-1)
										{
											strcpy((yyval.vp).type,functable[actfuncindex].vartable[find].vartype);

												if(!strcmp((yyval.vp).type,"int"))
												{
													gettemp = newint();

													char printer[1000];
													snprintf(printer,999,"t%d = %s",gettemp,functable[actfuncindex].vartable[find].finalname);

													GenQuad(printer);
												}
												else
												{
													gettemp = newfloat();

													char printer[1000];
													snprintf(printer,999,"f%d = %s",gettemp,functable[actfuncindex].vartable[find].finalname);
													GenQuad(printer);
												}

										}
										else if(pfind!=-1)
										{
											strcpy((yyval.vp).type,functable[actfuncindex].paramtable[pfind].vartype);

												if(!strcmp((yyval.vp).type,"int"))
												{
													gettemp = newint();

													char printer[1000];
													snprintf(printer,999,"t%d = %s",gettemp,functable[actfuncindex].paramtable[pfind].finalname);
													GenQuad(printer);

			
												}
												else
												{
													gettemp = newfloat();
													char printer[1000];
													snprintf(printer,999,"f%d = %s",gettemp,functable[actfuncindex].paramtable[pfind].finalname);
													GenQuad(printer);
													
												}
										}
										else if(gfind!=-1)
										{
											if(gfind!=-1 && functable[0].vartable[gfind].dimcount>0)
											{
												CallError("Arrays can't be used directly like this.");
											}
											strcpy((yyval.vp).type,functable[0].vartable[gfind].vartype);

												if(!strcmp((yyval.vp).type,"int"))
												{
													gettemp = newint();

													char printer[1000];
													snprintf(printer,999,"t%d = %s",gettemp,functable[0].vartable[gfind].finalname);

													GenQuad(printer);
												}
												else
												{
													gettemp = newfloat();

													char printer[1000];
													snprintf(printer,999,"f%d = %s",gettemp,functable[0].vartable[gfind].finalname);
													GenQuad(printer);
												}
										}
										(yyval.vp).tempreg=gettemp;

									}
									(yyval.vp).caseallow=false;
								;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 2545 "parser.y"
    {
									int gettemp;
									int t = strlen((yyvsp[(1) - (1)].vp).vali);
									int i=0;
									bool isf=false;
									for(i=0;i<t;i++)
									{
										if((yyvsp[(1) - (1)].vp).vali[i]=='.')
										{
										isf=true;
										break;
										}
									}
									if(isf)
									{
										strcpy((yyval.vp).type,"float");

										gettemp = newfloat();
										char printer[1000];
										snprintf(printer,999,"f%d = %s",gettemp,(yyvsp[(1) - (1)].vp).vali);
										GenQuad(printer);

										
									}
									else
									{
										strcpy((yyval.vp).type,"int");
										gettemp = newint();

										char printer[1000];
										snprintf(printer,999,"t%d = %s",gettemp,(yyvsp[(1) - (1)].vp).vali);
										GenQuad(printer);
									}
									(yyval.vp).tempreg=gettemp;

									(yyval.vp).caseallow=true;



								;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 2585 "parser.y"
    {
									strcpy((yyval.vp).type,(yyvsp[(1) - (1)].vp).type);
									(yyval.vp).tempreg=(yyvsp[(1) - (1)].vp).tempreg;

									if((yyval.vp).tempreg==-1)
									{
										CallError("Void Function does not return anything.");
									}
									(yyval.vp).caseallow=false;



								;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 2598 "parser.y"
    {
									strcpy((yyval.vp).type,(yyvsp[(2) - (3)].vp).type);
									(yyval.vp).tempreg=(yyvsp[(2) - (3)].vp).tempreg;

									(yyval.vp).caseallow=(yyvsp[(2) - (3)].vp).caseallow;
									backpatch((yyvsp[(2) - (3)].vp).bplist,(yyvsp[(2) - (3)].vp).bpcount,nextquad);


								;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 2607 "parser.y"
    {
									int tempreg=-2;
									char printer[1000];

									if((yyvsp[(1) - (1)].vp).arr!=-1 && (yyvsp[(1) - (1)].vp).ind!=-1)
									{
										if(!strcmp((yyvsp[(1) - (1)].vp).type,"int"))
										{
											tempreg = newint();
											snprintf(printer,999,"t%d = t%d[t%d]",tempreg,(yyvsp[(1) - (1)].vp).arr,(yyvsp[(1) - (1)].vp).ind);
											GenQuad(printer);
											releaseint((yyvsp[(1) - (1)].vp).arr);
											releaseint((yyvsp[(1) - (1)].vp).ind);
										}
										else if(!strcmp((yyvsp[(1) - (1)].vp).type,"float"))
										{
											tempreg = newfloat();
											snprintf(printer,999,"f%d = t%d[t%d]",tempreg,(yyvsp[(1) - (1)].vp).arr,(yyvsp[(1) - (1)].vp).ind);
											GenQuad(printer);
											releaseint((yyvsp[(1) - (1)].vp).arr);
											releaseint((yyvsp[(1) - (1)].vp).ind);
										}
									}
									strcpy((yyval.vp).type,(yyvsp[(1) - (1)].vp).type);
									(yyval.vp).tempreg=tempreg;
									(yyval.vp).caseallow=false;

								;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 2638 "parser.y"
    {
									(yyval.vp).arr=-1;
									(yyval.vp).ind=-1;
									strcpy((yyval.vp).type,"errortype");


									int find = InArr(functable[actfuncindex].vartable,functable[actfuncindex].varcount,(yyvsp[(1) - (2)].vp).vali);
									int gfind = InArr(functable[0].vartable,functable[0].varcount,(yyvsp[(1) - (2)].vp).vali);

									if(find==-1 && gfind==-1)
									{
										char printer1[1000];
										snprintf(printer1,999,"No such variable called %s exists",(yyvsp[(1) - (2)].vp).vali);
										CallError(printer1);
										strcpy((yyval.vp).type,"errortype");

									}
									else if(find!=-1)
									{
										if(find!=-1 && functable[actfuncindex].vartable[find].dimcount==0)
										{
											CallError("Such indexing not possible in simple variables.");
										}
										else
										{
											if(functable[actfuncindex].vartable[find].dimcount!=(yyvsp[(2) - (2)].vp).bpcount)
											{
												CallError("Number of dimensions not matching in array use.");	
											}
											else 
											{
												int getarr = newint();
												char printer[1000];
												snprintf(printer,999,"Load t%d %s",getarr,functable[actfuncindex].vartable[find].finalname);
												GenQuad(printer);

												int getindex = newint();
												int extra = newint();

												snprintf(printer,999,"t%d = 0",getindex);
												GenQuad(printer);

												for(int i=0;i<(yyvsp[(2) - (2)].vp).bpcount;i++)
												{
													snprintf(printer,999,"t%d = %d",extra,functable[actfuncindex].vartable[find].moddim[i]);
													GenQuad(printer);

													snprintf(printer,999,"t%d = t%d * t%d",extra,extra,(yyvsp[(2) - (2)].vp).bplist[i]);
													releaseint((yyvsp[(2) - (2)].vp).bplist[i]);
													GenQuad(printer);

													snprintf(printer,999,"t%d = t%d + t%d",getindex,getindex,extra);
													GenQuad(printer);
												}

												snprintf(printer,999,"t%d = 4",extra);
												GenQuad(printer);
												snprintf(printer,999,"t%d = t%d * t%d",getindex,getindex,extra);
												GenQuad(printer);

												releaseint(extra);

												(yyval.vp).arr=getarr;
												(yyval.vp).ind=getindex;
												strcpy((yyval.vp).type,functable[actfuncindex].vartable[find].vartype);
											}	
										}
									}
									else if(gfind!=-1)
									{
										if(gfind!=-1 && functable[0].vartable[gfind].dimcount==0)
										{
											CallError("Such indexing not possible in simple variables.");
										}
										else
										{
											if(functable[0].vartable[gfind].dimcount!=(yyvsp[(2) - (2)].vp).bpcount)
											{
												CallError("Number of dimensions not matching in array use.");	
											}
											else 
											{
												int getarr = newint();
												char printer[1000];
												snprintf(printer,999,"Load t%d %s",getarr,functable[0].vartable[gfind].finalname);
												GenQuad(printer);

												int getindex = newint();
												int extra = newint();

												snprintf(printer,999,"t%d = 0",getindex);
												GenQuad(printer);

												for(int i=0;i<(yyvsp[(2) - (2)].vp).bpcount;i++)
												{
													snprintf(printer,999,"t%d = %d",extra,functable[0].vartable[gfind].moddim[i]);
													GenQuad(printer);

													snprintf(printer,999,"t%d = t%d * t%d",extra,extra,(yyvsp[(2) - (2)].vp).bplist[i]);
													releaseint((yyvsp[(2) - (2)].vp).bplist[i]);
													GenQuad(printer);

													snprintf(printer,999,"t%d = t%d + t%d",getindex,getindex,extra);
													GenQuad(printer);
												}

												snprintf(printer,999,"t%d = 4",extra);
												GenQuad(printer);
												snprintf(printer,999,"t%d = t%d * t%d",getindex,getindex,extra);
												GenQuad(printer);

												releaseint(extra);

												(yyval.vp).arr=getarr;
												(yyval.vp).ind=getindex;
												strcpy((yyval.vp).type,functable[0].vartable[gfind].vartype);
											}	
										}
									}
								;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 2760 "parser.y"
    {
										backpatch((yyvsp[(3) - (4)].vp).bplist,(yyvsp[(3) - (4)].vp).bpcount,nextquad);
										if(strcmp((yyvsp[(3) - (4)].vp).type,"int"))
										{
											CallError("Array indices should compute to integers.");
										}
										(yyval.vp).bpcount=0;
										for(int i=0;i<(yyvsp[(1) - (4)].vp).bpcount;i++)
										{
											(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(1) - (4)].vp).bplist[i];
										}
										(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(3) - (4)].vp).tempreg;
									;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 2773 "parser.y"
    {
										backpatch((yyvsp[(2) - (3)].vp).bplist,(yyvsp[(2) - (3)].vp).bpcount,nextquad);
										if(strcmp((yyvsp[(2) - (3)].vp).type,"int"))
										{
											CallError("Array indices should compute to integers.");
										}
										(yyval.vp).bpcount=0;

										(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(2) - (3)].vp).tempreg;
									;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 2785 "parser.y"
    {
												
												(yyval.vp).bpcount=0;
												int i;
												for(i=0;i<(yyvsp[(3) - (4)].vp).bpcount;i++){
													(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(3) - (4)].vp).bplist[i];
												}
												
											;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 2796 "parser.y"
    {
												canbreak++;
												if(strcmp((yyvsp[(3) - (4)].vp).type,"int"))
												{
												CallError("Switch should have integer resulting expression.");
												}
												backpatch((yyvsp[(3) - (4)].vp).bplist,(yyvsp[(3) - (4)].vp).bpcount,nextquad);
												switchglobal=(yyvsp[(3) - (4)].vp).tempreg;
											;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 2806 "parser.y"
    {
									backpatch((yyvsp[(1) - (3)].vp).bplist2,(yyvsp[(1) - (3)].vp).bpcount2,(yyvsp[(2) - (3)].vp).quad);
									(yyval.vp).bpcount=0;
								

									for(int i=0;i<(yyvsp[(3) - (3)].vp).bpcount;i++)
									{
										(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(3) - (3)].vp).bplist[i];
									}

								;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 2817 "parser.y"
    {
									(yyval.vp).bpcount=0;
									for(int i=0;i<(yyvsp[(1) - (1)].vp).bpcount2;i++)
										(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(1) - (1)].vp).bplist2[i];
								;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 2824 "parser.y"
    {
									(yyval.vp).bpcount=0;
									for(int i=0;i<(yyvsp[(3) - (3)].vp).bpcount;i++)
									{
										(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(3) - (3)].vp).bplist[i];
									}
									
								 ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 2834 "parser.y"
    {
							
								backpatch((yyvsp[(1) - (2)].vp).bplist2,(yyvsp[(1) - (2)].vp).bpcount2,(yyvsp[(2) - (2)].vp).quad);
								(yyval.vp).bpcount2=0;
								for(int i=0;i<(yyvsp[(2) - (2)].vp).bpcount2;i++)
								{
									(yyval.vp).bplist2[(yyval.vp).bpcount2++]=(yyvsp[(2) - (2)].vp).bplist2[i];
								}
						  ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 2843 "parser.y"
    {
		   				
							
							(yyval.vp).bpcount2=0;
							for(int i=0;i<(yyvsp[(1) - (1)].vp).bpcount2;i++)
							{
								(yyval.vp).bplist2[(yyval.vp).bpcount2++]=(yyvsp[(1) - (1)].vp).bplist2[i];
							}
		   				;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 2853 "parser.y"
    {
													
													
													(yyval.vp).bpcount2=0;
													backpatch((yyvsp[(3) - (3)].vp).bplist,(yyvsp[(3) - (3)].vp).bpcount,nextquad);
													(yyval.vp).bplist2[(yyval.vp).bpcount2++]=nextquad;
													char printer[1000];
													snprintf(printer,999,"goto _____");
													GenQuad(printer);
													backpatch((yyvsp[(1) - (3)].vp).bplist,(yyvsp[(1) - (3)].vp).bpcount,nextquad);

													
													(yyval.vp).quad=(yyvsp[(2) - (3)].vp).quad;
												;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 2869 "parser.y"
    {(yyval.vp).quad=nextquad;;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 2870 "parser.y"
    {
	
																if(strcmp((yyvsp[(3) - (4)].vp).type,"int"))
																{
																	CallError("Case label does not reduce to an integer constant.");
																}
																else if(!((yyvsp[(3) - (4)].vp).caseallow))
																{
																	CallError("Case label should have only constant integer expressions.");
																}	
																backpatch((yyvsp[(3) - (4)].vp).bplist,(yyvsp[(3) - (4)].vp).bpcount,nextquad);
																char printer[1000];
																snprintf(printer,999,"if(t%d != t%d) goto _____",switchglobal,(yyvsp[(3) - (4)].vp).tempreg);
																(yyval.vp).bpcount=0;
																(yyval.vp).bplist[(yyval.vp).bpcount++]=nextquad;
																GenQuad(printer);
																releaseint((yyvsp[(3) - (4)].vp).tempreg);
															;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 2889 "parser.y"
    {
					(yyval.vp).bpcount=0;
					int i;
					for(i=0;i<(yyvsp[(1) - (1)].vp).bpcount;i++)
						(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[(1) - (1)].vp).bplist[i];
				;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 2896 "parser.y"
    {(yyval.vp).quad=nextquad;;}
    break;



/* Line 1455 of yacc.c  */
#line 4908 "parser.tab.c"
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
#line 2900 "parser.y"


int GiveType(char s1[],char s2[])
{
	if(!strcmp(s1,"errortype") || !strcmp(s2,"errortype"))
	return 0;

	if(!strcmp(s1,"float") || !strcmp(s2,"float"))
	return 1;

	return 2;

}
int InArr (struct varrecord arr[],int size,char finder[])
{
	int i=0;
	for(i=size-1;i>=0;i--)
	{
		if(!strcmp(arr[i].varname,finder))
			return i;

	}
	return -1;
}

bool CheckVar (struct varrecord arr[],int size,char finder[],int level)
{
	int i=0;
	for(i=0;i<size;i++)
	{
		if(!strcmp(arr[i].varname,finder) && arr[i].level==level)
			return true;

	}
	return false;
}

void PrintVars(struct varrecord a)
{
	printf("%s %s",a.varname,a.vartype);
	if(a.tag)
	printf(" %s ","1");
	else
	printf(" %s ","0");
	printf("%d\n",a.level);
}

void PrintFuncs(struct funcrecord a)
{
	printf("%s %s\n",a.name,a.type);
	int i=0;

	printf("Parameters %d\n",a.paramcount);
	for(i=0;i<a.paramcount;i++)
		PrintVars(a.paramtable[i]);
	printf("==============================================\n");
	printf("Variables %d\n",a.varcount);
	for(i=0;i<a.varcount;i++)
		PrintVars(a.vartable[i]);
}

void backpatch(int* arr, int len, int x)
{
	for (int i = 0; i < len; ++i)
		for (int j = 0; j < len; ++j)
			if(arr[i]<arr[j])
			{
				int t=arr[i];
				arr[i]=arr[j];
				arr[j]=t;

			}

	

	fseek(fp,0,0);
	int currLineNumber = 1;
	for (int i = 0; i < len; ++i)
	{
		while(1)
		{
			if(currLineNumber == arr[i])
			{
				char temp[300];
				char tempi=0;
				while(1)
				{
					char cx = getc(fp);
					temp[tempi] = cx;
					tempi++;
					if(cx=='\n')
						break;
				}
				temp[tempi]='\0';

				char new[5];
				sprintf(new,"%d",x);
				
				for (int ix = 0; ix < strlen(new); ++ix)
					temp[tempi-6+ix]=new[ix];
				
				for (int iy = strlen(new); iy < 5; ++iy)
					temp[tempi-6+iy] = ' ';
				
				fseek(fp,-tempi,SEEK_CUR);
				fputs(temp, fp);
				currLineNumber++;
				break;
			}
			char c = getc(fp);
			if(c=='\n')
			{
				currLineNumber++;
			}
		}
	}
	fseek(fp, 0, SEEK_END);
}


void PrintFuncTable()
{
	int i=0;
	for(i=0;i<actfuncindex;i++)
		PrintFuncs(functable[i]);
}

void GenQuad(char*s)
{
	fprintf(fp,"%d: %s\n",nextquad,s);
	nextquad++;
}
void CallError(char*s)
{
	printf("Semantic Error at Line #%d : ",lines+1);
	printf("%s\n",s);
	fclose(outFile);
	outFile = fopen("lexer.l", "r");
	success=false;
}

void CallWarning(char*s)
{
	printf("Semantic Warning at Line #%d : ",lines+1);
	printf("%s\n",s);
}

void yyerror (char *s) {
	success=false;
	printf("Syntax Error at line %d\n",lines+1);	
}

/*void despace(char target[], char input[], int l){
	int start=0, end=l-1;
	while(input[start]==' ' || input[start]=='\t') start++;
	while(input[end]==' ' || input[end]=='\t' || input[end]=='\n') end--;
	int y=0;
	for (int i = start; i <= end; ++i)
	{
		target[y++]=input[i];
	}
	target[y]='\0';
}*/
int newint()
{
	for(int i=0;i<10;i++)
	{
		if(!intreg[i])
			{intreg[i]=true;return i;}
	}
	return -1;
}
int newfloat()
{
	for(int i=0;i<10;i++)
	{
		if(!floatreg[i])
			{floatreg[i]=true;return i;}
	}
	return -1;
}
void releaseint(int i)
{
	if(i!=-1)
	intreg[i]=false;
}
void releasefloat(int i)
{
	if(i!=-1)
	floatreg[i]=false;
}
int stoi(char*s)
{
	int l=strlen(s);
	int ans=0;
	int i=0;
	for(i=0;i<l;i++)
	{
	ans=ans*10+(s[i]-48);
	}
	return ans;
}
bool isFtype(char line[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(line[i]=='(')
		return true;
	}
	return false;
}
bool isVar(char line[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			if(line[i]>='a' && line[i]<='z' || line[i]>='A' && line[i]<='Z')
			{

			}
			else
			{
				return false;
			}
		}
		else
		{
			if(line[i]>='a' && line[i]<='z' || line[i]>='A' && line[i]<='Z' || line[i]>='0' && line[i]<='9' || line[i]=='_' )
			{

			}
			else
			{
				return false;
			}
		}
	}
	return true;
}

bool NotEmpty(char line[],int l)
{
	for(int i=0;i<l;i++)
	{
		if(line[i]==' ' || line[i]=='\t' || line[i]=='\n')
		{

		}
		else
		{
			return true;
		}
	}
	return false;
}

int main(int argc, char const * argv[])
{
    char filename[100];
    snprintf(filename,999,"%s",argv[1]);
    char filename1[100];
    char filename2[100];
    snprintf(filename1,999,"%s",argv[2]);
    snprintf(filename2,999,"%s",argv[3]);


	outFile = fopen("svas.cpp", "w");
	fprintf(outFile, "#include \"funcs.h\"\n#include <iostream>\nusing namespace std;\n#include \"plotter.h\"\nstd::vector<std::pair<double, double>> points;\nstd::vector<std::pair<double, double>> lines;\nstd::vector<std::pair<double, double>> polygons;\n#include <vector>\n\nint x = 0;\nint y = 0;\n\n");
	fil=fopen(filename,"r");

	char new_name[1000];
	snprintf(new_name,999,"%s_Modified.txt",filename);
	FILE*fil1=fopen(new_name,"w");

	int ctr=0;
	char line[1000];
	char nline[1000];
	
	bool app=true;
	char printer[1000];
	while(fgets(line,sizeof(line),fil))
	{
		if(isFtype(line,strlen(line)))
		{
			app=false;
			fprintf(fil1,"%s",line);
		}
		else
		{
			if(app && NotEmpty(line,strlen(line)))
			{
				fprintf(fil1,"$$ %s",line);
			}
			else
			{
				fprintf(fil1,"%s",line);
			}

		}
	}
	fclose(fil);

	fclose(fil1);
	fil1=fopen(new_name,"r");



	yyin=fil1;
	int i=0;
	for(i=0;i<10;i++){
		intreg[i]=false;
		floatreg[i]=false;
	}
	fp=fopen(filename1,"w+");

	yyparse();

	fclose(fp);
	fclose(fil1);
	remove(new_name);

	if(success)
		printf("Compilation Successful!!\n");
	else
		printf("Error in Compilation.\n");

	printf("==============================================\n");

	FILE*varfile=fopen(filename2,"w");
	for(int i=0;i<totvars;i++)
	{
	fprintf(varfile,"%s,%s,%d\n",vars[i],types[i],sizes[i]*4);
	}
	fclose(varfile);

	FILE*successf=fopen("Res.txt","w");
	if(success){
		fprintf(successf,"1");
	}
	else
	{
		fprintf(successf,"0");
		
	}
	fclose(successf);
fclose(outFile);
	return 0;
}
