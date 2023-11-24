%{
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>




%}

%start	START


%token	SELECT
%token	PRINT
%token	INT
%token	FLT
%token	ID

%token FIVESTAR

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
%token SWITCHT
%token CASET
%token BREAK
%token DEFAULT

%token CSQ
%token OSQ
%token NUM
%token DOL



%%

START : INPUTGLOBAL
		;

INPUTGLOBAL : MGL GLIST NGL INPUT
				| NGL INPUT
				;

NGL    : 
		;
MGL  :
		 ;

GLIST : GLIST DOL VAR_DECL
		| DOL VAR_DECL
		;

INPUT : FUNC_DECL INPUT
		| FUNC_DECL
		;

FUNC_DECL : FUNC_HEAD BODY 
				| error SC 

		    ;
FUNC_HEAD : RESULT_ID OPT DECLISTE CPT  
			;
RESULT_ID : RESULT ID 
			;
RESULT : INT      
		| FLT	  
		| VOID    
		;
DECLISTE : DECLIST
		| ;
DECLIST : DECLIST COMMA DEC
			| DEC
			;
DEC : TYPE ID 				
		;
	| TYPE ARRFUNC 					
		;
ARRFUNC : ID LISTFUNC     
		;


LISTFUNC : LISTFUNC OSQ CSQ  
			| OSQ CSQ    
			;

BODY : OCURLY SLIST CCURLY  
		;
SLIST : SLIST MSLIST S     
		| S                
		;
MSLIST : 

S:      error SC  
		| VAR_DECL 
		| ASSIGN 
		| IFELSE 
		| FOR    
		| WHILE  
		| INCRLEVEL BODY	
		| FUNC_CALL SC 
		| RETURN SC 
		| FIVESTAR
		| SWITCH 
		| BREAK SC 		
		| PRINT OPT COR CPT  SC     
		; 

INCRLEVEL :  
			;
RETURN : RET           
		| RET COR   
		;

FUNC_CALL : IDTEMP OPT PARAMLIST CPT
			;
IDTEMP : ID 			
		;
PARAMLIST : PLIST 		
			|			
			;
PLIST : PLIST COMMA COR 
		| COR 						
		;



WHILE : WHILEXP BODY				
		;
WHILEXP : WHILET MWHILE OPT COR CPT 
		;
MWHILE :           
		;



FOR : FOREXP BODY 
		;

FOREXP : FORBACK1 FORBACK2 
		;
FORBACK1 : FORT OPT ASSIGN MFOR COR SC 
 		;

FORBACK2: NFOR FORASSIGN CPT 
		;
MFOR : 
	   ;
NFOR : 
		;




IFELSE : IFEXP BODY                   
		| IFEXP BODY NIF ELSE MIF BODY 
		;
NIF : 								
	;
MIF :  											
		;
IFEXP : IF OPT COR CPT  						
		;




VAR_DECL : TYPE L SC 				
		;
TYPE : INT 
	| FLT  	
	;
L : L COMMA IDS
	| IDS   
	| L COMMA ARRS
	| ARRS            
	;

ARRS : ARR
		;

ARR : ID BRLIST                
		;
BRLIST : BRLIST OSQ NUM CSQ    
		| OSQ NUM CSQ 
		;

IDS : ID 	
		;



FORASSIGN : ID EQ COR      
			| ARRF EQ COR   
			;
ASSIGN : ID EQ COR SC      
		| ARRF EQ COR SC     
		;

COR	: COR OR CAND               
		| CAND  				
		;
CAND : CAND AND CNOT  			
		| CNOT                  
		;
CNOT : ECOMP  					
		| NOT ECOMP 			
		;
ECOMP : ECOMP LT E              
		| ECOMP LTE E  			
		| ECOMP GT E 			
		| ECOMP GTE E          
		| ECOMP NEQ E          
		| ECOMP EQEQ E          
		| E 					
		;
E : E PLUS T                   
	| E MINUS T 				
	| T 						
	;
T : T MULT F 					
	| T DIV F                 
	| T MOD F 					
	| F 						
	;
F : ID 													

	| NUM						
	| FUNC_CALL 				 
	| OPT COR CPT 				
	| ARRF  					
	;


ARRF : ID ARRFLIST 				
		;

ARRFLIST : ARRFLIST OSQ COR CSQ    
		| OSQ COR CSQ 				
		;

SWITCH : SWITCHET OCURLY CASES CCURLY 		
		; 

SWITCHET : SWITCHT  OPT COR CPT 			
			;
CASES : CASELIST MCASE DEFAULTE 
		| CASELIST				
		;

DEFAULTE : DEFAULT COLON SLIST  
			;

CASELIST : CASELIST CASE 
		   | CASE     
		   ;
CASE : CASETEMP CMARK CBODY 							
		;

CMARK : ;
CASETEMP : CASET NCASE COR COLON      					
			;                
CBODY : SLIST  
		;
MCASE :; 
NCASE : ; 


%%


int main(int argc, char const * argv[])
{

	return 0;
}
