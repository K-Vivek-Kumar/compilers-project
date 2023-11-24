%{ 
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
int lines;
void print_error();
int y = 1;
FILE *outFile;
int k = 0;
int inside = 0;
char current_id[1000];
%}

sp [ ]*
tbsp [\t]
id [a-zA-Z][a-zA-Z0-9_]*


%%
"~".*[\n]   { /* Ignore comments */ lines++;}


{sp} {}
{tbsp} {}
"="["="]*">"  {}
"hello" {y = 1; return HELLO;}
"int" {y = 1;   return INT;}
"point" {y = 1; return POINT;}
"real" {y = 1;  return FLT;}
"void" {y = 1;   return VOID;}
"show" {y = 1;  return PRINT;}
"$$" {y = 1; return DOL;}
"*****" {y = 1; return FIVESTAR;}
"newline" {y = 1; k = k + 1;}

"if" {y = 1;   return IF;}
"else" {y = 1;   return ELSE;}
"for" {y = 1;   return FORT;}
"loop" {y = 1;  return WHILET;}
"return" {y = 1;   return RET;}
"is" {y = 1; return SWITCHT;}
"break" {y = 1;   return BREAK;}
"default" {y = 1;   return DEFAULT;}
"equals" {y = 1;  return CASET;}

{id}   {y = 0; 
	 return ID;
}
{num} { 
    y = 0;
     
    return NUM;
}

";"     {y = 1;  
			for(int i = 0; i < k; i++){
				
			}
			k = 0;
			return SC;
		}
":"     {y = 1;   return COLON;}
","     {y = 1;   return COMMA;}

"=" {y = 1;   return EQ;}
"||" {y = 1;   return OR;}
"&&" {y = 1;   return AND;}
"!" {y = 1;   return NOT;}

"<" {y = 1;   return LT;}
"<=" {y = 1;   return LTE;}
">" {y = 1;   return GT;}
">=" {y = 1;   return GTE;}
"==" {y = 1;   return EQEQ;}
"!=" {y = 1;   return NEQ;}

"+" {y = 1;   return PLUS;}
"-" {y = 1;   return MINUS;}
"*" {y = 1;   return MULT;}
"/" {y = 1;   return DIV;}
"%" {y = 1;   return MOD;}

"(" {y = 1;   return OPT;}
")" {y = 0;   return CPT;}

"{" {inside++;y = 1;   return OCURLY;}
"}" {inside--;y = 1;   return CCURLY;}

"[" {y = 1;   return OSQ;}
"]" {y = 1;   return CSQ;}

\n {lines++; }
. {print_error();}
%% 

int yywrap(void) {
    return 1;
}



void print_error() {
    printf("Invalid Syntax while lexical analysis.\n");
}
