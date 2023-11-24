/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    SELECT = 258,                  /* SELECT  */
    PRINT = 259,                   /* PRINT  */
    INT = 260,                     /* INT  */
    FLT = 261,                     /* FLT  */
    ID = 262,                      /* ID  */
    SC = 263,                      /* SC  */
    SP = 264,                      /* SP  */
    COMMA = 265,                   /* COMMA  */
    COLON = 266,                   /* COLON  */
    EQ = 267,                      /* EQ  */
    OR = 268,                      /* OR  */
    AND = 269,                     /* AND  */
    NOT = 270,                     /* NOT  */
    LT = 271,                      /* LT  */
    LTE = 272,                     /* LTE  */
    GT = 273,                      /* GT  */
    GTE = 274,                     /* GTE  */
    EQEQ = 275,                    /* EQEQ  */
    NEQ = 276,                     /* NEQ  */
    PLUS = 277,                    /* PLUS  */
    MINUS = 278,                   /* MINUS  */
    MULT = 279,                    /* MULT  */
    DIV = 280,                     /* DIV  */
    MOD = 281,                     /* MOD  */
    OPT = 282,                     /* OPT  */
    CPT = 283,                     /* CPT  */
    OCURLY = 284,                  /* OCURLY  */
    CCURLY = 285,                  /* CCURLY  */
    IF = 286,                      /* IF  */
    ELSE = 287,                    /* ELSE  */
    FORT = 288,                    /* FORT  */
    WHILET = 289,                  /* WHILET  */
    VOID = 290,                    /* VOID  */
    RET = 291,                     /* RET  */
    SWITCHT = 292,                 /* SWITCHT  */
    CASET = 293,                   /* CASET  */
    BREAK = 294,                   /* BREAK  */
    DEFAULT = 295,                 /* DEFAULT  */
    CSQ = 296,                     /* CSQ  */
    OSQ = 297,                     /* OSQ  */
    NUM = 298,                     /* NUM  */
    DOL = 299                      /* DOL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 120 "parser.y"

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

#line 132 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
