/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "parser.bison"

#include <stdio.h>
#include "../include/decl.h"

extern char *yytext;
extern int yylex();
extern int yyerror( char *str );
struct decl* parser_result = 0;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 234 "src/parser.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 247 "src/parser.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   290

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNRULES -- Number of states.  */
#define YYNSTATES  202

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    11,    13,    15,    17,    24,
      29,    38,    43,    52,    64,    67,    68,    70,    72,    76,
      78,    82,    85,    89,    92,    95,    98,   101,   106,   109,
     114,   117,   119,   124,   127,   135,   137,   138,   140,   142,
     144,   146,   151,   156,   158,   164,   165,   168,   170,   171,
     174,   175,   179,   181,   183,   187,   189,   193,   195,   199,
     204,   206,   210,   214,   218,   222,   224,   228,   232,   234,
     238,   242,   246,   248,   251,   254,   257,   261,   263,   265,
     267,   269,   271,   273,   275,   277,   279,   283,   285,   288,
     291,   293,   295,   298,   300,   305,   309,   315,   317,   318,
     320,   322,   324,   326,   328,   330,   332,   334,   336,   341,
     342,   348,   349
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      60,     0,    -1,    61,    12,    -1,    12,    -1,    62,    61,
      -1,    62,    -1,    63,    -1,    64,    -1,    93,    51,   100,
     104,    83,    52,    -1,    93,    51,   100,    52,    -1,    93,
      51,    97,   104,    30,    77,    31,    52,    -1,    93,    51,
      97,    52,    -1,    93,    51,    21,   101,     8,   102,     9,
      52,    -1,    93,    51,    21,   101,     8,   102,     9,   104,
      30,    65,    31,    -1,    66,    65,    -1,    -1,    67,    -1,
      68,    -1,    30,    65,    31,    -1,    63,    -1,    24,    83,
      52,    -1,    24,    52,    -1,    23,    80,    52,    -1,    92,
      52,    -1,    82,    52,    -1,    76,    52,    -1,    70,    66,
      -1,    70,    69,    17,    66,    -1,    71,    75,    -1,    70,
      69,    17,    69,    -1,    71,    74,    -1,    67,    -1,    22,
       8,    83,     9,    -1,    20,    72,    -1,     8,    73,    52,
      73,    52,    73,     9,    -1,    83,    -1,    -1,    52,    -1,
      69,    -1,    52,    -1,    66,    -1,    95,     8,    80,     9,
      -1,    30,    79,    31,    78,    -1,    79,    -1,    34,    30,
      79,    31,    78,    -1,    -1,    83,    81,    -1,    79,    -1,
      -1,    34,    79,    -1,    -1,    94,   104,    83,    -1,    82,
      -1,    84,    -1,    84,    50,    85,    -1,    85,    -1,    85,
      49,    86,    -1,    86,    -1,    86,    43,    87,    -1,    86,
      44,    43,    87,    -1,    87,    -1,    87,    45,    88,    -1,
      87,    46,    88,    -1,    87,    47,    88,    -1,    87,    48,
      88,    -1,    88,    -1,    88,    37,    89,    -1,    88,    38,
      89,    -1,    89,    -1,    89,    39,    90,    -1,    89,     7,
      90,    -1,    89,    40,    90,    -1,    90,    -1,    44,    91,
      -1,    38,    91,    -1,     4,    91,    -1,    90,    41,    91,
      -1,    91,    -1,    54,    -1,    92,    -1,    57,    -1,    55,
      -1,    56,    -1,    26,    -1,    18,    -1,    76,    -1,     8,
      83,     9,    -1,    94,    -1,    95,    35,    -1,    95,    36,
      -1,    53,    -1,    95,    -1,    95,    96,    -1,    93,    -1,
      32,    83,    33,    96,    -1,    32,    83,    33,    -1,    13,
      32,    98,    33,    99,    -1,    83,    -1,    -1,   100,    -1,
      97,    -1,     3,    -1,    19,    -1,    15,    -1,    16,    -1,
      25,    -1,   100,    -1,    27,    -1,    93,    51,    99,   103,
      -1,    -1,    34,    93,    51,    99,   103,    -1,    -1,    29,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,    95,    99,   104,   108,   109,   115,   116,
     118,   120,   126,   128,   132,   137,   141,   142,   146,   147,
     148,   149,   150,   151,   152,   153,   157,   158,   162,   170,
     174,   175,   179,   183,   185,   187,   188,   192,   193,   197,
     198,   202,   206,   207,   209,   210,   214,   218,   219,   221,
     222,   227,   231,   232,   235,   236,   239,   240,   243,   244,
     245,   248,   249,   250,   251,   252,   255,   256,   257,   260,
     261,   262,   263,   266,   267,   268,   269,   270,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   285,   286,
     289,   300,   301,   304,   307,   308,   312,   319,   320,   323,
     324,   327,   328,   329,   330,   331,   335,   336,   340,   341,
     343,   344,   347
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_INT", "TOKEN_PLUS", "TOKEN_MINUS",
  "TOKEN_MUL", "TOKEN_DIV", "TOKEN_LPAREN", "TOKEN_RPAREN", "TOKEN_SEMI",
  "TOKEN_ERROR", "TOKEN_EOF", "TOKEN_ARRAY", "TOKEN_AUTO", "TOKEN_BOOL",
  "TOKEN_CHAR", "TOKEN_ELSE", "TOKEN_FALSE", "TOKEN_FLOAT", "TOKEN_FOR",
  "TOKEN_FUNC", "TOKEN_IF", "TOKEN_PRINT", "TOKEN_RETURN", "TOKEN_STR",
  "TOKEN_TRUE", "TOKEN_VOID", "TOKEN_WHILE", "TOKEN_ASSIGN",
  "TOKEN_LBRACE", "TOKEN_RBRACE", "TOKEN_LBRACKET", "TOKEN_RBRACKET",
  "TOKEN_COMMA", "TOKEN_INC", "TOKEN_DEC", "TOKEN_ADD", "TOKEN_NEG",
  "TOKEN_MULT", "TOKEN_MOD", "TOKEN_EXP", "TOKEN_INEQ", "TOKEN_EQ",
  "TOKEN_NOT", "TOKEN_LT", "TOKEN_GT", "TOKEN_LEQ", "TOKEN_GEQ",
  "TOKEN_AND", "TOKEN_OR", "TOKEN_DEFINE", "TOKEN_SEMICOLON",
  "TOKEN_IDENT", "TOKEN_INT_LITERAL", "TOKEN_FLOAT_LITERAL",
  "TOKEN_STRING_LITERAL", "TOKEN_CHAR_LITERAL", "TOKEN_COMMENT", "$accept",
  "program", "decl_list", "decl", "var_decl", "func_decl", "stmt_list",
  "stmt", "simp_stmt", "cmpd_stmt", "if_dangle", "if_expr", "for_stmt",
  "for_cond", "for_expr", "dangle_end", "reg_end", "func_call",
  "array_init", "array_init_next", "expr_list", "opt_expr_list",
  "expr_next", "expr_assign", "expr", "expr2", "expr3", "expr4", "expr5",
  "expr6", "expr7", "expr8", "val_literal", "inc_or_dec", "ident", "mut",
  "ident_expr", "array_access", "array_type", "array_size", "all_types",
  "val_type", "return_type", "param_list", "param_next", "init", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    62,    62,    63,    63,
      63,    63,    64,    64,    65,    65,    66,    66,    67,    67,
      67,    67,    67,    67,    67,    67,    68,    68,    68,    69,
      69,    69,    70,    71,    72,    73,    73,    74,    74,    75,
      75,    76,    77,    77,    78,    78,    79,    80,    80,    81,
      81,    82,    83,    83,    84,    84,    85,    85,    86,    86,
      86,    87,    87,    87,    87,    87,    88,    88,    88,    89,
      89,    89,    89,    90,    90,    90,    90,    90,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    92,    92,
      93,    94,    94,    95,    96,    96,    97,    98,    98,    99,
      99,   100,   100,   100,   100,   100,   101,   101,   102,   102,
     103,   103,   104
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     1,     1,     6,     4,
       8,     4,     8,    11,     2,     0,     1,     1,     3,     1,
       3,     2,     3,     2,     2,     2,     2,     4,     2,     4,
       2,     1,     4,     2,     7,     1,     0,     1,     1,     1,
       1,     4,     4,     1,     5,     0,     2,     1,     0,     2,
       0,     3,     1,     1,     3,     1,     3,     1,     3,     4,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     2,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     2,
       1,     1,     2,     1,     4,     3,     5,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     0,
       5,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,    90,     0,     0,     5,     6,     7,     0,     1,
       2,     4,     0,   101,     0,   103,   104,   102,     0,   105,
       0,     0,    98,   107,   106,     0,   112,    11,     0,     9,
       0,     0,     0,    84,    83,     0,     0,    78,    81,    82,
      80,    85,    52,    97,    53,    55,    57,    60,    65,    68,
      72,    77,    79,    93,    87,    91,     0,   109,     0,     0,
      75,    87,     0,    74,    73,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,     0,    88,    89,    92,     0,     0,     0,     0,     0,
      43,    50,     8,    86,    54,    56,    58,     0,    61,    62,
      63,    64,    66,    67,    70,    69,    71,    76,    51,    47,
       0,     0,   100,    96,    99,     0,     0,     0,     0,     0,
      46,    59,    41,    95,   111,    12,     0,    45,    10,    49,
      94,     0,   108,    15,     0,    42,     0,     0,     0,    48,
       0,    15,    19,     0,    15,    16,    17,     0,     0,     0,
       0,     0,    93,     0,     0,     0,    36,    33,     0,     0,
      21,     0,     0,    13,    14,    26,    16,     0,     0,     0,
      39,    40,    28,    25,    24,    23,     0,     0,   111,     0,
      35,     0,    22,    20,    18,     0,     0,    39,    38,    30,
      45,   110,    36,    32,    27,     0,    44,     0,    29,    36,
       0,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,   142,     7,   143,   144,   145,   146,
     167,   147,   148,   157,   179,   189,   172,    41,    89,   135,
     109,   110,   120,    42,    91,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    61,    55,    84,   112,    56,
     113,   114,    25,    87,   132,    79
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -179
static const yytype_int16 yypact[] =
{
      -8,  -179,  -179,    10,     6,   -31,  -179,  -179,   -27,  -179,
    -179,  -179,   248,  -179,    21,  -179,  -179,  -179,   202,  -179,
     107,   111,   193,  -179,  -179,    30,  -179,  -179,    12,  -179,
     193,   100,   193,  -179,  -179,   100,   100,  -179,  -179,  -179,
    -179,  -179,  -179,  -179,    31,    29,   150,   209,   170,    70,
      47,  -179,  -179,  -179,    61,    81,    72,   -31,   134,    55,
    -179,  -179,   103,  -179,  -179,   193,   193,   193,    76,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   100,   193,
     193,   193,  -179,  -179,  -179,   255,    83,   123,   193,   115,
    -179,   124,  -179,  -179,    29,   150,   209,   193,   170,   170,
     170,   170,    70,    70,    47,    47,    47,  -179,  -179,  -179,
     158,   138,  -179,  -179,  -179,   255,   122,   144,   125,   193,
    -179,   209,  -179,   149,   166,  -179,   154,   176,  -179,  -179,
    -179,   -31,  -179,    62,   168,  -179,   165,   207,   217,   193,
     188,    62,  -179,   197,    62,  -179,  -179,    62,    71,   186,
     187,   208,   211,    61,   193,   255,   193,  -179,   193,   213,
    -179,   214,   228,  -179,  -179,  -179,   258,   259,    62,   200,
    -179,  -179,  -179,  -179,  -179,  -179,   255,   241,   166,   225,
    -179,   269,  -179,  -179,  -179,    62,   262,   264,  -179,  -179,
     176,  -179,   193,  -179,  -179,    62,  -179,   230,  -179,   193,
     274,  -179
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -179,  -179,   279,  -179,    28,  -179,  -110,    14,  -139,  -179,
     -65,   -96,   -93,  -179,  -178,  -179,  -179,  -121,  -179,    95,
     -56,   147,  -179,   -98,   -13,  -179,   222,   223,   -30,   164,
     139,   127,     5,   -89,     0,   -19,  -179,   167,    -6,  -179,
     -90,   -11,  -179,  -179,   110,    -5
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -38
static const yytype_int16 yytable[] =
{
       8,    21,    90,    54,     1,     8,    20,    24,   166,    43,
       9,    54,   149,    54,   197,    28,    30,    59,    10,    62,
     149,   200,     2,   149,    12,   124,   149,   149,     6,   166,
     166,   162,   117,     6,   164,   150,    60,    96,    57,    54,
      63,    64,    58,   150,   151,     2,   150,   149,   149,   150,
     150,   168,   151,    22,   169,   151,   166,    86,   151,   151,
      54,    54,    54,   129,   149,   178,   108,   121,   111,    54,
     150,   150,   168,   168,   149,   169,   169,    75,    66,   151,
     151,    65,   137,   107,   138,   139,   140,   150,    78,    80,
      26,   137,   141,   138,   139,   140,   151,   150,   177,   168,
      54,   141,   169,   186,   188,    85,   151,    92,    32,    76,
      77,   126,    93,    81,   153,     2,    82,    83,    33,    97,
      54,    54,   153,   170,     2,   153,    34,   161,   153,   153,
     198,   136,   116,   152,   115,    54,    26,    54,    31,    54,
      26,   152,    32,   180,   152,   181,   118,   152,   152,   153,
     153,    26,    33,     2,    37,    38,    39,    40,   119,    27,
      34,   165,   171,    29,    88,    21,   153,   122,   152,   152,
      20,   123,    35,    54,   125,   127,   153,   128,    36,   180,
      54,    81,   165,   171,   133,   152,   180,     2,    37,    38,
      39,    40,    31,    67,    68,   152,    32,    31,   154,   194,
     131,    32,   104,   105,   106,    13,    33,    73,    74,   194,
     134,    33,   102,   103,    34,   156,   155,    15,    16,    34,
     137,    17,   138,   139,   140,   158,    35,    19,   163,    23,
     141,    35,    36,    98,    99,   100,   101,    36,   173,   174,
     160,     2,    37,    38,    39,    40,     2,    37,    38,    39,
      40,    13,   187,     2,    69,    70,    71,    72,    13,   184,
     175,    14,   176,    15,    16,   182,   183,    17,    14,    18,
      15,    16,   190,    19,    17,   -31,   185,   192,   193,   195,
      19,   -37,   199,   201,    11,   196,   159,    94,   191,    95,
     130
};

static const yytype_uint8 yycheck[] =
{
       0,    12,    58,    22,    12,     5,    12,    18,   147,    22,
       0,    30,   133,    32,   192,    20,    21,    30,    12,    32,
     141,   199,    53,   144,    51,   115,   147,   148,     0,   168,
     169,   141,    88,     5,   144,   133,    31,    67,     8,    58,
      35,    36,    30,   141,   133,    53,   144,   168,   169,   147,
     148,   147,   141,    32,   147,   144,   195,    57,   147,   148,
      79,    80,    81,   119,   185,   155,    79,    97,    81,    88,
     168,   169,   168,   169,   195,   168,   169,     7,    49,   168,
     169,    50,    20,    78,    22,    23,    24,   185,    41,     8,
      29,    20,    30,    22,    23,    24,   185,   195,   154,   195,
     119,    30,   195,   168,   169,    33,   195,    52,     8,    39,
      40,   116,     9,    32,   133,    53,    35,    36,    18,    43,
     139,   140,   141,    52,    53,   144,    26,   140,   147,   148,
     195,   131,     9,   133,    51,   154,    29,   156,     4,   158,
      29,   141,     8,   156,   144,   158,    31,   147,   148,   168,
     169,    29,    18,    53,    54,    55,    56,    57,    34,    52,
      26,   147,   148,    52,    30,   176,   185,     9,   168,   169,
     176,    33,    38,   192,    52,    31,   195,    52,    44,   192,
     199,    32,   168,   169,    30,   185,   199,    53,    54,    55,
      56,    57,     4,    43,    44,   195,     8,     4,    30,   185,
      34,     8,    75,    76,    77,     3,    18,    37,    38,   195,
      34,    18,    73,    74,    26,     8,    51,    15,    16,    26,
      20,    19,    22,    23,    24,     8,    38,    25,    31,    27,
      30,    38,    44,    69,    70,    71,    72,    44,    52,    52,
      52,    53,    54,    55,    56,    57,    53,    54,    55,    56,
      57,     3,    52,    53,    45,    46,    47,    48,     3,    31,
      52,    13,    51,    15,    16,    52,    52,    19,    13,    21,
      15,    16,    31,    25,    19,    17,    17,    52,     9,    17,
      25,    17,    52,     9,     5,   190,   139,    65,   178,    66,
     123
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    53,    60,    61,    62,    63,    64,    93,     0,
      12,    61,    51,     3,    13,    15,    16,    19,    21,    25,
      97,   100,    32,    27,   100,   101,    29,    52,   104,    52,
     104,     4,     8,    18,    26,    38,    44,    54,    55,    56,
      57,    76,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    98,     8,    30,    83,
      91,    94,    83,    91,    91,    50,    49,    43,    44,    45,
      46,    47,    48,    37,    38,     7,    39,    40,    41,   104,
       8,    32,    35,    36,    96,    33,    93,   102,    30,    77,
      79,    83,    52,     9,    85,    86,    87,    43,    88,    88,
      88,    88,    89,    89,    90,    90,    90,    91,    83,    79,
      80,    83,    97,    99,   100,    51,     9,    79,    31,    34,
      81,    87,     9,    33,    99,    52,   104,    31,    52,    79,
      96,    34,   103,    30,    34,    78,    93,    20,    22,    23,
      24,    30,    63,    65,    66,    67,    68,    70,    71,    76,
      82,    92,    93,    94,    30,    51,     8,    72,     8,    80,
      52,    83,    65,    31,    65,    66,    67,    69,    70,    71,
      52,    66,    75,    52,    52,    52,    51,    79,    99,    73,
      83,    83,    52,    52,    31,    17,    69,    52,    69,    74,
      31,   103,    52,     9,    66,    17,    78,    73,    69,    52,
      73,     9
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 94 "parser.bison"
    { parser_result = (yyvsp[(1) - (2)].decl); return 0;;}
    break;

  case 3:
#line 95 "parser.bison"
    { parser_result = 0; return 0;;}
    break;

  case 4:
#line 100 "parser.bison"
    {
        (yyvsp[(1) - (2)].decl)->next = (yyvsp[(2) - (2)].decl);
        (yyval.decl) = (yyvsp[(1) - (2)].decl);
;}
    break;

  case 5:
#line 104 "parser.bison"
    { (yyval.decl) = (yyvsp[(1) - (1)].decl); ;}
    break;

  case 6:
#line 108 "parser.bison"
    { (yyval.decl) = (yyvsp[(1) - (1)].decl); ;}
    break;

  case 7:
#line 109 "parser.bison"
    { (yyval.decl) = (yyvsp[(1) - (1)].decl); ;}
    break;

  case 8:
#line 115 "parser.bison"
    { (yyval.decl) = decl_create((yyvsp[(1) - (6)].string_literal), (yyvsp[(3) - (6)].type), (yyvsp[(5) - (6)].expr), 0, 0); ;}
    break;

  case 9:
#line 116 "parser.bison"
    { (yyval.decl) = decl_create((yyvsp[(1) - (4)].string_literal), (yyvsp[(3) - (4)].type), 0, 0, 0); ;}
    break;

  case 10:
#line 118 "parser.bison"
    { (yyval.decl) = decl_create((yyvsp[(1) - (8)].string_literal), (yyvsp[(3) - (8)].type), (yyvsp[(6) - (8)].expr), 0, 0); ;}
    break;

  case 11:
#line 120 "parser.bison"
    { (yyval.decl) = decl_create((yyvsp[(1) - (4)].string_literal), (yyvsp[(3) - (4)].type), 0, 0, 0); ;}
    break;

  case 12:
#line 126 "parser.bison"
    { (yyval.decl) = decl_create((yyvsp[(1) - (8)].string_literal), type_create(TYPE_FUNC, (yyvsp[(4) - (8)].type), (yyvsp[(6) - (8)].param_list)), 0, 0, 0); ;}
    break;

  case 13:
#line 128 "parser.bison"
    { (yyval.decl) = decl_create((yyvsp[(1) - (11)].string_literal), type_create(TYPE_FUNC, (yyvsp[(4) - (11)].type), (yyvsp[(6) - (11)].param_list)), 0, (yyvsp[(10) - (11)].stmt), 0); ;}
    break;

  case 14:
#line 133 "parser.bison"
    {
        (yyvsp[(1) - (2)].stmt)->next = (yyvsp[(2) - (2)].stmt);
        (yyval.stmt) = (yyvsp[(1) - (2)].stmt);
;}
    break;

  case 15:
#line 137 "parser.bison"
    { (yyval.stmt) = 0; ;}
    break;

  case 16:
#line 141 "parser.bison"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 17:
#line 142 "parser.bison"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 18:
#line 146 "parser.bison"
    { (yyval.stmt) = (yyvsp[(2) - (3)].stmt); ;}
    break;

  case 19:
#line 147 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_DECL, (yyvsp[(1) - (1)].decl), 0, 0, 0, 0, 0, 0); ;}
    break;

  case 20:
#line 148 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_RETURN, 0, 0, (yyvsp[(2) - (3)].expr), 0, 0, 0, 0); ;}
    break;

  case 21:
#line 149 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_RETURN, 0, 0, 0, 0, 0, 0, 0); ;}
    break;

  case 22:
#line 150 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_PRINT, 0, 0, (yyvsp[(2) - (3)].expr), 0, 0, 0, 0); ;}
    break;

  case 23:
#line 151 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_EXPR, 0, 0, (yyvsp[(1) - (2)].expr), 0, 0, 0, 0); ;}
    break;

  case 24:
#line 152 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_EXPR, 0, 0, (yyvsp[(1) - (2)].expr), 0, 0, 0, 0); ;}
    break;

  case 25:
#line 153 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_EXPR, 0, 0, (yyvsp[(1) - (2)].expr), 0, 0, 0, 0); ;}
    break;

  case 26:
#line 157 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[(1) - (2)].expr), 0, (yyvsp[(2) - (2)].stmt), 0, 0); ;}
    break;

  case 27:
#line 159 "parser.bison"
    {
        (yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[(1) - (4)].expr), 0, (yyvsp[(2) - (4)].stmt), (yyvsp[(4) - (4)].stmt), 0);
;}
    break;

  case 28:
#line 163 "parser.bison"
    { 
        (yyvsp[(1) - (2)].stmt)->body = (yyvsp[(2) - (2)].stmt);
        (yyval.stmt) = (yyvsp[(1) - (2)].stmt);
;}
    break;

  case 29:
#line 171 "parser.bison"
    {
        (yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[(1) - (4)].expr), 0, (yyvsp[(2) - (4)].stmt), (yyvsp[(4) - (4)].stmt), 0);
;}
    break;

  case 30:
#line 174 "parser.bison"
    { (yyvsp[(1) - (2)].stmt)->body = (yyvsp[(2) - (2)].stmt); ;}
    break;

  case 31:
#line 175 "parser.bison"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 32:
#line 179 "parser.bison"
    { (yyval.expr) = (yyvsp[(3) - (4)].expr); ;}
    break;

  case 33:
#line 183 "parser.bison"
    { (yyval.stmt) = (yyvsp[(2) - (2)].stmt); ;}
    break;

  case 34:
#line 185 "parser.bison"
    {(yyval.stmt) = stmt_create(STMT_FOR, 0, (yyvsp[(2) - (7)].expr), (yyvsp[(4) - (7)].expr), (yyvsp[(6) - (7)].expr), 0, 0, 0);;}
    break;

  case 35:
#line 187 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 36:
#line 188 "parser.bison"
    { (yyval.expr) = 0; ;}
    break;

  case 37:
#line 192 "parser.bison"
    { (yyval.stmt) = 0; ;}
    break;

  case 38:
#line 193 "parser.bison"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 39:
#line 197 "parser.bison"
    { (yyval.stmt) = 0; ;}
    break;

  case 40:
#line 198 "parser.bison"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 41:
#line 202 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_FUNC, (yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 42:
#line 206 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_ARG, (yyvsp[(2) - (4)].expr), (yyvsp[(4) - (4)].expr)); ;}
    break;

  case 43:
#line 207 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_ARG, (yyvsp[(1) - (1)].expr), NULL); ;}
    break;

  case 44:
#line 209 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_ARG, (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr)); ;}
    break;

  case 45:
#line 210 "parser.bison"
    { (yyval.expr) = 0; ;}
    break;

  case 46:
#line 214 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_ARG, (yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 47:
#line 218 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 48:
#line 219 "parser.bison"
    { (yyval.expr) = 0; ;}
    break;

  case 49:
#line 221 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_ARG, (yyvsp[(2) - (2)].expr), 0); ;}
    break;

  case 50:
#line 222 "parser.bison"
    { (yyval.expr) = 0; ;}
    break;

  case 51:
#line 227 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_ASSIGN, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 52:
#line 231 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 53:
#line 232 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 54:
#line 235 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_OR, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 55:
#line 236 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 56:
#line 239 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_AND, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 57:
#line 240 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 58:
#line 243 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_EQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 59:
#line 244 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_NEQ, (yyvsp[(1) - (4)].expr), (yyvsp[(4) - (4)].expr)); ;}
    break;

  case 60:
#line 245 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 61:
#line 248 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_LT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 62:
#line 249 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_GT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 63:
#line 250 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_LEQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 64:
#line 251 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_GEQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 65:
#line 252 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 66:
#line 255 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_ADD, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 67:
#line 256 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_NEG, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 68:
#line 257 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 69:
#line 260 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_MULT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 70:
#line 261 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_DIV, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 71:
#line 262 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_MOD, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 72:
#line 263 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 73:
#line 266 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_NOT, (yyvsp[(2) - (2)].expr), 0); ;}
    break;

  case 74:
#line 267 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_NEG, (yyvsp[(2) - (2)].expr), 0); ;}
    break;

  case 75:
#line 268 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_PLUS, (yyvsp[(2) - (2)].expr), 0); ;}
    break;

  case 76:
#line 269 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_EXP, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 77:
#line 270 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 78:
#line 273 "parser.bison"
    { (yyval.expr) = expr_create_integer_literal(atoi(yytext)); ;}
    break;

  case 79:
#line 274 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 80:
#line 275 "parser.bison"
    { (yyval.expr) = expr_create_char_literal(*yytext); ;}
    break;

  case 81:
#line 276 "parser.bison"
    { (yyval.expr) = expr_create_float_literal(atof(yytext)); ;}
    break;

  case 82:
#line 277 "parser.bison"
    { (yyval.expr) = expr_create_string_literal(yytext); ;}
    break;

  case 83:
#line 278 "parser.bison"
    { (yyval.expr) = expr_create_bool_literal(1); ;}
    break;

  case 84:
#line 279 "parser.bison"
    { (yyval.expr) = expr_create_bool_literal(0); ;}
    break;

  case 85:
#line 280 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 86:
#line 281 "parser.bison"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); ;}
    break;

  case 87:
#line 282 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 88:
#line 285 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_INC, (yyvsp[(1) - (2)].expr), 0); ;}
    break;

  case 89:
#line 286 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_DEC, (yyvsp[(1) - (2)].expr), 0); ;}
    break;

  case 90:
#line 290 "parser.bison"
    { 
        char *s;
        if (!(s = strdup(yytext))) {
                fprintf(stderr, "ERROR: Could not allocate enough space for ident.\n");
                exit(EXIT_FAILURE);
        }
        (yyval.string_literal) = s;
;}
    break;

  case 91:
#line 300 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 92:
#line 301 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_ARRAY_SUB, (yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 93:
#line 304 "parser.bison"
    { (yyval.expr) = expr_create_ident((yyvsp[(1) - (1)].string_literal)); ;}
    break;

  case 94:
#line 307 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_ARG, (yyvsp[(2) - (4)].expr), (yyvsp[(4) - (4)].expr)); ;}
    break;

  case 95:
#line 308 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_ARG, (yyvsp[(2) - (3)].expr), 0); ;}
    break;

  case 96:
#line 313 "parser.bison"
    { 
                (yyval.type) = type_create(TYPE_ARRAY, (yyvsp[(5) - (5)].type), 0);
                (yyval.type)->array_size = (yyvsp[(3) - (5)].expr);
           ;}
    break;

  case 97:
#line 319 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 98:
#line 320 "parser.bison"
    { (yyval.expr) = 0; ;}
    break;

  case 99:
#line 323 "parser.bison"
    { (yyval.type) = (yyvsp[(1) - (1)].type); ;}
    break;

  case 100:
#line 324 "parser.bison"
    { (yyval.type) = (yyvsp[(1) - (1)].type); ;}
    break;

  case 101:
#line 327 "parser.bison"
    { (yyval.type) = type_create(TYPE_INT, 0, 0); ;}
    break;

  case 102:
#line 328 "parser.bison"
    { (yyval.type) = type_create(TYPE_FLOAT, 0, 0); ;}
    break;

  case 103:
#line 329 "parser.bison"
    { (yyval.type) = type_create(TYPE_BOOL, 0, 0); ;}
    break;

  case 104:
#line 330 "parser.bison"
    { (yyval.type) = type_create(TYPE_CHAR, 0, 0); ;}
    break;

  case 105:
#line 331 "parser.bison"
    { (yyval.type) = type_create(TYPE_STR, 0, 0); ;}
    break;

  case 106:
#line 335 "parser.bison"
    { (yyval.type) = (yyvsp[(1) - (1)].type); ;}
    break;

  case 107:
#line 336 "parser.bison"
    { (yyval.type) = type_create(TYPE_VOID, 0, 0); ;}
    break;

  case 108:
#line 340 "parser.bison"
    { (yyval.param_list) = param_list_create((yyvsp[(1) - (4)].string_literal), (yyvsp[(3) - (4)].type), (yyvsp[(4) - (4)].param_list)); ;}
    break;

  case 109:
#line 341 "parser.bison"
    { (yyval.param_list) = 0; ;}
    break;

  case 110:
#line 343 "parser.bison"
    { (yyval.param_list) = param_list_create((yyvsp[(2) - (5)].string_literal), (yyvsp[(4) - (5)].type), (yyvsp[(5) - (5)].param_list)); ;}
    break;

  case 111:
#line 344 "parser.bison"
    { (yyval.param_list) = 0; ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2234 "src/parser.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 350 "parser.bison"


int yyerror(char *s) {
    printf("parse error: %s\n",s);
    return 1;
}

