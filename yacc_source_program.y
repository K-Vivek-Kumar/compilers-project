%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

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
%token id
%token env
%token arrow parrow
%token ints real bools point lineseg
%token integer floater
%token doll ddoll
%token call
%token check 
%token trues falses
%token and or lequal geq leq neq
%token recheck returns show


%left '(' ')'
%left '*' '/' '%'
%left '+' '-'
%left '&'
%left '^'
%left '|'
%left '<' '>' leq geq lequal neq
%right '~'


%%

PROGRAM:
    ENV MODULES
    ;

ENV:
    env ':' id ';'
    ;

MODULES:
    MODULE
    | MODULE MODULES
    ;

MODULE:
    FPART1 FPART2 arrow FPART3 FPART4
    ;

FPART1:
    id ':'
    ;

FPART2:
    '(' DLIST ')'
    | '(' ')'
    ;

DLIST:
    DTYPE id
    | DTYPE id ',' DLIST
    ;

DTYPE:
    ints
    | bools
    | real
    | point
    | lineseg
    ;


FPART3:
    '(' DTYPE ')'
    | '(' ')'
    ;

FPART4:
    '{' STATS '}'
    | '{' '}'
    ;

STATS:
    STAT
    | STAT STATS
    | returns EXP ';'
    ;

STAT:
    DECL
    | EQN
    | CALLS ';'
    | CHECK
    ;

CHECK:
    CHECK1
    | CHECK2
    ;

CHECK1:
    check '(' COND ')' '{' STATS '}' OCHECK ECHECK
    | check '(' COND ')' '{' '}' OCHECK ECHECK
    ;

OCHECK:
    | OCHECK ':' check '(' COND ')' '{' STATS '}'
    | OCHECK ':' check '(' COND ')' '{' '}'
    ;

ECHECK:
    | ':' '{' STATS '}'
    | ':' '{' '}'
    ;

COND:
    EXP
    | EXP CONJ EXP
    | '~' EXP
    ;

CHECK2:
    ;

EQN:
    id '=' EXP ';'
    ;

DECL:
    DTYPE id ';'
    | DTYPE id '=' EXP ';'
    ;

EXP:
    id
    | integer
    | floater
    | '(' EXP ')'
    | EXP BI EXP
    | UOF EXP
    | EXP UOB
    | CALLS
    | trues
    | falses
    | EXP CONJ EXP
    ;

CONJ:
    and
    | or
    | lequal
    | '>'
    | '<'
    | geq
    | leq
    | neq
    ;

CALLS:
    call id '(' GLIST ')'
    | call id '(' ')'
    ;

GLIST:
    EXP
    | EXP ',' GLIST
    ;

BI:
    '+'
    | '-'
    | '*'
    | '/'
    | '|'
    | parrow
    | '.'
    | '#'
    ;

UOF:
    '~'
    ;

UOB:
    doll
    | ddoll
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
