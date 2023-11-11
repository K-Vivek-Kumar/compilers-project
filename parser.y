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
    int return_type;
}

%type <argument_list> ARGUMENTS
%type <argument_type> ARGUMENT
%type <return_type> RETURN_TYPE

%start PROGRAM

%token id
%token colon
%token comma
%token integer

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
        insert_a_function(strdup($1), $4, $7);
    }
    ;

ARGUMENTS:
    {
        $$ = NULL; // Initialize the pointer to NULL
    }
    | ARGUMENT {
        $$ = $1; // Assign the pointer
    }
    | ARGUMENT comma ARGUMENTS {
        $$ = $1; // Assign the pointer (assuming it's a list of arguments)
    }
    ;

ARGUMENT:
    integer id {
        int *arg_list = (int *)malloc(MAX_ARGS * sizeof(int)); // Allocate memory for an array of integers
        if (arg_list == NULL) {
            fprintf(stderr, "Memory allocation failed for argument list\n");
            exit(1); // Handle memory allocation failure
        }
        arg_list[0] = atoi($1); // Store argument type in the argument list
        $$ = arg_list; // Assign the pointer
    }
    ;


RETURN_TYPE:
    {
        $$ = -1; // Initialize the pointer to NULL
    }
    | integer {
        $$ = 0; // Assign the pointer
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
