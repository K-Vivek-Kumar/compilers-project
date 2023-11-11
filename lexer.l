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

":" {
    write_it_token("colon");
    return colon;
}
"int" {
    write_it_token("int");
    return intd;
}
"real" {
    write_it_token("real");
    return real;
}
"bool" {
    write_it_token("bools");
    return bools;
}
"point" {
    write_it_token("point");
    return point;
}
"lineseg" {
    write_it_token("lineseg");
    return lineseg;
}
"triangle" {
    write_it_token("triangle");
    return triangle;
}
"quad" {
    write_it_token("quad");
    return quad;
}

"(" {
    write_it_token("Left Parenthesis");
    return yytext[0];
}

")" {
    write_it_token("Right Parenthesis");
    return yytext[0];
}

"{" {
    write_it_token("Curl left");
    return yytext[0];
}

"}" {
    write_it_token("Curl Right");
    return yytext[0];
}

[0-9]+"."[0-9]+ {
    write_it_token("Float");
    return real;
}

[0-9]+ {
    write_it_token("Integer");
    return integer;
}

"," {
    write_it_token("comma");
    return comma;
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
