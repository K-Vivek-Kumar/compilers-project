%{
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

extern FILE * yyin;
void yyerror(char *s);

FILE*trans;
int bracketnums[100];
int bracketcount = 0;

bool intreg[10];
bool floatreg[10];
FILE*fp;
FILE*fil;
int canbreakarr[10][20];
int canbreakcount[10];
struct varrecord
{
	char varname[100];
	char vartype[100];
	char finalname[100];
	bool tag;
	int level;

	bool IsArr;
	int dimcount;
	int dim[100];
	int moddim[100];
};
struct funcrecord
{
	char name[100];
	char type[100];
	struct varrecord paramtable[100];
	struct varrecord vartable[100];
	int paramcount;
	int varcount;  
};


struct funcrecord functable[1000];
bool success=true;
int actfuncindex=0;
int canbreak=0;
int callfuncindex;
int globallevel=0;
void releasetemp(int i);
int newtemp();
int InArr(struct varrecord arr[],int size,char finder[]);
bool CheckVar (struct varrecord arr[],int size,char finder[],int level);
void PrintVars(struct varrecord a);
void PrintFuncs(struct funcrecord a);
void despace(char target[], char input[], int l);
void PrintFuncTable();
int stoi(char*s);
int nextquad=1;

char vars[100][100];
char varlist[100][100];
char types[100][100];
int sizes[100];
int totvars=0;
int varl = 0;

%}

%start	START


%token	SELECT
%token	PRINT
%token	INT
%token	PASS
%token	FLT
%token	ID

%token 	SC
%token 	SP
%token COMMA
%token COLON

%token EQ
%token OR
%token AND
%token NOT

%token LT
%token LTE
%token GT
%token GTE
%token EQEQ
%token NEQ

%token PLUS
%token MINUS
%token MULT
%token DIV
%token MOD
%token HASHT

%token OPT
%token CPT
%token OCURLY
%token CCURLY
%token IF
%token ELSE
%token FORT
%token WHILET
%token VOID
%token RET
%token BREAK

%token CSQ
%token OSQ
%token NUM
%token DOL

%token ARROW
%token PARROW
%token POINT
%token LINESEG


%union
{
  struct attributes{
  	char vali[1000];
	char type[1000];
	
	int arr;
	int ind;

	int counter;
	int countor;
	int countand;
	bool caseallow;
	bool isarray;

	int bplist[1000];
	int bpcount;
	int tempreg;
	int quad;
	int begin;
	int bplist2[1000];
	int bpcount2;
	} vp;
};

%type<vp> F START INPUT FUNC_DECL FUNC_HEAD BODY RESULT_ID OPT DECLISTE CPT RESULT INT FLT POINT LINESEG VOID DECLIST COMMA DEC TYPE OCURLY SLIST CCURLY MSLIST S VAR_DECL ASSIGN IFELSE FOR WHILE INCRLEVEL FUNC_CALL SC RETURN RET COR PARAMLIST PLIST WHILEXP WHILET MWHILE FOREXP FORT MFOR NFOR FORASSIGN IFEXP NIF MIF ELSE L IDS ARRS ARR ID BRLIST OSQ CSQ NUM EQ CAND OR AND CNOT NOT ECOMP LT LTE GT GTE NEQ EQEQ E PLUS MINUS HASHT T MULT DIV MOD COLON IDTEMP FORBACK1 FORBACK2 ARRFUNC LISTFUNC ARRF ARRFLIST INPUTGLOBAL GLIST MGL NGL DOL
%%

START : INPUTGLOBAL
		;

INPUTGLOBAL : MGL GLIST NGL INPUT
				| NGL INPUT
				;

NGL    : {
			actfuncindex=1;
		 }
		;
MGL  : {
			strcpy(functable[0].name,"global");
			strcpy(functable[0].type,"int");
		}
		 ;

GLIST : DOL VAR_DECL GLIST
		| DOL VAR_DECL
		;

INPUT : FUNC_DECL INPUT
		| FUNC_DECL
		;

FUNC_DECL : FUNC_HEAD BODY {
							actfuncindex++;  
							globallevel=0;
							 char printer[1000];
							 backpatch($2.bplist,$2.bpcount,nextquad);
							 
							 
							snprintf(printer,999,"func end");
							GenQuad(printer);
							
						}
				| error SC  { yyerrok;}

		    ;
FUNC_HEAD : RESULT_ID ARROW OPT DECLISTE CPT  {
										fprintf(trans, ")\n");
										globallevel++;	

										}
			;
RESULT_ID : ID COLON OPT RESULT CPT {
	functable[actfuncindex].paramcount=0;
						functable[actfuncindex].varcount=0;
						globallevel++;
						strcpy(functable[actfuncindex].name,$1.vali);

						fprintf(trans, "%s %s (", functable[actfuncindex].type, $1.vali);
						// char printer[1000];
						// snprintf(printer,999,"func begin %s",$1.vali);
						// GenQuad(printer);

					  }
			;
RESULT : INT       {strcpy(functable[actfuncindex].type,"int");}
		| FLT	   {strcpy(functable[actfuncindex].type,"float");}
		| VOID     {strcpy(functable[actfuncindex].type,"void");}
		| POINT     {strcpy(functable[actfuncindex].type,"point");}
		| LINESEG    {strcpy(functable[actfuncindex].type,"lineseg");}
		;
DECLISTE : DECLIST
		| ;
DECLIST : DECLIST COMMA {fprintf(trans, ",");} DEC 
			| DEC
			;
DEC : ID COLON TYPE				{
								int finder;
								finder = InArr(functable[actfuncindex].paramtable,functable[actfuncindex].paramcount,$1.vali); 
								if(finder!=-1)
								{
									char printer[1000];
									snprintf(printer,999,"Parameter with name %s already declared.",$1.vali);
									CallError(printer);
								}
								else
								{
									struct varrecord new_record;
									strcpy(new_record.varname,$1.vali);
									strcpy(new_record.vartype,$3.type);
									new_record.tag=false;
									new_record.level = globallevel;
									new_record.IsArr = false;
									new_record.dimcount = 0;

									char finalname[1000];
									snprintf(finalname,999,"%s_%d_%s_%d",new_record.varname,globallevel,functable[actfuncindex].name,functable[actfuncindex].paramcount);

									strcpy(new_record.finalname,finalname);

									functable[actfuncindex].paramtable[functable[actfuncindex].paramcount++]=new_record;
								}
								fprintf(trans, "%s %s", $3.type, $1.vali);
								
							}
		| ARRFUNC COLON TYPE					{
								int finder;
								finder = InArr(functable[actfuncindex].paramtable,functable[actfuncindex].paramcount,$1.vali); 
								if(finder!=-1)
								{
									char printer[1000];
									snprintf(printer,999,"Parameter with name %s already declared.",$1.vali);
									CallError(printer);
								}
								else
								{
									struct varrecord new_record;
									strcpy(new_record.varname,$1.vali);
									strcpy(new_record.vartype,$3.type);
									new_record.tag=false;
									new_record.level = globallevel;
									new_record.IsArr = true;
									new_record.dimcount = $1.counter;

									char finalname[1000];
									snprintf(finalname,999,"%s_%d_%s_%d",new_record.varname,globallevel,functable[actfuncindex].name,functable[actfuncindex].paramcount);

									strcpy(new_record.finalname,finalname);

									functable[actfuncindex].paramtable[functable[actfuncindex].paramcount++]=new_record;
								}	
								fprintf(trans, "%s %s", $3.type, $1.vali);
								for(int ijk = 0; ijk < $1.counter; ijk++){
									fprintf(trans, "[]");
								}
								}
		;
ARRFUNC : ID LISTFUNC     {strcpy($$.vali,$1.vali);
							$$.counter=$2.counter;}
		;

LISTFUNC : LISTFUNC OSQ CSQ  {$$.counter=$1.counter+1;}
			| OSQ CSQ     {$$.counter=1;}
			;

BODY : OCURLY {fprintf(trans, "{\n");} SLIST CCURLY  {
							int counter=0;
								int i;
								for(i=functable[actfuncindex].varcount-1;i>=0;i--)
								{
									if(functable[actfuncindex].vartable[i].level==globallevel)
									counter++;
								}
								functable[actfuncindex].varcount -= counter;
								globallevel--;

								$$.bpcount=0;
								for(int i=0;i<$1.bpcount;i++)
								{
									$$.bplist[$$.bpcount++]=$1.bplist[i];
								}
							fprintf(trans, "}\n");
							}
		;
SLIST : SLIST MSLIST S      {
								backpatch($1.bplist,$1.bpcount,$2.quad);

								$$.bpcount=0;
								for(int i=0;i<$3.bpcount;i++)
								{
									$$.bplist[$$.bpcount++]=$3.bplist[i];
								}
							}
		| S                 {
								$$.bpcount=0;
								for(int i=0;i<$1.bpcount;i++)
								{
									$$.bplist[$$.bpcount++]=$1.bplist[i];
								}
							}
		;
MSLIST : { $$.quad=nextquad;};

S:      error SC  { yyerrok;}
		| PASS {}
		| VAR_DECL {}
		| ASSIGN {}
		| IFELSE {
						$$.bpcount=0;
						int i;
						for( i=0;i<$1.bpcount;i++)
						{
							$$.bplist[$$.bpcount++]=$1.bplist[i];
						}
				 }
		| FOR    {

						$$.bpcount=0;
						int i;
						for(i=0;i<canbreakcount[canbreak];i++)
						{
							$$.bplist[$$.bpcount++]=canbreakarr[canbreak][i];
						}
						canbreakcount[canbreak]=0;
						canbreak--;
						for( i=0;i<$1.bpcount;i++)
						{
							$$.bplist[$$.bpcount++]=$1.bplist[i];
						}
				 }
		| WHILE  {
						$$.bpcount=0;
						int i;
						for(i=0;i<canbreakcount[canbreak];i++)
						{
							$$.bplist[$$.bpcount++]=canbreakarr[canbreak][i];
						}
						canbreakcount[canbreak]=0;
						canbreak--;
						for( i=0;i<$1.bpcount;i++)
						{
							$$.bplist[$$.bpcount++]=$1.bplist[i];
						}
				 }
		| INCRLEVEL BODY	{
								$$.bpcount=0;
								int i;
								for( i=0;i<$2.bpcount;i++)
								{
									$$.bplist[$$.bpcount++]=$2.bplist[i];
								}
							}
		| FUNC_CALL SC {}
		| RETURN SC {		
			fprintf(trans, ";\n");
		}
		| BREAK SC 			{
								if(canbreak==0)
								{
									CallError("Break can only occur within switch or loops.");
								}
								char printer[1000];
								snprintf(printer,999,"goto _____");
								canbreakarr[canbreak][canbreakcount[canbreak]++]=nextquad;
								GenQuad(printer);
							}
		| PRINT OPT COR CPT  SC      {
								char printer[1000];
								backpatch($3.bplist,$3.bpcount,nextquad);
								if(!strcmp($3.type,"errortype"))
								{
									CallError("Some error while calling print.");
								}
								else if(!strcmp($3.type,"int"))
								{
									snprintf(printer,999,"print(t%d)",$3.tempreg); 
									GenQuad(printer);
									releaseint($3.tempreg);
								}
								else if(!strcmp($3.type,"float"))
								{
									snprintf(printer,999,"print(f%d)",$3.tempreg); 
									GenQuad(printer);
									releasefloat($3.tempreg);
								}
							}
		; 

INCRLEVEL :  {globallevel++;}
			;
RETURN : RET           	{
							if(strcmp(functable[actfuncindex].type,"void"))
							{
								CallWarning("No return value in non-void function.");
							}
							char printer[1000];
							snprintf(printer,999,"return");
							GenQuad(printer);
							fprintf(trans, "return");
						}
		| RET COR       {
							if(!strcmp(functable[actfuncindex].type,"void"))
							{
								CallWarning("Return value in a void function.");
							}
							backpatch($2.bplist,$2.bpcount,nextquad);
							char printer[1000];
							if(!strcmp(functable[actfuncindex].type,"float"))
							{
								int temp2=$2.tempreg;
								if(!strcmp($2.type,"int"))
								{
									temp2=newfloat();
									snprintf(printer,999,"f%d = ConvertToFloat(t%d)",temp2,$2.tempreg);
									releaseint($2.tempreg);
									GenQuad(printer);
								}
								snprintf(printer,999,"return f%d",temp2);
								GenQuad(printer);
								releasefloat(temp2);
								
							}
							else
							{
								int temp2=$2.tempreg;
								if(!strcmp($2.type,"float"))
								{
									temp2=newint();
									snprintf(printer,999,"t%d = ConvertToInt(f%d)",temp2,$2.tempreg);
									releasefloat($2.tempreg);
									GenQuad(printer);
								}
								snprintf(printer,999,"return t%d",temp2);
								GenQuad(printer);
								releaseint(temp2);

							}

						}
		;

FUNC_CALL : IDTEMP OPT PARAMLIST CPT {
										if(callfuncindex!=-1 && functable[callfuncindex].paramcount!=$3.counter)
										{
											CallError("Number of parameters not matching.");
											strcpy($$.type,"errortype");
										}
										else if(callfuncindex==-1)
										{
											strcpy($$.type,"errortype");
										}
										else
										{
											strcpy($$.type,functable[callfuncindex].type);
										}


										char printer[1000];
										snprintf(printer,999,"call %s,%d",$1.vali,$3.counter+1);
										GenQuad(printer);
										int gettemp;
										if(callfuncindex!=-1)
										{
										if(!strcmp(functable[callfuncindex].type,"int"))
										{	
											gettemp=newint();
											snprintf(printer,999,"refparam t%d",gettemp);
											GenQuad(printer);
										}
										else if(!strcmp(functable[callfuncindex].type,"float"))
										{
											gettemp=newfloat();
											snprintf(printer,999,"refparam f%d",gettemp);
											GenQuad(printer);
										}
										else
											gettemp=-1;

										$$.tempreg=gettemp;
										}

									 }
			;
IDTEMP : ID 				{
								int get=-1;
								int i=0;
								for(i=0;i<actfuncindex+1;i++)
								{
									if(!strcmp(functable[i].name,$1.vali))
									{
											get=i;
											break;
									}
								}

								if(get==-1)
								{
									CallError("No such function exists.");
									callfuncindex=-1;
								}
								else
								{
									callfuncindex = get;
								}
								strcpy($$.vali,$1.vali);
	
							}
		;
PARAMLIST : PLIST 		{
							$$.counter = $1.counter;
						}
			|			{
							$$.counter = 0;
						} 
			;
PLIST : PLIST COMMA COR {
							$$.counter++;
							backpatch($3.bplist,$3.bpcount,nextquad);
							char checktype[100];
							if(callfuncindex!=-1)
							strcpy(checktype,functable[callfuncindex].paramtable[$$.counter-1].vartype);
							else{
							strcpy(checktype,"errortype");
							}

							char printer[1000];
							if(!strcmp($3.type,"int"))
							{
								if(!strcmp(checktype,"float"))
								{
									int gettemp = newfloat();
									
									snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp,$3.tempreg);
									GenQuad(printer);
									releaseint($3.tempreg);
									snprintf(printer,999,"param f%d",gettemp);
									releasefloat(gettemp);

								}
								else
								{
								snprintf(printer,999,"param t%d",$3.tempreg);
								releaseint($3.tempreg);
								}
							}
							if(!strcmp($3.type,"float"))
							{
								if(!strcmp(checktype,"int"))
								{
									int gettemp = newint();
									snprintf(printer,999,"t%d = ConvertToInt(f%d)",gettemp,$3.tempreg);
									GenQuad(printer);
									releasefloat($3.tempreg);
									snprintf(printer,999,"param t%d",gettemp);
									releaseint(gettemp);
								}
								else
								{
								snprintf(printer,999,"param f%d",$3.tempreg);
								releasefloat($3.tempreg);
								}	
							}

							GenQuad(printer);

						}
		| COR 			{
							$$.counter=1;
							backpatch($1.bplist,$1.bpcount,nextquad);

							char checktype[100];
							if(callfuncindex!=-1)
							strcpy(checktype,functable[callfuncindex].paramtable[$$.counter-1].vartype);
							else
							strcpy(checktype,"errortype");
							char printer[1000];
							if(!strcmp($1.type,"int"))
							{
								if(!strcmp(checktype,"float"))
								{
									int gettemp = newfloat();
									
									snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp,$1.tempreg);
									GenQuad(printer);
									releaseint($1.tempreg);
									snprintf(printer,999,"param f%d",gettemp);
									releasefloat(gettemp);

								}
								else
								{
								snprintf(printer,999,"param t%d",$1.tempreg);
								releaseint($1.tempreg);
								}
							}
							if(!strcmp($1.type,"float"))
							{
								if(!strcmp(checktype,"int"))
								{
									int gettemp = newint();
									snprintf(printer,999,"t%d = ConvertToInt(f%d)",gettemp,$1.tempreg);
									GenQuad(printer);
									releasefloat($1.tempreg);
									snprintf(printer,999,"param t%d",gettemp);
									releaseint(gettemp);
								}
								else
								{
								snprintf(printer,999,"param f%d",$1.tempreg);
								releasefloat($1.tempreg);
								}	
							}
							GenQuad(printer);

						}			
		;



WHILE : WHILEXP BODY				{
										
										char printer[1000];
										snprintf(printer,999,"goto %d",$1.begin);
										GenQuad(printer);
										backpatch($2.bplist,$2.bpcount,$1.begin);
										$$.bpcount=0;
										int i;
										for(i=0;i<$1.bpcount;i++)
											$$.bplist[$$.bpcount++]=$1.bplist[i];
									}
		;
WHILEXP : WHILET MWHILE OPT COR CPT { 
									backpatch($4.bplist,$4.bpcount,nextquad);
									
									int temp2=$4.tempreg;
									char printer[1000];
									if(!strcmp($4.type,"float"))
									{
										temp2=newint();
										snprintf(printer,999,"t%d = ConvertToInt(f%d)",temp2,$4.tempreg);
										releasefloat($4.tempreg);
										GenQuad(printer);
									}

									snprintf(printer,999,"if(t%d == 0) goto _____",temp2);
									$$.bpcount=0;
									$$.bplist[$$.bpcount++]=nextquad;
									GenQuad(printer);
									releaseint(temp2);
									$$.begin=$2.quad;

									globallevel++; canbreak++;
									
									}
		;
MWHILE :           { $$.quad=nextquad;} 
		;



FOR : FOREXP BODY {		
						char printer[1000];
						snprintf(printer,999,"goto _____");
						$2.bplist[$2.bpcount++]=nextquad;
						GenQuad(printer);
						backpatch($2.bplist,$2.bpcount,$1.quad);
						$$.bpcount=0;
						int i;
						for(i=0;i<$1.bpcount;i++)
						{
							$$.bplist[$$.bpcount++]=$1.bplist[i];
						}	
					}
		;

FOREXP : FORBACK1 FORBACK2 {globallevel++;canbreak++;
								$$.quad=$2.quad;
								char printer[1000];
								snprintf(printer,999,"goto %d",$1.quad);
								GenQuad(printer);

								backpatch($1.bplist2,$1.bpcount2,nextquad);
								$$.bpcount=0;
								int i;
								for(i=0;i<$1.bpcount;i++)
								{
									$$.bplist[$$.bpcount++]=$1.bplist[i];
								}	
							}
		;
FORBACK1 : FORT OPT ASSIGN MFOR COR SC {
									backpatch($5.bplist,$5.bpcount,nextquad);
									int temp2=$5.tempreg;
									char printer[1000];
									if(!strcmp($5.type,"float"))
									{
										temp2=newint();
										snprintf(printer,999,"t%d = ConvertToInt(f%d)",temp2,$5.tempreg);
										releasefloat($5.tempreg);
										GenQuad(printer);
									}

									snprintf(printer,999,"if(t%d == 0) goto _____",temp2);
									$$.bpcount=0;
									$$.bplist[$$.bpcount++]=nextquad;
									GenQuad(printer);
									releaseint(temp2);
									$$.bpcount2=0;
									$$.bplist2[$$.bpcount2++]=nextquad;
									snprintf(printer,999,"goto _____");
									GenQuad(printer);
									$$.quad=$4.quad;

 									}
 		;

FORBACK2: NFOR FORASSIGN CPT { $$.quad=$1.quad;}
		;
MFOR : { $$.quad=nextquad;}
	   ;
NFOR : {$$.quad=nextquad;}
		;




IFELSE : IFEXP BODY                    {
											int i;
											$$.bpcount=0;
											for(i=0;i<$1.bpcount;i++)
											{
												$$.bplist[$$.bpcount++]=$1.bplist[i];
											}
											for(i=0;i<$2.bpcount;i++)
											{
												$$.bplist[$$.bpcount++]=$2.bplist[i];
											}


										}
		| IFEXP BODY NIF ELSE MIF BODY { 
											backpatch($1.bplist,$1.bpcount,$5.quad);
											$$.bpcount=0;
											int i;
											for(i=0;i<$2.bpcount;i++)
											{
												$$.bplist[$$.bpcount++]=$2.bplist[i];
											}
											for(i=0;i<$3.bpcount;i++)
											{
												$$.bplist[$$.bpcount++]=$3.bplist[i];
											}
											for(i=0;i<$6.bpcount;i++)
											{
												$$.bplist[$$.bpcount++]=$6.bplist[i];
											}



										}
		;
NIF : 								{
											char printer[1000];
											snprintf(printer,999,"goto _____");
											$$.bpcount=0;
											$$.bplist[$$.bpcount++]=nextquad;
											GenQuad(printer);
										}
										;
MIF :  											{$$.quad=nextquad;globallevel++;}
		;
IFEXP : IF OPT COR CPT  						{ 
									backpatch($3.bplist,$3.bpcount,nextquad);
									char printer[1000];
									globallevel ++;
									int temp2=$3.tempreg;
									if(!strcmp($3.type,"float"))
									{
										temp2=newint();
										snprintf(printer,999,"t%d = ConvertToInt(f%d)",temp2,$3.tempreg);
										releasefloat($3.tempreg);
										GenQuad(printer);
									}

									snprintf(printer,999,"if(t%d == 0) goto _____",temp2);
									$$.bpcount=0;
									$$.bplist[$$.bpcount++]=nextquad;
									GenQuad(printer);
									releaseint(temp2);
								}
		;


VAR_DECL : L COLON TYPE SC 				{
										int i;
										int ct = 1;
										for(i=0;i<functable[actfuncindex].varcount;i++)
										{
											if(!strcmp(functable[actfuncindex].vartable[i].vartype,"-1"))
											{
												strcpy(functable[actfuncindex].vartable[i].vartype,$3.type);
												strcpy(types[totvars-ct],$3.type);
												ct--;

											}
										}
										fprintf(trans, "%s ", $3.type);
										for(int kk = 0; kk < varl; kk++){
											fprintf(trans, "%s", varlist[kk]);{
												if(kk < varl - 1){
													fprintf(trans, ", ");
												}
											}
										}
										fprintf(trans, ";\n");
										varl = 0;
									}
		;
TYPE : INT  {strcpy($$.type,"int");}
	| FLT  	{strcpy($$.type,"float");}
	| POINT  	{strcpy($$.type,"point");}
	| LINESEG 	{strcpy($$.type,"lineseg");}
	;
L : L COMMA IDS {strcpy(varlist[varl],$3.vali);varl++;}
	| IDS {strcpy(varlist[varl],$1.vali);varl++;}
	| L COMMA ARRS
	| ARRS         
	;

ARRS : ARR
		;

ARR : ID BRLIST                 {
				int finder;
				int checker;
				finder = InArr(functable[actfuncindex].paramtable,functable[actfuncindex].paramcount,$1.vali); 
				checker = InArr(functable[actfuncindex].vartable,functable[actfuncindex].varcount,$1.vali);
				if(finder!=-1 && globallevel==2)
				{
					char printer[1000];
					snprintf(printer,999,"Parameter with name %s already exists",$1.vali);
					CallError(printer);
				}
				else if(checker!=-1 && functable[actfuncindex].vartable[checker].level==globallevel)
				{
					char printer[1000];
					snprintf(printer,999,"Variable with name %s already exists in the current scope.",$1.vali);
					CallError(printer);
				}
				else
				{
					strcpy(functable[actfuncindex].vartable[functable[actfuncindex].varcount].varname,$1.vali);
					strcpy(functable[actfuncindex].vartable[functable[actfuncindex].varcount].vartype,"-1");	
					functable[actfuncindex].vartable[functable[actfuncindex].varcount].tag=true;
					functable[actfuncindex].vartable[functable[actfuncindex].varcount].level=globallevel;
					functable[actfuncindex].vartable[functable[actfuncindex].varcount].IsArr=true;

					char finalname[1000];
					snprintf(finalname,999,"%s_%d_%s",$1.vali,globallevel,functable[actfuncindex].name);
					strcpy(vars[totvars],finalname);
					strcpy(types[totvars],functable[actfuncindex].vartable[functable[actfuncindex].varcount].vartype);

					int store = functable[actfuncindex].vartable[functable[actfuncindex].varcount].dimcount;

					functable[actfuncindex].vartable[functable[actfuncindex].varcount].moddim[store-1]=1;
					for(int j=store-2;j>=0;j--)
					{
						functable[actfuncindex].vartable[functable[actfuncindex].varcount].moddim[j] = functable[actfuncindex].vartable[functable[actfuncindex].varcount].moddim[j+1] * functable[actfuncindex].vartable[functable[actfuncindex].varcount].dim[j+1];
					}

					int prod=1;
					int i=0;
					for(i=0;i<functable[actfuncindex].vartable[functable[actfuncindex].varcount].dimcount;i++)
					{
						prod *= functable[actfuncindex].vartable[functable[actfuncindex].varcount].dim[i];
					}
					sizes[totvars]=prod;
					totvars++;



					strcpy(functable[actfuncindex].vartable[functable[actfuncindex].varcount].finalname,finalname);
					functable[actfuncindex].varcount++;
				}	
				strcpy(varlist[varl],$1.vali);
				int offset = strlen(varlist[varl]);
				for(int kk = 0;kk<bracketcount; kk++){
					offset += sprintf(varlist[varl] + offset, "[%d]", bracketnums[kk]);
				}
				varl++;
				bracketcount = 0;
								}
		;
BRLIST : BRLIST OSQ NUM CSQ     {
									int t = strlen($3.vali);
									int i=0;
									bool isf=false;
									for(i=0;i<t;i++)
									{
										if($3.vali[i]=='.')
										{
										isf=true;
										break;
										}
									}
									bool isn = ($3.vali[0]=='-');
									if(isf)
									{
									CallError("Array dimensions should be an integer");
									}
									if(isn)
									{
									CallError("Array dimensions should be an positive integer");
									}

							functable[actfuncindex].vartable[functable[actfuncindex].varcount].dim[functable[actfuncindex].vartable[functable[actfuncindex].varcount].dimcount++]=stoi($3.vali);
	bracketnums[bracketcount] = stoi($3.vali);
	bracketcount++;
								}
		| OSQ NUM CSQ {
									int t = strlen($2.vali);
									int i=0;
									bool isf=false;
									for(i=0;i<t;i++)
									{
										if($2.vali[i]=='.')
										{
										isf=true;
										break;
										}
									}
									bool isn = ($2.vali[0]=='-');
									if(isf)
									{
									CallError("Array dimensions should be an integer");
									}
									if(isn)
									{
									CallError("Array dimensions should be an positive integer");
									}

							functable[actfuncindex].vartable[functable[actfuncindex].varcount].dimcount=1;
							functable[actfuncindex].vartable[functable[actfuncindex].varcount].dim[0]=stoi($2.vali);
bracketnums[bracketcount] = stoi($3.vali);
	bracketcount++;
					  }
		;

IDS : ID 	{
				int finder;
				int checker;
				finder = InArr(functable[actfuncindex].paramtable,functable[actfuncindex].paramcount,$1.vali); 
				checker = InArr(functable[actfuncindex].vartable,functable[actfuncindex].varcount,$1.vali);
				if(finder!=-1 && globallevel==2)
				{
					char printer[1000];
					snprintf(printer,999,"Parameter with name %s already exists",$1.vali);
					CallError(printer);
				}
				else if(checker!=-1 && functable[actfuncindex].vartable[checker].level==globallevel)
				{
					char printer[1000];
					snprintf(printer,999,"Variable with name %s already exists in the current scope.",$1.vali);
					CallError(printer);
				}
				else
				{
					struct varrecord new_record;
					strcpy(new_record.varname,$1.vali);
					strcpy(new_record.vartype,"-1");
					new_record.tag=true;
					new_record.level = globallevel;
					new_record.IsArr = false;
					new_record.dimcount = 0;



					char finalname[1000];
					snprintf(finalname,999,"%s_%d_%s",new_record.varname,globallevel,functable[actfuncindex].name);
					strcpy(vars[totvars],finalname);
					strcpy(types[totvars],new_record.vartype);
					sizes[totvars]=0;
					totvars++;

					strcpy(new_record.finalname,finalname);
					functable[actfuncindex].vartable[functable[actfuncindex].varcount++]=new_record;

				}
			}
		;



FORASSIGN : ID EQ COR       {
																backpatch($3.bplist,$3.bpcount,nextquad);
								int finder;
								int checker,gchecker;
								finder = InArr(functable[actfuncindex].paramtable,functable[actfuncindex].paramcount,$1.vali); 
								checker = InArr(functable[actfuncindex].vartable,functable[actfuncindex].varcount,$1.vali);
								gchecker = InArr(functable[0].vartable,functable[0].varcount,$1.vali);

								if(checker==-1 && finder==-1 && gchecker==-1)
								{
									char printer[1000];
									snprintf(printer,999,"No such variable called %s exists",$1.vali);
									CallError(printer);
								}
								if(checker!=-1)
									strcpy($1.type,functable[actfuncindex].vartable[checker].vartype);
								else if (finder!=-1)
									strcpy($1.type,functable[actfuncindex].paramtable[finder].vartype);
								else if(gchecker!=-1)
									strcpy($1.type,functable[0].vartable[gchecker].vartype);


								if($3.tempreg==-1)
								{
									CallError("Void function does not return anything.");
								}
								else if($3.tempreg==-2)
								{
									CallError("Some error in assignment.");
								}
								else
								{
									char printer[1000];
									if(!strcmp($3.type,"int"))
									{
										if(!strcmp($1.type,"int"))
										{
											if(checker!=-1)
												snprintf(printer,999,"%s = t%d",functable[actfuncindex].vartable[checker].finalname,$3.tempreg);
											else if(finder!=-1)
												snprintf(printer,999,"%s = t%d",functable[actfuncindex].paramtable[finder].finalname,$3.tempreg);
											else
												snprintf(printer,999,"%s = t%d",functable[0].vartable[gchecker].finalname,$3.tempreg);

											releaseint($3.tempreg);

										}
										else
										{
											int gettemp=newfloat();
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp,$3.tempreg);
											GenQuad(printer);
											releaseint($3.tempreg);
											if(checker!=-1)
												snprintf(printer,999,"%s = f%d",functable[actfuncindex].vartable[checker].finalname,gettemp);
											else if(finder!=-1)
												snprintf(printer,999,"%s = f%d",functable[actfuncindex].paramtable[finder].finalname,gettemp);
											else
												snprintf(printer,999,"%s = f%d",functable[0].vartable[gchecker].finalname,gettemp);

											releasefloat(gettemp);
										}
									}
									if(!strcmp($3.type,"float"))
									{
										if(!strcmp($1.type,"float"))
										{
											if(checker!=-1)
												snprintf(printer,999,"%s = f%d",functable[actfuncindex].vartable[checker].finalname,$3.tempreg);
											else if(finder!=-1)
												snprintf(printer,999,"%s = f%d",functable[actfuncindex].paramtable[finder].finalname,$3.tempreg);
											else
												snprintf(printer,999,"%s = f%d",functable[0].vartable[gchecker].finalname,$3.tempreg);

											releasefloat($3.tempreg);

										}
										else
										{
											int gettemp=newint();
											snprintf(printer,999,"t%d = ConvertToInt(f%d)",gettemp,$3.tempreg);
											GenQuad(printer);
											releasefloat($3.tempreg);
											if(checker!=-1)
												snprintf(printer,999,"%s = t%d",functable[actfuncindex].vartable[checker].finalname,gettemp);
											else if(finder!=-1)
												snprintf(printer,999,"%s = t%d",functable[actfuncindex].paramtable[finder].finalname,gettemp);
											else
												snprintf(printer,999,"%s = t%d",functable[0].vartable[gchecker].finalname,gettemp);

											releaseint(gettemp);

										}										
									}
									GenQuad(printer);
								}

							}
			| ARRF EQ COR    {
								backpatch($3.bplist,$3.bpcount,nextquad);
									if($1.arr!=-1 && $1.ind!=-1)
									{
										if($3.tempreg==-1)
										{
											CallError("Void function does not return anything.");
										}
										else if($3.tempreg==-2)
										{
									CallError("Some error in assignment.");
										
										}
										else
										{
											char printer[1000];
											if(!strcmp($3.type,"int"))
											{
												if(!strcmp($1.type,"int"))
												{
													snprintf(printer,999,"t%d[t%d] = t%d",$1.arr,$1.ind,$3.tempreg);
													releaseint($3.tempreg);

												}
												else
												{
													int gettemp=newfloat();
													snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp,$3.tempreg);
													GenQuad(printer);
													releaseint($3.tempreg);
													
										
													snprintf(printer,999,"t%d[t%d] = f%d",$1.arr,$1.ind,gettemp);

													releasefloat(gettemp);
												}
											}
											if(!strcmp($3.type,"float"))
											{
												if(!strcmp($1.type,"float"))
												{
													
													snprintf(printer,999,"t%d[t%d] = f%d",$1.arr,$1.ind,$3.tempreg);

													releasefloat($3.tempreg);

												}
												else
												{
													int gettemp=newint();
													snprintf(printer,999,"t%d = ConvertToInt(f%d)",gettemp,$3.tempreg);
													GenQuad(printer);
													releasefloat($3.tempreg);
												
													snprintf(printer,999,"t%d[t%d] = t%d",$1.arr,$1.ind,gettemp);

													releaseint(gettemp);

												}										
											}
										GenQuad(printer);
										releaseint($1.arr);
										releaseint($1.ind);
									}
							}
							}
			;
ASSIGN : ID EQ COR SC       {
																backpatch($3.bplist,$3.bpcount,nextquad);
								int finder;
								int checker,gchecker;
								finder = InArr(functable[actfuncindex].paramtable,functable[actfuncindex].paramcount,$1.vali); 
								checker = InArr(functable[actfuncindex].vartable,functable[actfuncindex].varcount,$1.vali);
								gchecker = InArr(functable[0].vartable,functable[0].varcount,$1.vali);

								if(checker==-1 && finder==-1 && gchecker==-1)
								{
									char printer[1000];
									snprintf(printer,999,"No such variable called %s exists",$1.vali);
									CallError(printer);
								}
								if(checker!=-1)
									strcpy($1.type,functable[actfuncindex].vartable[checker].vartype);
								else if (finder!=-1)
									strcpy($1.type,functable[actfuncindex].paramtable[finder].vartype);
								else if(gchecker!=-1)
									strcpy($1.type,functable[0].vartable[gchecker].vartype);


								if($3.tempreg==-1)
								{
									CallError("Void function does not return anything.");
								}
								else if($3.tempreg==-2)
								{
									CallError("Some error in assignment.");
								}
								else
								{
									char printer[1000];
									if(!strcmp($3.type,"int"))
									{
										if(!strcmp($1.type,"int"))
										{
											if(checker!=-1)
												snprintf(printer,999,"%s = t%d",functable[actfuncindex].vartable[checker].finalname,$3.tempreg);
											else if(finder!=-1)
												snprintf(printer,999,"%s = t%d",functable[actfuncindex].paramtable[finder].finalname,$3.tempreg);
											else
												snprintf(printer,999,"%s = t%d",functable[0].vartable[gchecker].finalname,$3.tempreg);

											releaseint($3.tempreg);

										}
										else
										{
											int gettemp=newfloat();
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp,$3.tempreg);
											GenQuad(printer);
											releaseint($3.tempreg);
											if(checker!=-1)
												snprintf(printer,999,"%s = f%d",functable[actfuncindex].vartable[checker].finalname,gettemp);
											else if(finder!=-1)
												snprintf(printer,999,"%s = f%d",functable[actfuncindex].paramtable[finder].finalname,gettemp);
											else
												snprintf(printer,999,"%s = f%d",functable[0].vartable[gchecker].finalname,gettemp);

											releasefloat(gettemp);
										}
									}
									if(!strcmp($3.type,"float"))
									{
										if(!strcmp($1.type,"float"))
										{
											if(checker!=-1)
												snprintf(printer,999,"%s = f%d",functable[actfuncindex].vartable[checker].finalname,$3.tempreg);
											else if(finder!=-1)
												snprintf(printer,999,"%s = f%d",functable[actfuncindex].paramtable[finder].finalname,$3.tempreg);
											else
												snprintf(printer,999,"%s = f%d",functable[0].vartable[gchecker].finalname,$3.tempreg);

											releasefloat($3.tempreg);

										}
										else
										{
											int gettemp=newint();
											snprintf(printer,999,"t%d = ConvertToInt(f%d)",gettemp,$3.tempreg);
											GenQuad(printer);
											releasefloat($3.tempreg);
											if(checker!=-1)
												snprintf(printer,999,"%s = t%d",functable[actfuncindex].vartable[checker].finalname,gettemp);
											else if(finder!=-1)
												snprintf(printer,999,"%s = t%d",functable[actfuncindex].paramtable[finder].finalname,gettemp);
											else
												snprintf(printer,999,"%s = t%d",functable[0].vartable[gchecker].finalname,gettemp);

											releaseint(gettemp);

										}										
									}
									GenQuad(printer);
								}

							}
		| ARRF EQ COR SC     {
									backpatch($3.bplist,$3.bpcount,nextquad);
									if($1.arr!=-1 && $1.ind!=-1)
									{
										if($3.tempreg==-1)
										{
											CallError("Void function does not return anything.");
										}
										else if($3.tempreg==-2)
										{
									CallError("Some error in assignment.");
										
										}
										else
										{
											char printer[1000];
											if(!strcmp($3.type,"int"))
											{
												if(!strcmp($1.type,"int"))
												{
													snprintf(printer,999,"t%d[t%d] = t%d",$1.arr,$1.ind,$3.tempreg);
													releaseint($3.tempreg);

												}
												else
												{
													int gettemp=newfloat();
													snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp,$3.tempreg);
													GenQuad(printer);
													releaseint($3.tempreg);
													
										
													snprintf(printer,999,"t%d[t%d] = f%d",$1.arr,$1.ind,gettemp);

													releasefloat(gettemp);
												}
											}
											if(!strcmp($3.type,"float"))
											{
												if(!strcmp($1.type,"float"))
												{
													
													snprintf(printer,999,"t%d[t%d] = f%d",$1.arr,$1.ind,$3.tempreg);

													releasefloat($3.tempreg);

												}
												else
												{
													int gettemp=newint();
													snprintf(printer,999,"t%d = ConvertToInt(f%d)",gettemp,$3.tempreg);
													GenQuad(printer);
													releasefloat($3.tempreg);
												
													snprintf(printer,999,"t%d[t%d] = t%d",$1.arr,$1.ind,gettemp);

													releaseint(gettemp);

												}										
											}
										GenQuad(printer);
										releaseint($1.arr);
										releaseint($1.ind);
									}
							}
							}
		;

COR	: COR OR CAND               {
									backpatch($3.bplist,$3.bpcount,nextquad);
									if($1.countor==0)
									{
										$$.countor=1;

										int gettemp;
										gettemp=newint();
										char printer[1000];
										snprintf(printer,999,"t%d = 0 ",gettemp);
										GenQuad(printer);
										int temp2=$1.tempreg;
										if(!strcmp($1.type,"float"))
										{
											temp2=newint();
											snprintf(printer,999,"t%d = ConvertToInt(f%d)",temp2,$1.tempreg);
											releasefloat($1.tempreg);
											GenQuad(printer);
										}

										snprintf(printer,999,"if(t%d == 0) goto %d",temp2,nextquad+3);
										GenQuad(printer);
										snprintf(printer,999,"t%d = 1",gettemp);
										GenQuad(printer);
										snprintf(printer,999,"goto _____");
										$1.bpcount=0;
										$1.bplist[$1.bpcount++]=nextquad;
										GenQuad(printer);
										releaseint(temp2);
										releaseint($1.tempreg);
										$1.tempreg=gettemp;
									}
									int getcase = GiveType($1.type,$3.type);
									if(getcase==0)
										strcpy($$.type,"errortype");
									else
										strcpy($$.type,"int");	
									$$.caseallow=$1.caseallow && $3.caseallow;
									

									char printer[1000];
									int temp2=$3.tempreg;
									if(!strcmp($3.type,"float"))
									{
										temp2=newint();
										snprintf(printer,999,"t%d = ConvertToInt(f%d)",temp2,$3.tempreg);
										releasefloat($3.tempreg);
										GenQuad(printer);
									}

									snprintf(printer,999,"if(t%d == 0) goto %d",temp2,nextquad+3);
									GenQuad(printer);
									snprintf(printer,999,"t%d = 1",$1.tempreg);
									GenQuad(printer);
									snprintf(printer,999,"goto _____");
									$$.bpcount=0;

									for(int i=0;i<$1.bpcount;i++)
									{
										$$.bplist[$$.bpcount++]=$1.bplist[i];
									}
									$$.bplist[$$.bpcount++]=nextquad;

									GenQuad(printer);
									releaseint(temp2);
									releaseint($3.tempreg);
									$$.tempreg=$1.tempreg;

								}
		| CAND  				{
									
									backpatch($1.bplist,$1.bpcount,nextquad);
									$$.bpcount=0;
									strcpy($$.type,$1.type);
									$$.caseallow=$1.caseallow;
									$$.tempreg=$1.tempreg;
									$$.countor=0;


								}
		;
CAND : CAND AND CNOT  			{
									if($1.countand==0)
									{
										$$.countand=1;
										int gettemp;
										gettemp=newint();
										char printer[1000];
										snprintf(printer,999,"t%d = 1 ",gettemp);
										GenQuad(printer);

										int temp2=$1.tempreg;
										if(!strcmp($1.type,"float"))
										{
											temp2=newint();
											snprintf(printer,999,"t%d = ConvertToInt(f%d)",temp2,$1.tempreg);
											releasefloat($1.tempreg);
											GenQuad(printer);
										}


										snprintf(printer,999,"if(t%d != 0) goto %d",temp2,nextquad+3);
										GenQuad(printer);
										snprintf(printer,999,"t%d = 0",gettemp);
										GenQuad(printer);
										snprintf(printer,999,"goto _____");
										
										$1.bpcount=0;
										$1.bplist[$1.bpcount++]=nextquad;
										GenQuad(printer);
										releaseint(temp2);
										releaseint($1.tempreg);
										$1.tempreg=gettemp;
									}
									int getcase = GiveType($1.type,$3.type);
									if(getcase==0)
										strcpy($$.type,"errortype");
									else
										strcpy($$.type,"int");
									$$.caseallow=$1.caseallow && $3.caseallow;

									char printer[1000];
									int temp2=$3.tempreg;
									if(!strcmp($3.type,"float"))
									{
										temp2=newint();
										snprintf(printer,999,"t%d = ConvertToInt(f%d)",temp2,$3.tempreg);
										releasefloat($3.tempreg);
										GenQuad(printer);
									}

									snprintf(printer,999,"if(t%d != 0) goto %d",temp2,nextquad+3);
									GenQuad(printer);
									snprintf(printer,999,"t%d = 0",$1.tempreg);
									GenQuad(printer);
									snprintf(printer,999,"goto _____");
									$$.bpcount=0;
									for(int i=0;i<$1.bpcount;i++)
									{
										$$.bplist[$$.bpcount++]=$1.bplist[i];
									}
									$$.bplist[$$.bpcount++]=nextquad;

									GenQuad(printer);
									releaseint(temp2);
									releaseint($3.tempreg);
									$$.tempreg=$1.tempreg;

									

								}
		| CNOT                  {
									$$.bpcount=0;
									strcpy($$.type,$1.type);
									$$.caseallow=$1.caseallow;
									$$.tempreg=$1.tempreg;
									$$.countand=0;


								}
		;
CNOT : ECOMP  					{
									strcpy($$.type,$1.type);
									$$.caseallow=$1.caseallow;
									$$.tempreg=$1.tempreg;

								
								}
		| NOT ECOMP 			{
									if(!strcmp($1.type,"errortype"))
									strcpy($$.type,"errortype");
									else
									strcpy($$.type,"int");
									$$.caseallow=$2.caseallow;

									int gettemp;
									gettemp=newint();
									char printer[1000];
									snprintf(printer,999,"t%d = 1 ",gettemp);
									GenQuad(printer);
									int temp2=$2.tempreg;
									if(!strcmp($2.type,"float"))
									{
										temp2=newint();
										snprintf(printer,999,"t%d = ConvertToInt(f%d)",temp2,$2.tempreg);
										releasefloat($2.tempreg);
										GenQuad(printer);
									}

									snprintf(printer,999,"if(t%d == 0) goto %d",temp2,nextquad+2);
									GenQuad(printer);
									snprintf(printer,999,"t%d = 0",gettemp);
									GenQuad(printer);
									releaseint(temp2);
									releaseint($2.tempreg);
									$$.tempreg=gettemp;
								}
		;
ECOMP : ECOMP LT E              {
									int getcase = GiveType($1.type,$3.type);
									if(getcase==0)
										strcpy($$.type,"errortype");
									else
										strcpy($$.type,"int");
									$$.caseallow=$1.caseallow && $3.caseallow;
									int gettemp;
									if(getcase==1)
									{
										if(!strcmp($1.type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,$1.tempreg);
											GenQuad(printer);
											releaseint($1.tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d < f%d) goto %d",gettemp2,$3.tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat($3.tempreg);
										}
										else if(!strcmp($3.type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,$3.tempreg);
											GenQuad(printer);
											releaseint($3.tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d < f%d) goto %d",$1.tempreg,gettemp2,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat($1.tempreg);
										}
										else
										{
											char printer[1000];
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d < f%d) goto %d",$1.tempreg,$3.tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat($1.tempreg);
											releasefloat($3.tempreg);
										}
										
									
									}

									else if(getcase==2)
									{
											gettemp = newint();
											char printer[1000];
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(t%d < t%d) goto %d",$1.tempreg,$3.tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releaseint($3.tempreg);
											releaseint($1.tempreg);
									}
									$$.tempreg=gettemp;
								}
		| ECOMP LTE E  			{
									int getcase = GiveType($1.type,$3.type);
									if(getcase==0)
										strcpy($$.type,"errortype");
									else
										strcpy($$.type,"int");
									$$.caseallow=$1.caseallow && $3.caseallow;

									int gettemp;
									if(getcase==1)
									{
										if(!strcmp($1.type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,$1.tempreg);
											GenQuad(printer);
											releaseint($1.tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d <= f%d) goto %d",gettemp2,$3.tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat($3.tempreg);
										}
										else if(!strcmp($3.type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,$3.tempreg);
											GenQuad(printer);
											releaseint($3.tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d <= f%d) goto %d",$1.tempreg,gettemp2,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat($1.tempreg);
										}
										else
										{
											char printer[1000];
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d <= f%d) goto %d",$1.tempreg,$3.tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat($1.tempreg);
											releasefloat($3.tempreg);
										}
										
									
									}

									else if(getcase==2)
									{
											gettemp = newint();
											char printer[1000];
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(t%d <= t%d) goto %d",$1.tempreg,$3.tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releaseint($3.tempreg);
											releaseint($1.tempreg);
									}
									$$.tempreg=gettemp;
								
								}
		| ECOMP GT E 			{
									int getcase = GiveType($1.type,$3.type);
									if(getcase==0)
										strcpy($$.type,"errortype");
									else
										strcpy($$.type,"int");
									$$.caseallow=$1.caseallow && $3.caseallow;

									int gettemp;
									if(getcase==1)
									{
										if(!strcmp($1.type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,$1.tempreg);
											GenQuad(printer);
											releaseint($1.tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d > f%d) goto %d",gettemp2,$3.tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat($3.tempreg);
										}
										else if(!strcmp($3.type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,$3.tempreg);
											GenQuad(printer);
											releaseint($3.tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d > f%d) goto %d",$1.tempreg,gettemp2,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat($1.tempreg);
										}
										else
										{
											char printer[1000];
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d > f%d) goto %d",$1.tempreg,$3.tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat($1.tempreg);
											releasefloat($3.tempreg);
										}

										
									
									}

									else if(getcase==2)
									{
											gettemp = newint();
											char printer[1000];
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(t%d > t%d) goto %d",$1.tempreg,$3.tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releaseint($3.tempreg);
											releaseint($1.tempreg);
									}
									$$.tempreg=gettemp;
								
								}
		| ECOMP GTE E           {
									int getcase = GiveType($1.type,$3.type);
									if(getcase==0)
										strcpy($$.type,"errortype");
									else
										strcpy($$.type,"int");
									$$.caseallow=$1.caseallow && $3.caseallow;

									int gettemp;
									if(getcase==1)
									{
										if(!strcmp($1.type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,$1.tempreg);
											GenQuad(printer);
											releaseint($1.tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d >= f%d) goto %d",gettemp2,$3.tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat($3.tempreg);
										}
										else if(!strcmp($3.type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,$3.tempreg);
											GenQuad(printer);
											releaseint($3.tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d >= f%d) goto %d",$1.tempreg,gettemp2,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat($1.tempreg);
										}
										else
										{
											char printer[1000];
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d >= f%d) goto %d",$1.tempreg,$3.tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat($1.tempreg);
											releasefloat($3.tempreg);
										}
										
									
									}

									else if(getcase==2)
									{
											gettemp = newint();
											char printer[1000];
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(t%d >= t%d) goto %d",$1.tempreg,$3.tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releaseint($3.tempreg);
											releaseint($1.tempreg);
									}
									$$.tempreg=gettemp;
								
								}
		| ECOMP NEQ E           {
									int getcase = GiveType($1.type,$3.type);
									if(getcase==0)
										strcpy($$.type,"errortype");
									else
										strcpy($$.type,"int");
									$$.caseallow=$1.caseallow && $3.caseallow;

									int gettemp;
									if(getcase==1)
									{
										if(!strcmp($1.type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,$1.tempreg);
											GenQuad(printer);
											releaseint($1.tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d != f%d) goto %d",gettemp2,$3.tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat($3.tempreg);
										}
										else if(!strcmp($3.type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,$3.tempreg);
											GenQuad(printer);
											releaseint($3.tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d != f%d) goto %d",$1.tempreg,gettemp2,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat($1.tempreg);
										}
										else
										{
											char printer[1000];
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d != f%d) goto %d",$1.tempreg,$3.tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat($1.tempreg);
											releasefloat($3.tempreg);
										}
										
									
									}

									else if(getcase==2)
									{
											gettemp = newint();
											char printer[1000];
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(t%d != t%d) goto %d",$1.tempreg,$3.tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releaseint($3.tempreg);
											releaseint($1.tempreg);
									}
									$$.tempreg=gettemp;

								}
		| ECOMP EQEQ E          {
									int getcase = GiveType($1.type,$3.type);
									if(getcase==0)
										strcpy($$.type,"errortype");
									else
										strcpy($$.type,"int");
									$$.caseallow=$1.caseallow && $3.caseallow;

									int gettemp;
									if(getcase==1)
									{
										if(!strcmp($1.type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,$1.tempreg);
											GenQuad(printer);
											releaseint($1.tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d == f%d) goto %d",gettemp2,$3.tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat($3.tempreg);
										}
										else if(!strcmp($3.type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,$3.tempreg);
											GenQuad(printer);
											releaseint($3.tempreg);
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d == f%d) goto %d",$1.tempreg,gettemp2,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat($1.tempreg);
										}
										else
										{
											char printer[1000];
											gettemp = newint();
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(f%d == f%d) goto %d",$1.tempreg,$3.tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releasefloat($1.tempreg);
											releasefloat($3.tempreg);
										}
										
									
									}

									else if(getcase==2)
									{
											gettemp = newint();
											char printer[1000];
											snprintf(printer,999,"t%d = 1",gettemp);
											GenQuad(printer);
											
											snprintf(printer,999,"if(t%d == t%d) goto %d",$1.tempreg,$3.tempreg,nextquad+2);
											GenQuad(printer);
											snprintf(printer,999,"t%d = 0",gettemp);
											GenQuad(printer);
											releaseint($3.tempreg);
											releaseint($1.tempreg);
									}
									$$.tempreg=gettemp;

								}
		| E 					{
									strcpy($$.type,$1.type);
									$$.tempreg=$1.tempreg;
									$$.caseallow=$1.caseallow;

								}
		;
E : E PLUS T                    {
									int gettemp;
									
									int getcase = GiveType($1.type,$3.type);
									if(getcase==0)
										strcpy($$.type,"errortype");
									if(getcase == 3){
										strcpy($$.type, "lineseg");
										if(!strcmp($1.type,"point"))
										{
											// C++ x+A, y+A
										}else if(!strcmp($3.type,"point")){
											// C++ x+A, y+A
										}else{
											// Convert to C++
										}
									}
									if(getcase==1){
										strcpy($$.type,"float");
										if(!strcmp($1.type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
									
											
									
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,$1.tempreg);
											

											GenQuad(printer);
											
											releaseint($1.tempreg);

											gettemp = newfloat();
											snprintf(printer,999,"f%d = f%d + f%d",gettemp,gettemp2,$3.tempreg);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat($3.tempreg);



										}
										else if(!strcmp($3.type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,$3.tempreg);
											GenQuad(printer);
											releaseint($3.tempreg);

											gettemp = newfloat();

											snprintf(printer,999,"f%d = f%d + f%d",gettemp,$1.tempreg,gettemp2);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat($1.tempreg);

										}
										else
										{
											gettemp=newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = f%d + f%d",gettemp,$1.tempreg,$3.tempreg);
											GenQuad(printer);
											releasefloat($3.tempreg);
											releasefloat($1.tempreg);
										}
									}
									if(getcase==2){
										strcpy($$.type,"int");
										gettemp = newint();
										char printer[1000];

										snprintf(printer,999,"t%d = t%d + t%d",gettemp,$1.tempreg,$3.tempreg);
										GenQuad(printer);
										releaseint($3.tempreg);
										releaseint($1.tempreg);

									}
									$$.tempreg = gettemp;
									$$.caseallow=$1.caseallow && $3.caseallow;


								}
	| E HASHT T					{
									int gettemp;
									
									int getcase = GiveType($1.type,$3.type);
									if(getcase==0)
										strcpy($$.type,"errortype");
									if(getcase == 3){
										strcpy($$.type,"point");
										if(!strcmp($1.type,"point")){
											if(strcmp($1.type, "lineseg")){
												// C++ Linesegment # point, is on line or not?
												strcpy($$.type,"bool");
											}else if(strcmp($1.type, "int")){
												// C++ increment both x and y with int
											}else if(strcmp($1.type, "float")){
												// C++ increment both x and y with float
											}
										}else if(!strcmp($3.type,"point")){
											if(strcmp($3.type, "lineseg")){
												// C++ Linesegment # point, is on line or not?
												strcpy($$.type,"bool");
											}else if(strcmp($3.type, "int")){
												// C++ increment both x and y with int
											}else if(strcmp($3.type, "float")){
												// C++ increment both x and y with float
											}
										}else{
											// C++ add two points
										}
									}
									if(getcase==1){
										strcpy($$.type,"point");
										if(!strcmp($1.type,"int"))
										{
											// C++ convert int to float and x-axis value
										}
										else if(!strcmp($3.type,"int"))
										{
											// C++ convert int to float and y-axis value
										}
										else
										{
											// C++ Make the floats as axis points
										}
									}
									if(getcase==2){
										strcpy($$.type,"point");
										// C++ Make the floats as axis points
									}
									strcpy($$.type,"point");
									$$.tempreg = gettemp;
									$$.caseallow=$1.caseallow && $3.caseallow;
								}
	| E MINUS T 				{
									int gettemp;
									
									int getcase = GiveType($1.type,$3.type);
									if(getcase==0)
										strcpy($$.type,"errortype");
									if(getcase == 3){
										strcpy($$.type, "float");
										if(!strcmp($1.type,"point"))
										{
											// C++ x+A, y+A
										}else if(!strcmp($3.type,"point")){
											// C++ x+A, y+A
										}else{
											// Convert to C++
										}
									}
									if(getcase==1){
										strcpy($$.type,"float");
										if(!strcmp($1.type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
									
											
									
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,$1.tempreg);
											

											GenQuad(printer);
											
											releaseint($1.tempreg);

											gettemp = newfloat();
											snprintf(printer,999,"f%d = f%d - f%d",gettemp,gettemp2,$3.tempreg);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat($3.tempreg);



										}
										else if(!strcmp($3.type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,$3.tempreg);
											GenQuad(printer);
											releaseint($3.tempreg);

											gettemp = newfloat();

											snprintf(printer,999,"f%d = f%d - f%d",gettemp,$1.tempreg,gettemp2);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat($1.tempreg);

										}
										else
										{
											gettemp=newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = f%d - f%d",gettemp,$1.tempreg,$3.tempreg);
											GenQuad(printer);
											releasefloat($3.tempreg);
											releasefloat($1.tempreg);
										}
									}
									if(getcase==2){
										strcpy($$.type,"int");
										gettemp = newint();
										char printer[1000];

										snprintf(printer,999,"t%d = t%d - t%d",gettemp,$1.tempreg,$3.tempreg);
										GenQuad(printer);
										releaseint($3.tempreg);
										releaseint($1.tempreg);

									}
									$$.tempreg = gettemp;
									$$.caseallow=$1.caseallow && $3.caseallow;


								}
	| T 						{
									strcpy($$.type,$1.type);
									$$.tempreg=$1.tempreg;
									$$.caseallow=$1.caseallow;

								}
	;
T : T MULT F 					{
									int gettemp;
									
									int getcase = GiveType($1.type,$3.type);
									if(getcase==0)
										strcpy($$.type,"errortype");
									if(getcase==1){
										strcpy($$.type,"float");
										if(!strcmp($1.type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
									
											
									
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,$1.tempreg);
											

											GenQuad(printer);
											
											releaseint($1.tempreg);

											gettemp = newfloat();
											snprintf(printer,999,"f%d = f%d * f%d",gettemp,gettemp2,$3.tempreg);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat($3.tempreg);



										}
										else if(!strcmp($3.type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,$3.tempreg);
											GenQuad(printer);
											releaseint($3.tempreg);

											gettemp = newfloat();

											snprintf(printer,999,"f%d = f%d * f%d",gettemp,$1.tempreg,gettemp2);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat($1.tempreg);

										}
										else
										{
											gettemp=newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = f%d * f%d",gettemp,$1.tempreg,$3.tempreg);
											GenQuad(printer);
											releasefloat($3.tempreg);
											releasefloat($1.tempreg);
										}
									}
									if(getcase==2){
										strcpy($$.type,"int");
										gettemp = newint();
										char printer[1000];

										snprintf(printer,999,"t%d = t%d * t%d",gettemp,$1.tempreg,$3.tempreg);
										GenQuad(printer);
										releaseint($3.tempreg);
										releaseint($1.tempreg);

									}
									$$.tempreg = gettemp;
									$$.caseallow=$1.caseallow && $3.caseallow;

									



								}
	| T DIV F                   {
									int gettemp;
									
									int getcase = GiveType($1.type,$3.type);
									if(getcase==0)
										strcpy($$.type,"errortype");
									if(getcase==1){
										strcpy($$.type,"float");
										if(!strcmp($1.type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
									
											
									
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,$1.tempreg);
											

											GenQuad(printer);
											
											releaseint($1.tempreg);

											gettemp = newfloat();
											snprintf(printer,999,"f%d = f%d / f%d",gettemp,gettemp2,$3.tempreg);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat($3.tempreg);



										}
										else if(!strcmp($3.type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,$3.tempreg);
											GenQuad(printer);
											releaseint($3.tempreg);

											gettemp = newfloat();

											snprintf(printer,999,"f%d = f%d / f%d",gettemp,$1.tempreg,gettemp2);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat($1.tempreg);

										}
										else
										{
											gettemp=newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = f%d / f%d",gettemp,$1.tempreg,$3.tempreg);
											GenQuad(printer);
											releasefloat($3.tempreg);
											releasefloat($1.tempreg);
										}
									}
									if(getcase==2){
										strcpy($$.type,"int");
										gettemp = newint();
										char printer[1000];

										snprintf(printer,999,"t%d = t%d / t%d",gettemp,$1.tempreg,$3.tempreg);
										GenQuad(printer);
										releaseint($3.tempreg);
										releaseint($1.tempreg);

									}
									$$.tempreg = gettemp;
									$$.caseallow=$1.caseallow && $3.caseallow;


								}
	| T MOD F 					{
									int gettemp;
									
									int getcase = GiveType($1.type,$3.type);
									if(getcase==0)
										strcpy($$.type,"errortype");
									if(getcase==1){
										strcpy($$.type,"float");
										if(!strcmp($1.type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
									
											
									
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,$1.tempreg);
											

											GenQuad(printer);
											
											releaseint($1.tempreg);

											gettemp = newfloat();
											snprintf(printer,999,"f%d = f%d %% f%d",gettemp,gettemp2,$3.tempreg);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat($3.tempreg);



										}
										else if(!strcmp($3.type,"int"))
										{
											int gettemp2;
											gettemp2 = newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = ConvertToFloat(t%d)",gettemp2,$3.tempreg);
											GenQuad(printer);
											releaseint($3.tempreg);

											gettemp = newfloat();

											snprintf(printer,999,"f%d = f%d %% f%d",gettemp,$1.tempreg,gettemp2);
											GenQuad(printer);
											releasefloat(gettemp2);
											releasefloat($1.tempreg);

										}
										else
										{
											gettemp=newfloat();
											char printer[1000];
											snprintf(printer,999,"f%d = f%d %% f%d",gettemp,$1.tempreg,$3.tempreg);
											GenQuad(printer);
											releasefloat($3.tempreg);
											releasefloat($1.tempreg);
										}
									}
									if(getcase==2){
										strcpy($$.type,"int");
										gettemp = newint();
										char printer[1000];

										snprintf(printer,999,"t%d = t%d %% t%d",gettemp,$1.tempreg,$3.tempreg);
										GenQuad(printer);
										releaseint($3.tempreg);
										releaseint($1.tempreg);

									}
									$$.tempreg = gettemp;
									$$.caseallow=$1.caseallow && $3.caseallow;

								}

	| F 						{
									strcpy($$.type,$1.type);
									$$.tempreg=$1.tempreg;
									$$.caseallow=$1.caseallow;


								}
	;
F : ID 							{
									int find = InArr(functable[actfuncindex].vartable,functable[actfuncindex].varcount,$1.vali);
									int pfind = InArr(functable[actfuncindex].paramtable,functable[actfuncindex].paramcount,$1.vali);
									int gfind = InArr(functable[0].vartable,functable[0].varcount,$1.vali);

									if(find==-1 && pfind==-1 && gfind==-1)
									{
										char printer1[1000];
										snprintf(printer1,999,"No such variable called %s exists",$1.vali);
										CallError(printer1);
										strcpy($$.type,"errortype");

									}
									else
									{
										if(find!=-1 && functable[actfuncindex].vartable[find].dimcount>0)
										{
											CallError("Arrays can't be used directly like this.");
										}

										int gettemp;

										if(find!=-1)
										{
											strcpy($$.type,functable[actfuncindex].vartable[find].vartype);

												if(!strcmp($$.type,"int"))
												{
													gettemp = newint();

													char printer[1000];
													snprintf(printer,999,"t%d = %s",gettemp,functable[actfuncindex].vartable[find].finalname);

													GenQuad(printer);
												}
												else
												{
													gettemp = newfloat();

													char printer[1000];
													snprintf(printer,999,"f%d = %s",gettemp,functable[actfuncindex].vartable[find].finalname);
													GenQuad(printer);
												}

										}
										else if(pfind!=-1)
										{
											strcpy($$.type,functable[actfuncindex].paramtable[pfind].vartype);

												if(!strcmp($$.type,"int"))
												{
													gettemp = newint();

													char printer[1000];
													snprintf(printer,999,"t%d = %s",gettemp,functable[actfuncindex].paramtable[pfind].finalname);
													GenQuad(printer);

			
												}
												else
												{
													gettemp = newfloat();
													char printer[1000];
													snprintf(printer,999,"f%d = %s",gettemp,functable[actfuncindex].paramtable[pfind].finalname);
													GenQuad(printer);
													
												}
										}
										else if(gfind!=-1)
										{
											if(gfind!=-1 && functable[0].vartable[gfind].dimcount>0)
											{
												CallError("Arrays can't be used directly like this.");
											}
											strcpy($$.type,functable[0].vartable[gfind].vartype);

												if(!strcmp($$.type,"int"))
												{
													gettemp = newint();

													char printer[1000];
													snprintf(printer,999,"t%d = %s",gettemp,functable[0].vartable[gfind].finalname);

													GenQuad(printer);
												}
												else
												{
													gettemp = newfloat();

													char printer[1000];
													snprintf(printer,999,"f%d = %s",gettemp,functable[0].vartable[gfind].finalname);
													GenQuad(printer);
												}
										}
										$$.tempreg=gettemp;

									}
									$$.caseallow=false;
								}							

	| NUM						{
									int gettemp;
									int t = strlen($1.vali);
									int i=0;
									bool isf=false;
									for(i=0;i<t;i++)
									{
										if($1.vali[i]=='.')
										{
										isf=true;
										break;
										}
									}
									if(isf)
									{
										strcpy($$.type,"float");

										gettemp = newfloat();
										char printer[1000];
										snprintf(printer,999,"f%d = %s",gettemp,$1.vali);
										GenQuad(printer);

										
									}
									else
									{
										strcpy($$.type,"int");
										gettemp = newint();

										char printer[1000];
										snprintf(printer,999,"t%d = %s",gettemp,$1.vali);
										GenQuad(printer);
									}
									$$.tempreg=gettemp;

									$$.caseallow=true;



								}
	| FUNC_CALL 				{
									strcpy($$.type,$1.type);
									$$.tempreg=$1.tempreg;

									if($$.tempreg==-1)
									{
										CallError("Void Function does not return anything.");
									}
									$$.caseallow=false;



								}     
	| OPT COR CPT 				{
									strcpy($$.type,$2.type);
									$$.tempreg=$2.tempreg;

									$$.caseallow=$2.caseallow;
									backpatch($2.bplist,$2.bpcount,nextquad);


								}
	| ARRF  					{
									int tempreg=-2;
									char printer[1000];

									if($1.arr!=-1 && $1.ind!=-1)
									{
										if(!strcmp($1.type,"int"))
										{
											tempreg = newint();
											snprintf(printer,999,"t%d = t%d[t%d]",tempreg,$1.arr,$1.ind);
											GenQuad(printer);
											releaseint($1.arr);
											releaseint($1.ind);
										}
										else if(!strcmp($1.type,"float"))
										{
											tempreg = newfloat();
											snprintf(printer,999,"f%d = t%d[t%d]",tempreg,$1.arr,$1.ind);
											GenQuad(printer);
											releaseint($1.arr);
											releaseint($1.ind);
										}
									}
									strcpy($$.type,$1.type);
									$$.tempreg=tempreg;
									$$.caseallow=false;

								}
	;


ARRF : PARROW ID ARRFLIST 				{
									$$.arr=-1;
									$$.ind=-1;
									strcpy($$.type,"errortype");


									int find = InArr(functable[actfuncindex].vartable,functable[actfuncindex].varcount,$2.vali);
									int gfind = InArr(functable[0].vartable,functable[0].varcount,$2.vali);

									if(find==-1 && gfind==-1)
									{
										char printer1[1000];
										snprintf(printer1,999,"No such variable called %s exists",$2.vali);
										CallError(printer1);
										strcpy($$.type,"errortype");

									}
									else if(find!=-1)
									{
										if(find!=-1 && functable[actfuncindex].vartable[find].dimcount==0)
										{
											CallError("Such indexing not possible in simple variables.");
										}
										else
										{
											if(functable[actfuncindex].vartable[find].dimcount!=$3.bpcount)
											{
												CallError("Number of dimensions not matching in array use.");	
											}
											else 
											{
												int getarr = newint();
												char printer[1000];
												snprintf(printer,999,"Load t%d %s",getarr,functable[actfuncindex].vartable[find].finalname);
												GenQuad(printer);

												int getindex = newint();
												int extra = newint();

												snprintf(printer,999,"t%d = 0",getindex);
												GenQuad(printer);

												for(int i=0;i<$3.bpcount;i++)
												{
													snprintf(printer,999,"t%d = %d",extra,functable[actfuncindex].vartable[find].moddim[i]);
													GenQuad(printer);

													snprintf(printer,999,"t%d = t%d * t%d",extra,extra,$3.bplist[i]);
													releaseint($3.bplist[i]);
													GenQuad(printer);

													snprintf(printer,999,"t%d = t%d + t%d",getindex,getindex,extra);
													GenQuad(printer);
												}

												snprintf(printer,999,"t%d = 4",extra);
												GenQuad(printer);
												snprintf(printer,999,"t%d = t%d * t%d",getindex,getindex,extra);
												GenQuad(printer);

												releaseint(extra);

												$$.arr=getarr;
												$$.ind=getindex;
												strcpy($$.type,functable[actfuncindex].vartable[find].vartype);
											}	
										}
									}
									else if(gfind!=-1)
									{
										if(gfind!=-1 && functable[0].vartable[gfind].dimcount==0)
										{
											CallError("Such indexing not possible in simple variables.");
										}
										else
										{
											if(functable[0].vartable[gfind].dimcount!=$3.bpcount)
											{
												CallError("Number of dimensions not matching in array use.");	
											}
											else 
											{
												int getarr = newint();
												char printer[1000];
												snprintf(printer,999,"Load t%d %s",getarr,functable[0].vartable[gfind].finalname);
												GenQuad(printer);

												int getindex = newint();
												int extra = newint();

												snprintf(printer,999,"t%d = 0",getindex);
												GenQuad(printer);

												for(int i=0;i<$3.bpcount;i++)
												{
													snprintf(printer,999,"t%d = %d",extra,functable[0].vartable[gfind].moddim[i]);
													GenQuad(printer);

													snprintf(printer,999,"t%d = t%d * t%d",extra,extra,$3.bplist[i]);
													releaseint($3.bplist[i]);
													GenQuad(printer);

													snprintf(printer,999,"t%d = t%d + t%d",getindex,getindex,extra);
													GenQuad(printer);
												}

												snprintf(printer,999,"t%d = 4",extra);
												GenQuad(printer);
												snprintf(printer,999,"t%d = t%d * t%d",getindex,getindex,extra);
												GenQuad(printer);

												releaseint(extra);

												$$.arr=getarr;
												$$.ind=getindex;
												strcpy($$.type,functable[0].vartable[gfind].vartype);
											}	
										}
									}
								}
		;

ARRFLIST : ARRFLIST OSQ COR CSQ     {
										backpatch($3.bplist,$3.bpcount,nextquad);
										if(strcmp($3.type,"int"))
										{
											CallError("Array indices should compute to integers.");
										}
										$$.bpcount=0;
										for(int i=0;i<$1.bpcount;i++)
										{
											$$.bplist[$$.bpcount++]=$1.bplist[i];
										}
										$$.bplist[$$.bpcount++]=$3.tempreg;
									}
		| OSQ COR CSQ 				{
										backpatch($2.bplist,$2.bpcount,nextquad);
										if(strcmp($2.type,"int"))
										{
											CallError("Array indices should compute to integers.");
										}
										$$.bpcount=0;

										$$.bplist[$$.bpcount++]=$2.tempreg;
									}
		;


%%

int GiveType(char s1[],char s2[])
{
	if(!strcmp(s1,"errortype") || !strcmp(s2,"errortype"))
	return 0;
	
	if(!strcmp(s1,"point") || !strcmp(s2,"point"))
	return 3;

	if(!strcmp(s1,"float") || !strcmp(s2,"float"))
	return 1;

	return 2;

}
int InArr (struct varrecord arr[],int size,char finder[])
{
	int i=0;
	for(i=size-1;i>=0;i--)
	{
		if(!strcmp(arr[i].varname,finder))
			return i;

	}
	return -1;
}

bool CheckVar (struct varrecord arr[],int size,char finder[],int level)
{
	int i=0;
	for(i=0;i<size;i++)
	{
		if(!strcmp(arr[i].varname,finder) && arr[i].level==level)
			return true;

	}
	return false;
}

void PrintVars(struct varrecord var)
{
    printf("%s %s", var.vartype, var.finalname);
    
    if (var.IsArr)
    {
        printf("[");
        for (int i = 0; i < var.dimcount; i++)
        {
            printf("%d", var.dim[i]);
            if (i < var.dimcount - 1)
                printf(",");
        }
        printf("]");
    }

    printf("\n");
}

void PrintFuncs(struct funcrecord a)
{

	printf("\n==============================================");
    printf("Function: %s\n", a.name);
    printf("Type: %s\n", a.type);
    
    // Print parameters
    printf("\nParameters (%d):\n", a.paramcount);
    for (int i = 0; i < a.paramcount; i++)
    {
        printf("  - ");
        PrintVars(a.paramtable[i]);
    }

    // Print variables
    printf("Variables (%d):\n", a.varcount);
    for (int i = 0; i < a.varcount; i++)
    {
        printf("  - ");
        PrintVars(a.vartable[i]);
    }

    // Print separator
    printf("==============================================\n");
}



void backpatch(int* arr, int len, int x)
{
	for (int i = 0; i < len; ++i)
		for (int j = 0; j < len; ++j)
			if(arr[i]<arr[j])
			{
				int t=arr[i];
				arr[i]=arr[j];
				arr[j]=t;

			}

	

	fseek(fp,0,0);
	int currLineNumber = 1;
	for (int i = 0; i < len; ++i)
	{
		while(1)
		{
			if(currLineNumber == arr[i])
			{
				char temp[300];
				char tempi=0;
				while(1)
				{
					char cx = getc(fp);
					temp[tempi] = cx;
					tempi++;
					if(cx=='\n')
						break;
				}
				temp[tempi]='\0';

				char new[5];
				sprintf(new,"%d",x);
				
				for (int ix = 0; ix < strlen(new); ++ix)
					temp[tempi-6+ix]=new[ix];
				
				for (int iy = strlen(new); iy < 5; ++iy)
					temp[tempi-6+iy] = ' ';
				
				fseek(fp,-tempi,SEEK_CUR);
				fputs(temp, fp);
				currLineNumber++;
				break;
			}
			char c = getc(fp);
			if(c=='\n')
			{
				currLineNumber++;
			}
		}
	}
	fseek(fp, 0, SEEK_END);
}


void PrintFuncTable()
{
	int i=0;
	for(i=0;i<actfuncindex;i++)
		PrintFuncs(functable[i]);
}

void GenQuad(char*s)
{
	fprintf(fp,"%d: %s\n",nextquad,s);
	nextquad++;
}
void CallError(char*s)
{
	printf("Semantic Error at Line #%d : ",lines+1);
	printf("%s\n",s);
	success=false;
}

void CallWarning(char*s)
{
	printf("Semantic Warning at Line #%d : ",lines+1);
	printf("%s\n",s);
}

void yyerror (char *s) {
	success=false;
	printf("Syntax Error at line %d\n",lines+1);	
}

/*void despace(char target[], char input[], int l){
	int start=0, end=l-1;
	while(input[start]==' ' || input[start]=='\t') start++;
	while(input[end]==' ' || input[end]=='\t' || input[end]=='\n') end--;
	int y=0;
	for (int i = start; i <= end; ++i)
	{
		target[y++]=input[i];
	}
	target[y]='\0';
}*/
int newint()
{
	for(int i=0;i<10;i++)
	{
		if(!intreg[i])
			{intreg[i]=true;return i;}
	}
	return -1;
}
int newfloat()
{
	for(int i=0;i<10;i++)
	{
		if(!floatreg[i])
			{floatreg[i]=true;return i;}
	}
	return -1;
}
void releaseint(int i)
{
	if(i!=-1)
	intreg[i]=false;
}
void releasefloat(int i)
{
	if(i!=-1)
	floatreg[i]=false;
}
int stoi(char*s)
{
	int l=strlen(s);
	int ans=0;
	int i=0;
	for(i=0;i<l;i++)
	{
	ans=ans*10+(s[i]-48);
	}
	return ans;
}
bool isFtype(char line[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(line[i]=='(')
		return true;
	}
	return false;
}
bool isVar(char line[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			if(line[i]>='a' && line[i]<='z' || line[i]>='A' && line[i]<='Z')
			{

			}
			else
			{
				return false;
			}
		}
		else
		{
			if(line[i]>='a' && line[i]<='z' || line[i]>='A' && line[i]<='Z' || line[i]>='0' && line[i]<='9' || line[i]=='_' )
			{

			}
			else
			{
				return false;
			}
		}
	}
	return true;
}

bool NotEmpty(char line[],int l)
{
	for(int i=0;i<l;i++)
	{
		if(line[i]==' ' || line[i]=='\t' || line[i]=='\n')
		{

		}
		else
		{
			return true;
		}
	}
	return false;
}

int main(int argc, char const * argv[])
{
    char filename[100];
    snprintf(filename,999,"%s",argv[1]);
    char filename1[100];
    char filename2[100];
    snprintf(filename1,999,"%s",argv[2]);
    snprintf(filename2,999,"%s",argv[3]);

	trans = fopen("svas.cpp", "w");
	if(!trans){
		printf("Error opening!");
		exit(1);
	}
	fil=fopen(filename,"r");

	char new_name[1000];
	snprintf(new_name,999,"%s_Modified.txt",filename);
	FILE*fil1=fopen(new_name,"w");

	int ctr=0;
	char line[1000];
	char nline[1000];
	
	bool app=true;
	char printer[1000];
	while(fgets(line,sizeof(line),fil))
	{
		if(isFtype(line,strlen(line)))
		{
			app=false;
			fprintf(fil1,"%s",line);
		}
		else
		{
			if(app && NotEmpty(line,strlen(line)))
			{
				fprintf(fil1,"$$ %s",line);
			}
			else
			{
				fprintf(fil1,"%s",line);
			}

		}
	}
	fclose(fil);

	fclose(fil1);
	fil1=fopen(new_name,"r");



	yyin=fil1;
	int i=0;
	for(i=0;i<10;i++){
		intreg[i]=false;
		floatreg[i]=false;
	}
	fp=fopen(filename1,"w+");

	yyparse();

	fclose(fp);
	fclose(fil1);
	remove(new_name);

	if(success)
		printf("Compilation Successful!!\n");
	else
		printf("Error in Compilation.\n");

	printf("==============================================\n");

	FILE*varfile=fopen(filename2,"w");
	for(int i=0;i<totvars;i++)
	{
	fprintf(varfile,"%s,%s,%d\n",vars[i],types[i],sizes[i]*4);
	}
	fclose(varfile);

	FILE*successf=fopen("Res.txt","w");
	if(success){
		fprintf(successf,"1");
	}
	else
	{
		fprintf(successf,"0");
		
	}
	fclose(successf);
	PrintFuncTable();
	fclose(trans);

	return 0;
}