%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size_symtab 100
#define size_funtab 100

int current_function_index = -1;

typedef struct
{
    char *name;
    bool ptype;   // primitive or secondary
    char *pptype; // int or bool or real
    bool atype;   // array or not
    char *stype;  // if not array then point or lineseg or triangle or quad
    int size;     // if array then size
    int level;    // scope
} symtabrow;

typedef struct
{
    char *name;
    char *rtype; // Return type
    int noargs; // Number of Arguments
    char **argtypes;  // List of all argument types
    symtabrow fsymtable[size_symtab];
    int f_symtab_size;
} eachfun;

eachfun functiontable[size_funtab];

symtabrow symbol_table[size_symtab]; // FOr Global Variables
int symtabindex = 0;

extern FILE *yyin;
extern FILE *yyout;
extern int yylex();
FILE *output_file;

void yyerror(const char *msg);
extern int lines;

void INSERTVAR(char* fname, char *name, bool ptype, char *pptype, bool atype, char *stype, int size, int level)
{
    if (symbol_table_size >= size_symtab)
    {
        fprintf(stderr, "Symbol table is full. Cannot insert more entries.\n");
        exit(1);
    }
    symtabrow newEntry;
    newEntry.name = strdup(name);
    newEntry.ptype = ptype;
    newEntry.pptype = strdup(pptype);
    newEntry.atype = atype;
    newEntry.stype = strdup(stype);
    newEntry.size = size;
    newEntry.level = level;
    symbol_table[symbol_table_size++] = newEntry;
}

void INSERTFUN(char *fname, int noargs, char *rtype, char **argtypes) {
    if (current_function_index == -1) {
        fprintf(stderr, "Error: Function declared outside the function scope.\n");
        exit(1);
    }
    eachfun *current_function = &functiontable[current_function_index];
    for (int i = 0; i < current_function_index; i++) {
        if (strcmp(functiontable[i].name, fname) == 0) {
            fprintf(stderr, "Error: Function %s is already declared.\n", fname);
            exit(1);
        }
    }
    current_function->name = strdup(fname);
    current_function->rtype = strdup(rtype);
    current_function->noargs = noargs;

    current_function->argtypes = (char **)malloc(noargs * sizeof(char *));
    for (int i = 0; i < noargs; i++) {
        current_function->argtypes[i] = strdup(argtypes[i]);
    }
    for (int i = 0; i < size_symtab; i++) {
        current_function->fsymtable[i].name = NULL;
    }
}



bool CHECK(char *name)
{
    for (int i = 0; i < symtabindex; i++)
    {
        if (strcmp(symbol_table[i].name, name) == 0)
        {
            return true;
        }
    }
    return false;
}

void DELETE(char *fname) {
    for (int i = 0; i < size_symtab; i++) {
        functiontable[current_function_index].fsymtable[i].name = NULL;
    }
}

char **fargss;

%}

%union {
    char* strval;
    int numval;
    float floatval;
}

%start PROGRAM

%token mains id colon arrow comma intd reald boold pointd linesegd quadd trid pass integer floater trues falses origin pointsd
%token add minus multiply divide and or longeql nt geq leq lt gt neg
%token area intersection check elses loop commonarea perimeter distance reflection isparallel isquare isrectangle slope length

%%

PROGRAM:
    FUNCTIONS MAINS
    | MAINS
    ;

FUNCTIONS:
    FUNCTION
    | FUNCTION FUNCTIONS
    ;

FUNCTION:
    id colon '(' FPARTARGS ')' arrow '(' FPARTRETS ')' FBODY        {
        if($1 == main)
        current_function_index++;
    }
    ;

FPARTARGS:
    | ARGS
    ;

ARGS:
    ARG
    | ARG comma ARGS
    ;

ARG:
    PDATA id
    | SDATA id
    ;

PDATA:
    intd
    | reald
    | boold
    ;

SDATA:
    pointd
    | linesegd
    | quadd
    | trid
    | pointsd
    ;

FPARTRETS:
    | PDATA
    | SDATA
    ;

MAINS:
    mains FBODY
    ;

FBODY:
    '{' PSTATS '}'
    | '{' pass '}'
    ;

PSTATS:
    PSTAT
    | PSTAT PSTATS
    ;

PSTAT:
    DSTMTS
    | CSTMTS
    | IFSTMT
    | LOOPSTMT
    | EQN
    ;

EQN:
    id '=' GAR ';'
    | id '=' PTEXP ';'
    | id '=' LEXP ';'
    | id '=' TEXP ';'
    | id '=' QEXP ';'
    ;

LOOPSTMT:
    loop '(' GAR ')' FBODY
    ;

IFSTMT:
    IFPT1
    | IFPT1 IFPT2
    ;

IFPT1:
    IFEXP FBODY
    ;

IFEXP:
    check '(' GAR ')'
    ;

IFPT2:
    elses IFSTMT
    | elses FBODY
    ;

CSTMTS:
    id '(' ')' ';'
    | id '(' GARG ')' ';'
    ;

GARG:
    GAR
    | GAR comma GARG
    ;

GAR:
    id
    | CTS
    | BIEXP
    | UNEXP
    | '(' GAR ')'
    | FOPRS
    ;

CTS:
    integer
    | floater
    | trues
    | falses
    | origin
    ;

FOPRS:
    area '(' GAR ')'
    | area '(' QEXP ')'
    | area '(' TEXP ')'
    | intersection '(' GAR comma GAR ')'
    | commonarea '(' GAR comma GAR ')'
    | perimeter '(' GAR ')'
    | distance '(' GAR comma GAR ')'
    | isquare '(' GAR ')'
    | slope '(' GAR ')'
    | length '(' GAR ')'
    | isrectangle '(' GAR ')'
    | slope '(' GAR comma GAR ')'
    | isparallel '(' GAR comma GAR ')'
    | reflection '(' GAR comma GAR ')'
    ;

BIEXP:
    GAR add GAR
    | GAR minus GAR
    | GAR multiply GAR
    | GAR divide GAR
    | GAR and GAR
    | GAR or GAR
    | GAR longeql GAR
    | GAR geq GAR
    | GAR leq GAR
    | GAR gt GAR
    | GAR lt GAR
    | GAR nt GAR
    ;

UNEXP:
    neg GAR
    ;

DSTMTS:
    POINTD
    | POINTSD
    | LINED
    | TRID
    | QUAD
    | PRIMITIVE
    ;

POINTSD:
    pointsd id ';'
    | pointsd id '=' '{' PTS '}' ';'
    ;

PTS:
    PTEXP
    | PTEXP comma PTS
    ;

POINTD:
    pointd id ';'
    | pointd id '=' PTEXP ';'
    ;

PTEXP:
    id
    | '(' EXP comma EXP ')'
    ;

EXP:
    integer
    | floater
    | id
    ;

LINED:
    linesegd id ';'
    | linesegd id '=' LEXP ';'
    ;

LEXP:
    id
    | '(' PTEXP comma PTEXP ')'
    ;

TRID:
    trid id ';'
    | trid id '=' TEXP ';'
    ;

TEXP:
    id
    | '(' PTEXP comma PTEXP comma PTEXP ')'
    | '(' PTEXP comma LEXP ')'
    ;

QUAD:
    quadd id ';'
    | quadd id '=' QEXP ';'
    ;

QEXP:
    id
    | '(' PTEXP comma PTEXP comma PTEXP comma PTEXP ')'
    | '(' PTEXP comma PTEXP comma LEXP ')'
    | '(' LEXP comma LEXP ')'
    ;

PRIMITIVE:
    intd id ';'
    | intd id '=' integer ';'
    | reald id ';'
    | boold id ';'
    | reald id '=' floater ';'
    | boold id '=' trues ';'
    | boold id '=' falses ';'
    | boold id '=' integer ';'
    | boold id '=' floater ';'
    ;

%%

void yyerror(const char* msg) {
    fprintf(yyout, " : invalid statement");
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    char* input_file = argv[1];
    output_file = fopen("tokens.txt", "w");
    if (!output_file) {
        return 1;
    }
    yyin = fopen(input_file, "r");
    if (!yyin) {
        fclose(output_file);
        return 1;
    }
    yyout = fopen("svas.cpp", "w");
    if (!yyout) {
        fclose(yyin);
        fclose(output_file);
        return 1;
    }
    yyparse();
    fclose(yyin);
    fclose(output_file);
    fclose(yyout);
    return 0;
}
