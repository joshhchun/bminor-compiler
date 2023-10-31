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
#define YYLAST   300

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNRULES -- Number of states.  */
#define YYNSTATES  204

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
      29,    38,    43,    52,    64,    67,    68,    71,    72,    74,
      76,    80,    82,    86,    89,    93,    96,    99,   102,   105,
     110,   113,   118,   121,   123,   128,   131,   139,   141,   142,
     144,   146,   148,   150,   155,   160,   162,   168,   169,   172,
     174,   175,   178,   179,   183,   185,   187,   191,   193,   197,
     199,   203,   208,   210,   214,   218,   222,   226,   228,   232,
     236,   238,   242,   246,   250,   252,   255,   258,   261,   265,
     267,   269,   271,   273,   275,   277,   279,   281,   283,   287,
     289,   292,   295,   297,   299,   302,   304,   309,   313,   319,
     321,   322,   324,   326,   328,   330,   332,   334,   336,   338,
     340,   345,   346,   352,   353
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      60,     0,    -1,    61,    12,    -1,    12,    -1,    62,    61,
      -1,    62,    -1,    63,    -1,    64,    -1,    94,    51,   101,
     105,    84,    52,    -1,    94,    51,   101,    52,    -1,    94,
      51,    98,   105,    30,    78,    31,    52,    -1,    94,    51,
      98,    52,    -1,    94,    51,    21,   102,     8,   103,     9,
      52,    -1,    94,    51,    21,   102,     8,   103,     9,   105,
      30,    65,    31,    -1,    67,    66,    -1,    -1,    67,    66,
      -1,    -1,    68,    -1,    69,    -1,    30,    65,    31,    -1,
      63,    -1,    24,    84,    52,    -1,    24,    52,    -1,    23,
      81,    52,    -1,    93,    52,    -1,    83,    52,    -1,    77,
      52,    -1,    71,    67,    -1,    71,    70,    17,    67,    -1,
      72,    76,    -1,    71,    70,    17,    70,    -1,    72,    75,
      -1,    68,    -1,    22,     8,    84,     9,    -1,    20,    73,
      -1,     8,    74,    52,    74,    52,    74,     9,    -1,    84,
      -1,    -1,    52,    -1,    70,    -1,    52,    -1,    67,    -1,
      96,     8,    81,     9,    -1,    30,    80,    31,    79,    -1,
      80,    -1,    34,    30,    80,    31,    79,    -1,    -1,    84,
      82,    -1,    80,    -1,    -1,    34,    80,    -1,    -1,    95,
     105,    84,    -1,    83,    -1,    85,    -1,    85,    50,    86,
      -1,    86,    -1,    86,    49,    87,    -1,    87,    -1,    87,
      43,    88,    -1,    87,    44,    43,    88,    -1,    88,    -1,
      88,    45,    89,    -1,    88,    46,    89,    -1,    88,    47,
      89,    -1,    88,    48,    89,    -1,    89,    -1,    89,    37,
      90,    -1,    89,    38,    90,    -1,    90,    -1,    90,    39,
      91,    -1,    90,     7,    91,    -1,    90,    40,    91,    -1,
      91,    -1,    44,    92,    -1,    38,    92,    -1,     4,    92,
      -1,    91,    41,    92,    -1,    92,    -1,    54,    -1,    93,
      -1,    57,    -1,    55,    -1,    56,    -1,    26,    -1,    18,
      -1,    77,    -1,     8,    84,     9,    -1,    95,    -1,    96,
      35,    -1,    96,    36,    -1,    53,    -1,    96,    -1,    96,
      97,    -1,    94,    -1,    32,    84,    33,    97,    -1,    32,
      84,    33,    -1,    13,    32,    99,    33,   100,    -1,    84,
      -1,    -1,   101,    -1,    98,    -1,     3,    -1,    19,    -1,
      15,    -1,    16,    -1,    25,    -1,   101,    -1,    27,    -1,
      94,    51,   100,   104,    -1,    -1,    34,    94,    51,   100,
     104,    -1,    -1,    29,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,    95,    99,   104,   108,   109,   115,   116,
     118,   120,   126,   128,   132,   137,   140,   141,   145,   146,
     150,   151,   152,   153,   154,   155,   156,   157,   161,   162,
     166,   174,   178,   179,   183,   187,   189,   191,   192,   196,
     197,   201,   202,   206,   210,   211,   213,   214,   218,   222,
     223,   225,   226,   231,   235,   236,   239,   240,   243,   244,
     247,   248,   249,   252,   253,   254,   255,   256,   259,   260,
     261,   264,   265,   266,   267,   270,   271,   272,   273,   274,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     289,   290,   293,   304,   305,   308,   311,   312,   316,   323,
     324,   327,   328,   331,   332,   333,   334,   335,   339,   340,
     344,   345,   347,   348,   351
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
  "stmt_next", "stmt", "simp_stmt", "cmpd_stmt", "if_dangle", "if_expr",
  "for_stmt", "for_cond", "for_expr", "dangle_end", "reg_end", "func_call",
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
      68,    68,    68,    68,    68,    68,    68,    68,    69,    69,
      69,    70,    70,    70,    71,    72,    73,    74,    74,    75,
      75,    76,    76,    77,    78,    78,    79,    79,    80,    81,
      81,    82,    82,    83,    84,    84,    85,    85,    86,    86,
      87,    87,    87,    88,    88,    88,    88,    88,    89,    89,
      89,    90,    90,    90,    90,    91,    91,    91,    91,    91,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      93,    93,    94,    95,    95,    96,    97,    97,    98,    99,
      99,   100,   100,   101,   101,   101,   101,   101,   102,   102,
     103,   103,   104,   104,   105
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     1,     1,     6,     4,
       8,     4,     8,    11,     2,     0,     2,     0,     1,     1,
       3,     1,     3,     2,     3,     2,     2,     2,     2,     4,
       2,     4,     2,     1,     4,     2,     7,     1,     0,     1,
       1,     1,     1,     4,     4,     1,     5,     0,     2,     1,
       0,     2,     0,     3,     1,     1,     3,     1,     3,     1,
       3,     4,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     2,     2,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       2,     2,     1,     1,     2,     1,     4,     3,     5,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     0,     5,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,    92,     0,     0,     5,     6,     7,     0,     1,
       2,     4,     0,   103,     0,   105,   106,   104,     0,   107,
       0,     0,   100,   109,   108,     0,   114,    11,     0,     9,
       0,     0,     0,    86,    85,     0,     0,    80,    83,    84,
      82,    87,    54,    99,    55,    57,    59,    62,    67,    70,
      74,    79,    81,    95,    89,    93,     0,   111,     0,     0,
      77,    89,     0,    76,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,     0,    90,    91,    94,     0,     0,     0,     0,     0,
      45,    52,     8,    88,    56,    58,    60,     0,    63,    64,
      65,    66,    68,    69,    72,    71,    73,    78,    53,    49,
       0,     0,   102,    98,   101,     0,     0,     0,     0,     0,
      48,    61,    43,    97,   113,    12,     0,    47,    10,    51,
      96,     0,   110,    15,     0,    44,     0,     0,     0,    50,
       0,    15,    21,     0,    17,    18,    19,     0,     0,     0,
       0,     0,    95,     0,     0,     0,    38,    35,     0,     0,
      23,     0,     0,    13,    14,    17,    28,    18,     0,     0,
       0,    41,    42,    30,    27,    26,    25,     0,     0,   113,
       0,    37,     0,    24,    22,    20,    16,     0,     0,    41,
      40,    32,    47,   112,    38,    34,    29,     0,    46,     0,
      31,    38,     0,    36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,   142,     7,   143,   164,   144,   145,
     146,   168,   147,   148,   157,   180,   191,   173,    41,    89,
     135,   109,   110,   120,    42,    91,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    61,    55,    84,   112,
      56,   113,   114,    25,    87,   132,    79
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -184
static const yytype_int16 yypact[] =
{
       2,  -184,  -184,     6,    12,   -16,  -184,  -184,   -18,  -184,
    -184,  -184,   258,  -184,     7,  -184,  -184,  -184,   187,  -184,
     -10,    53,   190,  -184,  -184,    35,  -184,  -184,    34,  -184,
     190,   183,   190,  -184,  -184,   183,   183,  -184,  -184,  -184,
    -184,  -184,  -184,  -184,    27,    52,   -22,   184,    54,    33,
      65,  -184,  -184,  -184,    94,    90,    99,   -16,    40,    88,
    -184,  -184,   134,  -184,  -184,   190,   190,   190,   109,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   183,   190,
     190,   190,  -184,  -184,  -184,   275,   107,   150,   190,   131,
    -184,   129,  -184,  -184,    52,   -22,   184,   190,    54,    54,
      54,    54,    33,    33,    65,    65,    65,  -184,  -184,  -184,
     155,   139,  -184,  -184,  -184,   275,    56,   142,   124,   190,
    -184,   184,  -184,   147,   146,  -184,   154,   152,  -184,  -184,
    -184,   -16,  -184,   242,   158,  -184,   141,   191,   196,   190,
     167,   242,  -184,   164,   242,  -184,  -184,   242,   228,   161,
     163,   165,   156,    94,   190,   275,   190,  -184,   190,   166,
    -184,   173,   195,  -184,  -184,   242,  -184,   210,   216,   242,
     233,  -184,  -184,  -184,  -184,  -184,  -184,   275,   204,   146,
     189,  -184,   240,  -184,  -184,  -184,  -184,   242,   225,   237,
    -184,  -184,   152,  -184,   190,  -184,  -184,   242,  -184,   207,
    -184,   190,   251,  -184
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -184,  -184,   270,  -184,    62,  -184,   135,   117,  -116,  -134,
    -184,   -55,   -67,   -60,  -184,  -183,  -184,  -184,  -118,  -184,
      92,   -54,   148,  -184,   -58,    -5,  -184,   224,   226,   -47,
     198,    82,    41,    10,    13,     0,   -20,  -184,   170,    -9,
    -184,   -99,   -11,  -184,  -184,   118,   -12
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -40
static const yytype_int16 yytable[] =
{
       8,    21,    54,    20,    90,     8,     9,    24,    28,    30,
      54,   199,    54,   167,     1,   149,   124,    43,   202,    26,
      96,    67,    68,   149,    10,    59,   149,    62,   165,   149,
     149,   166,   172,    12,   117,   167,   167,     2,    54,    22,
      75,    60,    27,    57,    31,    63,    64,   149,    32,   165,
     121,   149,   149,   166,   172,     2,   179,    86,    33,    54,
      54,    54,     6,   167,    58,   129,    34,     6,    54,   149,
      88,   196,    76,    77,   108,   150,   111,    65,    35,   149,
     169,   196,    26,   150,    36,    26,   150,   170,   107,   150,
     150,    73,    74,     2,    37,    38,    39,    40,    80,    54,
     178,    66,   169,   169,   126,    29,    78,   150,   125,   170,
     170,   150,   150,   153,   188,   190,   104,   105,   106,    54,
      54,   153,    81,    26,   153,    82,    83,   153,   153,   150,
     169,   136,    85,   152,    54,   161,    54,   170,    54,   150,
      92,   152,   200,    93,   152,   153,   151,   152,   152,   153,
     153,   181,    97,   182,   151,   102,   103,   151,   115,   116,
     151,   151,   118,   119,   122,   152,    21,   153,    20,   152,
     152,    31,   123,   127,    54,    32,   128,   153,   151,    81,
     131,    54,   151,   151,   133,    33,   134,   152,   154,   181,
      13,    32,   155,    34,    31,   163,   181,   152,    32,   156,
     151,    33,    15,    16,   158,    35,    17,   177,    33,    34,
     151,    36,    19,   174,    23,   175,    34,   176,   183,   160,
       2,    37,    38,    39,    40,   184,   185,   -33,    35,    69,
      70,    71,    72,   187,    36,   192,     2,    37,    38,    39,
      40,   194,   197,     2,    37,    38,    39,    40,   137,   195,
     138,   139,   140,   137,   -39,   138,   139,   140,   141,   201,
     203,    13,   137,   141,   138,   139,   140,    98,    99,   100,
     101,    14,   141,    15,    16,    11,   162,    17,    13,    18,
     171,     2,   186,    19,   198,   189,     2,   159,    14,    94,
      15,    16,    95,   130,    17,     2,     0,   193,     0,     0,
      19
};

static const yytype_int16 yycheck[] =
{
       0,    12,    22,    12,    58,     5,     0,    18,    20,    21,
      30,   194,    32,   147,    12,   133,   115,    22,   201,    29,
      67,    43,    44,   141,    12,    30,   144,    32,   144,   147,
     148,   147,   148,    51,    88,   169,   170,    53,    58,    32,
       7,    31,    52,     8,     4,    35,    36,   165,     8,   165,
      97,   169,   170,   169,   170,    53,   155,    57,    18,    79,
      80,    81,     0,   197,    30,   119,    26,     5,    88,   187,
      30,   187,    39,    40,    79,   133,    81,    50,    38,   197,
     147,   197,    29,   141,    44,    29,   144,   147,    78,   147,
     148,    37,    38,    53,    54,    55,    56,    57,     8,   119,
     154,    49,   169,   170,   116,    52,    41,   165,    52,   169,
     170,   169,   170,   133,   169,   170,    75,    76,    77,   139,
     140,   141,    32,    29,   144,    35,    36,   147,   148,   187,
     197,   131,    33,   133,   154,   140,   156,   197,   158,   197,
      52,   141,   197,     9,   144,   165,   133,   147,   148,   169,
     170,   156,    43,   158,   141,    73,    74,   144,    51,     9,
     147,   148,    31,    34,     9,   165,   177,   187,   177,   169,
     170,     4,    33,    31,   194,     8,    52,   197,   165,    32,
      34,   201,   169,   170,    30,    18,    34,   187,    30,   194,
       3,     8,    51,    26,     4,    31,   201,   197,     8,     8,
     187,    18,    15,    16,     8,    38,    19,    51,    18,    26,
     197,    44,    25,    52,    27,    52,    26,    52,    52,    52,
      53,    54,    55,    56,    57,    52,    31,    17,    38,    45,
      46,    47,    48,    17,    44,    31,    53,    54,    55,    56,
      57,    52,    17,    53,    54,    55,    56,    57,    20,     9,
      22,    23,    24,    20,    17,    22,    23,    24,    30,    52,
       9,     3,    20,    30,    22,    23,    24,    69,    70,    71,
      72,    13,    30,    15,    16,     5,   141,    19,     3,    21,
      52,    53,   165,    25,   192,    52,    53,   139,    13,    65,
      15,    16,    66,   123,    19,    53,    -1,   179,    -1,    -1,
      25
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    53,    60,    61,    62,    63,    64,    94,     0,
      12,    61,    51,     3,    13,    15,    16,    19,    21,    25,
      98,   101,    32,    27,   101,   102,    29,    52,   105,    52,
     105,     4,     8,    18,    26,    38,    44,    54,    55,    56,
      57,    77,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    99,     8,    30,    84,
      92,    95,    84,    92,    92,    50,    49,    43,    44,    45,
      46,    47,    48,    37,    38,     7,    39,    40,    41,   105,
       8,    32,    35,    36,    97,    33,    94,   103,    30,    78,
      80,    84,    52,     9,    86,    87,    88,    43,    89,    89,
      89,    89,    90,    90,    91,    91,    91,    92,    84,    80,
      81,    84,    98,   100,   101,    51,     9,    80,    31,    34,
      82,    88,     9,    33,   100,    52,   105,    31,    52,    80,
      97,    34,   104,    30,    34,    79,    94,    20,    22,    23,
      24,    30,    63,    65,    67,    68,    69,    71,    72,    77,
      83,    93,    94,    95,    30,    51,     8,    73,     8,    81,
      52,    84,    65,    31,    66,    67,    67,    68,    70,    71,
      72,    52,    67,    76,    52,    52,    52,    51,    80,   100,
      74,    84,    84,    52,    52,    31,    66,    17,    70,    52,
      70,    75,    31,   104,    52,     9,    67,    17,    79,    74,
      70,    52,    74,     9
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
        (yyval.stmt) = stmt_create(STMT_BLOCK, 0, 0, 0, 0, (yyvsp[(1) - (2)].stmt), 0, 0) 
;}
    break;

  case 15:
#line 137 "parser.bison"
    { (yyval.stmt) = 0; ;}
    break;

  case 16:
#line 140 "parser.bison"
    { (yyvsp[(1) - (2)].stmt)->next = (yyvsp[(2) - (2)].stmt); ;}
    break;

  case 17:
#line 141 "parser.bison"
    { (yyval.stmt) = 0; ;}
    break;

  case 18:
#line 145 "parser.bison"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 19:
#line 146 "parser.bison"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 20:
#line 150 "parser.bison"
    { (yyval.stmt) = (yyvsp[(2) - (3)].stmt); ;}
    break;

  case 21:
#line 151 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_DECL, (yyvsp[(1) - (1)].decl), 0, 0, 0, 0, 0, 0); ;}
    break;

  case 22:
#line 152 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_RETURN, 0, 0, (yyvsp[(2) - (3)].expr), 0, 0, 0, 0); ;}
    break;

  case 23:
#line 153 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_RETURN, 0, 0, 0, 0, 0, 0, 0); ;}
    break;

  case 24:
#line 154 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_PRINT, 0, 0, (yyvsp[(2) - (3)].expr), 0, 0, 0, 0); ;}
    break;

  case 25:
#line 155 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_EXPR, 0, 0, (yyvsp[(1) - (2)].expr), 0, 0, 0, 0); ;}
    break;

  case 26:
#line 156 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_EXPR, 0, 0, (yyvsp[(1) - (2)].expr), 0, 0, 0, 0); ;}
    break;

  case 27:
#line 157 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_EXPR, 0, 0, (yyvsp[(1) - (2)].expr), 0, 0, 0, 0); ;}
    break;

  case 28:
#line 161 "parser.bison"
    { (yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[(1) - (2)].expr), 0, (yyvsp[(2) - (2)].stmt), 0, 0); ;}
    break;

  case 29:
#line 163 "parser.bison"
    {
        (yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[(1) - (4)].expr), 0, (yyvsp[(2) - (4)].stmt), (yyvsp[(4) - (4)].stmt), 0);
;}
    break;

  case 30:
#line 167 "parser.bison"
    { 
        (yyvsp[(1) - (2)].stmt)->body = (yyvsp[(2) - (2)].stmt);
        (yyval.stmt) = (yyvsp[(1) - (2)].stmt);
;}
    break;

  case 31:
#line 175 "parser.bison"
    {
        (yyval.stmt) = stmt_create(STMT_IF_ELSE, 0, 0, (yyvsp[(1) - (4)].expr), 0, (yyvsp[(2) - (4)].stmt), (yyvsp[(4) - (4)].stmt), 0);
;}
    break;

  case 32:
#line 178 "parser.bison"
    { (yyvsp[(1) - (2)].stmt)->body = (yyvsp[(2) - (2)].stmt); ;}
    break;

  case 33:
#line 179 "parser.bison"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 34:
#line 183 "parser.bison"
    { (yyval.expr) = (yyvsp[(3) - (4)].expr); ;}
    break;

  case 35:
#line 187 "parser.bison"
    { (yyval.stmt) = (yyvsp[(2) - (2)].stmt); ;}
    break;

  case 36:
#line 189 "parser.bison"
    {(yyval.stmt) = stmt_create(STMT_FOR, 0, (yyvsp[(2) - (7)].expr), (yyvsp[(4) - (7)].expr), (yyvsp[(6) - (7)].expr), 0, 0, 0);;}
    break;

  case 37:
#line 191 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 38:
#line 192 "parser.bison"
    { (yyval.expr) = 0; ;}
    break;

  case 39:
#line 196 "parser.bison"
    { (yyval.stmt) = 0; ;}
    break;

  case 40:
#line 197 "parser.bison"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 41:
#line 201 "parser.bison"
    { (yyval.stmt) = 0; ;}
    break;

  case 42:
#line 202 "parser.bison"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); ;}
    break;

  case 43:
#line 206 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_FUNC, (yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr)); ;}
    break;

  case 44:
#line 210 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_ARG, (yyvsp[(2) - (4)].expr), (yyvsp[(4) - (4)].expr)); ;}
    break;

  case 45:
#line 211 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_ARG, (yyvsp[(1) - (1)].expr), NULL); ;}
    break;

  case 46:
#line 213 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_ARG, (yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].expr)); ;}
    break;

  case 47:
#line 214 "parser.bison"
    { (yyval.expr) = 0; ;}
    break;

  case 48:
#line 218 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_ARG, (yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 49:
#line 222 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 50:
#line 223 "parser.bison"
    { (yyval.expr) = 0; ;}
    break;

  case 51:
#line 225 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_ARG, (yyvsp[(2) - (2)].expr), 0); ;}
    break;

  case 52:
#line 226 "parser.bison"
    { (yyval.expr) = 0; ;}
    break;

  case 53:
#line 231 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_ASSIGN, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 54:
#line 235 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 55:
#line 236 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 56:
#line 239 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_OR, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 57:
#line 240 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 58:
#line 243 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_AND, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 59:
#line 244 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 60:
#line 247 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_EQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 61:
#line 248 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_NEQ, (yyvsp[(1) - (4)].expr), (yyvsp[(4) - (4)].expr)); ;}
    break;

  case 62:
#line 249 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 63:
#line 252 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_LT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 64:
#line 253 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_GT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 65:
#line 254 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_LEQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 66:
#line 255 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_GEQ, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 67:
#line 256 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 68:
#line 259 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_ADD, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 69:
#line 260 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_NEG, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 70:
#line 261 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 71:
#line 264 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_MULT, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 72:
#line 265 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_DIV, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 73:
#line 266 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_MOD, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 74:
#line 267 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 75:
#line 270 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_NOT, (yyvsp[(2) - (2)].expr), 0); ;}
    break;

  case 76:
#line 271 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_NEG, (yyvsp[(2) - (2)].expr), 0); ;}
    break;

  case 77:
#line 272 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_PLUS, (yyvsp[(2) - (2)].expr), 0); ;}
    break;

  case 78:
#line 273 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_EXP, (yyvsp[(1) - (3)].expr), (yyvsp[(3) - (3)].expr)); ;}
    break;

  case 79:
#line 274 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 80:
#line 277 "parser.bison"
    { (yyval.expr) = expr_create_integer_literal(atoi(yytext)); ;}
    break;

  case 81:
#line 278 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 82:
#line 279 "parser.bison"
    { (yyval.expr) = expr_create_char_literal(*yytext); ;}
    break;

  case 83:
#line 280 "parser.bison"
    { (yyval.expr) = expr_create_float_literal(atof(yytext)); ;}
    break;

  case 84:
#line 281 "parser.bison"
    { (yyval.expr) = expr_create_string_literal(yytext); ;}
    break;

  case 85:
#line 282 "parser.bison"
    { (yyval.expr) = expr_create_bool_literal(1); ;}
    break;

  case 86:
#line 283 "parser.bison"
    { (yyval.expr) = expr_create_bool_literal(0); ;}
    break;

  case 87:
#line 284 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 88:
#line 285 "parser.bison"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); ;}
    break;

  case 89:
#line 286 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 90:
#line 289 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_INC, (yyvsp[(1) - (2)].expr), 0); ;}
    break;

  case 91:
#line 290 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_DEC, (yyvsp[(1) - (2)].expr), 0); ;}
    break;

  case 92:
#line 294 "parser.bison"
    { 
        char *s;
        if (!(s = strdup(yytext))) {
                fprintf(stderr, "ERROR: Could not allocate enough space for ident.\n");
                exit(EXIT_FAILURE);
        }
        (yyval.string_literal) = s;
;}
    break;

  case 93:
#line 304 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 94:
#line 305 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_ARRAY_SUB, (yyvsp[(1) - (2)].expr), (yyvsp[(2) - (2)].expr)); ;}
    break;

  case 95:
#line 308 "parser.bison"
    { (yyval.expr) = expr_create_ident((yyvsp[(1) - (1)].string_literal)); ;}
    break;

  case 96:
#line 311 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_ARG, (yyvsp[(2) - (4)].expr), (yyvsp[(4) - (4)].expr)); ;}
    break;

  case 97:
#line 312 "parser.bison"
    { (yyval.expr) = expr_create(EXPR_ARG, (yyvsp[(2) - (3)].expr), 0); ;}
    break;

  case 98:
#line 317 "parser.bison"
    { 
                (yyval.type) = type_create(TYPE_ARRAY, (yyvsp[(5) - (5)].type), 0);
                (yyval.type)->array_size = (yyvsp[(3) - (5)].expr);
           ;}
    break;

  case 99:
#line 323 "parser.bison"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); ;}
    break;

  case 100:
#line 324 "parser.bison"
    { (yyval.expr) = 0; ;}
    break;

  case 101:
#line 327 "parser.bison"
    { (yyval.type) = (yyvsp[(1) - (1)].type); ;}
    break;

  case 102:
#line 328 "parser.bison"
    { (yyval.type) = (yyvsp[(1) - (1)].type); ;}
    break;

  case 103:
#line 331 "parser.bison"
    { (yyval.type) = type_create(TYPE_INT, 0, 0); ;}
    break;

  case 104:
#line 332 "parser.bison"
    { (yyval.type) = type_create(TYPE_FLOAT, 0, 0); ;}
    break;

  case 105:
#line 333 "parser.bison"
    { (yyval.type) = type_create(TYPE_BOOL, 0, 0); ;}
    break;

  case 106:
#line 334 "parser.bison"
    { (yyval.type) = type_create(TYPE_CHAR, 0, 0); ;}
    break;

  case 107:
#line 335 "parser.bison"
    { (yyval.type) = type_create(TYPE_STR, 0, 0); ;}
    break;

  case 108:
#line 339 "parser.bison"
    { (yyval.type) = (yyvsp[(1) - (1)].type); ;}
    break;

  case 109:
#line 340 "parser.bison"
    { (yyval.type) = type_create(TYPE_VOID, 0, 0); ;}
    break;

  case 110:
#line 344 "parser.bison"
    { (yyval.param_list) = param_list_create((yyvsp[(1) - (4)].string_literal), (yyvsp[(3) - (4)].type), (yyvsp[(4) - (4)].param_list)); ;}
    break;

  case 111:
#line 345 "parser.bison"
    { (yyval.param_list) = 0; ;}
    break;

  case 112:
#line 347 "parser.bison"
    { (yyval.param_list) = param_list_create((yyvsp[(2) - (5)].string_literal), (yyvsp[(4) - (5)].type), (yyvsp[(5) - (5)].param_list)); ;}
    break;

  case 113:
#line 348 "parser.bison"
    { (yyval.param_list) = 0; ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2246 "src/parser.c"
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


#line 354 "parser.bison"


int yyerror(char *s) {
    printf("parse error: %s\n",s);
    return 1;
}

