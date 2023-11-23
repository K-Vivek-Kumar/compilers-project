%{ 
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "parser.tab.h"
#include "header.h"
int lines;
void despace(char target[], char input[], int l);
void print_error();
int y = 1;
FILE *outFile;
int k = 0;
int inside = 0;
%}

sp [ ]*
tbsp [\t]
id [a-zA-Z][a-zA-Z0-9_]*
pnum ([0-9]+)|([0-9]+)"."([0-9]+)
nnum "-"{pnum}
num {nnum}|{pnum}

%%
"~".[\n]   { / Ignore comments */ lines++;}
"@g2d"		{
	if(inside != 0){
		printf("Only functions have environments!: %d\n", lines);
		return 0;
	} else {

	return DEFENV;
	}
}
"@point" {
    if (inside != 0) {
        fprintf(outFile, "points.emplace_back(x, y);\n");
    } else {
        printf("Line #%d: @point isn't callable on global scope.\n", lines);
    }
}

"@line" {
    if (inside != 0) {
        fprintf(outFile, "lines.emplace_back(x, y);\n");
    } else {
        printf("Line #%d: @line isn't callable on global scope.\n", lines);
    }
}

"@polygon" {
    if (inside != 0) {
        fprintf(outFile, "polygons.emplace_back(x, y);\n");
    } else {
        printf("Line #%d: @polygon isn't callable on global scope.\n", lines);
    }
}

"@graph" {
    if (inside != 0) {
        fprintf(outFile, "generatePythonScript(points, lines, polygons);\n");
        fprintf(outFile, "points.clear();\n");
        fprintf(outFile, "lines.clear();\n");
        fprintf(outFile, "polygons.clear();\n");
    } else {
        printf("Line #%d: @graph isn't callable on global scope.\n", lines);
    }
}

"@view" {
    if (inside != 0) {
        fprintf(outFile, "system(\"python svas.py\");\n");
    } else {
        printf("Line #%d: @view isn't callable on global scope.\n", lines);
    }
}

{sp} {fprintf(outFile, " ");}
{tbsp} {fprintf(outFile, "\t");}
"="["="]*">"  {fprintf(outFile, " ");}
"int" {y = 1; fprintf(outFile, "%s", yytext); return INT;}
"real" {y = 1; fprintf(outFile, "float"); return FLT;}
"void" {y = 1; fprintf(outFile, "%s", yytext); return VOID;}
"show" {y = 1; fprintf(outFile, "cout << "); return PRINT;}
"$$" {y = 1; fprintf(outFile, "%s", yytext); return DOL;}
"***" {y = 1; return FIVESTAR;}
"newline" {y = 1; k = k + 1;}

"if" {y = 1; fprintf(outFile, "%s", yytext); return IF;}
"else" {y = 1; fprintf(outFile, "%s", yytext); return ELSE;}
"for" {y = 1; fprintf(outFile, "%s", yytext); return FORT;}
"loop" {y = 1; fprintf(outFile, "while"); return WHILET;}
"return" {y = 1; fprintf(outFile, "%s", yytext); return RET;}
"is" {y = 1; fprintf(outFile, "switch"); return SWITCHT;}
"break" {y = 1; fprintf(outFile, "%s", yytext); return BREAK;}
"default" {y = 1; fprintf(outFile, "%s", yytext); return DEFAULT;}
"equals" {y = 1; fprintf(outFile, "case"); return CASET;}

{id}   {y = 0; char input[1000]; despace(input, yytext, strlen(yytext));
	if (strcmp(input, "x") == 0) {
        fprintf(stderr, "Warning: Identifier 'x' is used as a graph buffer.\n");
    }
	if (strcmp(input, "y") == 0) {
		fprintf(stderr, "Warning: Identifier 'y' is used as a graph buffer.\n");
	}
	fprintf(outFile, "%s", input); return ID;
}
{num} { 
    char input[1000]; 
    despace(input, yytext, strlen(yytext));
    if(y == 0) {
        if(input[0] == '-') {
            for(int i = strlen(input) - 1; i >= 1; i--)
                unput(input[i]);
            y = 1;
            fprintf(outFile, "%s", yytext);
            return MINUS;
        }
    }
    y = 0;
    fprintf(outFile, "%s", yytext);
    return NUM;
}

";"     {y = 1; fprintf(outFile, "%s", yytext);
			for(int i = 0; i < k; i++){
				fprintf(outFile, "cout << endl;");
			}
			k = 0;
			return SC;
		}
":"     {y = 1; fprintf(outFile, "%s", yytext); return COLON;}
","     {y = 1; fprintf(outFile, "%s", yytext); return COMMA;}

"=" {y = 1; fprintf(outFile, "%s", yytext); return EQ;}
"||" {y = 1; fprintf(outFile, "%s", yytext); return OR;}
"&&" {y = 1; fprintf(outFile, "%s", yytext); return AND;}
"!" {y = 1; fprintf(outFile, "%s", yytext); return NOT;}

"<" {y = 1; fprintf(outFile, "%s", yytext); return LT;}
"<=" {y = 1; fprintf(outFile, "%s", yytext); return LTE;}
">" {y = 1; fprintf(outFile, "%s", yytext); return GT;}
">=" {y = 1; fprintf(outFile, "%s", yytext); return GTE;}
"==" {y = 1; fprintf(outFile, "%s", yytext); return EQEQ;}
"!=" {y = 1; fprintf(outFile, "%s", yytext); return NEQ;}

"+" {y = 1; fprintf(outFile, "%s", yytext); return PLUS;}
"-" {y = 1; fprintf(outFile, "%s", yytext); return MINUS;}
"*" {y = 1; fprintf(outFile, "%s", yytext); return MULT;}
"/" {y = 1; fprintf(outFile, "%s", yytext); return DIV;}
"%" {y = 1; fprintf(outFile, "%s", yytext); return MOD;}

"(" {y = 1; fprintf(outFile, "%s", yytext); return OPT;}
")" {y = 0; fprintf(outFile, "%s", yytext); return CPT;}

"{" {inside++;y = 1; fprintf(outFile, "%s", yytext); return OCURLY;}
"}" {inside--;y = 1; fprintf(outFile, "%s", yytext); return CCURLY;}

"[" {y = 1; fprintf(outFile, "%s", yytext); return OSQ;}
"]" {y = 1; fprintf(outFile, "%s", yytext); return CSQ;}

\n {lines++; fprintf(outFile, "\n", yytext);}
. {}
%% 

int yywrap(void) {
    return 1;
}

void despace(char target[], char input[], int l) {
    int start = 0, end = l - 1;
    while (input[start] == ' ' || input[start] == '\t') start++;
    while (input[end] == ' ' || input[end] == '\t') end--;
    int y = 0;
    for (int i = start; i <= end; ++i) {
        target[y++] = input[i];
    }
    target[y] = '\0';
}

void print_error() {
    printf("Invalid Syntax while lexical analysis.\n");
}
