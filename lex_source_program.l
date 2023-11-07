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
    float currentfval;
%}

%option noyywrap
%x COMMENT COMMENT1

%%

<INITIAL>"---"                              { /* Starting a single line comment */ BEGIN(COMMENT); write_it_token("One-line", "Single Comment"); }
<COMMENT>[^\n]*                             { /* Ignore the comment string */ }
<COMMENT>"\n"                               { BEGIN(INITIAL); }

<INITIAL>"<>"                               { /* Starting a multi line comment */ BEGIN(COMMENT1); write_it_token("Start", "Multi-Line Comment"); }
<COMMENT1>[^"</>"]*                         { /* Ignore the comment */ }
<COMMENT1>"</>"                             { /* End */ BEGIN(INITIAL); write_it_token("End", "Multi-Line Comment"); }
"main"                                      { /* Special Keyword: main */ write_it_token(yytext, "Special Keyword"); return mains; }
"pass"                                      { /* Special Keyword: main */ write_it_token(yytext, "Special Keyword"); return pass; }
"area"                                      { /* Special Keyword: main */ write_it_token(yytext, "Special Keyword"); return area; }
"intersection"                                      { /* Special Keyword: main */ write_it_token(yytext, "Special Keyword"); return intersection; }

"true"                                      { /* Special Keyword: main */ write_it_token(yytext, "Special Keyword"); return trues; }
"false"                                      { /* Special Keyword: main */ write_it_token(yytext, "Special Keyword"); return falses; }
"+"                                      { /* Special Keyword: main */ write_it_token(yytext, "Special Keyword"); return add; }
"/"                                      { /* Special Keyword: main */ write_it_token(yytext, "Special Keyword"); return divide; }
""                                      { /* Special Keyword: main */ write_it_token(yytext, "Special Keyword"); return multiply; }
"-"                                      { /* Special Keyword: main */ write_it_token(yytext, "Special Keyword"); return minus; }
"&&"                                      { /* Special Keyword: main */ write_it_token(yytext, "Special Keyword"); return and; }
"||"                                      { /* Special Keyword: main */ write_it_token(yytext, "Special Keyword"); return or; }
"=="                                      { /* Special Keyword: main */ write_it_token(yytext, "Special Keyword"); return longeql; }
">="                                      { /* Special Keyword: main */ write_it_token(yytext, "Special Keyword"); return geq; }
"<="                                      { /* Special Keyword: main */ write_it_token(yytext, "Special Keyword"); return leq; }
">"                                      { /* Special Keyword: main */ write_it_token(yytext, "Special Keyword"); return gt; }
"<"                                      { /* Special Keyword: main */ write_it_token(yytext, "Special Keyword"); return lt; }
"!="                                      { /* Special Keyword: main */ write_it_token(yytext, "Special Keyword"); return nt; }
"!"                                      { /* Special Keyword: main */ write_it_token(yytext, "Special Keyword"); return neg; }
"=>" 		                                { /* Punctuation: */ write_it_token(yytext, "Punctuation"); return arrow; }
"=" 		                                { /* Punctuation: */ write_it_token(yytext, "Punctuation"); return yytext[0]; }
"{" 		                                { /* Punctuation: */ write_it_token(yytext, "Punctuation"); return yytext[0]; }
":" 		                                { /* Punctuation: */ write_it_token(yytext, "Punctuation"); return colon; }
"}" 		                                { /* Punctuation: */ write_it_token(yytext, "Punctuation"); return yytext[0]; }
"(" 		                                { /* Punctuation: */ write_it_token(yytext, "Punctuation"); return yytext[0]; }
")" 		                                { /* Punctuation: */ write_it_token(yytext, "Punctuation"); return yytext[0]; }
"," 		                                { /* Punctuation: */ write_it_token(yytext, "Punctuation"); return comma; }


";" 		                                { /* Punctuation: */ write_it_token(yytext, "Punctuation"); return yytext[0]; }

"int"                                      { /* Datatype: int */ write_it_token(yytext, "Primitive Datatype"); return intd; }
"real"                                      { /* Datatype: real */ write_it_token(yytext, "Primitive Datatype"); return reald; }
"bool"                                      { /* Datatype: bool */ write_it_token(yytext, "Primitive Datatype"); return boold; }
"point"                                      { /* Datatype: point */ write_it_token(yytext, "Secondary Datatype"); return pointd; }
"lineseg"                                      { /* Datatype: lineseg */ write_it_token(yytext, "Secondary Datatype"); return linesegd ; }
"quad"                                      { /* Datatype: lineseg */ write_it_token(yytext, "Secondary Datatype"); return quadd ; }
"triangle"                                      { /* Datatype: lineseg */ write_it_token(yytext, "Secondary Datatype"); return trid ; }


[0-9]+                                      { /* */ currentval = atoi(yytext); write_it_token(yytext, "Integer"); return integer;}
[0-9]+"."[0-9]+                             { /* */ currentfval = atof(yytext); write_it_token(yytext, "Float"); return floater;}
[a-zA-Z][a-zA-Z0-9]*                        { /* Identifier definition */ yylval.strval = strdup(yytext); write_it_token(yytext, "ID"); return id; }

[ ]+                                        { /* Extra spaces are meant to be skipped */ }
[\t]+                                       { /* Extra tab-spaces are meant to be skipped */ }
[\n]+                                       { /* Extra new lines are meant to be skipped */ lines = lines + 1; }

.                                           { fprintf(stderr, "Unrecognized token: %s\n", yytext); exit(1); }

%%

void write_it_token(const char* token, const char* type) {
    fprintf(output_file, "%s: %s\n",type,token);
}
