%{ 
    #include <stdbool.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include "parser.tab.h"
    #include "header.h"
    int lines;
    void despace(char target[], char input[], int l);
    void print_error();
    int y=1;
%}

sp [ \t]*
id [a-zA-Z][a-zA-Z0-9_]*
pnum ([0-9]+)|([0-9]+)"."([0-9]+)
nnum "-"{pnum}
num {nnum}|{pnum}

%% 
{sp}"point"{sp} {y=1;return POINT;}
{sp}"lineseg"{sp} {y=1;return LINESEG;}
{sp}"int"{sp} {y=1;return INT;}
{sp}"float"{sp} {y=1;return FLT;}
{sp}"void"{sp} {y=1;return VOID;}
{sp}"printf"{sp} {y=1;return PRINT;}
{sp}"$$"{sp} {y=1;return DOL;}




{sp}"check"{sp} {y=1;return IF;}
{sp}"else"{sp} {y=1;return ELSE;}

{sp}"for"{sp} {y=1;return FORT;}
{sp}"while"{sp} {y=1;return WHILET;}
{sp}"return"{sp} {y=1;return RET;}
{sp}"break"{sp} {y=1;return BREAK;}




{sp}{id}{sp}   {y=0;char input[1000]; despace(input,yytext,strlen(yytext));strcpy(yylval.vp.vali,input);return ID;}
{sp}{num}{sp} { 
			   char input[1000]; 
				despace(input,yytext,strlen(yytext));
				if(y==0)
				{
					if(input[0]=='-')
					{
						for(int i=strlen(input)-1;i>=1;i--)
							unput(input[i]);
						y=1;
						return MINUS;

					}
				}
				y=0;
				strcpy(yylval.vp.vali,input);
				return NUM;
			}


{sp}";"{sp}		{y=1;return SC;}
{sp}":"{sp}		{y=1;return COLON;}
{sp}","{sp}		{y=1;return COMMA;}

{sp}"="{sp} {y=1;return EQ;}
{sp}"||"{sp} {y=1;return OR;}
{sp}"&&"{sp} {y=1;return AND;}
{sp}"!"{sp} {y=1;return NOT;}

{sp}"<"{sp} {y=1;return LT;}
{sp}"<="{sp} {y=1;return LTE;}
{sp}">"{sp} {y=1;return GT;}
{sp}">="{sp} {y=1;return GTE;}
{sp}"=>"{sp} {y=1;return ARROW;}
{sp}"->"{sp} {y=1;return PARROW;}
{sp}"=="{sp} {y=1;return EQEQ;}
{sp}"!="{sp} {y=1;return NEQ;}

{sp}"*****"{sp} {y=1;return PASS;}
{sp}"+"{sp} {y=1;return PLUS;}
{sp}"#"{sp} {y=1;return HASHT;}
{sp}"-"{sp} {y=1;return MINUS;}
{sp}"*"{sp} {y=1;return MULT;}
{sp}"/"{sp} {y=1;return DIV;}
{sp}"%"{sp} {y=1;return MOD;}

{sp}"("{sp} {y=1;return OPT;}
{sp}")"{sp} {y=0;return CPT;}

{sp}"{"{sp} {y=1;return OCURLY;}
{sp}"}"{sp} {y=1;return CCURLY;}

{sp}"["{sp} {y=1;return OSQ;}
{sp}"]"{sp} {y=1;return CSQ;}


\n {lines++;}
. {}
%% 

int yywrap(void) {
    return 1;
}

void despace(char target[], char input[], int l){
	int start=0, end=l-1;
	while(input[start]==' ' || input[start]=='\t') start++;
	while(input[end]==' ' || input[end]=='\t') end--;
	int y=0;
	for (int i = start; i <= end; ++i)
	{
		target[y++]=input[i];
	}
	target[y]='\0';
}

void print_error()
{
	printf("Invalid Syntax while lexical analysis.\n");
}