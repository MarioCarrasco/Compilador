/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "compilador.y"

#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include "tabla_simbolos.h"
#include "ast.c"

extern yylineno;
void yyerror(const char *s);

simbolo tabla_simbolos[100];
int num_simbolos = 0;


/* Line 189 of yacc.c  */
#line 87 "compilador.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VARIABLE = 258,
     ENTERO = 259,
     DECIMAL = 260,
     COMENTARIO = 261,
     COMENTARIOL = 262,
     SI = 263,
     OSI = 264,
     SINO = 265,
     FIN = 266,
     MIENTRAS = 267,
     IMPRIMIR = 268,
     MAYORIGUAL = 269,
     MENORIGUAL = 270,
     DIFERENTE = 271,
     MAYOR = 272,
     MENOR = 273,
     IGUALIGUAL = 274
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 15 "compilador.y"

   int vInt;
   char* sVal;
   float fVal;
      struct valores{
         char* nombre;
         int valInt;
         float valFloat;
         char* valStr;
         char* tipo;
         struct ASTNode* nodo;
      } valores;



/* Line 214 of yacc.c  */
#line 158 "compilador.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 170 "compilador.tab.c"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  34
/* YYNRULES -- Number of states.  */
#define YYNSTATES  70

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   274

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      20,    21,    25,    22,     2,    23,     2,    26,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    24,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    27,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    20,
      22,    24,    26,    30,    34,    38,    42,    46,    48,    50,
      52,    54,    58,    62,    66,    70,    74,    78,    85,    94,
     102,   104,   107,   113,   120
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      29,     0,    -1,    30,    -1,    31,    -1,    30,    31,    -1,
      32,    -1,     6,    -1,     7,    -1,     3,    24,    32,    -1,
       4,    -1,     5,    -1,     3,    -1,    32,    22,    32,    -1,
      32,    23,    32,    -1,    32,    25,    32,    -1,    32,    26,
      32,    -1,    32,    27,    32,    -1,    33,    -1,    34,    -1,
      37,    -1,    38,    -1,    32,    17,    32,    -1,    32,    18,
      32,    -1,    32,    19,    32,    -1,    32,    16,    32,    -1,
      32,    15,    32,    -1,    32,    14,    32,    -1,     8,    20,
      33,    21,    30,    11,    -1,     8,    20,    33,    21,    30,
      10,    30,    11,    -1,     8,    20,    33,    21,    30,    35,
      11,    -1,    36,    -1,    35,    36,    -1,     9,    20,    33,
      21,    30,    -1,    12,    20,    33,    21,    30,    11,    -1,
      13,    20,    30,    21,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    53,    53,    56,    57,    60,    61,    62,    63,   131,
     135,   136,   164,   203,   239,   275,   320,   357,   358,   359,
     360,   363,   374,   385,   396,   407,   418,   431,   432,   433,
     435,   436,   438,   441,   444
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VARIABLE", "ENTERO", "DECIMAL",
  "COMENTARIO", "COMENTARIOL", "SI", "OSI", "SINO", "FIN", "MIENTRAS",
  "IMPRIMIR", "MAYORIGUAL", "MENORIGUAL", "DIFERENTE", "MAYOR", "MENOR",
  "IGUALIGUAL", "'('", "')'", "'+'", "'-'", "'='", "'*'", "'/'", "'^'",
  "$accept", "S", "sentencia", "sentencias", "expresion", "expr_booleanas",
  "sentencia_si", "osis", "osi", "bucle_while", "imprimir", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      40,    41,    43,    45,    61,    42,    47,    94
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    28,    29,    30,    30,    31,    31,    31,    31,    32,
      32,    32,    32,    32,    32,    32,    32,    32,    32,    32,
      32,    33,    33,    33,    33,    33,    33,    34,    34,    34,
      35,    35,    36,    37,    38
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     3,     1,
       1,     1,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     6,     8,     7,
       1,     2,     5,     6,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    11,     9,    10,     6,     7,     0,     0,     0,     0,
       2,     3,     5,    17,    18,    19,    20,     0,     0,     0,
       0,     1,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     8,     0,    17,    17,     0,
      26,    25,    24,    21,    22,    23,    12,    13,    14,    15,
      16,     0,     0,    34,     0,     0,     0,     0,    27,     0,
      30,    33,     0,     0,    29,    31,    17,    28,     0,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    13,    14,    59,    60,    15,
      16
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -20
static const yytype_int8 yypact[] =
{
     104,    -5,   -20,   -20,   -20,   -20,     0,     7,     8,     5,
     104,   -20,    46,   -20,   -20,   -20,   -20,   110,   110,   110,
     104,   -20,   -20,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   -20,    46,    46,    16,    20,    18,
      29,    29,    29,    29,    29,    29,     9,     9,    19,    19,
      19,   104,   104,   -20,    71,    82,    23,   104,   -20,    31,
     -20,   -20,   110,    93,   -20,   -20,    27,   -20,   104,   104
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -20,   -20,   -19,   -10,   -15,   -12,   -20,   -20,    -2,   -20,
     -20
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      22,    39,    35,    36,    36,    21,    37,    38,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    17,
      18,     1,     2,     3,     4,     5,     6,    19,    20,    22,
       7,     8,    54,    55,    31,    32,    33,    51,    63,    53,
      56,    52,    64,    62,    22,    22,    33,    36,    68,    69,
      66,    29,    30,    22,    31,    32,    33,    65,     0,    22,
      23,    24,    25,    26,    27,    28,     0,     0,    29,    30,
       0,    31,    32,    33,     1,     2,     3,     4,     5,     6,
      56,    57,    58,     7,     8,     1,     2,     3,     4,     5,
       6,     0,     0,    61,     7,     8,     1,     2,     3,     4,
       5,     6,     0,     0,    67,     7,     8,     1,     2,     3,
       4,     5,     6,    34,     2,     3,     7,     8,     6,     0,
       0,     0,     7,     8
};

static const yytype_int8 yycheck[] =
{
      10,    20,    17,    18,    19,     0,    18,    19,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    24,
      20,     3,     4,     5,     6,     7,     8,    20,    20,    39,
      12,    13,    51,    52,    25,    26,    27,    21,    57,    21,
       9,    21,    11,    20,    54,    55,    27,    62,    21,    68,
      62,    22,    23,    63,    25,    26,    27,    59,    -1,    69,
      14,    15,    16,    17,    18,    19,    -1,    -1,    22,    23,
      -1,    25,    26,    27,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,     3,     4,     5,     6,     7,
       8,    -1,    -1,    11,    12,    13,     3,     4,     5,     6,
       7,     8,    -1,    -1,    11,    12,    13,     3,     4,     5,
       6,     7,     8,     3,     4,     5,    12,    13,     8,    -1,
      -1,    -1,    12,    13
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    12,    13,    29,
      30,    31,    32,    33,    34,    37,    38,    24,    20,    20,
      20,     0,    31,    14,    15,    16,    17,    18,    19,    22,
      23,    25,    26,    27,     3,    32,    32,    33,    33,    30,
      32,    32,    32,    32,    32,    32,    32,    32,    32,    32,
      32,    21,    21,    21,    30,    30,     9,    10,    11,    35,
      36,    11,    20,    30,    11,    36,    33,    11,    21,    30
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1464 of yacc.c  */
#line 53 "compilador.y"
    { iniciarGCI((yyvsp[(1) - (1)].valores).nodo);/*llamar al método generarCodigoIntermedio()*/;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 56 "compilador.y"
    { (yyval.valores).nodo = (yyvsp[(1) - (1)].valores).nodo; ;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 57 "compilador.y"
    { (yyval.valores).nodo = createASTNode("SS", -1, -1, (yyvsp[(1) - (2)].valores).nodo, (yyvsp[(2) - (2)].valores).nodo); ;}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 60 "compilador.y"
    { (yyval.valores).nodo = (yyvsp[(1) - (1)].valores).nodo; ;}
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 61 "compilador.y"
    { /*No se hace nada con los comentarios, se obvian*/ ;}
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 62 "compilador.y"
    { /*No se hace nada con los comentarios, se obvian*/ ;}
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 63 "compilador.y"
    {  
            printf("Tipo de la expresion: %s \n", (yyvsp[(3) - (3)].valores).tipo);
            char* nuevoTipo = "";
            if (strcmp((yyvsp[(3) - (3)].valores).tipo, "entero") == 0){
               nuevoTipo = "entero";
               if(existe_simbolo((yyvsp[(1) - (3)].sVal),tabla_simbolos,num_simbolos)==0){ // no exixte simbolo, se crea
                  printf("Nuevo simbolo\n"); 
                  tabla_simbolos[num_simbolos].nombre = (yyvsp[(1) - (3)].sVal);
                  tabla_simbolos[num_simbolos].tipo = nuevoTipo;
                  tabla_simbolos[num_simbolos].valor = (yyvsp[(3) - (3)].valores).valInt;
                  printf("Nombre del nuevo simbolo: %s\n", tabla_simbolos[num_simbolos].nombre);
                  printf("Tipo del nuevo simbolo: %s\n", tabla_simbolos[num_simbolos].tipo);
                  printf("Valor del nuevo simbolo: %d\n", tabla_simbolos[num_simbolos].valor);
                  num_simbolos++;

                  struct ASTNode* temp = createASTNode("variable", -1, -1, NULL, NULL);
                  (yyval.valores).nodo = createASTNodeRegistro("declaracion", -1, -1, temp, (yyvsp[(3) - (3)].valores).nodo);
               }
               else{ // exixte simbolo, se actualiza
                  printf("Actualizamos simbolo\n"); 
                  for (int i = 0; i < num_simbolos; i++) {
                     if (strcmp(tabla_simbolos[i].nombre, (yyvsp[(1) - (3)].sVal)) == 0) {
                        tabla_simbolos[i].nombre = (yyvsp[(1) - (3)].sVal);
                        tabla_simbolos[i].tipo = nuevoTipo;
                        tabla_simbolos[i].valor = (yyvsp[(3) - (3)].valores).valInt;
                        printf("Nombre del simbolo actualizado: %s\n", tabla_simbolos[i].nombre);
                        printf("Tipo del simbolo actualizado: %s\n", tabla_simbolos[i].tipo);
                        printf("Valor del simbolo actualizado: %d\n", tabla_simbolos[i].valor);
                     }
                  }
                  struct ASTNode* temp = createASTNodeRegistro("variable", -1, -1, NULL, NULL);
                  (yyval.valores).nodo = createASTNodeRegistro("asignacion", -1, -1, temp, (yyvsp[(3) - (3)].valores).nodo);
               }
            }
            else if (strcmp((yyvsp[(3) - (3)].valores).tipo, "decimal") == 0){
               nuevoTipo = "decimal";
               if(existe_simbolo((yyvsp[(1) - (3)].sVal),tabla_simbolos,num_simbolos)==0){ // no exixte simbolo, se crea
                  printf("Nuevo simbolo\n"); 
                  tabla_simbolos[num_simbolos].nombre = (yyvsp[(1) - (3)].sVal);
                  tabla_simbolos[num_simbolos].tipo = nuevoTipo;
                  tabla_simbolos[num_simbolos].valorFloat = (yyvsp[(3) - (3)].valores).valFloat;
                  printf("Nombre del nuevo simbolo: %s\n", tabla_simbolos[num_simbolos].nombre);
                  printf("Tipo del nuevo simbolo: %s\n", tabla_simbolos[num_simbolos].tipo);
                  printf("Valor del nuevo simbolo: %d\n", tabla_simbolos[num_simbolos].valorFloat);
                  num_simbolos++;

                  struct ASTNode* temp = createASTNode("variable", -1, -1, NULL, NULL);
                  (yyval.valores).nodo = createASTNodeRegistro("declaracion", -1, -1, temp, (yyvsp[(3) - (3)].valores).nodo);
               }
               else{ // exixte simbolo, se actualiza
                  printf("Actualizamos simbolo\n"); 
                  for (int i = 0; i < num_simbolos; i++) {
                     if (strcmp(tabla_simbolos[i].nombre, (yyvsp[(1) - (3)].sVal)) == 0) {
                        tabla_simbolos[i].nombre = (yyvsp[(1) - (3)].sVal);
                        tabla_simbolos[i].tipo = nuevoTipo;
                        tabla_simbolos[i].valorFloat = (yyvsp[(3) - (3)].valores).valFloat;
                        printf("Nombre del simbolo actualizado: %s\n", tabla_simbolos[i].nombre);
                        printf("Tipo del simbolo actualizado: %s\n", tabla_simbolos[i].tipo);
                        printf("Valor del simbolo actualizado: %f\n", tabla_simbolos[i].valorFloat);
                     }
                  }
                  struct ASTNode* temp = createASTNodeRegistro("variable", -1, -1, NULL, NULL);
                  (yyval.valores).nodo = createASTNodeRegistro("asignacion", -1, -1, temp, (yyvsp[(3) - (3)].valores).nodo);
               }
            }
         ;}
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 131 "compilador.y"
    { (yyval.valores).valInt = (yyvsp[(1) - (1)].vInt); 
                  (yyval.valores).valFloat = (float)(yyvsp[(1) - (1)].vInt);
                  (yyval.valores).nodo = createASTNodeRegistroDeclarar("entero", (yyvsp[(1) - (1)].vInt), (float)(yyvsp[(1) - (1)].vInt), NULL, NULL); (yyval.valores).tipo = "entero"; 
                  ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 135 "compilador.y"
    { (yyval.valores).valFloat = (yyvsp[(1) - (1)].fVal); (yyval.valores).nodo = createASTNodeRegistroDeclarar("decimal", -1, (yyvsp[(1) - (1)].fVal), NULL, NULL); (yyval.valores).tipo = "decimal"; ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 136 "compilador.y"
    { printf("entra en variable\n"); 
            if(existe_simbolo((yyvsp[(1) - (1)].sVal), tabla_simbolos, num_simbolos)==1){
               int temp2;
               float temp3;
               if (buscar_tipo((yyvsp[(1) - (1)].sVal), tabla_simbolos, num_simbolos)=="entero"){
                  temp2 = buscar_simbolo((yyvsp[(1) - (1)].sVal),tabla_simbolos,num_simbolos);// solo funciona para valores enteros
                  (yyval.valores).valInt = temp2;
                  (yyval.valores).tipo = "entero";
                  printf("Nuevo valor: %d\n", temp2);
                  (yyval.valores).nodo = createASTNodeRegistroDeclarar("variable", temp2, (float)temp2, NULL, NULL);
               }
               else if (buscar_tipo((yyvsp[(1) - (1)].sVal), tabla_simbolos, num_simbolos)=="decimal"){
                  temp3 = buscar_simboloFloat((yyvsp[(1) - (1)].sVal),tabla_simbolos,num_simbolos);// solo funciona para valores enteros
                  (yyval.valores).valFloat = temp3;
                  (yyval.valores).tipo = "decimal";
                  printf("Nuevo valor: %f\n", temp3);
                  (yyval.valores).nodo = createASTNodeRegistroDeclarar("variable", -1, temp3, NULL, NULL);
               }
               else{
                  printf("Error en linea %d: Tipo de la variable %s no observado\n",(yylineno-1)-1, (yyvsp[(1) - (1)].sVal));
                  exit(1);
               }
            }
            else{
               printf("Error en linea %d: variable '%s' no declarada\n",(yylineno-1), (yyvsp[(1) - (1)].sVal));// cazar error de variable no declarada
               exit(1);
            }
         ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 164 "compilador.y"
    {
               if (strcmp((yyvsp[(1) - (3)].valores).tipo, (yyvsp[(3) - (3)].valores).tipo) == 0){ // si los tipos son el mismo
                  if (strcmp((yyvsp[(1) - (3)].valores).tipo, "entero") == 0){
                     printf("En la linea %d entra en la suma de enteros: %d + %d\n", (yylineno-1), (yyvsp[(1) - (3)].valores).valInt, (yyvsp[(3) - (3)].valores).valInt);
                     (yyval.valores).valFloat = (yyvsp[(1) - (3)].valores).valInt + (yyvsp[(3) - (3)].valores).valInt;
                     (yyval.valores).valInt = (yyvsp[(1) - (3)].valores).valInt + (yyvsp[(3) - (3)].valores).valInt;
                  }
                  else if (strcmp((yyvsp[(1) - (3)].valores).tipo, "decimal") == 0){
                     printf("En la linea %d entra en la suma de decimales: %f + %f\n", (yylineno-1), (yyvsp[(1) - (3)].valores).valFloat, (yyvsp[(3) - (3)].valores).valFloat);
                     (yyval.valores).valFloat = (yyvsp[(1) - (3)].valores).valFloat + (yyvsp[(3) - (3)].valores).valFloat;
                  }
                  /*else if (strcmp($1.tipo, "string") == 0){
                     printf("En la linea %d entra en la concatenacion: %s + %s\n", (yylineno-1), $1.valStr, $3.valStr);
                  }*/
                  else{
                     printf("Error en linea %d: Error de tipos\n",(yylineno-1));
                     exit(1);
                  }
               }
               else {
                  if (strcmp((yyvsp[(1) - (3)].valores).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].valores).tipo, "string") == 0){
                     printf("Error en linea %d: No se pueden operar numeros con strings\n",(yylineno-1));
                     exit(1);
                  }
                  else if (strcmp((yyvsp[(1) - (3)].valores).tipo, "entero") == 0 && strcmp((yyvsp[(3) - (3)].valores).tipo, "decimal") == 0){
                     printf("En la linea %d entra en la suma: %d + %f\n", (yylineno-1), (yyvsp[(1) - (3)].valores).valInt, (yyvsp[(3) - (3)].valores).valFloat);
                     (yyval.valores).valFloat = (yyvsp[(1) - (3)].valores).valInt + (yyvsp[(3) - (3)].valores).valFloat;
                  }
                  else if (strcmp((yyvsp[(1) - (3)].valores).tipo, "decimal") == 0 && strcmp((yyvsp[(3) - (3)].valores).tipo, "entero") == 0){
                     printf("En la linea %d entra en la suma: %f + %d\n", (yylineno-1), (yyvsp[(1) - (3)].valores).valFloat, (yyvsp[(3) - (3)].valores).valInt);
                     (yyval.valores).valFloat = (yyvsp[(1) - (3)].valores).valFloat + (yyvsp[(3) - (3)].valores).valInt;
                  }
                  else{
                     printf("Error en linea %d: Error de tipos\n",(yylineno-1));
                     exit(1);
                  }
               }
               (yyval.valores).nodo = createASTNodeRegistro("suma", -1, -1, (yyvsp[(1) - (3)].valores).nodo, (yyvsp[(3) - (3)].valores).nodo); 
            ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 203 "compilador.y"
    { 
               if (strcmp((yyvsp[(1) - (3)].valores).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].valores).tipo, "string") == 0){
                     printf("Error en linea %d: No se puede realizar la operación 'resta' con un string\n", (yylineno-1));
                     exit(1);
               }
               if (strcmp((yyvsp[(1) - (3)].valores).tipo, (yyvsp[(3) - (3)].valores).tipo) == 0){ // si los tipos son el mismo
                  if (strcmp((yyvsp[(1) - (3)].valores).tipo, "entero") == 0){
                     printf("En la linea %d entra en la resta de enteros: %d - %d\n", (yylineno-1), (yyvsp[(1) - (3)].valores).valInt, (yyvsp[(3) - (3)].valores).valInt);
                     (yyval.valores).valFloat = (yyvsp[(1) - (3)].valores).valInt - (yyvsp[(3) - (3)].valores).valInt;
                     (yyval.valores).valInt = (yyvsp[(1) - (3)].valores).valInt - (yyvsp[(3) - (3)].valores).valInt;
                  }
                  else if (strcmp((yyvsp[(1) - (3)].valores).tipo, "decimal") == 0){
                     printf("En la linea %d entra en la resta de decimales: %f - %f\n", (yylineno-1), (yyvsp[(1) - (3)].valores).valFloat, (yyvsp[(3) - (3)].valores).valFloat);
                     (yyval.valores).valFloat = (yyvsp[(1) - (3)].valores).valFloat - (yyvsp[(3) - (3)].valores).valFloat;
                  }
                  else{
                     printf("Error en linea %d: Error de tipos\n",(yylineno-1));
                     exit(1);
                  }
               }
               else {
                  if (strcmp((yyvsp[(1) - (3)].valores).tipo, "entero") == 0 && strcmp((yyvsp[(3) - (3)].valores).tipo, "decimal") == 0){
                     printf("En la linea %d entra en la resta: %d - %f\n", (yylineno-1), (yyvsp[(1) - (3)].valores).valInt, (yyvsp[(3) - (3)].valores).valFloat);
                     (yyval.valores).valFloat = (yyvsp[(1) - (3)].valores).valInt - (yyvsp[(3) - (3)].valores).valFloat;
                  }
                  else if (strcmp((yyvsp[(1) - (3)].valores).tipo, "decimal") == 0 && strcmp((yyvsp[(3) - (3)].valores).tipo, "entero") == 0){
                     printf("En la linea %d entra en la resta: %f - %d\n", (yylineno-1), (yyvsp[(1) - (3)].valores).valFloat, (yyvsp[(3) - (3)].valores).valInt);
                     (yyval.valores).valFloat = (yyvsp[(1) - (3)].valores).valFloat - (yyvsp[(3) - (3)].valores).valInt;
                  }
                  else{
                     printf("Error en linea %s: Error de tipos\n",(yylineno-1));
                     exit(1);
                  }
               }
               (yyval.valores).nodo = createASTNodeRegistro("resta", -1, -1, (yyvsp[(1) - (3)].valores).nodo, (yyvsp[(3) - (3)].valores).nodo);
            ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 239 "compilador.y"
    { 
               if (strcmp((yyvsp[(1) - (3)].valores).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].valores).tipo, "string") == 0){
                     printf("Error en linea %s: No se puede realizar la operación 'multiplicacion' con un string\n", (yylineno-1));
                     exit(1);
               }
               else if (strcmp((yyvsp[(1) - (3)].valores).tipo, (yyvsp[(3) - (3)].valores).tipo) == 0){ // si los tipos son el mismo
                  if (strcmp((yyvsp[(1) - (3)].valores).tipo, "entero") == 0){
                     printf("En la linea %d entra en la multiplicacion de enteros: %d * %d\n", (yylineno-1), (yyvsp[(1) - (3)].valores).valInt, (yyvsp[(3) - (3)].valores).valInt);
                     (yyval.valores).valFloat = (yyvsp[(1) - (3)].valores).valInt * (yyvsp[(3) - (3)].valores).valInt;
                     (yyval.valores).valInt = (yyvsp[(1) - (3)].valores).valInt * (yyvsp[(3) - (3)].valores).valInt;
                  }
                  else if (strcmp((yyvsp[(1) - (3)].valores).tipo, "decimal") == 0){
                     printf("En la linea %d entra en la multiplicacion de decimales: %f * %f\n", (yylineno-1), (yyvsp[(1) - (3)].valores).valFloat, (yyvsp[(3) - (3)].valores).valFloat);
                     (yyval.valores).valFloat = (yyvsp[(1) - (3)].valores).valFloat * (yyvsp[(3) - (3)].valores).valFloat;
                  }
                  else{
                     printf("Error en linea %s: Error de tipos\n",(yylineno-1));
                     exit(1);
                  }
               }
               else {
                  if (strcmp((yyvsp[(1) - (3)].valores).tipo, "entero") == 0 && strcmp((yyvsp[(3) - (3)].valores).tipo, "decimal") == 0){
                     printf("En la linea %d entra en la multiplicacion: %d * %f\n", (yylineno-1), (yyvsp[(1) - (3)].valores).valInt, (yyvsp[(3) - (3)].valores).valFloat);
                     (yyval.valores).valFloat = (yyvsp[(1) - (3)].valores).valInt * (yyvsp[(3) - (3)].valores).valFloat;
                  }
                  else if (strcmp((yyvsp[(1) - (3)].valores).tipo, "decimal") == 0 && strcmp((yyvsp[(3) - (3)].valores).tipo, "entero") == 0){
                     printf("En la linea %d entra en la multiplicacion: %f * %d\n", (yylineno-1), (yyvsp[(1) - (3)].valores).valFloat, (yyvsp[(3) - (3)].valores).valInt);
                     (yyval.valores).valFloat = (yyvsp[(1) - (3)].valores).valFloat * (yyvsp[(3) - (3)].valores).valInt;
                  }
                  else{
                     printf("Error en linea %s: Error de tipos\n",(yylineno-1));
                     exit(1);
                  }
               }
               (yyval.valores).nodo = createASTNodeRegistro("multiplicacion", -1, -1, (yyvsp[(1) - (3)].valores).nodo, (yyvsp[(3) - (3)].valores).nodo);
            ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 275 "compilador.y"
    { 
               if (strcmp((yyvsp[(1) - (3)].valores).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].valores).tipo, "string") == 0){
                     printf("Error en linea %s: No se puede realizar la operación 'division' con un string\n", (yylineno-1));
                     exit(1);
               }
               // control semantico sobre las divisiones entre 0
               else if (strcmp((yyvsp[(3) - (3)].valores).tipo, "entero") == 0 && (yyvsp[(3) - (3)].valores).valInt == 0){
                  printf("Error en linea %d: No se puede dividir entre 0\n",(yylineno-1));
                  exit(1);
               }
               else if (strcmp((yyvsp[(3) - (3)].valores).tipo, "decimal") == 0 && (yyvsp[(3) - (3)].valores).valFloat == 0){
                  printf("Error en linea %d: No se puede dividir entre 0\n",(yylineno-1));
                  exit(1);
               }
               else if (strcmp((yyvsp[(1) - (3)].valores).tipo, (yyvsp[(3) - (3)].valores).tipo) == 0){ // si los tipos son el mismo
                  if (strcmp((yyvsp[(1) - (3)].valores).tipo, "entero") == 0){
                     printf("En la linea %d entra en la division de enteros: %d / %d\n", (yylineno-1), (yyvsp[(1) - (3)].valores).valInt, (yyvsp[(3) - (3)].valores).valInt);
                     (yyval.valores).valFloat = (yyvsp[(1) - (3)].valores).valInt / (yyvsp[(3) - (3)].valores).valInt;
                     (yyval.valores).valInt = (yyvsp[(1) - (3)].valores).valInt / (yyvsp[(3) - (3)].valores).valInt;
                  }
                  else if (strcmp((yyvsp[(1) - (3)].valores).tipo, "decimal") == 0){
                     printf("En la linea %d entra en la division de decimales: %f / %f\n", (yylineno-1), (yyvsp[(1) - (3)].valores).valFloat, (yyvsp[(3) - (3)].valores).valFloat);
                     (yyval.valores).valFloat = (yyvsp[(1) - (3)].valores).valFloat / (yyvsp[(3) - (3)].valores).valFloat;
                  }
                  else{
                     printf("Error en linea %d: Error de tipos\n",(yylineno-1));
                     exit(1);
                  }
               }
               else {
                  if (strcmp((yyvsp[(1) - (3)].valores).tipo, "entero") == 0 && strcmp((yyvsp[(3) - (3)].valores).tipo, "decimal") == 0){
                     printf("En la linea %d entra en la division: %d / %f\n", (yylineno-1), (yyvsp[(1) - (3)].valores).valInt, (yyvsp[(3) - (3)].valores).valFloat);
                     (yyval.valores).valFloat = (yyvsp[(1) - (3)].valores).valInt / (yyvsp[(3) - (3)].valores).valFloat;
                  }
                  else if (strcmp((yyvsp[(1) - (3)].valores).tipo, "decimal") == 0 && strcmp((yyvsp[(3) - (3)].valores).tipo, "entero") == 0){
                     printf("En la linea %d entra en la division: %f / %d\n", (yylineno-1), (yyvsp[(1) - (3)].valores).valFloat, (yyvsp[(3) - (3)].valores).valInt);
                     (yyval.valores).valFloat = (yyvsp[(1) - (3)].valores).valFloat / (yyvsp[(3) - (3)].valores).valInt;
                  }
                  else{
                     printf("Error en linea %s: Error de tipos\n",(yylineno-1));
                     exit(1);
                  }
               }
               (yyval.valores).nodo = createASTNodeRegistro("division", -1, -1, (yyvsp[(1) - (3)].valores).nodo, (yyvsp[(3) - (3)].valores).nodo);
            ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 320 "compilador.y"
    { 
               if (strcmp((yyvsp[(1) - (3)].valores).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].valores).tipo, "string") == 0){
                     printf("Error en linea %s: No se puede realizar la operación 'potencia' con un string\n", (yylineno-1));
                     exit(1);
               }
               else if (strcmp((yyvsp[(1) - (3)].valores).tipo, (yyvsp[(3) - (3)].valores).tipo) == 0){ // si los tipos son el mismo
                  if (strcmp((yyvsp[(1) - (3)].valores).tipo, "entero") == 0){
                     printf("En la linea %d entra en la potencia de enteros: %d ^ %d\n", (yylineno-1), (yyvsp[(1) - (3)].valores).valInt, (yyvsp[(3) - (3)].valores).valInt);
                     (yyval.valores).valFloat = pow((yyvsp[(1) - (3)].valores).valInt, (yyvsp[(3) - (3)].valores).valInt);
                     (yyval.valores).valInt = pow((yyvsp[(1) - (3)].valores).valInt, (yyvsp[(3) - (3)].valores).valInt);
                  }
                  else if (strcmp((yyvsp[(1) - (3)].valores).tipo, "decimal") == 0){
                     printf("En la linea %d entra en la potencia de decimales: %f ^ %f\n", (yylineno-1), (yyvsp[(1) - (3)].valores).valFloat, (yyvsp[(3) - (3)].valores).valFloat);
                     (yyval.valores).valFloat = pow((yyvsp[(1) - (3)].valores).valFloat, (yyvsp[(3) - (3)].valores).valFloat);
                  }
                  else{
                     printf("Error en linea %s: Error de tipos\n",(yylineno-1));
                     exit(1);
                  }
               }
               else {
                  if (strcmp((yyvsp[(1) - (3)].valores).tipo, "entero") == 0 && strcmp((yyvsp[(3) - (3)].valores).tipo, "decimal") == 0){
                     printf("En la linea %d entra en la potencia: %d ^ %f\n", (yylineno-1), (yyvsp[(1) - (3)].valores).valInt, (yyvsp[(3) - (3)].valores).valFloat);
                     (yyval.valores).valFloat = pow((yyvsp[(1) - (3)].valores).valInt, (yyvsp[(3) - (3)].valores).valFloat);
                  }
                  else if (strcmp((yyvsp[(1) - (3)].valores).tipo, "decimal") == 0 && strcmp((yyvsp[(3) - (3)].valores).tipo, "entero") == 0){
                     printf("En la linea %d entra en la potencia: %f ^ %d\n", (yylineno-1), (yyvsp[(1) - (3)].valores).valFloat, (yyvsp[(3) - (3)].valores).valInt);
                     (yyval.valores).valFloat = pow((yyvsp[(1) - (3)].valores).valFloat, (yyvsp[(3) - (3)].valores).valInt);
                  }
                  else{
                     printf("Error en linea %s: Error de tipos\n",(yylineno-1));
                     exit(1);
                  }
               }
               (yyval.valores).nodo = createASTNodeRegistro("potencia", -1, -1, (yyvsp[(1) - (3)].valores).nodo, (yyvsp[(3) - (3)].valores).nodo);
            ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 357 "compilador.y"
    { (yyval.valores).nodo = (yyvsp[(1) - (1)].valores).nodo; ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 358 "compilador.y"
    { (yyval.valores).nodo = (yyvsp[(1) - (1)].valores).nodo; ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 359 "compilador.y"
    { (yyval.valores).nodo = (yyvsp[(1) - (1)].valores).nodo; ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 360 "compilador.y"
    { (yyval.valores).nodo = (yyvsp[(1) - (1)].valores).nodo; ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 363 "compilador.y"
    {
            if (strcmp((yyvsp[(1) - (3)].valores).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].valores).tipo, "string") == 0){
               printf("Error en linea %d: No se pueden hacer operaciones racionales con tipos string\n",(yylineno-1));
               exit(1);
            }
            else{
               (yyval.valores).tipo = "bool";
               (yyval.valores).nodo = createASTNodeRegistro("mayor", -1, -1, (yyvsp[(1) - (3)].valores).nodo, (yyvsp[(3) - (3)].valores).nodo);
               (yyval.valores).valFloat = (yyvsp[(1) - (3)].valores).nodo > (yyvsp[(3) - (3)].valores).nodo;
            }
         ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 374 "compilador.y"
    {
               if (strcmp((yyvsp[(1) - (3)].valores).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].valores).tipo, "string") == 0){
               printf("Error en linea %d: No se pueden hacer operaciones racionales con tipos string\n",(yylineno-1));
               exit(1);
            }
            else{
               (yyval.valores).tipo = "bool";
               (yyval.valores).nodo = createASTNodeRegistro("menor", -1, -1, (yyvsp[(1) - (3)].valores).nodo, (yyvsp[(3) - (3)].valores).nodo);
               (yyval.valores).valFloat = (yyvsp[(1) - (3)].valores).nodo < (yyvsp[(3) - (3)].valores).nodo;
            }
         ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 385 "compilador.y"
    {
            if (strcmp((yyvsp[(1) - (3)].valores).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].valores).tipo, "string") == 0){
               printf("Error en linea %d: No se pueden hacer operaciones racionales con tipos string\n",(yylineno-1));
               exit(1);
            }
            else{
               (yyval.valores).tipo = "bool";
               (yyval.valores).nodo = createASTNodeRegistro("igualigual", -1, -1, (yyvsp[(1) - (3)].valores).nodo, (yyvsp[(3) - (3)].valores).nodo);
               (yyval.valores).valFloat = (yyvsp[(1) - (3)].valores).nodo == (yyvsp[(3) - (3)].valores).nodo;
            }         
         ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 396 "compilador.y"
    {
            if (strcmp((yyvsp[(1) - (3)].valores).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].valores).tipo, "string") == 0){
               printf("Error en linea %d: No se pueden hacer operaciones racionales con tipos string\n",(yylineno-1));
               exit(1);
            }
            else{
               (yyval.valores).tipo = "bool";
               (yyval.valores).nodo = createASTNodeRegistro("diferente", -1, -1, (yyvsp[(1) - (3)].valores).nodo, (yyvsp[(3) - (3)].valores).nodo);
               (yyval.valores).valFloat = (yyvsp[(1) - (3)].valores).nodo != (yyvsp[(3) - (3)].valores).nodo;
            }
         ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 407 "compilador.y"
    {
            if (strcmp((yyvsp[(1) - (3)].valores).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].valores).tipo, "string") == 0){
               printf("Error en linea %d: No se pueden hacer operaciones racionales con tipos string\n",(yylineno-1));
               exit(1);
            }
            else{
               (yyval.valores).tipo = "bool";
               (yyval.valores).nodo = createASTNodeRegistro("menorigual", -1, -1, (yyvsp[(1) - (3)].valores).nodo, (yyvsp[(3) - (3)].valores).nodo);
               (yyval.valores).valFloat = (yyvsp[(1) - (3)].valores).nodo <= (yyvsp[(3) - (3)].valores).nodo;
            }         
         ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 418 "compilador.y"
    {
            if (strcmp((yyvsp[(1) - (3)].valores).tipo, "string") == 0 || strcmp((yyvsp[(3) - (3)].valores).tipo, "string") == 0){
               printf("Error en linea %d: No se pueden hacer operaciones racionales con tipos string\n",(yylineno-1));
               exit(1);
            }
            else{
               (yyval.valores).tipo = "bool";
               (yyval.valores).nodo = createASTNodeRegistro("mayorigual", -1, -1, (yyvsp[(1) - (3)].valores).nodo, (yyvsp[(3) - (3)].valores).nodo);
               (yyval.valores).valFloat = (yyvsp[(1) - (3)].valores).nodo >= (yyvsp[(3) - (3)].valores).nodo;
            }
         ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 431 "compilador.y"
    { (yyval.valores).nodo = createASTNode("si", -1, -1, (yyvsp[(3) - (6)].valores).nodo, (yyvsp[(5) - (6)].valores).nodo); ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 432 "compilador.y"
    { (yyval.valores).nodo = createASTNodeSino("sino", -1, -1, (yyvsp[(3) - (8)].valores).nodo, (yyvsp[(5) - (8)].valores).nodo, (yyvsp[(7) - (8)].valores).nodo); ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 433 "compilador.y"
    { printf("si con osi") ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 435 "compilador.y"
    {printf("osi\n");}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 436 "compilador.y"
    {printf("mas de un osi\n");}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 438 "compilador.y"
    {printf("sentencia osi");}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 441 "compilador.y"
    { (yyval.valores).nodo = createASTNode("mientras", -1, -1, (yyvsp[(3) - (6)].valores).nodo, (yyvsp[(5) - (6)].valores).nodo); ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 444 "compilador.y"
    { (yyval.valores).nodo = createASTNode("imprimir", -1, -1, (yyvsp[(3) - (4)].valores).nodo, NULL); ;}
    break;



/* Line 1464 of yacc.c  */
#line 2005 "compilador.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1684 of yacc.c  */
#line 448 "compilador.y"

extern FILE* yyin;
extern FILE* yyout;

main()
{
   char pathI[100] = "./CodigoEntrada/in.txt";
   char pathO[100] = "./CodigoEntrada/out.txt";

   yyin = fopen(pathI, "rt");
   yyout = fopen(pathO, "wt");

   yyparse();
   fclose(pathI);
   fclose(pathO);
}

void yyerror(const char *s)
{ 
    fprintf(stderr, "Error");
}
