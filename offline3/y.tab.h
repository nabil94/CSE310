/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    FOR = 260,
    WHILE = 261,
    DO = 262,
    BREAK = 263,
    CONTINUE = 264,
    INT = 265,
    FLOAT = 266,
    CHAR = 267,
    DOUBLE = 268,
    VOID = 269,
    RETURN = 270,
    SWITCH = 271,
    CASE = 272,
    DEFAULT = 273,
    INCOP = 274,
    DECOP = 275,
    ASSIGNOP = 276,
    LPAREN = 277,
    RPAREN = 278,
    LCURL = 279,
    RCURL = 280,
    LTHIRD = 281,
    RTHIRD = 282,
    SEMICOLON = 283,
    COMMA = 284,
    STRING = 285,
    NOT = 286,
    PRINTLN = 287,
    ID = 288,
    CONST_INT = 289,
    CONST_FLOAT = 290,
    CONST_CHAR = 291,
    ADDOP = 292,
    MULOP = 293,
    LOGICOP = 294,
    RELOP = 295,
    lower_than_else = 296
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define DO 262
#define BREAK 263
#define CONTINUE 264
#define INT 265
#define FLOAT 266
#define CHAR 267
#define DOUBLE 268
#define VOID 269
#define RETURN 270
#define SWITCH 271
#define CASE 272
#define DEFAULT 273
#define INCOP 274
#define DECOP 275
#define ASSIGNOP 276
#define LPAREN 277
#define RPAREN 278
#define LCURL 279
#define RCURL 280
#define LTHIRD 281
#define RTHIRD 282
#define SEMICOLON 283
#define COMMA 284
#define STRING 285
#define NOT 286
#define PRINTLN 287
#define ID 288
#define CONST_INT 289
#define CONST_FLOAT 290
#define CONST_CHAR 291
#define ADDOP 292
#define MULOP 293
#define LOGICOP 294
#define RELOP 295
#define lower_than_else 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 61 "Parse.y" /* yacc.c:1909  */

SymbolInfo* sym;

#line 140 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
