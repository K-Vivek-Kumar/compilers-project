%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"

extern FILE* yyin;
extern FILE* output_file;
extern FILE* yyout;

void write_it_token(const char* str);
%}

%option noyywrap
%x COMMENT COMMENT1

%union {
    float float_num;  // To store floating-point numbers
    char* strval;      // To store string values (IDs)
}

%%

<INITIAL>"---" {
    BEGIN(COMMENT);
    write_it_token("Single Comment");
}

<COMMENT>[^\n]* {
    /* Ignore the comment string */
}

<COMMENT>"\n" {
    BEGIN(INITIAL);
}

<INITIAL>"<>" {
    BEGIN(COMMENT1);
    write_it_token("Multi-Line Comment");
}

<COMMENT1>[^"</>"]* {
    /* Ignore the comment */
}

<COMMENT1>"</>" {
    BEGIN(INITIAL);
    write_it_token("Multi-Line Comment");
}

[0-9]+"."[0-9]+ {
    yylval.float_num = atof(yytext);
    write_it_token("Float");
    return floater;
}

"comma" {
    write_it_token("comma");
}

[a-zA-Z][a-zA-Z0-9]* {
    yylval.strval = strdup(yytext);
    write_it_token("ID");
    return id;
}

[ ]+ {
    /* Extra spaces are meant to be skipped */
}
[\t]+ {
    /* Extra tab-spaces are meant to be skipped */
}

. {
    fprintf(stderr, "Unrecognized token: %s\n", yytext);
    exit(1);
}

%%

void write_it_token(const char* str) {
    fprintf(output_file, "%s\n", str);
}
