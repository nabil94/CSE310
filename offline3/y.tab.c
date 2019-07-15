/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "Parse.y" /* yacc.c:339  */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
#include "1505094_SymbolTable.h"
//#define YYSTYPE SymbolInfo*

using namespace std;

extern char *yytext;
int yyparse(void);
int yylex(void);
extern FILE *yyin;
string unit;
string stmts1;
string func_var;
string param;
string var_dec;
string func_dec;
string func_def;
string stmt;
string stmts;
string comp_stmt;
string expr_stmt;
string expr;
string logic_expr;
string rel_expr;
string simp_expr;
string term;
string una_expr;
string fac;
string VAR;
string v_incop;
string v_decop;
string args;
SymbolTable st(30);
int IDargs = 0;
vector<string> args_name;
vector<string> args_type; 
bool funcDef = false;
extern int line_count;
int semanticErrors = 0;
//SymbolInfo *symbol; 
string var;
extern string p;
ofstream logout;
extern ofstream errorout;

void yyerror(const char *s)
{
	//write your code
}



#line 127 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 61 "Parse.y" /* yacc.c:355  */

SymbolInfo* sym;

#line 253 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 270 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  133

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    90,    94,   100,   106,   114,   123,   156,
     178,   183,   190,   190,   210,   210,   227,   236,   240,   248,
     256,   262,   256,   268,   272,   283,   289,   298,   306,   316,
     341,   368,   393,   420,   424,   428,   434,   442,   454,   461,
     468,   474,   478,   484,   490,   496,   502,   506,   512,   518,
     525,   534,   540,   560,   582,   588,   620,   686,   719,   851,
     880,  1288,  1322,  1667,  1696,  2082,  2136,  2159,  2189,  2193,
    2229,  2233,  2243,  2254,  2283,  2313,  2315,  2318,  2323
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "DO",
  "BREAK", "CONTINUE", "INT", "FLOAT", "CHAR", "DOUBLE", "VOID", "RETURN",
  "SWITCH", "CASE", "DEFAULT", "INCOP", "DECOP", "ASSIGNOP", "LPAREN",
  "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA",
  "STRING", "NOT", "PRINTLN", "ID", "CONST_INT", "CONST_FLOAT",
  "CONST_CHAR", "ADDOP", "MULOP", "LOGICOP", "RELOP", "lower_than_else",
  "$accept", "start", "program", "unit", "func_declaration",
  "func_definition", "$@1", "$@2", "parameter_list", "compound_statement",
  "$@3", "$@4", "var_declaration", "type_specifier", "declaration_list",
  "statements", "statement", "expression_statement", "variable",
  "expression", "logic_expression", "rel_expression", "simple_expression",
  "term", "unary_expression", "factor", "argument_list", "arguments", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF -75

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-75)))

#define YYTABLE_NINF -15

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   -75,   -75,   -75,    26,     4,   -75,   -75,   -75,   -75,
       2,   -75,   -75,    50,    11,    80,    65,   -75,   -75,    29,
       9,   -10,    45,    23,    62,    75,   -75,   -75,    81,    33,
       4,   -75,   -75,   -75,   -75,    77,    97,   -75,   -75,   -75,
      81,    93,    31,   -75,    82,   -75,   -75,   -75,   -75,   106,
     108,   112,    98,    98,   -75,    98,   116,    76,   -75,   -75,
      98,   -75,   -75,   107,    49,   -75,   -75,    88,    19,   -75,
     100,   -12,   103,   -75,   -75,    98,    90,    98,    20,   119,
     117,   -75,   110,    98,    98,   -75,   118,   -75,   -75,   -75,
     -75,    98,   -75,   -75,    98,    98,    98,    98,   122,    90,
     123,   -75,   -75,   -75,   124,   -75,   125,   120,    68,   -75,
     -75,   -75,   103,   113,   -75,    82,    98,    82,    21,   -75,
      98,   -75,   -75,   147,   129,   -75,   -75,   -75,   -75,    82,
      82,   -75,   -75
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    28,    27,    26,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    31,     0,     0,     0,    25,    24,     0,
       0,     0,    19,     0,     0,    29,    11,     9,     0,     0,
       0,    18,    34,    32,    33,     0,    20,    15,    10,     8,
       0,    17,     0,    23,     0,    13,    16,    35,    30,     0,
       0,     0,     0,     0,    49,     0,     0,    52,    71,    72,
       0,    40,    38,     0,     0,    36,    39,    68,     0,    55,
      57,    59,    61,    63,    67,     0,     0,     0,     0,     0,
      68,    66,     0,    76,     0,    65,    31,    21,    37,    73,
      74,     0,    51,    50,     0,     0,     0,     0,     0,     0,
       0,    48,    47,    70,     0,    78,     0,    75,     0,    22,
      56,    58,    62,    60,    64,     0,     0,     0,     0,    69,
       0,    54,    53,    42,     0,    44,    46,    45,    77,     0,
       0,    43,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,   -75,   148,   -75,   -75,   -75,   -75,   -75,   -17,
     -75,   -75,    70,     1,   -75,   -75,   -64,   -20,   -53,   -48,
     -74,    60,    59,    61,   -52,   -75,   -75,   -75
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    40,    28,    21,    61,
      44,   109,    62,    63,    14,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,   106,   107
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      88,    10,    80,    81,    78,    79,    10,    80,    85,   105,
      26,    37,    17,    29,     1,     2,    22,   110,     3,    30,
      92,   101,   126,    45,    32,    95,    11,    98,    96,   100,
      80,    41,    47,   -14,    38,    13,   108,    27,    80,    18,
      19,    80,    80,    80,    80,   114,   128,    93,   102,   127,
      33,   123,    49,   125,    50,    51,    99,   -12,    48,     1,
       2,    39,    25,     3,    52,   131,   132,    80,   124,   121,
       9,    53,    15,    36,    87,     9,    16,    54,    31,   116,
      55,    56,    57,    58,    59,    49,    60,    50,    51,    34,
       1,     2,     1,     2,     3,   122,     3,    52,    83,    23,
      24,    35,    84,    20,    53,    36,    36,    89,    90,    91,
      54,    42,    53,    55,    56,    57,    58,    59,    54,    60,
      53,    55,    43,    57,    58,    59,    46,    60,    75,    55,
      76,    57,    58,    59,    77,    60,    89,    90,    82,    94,
      86,    97,   103,   104,    16,   115,   117,   118,   119,   120,
      95,   129,   130,    12,   111,   113,   112
};

static const yytype_uint8 yycheck[] =
{
      64,     0,    55,    55,    52,    53,     5,    60,    60,    83,
       1,    28,     1,    23,    10,    11,    15,    91,    14,    29,
       1,     1,     1,    40,     1,    37,     0,    75,    40,    77,
      83,    30,     1,    24,     1,    33,    84,    28,    91,    28,
      29,    94,    95,    96,    97,    97,   120,    28,    28,    28,
      27,   115,     3,   117,     5,     6,    76,    24,    27,    10,
      11,    28,    33,    14,    15,   129,   130,   120,   116,     1,
       0,    22,    22,    24,    25,     5,    26,    28,    33,    99,
      31,    32,    33,    34,    35,     3,    37,     5,     6,    27,
      10,    11,    10,    11,    14,    27,    14,    15,    22,    34,
      35,    26,    26,    23,    22,    24,    24,    19,    20,    21,
      28,    34,    22,    31,    32,    33,    34,    35,    28,    37,
      22,    31,    25,    33,    34,    35,    33,    37,    22,    31,
      22,    33,    34,    35,    22,    37,    19,    20,    22,    39,
      33,    38,    23,    33,    26,    23,    23,    23,    23,    29,
      37,     4,    23,     5,    94,    96,    95
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    11,    14,    43,    44,    45,    46,    47,    54,
      55,     0,    45,    33,    56,    22,    26,     1,    28,    29,
      23,    50,    55,    34,    35,    33,     1,    28,    49,    23,
      29,    33,     1,    27,    27,    26,    24,    51,     1,    28,
      48,    55,    34,    25,    52,    51,    33,     1,    27,     3,
       5,     6,    15,    22,    28,    31,    32,    33,    34,    35,
      37,    51,    54,    55,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    22,    22,    22,    61,    61,
      60,    66,    22,    22,    26,    66,    33,    25,    58,    19,
      20,    21,     1,    28,    39,    37,    40,    38,    61,    59,
      61,     1,    28,    23,    33,    62,    68,    69,    61,    53,
      62,    63,    65,    64,    66,    23,    59,    23,    23,    23,
      29,     1,    27,    58,    61,    58,     1,    28,    62,     4,
      23,    58,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    45,    46,    46,
      46,    46,    48,    47,    49,    47,    50,    50,    50,    50,
      52,    53,    51,    51,    54,    54,    55,    55,    55,    56,
      56,    56,    56,    56,    56,    56,    57,    57,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    59,
      59,    59,    60,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    66,    67,    67,
      67,    67,    67,    67,    67,    68,    68,    69,    69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       6,     5,     0,     7,     0,     6,     4,     3,     2,     1,
       0,     0,     5,     2,     3,     3,     1,     1,     1,     3,
       6,     1,     4,     4,     4,     6,     1,     2,     1,     1,
       1,     7,     5,     7,     5,     5,     5,     3,     3,     1,
       2,     2,     1,     4,     4,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     2,     2,     1,     1,     4,
       3,     1,     1,     2,     2,     1,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 83 "Parse.y" /* yacc.c:1646  */
    {
		//fprintf(log,"Line %d : start : program\n\n",line_count);
		logout<<"Line "<<line_count<<" : start program\n"<<endl;
		
		}
#line 1451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 90 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<" : program : program unit\n"<<endl;
		logout<<p<<endl;
		}
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 94 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<" : program : unit\n"<<endl;
		logout<<unit<<endl;
	}
#line 1469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 100 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<" : unit : var_declaration\n"<<endl;
		unit = var_dec;
		logout<<unit<<endl;
		var_dec = "\0";
		}
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 106 "Parse.y" /* yacc.c:1646  */
    {
		//fprintf(log,"Line %d : func_declaration\n\n",line_count);
		logout<<"Line "<<line_count<<" : unit : func_declaration\n"<<endl;
		unit = func_dec;
		logout<<unit<<endl;
		func_dec = "\0";
		}
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 114 "Parse.y" /* yacc.c:1646  */
    {
		
		logout<<"Line "<<line_count<<" : unit : func_definition\n"<<endl;
		unit = func_def;
		logout<<unit<<endl;
		func_def = "\0";
		}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 124 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<" : func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n"<<endl;
		func_dec =(yyvsp[-5].sym)->getvarType()+" "+ (yyvsp[-4].sym)->getName()+"("+param+")"+";";
		logout<<func_dec<<endl<<endl;
		//param = "\0";
		SymbolInfo *s = st.lookUp((yyvsp[-4].sym)->getName(),"function");
		//logout<<s->getidType()<<endl;
		if(s != NULL ){//&& s->getidType() == "function" && s->getvarType() == $1->getvarType()){
			//logout<<s->
			errorout<<"Error at line : "<<line_count<<" : function already declared"<<endl;
			semanticErrors++;
			logout<<s->param_list.size()<<endl;
		}
		else{
			(yyvsp[-4].sym)->setType("ID");
			SymbolInfo *si = new SymbolInfo((yyvsp[-4].sym)->getName(),(yyvsp[-4].sym)->getType(),"function",(yyvsp[-5].sym)->getvarType());
			si->setvarType((yyvsp[-5].sym)->getvarType());
			si->setidType("function");
			si->setreturnType(si->getvarType());
			/*for(int i = 0; i < args_name.size();i++){
			     logout<<args_name[i]<<args_type[i]<<endl;
			}*/
			for(int i = 0; i < args_name.size();i++){
			     si->param_list.push_back(args_name[i]);
			     si->param_type.push_back(args_type[i]);
			}
			st.insertSym(si);
			logout<<si->param_list.size()<<endl;
			args_name.clear();
			args_type.clear();
		}
		}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 157 "Parse.y" /* yacc.c:1646  */
    {
		func_dec = (yyvsp[-4].sym)->getvarType()+" "+ (yyvsp[-3].sym)->getName()+"()"+";";
		logout<<"Line "<<line_count<<" : func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n"<<endl;	
		logout<<func_dec<<endl<<endl;
		SymbolInfo *s = st.lookUp((yyvsp[-3].sym)->getName(),"function");
		//logout<<s->getidType()<<endl;
		if(s != NULL ){
			errorout<<"Error at line : "<<line_count<<" : function already declared"<<endl;
			semanticErrors++;
		}
		else{
			(yyvsp[-3].sym)->setType("ID");
			SymbolInfo *si = new SymbolInfo((yyvsp[-3].sym)->getName(),(yyvsp[-3].sym)->getType(),"function",(yyvsp[-4].sym)->getvarType());
			si->setvarType((yyvsp[-4].sym)->getvarType());
			si->setidType("function");
			si->setreturnType(si->getvarType());
			st.insertSym(si);
			st.printAll(logout);
		}
		//$$ = si;
		}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 179 "Parse.y" /* yacc.c:1646  */
    {
			errorout << "Error at line " << line_count << "; missing" << endl << endl;
			semanticErrors++;
		}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 184 "Parse.y" /* yacc.c:1646  */
    {
			errorout << "Error at line " << line_count << "; missing" << endl << endl;
			semanticErrors++;
		}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 190 "Parse.y" /* yacc.c:1646  */
    {SymbolInfo *si = new SymbolInfo((yyvsp[-3].sym)->getName(),(yyvsp[-3].sym)->getType(),"function",(yyvsp[-4].sym)->getvarType());
		//si->setvarType($1->getvarType());
		si->setreturnType(si->getvarType());
		//si->setidType("function");
		for(int i = 0; i < args_name.size();i++){
			si->param_list.push_back(args_name[i]);
			si->param_type.push_back(args_type[i]);
		}
		logout<<si->param_list.size()<<endl;
		st.insertSym(si);
		func_var = (yyvsp[-4].sym)->getName();
		//args_type.clear();
		/*st.printAll(logout);*/}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 202 "Parse.y" /* yacc.c:1646  */
    {
		logout << "Line " << line_count << " : func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n"<< endl;
		func_def = (yyvsp[-6].sym)->getvarType() + " " + (yyvsp[-5].sym)->getName() + "("+param+")"+comp_stmt;
		logout<<func_def<<endl<<endl;
		
		
		
		}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 210 "Parse.y" /* yacc.c:1646  */
    {(yyvsp[-2].sym)->setType("ID");
		//SymbolInfo *si = new SymbolInfo($2->getName(),$2->getType(),"int","function");
		SymbolInfo *si = new SymbolInfo((yyvsp[-2].sym)->getName(),(yyvsp[-2].sym)->getType(),"function",(yyvsp[-3].sym)->getvarType());
		//si->setvarType($1->getvarType());
		si->setreturnType(si->getvarType());
		//si->setidType("function");
		st.insertSym(si);
		st.printAll(logout);}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 217 "Parse.y" /* yacc.c:1646  */
    {
		logout << "Line " << line_count << " : func_definition : type_specifier ID LPAREN RPAREN compound_statement\n"<< endl;
		func_def = (yyvsp[-5].sym)->getvarType() + " " + (yyvsp[-4].sym)->getName() + "()"+comp_stmt;
		logout<<func_def<<endl<<endl;
		//fprintf(log,"Line %d : type_specifier ID LPAREN RPAREN compound_statement\n\n",line_count);
		
		}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 227 "Parse.y" /* yacc.c:1646  */
    {
		logout << "Line " << line_count << " : parameter_list : parameter_list COMMA type_specifier ID\n"<< endl;
		//logout<<$4->getName()<<endl<<endl;
		param = param+","+(yyvsp[-1].sym)->getvarType()+" "+(yyvsp[0].sym)->getName();;
		logout<<param<<endl;
		args_name.push_back((yyvsp[0].sym)->getName());
		args_type.push_back((yyvsp[-1].sym)->getvarType());
		//fprintf(log,"Line %d : parameter_list COMMA type_specifier ID\n\n",line_count);
		}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 236 "Parse.y" /* yacc.c:1646  */
    {
		logout << "Line " << line_count << " : parameter_list : parameter_list COMMA type_specifier\n"<< endl;
		//fprintf(log,"Line %d : parameter_list COMMA type_specifier\n\n",line_count);
		}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 241 "Parse.y" /* yacc.c:1646  */
    {
		logout << "Line " << line_count << " : parameter_list : type_specifier ID\n"<< endl;
		param = (yyvsp[-1].sym)->getvarType()+" "+(yyvsp[0].sym)->getName();
		logout<<param<<endl;
		args_name.push_back((yyvsp[0].sym)->getName());
		args_type.push_back((yyvsp[-1].sym)->getvarType());
		}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 248 "Parse.y" /* yacc.c:1646  */
    {
		logout << "Line " << line_count << " : parameter_list : type_specifier\n"<< endl;
		logout<<(yyvsp[0].sym)->getvarType()<<endl<<endl;
		//fprintf(log,"Line %d : type_specifier\n\n",line_count);
		}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 256 "Parse.y" /* yacc.c:1646  */
    {st.enterScope(logout);
			for(int i = 0; i < args_name.size(); i++){
			     SymbolInfo *si = new SymbolInfo(args_name[i],"ID","variable",args_type[i]);
			     st.insertSym(si);
			}
			args_name.clear();
			args_type.clear();}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 262 "Parse.y" /* yacc.c:1646  */
    {st.printAll(logout);st.exitScope(logout);}
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 262 "Parse.y" /* yacc.c:1646  */
    {
		logout << "Line " << line_count << " : compound_statement : LCURL statements RCURL\n"<< endl;
		comp_stmt = "{\n   "+stmts+"}\n";
		logout<<comp_stmt<<endl;
		stmts = "\0";
		}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 268 "Parse.y" /* yacc.c:1646  */
    {logout << "Line " << line_count << " : compound_statement : LCURL RCURL\n"<< endl;}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 272 "Parse.y" /* yacc.c:1646  */
    {
		var_dec = (yyvsp[-2].sym)->getvarType() + " "+var_dec +";";
	
		if(var == "void"){
			logout<<"Error at line "<<line_count<<" : variable cannot be a void"<<endl;
		}else{
		logout << "Line " << line_count << " : var_declaration : type_specifier declaration_list SEMICOLON\n"<< endl;
		logout<<var_dec<<endl; 
		
			}
		}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 283 "Parse.y" /* yacc.c:1646  */
    {
			logout << "Error at line " << line_count << "; missing" << endl << endl;
			semanticErrors++;
		}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 290 "Parse.y" /* yacc.c:1646  */
    {logout << "Line " << line_count << " type_specifier: VOID 	:\n"<< endl;
	//logout<<"void "<<endl<<endl;
	SymbolInfo *si = new SymbolInfo();
	var = "void";
	si->setvarType("void");
	(yyval.sym) = si;
	logout<<"void"<<endl;
	}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 299 "Parse.y" /* yacc.c:1646  */
    {logout << "Line " << line_count << " type_specifier	: FLOAT:\n"<< endl;
		//logout<<"float "<<endl<<endl;
		SymbolInfo *si = new SymbolInfo();
		var = "float";
		si->setvarType("float");
		(yyval.sym) = si;
		logout<<var<<endl;}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 307 "Parse.y" /* yacc.c:1646  */
    {logout << "Line " << line_count << " type_specifier: INT:\n"<< endl;
		//logout<<"int "<<endl<<endl;
		SymbolInfo *si = new SymbolInfo();
		var = "int";
		si->setvarType("int");
		(yyval.sym) = si;
		logout<<var<<endl;}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 316 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": declaration_list : declaration_list COMMA ID"<<endl<<endl;
		//logout<<","<<$3->getName()<<endl<<endl;
		var_dec = var_dec + "," + (yyvsp[0].sym)->getName();
		logout<<var_dec<<endl<<endl;
		if(var == "void"){
		   errorout<<"Error at line "<<line_count<<" : variable cannot be void"<<endl;
			semanticErrors++;
		}
		SymbolInfo *s = st.lookUp((yyvsp[0].sym)->getName(),"variable");
		if(s != NULL){
			errorout<<"Error at line : "<<line_count<<" variable already declared "<<endl;
			semanticErrors++;
		}
		else{
			(yyvsp[0].sym)->setType("ID");
			//SymbolInfo *si = new SymbolInfo($3->getName(),$3->getType(),"int","variable");
			SymbolInfo *si = new SymbolInfo((yyvsp[0].sym)->getName(),(yyvsp[0].sym)->getType(),"variable",var);
			//si->setvarType($1->getvarType());
			si->setidType("variable");
			//si->returnType()
			st.insertSym(si);
			//st.printAll(logout);
		}
		}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 341 "Parse.y" /* yacc.c:1646  */
    {
		var_dec = var_dec + yytext + (yyvsp[-3].sym)->getName()+"["+(yyvsp[-1].sym)->getName()+"]";
		logout<<var_dec<<endl;
		if(var == "void"){
			  logout<<"Error at line "<<line_count<<" : variable cannot be a void"<<endl;
			}else{
			SymbolInfo *s = st.lookUp((yyvsp[-3].sym)->getName(),"array");
			if(s != NULL){
				errorout<<"Error at line : "<<line_count<<": array already declared"<<endl<<endl;
				semanticErrors++;
			}
			else{
			logout<<"Line "<<line_count<<": declaration_list COMMa ID LTHIRD CONST_INT RTHIRD"<<endl<<endl;
			logout<<p<<endl<<endl;
			SymbolInfo *si = new SymbolInfo();
			si = (yyvsp[-3].sym);
			si->setidType("array");
			si->setvarType(var);
			si->setarraySize(atoi((yyvsp[-1].sym)->getName().c_str()));
			st.insertSym(si);
			//$$ = si;
			//st.printAll(logout);
			
			}	
			
			} 
		}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 368 "Parse.y" /* yacc.c:1646  */
    {
			var_dec = (yyvsp[0].sym)->getName();
			if(var == "void"){
			  logout<<"Error at line "<<line_count<<" : variable cannot be a void"<<endl;
			}else{
			logout<<"Line "<<line_count<<": declaration_list : ID"<<endl<<endl;
			logout<<var_dec<<endl;
			//logout<<$1->getName()<<endl<<endl;
			SymbolInfo *s = st.lookUp((yyvsp[0].sym)->getName(),"variable");
			if(s != NULL){
			    errorout<<"Error at line : "<<line_count<<": variable already declared"<<endl<<endl;
				semanticErrors++;
			}
			else{
			(yyvsp[0].sym)->setType("ID");
			SymbolInfo *si = new SymbolInfo((yyvsp[0].sym)->getName(),(yyvsp[0].sym)->getType(),"variable",var);
			//si->setvarType($1->getvarType());
			si->setidType("variable");
			//si->returnType()
			st.insertSym(si);
			//st.printAll(logout);
			
		}	//$$ = $1;
}
			}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 393 "Parse.y" /* yacc.c:1646  */
    {
			var_dec = (yyvsp[-3].sym)->getName()+"["+(yyvsp[-1].sym)->getName()+"]";
			logout<<var_dec<<endl;
			if(var == "void"){
			  logout<<"Error at line "<<line_count<<" : variable cannot be a void"<<endl;
			}else{
			SymbolInfo *s = st.lookUp((yyvsp[-3].sym)->getName(),"array");
			if(s != NULL){
				errorout<<"Error at line : "<<line_count<<": array already declared"<<endl<<endl;
				semanticErrors++;
			}
			else{
			logout<<"Line "<<line_count<<": declaration_list : ID LTHIRD CONST_INT RTHIRD"<<endl<<endl;
			//logout<<$1->getName()<<"["<<$3->getName()<<"]"<<endl<<endl;
			SymbolInfo *si = new SymbolInfo((yyvsp[-3].sym)->getName(),(yyvsp[-3].sym)->getType());
			si = (yyvsp[-3].sym);
			si->setidType("array");
			si->setarraySize(atoi((yyvsp[-1].sym)->getName().c_str()));
			si->setvarType(var);
			st.insertSym(si);
			//$$ = si;
			//st.printAll(logout);
			
			}	
			
			} 
		}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 420 "Parse.y" /* yacc.c:1646  */
    {
		errorout<<"error at line : "<<line_count<<": array index cannot be a float"<<endl<<endl;
		semanticErrors++;
		}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 424 "Parse.y" /* yacc.c:1646  */
    {
			errorout << "Error at line " << line_count << " : ] missing" << endl << endl;
			semanticErrors++;
		}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 428 "Parse.y" /* yacc.c:1646  */
    {
			errorout << "Error at line " << line_count << " : ] missing" << endl << endl;
			semanticErrors++;		
		}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 434 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": statements : statement"<<endl<<endl;
		stmts=(yyvsp[0].sym)->str;
		logout<<stmt<<endl;
		stmt = "\0";
		(yyval.sym)->str = stmts;
		//stmts = "\0";
		}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 442 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": statements : statements statement"<<endl<<endl;
		stmts = (yyvsp[-1].sym)->str + (yyvsp[0].sym)->str;
		//stmts1 = stmts1 + stmts;
		logout<<stmts<<endl<<endl;
		//logout<<stmts1<<endl;
		//s = stmts;
		stmt = "\0";
		(yyval.sym)->str = stmts;;
		}
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 454 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": statement : var_declaration"<<endl<<endl;
		stmt = var_dec;
		logout<<stmt<<endl;
		var_dec = "\0";
		(yyval.sym)->str = stmt;
		}
#line 1974 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 461 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": statement : expression_statement"<<endl<<endl;
		stmt = expr_stmt;
		logout<<stmt<<endl;
		expr_stmt = "\0";
		(yyval.sym)->str = stmt;
		}
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 468 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": statement : compound_statement"<<endl<<endl;
		stmt = comp_stmt;
		logout<<stmt<<endl;
		(yyval.sym)->str = stmt;
		}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 474 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement"<<endl<<endl;
		//$$->setName(stmt);
	}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 478 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": statement : IF LPAREN expression RPAREN statement"<<endl<<endl;
		stmt = "if(" + (yyvsp[-2].sym)->str + ")" + (yyvsp[0].sym)->str;
		logout<<stmt<<endl;
		(yyval.sym)->str = stmt;
	}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 484 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": statement : IF LPAREN expression RPAREN statement ELSE statement"<<endl<<endl;
		stmt = "if(" + (yyvsp[-4].sym)->str + ")" + (yyvsp[-2].sym)->str + "\nelse\n"+(yyvsp[0].sym)->str;
		logout<<stmt<<endl;
		(yyval.sym)->str = stmt;
	}
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 490 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": statement : WHILE LPAREN expression RPAREN statement"<<endl<<endl;
		stmt = "while(" + (yyvsp[-2].sym)->str + ")" + (yyvsp[0].sym)->str;
		(yyval.sym)->str = stmt;
		logout<<stmt<<endl;
	}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 496 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": statement : PRINTLN LPAREN ID RPAREN SEMICOLON"<<endl<<endl;
		stmt = "printf(" + (yyvsp[-2].sym)->getName()+");\n";
		(yyval.sym)->str = stmt;
		logout<<stmt<<endl;
	}
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 502 "Parse.y" /* yacc.c:1646  */
    {
		errorout << "Error at line " << line_count << "; missing" << endl << endl;
		semanticErrors++;
	}
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 506 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": statement : RETURN expression SEMICOLON"<<endl<<endl;
		stmt = "return "+  (yyvsp[-1].sym)->str +";";
		logout<<stmt<<endl;
		expr = "\0";
		(yyval.sym)->str = stmt;	}
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 512 "Parse.y" /* yacc.c:1646  */
    {
		errorout << "Error at line " << line_count << "; missing" << endl << endl;
		semanticErrors++;
	}
#line 2079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 518 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": expression_statement : SEMICOLON"<<endl<<endl;
		//logout<<";"<<endl<<endl;
		expr_stmt = expr_stmt + ";\n";
		logout<<expr_stmt<<endl;
		//$$->setName(expr_stmt);
	}
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 525 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": expression_statement : expression SEMICOLON"<<endl<<endl;
		expr_stmt = (yyvsp[-1].sym)->str +";\n";
		SymbolInfo *si = new SymbolInfo();
		si->str = expr_stmt;
		logout<<expr_stmt<<endl;
		(yyval.sym) = si;
		expr = "\0";
		
	}
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 534 "Parse.y" /* yacc.c:1646  */
    {
			errorout << "Error at line " << line_count << "; missing" << endl << endl;
			semanticErrors++;
		}
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 540 "Parse.y" /* yacc.c:1646  */
    {
	logout<<"Line "<<line_count<<": variable : ID"<<endl<<endl;
	VAR = (yyvsp[0].sym)->getName();
	logout<<VAR<<endl;
	//VAR = "\0";
	logout<<(yyvsp[0].sym)->getName()<<endl<<endl;
	(yyvsp[0].sym)->setidType("variable");
	SymbolInfo *s = st.lookUp((yyvsp[0].sym)->getName(),"variable");
	if(s == NULL){
		errorout<<"Error at line "<<line_count<<" : variable was not declared in this scope"<<endl;
		semanticErrors++;
	}
	else{
		(yyval.sym) = s;
		//logout<<s->ival<<endl;
		(yyval.sym)->setVal(s->ival);
		(yyval.sym)->setName((yyvsp[0].sym)->getName());
		(yyval.sym)->str = VAR;
	}
	}
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 560 "Parse.y" /* yacc.c:1646  */
    {
	logout<<"Line "<<line_count<<": variable : ID LTHIRD expression RTHIRD "<<endl<<endl;
	VAR = (yyvsp[-3].sym)->getName() + "[" + expr + "]";
	logout<<VAR<<endl;
	expr = "\0";
	SymbolInfo *si = st.lookUp((yyvsp[-3].sym)->getName(),"array");
	if(si != NULL){
	//logout<<si->getName()<<"["<<$3->ival<<"]"<<endl<<endl;
	//logout<<si->getarraySize()<<endl<<endl;
	
		/*if($3->ival>si->getarraySize()){
	  	errorout<<"Error at line "<<line_count<<" : arraybound exceeded"<<endl<<endl;
		}*/
		if((yyvsp[-1].sym)->getvarType() == "float"){
	  	 errorout<<"Error at line "<<line_count<<" : array index cannot be a float"<<endl<<endl;
		semanticErrors++;
		}
		(yyval.sym) = si;
		}
		(yyval.sym)->str = VAR;
		//logout<<$$->getName()<<endl;
}
#line 2167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 582 "Parse.y" /* yacc.c:1646  */
    {
		errorout << "Error at line " << line_count << " : ] missing" << endl << endl;
			semanticErrors++;
	}
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 588 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": expression : logic_expression	"<<endl<<endl;
		expr = logic_expr;
		logout<<expr<<endl;
		logic_expr = "\0";
		//expr = "\0";
		if((yyvsp[0].sym)->getidType() == "variable"){
		    (yyval.sym) = (yyvsp[0].sym);
		    if((yyval.sym)->getvarType() == "int"){
			(yyval.sym)->setVal((yyvsp[0].sym)->ival);
			logout<<(yyval.sym)->ival<<endl;
			}
			else if((yyval.sym)->getvarType() == "float"){
			//$$->setVal($1->ival);
			(yyval.sym)->setFloat((yyvsp[0].sym)->ifloat);
			}
		}else if((yyvsp[0].sym)->getidType() == "array"){
		    (yyval.sym) = (yyvsp[0].sym);
		    if((yyval.sym)->getvarType() == "int"){
			(yyval.sym)->setVal((yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex]);
			(yyval.sym)->integer[(yyvsp[0].sym)->arrayIndex] = (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			logout<<(yyval.sym)->integer[(yyvsp[0].sym)->arrayIndex]<<endl;
			}
			else if((yyval.sym)->getvarType() == "float"){
			//$$->setVal($1->ival);
			(yyval.sym)->setFloat((yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex]);
			(yyval.sym)->floating[(yyvsp[0].sym)->arrayIndex] = (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			
			}
		}
		(yyval.sym)->str = expr;
	}
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 620 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": expression : variable ASSIGNOP logic_expression"<<endl<<endl;
		expr = (yyvsp[-2].sym)->str + "=" + logic_expr;
		logout<<expr<<endl;
		logout<<(yyvsp[-2].sym)->getvarType()<<endl;
		logout<<(yyvsp[0].sym)->getvarType()<<endl;
		//expr = "\0";
		SymbolInfo *si = st.lookUp((yyvsp[-2].sym)->getName(),(yyvsp[-2].sym)->getidType());
		if(si != NULL){
		//if($1->getidType() )	
	if(si->getidType() == "variable"){
		if(si->getvarType() == "int"){
			if((yyvsp[0].sym)->getvarType() == "int"){
			    si->setVal((yyvsp[0].sym)->ival);
			    logout<<si->ival<<endl;
			}
		   	else if((yyvsp[0].sym)->getvarType() == "float"){
			    errorout<<"Error at line "<<line_count<<" : type mismatch"<<endl<<endl;
				semanticErrors++;
			}
		}
		else if(si->getvarType() == "float"){
			if((yyvsp[0].sym)->getvarType() == "int"){
			    errorout<<"Error at line "<<line_count<<" : type mismatch"<<endl<<endl;
				semanticErrors++;
			}
		   	else if((yyvsp[0].sym)->getvarType() == "float"){
			    si->setFloat((yyvsp[0].sym)->ifloat);
			    logout<<si->ifloat<<endl;
			}
		}
	}else if(si->getidType() == "array"){
		if(si->getvarType() == "int"){
			if((yyvsp[0].sym)->getvarType() == "int"){
			    si->initInteger();
			    si->integer[(yyvsp[-2].sym)->arrayIndex] = (yyvsp[0].sym)->ival;
			    logout<<si->getName()<<"["<<(yyvsp[-2].sym)->arrayIndex<<"] = "<<si->integer[(yyvsp[-2].sym)->arrayIndex]<<endl;	
			    logout<<(yyvsp[-2].sym)->arrayIndex<<endl;
			}
		   	else if((yyvsp[0].sym)->getvarType() == "float"){
			    errorout<<"Error at line "<<line_count<<" : type mismatch"<<endl<<endl;
				semanticErrors++;
			}
		}
		else if(si->getvarType() == "float"){
			if((yyvsp[0].sym)->getvarType() == "int"){
			    logout<<"Error at line "<<line_count<<" : type mismatch"<<endl<<endl;
			}
		   	else if((yyvsp[0].sym)->getvarType() == "float"){
			    si->initFloat();
			    si->floating[(yyvsp[-2].sym)->arrayIndex] = (yyvsp[0].sym)->ifloat;
			    logout<<si->floating[(yyvsp[-2].sym)->arrayIndex]<<endl;
			}
		}
	
	}
	if((yyvsp[0].sym)->getidType() == "function" && (yyvsp[0].sym)->getvarType() == "void"){errorout<<"Error at line "<<line_count<<" : "<<logic_expr<<" does not return anything"<<endl;semanticErrors++;}
	logic_expr = "\0";
	(yyval.sym) = si;
	(yyval.sym)->str = expr;
	}
		//$$ = si;
		
	}
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 686 "Parse.y" /* yacc.c:1646  */
    {

		logout<<"Line "<<line_count<<": logic_expression : rel_expression"<<endl<<endl;
		logic_expr = rel_expr;
		logout<<logic_expr<<endl;
		rel_expr = "\0";
		if((yyvsp[0].sym)->getidType() == "variable"){
		    (yyval.sym) = (yyvsp[0].sym);
		    if((yyval.sym)->getvarType() == "int"){
			(yyval.sym)->setVal((yyvsp[0].sym)->ival);
			logout<<(yyval.sym)->ival<<endl;
			}
			else if((yyval.sym)->getvarType() == "float"){
			//$$->setVal($1->ival);
			(yyval.sym)->setFloat((yyvsp[0].sym)->ifloat);
			}
		}else if((yyvsp[0].sym)->getidType() == "array"){
		    (yyval.sym) = (yyvsp[0].sym);
		    if((yyval.sym)->getvarType() == "int"){
			(yyval.sym)->setVal((yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex]);
			(yyval.sym)->integer[(yyvsp[0].sym)->arrayIndex] = (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			logout<<(yyval.sym)->integer[(yyvsp[0].sym)->arrayIndex]<<endl;
			}
			else if((yyval.sym)->getvarType() == "float"){
			//$$->setVal($1->ival);
			(yyval.sym)->setFloat((yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex]);
			(yyval.sym)->floating[(yyvsp[0].sym)->arrayIndex] = (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			
			}
		}
		(yyval.sym)->str = logic_expr;
		
	}
#line 2320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 719 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": logic_expression : rel_expression LOGICOP rel_expression"<<endl<<endl;
		logic_expr = (yyvsp[-2].sym)->str +" "+ (yyvsp[-1].sym)->getName() +" "+ (yyvsp[0].sym)->str;
		logout<<logic_expr<<endl;
		rel_expr = "\0";
		SymbolInfo *si = new SymbolInfo();
		si->setvarType("int");
		si->setidType("variable");
		if((yyvsp[-1].sym)->getName() == "&&"){
		   if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "variable"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			     si->ival = (yyvsp[-2].sym)->ival && (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			     si->ival = (yyvsp[-2].sym)->ival && (yyvsp[0].sym)->ifloat;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			     si->ival = (yyvsp[-2].sym)->ifloat && (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			     si->ival = (yyvsp[-2].sym)->ifloat && (yyvsp[0].sym)->ifloat;
			}
		   }
		   else if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "array"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->ival && (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->ival && (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->ifloat && (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->ifloat && (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
		  }
		  else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "variable"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] && (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] && (yyvsp[0].sym)->ifloat;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] && (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] && (yyvsp[0].sym)->ifloat;
			}
		  }
		  else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "array"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] && (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] && (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] && (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] && (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
		  }
		   
		}
		else if((yyvsp[-1].sym)->getName() == "||"){
		   if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "variable"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			     si->ival = (yyvsp[-2].sym)->ival || (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			     si->ival = (yyvsp[-2].sym)->ival || (yyvsp[0].sym)->ifloat;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			     si->ival = (yyvsp[-2].sym)->ifloat || (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			     si->ival = (yyvsp[-2].sym)->ifloat || (yyvsp[0].sym)->ifloat;
			}
		   }
		   else if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "array"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->ival || (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->ival || (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->ifloat || (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->ifloat || (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
		  }
		  else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "variable"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] || (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] || (yyvsp[0].sym)->ifloat;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] || (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] || (yyvsp[0].sym)->ifloat;
			}
		  }
		  else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "array"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] || (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] || (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] || (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] || (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
		  }
		   
		}
		
		(yyval.sym) = si;
		(yyval.sym)->str = logic_expr;
	}
#line 2455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 851 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": rel_expression	: simple_expression"<<endl<<endl;
		rel_expr = (yyvsp[0].sym)->str;
		logout<<rel_expr<<endl;
		simp_expr = "\0";
		if((yyvsp[0].sym)->getidType() == "variable"){
		    (yyval.sym) = (yyvsp[0].sym);
		    if((yyval.sym)->getvarType() == "int"){
			(yyval.sym)->setVal((yyvsp[0].sym)->ival);
			}
			else if((yyval.sym)->getvarType() == "float"){
			//$$->setVal($1->ival);
			(yyval.sym)->setFloat((yyvsp[0].sym)->ifloat);
			}
		}else if((yyvsp[0].sym)->getidType() == "array"){
		    (yyval.sym) = (yyvsp[0].sym);
		    if((yyval.sym)->getvarType() == "int"){
			(yyval.sym)->setVal((yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex]);
			(yyval.sym)->integer[(yyvsp[0].sym)->arrayIndex] = (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			logout<<(yyval.sym)->integer[(yyvsp[0].sym)->arrayIndex]<<endl;
			}
			else if((yyval.sym)->getvarType() == "float"){
			(yyval.sym)->setFloat((yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex]);
			(yyval.sym)->floating[(yyvsp[0].sym)->arrayIndex] = (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			
			}
		}
		(yyval.sym)->str = rel_expr;
		}
#line 2489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 880 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": rel_expression	: simple_expression RELOP simple_expression"<<endl<<endl;
		rel_expr = (yyvsp[-2].sym)->str +" "+ (yyvsp[-1].sym)->getName() +" "+ (yyvsp[0].sym)->str;
		logout<<rel_expr<<endl;
		simp_expr = "\0";
		SymbolInfo *si = new SymbolInfo();
		si->setvarType("int");
		si->setidType("variable");
		if((yyvsp[-1].sym)->getName() == "=="){
		     if((yyvsp[-2].sym)->getvarType() == (yyvsp[0].sym)->getvarType() ){
			if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "variable"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType()=="int"){
				if((yyvsp[-2].sym)->ival == (yyvsp[0].sym)->ival){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType()=="float"){
				if((yyvsp[-2].sym)->ifloat == (yyvsp[0].sym)->ifloat){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
		    }
		    else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "variable"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType()=="int"){
				if((yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] == (yyvsp[0].sym)->ival){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType()=="float"){
				if((yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] == (yyvsp[0].sym)->ifloat){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
		    }
		    else if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "array"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType()=="int"){
				if((yyvsp[-2].sym)->ival == (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex]){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType()=="float"){
				if((yyvsp[-2].sym)->ifloat == (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex]){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
		    }
		    else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "array"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType()=="int"){
				if((yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] == (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex]){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType()=="float"){
				if((yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] == (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex]){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
		    }
		}
		     else{
			errorout<<"Error at line "<<line_count<<" : type mismatch"<<endl<<endl;
			semanticErrors++;
			si->setVal(0);
			}
		}
		 else if((yyvsp[-1].sym)->getName() == "!="){
		     if((yyvsp[-2].sym)->getvarType() == (yyvsp[0].sym)->getvarType() ){
			if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "variable"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType()=="int"){
				if((yyvsp[-2].sym)->ival != (yyvsp[0].sym)->ival){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType()=="float"){
				if((yyvsp[-2].sym)->ifloat != (yyvsp[0].sym)->ifloat){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
		    }
		    else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "variable"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType()=="int"){
				if((yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] != (yyvsp[0].sym)->ival){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType()=="float"){
				if((yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] != (yyvsp[0].sym)->ifloat){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
		    }
		    else if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "array"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType()=="int"){
				if((yyvsp[-2].sym)->ival != (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex]){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType()=="float"){
				if((yyvsp[-2].sym)->ifloat != (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex]){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
		    }
		    else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "array"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType()=="int"){
				if((yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] != (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex]){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType()=="float"){
				if((yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] != (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex]){
				    si->ival = 1;
				}
				else{
				   si->ival = 0;
				}
			}
		    }
		}
		     else{
			errorout<<"Error at line "<<line_count<<" : type mismatch"<<endl<<endl;
			semanticErrors++;
			si->setVal(0);
			}
		}
		else if((yyvsp[-1].sym)->getName() == ">"){
		  if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "variable"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->ival > (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->ival > (yyvsp[0].sym)->ifloat;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->ifloat > (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->ifloat > (yyvsp[0].sym)->ifloat;
			}
		  }
		  else if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "array"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->ival > (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->ival > (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->ifloat > (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->ifloat > (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
		  }
		  else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "variable"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] > (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] > (yyvsp[0].sym)->ifloat;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] > (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] > (yyvsp[0].sym)->ifloat;
			}
		  }
		  else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "array"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] > (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] > (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] > (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] > (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
		  }
		}
		else if((yyvsp[-1].sym)->getName() == ">="){
		  if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "variable"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->ival >= (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->ival > (yyvsp[0].sym)->ifloat;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->ifloat >= (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->ifloat >= (yyvsp[0].sym)->ifloat;
			}
		  }
		  else if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "array"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->ival >= (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->ival >= (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->ifloat >= (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->ifloat >= (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
		  }
		  else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "variable"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] >= (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] >= (yyvsp[0].sym)->ifloat;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] >= (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] >= (yyvsp[0].sym)->ifloat;
			}
		  }
		  else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "array"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] >= (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] >= (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] >= (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] >= (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
		  }
		}
		else if((yyvsp[-1].sym)->getName() == "<"){
		  if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "variable"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->ival < (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->ival < (yyvsp[0].sym)->ifloat;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->ifloat < (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->ifloat < (yyvsp[0].sym)->ifloat;
			}
		  }
		  else if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "array"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->ival < (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->ival < (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->ifloat < (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->ifloat < (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
		  }
		  else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "variable"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] < (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] < (yyvsp[0].sym)->ifloat;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] < (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] < (yyvsp[0].sym)->ifloat;
			}
		  }
		  else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "array"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] < (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] < (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] < (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] < (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
		  }
		}
		else if((yyvsp[-1].sym)->getName() == "<="){
		  if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "variable"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->ival <= (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->ival <= (yyvsp[0].sym)->ifloat;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->ifloat <= (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->ifloat <= (yyvsp[0].sym)->ifloat;
			}
		  }
		  else if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "array"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->ival <= (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->ival <= (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->ifloat <= (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->ifloat <= (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
		  }
		  else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "variable"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] <= (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] <= (yyvsp[0].sym)->ifloat;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] <= (yyvsp[0].sym)->ival;
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] <= (yyvsp[0].sym)->ifloat;
			}
		  }
		  else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "array"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] <= (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex] <= (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] <= (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
			   si->ival = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex] <= (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
		  }
		}
		(yyval.sym) = si;
		(yyval.sym)->str = rel_expr;
		
	}
#line 2900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1288 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": simple_expression : term"<<endl<<endl;
		simp_expr = term;
		logout<<simp_expr<<endl;
		logout<<(yyvsp[0].sym)->getidType()<<endl;
		term = "\0";
		(yyval.sym)->str = simp_expr;
		if((yyvsp[0].sym)->getType() == "ID"){simp_expr = "\0";}
		if((yyvsp[0].sym)->getidType() == "variable"){
		    (yyval.sym) = (yyvsp[0].sym);
		    if((yyval.sym)->getvarType() == "int"){
			(yyval.sym)->setVal((yyvsp[0].sym)->ival);
			}
			else if((yyval.sym)->getvarType() == "float"){
			//$$->setVal($1->ival);
			(yyval.sym)->setFloat((yyvsp[0].sym)->ifloat);
			}
		}else if((yyvsp[0].sym)->getidType() == "array"){
		    (yyval.sym) = (yyvsp[0].sym);
		    if((yyval.sym)->getvarType() == "int"){
			(yyval.sym)->setVal((yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex]);
			(yyval.sym)->integer[(yyvsp[0].sym)->arrayIndex] = (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			//logout<<$$->integer[$1->arrayIndex]<<endl;
			}
			else if((yyval.sym)->getvarType() == "float"){
			//$$->setVal($1->ival);
			(yyval.sym)->setFloat((yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex]);
			(yyval.sym)->floating[(yyvsp[0].sym)->arrayIndex] = (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			
			}
		}
		//$$->setName(simp_expr);
		simp_expr = "\0";
	}
#line 2939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1322 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": simple_expression : simple_expression ADDOP term "<<endl<<endl;
		simp_expr = (yyvsp[-2].sym)->str + (yyvsp[-1].sym)->getName()+term;
		logout<<simp_expr<<endl;
		term = "\0";
		if((yyvsp[-1].sym)->getName() == "+"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
				(yyval.sym)->setvarType("float");
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				(yyval.sym)->setvarType("int");
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
				(yyval.sym)->setvarType("float");
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
				(yyval.sym)->setvarType("float");
			}
		      
			if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "variable"){
				if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = (yyvsp[-2].sym)->ival+(yyvsp[0].sym)->ival;
				      //$1->setVal(si->ival);
				      (yyval.sym) = si;
				      
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float((yyvsp[-2].sym)->ival)+(yyvsp[0].sym)->ifloat;
				   
				      (yyval.sym) = si;

				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->ifloat+float((yyvsp[0].sym)->ival);
				      
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->ifloat+(yyvsp[0].sym)->ifloat;
				      char *ch;
				      
				}	
			}
			else if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "array"){
				if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = (yyvsp[-2].sym)->ival+(yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
				      //$1->setVal(si->ival);
				      (yyval.sym) = si;
				      
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float((yyvsp[-2].sym)->ival)+(yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
				   
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->ifloat+float((yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex]);
				      
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->ifloat+(yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
				      (yyval.sym) = (yyvsp[-2].sym);
				      
				}	
			}
			else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "variable"){
				if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex]+(yyvsp[0].sym)->ival;
				      //$1->setVal(si->ival);
				      (yyval.sym) = si;
				      
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float((yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex])+(yyvsp[0].sym)->ifloat;
				   
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex]+float((yyvsp[0].sym)->ival);
				      
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[0].sym)->ifloat+(yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex];
				      (yyval.sym) = si;
				}	
			}
			else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "array"){
				if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex]+(yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
				      //$1->setVal(si->ival);
				      (yyval.sym) = si;
				      
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float((yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex])+(yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
				   
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex]+float((yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex]);
				      
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex]+(yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex];
				      (yyval.sym) = si;
				}	
			}
		}
		else if((yyvsp[-1].sym)->getName() == "-"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
				(yyval.sym)->setvarType("float");
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				(yyval.sym)->setvarType("int");
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
				(yyval.sym)->setvarType("float");
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
				(yyval.sym)->setvarType("float");
			}
		      
		      if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "variable"){
				if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = (yyvsp[-2].sym)->ival-(yyvsp[0].sym)->ival;
				      (yyvsp[-2].sym)->setVal(si->ival);
				      logout<<si->ival<<endl;
				      (yyval.sym) = si;
				      
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float((yyvsp[-2].sym)->ival)-(yyvsp[0].sym)->ifloat;
				      
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->ifloat-float((yyvsp[0].sym)->ival);
				      
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->ifloat-(yyvsp[0].sym)->ifloat;
				      
				      (yyval.sym) = si;
				      
				}	
			}
			else if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "array"){
				if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = (yyvsp[-2].sym)->ival-(yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
				      //$1->setVal(si->ival);
				      (yyval.sym) = si;
				      
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float((yyvsp[-2].sym)->ival)-(yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
				   
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->ifloat-float((yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex]);
				      
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->ifloat-(yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
				      char *ch;
				      
				}	
			}
			else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "variable"){
				if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex]-(yyvsp[0].sym)->ival;
				      //$1->setVal(si->ival);
				      (yyval.sym) = si;
				      
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float((yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex])-(yyvsp[0].sym)->ifloat;
				   
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex]-float((yyvsp[0].sym)->ival);
				      
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->ifloat-(yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
				      char *ch;
				      
				}	
			}
			else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "array"){
				if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex]-(yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
				      //$1->setVal(si->ival);
				      (yyval.sym) = si;
				      
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float((yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex])-(yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
				   
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex]-float((yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex]);
				      
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex]-(yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex];
				      (yyval.sym) = si;
				      
				}	
			}
		}
		(yyval.sym)->str= simp_expr;
		
	}
#line 3287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1667 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": term : unary_expression "<<endl<<endl;
		term = una_expr;
		una_expr = "\0";
		logout<<term<<endl;
		if((yyvsp[0].sym)->getidType() == "variable"){
		    (yyval.sym) = (yyvsp[0].sym);
		    if((yyval.sym)->getvarType() == "int"){
			(yyval.sym)->setVal((yyvsp[0].sym)->ival);
			}
			else if((yyval.sym)->getvarType() == "float"){
			//$$->setVal($1->ival);
			(yyval.sym)->setFloat((yyvsp[0].sym)->ifloat);
			}
		}else if((yyvsp[0].sym)->getidType() == "array"){
		    (yyval.sym) = (yyvsp[0].sym);
		    if((yyval.sym)->getvarType() == "int"){
			(yyval.sym)->setVal((yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex]);
			(yyval.sym)->integer[(yyvsp[0].sym)->arrayIndex] = (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			//logout<<$$->integer[$1->arrayIndex]<<endl;
			}
			else if((yyval.sym)->getvarType() == "float"){
			//$$->setVal($1->ival);
			(yyval.sym)->setFloat((yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex]);
			(yyval.sym)->floating[(yyvsp[0].sym)->arrayIndex] = (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			
			}
		}
	}
#line 3321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1696 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": term : term MULOP unary_expression "<<endl<<endl;
		term = term + (yyvsp[-1].sym)->getName()+una_expr;
		logout<<term<<endl;
		una_expr = "\0";
		if((yyvsp[-1].sym)->getName() == "*"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
				(yyval.sym)->setvarType("float");
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				(yyval.sym)->setvarType("int");
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
				(yyval.sym)->setvarType("float");
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
				(yyval.sym)->setvarType("float");
			}
		      
		      if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "variable"){
				if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = (yyvsp[-2].sym)->ival*(yyvsp[0].sym)->ival;
				      //$1->setVal(si->ival);
				      
				      (yyval.sym) = si;
				      
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float((yyvsp[-2].sym)->ival)*(yyvsp[0].sym)->ifloat;
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->ifloat*float((yyvsp[0].sym)->ival);
				      
				      (yyval.sym) = si;
					logout<<(yyval.sym)->getvarType()<<endl;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->ifloat*(yyvsp[0].sym)->ifloat;
				      (yyval.sym) = si;
				      
				}	
			}
			else if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "array"){
				if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = (yyvsp[-2].sym)->ival*(yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
				      (yyval.sym) = si;
				      
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float((yyvsp[-2].sym)->ival)*(yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
				      
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->ifloat*float((yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex]);
				      
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->ifloat*(yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
				      (yyval.sym) = si;
				      
				}	
			}
			else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "variable"){
				if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex]*(yyvsp[0].sym)->ival;
				      (yyval.sym) = si;      
				}
				else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float((yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex])*(yyvsp[0].sym)->ifloat;
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex]*float((yyvsp[0].sym)->ival);
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex]*(yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
				      (yyval.sym) = si;
				      
				}	
			}
			else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "array"){
				if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("int");
				      si->setType("CONST_INT");
				      si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex]*(yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
				     (yyval.sym) = si;
				      
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float((yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex])*(yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex]*float((yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex]);
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex]*(yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
				      (yyval.sym) = si;      
				}	
			}
		}
		else if((yyvsp[-1].sym)->getName() == "/"){
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
				(yyval.sym)->setvarType("float");
			}
			else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				(yyval.sym)->setvarType("int");
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
				(yyval.sym)->setvarType("float");
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
				(yyval.sym)->setvarType("float");
			}
		      
		      if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "variable"){
				if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      if((yyvsp[-2].sym)->ival%(yyvsp[0].sym)->ival == 0){
					   si->setvarType("int");
					   si->setType("CONST_INT");
					   si->ival = (yyvsp[-2].sym)->ival/(yyvsp[0].sym)->ival;
					} 
					else{
					   si->setvarType("float");
					   si->setType("CONST_FLOAT");
					   si->ifloat = (yyvsp[-2].sym)->ival/(yyvsp[0].sym)->ival;
					} 
					(yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float((yyvsp[-2].sym)->ival)/(yyvsp[0].sym)->ifloat;
				  	(yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->ifloat/float((yyvsp[0].sym)->ival);
				      (yyval.sym) = si;
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->ifloat/(yyvsp[0].sym)->ifloat;
				      (yyval.sym) = si;
				}	
			}
			else if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "array"){
				if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      if((yyvsp[-2].sym)->ival%(yyvsp[0].sym)->ival == 0){
					   si->setvarType("int");
					   si->setType("CONST_INT");
					   si->ival = (yyvsp[-2].sym)->ival/(yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
					} 
					else{
					   si->setvarType("float");
					   si->setType("CONST_FLOAT");
					   si->ifloat = (yyvsp[-2].sym)->ival/(yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
					} 
					(yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float((yyvsp[-2].sym)->ival)/(yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
				   (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->ifloat/float((yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex]);
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex]/(yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
				      (yyval.sym) = si;
				      
				}	
			}
			else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "variable"){
				if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      if((yyvsp[-2].sym)->ival%(yyvsp[0].sym)->ival == 0){
					   si->setvarType("int");
					   si->setType("CONST_INT");
					   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex]/(yyvsp[0].sym)->ival;
					} 
					else{
					   si->setvarType("float");
					   si->setType("CONST_FLOAT");
					   si->ifloat = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex]/(yyvsp[0].sym)->ival;
					} 
					(yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float((yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex])/(yyvsp[0].sym)->ifloat;
				  
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex]/float((yyvsp[0].sym)->ival);
				      (yyval.sym) = si;
					logout<<(yyval.sym)->getvarType()<<endl;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex]/(yyvsp[0].sym)->ifloat;
				      (yyval.sym) = si;
				      
				}	
			}
			else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "array"){
				if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      if((yyvsp[-2].sym)->ival%(yyvsp[0].sym)->ival == 0){
					   si->setvarType("int");
					   si->setType("CONST_INT");
					   si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex]/(yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
					} 
					else{
					   si->setvarType("float");
					   si->setType("CONST_FLOAT");
					   si->ifloat = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex]/(yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
					} 
					(yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = float((yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex])/(yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
				  
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "int"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex]/float((yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex]);
				      (yyval.sym) = si;
				      
				}
				else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
				      SymbolInfo *si = new SymbolInfo();
				      si->setvarType("float");
				      si->setType("CONST_FLOAT");
				      si->ifloat = (yyvsp[-2].sym)->floating[(yyvsp[-2].sym)->arrayIndex]/(yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
				      (yyval.sym) = si;
				      
				}	
			}
			
		}
		else if((yyvsp[-1].sym)->getName() == "%"){
			if((yyvsp[-2].sym)->getvarType() == "float" || (yyvsp[0].sym)->getvarType() == "float"){
				      errorout<<"Error at line "<<line_count<<" : invalid operands of types"<<endl<<endl;
				      semanticErrors++;
			}
			SymbolInfo *si = new SymbolInfo();
			si->setvarType("int");
			si->setType("CONST_INT");
		        if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "variable"){
				if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				      si->ival = (yyvsp[-2].sym)->ival%(yyvsp[0].sym)->ival;
				}
			}
			else if((yyvsp[-2].sym)->getidType() == "variable" && (yyvsp[0].sym)->getidType() == "array"){
				if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				      si->ival = (yyvsp[-2].sym)->ival%(yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
				}
			}
			else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "variable"){
				if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				      si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex]%(yyvsp[0].sym)->ival;
				}
			}
			else if((yyvsp[-2].sym)->getidType() == "array" && (yyvsp[0].sym)->getidType() == "array"){
				if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				      si->ival = (yyvsp[-2].sym)->integer[(yyvsp[-2].sym)->arrayIndex]%(yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
				}
			}
			(yyval.sym) = si;
			
			if((yyvsp[-2].sym)->getvarType() == "int" && (yyvsp[0].sym)->getvarType() == "int"){
				(yyval.sym)->setvarType("int");
			}
			else if((yyvsp[-2].sym)->getvarType() == "float" && (yyvsp[0].sym)->getvarType() == "float"){
				(yyval.sym)->setvarType("float");
			}
		      
		}
		
}
#line 3710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 2082 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": unary_expression : ADDOP unary_expression"<<endl<<endl;
		//logout<<$2->getvarType()<<endl;
		una_expr = (yyvsp[-1].sym)->getName()+una_expr;
		logout<<una_expr<<endl;
		SymbolInfo *si = new SymbolInfo();
		si->setidType("variable");
		if((yyvsp[-1].sym)->getName() == "-"){
		   if((yyvsp[0].sym)->getidType() == "variable"){
			if((yyvsp[0].sym)->getvarType() == "int"){
			     si->ival = (-1)*(yyvsp[0].sym)->ival;
			     si->setvarType("int");
			}
			else if((yyvsp[0].sym)->getvarType() == "float"){ 
			     si->ifloat= (-1)*(yyvsp[0].sym)->ifloat;
			     si->setvarType("float");
			}
		   }
		   else if((yyvsp[0].sym)->getidType() == "array"){
			if((yyvsp[0].sym)->getvarType() == "int"){
			     si->ival = (-1)*(yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			     si->setvarType("int");
			}
			else if((yyvsp[0].sym)->getvarType() == "float"){ 
			     si->ifloat= (-1)*(yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			     si->setvarType("float");
			}
		   }
		}
		else if((yyvsp[-1].sym)->getName() == "+"){
		   if((yyvsp[0].sym)->getidType() == "variable"){
			if((yyvsp[0].sym)->getvarType() == "int"){
			     si->ival = (yyvsp[0].sym)->ival;
			     si->setvarType("int");
			}
			else if((yyvsp[0].sym)->getvarType() == "float"){ 
			     si->ifloat= (yyvsp[0].sym)->ifloat;
			     si->setvarType("float");
			}
		   }
		   else if((yyvsp[0].sym)->getidType() == "array"){
			if((yyvsp[0].sym)->getvarType() == "int"){
			     si->ival = (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			     si->setvarType("int");
			}
			else if((yyvsp[0].sym)->getvarType() == "float"){ 
			     si->ifloat= (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			     si->setvarType("float");
			}
		   }
		}
		
		(yyval.sym) = si;
	}
#line 3769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 2136 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": unary_expression : NOT unary_expression "<<endl<<endl;
		una_expr = "!" + una_expr;
		logout<<una_expr<<endl;
		SymbolInfo *si = new SymbolInfo();
		si->setvarType("int");
		if((yyvsp[0].sym)->getidType() == "variable"){
		   if((yyvsp[0].sym)->getvarType() == "int"){
			si->ival = !((yyvsp[0].sym)->ival);
		   }
		   else if((yyvsp[0].sym)->getvarType() == "float"){
			si->ival = !((yyvsp[0].sym)->ifloat);
		   }
		}
		else if((yyvsp[0].sym)->getidType() == "array"){
		   if((yyvsp[0].sym)->getvarType() == "int"){
			si->ival = !((yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex]);
		   }
		   else if((yyvsp[0].sym)->getvarType() == "float"){
			si->ival = !((yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex]);
		   }
		}
		}
#line 3797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 2159 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": unary expression : factor "<<endl<<endl;
		una_expr = fac;
		fac = "\0";
		logout<<una_expr<<endl;
		logout<<(yyvsp[0].sym)->getidType()<<endl;
		if((yyvsp[0].sym)->getidType() == "variable"){
		    (yyval.sym) = (yyvsp[0].sym);
		    if((yyval.sym)->getvarType() == "int"){
			(yyval.sym)->setVal((yyvsp[0].sym)->ival);
			}
			else if((yyval.sym)->getvarType() == "float"){
			//$$->setVal($1->ival);
			(yyval.sym)->setFloat((yyvsp[0].sym)->ifloat);
			}
		}else if((yyvsp[0].sym)->getidType() == "array"){
		    (yyval.sym) = (yyvsp[0].sym);
		    if((yyval.sym)->getvarType() == "int"){
			(yyval.sym)->setVal((yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex]);
			(yyval.sym)->integer[(yyvsp[0].sym)->arrayIndex] = (yyvsp[0].sym)->integer[(yyvsp[0].sym)->arrayIndex];
			}
			else if((yyval.sym)->getvarType() == "float"){
			//$$->setVal($1->ival);
			(yyval.sym)->setFloat((yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex]);
			(yyval.sym)->floating[(yyvsp[0].sym)->arrayIndex] = (yyvsp[0].sym)->floating[(yyvsp[0].sym)->arrayIndex];
			}
		}
		}
#line 3830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 2189 "Parse.y" /* yacc.c:1646  */
    {logout<<"Line "<<line_count<<": factor : variable "<<endl<<endl; (yyval.sym)=(yyvsp[0].sym);
	fac = (yyvsp[0].sym)->getName();
	//fac = VAR;
	logout<<fac<<endl;}
#line 3839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 2193 "Parse.y" /* yacc.c:1646  */
    {
	logout<<"Line "<<line_count<<": factor : ID LPAREN argument_list RPAREN "<<endl<<endl;
	fac = (yyvsp[-3].sym)->getName() + "(" +args+")";
	logout<<fac<<endl;
	int flag = 0;
	SymbolInfo *si = st.lookUp((yyvsp[-3].sym)->getName(),"function");
	//logout<<si->param_list.size()<<endl;
	logout<<args_type.size()<<endl;
	if(si == NULL){
		errorout<<"Error at line "<<line_count<<" "<<(yyvsp[-3].sym)->getName()<<"() function doesn't exist"<<endl<<endl;
		semanticErrors++;
		}
	else{
		  if(args_type.size() != si->param_type.size()){
			errorout<<"Error at line "<<line_count<<" : arguments number mismatch"<<endl<<endl;
			semanticErrors++;
		  }
		  else{
			for(int i = 0; i< args_type.size(); i++){
			   if(si->param_type[i] != args_type[i]){
				flag = 1; 
				break;
			    }else{flag = 0;}
			}
		
		if(flag == 1){
		   errorout<<"Error at line "<<line_count<<" : arguments mismatch"<<endl<<endl;
			semanticErrors++;
		}
		
		args_type.clear();
		(yyval.sym) = si;
		}	 
	}
	
	}
#line 3880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 2229 "Parse.y" /* yacc.c:1646  */
    {logout<<"Line "<<line_count<<": factor : LPAREN expression RPAREN "<<endl<<endl;
		fac = "(" + expr + ")";
		logout<<fac<<endl;
		expr = "\0";}
#line 3889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 2233 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": factor : CONST_INT"<<endl<<endl;
		logout<<(yyvsp[0].sym)->getName()<<endl<<endl;
		(yyvsp[0].sym)->setidType("variable");
		(yyvsp[0].sym)->setvarType("int");
		fac = (yyvsp[0].sym)->getName();
		int i = atoi((yyvsp[0].sym)->getName().c_str());
		(yyvsp[0].sym)->setVal(i);
		(yyval.sym) = (yyvsp[0].sym);
	}
#line 3904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 2243 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": factor : CONST_FLOAT"<<endl<<endl;
		fac = (yyvsp[0].sym)->getName();
		logout<<fac<<endl<<endl;
		(yyvsp[0].sym)->setidType("variable");
		(yyvsp[0].sym)->setvarType("float");
		float i = atof((yyvsp[0].sym)->getName().c_str());
		(yyvsp[0].sym)->ifloat = i; 
		(yyval.sym) = (yyvsp[0].sym);
          }
#line 3919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 2254 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": factor : variable DECOP "<<endl<<endl;
		v_incop = (yyvsp[-1].sym)->getName() + "++";
		fac = fac + v_incop;
		logout<<v_incop<<endl;
		v_incop = "\0";
		SymbolInfo *si = st.lookUp((yyvsp[-1].sym)->getName(),(yyvsp[-1].sym)->getidType());
		if(si != NULL){
			if((yyvsp[-1].sym)->getidType() == "variable"){
				if(si->getvarType() == "int"){
				si->ival = si->ival + 1;
				}
				else if(si->getvarType() == "float"){
				si->ifloat = si->ifloat + 1.0;
				}
			
			}
		else if(si->getidType() == "array"){
			if(si->getvarType() == "int"){
				si->integer[(yyvsp[-1].sym)->arrayIndex] = si->integer[(yyvsp[-1].sym)->arrayIndex] + 1;
			}
			else if(si->getvarType() == "float"){
				si->floating[(yyvsp[-1].sym)->arrayIndex] = si->floating[(yyvsp[-1].sym)->arrayIndex] + 1.0;
			}
			
		}
		(yyval.sym) = si;
	}
	}
#line 3953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 2283 "Parse.y" /* yacc.c:1646  */
    {
		logout<<"Line "<<line_count<<": factor : variable DECOP "<<endl<<endl;
		v_decop = (yyvsp[-1].sym)->getName() + "--";
		fac = fac+v_decop;
		logout<<v_decop<<endl;
		v_decop = "\0";
		SymbolInfo *si = st.lookUp((yyvsp[-1].sym)->getName(),(yyvsp[-1].sym)->getidType());
		if(si != NULL){
			if((yyvsp[-1].sym)->getidType() == "variable"){
				if(si->getvarType() == "int"){
				si->ival = si->ival - 1;
				}
				else if(si->getvarType() == "float"){
				si->ifloat = si->ifloat - 1.0;
				}
			
			}
		else if(si->getidType() == "array"){
			if(si->getvarType() == "int"){
				si->integer[(yyvsp[-1].sym)->arrayIndex] = si->integer[(yyvsp[-1].sym)->arrayIndex] - 1;
			}
			else if(si->getvarType() == "float"){
				si->floating[(yyvsp[-1].sym)->arrayIndex] = si->floating[(yyvsp[-1].sym)->arrayIndex] - 1.0;
			}
			
		}
		(yyval.sym) = si;
	}
	}
#line 3987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 2313 "Parse.y" /* yacc.c:1646  */
    {logout<<"Line "<<line_count<<": argument_list : arguments "<<endl<<endl;
			logout<<args<<endl;}
#line 3994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 2318 "Parse.y" /* yacc.c:1646  */
    {logout<<"Line "<<line_count<<": arguments COMMA logic_expression "<<endl<<endl;
			args = args + "," + logic_expr;
			logout<<args<<endl;
			args_type.push_back((yyvsp[0].sym)->getvarType());
		}
#line 4004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 2324 "Parse.y" /* yacc.c:1646  */
    {logout<<"Line "<<line_count<<": logic_expression "<<endl<<endl;
		args = logic_expr;
		logout<<args<<endl;
		args_type.push_back((yyvsp[0].sym)->getvarType());
		}
#line 4014 "y.tab.c" /* yacc.c:1646  */
    break;


#line 4018 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 2332 "Parse.y" /* yacc.c:1906  */


int main(int argc,char *argv[]){
	
	if((yyin=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	logout.open("1505094_log.txt");
	errorout.open("1505094_errors.txt");
	
	
	yyparse();
	st.printAll(logout);
	logout << "Total Lines : " << line_count-1 << endl << endl; 
	logout << "Total Errors : " << semanticErrors << endl;
	errorout << "Total Errors : " << semanticErrors << endl;
	logout.close();
	errorout.close();

	return 0;
}
