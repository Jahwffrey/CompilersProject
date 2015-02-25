/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.y"

    #include <cstdlib>
    #include <cstdio>
    #include <iostream>
    #include "ast.hpp"
    
    #define YYDEBUG 1
    int yylex(void);
    void yyerror(const char *);
    
    extern ASTNode* astRoot;

/* Line 371 of yacc.c  */
#line 81 "parser.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "parser.hpp".  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_PLUS = 258,
     T_MINUS = 259,
     T_MULTI = 260,
     T_DIVID = 261,
     T_EQ = 262,
     T_LESSTHAN = 263,
     T_LESSTHANOREQ = 264,
     T_OPENCURLYBRACE = 265,
     T_CLOSECURLYBRACE = 266,
     T_OPENPAREN = 267,
     T_CLOSEPAREN = 268,
     T_DOT = 269,
     T_NUM = 270,
     T_IF = 271,
     T_OR = 272,
     T_NEW = 273,
     T_AND = 274,
     T_NOT = 275,
     T_ELSE = 276,
     T_COLON = 277,
     T_COMMA = 278,
     T_NONE = 279,
     T_TRUE = 280,
     T_FALSE = 281,
     T_PRINT = 282,
     T_WHILE = 283,
     T_RETURN = 284,
     T_EQUALS = 285,
     T_BOOL = 286,
     T_INT = 287,
     T_EXTENDS = 288,
     T_ARROW = 289,
     T_ID = 290,
     then = 291
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 182 "parser.cpp"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   236

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNRULES -- Number of states.  */
#define YYNSTATES  139

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

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
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    32,    35,    36,    38,    41,    43,
      46,    49,    50,    60,    63,    64,    68,    69,    73,    76,
      79,    81,    85,    89,    90,    93,    94,    98,   104,   106,
     108,   110,   112,   114,   117,   123,   129,   139,   142,   143,
     147,   151,   155,   159,   163,   167,   171,   175,   179,   182,
     185,   187,   191,   193,   197,   199,   201,   203,   206,   212,
     217,   224,   227,   228,   232
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,    40,    -1,    35,    -1,    43,    40,    -1,
      43,    -1,    32,    -1,    31,    -1,    39,    -1,    32,    -1,
      31,    -1,    39,    -1,    24,    -1,    39,    44,    10,    45,
      11,    -1,    33,    39,    -1,    -1,    46,    -1,    47,    46,
      -1,    48,    -1,    41,    39,    -1,    49,    48,    -1,    -1,
      39,    12,    50,    13,    34,    42,    10,    53,    11,    -1,
      52,    51,    -1,    -1,    23,    52,    51,    -1,    -1,    39,
      22,    41,    -1,    54,    63,    -1,    55,    54,    -1,    57,
      -1,    41,    39,    56,    -1,    23,    39,    56,    -1,    -1,
      59,    57,    -1,    -1,    39,     7,    64,    -1,    39,    14,
      39,     7,    64,    -1,    58,    -1,    65,    -1,    61,    -1,
      60,    -1,    62,    -1,    27,    64,    -1,    28,    64,    10,
      57,    11,    -1,    16,    64,    10,    57,    11,    -1,    16,
      64,    10,    57,    11,    21,    10,    57,    11,    -1,    29,
      64,    -1,    -1,    64,     3,    64,    -1,    64,     4,    64,
      -1,    64,     5,    64,    -1,    64,     6,    64,    -1,    64,
       8,    64,    -1,    64,     9,    64,    -1,    64,    30,    64,
      -1,    64,    19,    64,    -1,    64,    17,    64,    -1,    20,
      64,    -1,     4,    64,    -1,    39,    -1,    39,    14,    39,
      -1,    65,    -1,    12,    64,    13,    -1,    15,    -1,    25,
      -1,    26,    -1,    18,    39,    -1,    18,    39,    12,    66,
      13,    -1,    39,    12,    66,    13,    -1,    39,    14,    39,
      12,    66,    13,    -1,    64,    67,    -1,    -1,    23,    64,
      67,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    97,    97,   100,   102,   103,   106,   107,   108,   111,
     112,   113,   114,   117,   120,   121,   124,   127,   128,   131,
     134,   135,   138,   141,   142,   145,   146,   149,   153,   156,
     157,   160,   163,   164,   167,   168,   171,   172,   175,   176,
     177,   178,   179,   182,   185,   187,   188,   191,   192,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   217,
     218,   221,   222,   225,   226
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_PLUS", "T_MINUS", "T_MULTI",
  "T_DIVID", "T_EQ", "T_LESSTHAN", "T_LESSTHANOREQ", "T_OPENCURLYBRACE",
  "T_CLOSECURLYBRACE", "T_OPENPAREN", "T_CLOSEPAREN", "T_DOT", "T_NUM",
  "T_IF", "T_OR", "T_NEW", "T_AND", "T_NOT", "T_ELSE", "T_COLON",
  "T_COMMA", "T_NONE", "T_TRUE", "T_FALSE", "T_PRINT", "T_WHILE",
  "T_RETURN", "T_EQUALS", "T_BOOL", "T_INT", "T_EXTENDS", "T_ARROW",
  "T_ID", "then", "$accept", "Start", "Id", "Classes", "Type",
  "ReturnType", "Class", "Extension", "InsideClass", "Members", "Member",
  "Methods", "Method", "Params", "MoreParams", "Param", "MethodBody",
  "Declarations", "Declaration", "InlineDeclarations", "Statements",
  "Assigner", "Statement", "PrintStatement", "WhileStatement",
  "IfStatement", "MaybeReturn", "Expression", "MethodCall",
  "MethodCallParams", "MoreMethodCallParams", YY_NULL
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
     285,   286,   287,   288,   289,   290,   291
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    40,    40,    41,    41,    41,    42,
      42,    42,    42,    43,    44,    44,    45,    46,    46,    47,
      48,    48,    49,    50,    50,    51,    51,    52,    53,    54,
      54,    55,    56,    56,    57,    57,    58,    58,    59,    59,
      59,    59,    59,    60,    61,    62,    62,    63,    63,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    65,
      65,    66,    66,    67,    67
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     2,     0,     1,     2,     1,     2,
       2,     0,     9,     2,     0,     3,     0,     3,     2,     2,
       1,     3,     3,     0,     2,     0,     3,     5,     1,     1,
       1,     1,     1,     2,     5,     5,     9,     2,     0,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       1,     3,     1,     3,     1,     1,     1,     2,     5,     4,
       6,     2,     0,     3,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,    15,     2,     5,     1,     0,     0,     4,
      14,    21,     7,     6,     8,     0,     0,    16,    21,    18,
      21,    24,    19,    13,    17,     0,    20,     0,     0,    26,
       0,     0,     0,    23,     8,    27,     0,    26,    12,    10,
       9,    11,     0,    25,    35,     0,     0,     0,     8,     0,
       0,    48,    35,    30,    38,    35,    41,    40,    42,    39,
       0,     0,    64,     0,     0,    65,    66,    60,     0,    62,
      43,     0,     0,    72,     0,    33,    22,     0,    28,    29,
       0,    34,    59,     0,    67,    58,     0,     0,     0,     0,
       0,     0,     0,    35,     0,     0,     0,    35,    36,    74,
       0,     0,     0,    31,    47,    63,    72,    61,    49,    50,
      51,    52,    53,    54,     0,    57,    56,    55,     0,     0,
      71,    69,     0,    72,    33,     0,    45,    44,    74,    37,
       0,    32,    68,     0,    73,    70,    35,     0,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    67,     4,    15,    42,     5,     8,    16,    17,
      18,    19,    20,    28,    33,    29,    50,    51,    52,   103,
      53,    54,    55,    56,    57,    58,    78,    99,    69,   100,
     120
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -93
static const yytype_int16 yypact[] =
{
     -18,   -93,    38,     7,   -93,   -18,   -93,   -18,    32,   -93,
     -93,   -29,   -93,   -93,    42,   -18,    45,   -93,   -29,   -93,
     -18,   -18,   -93,   -93,   -93,    42,   -93,    49,    47,    52,
     -29,    53,   -18,   -93,   -93,   -93,    46,    52,   -93,   -93,
     -93,   -93,    62,   -93,    57,    33,    33,    33,    55,   -18,
      65,    61,    57,   -93,   -93,     6,   -93,   -93,   -93,   -93,
      33,    33,   -93,   -18,    33,   -93,   -93,    -2,   113,   -93,
     199,   141,    33,    33,   -18,    71,   -93,    33,   -93,   -93,
      55,   -93,   -93,   159,    83,   -93,   -18,    33,    33,    33,
      33,    33,    33,     6,    33,    33,    33,     6,   199,   176,
      85,    -3,   -18,   -93,   199,   -93,    33,    87,    41,    41,
     -93,   -93,   121,   121,    90,   206,    20,   121,    92,    33,
     -93,   -93,    33,    33,    71,    91,    84,   -93,   176,   199,
      99,   -93,   -93,   110,   -93,   -93,     6,   117,   -93
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -93,   -93,     0,   124,   -17,   -93,   -93,   -93,   -93,   115,
     -93,   111,   -93,   -93,    97,   103,   -93,    88,   -93,    13,
     -54,   -93,   -93,   -93,   -93,   -93,   -93,    19,   -36,   -92,
      11
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       3,    81,    12,    13,   122,     3,     1,    10,    59,   123,
      73,    14,    86,    35,   125,    22,    59,     1,    14,    59,
      25,    27,    45,    87,    88,    89,    90,    49,    91,    92,
      34,   130,    27,    46,    47,    49,    41,    60,     6,   114,
       7,     1,    11,   118,    48,    61,    89,    90,    62,    75,
      96,    63,    48,    64,    21,    80,    23,    59,    65,    66,
      31,    59,    72,    84,    68,    70,    71,    73,     1,    74,
      38,    30,    44,    45,   101,    32,    76,    39,    40,    82,
      83,     1,   137,    85,    46,    47,   107,    36,    12,    13,
      77,    98,     1,    80,   102,   106,   104,    80,   121,   123,
      59,   126,   124,   127,   132,   133,   108,   109,   110,   111,
     112,   113,   135,   115,   116,   117,    87,    88,    89,    90,
     136,    91,    92,    93,    87,    88,    89,    90,   138,     9,
      94,    26,    95,    24,    43,    37,    80,   131,   128,   134,
      79,   129,     0,    96,    87,    88,    89,    90,     0,    91,
      92,    97,     0,     0,     0,     0,     0,     0,    94,     0,
      95,     0,    87,    88,    89,    90,     0,    91,    92,     0,
       0,    96,   105,     0,     0,     0,    94,     0,    95,    87,
      88,    89,    90,     0,    91,    92,     0,     0,     0,    96,
       0,     0,     0,    94,     0,    95,     0,     0,     0,   119,
       0,     0,    87,    88,    89,    90,    96,    91,    92,    87,
      88,    89,    90,     0,    91,    92,    94,     0,    95,     0,
       0,     0,     0,     0,     0,    95,     0,     0,     0,    96,
       0,     0,     0,     0,     0,     0,    96
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-93)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    55,    31,    32,     7,     5,    35,     7,    44,    12,
      12,    11,    14,    30,   106,    15,    52,    35,    18,    55,
      20,    21,    16,     3,     4,     5,     6,    44,     8,     9,
      30,   123,    32,    27,    28,    52,    36,     4,     0,    93,
      33,    35,    10,    97,    44,    12,     5,     6,    15,    49,
      30,    18,    52,    20,    12,    55,    11,    93,    25,    26,
      13,    97,     7,    63,    45,    46,    47,    12,    35,    14,
      24,    22,    10,    16,    74,    23,    11,    31,    32,    60,
      61,    35,   136,    64,    27,    28,    86,    34,    31,    32,
      29,    72,    35,    93,    23,    12,    77,    97,    13,    12,
     136,    11,   102,    11,    13,    21,    87,    88,    89,    90,
      91,    92,    13,    94,    95,    96,     3,     4,     5,     6,
      10,     8,     9,    10,     3,     4,     5,     6,    11,     5,
      17,    20,    19,    18,    37,    32,   136,   124,   119,   128,
      52,   122,    -1,    30,     3,     4,     5,     6,    -1,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      19,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    30,    13,    -1,    -1,    -1,    17,    -1,    19,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    17,    -1,    19,    -1,    -1,    -1,    23,
      -1,    -1,     3,     4,     5,     6,    30,     8,     9,     3,
       4,     5,     6,    -1,     8,     9,    17,    -1,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    35,    38,    39,    40,    43,     0,    33,    44,    40,
      39,    10,    31,    32,    39,    41,    45,    46,    47,    48,
      49,    12,    39,    11,    46,    39,    48,    39,    50,    52,
      22,    13,    23,    51,    39,    41,    34,    52,    24,    31,
      32,    39,    42,    51,    10,    16,    27,    28,    39,    41,
      53,    54,    55,    57,    58,    59,    60,    61,    62,    65,
       4,    12,    15,    18,    20,    25,    26,    39,    64,    65,
      64,    64,     7,    12,    14,    39,    11,    29,    63,    54,
      39,    57,    64,    64,    39,    64,    14,     3,     4,     5,
       6,     8,     9,    10,    17,    19,    30,    10,    64,    64,
      66,    39,    23,    56,    64,    13,    12,    39,    64,    64,
      64,    64,    64,    64,    57,    64,    64,    64,    57,    23,
      67,    13,     7,    12,    39,    66,    11,    11,    64,    64,
      66,    56,    13,    21,    67,    13,    10,    57,    11
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
/* Line 1792 of yacc.c  */
#line 97 "parser.y"
    { astRoot = new ProgramNode((yyvsp[(1) - (1)].class_list_ptr));}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 100 "parser.y"
    { (yyval.identifier_ptr) = new IdentifierNode(yylval.base_char_ptr);}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 102 "parser.y"
    { (yyvsp[(2) - (2)].class_list_ptr)->push_front((yyvsp[(1) - (2)].class_ptr)); (yyval.class_list_ptr) = (yyvsp[(2) - (2)].class_list_ptr);}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 103 "parser.y"
    { (yyval.class_list_ptr) = new std::list<ClassNode*>(); (yyval.class_list_ptr)->push_front((yyvsp[(1) - (1)].class_ptr));}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 106 "parser.y"
    { (yyval.type_ptr) = new IntegerTypeNode();}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 107 "parser.y"
    { (yyval.type_ptr) = new BooleanTypeNode();}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 108 "parser.y"
    { (yyval.type_ptr) = new ObjectTypeNode((yyvsp[(1) - (1)].identifier_ptr));}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 111 "parser.y"
    { (yyval.type_ptr) = new IntegerTypeNode();}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 112 "parser.y"
    { (yyval.type_ptr) = new BooleanTypeNode();}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 113 "parser.y"
    { (yyval.type_ptr) = new ObjectTypeNode((yyvsp[(1) - (1)].identifier_ptr));}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 114 "parser.y"
    { (yyval.type_ptr) = new NoneNode();}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 117 "parser.y"
    { (yyvsp[(4) - (5)].class_ptr)->identifier_1 = (yyvsp[(1) - (5)].identifier_ptr); (yyvsp[(4) - (5)].class_ptr)->identifier_2 = (yyvsp[(2) - (5)].identifier_ptr); (yyval.class_ptr) = (yyvsp[(4) - (5)].class_ptr);}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 120 "parser.y"
    { (yyval.identifier_ptr) = (yyvsp[(2) - (2)].identifier_ptr);}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 121 "parser.y"
    { (yyval.identifier_ptr) = NULL;}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 124 "parser.y"
    {(yyval.class_ptr) = (yyvsp[(1) - (1)].class_ptr);}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 127 "parser.y"
    { (yyvsp[(2) - (2)].class_ptr)->declaration_list->push_front((yyvsp[(1) - (2)].declaration_ptr)); (yyval.class_ptr) = (yyvsp[(2) - (2)].class_ptr);}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 128 "parser.y"
    { (yyval.class_ptr) = new ClassNode(NULL,NULL,new std::list<DeclarationNode*>(),(yyvsp[(1) - (1)].method_list_ptr));}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 131 "parser.y"
    { (yyval.declaration_ptr) = new DeclarationNode((yyvsp[(1) - (2)].type_ptr),new std::list<IdentifierNode*>()); (yyval.declaration_ptr)->identifier_list->push_front((yyvsp[(2) - (2)].identifier_ptr));}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 134 "parser.y"
    { (yyvsp[(2) - (2)].method_list_ptr)->push_front((yyvsp[(1) - (2)].method_ptr)); (yyval.method_list_ptr) = (yyvsp[(2) - (2)].method_list_ptr);}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 135 "parser.y"
    { (yyval.method_list_ptr) = new std::list<MethodNode*>();}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 138 "parser.y"
    { (yyval.method_ptr) = new MethodNode((yyvsp[(1) - (9)].identifier_ptr),(yyvsp[(3) - (9)].parameter_list_ptr),(yyvsp[(6) - (9)].type_ptr),(yyvsp[(8) - (9)].methodbody_ptr));}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 141 "parser.y"
    { (yyvsp[(2) - (2)].parameter_list_ptr)->push_front((yyvsp[(1) - (2)].parameter_ptr)); (yyval.parameter_list_ptr) = (yyvsp[(2) - (2)].parameter_list_ptr);}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 142 "parser.y"
    { (yyval.parameter_list_ptr) = NULL;}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 145 "parser.y"
    { (yyvsp[(3) - (3)].parameter_list_ptr)->push_front((yyvsp[(2) - (3)].parameter_ptr)); (yyval.parameter_list_ptr) = (yyvsp[(3) - (3)].parameter_list_ptr);}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 146 "parser.y"
    { (yyval.parameter_list_ptr) = new std::list<ParameterNode*>();}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 149 "parser.y"
    { (yyval.parameter_ptr) = new ParameterNode((yyvsp[(3) - (3)].type_ptr),(yyvsp[(1) - (3)].identifier_ptr)); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 153 "parser.y"
    { (yyvsp[(1) - (2)].methodbody_ptr)->returnstatement = (yyvsp[(2) - (2)].returnstatement_ptr); (yyval.methodbody_ptr) = (yyvsp[(1) - (2)].methodbody_ptr);}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 156 "parser.y"
    { (yyvsp[(2) - (2)].methodbody_ptr)->declaration_list->push_front((yyvsp[(1) - (2)].declaration_ptr)); (yyval.methodbody_ptr) = (yyvsp[(2) - (2)].methodbody_ptr);}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 157 "parser.y"
    { (yyval.methodbody_ptr) = new MethodBodyNode(new std::list<DeclarationNode*>(),(yyvsp[(1) - (1)].statement_list_ptr),NULL);}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 160 "parser.y"
    { (yyvsp[(3) - (3)].identifier_list_ptr)->push_front((yyvsp[(2) - (3)].identifier_ptr)); (yyval.declaration_ptr) = new DeclarationNode((yyvsp[(1) - (3)].type_ptr),(yyvsp[(3) - (3)].identifier_list_ptr));}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 163 "parser.y"
    { (yyvsp[(3) - (3)].identifier_list_ptr)->push_front((yyvsp[(2) - (3)].identifier_ptr)); (yyval.identifier_list_ptr) = (yyvsp[(3) - (3)].identifier_list_ptr); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 164 "parser.y"
    { (yyval.identifier_list_ptr) = new std::list<IdentifierNode*>(); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 167 "parser.y"
    { (yyvsp[(2) - (2)].statement_list_ptr)->push_front((yyvsp[(1) - (2)].statement_ptr)); (yyval.statement_list_ptr) = (yyvsp[(2) - (2)].statement_list_ptr); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 168 "parser.y"
    { (yyval.statement_list_ptr) = new std::list<StatementNode*>(); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 171 "parser.y"
    { (yyval.assignment_ptr) = new AssignmentNode((yyvsp[(1) - (3)].identifier_ptr),NULL,(yyvsp[(3) - (3)].expression_ptr));}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 172 "parser.y"
    { (yyval.assignment_ptr) = new AssignmentNode((yyvsp[(1) - (5)].identifier_ptr),(yyvsp[(3) - (5)].identifier_ptr),(yyvsp[(5) - (5)].expression_ptr));}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 175 "parser.y"
    { (yyval.statement_ptr) = (yyvsp[(1) - (1)].assignment_ptr);}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 176 "parser.y"
    { (yyval.statement_ptr) = new CallNode((yyvsp[(1) - (1)].methodcall_ptr));}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 177 "parser.y"
    { (yyval.statement_ptr) = (yyvsp[(1) - (1)].while_ptr);}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 178 "parser.y"
    { (yyval.statement_ptr) = (yyvsp[(1) - (1)].print_ptr);}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 179 "parser.y"
    { (yyval.statement_ptr) = (yyvsp[(1) - (1)].ifelse_ptr);}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 182 "parser.y"
    { (yyval.print_ptr) = new PrintNode((yyvsp[(2) - (2)].expression_ptr)); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 185 "parser.y"
    { (yyval.while_ptr) = new WhileNode((yyvsp[(2) - (5)].expression_ptr),(yyvsp[(4) - (5)].statement_list_ptr)); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 187 "parser.y"
    { (yyval.ifelse_ptr) = new IfElseNode((yyvsp[(2) - (5)].expression_ptr),(yyvsp[(4) - (5)].statement_list_ptr),NULL);}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 188 "parser.y"
    {(yyval.ifelse_ptr) = new IfElseNode((yyvsp[(2) - (9)].expression_ptr),(yyvsp[(4) - (9)].statement_list_ptr),(yyvsp[(8) - (9)].statement_list_ptr));}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 191 "parser.y"
    { (yyval.returnstatement_ptr) = new ReturnStatementNode((yyvsp[(2) - (2)].expression_ptr)); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 192 "parser.y"
    { (yyval.returnstatement_ptr) = NULL; }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 195 "parser.y"
    { (yyval.expression_ptr) = new PlusNode((yyvsp[(1) - (3)].expression_ptr),(yyvsp[(3) - (3)].expression_ptr));}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 196 "parser.y"
    { (yyval.expression_ptr) = new MinusNode((yyvsp[(1) - (3)].expression_ptr),(yyvsp[(3) - (3)].expression_ptr));}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 197 "parser.y"
    { (yyval.expression_ptr) = new TimesNode((yyvsp[(1) - (3)].expression_ptr),(yyvsp[(3) - (3)].expression_ptr));}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 198 "parser.y"
    { (yyval.expression_ptr) = new DivideNode((yyvsp[(1) - (3)].expression_ptr),(yyvsp[(3) - (3)].expression_ptr));}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 199 "parser.y"
    { (yyval.expression_ptr) = new LessNode((yyvsp[(1) - (3)].expression_ptr),(yyvsp[(3) - (3)].expression_ptr));}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 200 "parser.y"
    { (yyval.expression_ptr) = new LessEqualNode((yyvsp[(1) - (3)].expression_ptr),(yyvsp[(3) - (3)].expression_ptr));}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 201 "parser.y"
    { (yyval.expression_ptr) = new EqualNode((yyvsp[(1) - (3)].expression_ptr),(yyvsp[(3) - (3)].expression_ptr));}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 202 "parser.y"
    { (yyval.expression_ptr) = new AndNode((yyvsp[(1) - (3)].expression_ptr),(yyvsp[(3) - (3)].expression_ptr));}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 203 "parser.y"
    { (yyval.expression_ptr) = new OrNode((yyvsp[(1) - (3)].expression_ptr),(yyvsp[(3) - (3)].expression_ptr));}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 204 "parser.y"
    { (yyval.expression_ptr) = new NotNode((yyvsp[(2) - (2)].expression_ptr)); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 205 "parser.y"
    { (yyval.expression_ptr) = new NegationNode((yyvsp[(2) - (2)].expression_ptr)); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 206 "parser.y"
    { (yyval.expression_ptr) = new VariableNode((yyvsp[(1) - (1)].identifier_ptr)); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 207 "parser.y"
    { (yyval.expression_ptr) = new MemberAccessNode((yyvsp[(1) - (3)].identifier_ptr),(yyvsp[(3) - (3)].identifier_ptr));}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 208 "parser.y"
    { (yyval.expression_ptr) = (yyvsp[(1) - (1)].methodcall_ptr); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 209 "parser.y"
    { (yyval.expression_ptr) = (yyvsp[(2) - (3)].expression_ptr); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 210 "parser.y"
    { (yyval.expression_ptr) = new IntegerLiteralNode(new IntegerNode(yylval.base_int));}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 211 "parser.y"
    { (yyval.expression_ptr) = new BooleanLiteralNode(new IntegerNode(1)); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 212 "parser.y"
    { (yyval.expression_ptr) = new BooleanLiteralNode(new IntegerNode(0)); }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 213 "parser.y"
    { (yyval.expression_ptr) = new NewNode((yyvsp[(2) - (2)].identifier_ptr),NULL);}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 214 "parser.y"
    { (yyval.expression_ptr) = new NewNode((yyvsp[(2) - (5)].identifier_ptr),(yyvsp[(4) - (5)].expression_list_ptr));}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 217 "parser.y"
    { (yyval.methodcall_ptr) = new MethodCallNode((yyvsp[(1) - (4)].identifier_ptr),NULL,(yyvsp[(3) - (4)].expression_list_ptr));}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 218 "parser.y"
    { (yyval.methodcall_ptr) = new MethodCallNode((yyvsp[(1) - (6)].identifier_ptr),(yyvsp[(3) - (6)].identifier_ptr),(yyvsp[(5) - (6)].expression_list_ptr));}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 221 "parser.y"
    {(yyvsp[(2) - (2)].expression_list_ptr)->push_front((yyvsp[(1) - (2)].expression_ptr)); (yyval.expression_list_ptr) = (yyvsp[(2) - (2)].expression_list_ptr);}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 222 "parser.y"
    {(yyval.expression_list_ptr) = NULL;}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 225 "parser.y"
    { (yyvsp[(3) - (3)].expression_list_ptr)->push_front((yyvsp[(2) - (3)].expression_ptr)); (yyval.expression_list_ptr) = (yyvsp[(3) - (3)].expression_list_ptr);}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 226 "parser.y"
    { (yyval.expression_list_ptr) = new std::list<ExpressionNode*>();}
    break;


/* Line 1792 of yacc.c  */
#line 1955 "parser.cpp"
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


/* Line 2055 of yacc.c  */
#line 229 "parser.y"


extern int yylineno;

void yyerror(const char *s) {
  fprintf(stderr, "%s at line %d\n", s, yylineno);
  exit(1);
}
