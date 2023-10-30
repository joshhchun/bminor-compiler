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
     TOKEN_PLUS = 259,
     TOKEN_MINUS = 260,
     TOKEN_MUL = 261,
     TOKEN_DIV = 262,
     TOKEN_LPAREN = 263,
     TOKEN_RPAREN = 264,
     TOKEN_SEMI = 265,
     TOKEN_ERROR = 266,
     TOKEN_EOF = 267,
     TOKEN_ARRAY = 268,
     TOKEN_AUTO = 269,
     TOKEN_BOOL = 270,
     TOKEN_CHAR = 271,
     TOKEN_ELSE = 272,
     TOKEN_FALSE = 273,
     TOKEN_FLOAT = 274,
     TOKEN_FOR = 275,
     TOKEN_FUNC = 276,
     TOKEN_IF = 277,
     TOKEN_PRINT = 278,
     TOKEN_RETURN = 279,
     TOKEN_STR = 280,
     TOKEN_TRUE = 281,
     TOKEN_VOID = 282,
     TOKEN_WHILE = 283,
     TOKEN_ASSIGN = 284,
     TOKEN_LBRACE = 285,
     TOKEN_RBRACE = 286,
     TOKEN_LBRACKET = 287,
     TOKEN_RBRACKET = 288,
     TOKEN_COMMA = 289,
     TOKEN_INC = 290,
     TOKEN_DEC = 291,
     TOKEN_ADD = 292,
     TOKEN_NEG = 293,
     TOKEN_MULT = 294,
     TOKEN_MOD = 295,
     TOKEN_EXP = 296,
     TOKEN_INEQ = 297,
     TOKEN_EQ = 298,
     TOKEN_NOT = 299,
     TOKEN_LT = 300,
     TOKEN_GT = 301,
     TOKEN_LEQ = 302,
     TOKEN_GEQ = 303,
     TOKEN_AND = 304,
     TOKEN_OR = 305,
     TOKEN_DEFINE = 306,
     TOKEN_SEMICOLON = 307,
     TOKEN_IDENT = 308,
     TOKEN_INT_LITERAL = 309,
     TOKEN_FLOAT_LITERAL = 310,
     TOKEN_STRING_LITERAL = 311,
     TOKEN_CHAR_LITERAL = 312,
     TOKEN_COMMENT = 313
   };
#endif
/* Tokens.  */
#define TOKEN_INT 258
#define TOKEN_PLUS 259
#define TOKEN_MINUS 260
#define TOKEN_MUL 261
#define TOKEN_DIV 262
#define TOKEN_LPAREN 263
#define TOKEN_RPAREN 264
#define TOKEN_SEMI 265
#define TOKEN_ERROR 266
#define TOKEN_EOF 267
#define TOKEN_ARRAY 268
#define TOKEN_AUTO 269
#define TOKEN_BOOL 270
#define TOKEN_CHAR 271
#define TOKEN_ELSE 272
#define TOKEN_FALSE 273
#define TOKEN_FLOAT 274
#define TOKEN_FOR 275
#define TOKEN_FUNC 276
#define TOKEN_IF 277
#define TOKEN_PRINT 278
#define TOKEN_RETURN 279
#define TOKEN_STR 280
#define TOKEN_TRUE 281
#define TOKEN_VOID 282
#define TOKEN_WHILE 283
#define TOKEN_ASSIGN 284
#define TOKEN_LBRACE 285
#define TOKEN_RBRACE 286
#define TOKEN_LBRACKET 287
#define TOKEN_RBRACKET 288
#define TOKEN_COMMA 289
#define TOKEN_INC 290
#define TOKEN_DEC 291
#define TOKEN_ADD 292
#define TOKEN_NEG 293
#define TOKEN_MULT 294
#define TOKEN_MOD 295
#define TOKEN_EXP 296
#define TOKEN_INEQ 297
#define TOKEN_EQ 298
#define TOKEN_NOT 299
#define TOKEN_LT 300
#define TOKEN_GT 301
#define TOKEN_LEQ 302
#define TOKEN_GEQ 303
#define TOKEN_AND 304
#define TOKEN_OR 305
#define TOKEN_DEFINE 306
#define TOKEN_SEMICOLON 307
#define TOKEN_IDENT 308
#define TOKEN_INT_LITERAL 309
#define TOKEN_FLOAT_LITERAL 310
#define TOKEN_STRING_LITERAL 311
#define TOKEN_CHAR_LITERAL 312
#define TOKEN_COMMENT 313




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 68 "parser.bison"
{
        char* string_literal;
        int int_literal;
        char char_literal;

        struct decl *decl;
        struct stmt *stmt;
        struct expr *expr;
        struct param_list* param_list;
        struct type *type;
}
/* Line 1529 of yacc.c.  */
#line 177 "include/token.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

