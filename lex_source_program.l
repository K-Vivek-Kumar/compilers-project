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
"int"                                       { write_it_token(yytext, "Datatype"); return datatype; }
"bool"                                      { write_it_token(yytext, "Datatype"); return datatype; }
"real"                                      { write_it_token(yytext, "Datatype"); return datatype; }
"point"                                     { write_it_token(yytext, "Datatype"); return datatype; }
"null"                                      { write_it_token(yytext, "Datatype"); return null; }
"lineseg"                                   { write_it_token(yytext, "Datatype"); return datatype; }
"about"                                     { write_it_token(yytext, "Special Keyword"); return about; }
"check"                                     { write_it_token(yytext, "Special Keyword"); return check; }
"main"                                      { write_it_token(yytext, "Special Keyword"); return main; }
"return"                                     { write_it_token(yytext, "Special Keyword"); return return; }
"show"                                     { write_it_token(yytext, "Special Keyword"); return show; }
";" 		                                { write_it_token(yytext, "End of Work"); return yytext[0]; }
":" 		                                { write_it_token(yytext, "Is defined as"); return yytext[0]; }

"--"[-]*">"                                 { /* Starting a single line comment */ BEGIN(COMMENT); write_it_token("One-line", "Single Comment"); }
<COMMENT>[^\n]*                             { /* Ignore the comment string */ }
<COMMENT>"\n"                               { BEGIN(INITIAL); }

"--"[-]*"!>"                                { /* Starting a multi line comment */ BEGIN(COMMENT1); write_it_token("Start", "Multi-Line Comment"); }
<COMMENT1>[^"!>"]*                          { /* Ignore the comment */ }
<COMMENT1>"!>"                              { /* End */ BEGIN(INITIAL); write_it_token("End", "Multi-Line Comment"); }
"*"                                       { write_it_token(yytext, "Check if two linesegment or two point touch each other"); return star; }
"#"                                     { write_it_token(yytext, "Check the overlap of two linesegment or two point"); return hashtag; }
"->"                                    { write_it_token(yytext, "Check if one point or linesegment is on another one"); return arrow; }
"+"                                       { write_it_token(yytext, "Incrementing the length of line segment"); return increment; }
"|"                                      { write_it_token(yytext, "Check if first point or linesegment is on the left of second"); return pipe; }
"("                                      { write_it_token(yytext, "Punctuation"); return leftbr; }
")"                                      { write_it_token(yytext, "Punctuation"); return rightbr; }
"{"                                      { write_it_token(yytext, "Punctuation"); return leftcr; }
"}"                                      { write_it_token(yytext, "Punctuation"); return rightcr; }

[a-zA-Z][a-zA-Z0-9]*                        { /* Identifier definition */ yylval.strval = strdup(yytext); write_it_token(yytext, "ID"); return id; }

[ ]+                                        { /* Extra spaces are meant to be skipped */ }
[\t]+                                       { /* Extra tab-spaces are meant to be skipped */ }
[\n]+                                       { /* Extra new lines are meant to be skipped */ lines = lines + 1; }

.                                           { fprintf(stderr, "Unrecognized token: %s\n", yytext); exit(1); }

%%

void write_it_token(const char* token, const char* type) {
    fprintf(output_file, "%s: %s\n", type, token);
}
