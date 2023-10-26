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
}

%start PROGRAM
%token id
%token env
%token g1d g2d              // Environments

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
    id
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

