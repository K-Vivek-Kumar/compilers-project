%{
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
%}

%start Program

%token SELECT PRINT INT FLT ID FIVESTAR SC SP COMMA COLON EQ OR AND NOT LT LTE GT GTE EQEQ NEQ PLUS MINUS MULT DIV MOD OPT CPT OCURLY CCURLY IF ELSE FORT WHILET VOID RET SWITCHT CASET BREAK DEFAULT CSQ OSQ NUM DOL POINT

%%

Program : GlobalInput
        ;

GlobalInput : ModuleGlobalList FunctionList NestedGlobalInput
            | NestedGlobalInput
            ;

NestedGlobalInput : /* empty */
                 ;

ModuleGlobalList : ModuleGlobalList DOL VariableDeclaration
                 | DOL VariableDeclaration
                 ;

VariableDeclaration : TypeDecl ListOfIds SC
                  | TypeDecl PointDecl SC
                  ;

TypeDecl : INT
         | FLT
         ;

PointDecl : POINT ID EQ OPAREN NUM COMMA NUM CPAREN
          ;

ListOfIds : ListOfIds COMMA ID
          | ID
          ;

FunctionList : FunctionDeclaration FunctionList
             | /* empty */
             ;

FunctionDeclaration : FunctionHead FunctionBody
                  | error SC
                  ;

FunctionHead : ReturnType ID OptionalParams CPT
             ;

ReturnType : INT
          | FLT
          | VOID
          ;

OptionalParams : ParamList
               | /* empty */
               ;

ParamList : ParamList COMMA Parameter
          | Parameter
          ;

Parameter : TypeDecl ArrayFunc
          | ID ArrayFunc
          ;

ArrayFunc : ListFunc
          | /* empty */
          ;

ListFunc : ListFunc OSQ CSQ
         | OSQ CSQ
         ;

FunctionBody : OCURLY StatementList CCURLY
             ;

StatementList : StatementList Statement
              | Statement
              ;

Statement : error SC
          | VariableDeclaration
          | Assignment SC
          | IfElseStatement
          | ForStatement
          | WhileStatement
          | IncrementLevelStatement FunctionBody
          | FunctionCall SC
          | ReturnStatement SC
          | FIVESTAR
          | SwitchStatement
          | BREAK SC
          | PrintStatement SC
          | Expression SC
          ;

IfElseStatement : IfExpression FunctionBody
               | IfExpression FunctionBody NIf ELSE MIf FunctionBody
               ;

NIf : /* empty */
    ;

MIf : /* empty */
    ;

IfExpression : IF OPT OCURLY CCURLY
             ;

ForStatement : ForExpression FunctionBody
             ;

ForExpression : FORT OPT Assignment MFor SC
             ;

MFor : /* empty */
     ;

WhileStatement : WhileExpression FunctionBody
              ;

WhileExpression : WHILET MWhile OPT OCURLY CCURLY
               ;

MWhile : /* empty */
       ;

IncrementLevelStatement : /* empty */
                      ;

ReturnStatement : RET OptionalReturn SC
               ;

OptionalReturn : RET
              | RET OCURLY CCURLY
              ;

FunctionCall : ID OptionalParams CPT
             ;

Assignment : ID EQ OCURLY CCURLY
           | ArrayFunc EQ OCURLY CCURLY
           | PointDecl
           | ID EQ Expression
           | ArrayFunc EQ Expression
           ;

SwitchStatement : SWITCHET OCURLY CaseList Default SC CCURLY
               ;

SwitchExpression : SWITCHT OPT OCURLY CCURLY
                ;

CaseList : CaseList Case
         | Case
         ;

Case : CaseTemp CMARK CaseBody
     ;

CaseTemp : CASET NCase OCURLY CCURLY
        ;

CaseBody : StatementList
         ;

NCase : /* empty */
      ;

Default : DEFAULT COLON CaseBody
        | /* empty */
        ;

PrintStatement : PRINT OPT COR CPT SC
              ;

Expression : E
          ;

E : E PLUS T
  | E MINUS T
  | T
  ;

T : T MULT F
  | T DIV F
  | F
  ;

F : ID
  | NUM
  | OPT Expression CPT
  | ARRF
  ;

ARRF : ID ARRFLIST
     ;

ARRFLIST : ARRFLIST OSQ Expression CSQ
         | OSQ Expression CSQ
         ;

OPAREN : '('
       ;

CPAREN : ')'
       ;

OCURLY : '{'
       ;

CCURLY : '}'
       ;

COMMA : ','
      ;

COLON : ':'
      ;

EQ : '='
   ;

POINT : 'point'
      ;

%%

int main(int argc, char const *argv[])
{
    return 0;
}
