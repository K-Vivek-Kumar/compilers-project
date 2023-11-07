%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define size_symtab 100

    typedef struct {
        char *name;
        char *type;
        char *env;
        int level;
    } symtabrow;

    symtabrow symbol_table[size_symtab];
    int symtabindex = 0;

    extern FILE* yyin;
    extern FILE* yyout;
    extern int yylex();
    FILE* output_file;

    void yyerror(const char* msg);
    extern int lines;
%}

%union {
    char* strval;
    int numval;
    float floatval;
}

%start PROGRAM

%token mains id colon arrow comma intd reald boold pointd linesegd quadd trid pass integer floater trues falses origin
%token add minus multiply divide and or longeql nt geq leq lt gt neg
%token area intersection

%%

PROGRAM:
    FUNCTIONS MAINS
    | MAINS
    ;

FUNCTIONS:
    FUNCTION FUNCTIONS
    ;

FUNCTION:
    id colon FPARTARGS arrow FPARTRETS FBODY
    id colon '(' ')' arrow '(' ')' '{' '}'
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
    | intersection '(' GAR comma GAR ')'
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
    | LINED
    | TRID
    | QUAD
    | PRIMITIVE
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
    return 0;
}

