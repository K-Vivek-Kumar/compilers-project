%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

extern FILE *yyin;
extern FILE *yyout;
FILE *output_file;
extern int yylex();

void yyerror(const char *msg);

#define MAX_FUNCTIONS 100
#define MAX_ARGS 100

typedef struct {
    char *function_name;
    int number_of_arguments;
    struct Arg *arg_list;
    int r_type;
} each_function;

each_function function_table[MAX_FUNCTIONS];
int function_count = 0;

void insert_a_function(char *function_name, struct Arg **arg_lst, int return_type) {
    printf("Function to be inserted\n");
}





void printArg(struct Arg *arg) {
        printf("Name: %s\n", arg->name);
        printf("Type: %d\n", arg->type);
}

void printArgList(struct Arg **arg_list) {
    if (arg_list == NULL) {
        printf("No arguments\n");
        return;
    }

    printf("Arguments:\n");
    for (int i = 0; arg_list[i] != NULL; i++) {
        printf("  Argument %d:\n", i + 1);
        printf("    Name: %s\n", arg_list[i]->name);
        printf("    Type: %d\n", arg_list[i]->type);
    }
}
%}

%union {
    int return_type;
    char* strval;
    int numval;
    float floatval;
    struct Arg *arg;
    struct Arg **arg_list;
}

%type <arg_list> ARGUMENTS
%type <arg> ARGUMENT
%type <return_type> RETURN_TYPE

%start PROGRAM

%token id
%token colon 
%token comma
%token integer
%token intd real bools point lineseg triangle quad


%%

PROGRAM:
    FUNCTIONS
    ;

FUNCTIONS:
    FUNCTION
    | FUNCTION FUNCTIONS
    ;

FUNCTION:
    id colon '(' ARGUMENTS ')' '(' RETURN_TYPE ')' '{' '}' {
        printArgList($4);
        insert_a_function($<strval>1, $4, $7);
    }
    ;


ARGUMENTS:
    {
        $$ = (struct Arg **)malloc(sizeof(struct Arg *));
        $$[0] = NULL;
    }
    | ARGUMENT {
        $$ = (struct Arg **)malloc(sizeof(struct Arg *) * 2);
        if ($$ == NULL) {
            fprintf(stderr, "Memory allocation failed for ARGUMENTS\n");
            exit(1);
        }
        $$[0] = $1;
        $$[1] = NULL;
    }
    | ARGUMENT comma ARGUMENTS {
        $$ = (struct Arg **)malloc(sizeof(struct Arg *) * 3);
        if ($$ == NULL) {
            fprintf(stderr, "Memory allocation failed for ARGUMENTS\n");
            exit(1);
        }
        $$[0] = $1; 
        int i;
        for (i = 0; $3[i] != NULL; i++) {
            $$[i + 1] = $3[i];
        }
        $$[i + 1] = NULL;
    }
    ;

ARGUMENT:
    intd id {
        $$ = (struct Arg *)malloc(sizeof(struct Arg));
        if ($$ == NULL) {
            fprintf(stderr, "Memory allocation failed for ARGUMENT\n");
            exit(1);
        }
        $$->type = 0;
        $$->name = strdup($<strval>2);
    }
    | id id {
        yyerror("Unrecognized argument type");
        exit(1);
    }
    | id {
        yyerror("Argument should contain a datatype!");
        exit(1);
    }
    ;



RETURN_TYPE:
    {
        $$ = -1; // Initialize the pointer to NULL
    }
    | intd {
        $$ = 0; // Assign the pointer
    }
    | bools {
        $$ = 1; // Assign the pointer
    }
    | real {
        $$ = 2; // Assign the pointer
    }
    | point {
        $$ = 3; // Assign the pointer
    }
    | lineseg {
        $$ = 4; // Assign the pointer
    }
    | triangle {
        $$ = 5; // Assign the pointer
    }
    | quad {
        $$ = 6; // Assign the pointer
    }
    | id {
        yyerror("Unrecognized return type");
        exit(1);
    }
    ;

%%

void yyerror(const char* msg) {
    printf("%s\n", msg);
    exit(1);
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
