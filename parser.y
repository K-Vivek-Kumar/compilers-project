%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int return_type;
    int *list_of_argument_types; // Changed to a pointer
} each_function;

each_function function_table[MAX_FUNCTIONS];
int function_count = 0;

void insert_a_function(char *function_name, int *list_of_argument_types, int return_type) {
    if (function_count < MAX_FUNCTIONS) {
        function_table[function_count].function_name = strdup(function_name);
        function_table[function_count].number_of_arguments = function_count;
        function_table[function_count].return_type = return_type;
        function_table[function_count].list_of_argument_types = list_of_argument_types; // Assign the pointer
        printf("Function inserted successfully: %s\n", function_name);
        function_count++;
    } else {
        printf("Error: Maximum number of functions reached\n");
    }
}
%}

%union {
    int *argument_list; // Change the type to a pointer
    int argument_type;
    char *arg_name;
    char **arg_name_list;
    int return_type;
    char* strval;
    int numval;
    float floatval;
}

%type <argument_list> ARGUMENTS
%type <argument_type> ARGUMENT
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
        insert_a_function($<strval>1, $4, $7);
    }
    ;


ARGUMENTS:
    {
        $$ = NULL; // Initialize the pointer to NULL
    }
    | ARGUMENT {
        int *arg_list = (int *)malloc(MAX_ARGS * sizeof(int)); // Allocate memory for an array of integers
        if (arg_list == NULL) {
            fprintf(stderr, "Memory allocation failed for argument list\n");
            exit(1); // Handle memory allocation failure
        }
        arg_list[0] = $1;
        $$ = arg_list; // Assign the pointer
    }
    | ARGUMENT comma ARGUMENTS {
        int *arg_list = (int *)malloc(MAX_ARGS * sizeof(int)); // Allocate memory for an array of integers
        if (arg_list == NULL) {
            fprintf(stderr, "Memory allocation failed for argument list\n");
            exit(1); // Handle memory allocation failure
        }
        arg_list[0] = $1;
        for (int i = 0; i < MAX_ARGS && $3[i] != -1; i++) {
            arg_list[i + 1] = $3[i];
        }
        $$ = arg_list; // Assign the pointer
    }
    ;


ARGUMENT:
    intd id {
        $$ = 0; // Assign the pointer
    }
    |
    bools id {
        $$ = 1; // Assign the pointer
    }
    |
    real id {
        $$ = 2; // Assign the pointer
    }
    |
    point id {
        $$ = 4; // Assign the pointer
    }
    |
    lineseg id {
        $$ = 5; // Assign the pointer
    }
    |
    triangle id {
        $$ = 6; // Assign the pointer
    }
    |
    quad id {
        $$ = 7; // Assign the pointer
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
