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

    int currentval;
    int currentfval;
%}

%option noyywrap
%x COMMENT COMMENT1

%%

"--"[-]">"                                 { /* Starting a single line comment */ BEGIN(COMMENT); write_it_token("One-line", "Single Comment"); }
<COMMENT>[^\n]*                             { /* Ignore the comment string */ }
<COMMENT>"\n"                               { BEGIN(INITIAL); }

"--"[-]"!>"                                { /* Starting a multi line comment */ BEGIN(COMMENT1); write_it_token("Start", "Multi-Line Comment"); }
<COMMENT1>[^"!>"]*                          { /* Ignore the comment */ }
<COMMENT1>"!>"                              { /* End */ BEGIN(INITIAL); write_it_token("End", "Multi-Line Comment"); }

"call"                                        { write_it_token(yytext, "Special Keyword"); return call; }
"check"                                        { write_it_token(yytext, "Special Keyword"); return check; }
"recheck"                                        { write_it_token(yytext, "Special Keyword"); return recheck; }
"return"                                        { write_it_token(yytext, "Special Keyword"); return returns; }
"show"                                        { write_it_token(yytext, "Special Keyword"); return show; }

"int"                                      { write_it_token(yytext, "Datatype"); return ints; }
"real"                                      { write_it_token(yytext, "Datatype"); return real; }
"bool"                                      { write_it_token(yytext, "Datatype"); return bools; }
"point"                                      { write_it_token(yytext, "Datatype"); return point; }
"lineseg"                                      { write_it_token(yytext, "Datatype"); return lineseg ; }
"true"                                      { write_it_token(yytext, "Datatype"); return trues ; }
"false"                                      { write_it_token(yytext, "Datatype"); return falses ; }
"and"                                      { write_it_token(yytext, "Datatype"); return and ; }
"or"                                      { write_it_token(yytext, "Datatype"); return or ; }
"env"                                       { write_it_token(yytext, "Environment"); return env; }

"$$"                                          { write_it_token(yytext, "UOperator"); return ddoll; }
"$"                                          { write_it_token(yytext, "UOperator"); return doll; }
"==" 		                                { write_it_token(yytext, "Assignment Operator"); return lequal; }
"=>"                                          { write_it_token(yytext, "Operator"); return arrow; }
"->"                                          { write_it_token(yytext, "Operator"); return parrow; }

">" 		                                { write_it_token(yytext, "Punctuation"); return yytext[0]; }
"<" 		                                { write_it_token(yytext, "Punctuation"); return yytext[0]; }
">=" 		                                { write_it_token(yytext, "Punctuation"); return geq; }
"<=" 		                                { write_it_token(yytext, "Punctuation"); return leq; }
"!=" 		                                { write_it_token(yytext, "Punctuation"); return neq; }

"=" 		                                { write_it_token(yytext, "Assignment Operator"); return yytext[0]; }
"(" 		                                { write_it_token(yytext, "Punctuation"); return yytext[0]; }
")" 		                                { write_it_token(yytext, "Punctuation"); return yytext[0]; }
"{" 		                                { write_it_token(yytext, "Punctuation"); return yytext[0]; }
"}" 		                                { write_it_token(yytext, "Punctuation"); return yytext[0]; }
"/." 		                                { write_it_token(yytext, "Punctuation"); return yytext[0]; }

"," 		                                { write_it_token(yytext, "Comma"); return yytext[0]; }
";" 		                                { write_it_token(yytext, "End of Work"); return yytext[0]; }
":" 		                                { write_it_token(yytext, "Is defined as"); return yytext[0]; }
"~" 		                                { write_it_token(yytext, "Negation"); return yytext[0]; }
"-" 		                                { write_it_token(yytext, "Operator"); return yytext[0]; }

"*"                                       { write_it_token(yytext, "Check if two linesegment or two point touch each other"); return yytext[0]; }
"#"                                     { write_it_token(yytext, "Check the overlap of two linesegment or two point"); return yytext[0]; }

"+"                                       { write_it_token(yytext, "Incrementing the length of line segment"); return yytext[0]; }
"|"                                      { write_it_token(yytext, "Check if first point or linesegment is on the left of second"); return yytext[0]; }



[0-9]+                                   { /* */ currentval = atoi(yytext); write_it_token(yytext, "Integer"); return integer;}
[0-9]+"."[0-9]+                                      { /* */ currentfval = atof(yytext); write_it_token(yytext, "Float"); return floater;}
[a-zA-Z][a-zA-Z0-9]*                        { /* Identifier definition */ yylval.strval = strdup(yytext); write_it_token(yytext, "ID"); return id; }

[ ]+                                        { /* Extra spaces are meant to be skipped */ }
[\t]+                                       { /* Extra tab-spaces are meant to be skipped */ }
[\n]+                                       { /* Extra new lines are meant to be skipped */ lines = lines + 1; }

.                                           { fprintf(stderr, "Unrecognized token: %s\n", yytext); exit(1); }

%%

void write_it_token(const char* token, const char* type) {
    fprintf(output_file, "%s: %s\n",type, token);
}
