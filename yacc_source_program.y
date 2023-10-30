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
%token g1d g2d              // Environments
%token mains
%token arrow parrow
%token ints real bools point lineseg
%token integer floater
%token doll ddoll
%token call

%%

PROGRAM:
    ENVIRONMENT MODULES
    ;

ENVIRONMENT:
    env ':' g1d ';'                                 { fprintf(yyout, "Hello world"); }
    |   env ':' g2d ';'
    |   env ':' id ';'                              { fprintf(stderr, "Line %d: is an `Unknown Environment`.\n", lines); }
    ;

MODULES:
    PART1 PART3
    ;


PART1:
    id ':' PART2
    | mains ':'
    ;

PART2:
    '(' FLIST ')' arrow '(' RTYPE ')'
    ;

FLIST:
    RTYPE2 id
    | RTYPE2 id ',' FLIST
    ;

RTYPE:                  // Empty for void type functions
    | ints
    | bools
    | real
    | point
    | lineseg
    ;

RTYPE2:                 // For argument data-types
    ints
    | bools
    | real
    | point
    | lineseg
    ;

PART3:
    '{' STATEMENTS '}'
    ;

STATEMENTS:
    STATEMENT STATEMENTS
    ;

STATEMENT:
    | DST
    | AST
    | CHECK 
    ;

CHECK:
    PARTC1 PARTC2
    |
    ;

PARTC1:
    NCHECK PART3
    | NCHECK PART3 ':' PARTC1
    | NCHECK PART3 ':' PART3
    ;

NCHECK:
    id
    ;

PARTC2:
    id
    ;

AST:
    id '=' EXP ';'
    ;

DST:
    RTYPE2 id ';'
    | RTYPE2 id '=' EXP ';'
    ;

EXP:
    integer
    | floater
    | UI EXP
    | EXP UIB
    | EXP BI EXP
    | '(' EXP ')'
    | CALL
    ;

CALL:
    call id '(' ARGLIST ')'
    ;

ARGLIST:
    | ARGS
    ;

ARGS:
    EXP
    | EXP ',' ARGS
    ;

BI:
    '+'
    | '*'
    | '#'
    | '|'
    | '-'
    | '/'
    | parrow
    ;

UI:
    '~'
    | '-'
    ;

UIB:
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
    return 0;
}
