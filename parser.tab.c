/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

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


#line 136 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SELECT = 3,                     /* SELECT  */
  YYSYMBOL_PRINT = 4,                      /* PRINT  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_FLT = 6,                        /* FLT  */
  YYSYMBOL_ID = 7,                         /* ID  */
  YYSYMBOL_SC = 8,                         /* SC  */
  YYSYMBOL_SP = 9,                         /* SP  */
  YYSYMBOL_COMMA = 10,                     /* COMMA  */
  YYSYMBOL_COLON = 11,                     /* COLON  */
  YYSYMBOL_EQ = 12,                        /* EQ  */
  YYSYMBOL_OR = 13,                        /* OR  */
  YYSYMBOL_AND = 14,                       /* AND  */
  YYSYMBOL_NOT = 15,                       /* NOT  */
  YYSYMBOL_LT = 16,                        /* LT  */
  YYSYMBOL_LTE = 17,                       /* LTE  */
  YYSYMBOL_GT = 18,                        /* GT  */
  YYSYMBOL_GTE = 19,                       /* GTE  */
  YYSYMBOL_EQEQ = 20,                      /* EQEQ  */
  YYSYMBOL_NEQ = 21,                       /* NEQ  */
  YYSYMBOL_PLUS = 22,                      /* PLUS  */
  YYSYMBOL_MINUS = 23,                     /* MINUS  */
  YYSYMBOL_MULT = 24,                      /* MULT  */
  YYSYMBOL_DIV = 25,                       /* DIV  */
  YYSYMBOL_MOD = 26,                       /* MOD  */
  YYSYMBOL_OPT = 27,                       /* OPT  */
  YYSYMBOL_CPT = 28,                       /* CPT  */
  YYSYMBOL_OCURLY = 29,                    /* OCURLY  */
  YYSYMBOL_CCURLY = 30,                    /* CCURLY  */
  YYSYMBOL_IF = 31,                        /* IF  */
  YYSYMBOL_ELSE = 32,                      /* ELSE  */
  YYSYMBOL_FORT = 33,                      /* FORT  */
  YYSYMBOL_WHILET = 34,                    /* WHILET  */
  YYSYMBOL_VOID = 35,                      /* VOID  */
  YYSYMBOL_RET = 36,                       /* RET  */
  YYSYMBOL_SWITCHT = 37,                   /* SWITCHT  */
  YYSYMBOL_CASET = 38,                     /* CASET  */
  YYSYMBOL_BREAK = 39,                     /* BREAK  */
  YYSYMBOL_DEFAULT = 40,                   /* DEFAULT  */
  YYSYMBOL_CSQ = 41,                       /* CSQ  */
  YYSYMBOL_OSQ = 42,                       /* OSQ  */
  YYSYMBOL_NUM = 43,                       /* NUM  */
  YYSYMBOL_DOL = 44,                       /* DOL  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_START = 46,                     /* START  */
  YYSYMBOL_INPUTGLOBAL = 47,               /* INPUTGLOBAL  */
  YYSYMBOL_NGL = 48,                       /* NGL  */
  YYSYMBOL_MGL = 49,                       /* MGL  */
  YYSYMBOL_GLIST = 50,                     /* GLIST  */
  YYSYMBOL_INPUT = 51,                     /* INPUT  */
  YYSYMBOL_FUNC_DECL = 52,                 /* FUNC_DECL  */
  YYSYMBOL_FUNC_HEAD = 53,                 /* FUNC_HEAD  */
  YYSYMBOL_RESULT_ID = 54,                 /* RESULT_ID  */
  YYSYMBOL_RESULT = 55,                    /* RESULT  */
  YYSYMBOL_DECLISTE = 56,                  /* DECLISTE  */
  YYSYMBOL_DECLIST = 57,                   /* DECLIST  */
  YYSYMBOL_DEC = 58,                       /* DEC  */
  YYSYMBOL_ARRFUNC = 59,                   /* ARRFUNC  */
  YYSYMBOL_LISTFUNC = 60,                  /* LISTFUNC  */
  YYSYMBOL_BODY = 61,                      /* BODY  */
  YYSYMBOL_SLIST = 62,                     /* SLIST  */
  YYSYMBOL_MSLIST = 63,                    /* MSLIST  */
  YYSYMBOL_S = 64,                         /* S  */
  YYSYMBOL_INCRLEVEL = 65,                 /* INCRLEVEL  */
  YYSYMBOL_RETURN = 66,                    /* RETURN  */
  YYSYMBOL_FUNC_CALL = 67,                 /* FUNC_CALL  */
  YYSYMBOL_IDTEMP = 68,                    /* IDTEMP  */
  YYSYMBOL_PARAMLIST = 69,                 /* PARAMLIST  */
  YYSYMBOL_PLIST = 70,                     /* PLIST  */
  YYSYMBOL_WHILE = 71,                     /* WHILE  */
  YYSYMBOL_WHILEXP = 72,                   /* WHILEXP  */
  YYSYMBOL_MWHILE = 73,                    /* MWHILE  */
  YYSYMBOL_FOR = 74,                       /* FOR  */
  YYSYMBOL_FOREXP = 75,                    /* FOREXP  */
  YYSYMBOL_FORBACK1 = 76,                  /* FORBACK1  */
  YYSYMBOL_FORBACK2 = 77,                  /* FORBACK2  */
  YYSYMBOL_MFOR = 78,                      /* MFOR  */
  YYSYMBOL_NFOR = 79,                      /* NFOR  */
  YYSYMBOL_IFELSE = 80,                    /* IFELSE  */
  YYSYMBOL_NIF = 81,                       /* NIF  */
  YYSYMBOL_MIF = 82,                       /* MIF  */
  YYSYMBOL_IFEXP = 83,                     /* IFEXP  */
  YYSYMBOL_VAR_DECL = 84,                  /* VAR_DECL  */
  YYSYMBOL_TYPE = 85,                      /* TYPE  */
  YYSYMBOL_L = 86,                         /* L  */
  YYSYMBOL_ARRS = 87,                      /* ARRS  */
  YYSYMBOL_ARR = 88,                       /* ARR  */
  YYSYMBOL_BRLIST = 89,                    /* BRLIST  */
  YYSYMBOL_IDS = 90,                       /* IDS  */
  YYSYMBOL_FORASSIGN = 91,                 /* FORASSIGN  */
  YYSYMBOL_ASSIGN = 92,                    /* ASSIGN  */
  YYSYMBOL_COR = 93,                       /* COR  */
  YYSYMBOL_CAND = 94,                      /* CAND  */
  YYSYMBOL_CNOT = 95,                      /* CNOT  */
  YYSYMBOL_ECOMP = 96,                     /* ECOMP  */
  YYSYMBOL_E = 97,                         /* E  */
  YYSYMBOL_T = 98,                         /* T  */
  YYSYMBOL_F = 99,                         /* F  */
  YYSYMBOL_ARRF = 100,                     /* ARRF  */
  YYSYMBOL_ARRFLIST = 101,                 /* ARRFLIST  */
  YYSYMBOL_SWITCH = 102,                   /* SWITCH  */
  YYSYMBOL_SWITCHET = 103,                 /* SWITCHET  */
  YYSYMBOL_CASES = 104,                    /* CASES  */
  YYSYMBOL_DEFAULTE = 105,                 /* DEFAULTE  */
  YYSYMBOL_CASELIST = 106,                 /* CASELIST  */
  YYSYMBOL_CASE = 107,                     /* CASE  */
  YYSYMBOL_CMARK = 108,                    /* CMARK  */
  YYSYMBOL_CASETEMP = 109,                 /* CASETEMP  */
  YYSYMBOL_CBODY = 110,                    /* CBODY  */
  YYSYMBOL_MCASE = 111,                    /* MCASE  */
  YYSYMBOL_NCASE = 112                     /* NCASE  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   222

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  68
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   147,   147,   150,   151,   154,   158,   164,   165,   168,
     169,   172,   184,   187,   193,   204,   205,   206,   208,   209,
     210,   211,   213,   241,   269,   273,   274,   277,   296,   305,
     313,   315,   316,   317,   318,   326,   341,   355,   363,   364,
     368,   384,   394,   416,   418,   427,   468,   510,   535,   538,
     542,   593,   646,   658,   682,   687,   702,   717,   743,   745,
     747,   753,   767,   788,   796,   798,   822,   837,   838,   840,
     841,   842,   843,   846,   849,   903,   928,   956,  1001,  1099,
    1165,  1263,  1331,  1400,  1412,  1482,  1492,  1499,  1529,  1611,
    1695,  1780,  1864,  1937,  2007,  2014,  2083,  2152,  2159,  2231,
    2300,  2369,  2377,  2470,  2508,  2521,  2530,  2559,  2666,  2679,
    2691,  2702,  2712,  2723,  2730,  2740,  2749,  2759,  2774,  2775,
    2793,  2800,  2801
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SELECT", "PRINT",
  "INT", "FLT", "ID", "SC", "SP", "COMMA", "COLON", "EQ", "OR", "AND",
  "NOT", "LT", "LTE", "GT", "GTE", "EQEQ", "NEQ", "PLUS", "MINUS", "MULT",
  "DIV", "MOD", "OPT", "CPT", "OCURLY", "CCURLY", "IF", "ELSE", "FORT",
  "WHILET", "VOID", "RET", "SWITCHT", "CASET", "BREAK", "DEFAULT", "CSQ",
  "OSQ", "NUM", "DOL", "$accept", "START", "INPUTGLOBAL", "NGL", "MGL",
  "GLIST", "INPUT", "FUNC_DECL", "FUNC_HEAD", "RESULT_ID", "RESULT",
  "DECLISTE", "DECLIST", "DEC", "ARRFUNC", "LISTFUNC", "BODY", "SLIST",
  "MSLIST", "S", "INCRLEVEL", "RETURN", "FUNC_CALL", "IDTEMP", "PARAMLIST",
  "PLIST", "WHILE", "WHILEXP", "MWHILE", "FOR", "FOREXP", "FORBACK1",
  "FORBACK2", "MFOR", "NFOR", "IFELSE", "NIF", "MIF", "IFEXP", "VAR_DECL",
  "TYPE", "L", "ARRS", "ARR", "BRLIST", "IDS", "FORASSIGN", "ASSIGN",
  "COR", "CAND", "CNOT", "ECOMP", "E", "T", "F", "ARRF", "ARRFLIST",
  "SWITCH", "SWITCHET", "CASES", "DEFAULTE", "CASELIST", "CASE", "CMARK",
  "CASETEMP", "CBODY", "MCASE", "NCASE", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-172)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-122)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      21,     6,  -172,    31,    34,  -172,    78,  -172,  -172,  -172,
    -172,    29,    53,    77,   106,    69,    75,  -172,  -172,    19,
    -172,    69,  -172,  -172,  -172,  -172,   116,    69,    31,    93,
     104,     7,   105,   108,  -172,     1,   109,   118,   103,  -172,
      53,   126,   129,   111,  -172,    53,  -172,    53,  -172,  -172,
      53,  -172,  -172,   127,  -172,   112,   114,   130,  -172,   136,
     102,    -5,  -172,  -172,  -172,  -172,  -172,  -172,     1,     1,
       1,   110,     1,   138,   119,     0,     4,     1,  -172,  -172,
     134,   135,  -172,    72,    99,    85,  -172,  -172,     1,  -172,
    -172,    19,  -172,  -172,  -172,     1,  -172,  -172,  -172,   141,
     121,     1,   113,  -172,    69,   115,  -172,   117,   120,  -172,
     116,    48,    92,    -3,     1,    49,     7,  -172,     1,    72,
      55,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,    56,  -172,   122,   144,   134,     9,
     128,   143,   132,    94,  -172,   131,    74,  -172,  -172,  -172,
     124,   125,   133,   123,  -172,  -172,   150,  -172,  -172,    26,
    -172,     1,    57,  -172,   135,  -172,    99,    99,    99,    99,
      99,    99,    85,    85,  -172,  -172,  -172,  -172,  -172,     1,
       1,  -172,     1,  -172,  -172,     1,  -172,  -172,   137,    19,
    -172,   139,  -172,   140,  -172,  -172,    95,  -172,   134,   134,
     134,    53,   107,   148,  -172,    41,  -172,  -172,  -172,  -172,
    -172,  -172,    19,   142
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     2,     0,     0,     1,     0,    15,    16,    17,
       4,     0,     0,     0,     0,     0,     5,    12,     9,     0,
      11,    19,    14,    67,    68,     8,     0,     0,     0,     0,
       0,    47,     0,     0,    54,    44,     0,     0,    30,    29,
       0,     0,     0,     0,    36,     0,    35,     0,    60,    34,
       0,    32,    33,     0,    40,     0,     0,    18,    21,     0,
      77,     0,    72,    73,    70,     7,     3,    31,     0,     0,
       0,   107,     0,     0,     0,   102,     0,     0,   103,   104,
      45,    83,    85,    86,    94,    97,   101,   106,     0,    41,
      27,     0,    37,    39,    38,    49,    52,    55,    56,     0,
      61,     0,     0,    13,     0,    22,    23,     0,    74,    66,
       0,     0,     0,     0,     0,     0,     0,    59,     0,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,     0,    48,    51,     0,
       0,     0,     0,     0,   122,     0,   113,   116,   118,    20,
       0,    24,     0,     0,    71,    69,     0,    80,   109,     0,
      65,     0,     0,   105,    82,    84,    88,    89,    90,    91,
      93,    92,    95,    96,    98,    99,   100,   111,    46,     0,
       0,    58,     0,    64,    81,     0,   110,   115,     0,     0,
      26,     0,    76,     0,    42,   108,     0,    53,    50,    78,
      79,     0,     0,     0,   112,    30,   117,    25,    75,    57,
      62,   119,     0,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -172,  -172,  -172,   152,  -172,  -172,    32,  -172,  -172,  -172,
    -172,  -172,  -172,    65,  -172,  -172,   -38,  -171,  -172,    82,
    -172,  -172,   -18,  -172,  -172,  -172,  -172,  -172,  -172,  -172,
    -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,    30,
     -17,  -172,    66,  -172,  -172,    68,  -172,   145,   -55,    54,
      60,   146,   -29,    -1,   -16,   -19,  -172,  -172,  -172,  -172,
    -172,  -172,    33,  -172,  -172,  -172,  -172,  -172
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     3,     4,    16,    10,    11,    12,    13,
      14,    56,    57,    58,   106,   151,    20,    38,    91,    39,
      40,    41,    79,    43,   136,   137,    44,    45,    74,    46,
      47,    48,    98,   161,    99,    49,   142,   201,    50,    51,
      26,    61,    62,    63,   108,    64,   140,    52,    80,    81,
      82,    83,    84,    85,    86,    87,    71,    54,    55,   145,
     204,   146,   147,   189,   148,   206,   188,   185
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    42,    92,   109,    59,   110,     5,    96,    75,    97,
     121,    75,   100,   111,   112,   113,    76,   115,   205,    69,
      29,   180,   120,    30,    23,    24,    31,   -47,    77,   -10,
       6,    77,     6,   134,     7,     8,     7,     8,   158,   121,
     138,   213,    70,    18,    78,    25,   143,    78,   -43,    70,
      32,    70,    33,    34,    53,    35,    36,    65,    37,   159,
      66,   121,   121,   162,     9,    -6,     9,   195,   121,   121,
     121,  -120,    53,    42,    23,    24,   156,   160,    15,  -120,
     141,  -120,    19,   163,   177,   197,    17,    59,   123,   124,
     125,   126,   127,   128,   166,   167,   168,   169,   170,   171,
     157,    67,   184,   209,    21,   121,   196,   121,   121,   131,
     132,   133,   144,    22,  -121,   174,   175,   176,   211,    27,
     121,   129,   130,    60,   198,   199,    89,   200,   172,   173,
     202,    68,    72,    90,    93,    73,    88,    94,    95,   101,
     104,   102,   103,   105,   107,   116,   118,   121,   139,   122,
     178,   144,   114,   -63,   179,   182,   181,   150,   194,   212,
     152,   186,   153,   210,   183,   190,   193,   191,    28,   149,
      53,    42,  -114,   135,   192,   164,   154,   203,   155,   187,
     207,   208,   165,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   117,     0,
       0,     0,   119
};

static const yytype_int16 yycheck[] =
{
      19,    19,    40,     8,    21,    10,     0,    45,     7,    47,
      13,     7,    50,    68,    69,    70,    15,    72,   189,    12,
       1,    12,    77,     4,     5,     6,     7,    27,    27,     0,
       1,    27,     1,    88,     5,     6,     5,     6,    41,    13,
      95,   212,    42,    11,    43,    15,   101,    43,    29,    42,
      31,    42,    33,    34,    73,    36,    37,    27,    39,   114,
      28,    13,    13,   118,    35,    44,    35,    41,    13,    13,
      13,    30,    91,    91,     5,     6,    28,    28,    44,    38,
      99,    40,    29,    28,    28,    28,     8,   104,    16,    17,
      18,    19,    20,    21,   123,   124,   125,   126,   127,   128,
       8,     8,     8,     8,    27,    13,   161,    13,    13,    24,
      25,    26,    38,     7,    40,   131,   132,   133,    11,    44,
      13,    22,    23,     7,   179,   180,     8,   182,   129,   130,
     185,    27,    27,    30,     8,    27,    27,     8,    27,    12,
      10,    29,    28,     7,    42,     7,    27,    13,     7,    14,
      28,    38,    42,    32,    10,    12,    28,    42,     8,    11,
      43,    30,    42,   201,    32,    41,    43,    42,    16,   104,
     189,   189,    30,    91,    41,   121,   110,    40,   110,   146,
      41,    41,   122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,   212,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    76
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    46,    47,    48,    49,     0,     1,     5,     6,    35,
      51,    52,    53,    54,    55,    44,    50,     8,    51,    29,
      61,    27,     7,     5,     6,    84,    85,    44,    48,     1,
       4,     7,    31,    33,    34,    36,    37,    39,    62,    64,
      65,    66,    67,    68,    71,    72,    74,    75,    76,    80,
      83,    84,    92,   100,   102,   103,    56,    57,    58,    85,
       7,    86,    87,    88,    90,    84,    51,     8,    27,    12,
      42,   101,    27,    27,    73,     7,    15,    27,    43,    67,
      93,    94,    95,    96,    97,    98,    99,   100,    27,     8,
      30,    63,    61,     8,     8,    27,    61,    61,    77,    79,
      61,    12,    29,    28,    10,     7,    59,    42,    89,     8,
      10,    93,    93,    93,    42,    93,     7,    92,    27,    96,
      93,    13,    14,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    93,    64,    69,    70,    93,     7,
      91,   100,    81,    93,    38,   104,   106,   107,   109,    58,
      42,    60,    43,    42,    87,    90,    28,     8,    41,    93,
      28,    78,    93,    28,    94,    95,    97,    97,    97,    97,
      97,    97,    98,    98,    99,    99,    99,    28,    28,    10,
      12,    28,    12,    32,     8,   112,    30,   107,   111,   108,
      41,    42,    41,    43,     8,    41,    93,    28,    93,    93,
      93,    82,    93,    40,   105,    62,   110,    41,    41,     8,
      61,    11,    11,    62
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    49,    50,    50,    51,
      51,    52,    52,    53,    54,    55,    55,    55,    56,    56,
      57,    57,    58,    58,    59,    60,    60,    61,    62,    62,
      63,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    66,    66,    67,    68,    69,    69,
      70,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    80,    81,    82,    83,    84,    85,    85,    86,
      86,    86,    86,    87,    88,    89,    89,    90,    91,    91,
      92,    92,    93,    93,    94,    94,    95,    95,    96,    96,
      96,    96,    96,    96,    96,    97,    97,    97,    98,    98,
      98,    98,    99,    99,    99,    99,    99,   100,   101,   101,
     102,   103,   104,   104,   105,   106,   106,   107,   108,   109,
     110,   111,   112
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     4,     2,     0,     0,     3,     2,     2,
       1,     2,     2,     4,     2,     1,     1,     1,     1,     0,
       3,     1,     2,     2,     2,     3,     2,     3,     3,     1,
       0,     2,     1,     1,     1,     1,     1,     2,     2,     2,
       1,     2,     5,     0,     1,     2,     4,     1,     1,     0,
       3,     1,     2,     5,     0,     2,     2,     6,     3,     0,
       0,     2,     6,     0,     0,     4,     3,     1,     1,     3,
       1,     3,     1,     1,     2,     4,     3,     1,     3,     3,
       4,     4,     3,     1,     3,     1,     1,     2,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     1,     1,     1,     3,     1,     2,     4,     3,
       4,     4,     3,     1,     3,     2,     1,     3,     0,     4,
       1,     0,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 5: /* NGL: %empty  */
#line 154 "parser.y"
         {
actfuncindex=1;
}
#line 1395 "parser.tab.c"
    break;

  case 6: /* MGL: %empty  */
#line 158 "parser.y"
        {
strcpy(functable[0].name,"global");
strcpy(functable[0].type,"int");
}
#line 1404 "parser.tab.c"
    break;

  case 11: /* FUNC_DECL: FUNC_HEAD BODY  */
#line 172 "parser.y"
                           {
actfuncindex++;  
globallevel=0;
char printer[1000];
backpatch((yyvsp[0].vp).bplist,(yyvsp[0].vp).bpcount,nextquad);




GenQuad(printer);

}
#line 1421 "parser.tab.c"
    break;

  case 12: /* FUNC_DECL: error SC  */
#line 184 "parser.y"
            { yyerrok;}
#line 1427 "parser.tab.c"
    break;

  case 13: /* FUNC_HEAD: RESULT_ID OPT DECLISTE CPT  */
#line 187 "parser.y"
                                        {

globallevel++;

}
#line 1437 "parser.tab.c"
    break;

  case 14: /* RESULT_ID: RESULT ID  */
#line 193 "parser.y"
                      { functable[actfuncindex].paramcount=0;
functable[actfuncindex].varcount=0;
globallevel++;
strcpy(functable[actfuncindex].name,(yyvsp[0].vp).vali);

char printer[1000];

GenQuad(printer);

 }
#line 1452 "parser.tab.c"
    break;

  case 15: /* RESULT: INT  */
#line 204 "parser.y"
                   {strcpy(functable[actfuncindex].type,"int");}
#line 1458 "parser.tab.c"
    break;

  case 16: /* RESULT: FLT  */
#line 205 "parser.y"
        {strcpy(functable[actfuncindex].type,"float");}
#line 1464 "parser.tab.c"
    break;

  case 17: /* RESULT: VOID  */
#line 206 "parser.y"
           {strcpy(functable[actfuncindex].type,"void");}
#line 1470 "parser.tab.c"
    break;

  case 22: /* DEC: TYPE ID  */
#line 213 "parser.y"
              {
int finder;
finder = InArr(functable[actfuncindex].paramtable,functable[actfuncindex].paramcount,(yyvsp[0].vp).vali);
if(finder!=-1)
{
char printer[1000];

CallError(printer);
}
else
{
struct varrecord new_record;
strcpy(new_record.varname,(yyvsp[0].vp).vali);
strcpy(new_record.vartype,(yyvsp[-1].vp).type);
new_record.tag=false;
new_record.level = globallevel;
new_record.IsArr = false;
new_record.dimcount = 0;

char finalname[1000];

strcpy(new_record.finalname,finalname);

functable[actfuncindex].paramtable[functable[actfuncindex].paramcount++]=new_record;
}

}
#line 1502 "parser.tab.c"
    break;

  case 23: /* DEC: TYPE ARRFUNC  */
#line 241 "parser.y"
               {
int finder;
finder = InArr(functable[actfuncindex].paramtable,functable[actfuncindex].paramcount,(yyvsp[0].vp).vali);
if(finder!=-1)
{
char printer[1000];

CallError(printer);
}
else
{
struct varrecord new_record;
strcpy(new_record.varname,(yyvsp[0].vp).vali);
strcpy(new_record.vartype,(yyvsp[-1].vp).type);
new_record.tag=false;
new_record.level = globallevel;
new_record.IsArr = true;
new_record.dimcount = (yyvsp[0].vp).counter;

char finalname[1000];


strcpy(new_record.finalname,finalname);

functable[actfuncindex].paramtable[functable[actfuncindex].paramcount++]=new_record;
}
}
#line 1534 "parser.tab.c"
    break;

  case 24: /* ARRFUNC: ID LISTFUNC  */
#line 269 "parser.y"
                          {strcpy((yyval.vp).vali,(yyvsp[-1].vp).vali);
(yyval.vp).counter=(yyvsp[0].vp).counter;}
#line 1541 "parser.tab.c"
    break;

  case 25: /* LISTFUNC: LISTFUNC OSQ CSQ  */
#line 273 "parser.y"
                             {(yyval.vp).counter=(yyvsp[-2].vp).counter+1;}
#line 1547 "parser.tab.c"
    break;

  case 26: /* LISTFUNC: OSQ CSQ  */
#line 274 "parser.y"
              {(yyval.vp).counter=1;}
#line 1553 "parser.tab.c"
    break;

  case 27: /* BODY: OCURLY SLIST CCURLY  */
#line 277 "parser.y"
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
for(int i=0;i<(yyvsp[-1].vp).bpcount;i++)
{
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[-1].vp).bplist[i];
}

}
#line 1576 "parser.tab.c"
    break;

  case 28: /* SLIST: SLIST MSLIST S  */
#line 296 "parser.y"
                            {
backpatch((yyvsp[-2].vp).bplist,(yyvsp[-2].vp).bpcount,(yyvsp[-1].vp).quad);

(yyval.vp).bpcount=0;
for(int i=0;i<(yyvsp[0].vp).bpcount;i++)
{
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[0].vp).bplist[i];
}
}
#line 1590 "parser.tab.c"
    break;

  case 29: /* SLIST: S  */
#line 305 "parser.y"
                    {
(yyval.vp).bpcount=0;
for(int i=0;i<(yyvsp[0].vp).bpcount;i++)
{
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[0].vp).bplist[i];
}
}
#line 1602 "parser.tab.c"
    break;

  case 30: /* MSLIST: %empty  */
#line 313 "parser.y"
         { (yyval.vp).quad=nextquad;}
#line 1608 "parser.tab.c"
    break;

  case 31: /* S: error SC  */
#line 315 "parser.y"
                  { yyerrok;}
#line 1614 "parser.tab.c"
    break;

  case 32: /* S: VAR_DECL  */
#line 316 "parser.y"
           {}
#line 1620 "parser.tab.c"
    break;

  case 33: /* S: ASSIGN  */
#line 317 "parser.y"
         {}
#line 1626 "parser.tab.c"
    break;

  case 34: /* S: IFELSE  */
#line 318 "parser.y"
         {
(yyval.vp).bpcount=0;
int i;
for( i=0;i<(yyvsp[0].vp).bpcount;i++)
{
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[0].vp).bplist[i];
}
}
#line 1639 "parser.tab.c"
    break;

  case 35: /* S: FOR  */
#line 326 "parser.y"
         {

(yyval.vp).bpcount=0;
int i;
for(i=0;i<canbreakcount[canbreak];i++)
{
(yyval.vp).bplist[(yyval.vp).bpcount++]=canbreakarr[canbreak][i];
}
canbreakcount[canbreak]=0;
canbreak--;
for( i=0;i<(yyvsp[0].vp).bpcount;i++)
{
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[0].vp).bplist[i];
}
}
#line 1659 "parser.tab.c"
    break;

  case 36: /* S: WHILE  */
#line 341 "parser.y"
         {
(yyval.vp).bpcount=0;
int i;
for(i=0;i<canbreakcount[canbreak];i++)
{
(yyval.vp).bplist[(yyval.vp).bpcount++]=canbreakarr[canbreak][i];
}
canbreakcount[canbreak]=0;
canbreak--;
for( i=0;i<(yyvsp[0].vp).bpcount;i++)
{
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[0].vp).bplist[i];
}
}
#line 1678 "parser.tab.c"
    break;

  case 37: /* S: INCRLEVEL BODY  */
#line 355 "parser.y"
                 {
(yyval.vp).bpcount=0;
int i;
for( i=0;i<(yyvsp[0].vp).bpcount;i++)
{
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[0].vp).bplist[i];
}
}
#line 1691 "parser.tab.c"
    break;

  case 38: /* S: FUNC_CALL SC  */
#line 363 "parser.y"
               {}
#line 1697 "parser.tab.c"
    break;

  case 39: /* S: RETURN SC  */
#line 364 "parser.y"
            {


}
#line 1706 "parser.tab.c"
    break;

  case 40: /* S: SWITCH  */
#line 368 "parser.y"
         {
(yyval.vp).bpcount=0;

int i;
for(i=0;i<canbreakcount[canbreak];i++)
{
(yyval.vp).bplist[(yyval.vp).bpcount++]=canbreakarr[canbreak][i];
}
canbreakcount[canbreak]=0;
canbreak--;
for(i=0;i<(yyvsp[0].vp).bpcount;i++){
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[0].vp).bplist[i];
}
releaseint(switchglobal);

}
#line 1727 "parser.tab.c"
    break;

  case 41: /* S: BREAK SC  */
#line 384 "parser.y"
           {
if(canbreak==0)
{
CallError("Break can only occur within switch or loops.");
}
char printer[1000];

canbreakarr[canbreak][canbreakcount[canbreak]++]=nextquad;
GenQuad(printer);
}
#line 1742 "parser.tab.c"
    break;

  case 42: /* S: PRINT OPT COR CPT SC  */
#line 394 "parser.y"
                             {
char printer[1000];
backpatch((yyvsp[-2].vp).bplist,(yyvsp[-2].vp).bpcount,nextquad);
if(!strcmp((yyvsp[-2].vp).type,"errortype"))
{
CallError("Some error while calling print.");
}
else if(!strcmp((yyvsp[-2].vp).type,"int"))
{

GenQuad(printer);
releaseint((yyvsp[-2].vp).tempreg);
}
else if(!strcmp((yyvsp[-2].vp).type,"float"))
{

GenQuad(printer);
releasefloat((yyvsp[-2].vp).tempreg);
}
}
#line 1767 "parser.tab.c"
    break;

  case 43: /* INCRLEVEL: %empty  */
#line 416 "parser.y"
             {globallevel++;}
#line 1773 "parser.tab.c"
    break;

  case 44: /* RETURN: RET  */
#line 418 "parser.y"
                       {
if(strcmp(functable[actfuncindex].type,"void"))
{
CallWarning("No return value in non-void function.");
}
char printer[1000];

GenQuad(printer);
}
#line 1787 "parser.tab.c"
    break;

  case 45: /* RETURN: RET COR  */
#line 427 "parser.y"
                {
if(!strcmp(functable[actfuncindex].type,"void"))
{
CallWarning("Return value in a void function.");
}
backpatch((yyvsp[0].vp).bplist,(yyvsp[0].vp).bpcount,nextquad);
char printer[1000];
if(!strcmp(functable[actfuncindex].type,"float"))
{
int temp2=(yyvsp[0].vp).tempreg;
if(!strcmp((yyvsp[0].vp).type,"int"))
{
temp2=newfloat();

releaseint((yyvsp[0].vp).tempreg);
GenQuad(printer);
}

GenQuad(printer);
releasefloat(temp2);

}
else
{
int temp2=(yyvsp[0].vp).tempreg;
if(!strcmp((yyvsp[0].vp).type,"float"))
{
temp2=newint();

releasefloat((yyvsp[0].vp).tempreg);
GenQuad(printer);
}

GenQuad(printer);
releaseint(temp2);

}

}
#line 1831 "parser.tab.c"
    break;

  case 46: /* FUNC_CALL: IDTEMP OPT PARAMLIST CPT  */
#line 468 "parser.y"
                                     {
if(callfuncindex!=-1 && functable[callfuncindex].paramcount!=(yyvsp[-1].vp).counter)
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

GenQuad(printer);
int gettemp;
if(callfuncindex!=-1)
{
if(!strcmp(functable[callfuncindex].type,"int"))
{
gettemp=newint();

GenQuad(printer);
}
else if(!strcmp(functable[callfuncindex].type,"float"))
{
gettemp=newfloat();

GenQuad(printer);
}
else
gettemp=-1;

(yyval.vp).tempreg=gettemp;
}

}
#line 1877 "parser.tab.c"
    break;

  case 47: /* IDTEMP: ID  */
#line 510 "parser.y"
            {
int get=-1;
int i=0;
for(i=0;i<actfuncindex+1;i++)
{
if(!strcmp(functable[i].name,(yyvsp[0].vp).vali))
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
strcpy((yyval.vp).vali,(yyvsp[0].vp).vali);

}
#line 1906 "parser.tab.c"
    break;

  case 48: /* PARAMLIST: PLIST  */
#line 535 "parser.y"
                  {
(yyval.vp).counter = (yyvsp[0].vp).counter;
}
#line 1914 "parser.tab.c"
    break;

  case 49: /* PARAMLIST: %empty  */
#line 538 "parser.y"
  {
(yyval.vp).counter = 0;
}
#line 1922 "parser.tab.c"
    break;

  case 50: /* PLIST: PLIST COMMA COR  */
#line 542 "parser.y"
                        {
(yyval.vp).counter++;
backpatch((yyvsp[0].vp).bplist,(yyvsp[0].vp).bpcount,nextquad);
char checktype[100];
if(callfuncindex!=-1)
strcpy(checktype,functable[callfuncindex].paramtable[(yyval.vp).counter-1].vartype);
else{
strcpy(checktype,"errortype");
}

char printer[1000];
if(!strcmp((yyvsp[0].vp).type,"int"))
{
if(!strcmp(checktype,"float"))
{
int gettemp = newfloat();


GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);

releasefloat(gettemp);

}
else
{

releaseint((yyvsp[0].vp).tempreg);
}
}
if(!strcmp((yyvsp[0].vp).type,"float"))
{
if(!strcmp(checktype,"int"))
{
int gettemp = newint();

GenQuad(printer);
releasefloat((yyvsp[0].vp).tempreg);

releaseint(gettemp);
}
else
{

releasefloat((yyvsp[0].vp).tempreg);
}
}

GenQuad(printer);

}
#line 1978 "parser.tab.c"
    break;

  case 51: /* PLIST: COR  */
#line 593 "parser.y"
      {
(yyval.vp).counter=1;
backpatch((yyvsp[0].vp).bplist,(yyvsp[0].vp).bpcount,nextquad);

char checktype[100];
if(callfuncindex!=-1)
strcpy(checktype,functable[callfuncindex].paramtable[(yyval.vp).counter-1].vartype);
else
strcpy(checktype,"errortype");
char printer[1000];
if(!strcmp((yyvsp[0].vp).type,"int"))
{
if(!strcmp(checktype,"float"))
{
int gettemp = newfloat();


GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);

releasefloat(gettemp);

}
else
{

releaseint((yyvsp[0].vp).tempreg);
}
}
if(!strcmp((yyvsp[0].vp).type,"float"))
{
if(!strcmp(checktype,"int"))
{
int gettemp = newint();

GenQuad(printer);
releasefloat((yyvsp[0].vp).tempreg);

releaseint(gettemp);
}
else
{

releasefloat((yyvsp[0].vp).tempreg);
}
}
GenQuad(printer);

}
#line 2032 "parser.tab.c"
    break;

  case 52: /* WHILE: WHILEXP BODY  */
#line 646 "parser.y"
                     {

char printer[1000];

GenQuad(printer);
backpatch((yyvsp[0].vp).bplist,(yyvsp[0].vp).bpcount,(yyvsp[-1].vp).begin);
(yyval.vp).bpcount=0;
int i;
for(i=0;i<(yyvsp[-1].vp).bpcount;i++)
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[-1].vp).bplist[i];
}
#line 2048 "parser.tab.c"
    break;

  case 53: /* WHILEXP: WHILET MWHILE OPT COR CPT  */
#line 658 "parser.y"
                                    {
backpatch((yyvsp[-1].vp).bplist,(yyvsp[-1].vp).bpcount,nextquad);

int temp2=(yyvsp[-1].vp).tempreg;
char printer[1000];
if(!strcmp((yyvsp[-1].vp).type,"float"))
{
temp2=newint();

releasefloat((yyvsp[-1].vp).tempreg);
GenQuad(printer);
}


(yyval.vp).bpcount=0;
(yyval.vp).bplist[(yyval.vp).bpcount++]=nextquad;
GenQuad(printer);
releaseint(temp2);
(yyval.vp).begin=(yyvsp[-3].vp).quad;

globallevel++; canbreak++;

}
#line 2076 "parser.tab.c"
    break;

  case 54: /* MWHILE: %empty  */
#line 682 "parser.y"
                   { (yyval.vp).quad=nextquad;}
#line 2082 "parser.tab.c"
    break;

  case 55: /* FOR: FOREXP BODY  */
#line 687 "parser.y"
                  {
char printer[1000];

(yyvsp[0].vp).bplist[(yyvsp[0].vp).bpcount++]=nextquad;
GenQuad(printer);
backpatch((yyvsp[0].vp).bplist,(yyvsp[0].vp).bpcount,(yyvsp[-1].vp).quad);
(yyval.vp).bpcount=0;
int i;
for(i=0;i<(yyvsp[-1].vp).bpcount;i++)
{
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[-1].vp).bplist[i];
}
}
#line 2100 "parser.tab.c"
    break;

  case 56: /* FOREXP: FORBACK1 FORBACK2  */
#line 702 "parser.y"
                           {globallevel++;canbreak++;
(yyval.vp).quad=(yyvsp[0].vp).quad;
char printer[1000];

GenQuad(printer);

backpatch((yyvsp[-1].vp).bplist2,(yyvsp[-1].vp).bpcount2,nextquad);
(yyval.vp).bpcount=0;
int i;
for(i=0;i<(yyvsp[-1].vp).bpcount;i++)
{
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[-1].vp).bplist[i];
}
}
#line 2119 "parser.tab.c"
    break;

  case 57: /* FORBACK1: FORT OPT ASSIGN MFOR COR SC  */
#line 717 "parser.y"
                                       {
backpatch((yyvsp[-1].vp).bplist,(yyvsp[-1].vp).bpcount,nextquad);
int temp2=(yyvsp[-1].vp).tempreg;
char printer[1000];
if(!strcmp((yyvsp[-1].vp).type,"float"))
{
temp2=newint();

releasefloat((yyvsp[-1].vp).tempreg);
GenQuad(printer);
}


(yyval.vp).bpcount=0;
(yyval.vp).bplist[(yyval.vp).bpcount++]=nextquad;
GenQuad(printer);
releaseint(temp2);
(yyval.vp).bpcount2=0;
(yyval.vp).bplist2[(yyval.vp).bpcount2++]=nextquad;

GenQuad(printer);
(yyval.vp).quad=(yyvsp[-2].vp).quad;

  }
#line 2148 "parser.tab.c"
    break;

  case 58: /* FORBACK2: NFOR FORASSIGN CPT  */
#line 743 "parser.y"
                             { (yyval.vp).quad=(yyvsp[-2].vp).quad;}
#line 2154 "parser.tab.c"
    break;

  case 59: /* MFOR: %empty  */
#line 745 "parser.y"
       { (yyval.vp).quad=nextquad;}
#line 2160 "parser.tab.c"
    break;

  case 60: /* NFOR: %empty  */
#line 747 "parser.y"
       {(yyval.vp).quad=nextquad;}
#line 2166 "parser.tab.c"
    break;

  case 61: /* IFELSE: IFEXP BODY  */
#line 753 "parser.y"
                                       {
int i;
(yyval.vp).bpcount=0;
for(i=0;i<(yyvsp[-1].vp).bpcount;i++)
{
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[-1].vp).bplist[i];
}
for(i=0;i<(yyvsp[0].vp).bpcount;i++)
{
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[0].vp).bplist[i];
}


}
#line 2185 "parser.tab.c"
    break;

  case 62: /* IFELSE: IFEXP BODY NIF ELSE MIF BODY  */
#line 767 "parser.y"
                               {
backpatch((yyvsp[-5].vp).bplist,(yyvsp[-5].vp).bpcount,(yyvsp[-1].vp).quad);
(yyval.vp).bpcount=0;
int i;
for(i=0;i<(yyvsp[-4].vp).bpcount;i++)
{
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[-4].vp).bplist[i];
}
for(i=0;i<(yyvsp[-3].vp).bpcount;i++)
{
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[-3].vp).bplist[i];
}
for(i=0;i<(yyvsp[0].vp).bpcount;i++)
{
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[0].vp).bplist[i];
}



}
#line 2210 "parser.tab.c"
    break;

  case 63: /* NIF: %empty  */
#line 788 "parser.y"
      {
char printer[1000];

(yyval.vp).bpcount=0;
(yyval.vp).bplist[(yyval.vp).bpcount++]=nextquad;
GenQuad(printer);
}
#line 2222 "parser.tab.c"
    break;

  case 64: /* MIF: %empty  */
#line 796 "parser.y"
        {(yyval.vp).quad=nextquad;globallevel++;}
#line 2228 "parser.tab.c"
    break;

  case 65: /* IFEXP: IF OPT COR CPT  */
#line 798 "parser.y"
                         {
backpatch((yyvsp[-1].vp).bplist,(yyvsp[-1].vp).bpcount,nextquad);
char printer[1000];
globallevel ++;
int temp2=(yyvsp[-1].vp).tempreg;
if(!strcmp((yyvsp[-1].vp).type,"float"))
{
temp2=newint();

releasefloat((yyvsp[-1].vp).tempreg);
GenQuad(printer);
}


(yyval.vp).bpcount=0;
(yyval.vp).bplist[(yyval.vp).bpcount++]=nextquad;
GenQuad(printer);
releaseint(temp2);
}
#line 2252 "parser.tab.c"
    break;

  case 66: /* VAR_DECL: TYPE L SC  */
#line 822 "parser.y"
                     {
int i;
int ct = 1;
for(i=0;i<functable[actfuncindex].varcount;i++)
{
if(!strcmp(functable[actfuncindex].vartable[i].vartype,"-1"))
{
strcpy(functable[actfuncindex].vartable[i].vartype,(yyvsp[-2].vp).type);
strcpy(types[totvars-ct],(yyvsp[-2].vp).type);
ct--;

}
}
}
#line 2271 "parser.tab.c"
    break;

  case 67: /* TYPE: INT  */
#line 837 "parser.y"
            {strcpy((yyval.vp).type,"int");}
#line 2277 "parser.tab.c"
    break;

  case 68: /* TYPE: FLT  */
#line 838 "parser.y"
        {strcpy((yyval.vp).type,"float");}
#line 2283 "parser.tab.c"
    break;

  case 74: /* ARR: ID BRLIST  */
#line 849 "parser.y"
                                {
int finder;
int checker;
finder = InArr(functable[actfuncindex].paramtable,functable[actfuncindex].paramcount,(yyvsp[-1].vp).vali);
checker = InArr(functable[actfuncindex].vartable,functable[actfuncindex].varcount,(yyvsp[-1].vp).vali);
if(finder!=-1 && globallevel==2)
{
char printer[1000];

CallError(printer);
}
else if(checker!=-1 && functable[actfuncindex].vartable[checker].level==globallevel)
{
char printer[1000];

CallError(printer);
}
else
{
strcpy(functable[actfuncindex].vartable[functable[actfuncindex].varcount].varname,(yyvsp[-1].vp).vali);
strcpy(functable[actfuncindex].vartable[functable[actfuncindex].varcount].vartype,"-1");
functable[actfuncindex].vartable[functable[actfuncindex].varcount].tag=true;
functable[actfuncindex].vartable[functable[actfuncindex].varcount].level=globallevel;
functable[actfuncindex].vartable[functable[actfuncindex].varcount].IsArr=true;

char finalname[1000];

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
}
#line 2341 "parser.tab.c"
    break;

  case 75: /* BRLIST: BRLIST OSQ NUM CSQ  */
#line 903 "parser.y"
                                {
int t = strlen((yyvsp[-1].vp).vali);
int i=0;
bool isf=false;
for(i=0;i<t;i++)
{
if((yyvsp[-1].vp).vali[i]=='.')
{
isf=true;
break;
}
}
bool isn = ((yyvsp[-1].vp).vali[0]=='-');
if(isf)
{
CallError("Array dimensions should be an integer");
}
if(isn)
{
CallError("Array dimensions should be an positive integer");
}

functable[actfuncindex].vartable[functable[actfuncindex].varcount].dim[functable[actfuncindex].vartable[functable[actfuncindex].varcount].dimcount++]=stoi((yyvsp[-1].vp).vali);

}
#line 2371 "parser.tab.c"
    break;

  case 76: /* BRLIST: OSQ NUM CSQ  */
#line 928 "parser.y"
              {
int t = strlen((yyvsp[-1].vp).vali);
int i=0;
bool isf=false;
for(i=0;i<t;i++)
{
if((yyvsp[-1].vp).vali[i]=='.')
{
isf=true;
break;
}
}
bool isn = ((yyvsp[-1].vp).vali[0]=='-');
if(isf)
{
CallError("Array dimensions should be an integer");
}
if(isn)
{
CallError("Array dimensions should be an positive integer");
}

functable[actfuncindex].vartable[functable[actfuncindex].varcount].dimcount=1;
functable[actfuncindex].vartable[functable[actfuncindex].varcount].dim[0]=stoi((yyvsp[-1].vp).vali);

 }
#line 2402 "parser.tab.c"
    break;

  case 77: /* IDS: ID  */
#line 956 "parser.y"
         {
int finder;
int checker;
finder = InArr(functable[actfuncindex].paramtable,functable[actfuncindex].paramcount,(yyvsp[0].vp).vali);
checker = InArr(functable[actfuncindex].vartable,functable[actfuncindex].varcount,(yyvsp[0].vp).vali);
if(finder!=-1 && globallevel==2)
{
char printer[1000];

CallError(printer);
}
else if(checker!=-1 && functable[actfuncindex].vartable[checker].level==globallevel)
{
char printer[1000];

CallError(printer);
}
else
{
struct varrecord new_record;
strcpy(new_record.varname,(yyvsp[0].vp).vali);
strcpy(new_record.vartype,"-1");
new_record.tag=true;
new_record.level = globallevel;
new_record.IsArr = false;
new_record.dimcount = 0;



char finalname[1000];

strcpy(vars[totvars],finalname);
strcpy(types[totvars],new_record.vartype);
sizes[totvars]=0;
totvars++;

strcpy(new_record.finalname,finalname);
functable[actfuncindex].vartable[functable[actfuncindex].varcount++]=new_record;

}
}
#line 2448 "parser.tab.c"
    break;

  case 78: /* FORASSIGN: ID EQ COR  */
#line 1001 "parser.y"
                            {
backpatch((yyvsp[0].vp).bplist,(yyvsp[0].vp).bpcount,nextquad);
int finder;
int checker,gchecker;
finder = InArr(functable[actfuncindex].paramtable,functable[actfuncindex].paramcount,(yyvsp[-2].vp).vali);
checker = InArr(functable[actfuncindex].vartable,functable[actfuncindex].varcount,(yyvsp[-2].vp).vali);
gchecker = InArr(functable[0].vartable,functable[0].varcount,(yyvsp[-2].vp).vali);

if(checker==-1 && finder==-1 && gchecker==-1)
{
char printer[1000];

CallError(printer);
}
if(checker!=-1)
strcpy((yyvsp[-2].vp).type,functable[actfuncindex].vartable[checker].vartype);
else if (finder!=-1)
strcpy((yyvsp[-2].vp).type,functable[actfuncindex].paramtable[finder].vartype);
else if(gchecker!=-1)
strcpy((yyvsp[-2].vp).type,functable[0].vartable[gchecker].vartype);


if((yyvsp[0].vp).tempreg==-1)
{
CallError("Void function does not return anything.");
}
else if((yyvsp[0].vp).tempreg==-2)
{
CallError("Some error in assignment.");
}
else
{
char printer[1000];
if(!strcmp((yyvsp[0].vp).type,"int"))
{
if(!strcmp((yyvsp[-2].vp).type,"int"))
{
if(checker!=-1){}

else if(finder!=-1){}

else{}


releaseint((yyvsp[0].vp).tempreg);

}
else
{
int gettemp=newfloat();

GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);
if(checker!=-1){}

else if(finder!=-1){}

else{}


releasefloat(gettemp);
}
}
if(!strcmp((yyvsp[0].vp).type,"float"))
{
if(!strcmp((yyvsp[-2].vp).type,"float"))
{
if(checker!=-1){}

else if(finder!=-1){}

else{}


releasefloat((yyvsp[0].vp).tempreg);

}
else
{
int gettemp=newint();

GenQuad(printer);
releasefloat((yyvsp[0].vp).tempreg);
if(checker!=-1){}

else if(finder!=-1){}

else{}


releaseint(gettemp);

}
}
GenQuad(printer);
}

}
#line 2551 "parser.tab.c"
    break;

  case 79: /* FORASSIGN: ARRF EQ COR  */
#line 1099 "parser.y"
                 {
backpatch((yyvsp[0].vp).bplist,(yyvsp[0].vp).bpcount,nextquad);
if((yyvsp[-2].vp).arr!=-1 && (yyvsp[-2].vp).ind!=-1)
{
if((yyvsp[0].vp).tempreg==-1)
{
CallError("Void function does not return anything.");
}
else if((yyvsp[0].vp).tempreg==-2)
{
CallError("Some error in assignment.");

}
else
{
char printer[1000];
if(!strcmp((yyvsp[0].vp).type,"int"))
{
if(!strcmp((yyvsp[-2].vp).type,"int"))
{

releaseint((yyvsp[0].vp).tempreg);

}
else
{
int gettemp=newfloat();

GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);



releasefloat(gettemp);
}
}
if(!strcmp((yyvsp[0].vp).type,"float"))
{
if(!strcmp((yyvsp[-2].vp).type,"float"))
{



releasefloat((yyvsp[0].vp).tempreg);

}
else
{
int gettemp=newint();

GenQuad(printer);
releasefloat((yyvsp[0].vp).tempreg);



releaseint(gettemp);

}
}
GenQuad(printer);
releaseint((yyvsp[-2].vp).arr);
releaseint((yyvsp[-2].vp).ind);
}
}
}
#line 2621 "parser.tab.c"
    break;

  case 80: /* ASSIGN: ID EQ COR SC  */
#line 1165 "parser.y"
                            {
backpatch((yyvsp[-1].vp).bplist,(yyvsp[-1].vp).bpcount,nextquad);
int finder;
int checker,gchecker;
finder = InArr(functable[actfuncindex].paramtable,functable[actfuncindex].paramcount,(yyvsp[-3].vp).vali);
checker = InArr(functable[actfuncindex].vartable,functable[actfuncindex].varcount,(yyvsp[-3].vp).vali);
gchecker = InArr(functable[0].vartable,functable[0].varcount,(yyvsp[-3].vp).vali);

if(checker==-1 && finder==-1 && gchecker==-1)
{
char printer[1000];

CallError(printer);
}
if(checker!=-1)
strcpy((yyvsp[-3].vp).type,functable[actfuncindex].vartable[checker].vartype);
else if (finder!=-1)
strcpy((yyvsp[-3].vp).type,functable[actfuncindex].paramtable[finder].vartype);
else if(gchecker!=-1)
strcpy((yyvsp[-3].vp).type,functable[0].vartable[gchecker].vartype);


if((yyvsp[-1].vp).tempreg==-1)
{
CallError("Void function does not return anything.");
}
else if((yyvsp[-1].vp).tempreg==-2)
{
CallError("Some error in assignment.");
}
else
{
char printer[1000];
if(!strcmp((yyvsp[-1].vp).type,"int"))
{
if(!strcmp((yyvsp[-3].vp).type,"int"))
{
if(checker!=-1){}

else if(finder!=-1){}

else{}


releaseint((yyvsp[-1].vp).tempreg);

}
else
{
int gettemp=newfloat();

GenQuad(printer);
releaseint((yyvsp[-1].vp).tempreg);
if(checker!=-1){}

else if(finder!=-1){}

else{}


releasefloat(gettemp);
}
}
if(!strcmp((yyvsp[-1].vp).type,"float"))
{
if(!strcmp((yyvsp[-3].vp).type,"float"))
{
if(checker!=-1){}

else if(finder!=-1){}

else{}


releasefloat((yyvsp[-1].vp).tempreg);

}
else
{
int gettemp=newint();

GenQuad(printer);
releasefloat((yyvsp[-1].vp).tempreg);
if(checker!=-1){}

else if(finder!=-1){}

else{}


releaseint(gettemp);

}
}
GenQuad(printer);
}

}
#line 2724 "parser.tab.c"
    break;

  case 81: /* ASSIGN: ARRF EQ COR SC  */
#line 1263 "parser.y"
                     {
backpatch((yyvsp[-1].vp).bplist,(yyvsp[-1].vp).bpcount,nextquad);
if((yyvsp[-3].vp).arr!=-1 && (yyvsp[-3].vp).ind!=-1)
{
if((yyvsp[-1].vp).tempreg==-1)
{
CallError("Void function does not return anything.");
}
else if((yyvsp[-1].vp).tempreg==-2)
{
CallError("Some error in assignment.");

}
else
{
char printer[1000];
if(!strcmp((yyvsp[-1].vp).type,"int"))
{
if(!strcmp((yyvsp[-3].vp).type,"int"))
{

releaseint((yyvsp[-1].vp).tempreg);

}
else
{
int gettemp=newfloat();

GenQuad(printer);
releaseint((yyvsp[-1].vp).tempreg);




releasefloat(gettemp);
}
}
if(!strcmp((yyvsp[-1].vp).type,"float"))
{
if(!strcmp((yyvsp[-3].vp).type,"float"))
{



releasefloat((yyvsp[-1].vp).tempreg);

}
else
{
int gettemp=newint();

GenQuad(printer);
releasefloat((yyvsp[-1].vp).tempreg);



releaseint(gettemp);

}
}
GenQuad(printer);
releaseint((yyvsp[-3].vp).arr);
releaseint((yyvsp[-3].vp).ind);
}
}
}
#line 2795 "parser.tab.c"
    break;

  case 82: /* COR: COR OR CAND  */
#line 1331 "parser.y"
                                {
backpatch((yyvsp[0].vp).bplist,(yyvsp[0].vp).bpcount,nextquad);
if((yyvsp[-2].vp).countor==0)
{
(yyval.vp).countor=1;

int gettemp;
gettemp=newint();
char printer[1000];

GenQuad(printer);
int temp2=(yyvsp[-2].vp).tempreg;
if(!strcmp((yyvsp[-2].vp).type,"float"))
{
temp2=newint();

releasefloat((yyvsp[-2].vp).tempreg);
GenQuad(printer);
}


GenQuad(printer);

GenQuad(printer);

(yyvsp[-2].vp).bpcount=0;
(yyvsp[-2].vp).bplist[(yyvsp[-2].vp).bpcount++]=nextquad;
GenQuad(printer);
releaseint(temp2);
releaseint((yyvsp[-2].vp).tempreg);
(yyvsp[-2].vp).tempreg=gettemp;
}
int getcase = GiveType((yyvsp[-2].vp).type,(yyvsp[0].vp).type);
if(getcase==0)
strcpy((yyval.vp).type,"errortype");
else
strcpy((yyval.vp).type,"int");
(yyval.vp).caseallow=(yyvsp[-2].vp).caseallow && (yyvsp[0].vp).caseallow;


char printer[1000];
int temp2=(yyvsp[0].vp).tempreg;
if(!strcmp((yyvsp[0].vp).type,"float"))
{
temp2=newint();

releasefloat((yyvsp[0].vp).tempreg);
GenQuad(printer);
}


GenQuad(printer);

GenQuad(printer);

(yyval.vp).bpcount=0;

for(int i=0;i<(yyvsp[-2].vp).bpcount;i++)
{
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[-2].vp).bplist[i];
}
(yyval.vp).bplist[(yyval.vp).bpcount++]=nextquad;

GenQuad(printer);
releaseint(temp2);
releaseint((yyvsp[0].vp).tempreg);
(yyval.vp).tempreg=(yyvsp[-2].vp).tempreg;

}
#line 2869 "parser.tab.c"
    break;

  case 83: /* COR: CAND  */
#line 1400 "parser.y"
         {

backpatch((yyvsp[0].vp).bplist,(yyvsp[0].vp).bpcount,nextquad);
(yyval.vp).bpcount=0;
strcpy((yyval.vp).type,(yyvsp[0].vp).type);
(yyval.vp).caseallow=(yyvsp[0].vp).caseallow;
(yyval.vp).tempreg=(yyvsp[0].vp).tempreg;
(yyval.vp).countor=0;


}
#line 2885 "parser.tab.c"
    break;

  case 84: /* CAND: CAND AND CNOT  */
#line 1412 "parser.y"
                       {
if((yyvsp[-2].vp).countand==0)
{
(yyval.vp).countand=1;
int gettemp;
gettemp=newint();
char printer[1000];

GenQuad(printer);

int temp2=(yyvsp[-2].vp).tempreg;
if(!strcmp((yyvsp[-2].vp).type,"float"))
{
temp2=newint();

releasefloat((yyvsp[-2].vp).tempreg);
GenQuad(printer);
}



GenQuad(printer);

GenQuad(printer);


(yyvsp[-2].vp).bpcount=0;
(yyvsp[-2].vp).bplist[(yyvsp[-2].vp).bpcount++]=nextquad;
GenQuad(printer);
releaseint(temp2);
releaseint((yyvsp[-2].vp).tempreg);
(yyvsp[-2].vp).tempreg=gettemp;
}
int getcase = GiveType((yyvsp[-2].vp).type,(yyvsp[0].vp).type);
if(getcase==0)
strcpy((yyval.vp).type,"errortype");
else
strcpy((yyval.vp).type,"int");
(yyval.vp).caseallow=(yyvsp[-2].vp).caseallow && (yyvsp[0].vp).caseallow;

char printer[1000];
int temp2=(yyvsp[0].vp).tempreg;
if(!strcmp((yyvsp[0].vp).type,"float"))
{
temp2=newint();

releasefloat((yyvsp[0].vp).tempreg);
GenQuad(printer);
}


GenQuad(printer);

GenQuad(printer);

(yyval.vp).bpcount=0;
for(int i=0;i<(yyvsp[-2].vp).bpcount;i++)
{
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[-2].vp).bplist[i];
}
(yyval.vp).bplist[(yyval.vp).bpcount++]=nextquad;

GenQuad(printer);
releaseint(temp2);
releaseint((yyvsp[0].vp).tempreg);
(yyval.vp).tempreg=(yyvsp[-2].vp).tempreg;



}
#line 2960 "parser.tab.c"
    break;

  case 85: /* CAND: CNOT  */
#line 1482 "parser.y"
                        {
(yyval.vp).bpcount=0;
strcpy((yyval.vp).type,(yyvsp[0].vp).type);
(yyval.vp).caseallow=(yyvsp[0].vp).caseallow;
(yyval.vp).tempreg=(yyvsp[0].vp).tempreg;
(yyval.vp).countand=0;


}
#line 2974 "parser.tab.c"
    break;

  case 86: /* CNOT: ECOMP  */
#line 1492 "parser.y"
               {
strcpy((yyval.vp).type,(yyvsp[0].vp).type);
(yyval.vp).caseallow=(yyvsp[0].vp).caseallow;
(yyval.vp).tempreg=(yyvsp[0].vp).tempreg;


}
#line 2986 "parser.tab.c"
    break;

  case 87: /* CNOT: NOT ECOMP  */
#line 1499 "parser.y"
            {
if(!strcmp((yyvsp[-1].vp).type,"errortype"))
strcpy((yyval.vp).type,"errortype");
else
strcpy((yyval.vp).type,"int");
(yyval.vp).caseallow=(yyvsp[0].vp).caseallow;

int gettemp;
gettemp=newint();
char printer[1000];

GenQuad(printer);
int temp2=(yyvsp[0].vp).tempreg;
if(!strcmp((yyvsp[0].vp).type,"float"))
{
temp2=newint();

releasefloat((yyvsp[0].vp).tempreg);
GenQuad(printer);
}


GenQuad(printer);

GenQuad(printer);
releaseint(temp2);
releaseint((yyvsp[0].vp).tempreg);
(yyval.vp).tempreg=gettemp;
}
#line 3020 "parser.tab.c"
    break;

  case 88: /* ECOMP: ECOMP LT E  */
#line 1529 "parser.y"
                                {
int getcase = GiveType((yyvsp[-2].vp).type,(yyvsp[0].vp).type);
if(getcase==0)
strcpy((yyval.vp).type,"errortype");
else
strcpy((yyval.vp).type,"int");
(yyval.vp).caseallow=(yyvsp[-2].vp).caseallow && (yyvsp[0].vp).caseallow;
int gettemp;
if(getcase==1)
{
if(!strcmp((yyvsp[-2].vp).type,"int"))
{
int gettemp2;
gettemp2 = newfloat();
char printer[1000];

GenQuad(printer);
releaseint((yyvsp[-2].vp).tempreg);
gettemp = newint();

GenQuad(printer);


GenQuad(printer);

GenQuad(printer);
releasefloat(gettemp2);
releasefloat((yyvsp[0].vp).tempreg);
}
else if(!strcmp((yyvsp[0].vp).type,"int"))
{
int gettemp2;
gettemp2 = newfloat();
char printer[1000];

GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);
gettemp = newint();

GenQuad(printer);


GenQuad(printer);

GenQuad(printer);
releasefloat(gettemp2);
releasefloat((yyvsp[-2].vp).tempreg);
}
else
{
char printer[1000];
gettemp = newint();

GenQuad(printer);


GenQuad(printer);

GenQuad(printer);
releasefloat((yyvsp[-2].vp).tempreg);
releasefloat((yyvsp[0].vp).tempreg);
}


}

else if(getcase==2)
{
gettemp = newint();
char printer[1000];

GenQuad(printer);


GenQuad(printer);

GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);
releaseint((yyvsp[-2].vp).tempreg);
}
(yyval.vp).tempreg=gettemp;
}
#line 3107 "parser.tab.c"
    break;

  case 89: /* ECOMP: ECOMP LTE E  */
#line 1611 "parser.y"
                {
int getcase = GiveType((yyvsp[-2].vp).type,(yyvsp[0].vp).type);
if(getcase==0)
strcpy((yyval.vp).type,"errortype");
else
strcpy((yyval.vp).type,"int");
(yyval.vp).caseallow=(yyvsp[-2].vp).caseallow && (yyvsp[0].vp).caseallow;

int gettemp;
if(getcase==1)
{
if(!strcmp((yyvsp[-2].vp).type,"int"))
{
int gettemp2;
gettemp2 = newfloat();
char printer[1000];

GenQuad(printer);
releaseint((yyvsp[-2].vp).tempreg);
gettemp = newint();

GenQuad(printer);


GenQuad(printer);

GenQuad(printer);
releasefloat(gettemp2);
releasefloat((yyvsp[0].vp).tempreg);
}
else if(!strcmp((yyvsp[0].vp).type,"int"))
{
int gettemp2;
gettemp2 = newfloat();
char printer[1000];

GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);
gettemp = newint();

GenQuad(printer);


GenQuad(printer);

GenQuad(printer);
releasefloat(gettemp2);
releasefloat((yyvsp[-2].vp).tempreg);
}
else
{
char printer[1000];
gettemp = newint();

GenQuad(printer);


GenQuad(printer);

GenQuad(printer);
releasefloat((yyvsp[-2].vp).tempreg);
releasefloat((yyvsp[0].vp).tempreg);
}


}

else if(getcase==2)
{
gettemp = newint();
char printer[1000];

GenQuad(printer);


GenQuad(printer);

GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);
releaseint((yyvsp[-2].vp).tempreg);
}
(yyval.vp).tempreg=gettemp;

}
#line 3196 "parser.tab.c"
    break;

  case 90: /* ECOMP: ECOMP GT E  */
#line 1695 "parser.y"
             {
int getcase = GiveType((yyvsp[-2].vp).type,(yyvsp[0].vp).type);
if(getcase==0)
strcpy((yyval.vp).type,"errortype");
else
strcpy((yyval.vp).type,"int");
(yyval.vp).caseallow=(yyvsp[-2].vp).caseallow && (yyvsp[0].vp).caseallow;

int gettemp;
if(getcase==1)
{
if(!strcmp((yyvsp[-2].vp).type,"int"))
{
int gettemp2;
gettemp2 = newfloat();
char printer[1000];

GenQuad(printer);
releaseint((yyvsp[-2].vp).tempreg);
gettemp = newint();

GenQuad(printer);


GenQuad(printer);

GenQuad(printer);
releasefloat(gettemp2);
releasefloat((yyvsp[0].vp).tempreg);
}
else if(!strcmp((yyvsp[0].vp).type,"int"))
{
int gettemp2;
gettemp2 = newfloat();
char printer[1000];

GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);
gettemp = newint();

GenQuad(printer);


GenQuad(printer);

GenQuad(printer);
releasefloat(gettemp2);
releasefloat((yyvsp[-2].vp).tempreg);
}
else
{
char printer[1000];
gettemp = newint();

GenQuad(printer);


GenQuad(printer);

GenQuad(printer);
releasefloat((yyvsp[-2].vp).tempreg);
releasefloat((yyvsp[0].vp).tempreg);
}



}

else if(getcase==2)
{
gettemp = newint();
char printer[1000];

GenQuad(printer);


GenQuad(printer);

GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);
releaseint((yyvsp[-2].vp).tempreg);
}
(yyval.vp).tempreg=gettemp;

}
#line 3286 "parser.tab.c"
    break;

  case 91: /* ECOMP: ECOMP GTE E  */
#line 1780 "parser.y"
                        {
int getcase = GiveType((yyvsp[-2].vp).type,(yyvsp[0].vp).type);
if(getcase==0)
strcpy((yyval.vp).type,"errortype");
else
strcpy((yyval.vp).type,"int");
(yyval.vp).caseallow=(yyvsp[-2].vp).caseallow && (yyvsp[0].vp).caseallow;

int gettemp;
if(getcase==1)
{
if(!strcmp((yyvsp[-2].vp).type,"int"))
{
int gettemp2;
gettemp2 = newfloat();
char printer[1000];

GenQuad(printer);
releaseint((yyvsp[-2].vp).tempreg);
gettemp = newint();

GenQuad(printer);


GenQuad(printer);

GenQuad(printer);
releasefloat(gettemp2);
releasefloat((yyvsp[0].vp).tempreg);
}
else if(!strcmp((yyvsp[0].vp).type,"int"))
{
int gettemp2;
gettemp2 = newfloat();
char printer[1000];

GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);
gettemp = newint();

GenQuad(printer);


GenQuad(printer);

GenQuad(printer);
releasefloat(gettemp2);
releasefloat((yyvsp[-2].vp).tempreg);
}
else
{
char printer[1000];
gettemp = newint();

GenQuad(printer);


GenQuad(printer);

GenQuad(printer);
releasefloat((yyvsp[-2].vp).tempreg);
releasefloat((yyvsp[0].vp).tempreg);
}


}

else if(getcase==2)
{
gettemp = newint();
char printer[1000];

GenQuad(printer);


GenQuad(printer);

GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);
releaseint((yyvsp[-2].vp).tempreg);
}
(yyval.vp).tempreg=gettemp;

}
#line 3375 "parser.tab.c"
    break;

  case 92: /* ECOMP: ECOMP NEQ E  */
#line 1864 "parser.y"
                        {
int getcase = GiveType((yyvsp[-2].vp).type,(yyvsp[0].vp).type);
if(getcase==0)
strcpy((yyval.vp).type,"errortype");
else
strcpy((yyval.vp).type,"int");
(yyval.vp).caseallow=(yyvsp[-2].vp).caseallow && (yyvsp[0].vp).caseallow;

int gettemp;
if(getcase==1)
{
if(!strcmp((yyvsp[-2].vp).type,"int"))
{
int gettemp2;
gettemp2 = newfloat();
char printer[1000];

GenQuad(printer);
releaseint((yyvsp[-2].vp).tempreg);
gettemp = newint();

GenQuad(printer);


GenQuad(printer);
GenQuad(printer);
releasefloat(gettemp2);
releasefloat((yyvsp[0].vp).tempreg);
}
else if(!strcmp((yyvsp[0].vp).type,"int"))
{
int gettemp2;
gettemp2 = newfloat();
char printer[1000];
GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);
gettemp = newint();
GenQuad(printer);

GenQuad(printer);
GenQuad(printer);
releasefloat(gettemp2);
releasefloat((yyvsp[-2].vp).tempreg);
}
else
{
char printer[1000];
gettemp = newint();
GenQuad(printer);

GenQuad(printer);
GenQuad(printer);
releasefloat((yyvsp[-2].vp).tempreg);
releasefloat((yyvsp[0].vp).tempreg);
}


}

else if(getcase==2)
{
gettemp = newint();
char printer[1000];
GenQuad(printer);

GenQuad(printer);
GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);
releaseint((yyvsp[-2].vp).tempreg);
}
(yyval.vp).tempreg=gettemp;

}
#line 3453 "parser.tab.c"
    break;

  case 93: /* ECOMP: ECOMP EQEQ E  */
#line 1937 "parser.y"
                        {
int getcase = GiveType((yyvsp[-2].vp).type,(yyvsp[0].vp).type);
if(getcase==0)
strcpy((yyval.vp).type,"errortype");
else
strcpy((yyval.vp).type,"int");
(yyval.vp).caseallow=(yyvsp[-2].vp).caseallow && (yyvsp[0].vp).caseallow;

int gettemp;
if(getcase==1)
{
if(!strcmp((yyvsp[-2].vp).type,"int"))
{
int gettemp2;
gettemp2 = newfloat();
char printer[1000];
GenQuad(printer);
releaseint((yyvsp[-2].vp).tempreg);
gettemp = newint();
GenQuad(printer);

GenQuad(printer);
GenQuad(printer);
releasefloat(gettemp2);
releasefloat((yyvsp[0].vp).tempreg);
}
else if(!strcmp((yyvsp[0].vp).type,"int"))
{
int gettemp2;
gettemp2 = newfloat();
char printer[1000];
GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);
gettemp = newint();
GenQuad(printer);

GenQuad(printer);
GenQuad(printer);
releasefloat(gettemp2);
releasefloat((yyvsp[-2].vp).tempreg);
}
else
{
char printer[1000];
gettemp = newint();
GenQuad(printer);

GenQuad(printer);
GenQuad(printer);
releasefloat((yyvsp[-2].vp).tempreg);
releasefloat((yyvsp[0].vp).tempreg);
}


}

else if(getcase==2)
{
gettemp = newint();
char printer[1000];
GenQuad(printer);

GenQuad(printer);
GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);
releaseint((yyvsp[-2].vp).tempreg);
}
(yyval.vp).tempreg=gettemp;

}
#line 3528 "parser.tab.c"
    break;

  case 94: /* ECOMP: E  */
#line 2007 "parser.y"
    {
strcpy((yyval.vp).type,(yyvsp[0].vp).type);
(yyval.vp).tempreg=(yyvsp[0].vp).tempreg;
(yyval.vp).caseallow=(yyvsp[0].vp).caseallow;

}
#line 3539 "parser.tab.c"
    break;

  case 95: /* E: E PLUS T  */
#line 2014 "parser.y"
                                {
int gettemp;

int getcase = GiveType((yyvsp[-2].vp).type,(yyvsp[0].vp).type);
if(getcase==0)
strcpy((yyval.vp).type,"errortype");
if(getcase==1){
strcpy((yyval.vp).type,"float");
if(!strcmp((yyvsp[-2].vp).type,"int"))
{
int gettemp2;
gettemp2 = newfloat();
char printer[1000];





GenQuad(printer);

releaseint((yyvsp[-2].vp).tempreg);

gettemp = newfloat();
GenQuad(printer);
releasefloat(gettemp2);
releasefloat((yyvsp[0].vp).tempreg);



}
else if(!strcmp((yyvsp[0].vp).type,"int"))
{
int gettemp2;
gettemp2 = newfloat();
char printer[1000];
GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);

gettemp = newfloat();

GenQuad(printer);
releasefloat(gettemp2);
releasefloat((yyvsp[-2].vp).tempreg);

}
else
{
gettemp=newfloat();
char printer[1000];
GenQuad(printer);
releasefloat((yyvsp[0].vp).tempreg);
releasefloat((yyvsp[-2].vp).tempreg);
}
}
if(getcase==2){
strcpy((yyval.vp).type,"int");
gettemp = newint();
char printer[1000];

GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);
releaseint((yyvsp[-2].vp).tempreg);

}
(yyval.vp).tempreg = gettemp;
(yyval.vp).caseallow=(yyvsp[-2].vp).caseallow && (yyvsp[0].vp).caseallow;


}
#line 3613 "parser.tab.c"
    break;

  case 96: /* E: E MINUS T  */
#line 2083 "parser.y"
            {
int gettemp;

int getcase = GiveType((yyvsp[-2].vp).type,(yyvsp[0].vp).type);
if(getcase==0)
strcpy((yyval.vp).type,"errortype");
if(getcase==1){
strcpy((yyval.vp).type,"float");
if(!strcmp((yyvsp[-2].vp).type,"int"))
{
int gettemp2;
gettemp2 = newfloat();
char printer[1000];





GenQuad(printer);

releaseint((yyvsp[-2].vp).tempreg);

gettemp = newfloat();
GenQuad(printer);
releasefloat(gettemp2);
releasefloat((yyvsp[0].vp).tempreg);



}
else if(!strcmp((yyvsp[0].vp).type,"int"))
{
int gettemp2;
gettemp2 = newfloat();
char printer[1000];
GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);

gettemp = newfloat();

GenQuad(printer);
releasefloat(gettemp2);
releasefloat((yyvsp[-2].vp).tempreg);

}
else
{
gettemp=newfloat();
char printer[1000];
GenQuad(printer);
releasefloat((yyvsp[0].vp).tempreg);
releasefloat((yyvsp[-2].vp).tempreg);
}
}
if(getcase==2){
strcpy((yyval.vp).type,"int");
gettemp = newint();
char printer[1000];

GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);
releaseint((yyvsp[-2].vp).tempreg);

}
(yyval.vp).tempreg = gettemp;
(yyval.vp).caseallow=(yyvsp[-2].vp).caseallow && (yyvsp[0].vp).caseallow;


}
#line 3687 "parser.tab.c"
    break;

  case 97: /* E: T  */
#line 2152 "parser.y"
    {
strcpy((yyval.vp).type,(yyvsp[0].vp).type);
(yyval.vp).tempreg=(yyvsp[0].vp).tempreg;
(yyval.vp).caseallow=(yyvsp[0].vp).caseallow;

}
#line 3698 "parser.tab.c"
    break;

  case 98: /* T: T MULT F  */
#line 2159 "parser.y"
             {
int gettemp;

int getcase = GiveType((yyvsp[-2].vp).type,(yyvsp[0].vp).type);
if(getcase==0)
strcpy((yyval.vp).type,"errortype");
if(getcase==1){
strcpy((yyval.vp).type,"float");
if(!strcmp((yyvsp[-2].vp).type,"int"))
{
int gettemp2;
gettemp2 = newfloat();
char printer[1000];





GenQuad(printer);

releaseint((yyvsp[-2].vp).tempreg);

gettemp = newfloat();
GenQuad(printer);
releasefloat(gettemp2);
releasefloat((yyvsp[0].vp).tempreg);



}
else if(!strcmp((yyvsp[0].vp).type,"int"))
{
int gettemp2;
gettemp2 = newfloat();
char printer[1000];
GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);

gettemp = newfloat();

GenQuad(printer);
releasefloat(gettemp2);
releasefloat((yyvsp[-2].vp).tempreg);

}
else
{
gettemp=newfloat();
char printer[1000];
GenQuad(printer);
releasefloat((yyvsp[0].vp).tempreg);
releasefloat((yyvsp[-2].vp).tempreg);
}
}
if(getcase==2){
strcpy((yyval.vp).type,"int");
gettemp = newint();
char printer[1000];

GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);
releaseint((yyvsp[-2].vp).tempreg);

}
(yyval.vp).tempreg = gettemp;
(yyval.vp).caseallow=(yyvsp[-2].vp).caseallow && (yyvsp[0].vp).caseallow;





}
#line 3775 "parser.tab.c"
    break;

  case 99: /* T: T DIV F  */
#line 2231 "parser.y"
                            {
int gettemp;

int getcase = GiveType((yyvsp[-2].vp).type,(yyvsp[0].vp).type);
if(getcase==0)
strcpy((yyval.vp).type,"errortype");
if(getcase==1){
strcpy((yyval.vp).type,"float");
if(!strcmp((yyvsp[-2].vp).type,"int"))
{
int gettemp2;
gettemp2 = newfloat();
char printer[1000];





GenQuad(printer);

releaseint((yyvsp[-2].vp).tempreg);

gettemp = newfloat();
GenQuad(printer);
releasefloat(gettemp2);
releasefloat((yyvsp[0].vp).tempreg);



}
else if(!strcmp((yyvsp[0].vp).type,"int"))
{
int gettemp2;
gettemp2 = newfloat();
char printer[1000];
GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);

gettemp = newfloat();

GenQuad(printer);
releasefloat(gettemp2);
releasefloat((yyvsp[-2].vp).tempreg);

}
else
{
gettemp=newfloat();
char printer[1000];
GenQuad(printer);
releasefloat((yyvsp[0].vp).tempreg);
releasefloat((yyvsp[-2].vp).tempreg);
}
}
if(getcase==2){
strcpy((yyval.vp).type,"int");
gettemp = newint();
char printer[1000];

GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);
releaseint((yyvsp[-2].vp).tempreg);

}
(yyval.vp).tempreg = gettemp;
(yyval.vp).caseallow=(yyvsp[-2].vp).caseallow && (yyvsp[0].vp).caseallow;


}
#line 3849 "parser.tab.c"
    break;

  case 100: /* T: T MOD F  */
#line 2300 "parser.y"
          {
int gettemp;

int getcase = GiveType((yyvsp[-2].vp).type,(yyvsp[0].vp).type);
if(getcase==0)
strcpy((yyval.vp).type,"errortype");
if(getcase==1){
strcpy((yyval.vp).type,"float");
if(!strcmp((yyvsp[-2].vp).type,"int"))
{
int gettemp2;
gettemp2 = newfloat();
char printer[1000];





GenQuad(printer);

releaseint((yyvsp[-2].vp).tempreg);

gettemp = newfloat();
GenQuad(printer);
releasefloat(gettemp2);
releasefloat((yyvsp[0].vp).tempreg);



}
else if(!strcmp((yyvsp[0].vp).type,"int"))
{
int gettemp2;
gettemp2 = newfloat();
char printer[1000];
GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);

gettemp = newfloat();

GenQuad(printer);
releasefloat(gettemp2);
releasefloat((yyvsp[-2].vp).tempreg);

}
else
{
gettemp=newfloat();
char printer[1000];
GenQuad(printer);
releasefloat((yyvsp[0].vp).tempreg);
releasefloat((yyvsp[-2].vp).tempreg);
}
}
if(getcase==2){
strcpy((yyval.vp).type,"int");
gettemp = newint();
char printer[1000];

GenQuad(printer);
releaseint((yyvsp[0].vp).tempreg);
releaseint((yyvsp[-2].vp).tempreg);

}
(yyval.vp).tempreg = gettemp;
(yyval.vp).caseallow=(yyvsp[-2].vp).caseallow && (yyvsp[0].vp).caseallow;

}
#line 3922 "parser.tab.c"
    break;

  case 101: /* T: F  */
#line 2369 "parser.y"
    {
strcpy((yyval.vp).type,(yyvsp[0].vp).type);
(yyval.vp).tempreg=(yyvsp[0].vp).tempreg;
(yyval.vp).caseallow=(yyvsp[0].vp).caseallow;


}
#line 3934 "parser.tab.c"
    break;

  case 102: /* F: ID  */
#line 2377 "parser.y"
       {
int find = InArr(functable[actfuncindex].vartable,functable[actfuncindex].varcount,(yyvsp[0].vp).vali);
int pfind = InArr(functable[actfuncindex].paramtable,functable[actfuncindex].paramcount,(yyvsp[0].vp).vali);
int gfind = InArr(functable[0].vartable,functable[0].varcount,(yyvsp[0].vp).vali);

if(find==-1 && pfind==-1 && gfind==-1)
{
char printer1[1000];
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

GenQuad(printer);
}
else
{
gettemp = newfloat();

char printer[1000];
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
GenQuad(printer);


}
else
{
gettemp = newfloat();
char printer[1000];
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

GenQuad(printer);
}
else
{
gettemp = newfloat();

char printer[1000];
GenQuad(printer);
}
}
(yyval.vp).tempreg=gettemp;

}
(yyval.vp).caseallow=false;
}
#line 4031 "parser.tab.c"
    break;

  case 103: /* F: NUM  */
#line 2470 "parser.y"
      {
int gettemp;
int t = strlen((yyvsp[0].vp).vali);
int i=0;
bool isf=false;
for(i=0;i<t;i++)
{
if((yyvsp[0].vp).vali[i]=='.')
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
GenQuad(printer);


}
else
{
strcpy((yyval.vp).type,"int");
gettemp = newint();

char printer[1000];
GenQuad(printer);
}
(yyval.vp).tempreg=gettemp;

(yyval.vp).caseallow=true;



}
#line 4074 "parser.tab.c"
    break;

  case 104: /* F: FUNC_CALL  */
#line 2508 "parser.y"
            {
strcpy((yyval.vp).type,(yyvsp[0].vp).type);
(yyval.vp).tempreg=(yyvsp[0].vp).tempreg;

if((yyval.vp).tempreg==-1)
{
CallError("Void Function does not return anything.");
}
(yyval.vp).caseallow=false;



}
#line 4092 "parser.tab.c"
    break;

  case 105: /* F: OPT COR CPT  */
#line 2521 "parser.y"
              {
strcpy((yyval.vp).type,(yyvsp[-1].vp).type);
(yyval.vp).tempreg=(yyvsp[-1].vp).tempreg;

(yyval.vp).caseallow=(yyvsp[-1].vp).caseallow;
backpatch((yyvsp[-1].vp).bplist,(yyvsp[-1].vp).bpcount,nextquad);


}
#line 4106 "parser.tab.c"
    break;

  case 106: /* F: ARRF  */
#line 2530 "parser.y"
         {
int tempreg=-2;
char printer[1000];

if((yyvsp[0].vp).arr!=-1 && (yyvsp[0].vp).ind!=-1)
{
if(!strcmp((yyvsp[0].vp).type,"int"))
{
tempreg = newint();
GenQuad(printer);
releaseint((yyvsp[0].vp).arr);
releaseint((yyvsp[0].vp).ind);
}
else if(!strcmp((yyvsp[0].vp).type,"float"))
{
tempreg = newfloat();
GenQuad(printer);
releaseint((yyvsp[0].vp).arr);
releaseint((yyvsp[0].vp).ind);
}
}
strcpy((yyval.vp).type,(yyvsp[0].vp).type);
(yyval.vp).tempreg=tempreg;
(yyval.vp).caseallow=false;

}
#line 4137 "parser.tab.c"
    break;

  case 107: /* ARRF: ID ARRFLIST  */
#line 2559 "parser.y"
                   {
(yyval.vp).arr=-1;
(yyval.vp).ind=-1;
strcpy((yyval.vp).type,"errortype");


int find = InArr(functable[actfuncindex].vartable,functable[actfuncindex].varcount,(yyvsp[-1].vp).vali);
int gfind = InArr(functable[0].vartable,functable[0].varcount,(yyvsp[-1].vp).vali);

if(find==-1 && gfind==-1)
{
char printer1[1000];
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
if(functable[actfuncindex].vartable[find].dimcount!=(yyvsp[0].vp).bpcount)
{
CallError("Number of dimensions not matching in array use.");
}
else
{
int getarr = newint();
char printer[1000];
GenQuad(printer);

int getindex = newint();
int extra = newint();

GenQuad(printer);

for(int i=0;i<(yyvsp[0].vp).bpcount;i++)
{
GenQuad(printer);

releaseint((yyvsp[0].vp).bplist[i]);
GenQuad(printer);

GenQuad(printer);
}

GenQuad(printer);
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
if(functable[0].vartable[gfind].dimcount!=(yyvsp[0].vp).bpcount)
{
CallError("Number of dimensions not matching in array use.");
}
else
{
int getarr = newint();
char printer[1000];
GenQuad(printer);

int getindex = newint();
int extra = newint();

GenQuad(printer);

for(int i=0;i<(yyvsp[0].vp).bpcount;i++)
{
GenQuad(printer);

releaseint((yyvsp[0].vp).bplist[i]);
GenQuad(printer);

GenQuad(printer);
}

GenQuad(printer);
GenQuad(printer);

releaseint(extra);

(yyval.vp).arr=getarr;
(yyval.vp).ind=getindex;
strcpy((yyval.vp).type,functable[0].vartable[gfind].vartype);
}
}
}
}
#line 4247 "parser.tab.c"
    break;

  case 108: /* ARRFLIST: ARRFLIST OSQ COR CSQ  */
#line 2666 "parser.y"
                                    {
backpatch((yyvsp[-1].vp).bplist,(yyvsp[-1].vp).bpcount,nextquad);
if(strcmp((yyvsp[-1].vp).type,"int"))
{
CallError("Array indices should compute to integers.");
}
(yyval.vp).bpcount=0;
for(int i=0;i<(yyvsp[-3].vp).bpcount;i++)
{
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[-3].vp).bplist[i];
}
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[-1].vp).tempreg;
}
#line 4265 "parser.tab.c"
    break;

  case 109: /* ARRFLIST: OSQ COR CSQ  */
#line 2679 "parser.y"
              {
backpatch((yyvsp[-1].vp).bplist,(yyvsp[-1].vp).bpcount,nextquad);
if(strcmp((yyvsp[-1].vp).type,"int"))
{
CallError("Array indices should compute to integers.");
}
(yyval.vp).bpcount=0;

(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[-1].vp).tempreg;
}
#line 4280 "parser.tab.c"
    break;

  case 110: /* SWITCH: SWITCHET OCURLY CASES CCURLY  */
#line 2691 "parser.y"
                                      {

(yyval.vp).bpcount=0;
int i;
for(i=0;i<(yyvsp[-1].vp).bpcount;i++){
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[-1].vp).bplist[i];
}

}
#line 4294 "parser.tab.c"
    break;

  case 111: /* SWITCHET: SWITCHT OPT COR CPT  */
#line 2702 "parser.y"
                                {
canbreak++;
if(strcmp((yyvsp[-1].vp).type,"int"))
{
CallError("Switch should have integer resulting expression.");
}
backpatch((yyvsp[-1].vp).bplist,(yyvsp[-1].vp).bpcount,nextquad);
switchglobal=(yyvsp[-1].vp).tempreg;
}
#line 4308 "parser.tab.c"
    break;

  case 112: /* CASES: CASELIST MCASE DEFAULTE  */
#line 2712 "parser.y"
                                {
backpatch((yyvsp[-2].vp).bplist2,(yyvsp[-2].vp).bpcount2,(yyvsp[-1].vp).quad);
(yyval.vp).bpcount=0;


for(int i=0;i<(yyvsp[0].vp).bpcount;i++)
{
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[0].vp).bplist[i];
}

}
#line 4324 "parser.tab.c"
    break;

  case 113: /* CASES: CASELIST  */
#line 2723 "parser.y"
           {
(yyval.vp).bpcount=0;
for(int i=0;i<(yyvsp[0].vp).bpcount2;i++)
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[0].vp).bplist2[i];
}
#line 4334 "parser.tab.c"
    break;

  case 114: /* DEFAULTE: DEFAULT COLON SLIST  */
#line 2730 "parser.y"
                                 {
(yyval.vp).bpcount=0;
for(int i=0;i<(yyvsp[0].vp).bpcount;i++)
{
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[0].vp).bplist[i];
}

}
#line 4347 "parser.tab.c"
    break;

  case 115: /* CASELIST: CASELIST CASE  */
#line 2740 "parser.y"
                          {

backpatch((yyvsp[-1].vp).bplist2,(yyvsp[-1].vp).bpcount2,(yyvsp[0].vp).quad);
(yyval.vp).bpcount2=0;
for(int i=0;i<(yyvsp[0].vp).bpcount2;i++)
{
(yyval.vp).bplist2[(yyval.vp).bpcount2++]=(yyvsp[0].vp).bplist2[i];
}
 }
#line 4361 "parser.tab.c"
    break;

  case 116: /* CASELIST: CASE  */
#line 2749 "parser.y"
               {
 

(yyval.vp).bpcount2=0;
for(int i=0;i<(yyvsp[0].vp).bpcount2;i++)
{
(yyval.vp).bplist2[(yyval.vp).bpcount2++]=(yyvsp[0].vp).bplist2[i];
}
  }
#line 4375 "parser.tab.c"
    break;

  case 117: /* CASE: CASETEMP CMARK CBODY  */
#line 2759 "parser.y"
                            {


(yyval.vp).bpcount2=0;
backpatch((yyvsp[0].vp).bplist,(yyvsp[0].vp).bpcount,nextquad);
(yyval.vp).bplist2[(yyval.vp).bpcount2++]=nextquad;
char printer[1000];
GenQuad(printer);
backpatch((yyvsp[-2].vp).bplist,(yyvsp[-2].vp).bpcount,nextquad);


(yyval.vp).quad=(yyvsp[-1].vp).quad;
}
#line 4393 "parser.tab.c"
    break;

  case 118: /* CMARK: %empty  */
#line 2774 "parser.y"
        {(yyval.vp).quad=nextquad;}
#line 4399 "parser.tab.c"
    break;

  case 119: /* CASETEMP: CASET NCASE COR COLON  */
#line 2775 "parser.y"
                                       {

if(strcmp((yyvsp[-1].vp).type,"int"))
{
CallError("Case label does not reduce to an integer constant.");
}
else if(!((yyvsp[-1].vp).caseallow))
{
CallError("Case label should have only constant integer expressions.");
}
backpatch((yyvsp[-1].vp).bplist,(yyvsp[-1].vp).bpcount,nextquad);
char printer[1000];
(yyval.vp).bpcount=0;
(yyval.vp).bplist[(yyval.vp).bpcount++]=nextquad;
GenQuad(printer);
releaseint((yyvsp[-1].vp).tempreg);
}
#line 4421 "parser.tab.c"
    break;

  case 120: /* CBODY: SLIST  */
#line 2793 "parser.y"
                {
(yyval.vp).bpcount=0;
int i;
for(i=0;i<(yyvsp[0].vp).bpcount;i++)
(yyval.vp).bplist[(yyval.vp).bpcount++]=(yyvsp[0].vp).bplist[i];
}
#line 4432 "parser.tab.c"
    break;

  case 121: /* MCASE: %empty  */
#line 2800 "parser.y"
        {(yyval.vp).quad=nextquad;}
#line 4438 "parser.tab.c"
    break;


#line 4442 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 2804 "parser.y"


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
    char filename1[100];
    char filename2[100];


fil=fopen(filename,"r");

char new_name[1000];
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

return 0;
}
