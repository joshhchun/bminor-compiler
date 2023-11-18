/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     TOKEN_INT = 258,
     TOKEN_MINUS = 259,
     TOKEN_MUL = 260,
     TOKEN_DIV = 261,
     TOKEN_LPAREN = 262,
     TOKEN_RPAREN = 263,
     TOKEN_SEMI = 264,
     TOKEN_ERROR = 265,
     TOKEN_EOF = 266,
     TOKEN_ARRAY = 267,
     TOKEN_AUTO = 268,
     TOKEN_BOOL = 269,
     TOKEN_CHAR = 270,
     TOKEN_ELSE = 271,
     TOKEN_FALSE = 272,
     TOKEN_FLOAT = 273,
     TOKEN_FOR = 274,
     TOKEN_FUNC = 275,
     TOKEN_IF = 276,
     TOKEN_PRINT = 277,
     TOKEN_RETURN = 278,
     TOKEN_STR = 279,
     TOKEN_TRUE = 280,
     TOKEN_VOID = 281,
     TOKEN_WHILE = 282,
     TOKEN_ASSIGN = 283,
     TOKEN_LBRACE = 284,
     TOKEN_RBRACE = 285,
     TOKEN_LBRACKET = 286,
     TOKEN_RBRACKET = 287,
     TOKEN_COMMA = 288,
     TOKEN_INC = 289,
     TOKEN_DEC = 290,
     TOKEN_ADD = 291,
     TOKEN_NEG = 292,
     TOKEN_MULT = 293,
     TOKEN_MOD = 294,
     TOKEN_EXP = 295,
     TOKEN_INEQ = 296,
     TOKEN_EQ = 297,
     TOKEN_NOT = 298,
     TOKEN_LT = 299,
     TOKEN_GT = 300,
     TOKEN_LEQ = 301,
     TOKEN_GEQ = 302,
     TOKEN_AND = 303,
     TOKEN_OR = 304,
     TOKEN_DEFINE = 305,
     TOKEN_SEMICOLON = 306,
     TOKEN_IDENT = 307,
     TOKEN_INT_LITERAL = 308,
     TOKEN_FLOAT_LITERAL = 309,
     TOKEN_STRING_LITERAL = 310,
     TOKEN_CHAR_LITERAL = 311,
     TOKEN_COMMENT = 312
   };
#endif
/* Tokens.  */
#define TOKEN_INT 258
#define TOKEN_MINUS 259
#define TOKEN_MUL 260
#define TOKEN_DIV 261
#define TOKEN_LPAREN 262
#define TOKEN_RPAREN 263
#define TOKEN_SEMI 264
#define TOKEN_ERROR 265
#define TOKEN_EOF 266
#define TOKEN_ARRAY 267
#define TOKEN_AUTO 268
#define TOKEN_BOOL 269
#define TOKEN_CHAR 270
#define TOKEN_ELSE 271
#define TOKEN_FALSE 272
#define TOKEN_FLOAT 273
#define TOKEN_FOR 274
#define TOKEN_FUNC 275
#define TOKEN_IF 276
#define TOKEN_PRINT 277
#define TOKEN_RETURN 278
#define TOKEN_STR 279
#define TOKEN_TRUE 280
#define TOKEN_VOID 281
#define TOKEN_WHILE 282
#define TOKEN_ASSIGN 283
#define TOKEN_LBRACE 284
#define TOKEN_RBRACE 285
#define TOKEN_LBRACKET 286
#define TOKEN_RBRACKET 287
#define TOKEN_COMMA 288
#define TOKEN_INC 289
#define TOKEN_DEC 290
#define TOKEN_ADD 291
#define TOKEN_NEG 292
#define TOKEN_MULT 293
#define TOKEN_MOD 294
#define TOKEN_EXP 295
#define TOKEN_INEQ 296
#define TOKEN_EQ 297
#define TOKEN_NOT 298
#define TOKEN_LT 299
#define TOKEN_GT 300
#define TOKEN_LEQ 301
#define TOKEN_GEQ 302
#define TOKEN_AND 303
#define TOKEN_OR 304
#define TOKEN_DEFINE 305
#define TOKEN_SEMICOLON 306
#define TOKEN_IDENT 307
#define TOKEN_INT_LITERAL 308
#define TOKEN_FLOAT_LITERAL 309
#define TOKEN_STRING_LITERAL 310
#define TOKEN_CHAR_LITERAL 311
#define TOKEN_COMMENT 312




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 67 "parser.bison"
{
        char* string_literal;
        int int_literal;
        char* char_literal;

        struct decl *decl;
        struct stmt *stmt;
        struct expr *expr;
        struct param_list* param_list;
        struct type *type;
}
/* Line 1529 of yacc.c.  */
#line 175 "include/token.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

