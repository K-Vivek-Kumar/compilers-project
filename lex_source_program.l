%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "yacc_source_program.tab.h"

    extern FILE* yyin;
    extern FILE* output_file;
    extern FILE* yyout;

    void write_it_token(const char* token, const char* type);
    int lines = 0;
%}

%option noyywrap
%x COMMENT COMMENT1

%%


"env"                                       { write_it_token(yytext, "Environment"); return env; }
"g1d"                                       { write_it_token(yytext, "Workspace is 1-Dimensional Geometry"); return g1d; }
"g2d"                                       { write_it_token(yytext, "Workspace is 2-Dimensional Geometry"); return g2d; }
"int"                                       { write_it_token(yytext, "Data Type"); return datatype; }
"bool"                                      { write_it_token(yytext, "Data Type"); return datatype; }
"real"                                      { write_it_token(yytext, "Data Type"); return datatype; }
"point"                                     { write_it_token(yytext, "Data Type"); return datatype; }
"lineseg"                                   { write_it_token(yytext, "Data Type"); return datatype; }
";" 		                                { write_it_token(yytext, "End of Work"); return yytext[0]; }
":" 		                                { write_it_token(yytext, "Is defined as"); return yytext[0]; }

"--"[-]*">"                                 { /* Starting a single line comment */ BEGIN(COMMENT); write_it_token("One-line", "Single Comment"); }
<COMMENT>[^\n]*                             { /* Ignore the comment string */ }
<COMMENT>"\n"                               { BEGIN(INITIAL); }

"--"[-]*"!>"                                { /* Starting a multi line comment */ BEGIN(COMMENT1); write_it_token("Start", "Multi-Line Comment"); }
<COMMENT1>[^"!>"]*                          { /* Ignore the comment */ }
<COMMENT1>"!>"                              { /* End */ BEGIN(INITIAL); write_it_token("End", "Multi-Line Comment"); }

[a-zA-Z][a-zA-Z0-9]*                        { /* Identifier definition */ yylval.strval = strdup(yytext); write_it_token(yytext, "ID"); return id; }

[ ]+                                        { /* Extra spaces are meant to be skipped */ }
[\t]+                                       { /* Extra tab-spaces are meant to be skipped */ }
[\n]+                                       { /* Extra new lines are meant to be skipped */ lines = lines + 1; }

.                                           { fprintf(stderr, "Unrecognized token: %s\n", yytext); exit(1); }

%%

void write_it_token(const char* token, const char* type) {
    fprintf(output_file, "%s: %s\n", type, token);
}
