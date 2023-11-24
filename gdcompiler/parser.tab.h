
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SELECT = 258,
     PRINT = 259,
     INT = 260,
     FLT = 261,
     ID = 262,
     FIVESTAR = 263,
     SC = 264,
     SP = 265,
     COMMA = 266,
     COLON = 267,
     EQ = 268,
     OR = 269,
     AND = 270,
     NOT = 271,
     LT = 272,
     LTE = 273,
     GT = 274,
     GTE = 275,
     EQEQ = 276,
     NEQ = 277,
     PLUS = 278,
     MINUS = 279,
     MULT = 280,
     DIV = 281,
     MOD = 282,
     HELLO = 283,
     OPT = 284,
     CPT = 285,
     OCURLY = 286,
     CCURLY = 287,
     IF = 288,
     ELSE = 289,
     FORT = 290,
     WHILET = 291,
     VOID = 292,
     RET = 293,
     SWITCHT = 294,
     CASET = 295,
     BREAK = 296,
     DEFAULT = 297,
     POINT = 298,
     CSQ = 299,
     OSQ = 300,
     NUM = 301,
     DOL = 302
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 122 "parser.y"

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



/* Line 1676 of yacc.c  */
#line 125 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


