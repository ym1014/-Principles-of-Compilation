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
     ID = 258,
     INTCON = 259,
     CHARCON = 260,
     STRINGCON = 261,
     CHAR = 262,
     INT = 263,
     VOID = 264,
     EXTERN = 265,
     IF = 266,
     ELSE = 267,
     WHILE = 268,
     FOR = 269,
     RETURN = 270,
     AND = 271,
     OR = 272,
     EQ = 273,
     NEQ = 274,
     LE = 275,
     GE = 276,
     dangling_else = 277
   };
#endif
/* Tokens.  */
#define ID 258
#define INTCON 259
#define CHARCON 260
#define STRINGCON 261
#define CHAR 262
#define INT 263
#define VOID 264
#define EXTERN 265
#define IF 266
#define ELSE 267
#define WHILE 268
#define FOR 269
#define RETURN 270
#define AND 271
#define OR 272
#define EQ 273
#define NEQ 274
#define LE 275
#define GE 276
#define dangling_else 277




/* Copy the first part of user declarations.  */
#line 13 "parser.y"

#include "global.h"
#include "error.h"
#include "syntax-tree.h"
#include "symbol-table.h"

extern int yylex();
extern void yyerror();

/*
 * The function process_syntax_tree() is defined in the file 
 * process_syntax_tree.c.  For each function in the input program, 
 * process_syntax_tree() is called once that function's syntax tree has 
 * been constructed.  The arguments passed to process_syntrax_tree() 
 * are (1) a pointer to the global symbol table entry for the function
 * name; and (2) a pointer to the root of the syntax tree for the function
 * body.
 *
 * Syntax tree processing can be customized by replacing the code for
 * this function.
 */
extern void process_syntax_tree(symtabnode *fn_name, struct treenode *fn_body);

  /*
   * struct treenode *currfnbodyTree is set to point to
   * the syntax tree for the body of the current function
   * at the end of each function.  
   * NOTE: the syntax tree MUST be used before CleanupFnInfo()
   * is called at the end of the function.  After that the
   * symbol table entries for the local variables of the
   * function will go away, leaving dangling pointers from
   * the syntax tree.
   */
struct treenode *currfnbodyTree = NULL;

extern char *id_name, *yytext;
extern int ival;
extern int linenum;
char *fnName;
symtabnode *stptr, *currFun;
int CurrType, EltType, fnRetType;
int CurrScope = Global;
llistptr lptr;
bool is_extern;
int errstate = 0;


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
#line 60 "parser.y"
{
  tnptr tptr;
  llistptr idlistptr;
  char *chptr;
  int nval;
}
/* Line 193 of yacc.c.  */
#line 194 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 207 "y.tab.c"

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   294

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNRULES -- Number of states.  */
#define YYNSTATES  181

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,     2,     2,     2,     2,     2,     2,
      31,    32,    28,    26,    30,    27,     2,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    33,
      21,    24,    23,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    22,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    17,    27,    28,    41,    42,    44,
      45,    46,    52,    54,    59,    61,    63,    67,    69,    72,
      77,    79,    81,    83,    87,    88,    91,    92,    97,    98,
     103,   105,   107,   112,   114,   117,   118,   125,   131,   141,
     145,   148,   151,   153,   155,   157,   159,   160,   163,   165,
     166,   169,   173,   176,   177,   179,   180,   182,   183,   185,
     186,   190,   194,   198,   202,   206,   210,   214,   217,   221,
     225,   229,   232,   236,   240,   244,   248,   250,   252,   256,
     260,   262,   264,   266,   270,   275,   280,   284,   289,   294,
     296,   301,   306,   310,   312
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    40,    50,    53,    33,    -1,    40,    50,
      76,    31,    43,    47,    32,    44,    -1,    40,    42,    50,
      76,    31,    43,    47,    32,    44,    -1,    -1,    40,    50,
      76,    31,    43,    47,    32,    34,    41,    51,    58,    35,
      -1,    -1,    10,    -1,    -1,    -1,    62,    45,    46,    43,
      44,    -1,    33,    -1,    76,    31,    47,    32,    -1,     9,
      -1,    48,    -1,    48,    62,    49,    -1,    49,    -1,    50,
      76,    -1,    50,    76,    36,    37,    -1,     8,    -1,     7,
      -1,     9,    -1,    51,    52,    33,    -1,    -1,    50,    53,
      -1,    -1,    53,    62,    54,    56,    -1,    -1,     1,    62,
      55,    56,    -1,    56,    -1,    76,    -1,    76,    36,    57,
      37,    -1,     4,    -1,    59,    58,    -1,    -1,    11,    31,
      70,    32,    59,    65,    -1,    13,    31,    70,    32,    59,
      -1,    14,    31,    66,    60,    68,    60,    66,    32,    59,
      -1,    15,    67,    60,    -1,    69,    60,    -1,    73,    60,
      -1,    64,    -1,    33,    -1,     1,    -1,    33,    -1,    -1,
      61,     1,    -1,    30,    -1,    -1,    63,     1,    -1,    34,
      58,    35,    -1,    12,    59,    -1,    -1,    69,    -1,    -1,
      71,    -1,    -1,    70,    -1,    -1,    74,    24,    71,    -1,
      71,    18,    71,    -1,    71,    19,    71,    -1,    71,    20,
      71,    -1,    71,    22,    71,    -1,    71,    21,    71,    -1,
      71,    23,    71,    -1,    25,    70,    -1,    70,    16,    70,
      -1,    70,    17,    70,    -1,    31,    70,    32,    -1,    27,
      71,    -1,    71,    26,    71,    -1,    71,    27,    71,    -1,
      71,    28,    71,    -1,    71,    29,    71,    -1,    72,    -1,
      74,    -1,    31,    71,    32,    -1,    31,     1,    32,    -1,
       4,    -1,     5,    -1,     6,    -1,    76,    31,    32,    -1,
      76,    31,    75,    32,    -1,    76,    31,     1,    32,    -1,
      76,    31,    32,    -1,    76,    31,    75,    32,    -1,    76,
      31,     1,    32,    -1,    76,    -1,    76,    36,    71,    37,
      -1,    76,    36,     1,    37,    -1,    71,    62,    75,    -1,
      71,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,    96,    98,   101,   100,   114,   117,   119,
     128,   128,   129,   133,   145,   146,   150,   151,   155,   156,
     161,   162,   163,   167,   168,   172,   176,   176,   177,   177,
     178,   182,   193,   207,   211,   212,   216,   222,   228,   234,
     258,   259,   260,   261,   262,   270,   271,   271,   275,   276,
     276,   280,   284,   285,   289,   290,   294,   295,   299,   300,
     304,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   355,   379,   401,   412,   438,   464,   475,
     485,   512,   527,   528,   531
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INTCON", "CHARCON", "STRINGCON",
  "CHAR", "INT", "VOID", "EXTERN", "IF", "ELSE", "WHILE", "FOR", "RETURN",
  "AND", "OR", "EQ", "NEQ", "LE", "'<'", "GE", "'>'", "'='", "'!'", "'+'",
  "'-'", "'*'", "'/'", "','", "'('", "')'", "';'", "'{'", "'}'", "'['",
  "']'", "dangling_else", "$accept", "prog", "@1", "Extern", "SetFnInfo",
  "fprotRest", "@2", "fprototype", "parm_types", "nonempty_parm_type_list",
  "parm_type_decl", "type", "var_decls", "var_decl", "id_list", "@3", "@4",
  "id_decl", "ArraySize", "stmt_list", "stmt", "semicolon", "@5", "comma",
  "@6", "compound_stmt", "optional_else", "optional_assgt",
  "optional_expr", "optional_boolexp", "assignment", "boolexp", "expr",
  "fun_call", "proc_call", "variable", "expr_list", "Ident", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    60,   276,    62,    61,    33,    43,    45,    42,    47,
      44,    40,    41,    59,   123,   125,    91,    93,   277
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    40,    40,    41,    40,    40,    42,    43,
      45,    44,    44,    46,    47,    47,    48,    48,    49,    49,
      50,    50,    50,    51,    51,    52,    54,    53,    55,    53,
      53,    56,    56,    57,    58,    58,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    60,    61,    60,    62,    63,
      62,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      69,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    72,    72,    72,    73,    73,    73,    74,
      74,    74,    75,    75,    76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     8,     9,     0,    12,     0,     1,     0,
       0,     5,     1,     4,     1,     1,     3,     1,     2,     4,
       1,     1,     1,     3,     0,     2,     0,     4,     0,     4,
       1,     1,     4,     1,     2,     0,     6,     5,     9,     3,
       2,     2,     1,     1,     1,     1,     0,     2,     1,     0,
       2,     3,     2,     0,     1,     0,     1,     0,     1,     0,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     2,     3,     3,     3,     3,     1,     1,     3,     3,
       1,     1,     1,     3,     4,     4,     3,     4,     4,     1,
       4,     4,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     1,    21,    20,    22,     8,     0,     0,     0,
      49,    94,    49,    30,    31,     0,    48,    28,     0,     2,
      26,     9,     0,     9,     0,    50,     0,     0,    33,     0,
       0,    29,    31,    27,    14,     0,    15,    17,     0,    32,
       0,    49,     0,    18,    49,    12,     5,     3,    10,    16,
       0,     4,    24,     0,    19,     0,     9,     0,    44,     0,
       0,     0,    57,    43,     0,     0,     0,     0,     0,    42,
      46,    46,     0,    89,    49,     0,     0,     0,    55,    80,
      81,    82,     0,     0,    46,    56,    76,    77,    89,     0,
      25,    23,     6,    34,    45,    40,     0,    41,     0,     0,
       0,    11,     0,     0,     0,     0,     0,     0,    46,    54,
      89,    71,     0,     0,    39,     0,     0,     0,     0,     0,
      51,    47,    60,     0,    86,    49,     0,     0,     0,    13,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    59,    79,    78,    72,    73,    74,    75,
       0,    83,     0,    88,     0,    87,    91,    90,    70,    68,
      69,    53,    61,    62,    63,    65,    64,    66,    37,    46,
      58,    85,    84,    92,     0,    36,    55,    52,     0,     0,
      38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    52,     7,    27,    47,    53,    56,    35,    36,
      37,    38,    55,    66,    12,    26,    24,    13,    29,    67,
      68,    95,    96,    48,    18,    69,   175,   108,    84,   169,
      70,   105,   106,    86,    71,    87,   126,    88
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -108
static const yytype_int16 yypact[] =
{
    -108,   266,  -108,  -108,  -108,  -108,  -108,   200,   137,    24,
      16,  -108,    57,  -108,     0,    22,  -108,  -108,    70,  -108,
    -108,  -108,    84,  -108,    24,  -108,    24,   208,  -108,    63,
     208,  -108,    96,  -108,   102,   101,    25,  -108,    24,  -108,
     117,    73,   200,   119,    92,  -108,  -108,  -108,  -108,  -108,
      91,  -108,  -108,    24,  -108,   128,  -108,   129,  -108,   133,
     134,   136,    93,  -108,     9,   137,   126,   135,     9,  -108,
     139,   139,   145,     1,    92,   208,   228,   228,    24,  -108,
    -108,  -108,    93,   193,   139,   265,  -108,  -108,    30,   138,
      25,  -108,  -108,  -108,  -108,  -108,   174,  -108,    93,   147,
     199,  -108,   149,   228,   187,    33,   242,    52,   139,  -108,
     150,  -108,   155,   258,  -108,    93,    93,    93,    93,   179,
    -108,  -108,   265,   157,  -108,   251,   163,   164,    82,  -108,
    -108,    69,   217,   228,   228,   143,    93,    93,    93,    93,
      93,    93,   143,   228,  -108,  -108,    11,    11,  -108,  -108,
     181,  -108,   189,  -108,    93,  -108,  -108,  -108,  -108,  -108,
    -108,   207,   265,   265,   265,   265,   265,   265,  -108,   139,
      62,  -108,  -108,  -108,   143,  -108,    24,  -108,   190,   143,
    -108
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -108,  -108,  -108,  -108,    -4,   -23,  -108,  -108,   -21,  -108,
     183,     7,  -108,  -108,   158,  -108,  -108,   121,  -108,    13,
    -107,   -67,  -108,    -7,  -108,  -108,  -108,    51,  -108,  -108,
     -72,   -70,   -24,  -108,  -108,   -53,  -106,    -8
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -94
static const yytype_int16 yytable[] =
{
      14,    15,    72,    17,    97,    20,   109,   107,     8,    40,
      58,    72,    11,   152,     9,    72,    32,   114,    32,    30,
      59,    51,    60,    61,    62,    72,   -49,    11,   161,    42,
      43,    21,    99,   130,   131,   168,    22,   100,    85,   117,
     118,   143,    63,    64,   -35,    57,    16,    73,   173,   133,
     134,   101,    74,    23,   102,    16,    73,    32,   111,   113,
      73,   119,    65,   159,   160,   135,   100,   177,   133,   134,
     110,    25,   180,   170,   122,   125,   128,    89,   133,   134,
     132,    93,    72,    20,   142,   133,   134,    16,    28,    72,
      19,   146,   147,   148,   149,   125,    11,    79,    80,    81,
      39,   158,   176,    16,   109,   -22,    45,    46,   115,   116,
     117,   118,   162,   163,   164,   165,   166,   167,   154,   157,
      82,    72,    16,    72,    83,    45,    72,    73,    54,    58,
     125,    11,    22,    41,    73,     3,     4,     5,    10,    59,
      11,    60,    61,    62,    58,    31,    11,    33,   123,    44,
      11,    79,    80,    81,    59,    50,    60,    61,    62,    91,
      75,    63,    64,   -35,    76,    77,    73,    78,   110,    98,
      92,    73,    94,   120,    82,   121,    63,    64,    83,   124,
     150,   129,    11,    79,    80,    81,   100,   144,   112,   153,
      11,    79,    80,    81,   112,   155,    11,    79,    80,    81,
     127,   156,    11,    79,    80,    81,    82,     3,     4,     5,
      83,   151,   103,   171,    82,     3,     4,    34,   104,   174,
      82,   172,   179,    90,    83,    49,    82,   178,     0,     0,
      83,    11,    79,    80,    81,   136,   137,   138,   139,   140,
     141,     0,     0,   115,   116,   117,   118,     0,     0,   145,
       0,     0,     0,   103,     0,    82,     0,     0,     0,   104,
     136,   137,   138,   139,   140,   141,     2,     0,   115,   116,
     117,   118,     0,     3,     4,     5,     6,   115,   116,   117,
     118,    16,     0,   -93,   115,   116,   117,   118,     0,     0,
     145,   115,   116,   117,   118
};

static const yytype_int16 yycheck[] =
{
       8,     9,    55,    10,    71,    12,    78,    77,     1,    30,
       1,    64,     3,   119,     7,    68,    24,    84,    26,    23,
      11,    44,    13,    14,    15,    78,     1,     3,   135,    36,
      38,    31,    31,   103,   104,   142,    36,    36,    62,    28,
      29,   108,    33,    34,    35,    53,    30,    55,   154,    16,
      17,    74,    56,    31,    75,    30,    64,    65,    82,    83,
      68,    31,    55,   133,   134,    32,    36,   174,    16,    17,
      78,     1,   179,   143,    98,    99,   100,    64,    16,    17,
     104,    68,   135,    90,    32,    16,    17,    30,     4,   142,
      33,   115,   116,   117,   118,   119,     3,     4,     5,     6,
      37,    32,   169,    30,   176,     3,    33,    34,    26,    27,
      28,    29,   136,   137,   138,   139,   140,   141,   125,    37,
      27,   174,    30,   176,    31,    33,   179,   135,    37,     1,
     154,     3,    36,    32,   142,     7,     8,     9,     1,    11,
       3,    13,    14,    15,     1,    24,     3,    26,     1,    32,
       3,     4,     5,     6,    11,    36,    13,    14,    15,    33,
      31,    33,    34,    35,    31,    31,   174,    31,   176,    24,
      35,   179,    33,    35,    27,     1,    33,    34,    31,    32,
       1,    32,     3,     4,     5,     6,    36,    32,     1,    32,
       3,     4,     5,     6,     1,    32,     3,     4,     5,     6,
       1,    37,     3,     4,     5,     6,    27,     7,     8,     9,
      31,    32,    25,    32,    27,     7,     8,     9,    31,    12,
      27,    32,    32,    65,    31,    42,    27,   176,    -1,    -1,
      31,     3,     4,     5,     6,    18,    19,    20,    21,    22,
      23,    -1,    -1,    26,    27,    28,    29,    -1,    -1,    32,
      -1,    -1,    -1,    25,    -1,    27,    -1,    -1,    -1,    31,
      18,    19,    20,    21,    22,    23,     0,    -1,    26,    27,
      28,    29,    -1,     7,     8,     9,    10,    26,    27,    28,
      29,    30,    -1,    32,    26,    27,    28,    29,    -1,    -1,
      32,    26,    27,    28,    29
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,     0,     7,     8,     9,    10,    42,    50,    50,
       1,     3,    53,    56,    76,    76,    30,    62,    63,    33,
      62,    31,    36,    31,    55,     1,    54,    43,     4,    57,
      43,    56,    76,    56,     9,    47,    48,    49,    50,    37,
      47,    32,    62,    76,    32,    33,    34,    44,    62,    49,
      36,    44,    41,    45,    37,    51,    46,    76,     1,    11,
      13,    14,    15,    33,    34,    50,    52,    58,    59,    64,
      69,    73,    74,    76,    43,    31,    31,    31,    31,     4,
       5,     6,    27,    31,    67,    71,    72,    74,    76,    58,
      53,    33,    35,    58,    33,    60,    61,    60,    24,    31,
      36,    44,    47,    25,    31,    70,    71,    70,    66,    69,
      76,    71,     1,    71,    60,    26,    27,    28,    29,    31,
      35,     1,    71,     1,    32,    71,    75,     1,    71,    32,
      70,    70,    71,    16,    17,    32,    18,    19,    20,    21,
      22,    23,    32,    60,    32,    32,    71,    71,    71,    71,
       1,    32,    75,    32,    62,    32,    37,    37,    32,    70,
      70,    59,    71,    71,    71,    71,    71,    71,    59,    68,
      70,    32,    32,    75,    12,    65,    60,    59,    66,    32,
      59
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
        case 5:
#line 101 "parser.y"
    { currFun = SymTabRecordFunInfo(false);}
    break;

  case 6:
#line 103 "parser.y"
    { 
      currfnbodyTree = AppendReturn((yyvsp[(11) - (12)].tptr));
      /*
       * At this point, currfnbodyTree points to the syntax tree
       * for the body of the current function.  This can then
       * be traversed for code generation etc.
       */
      process_syntax_tree(currFun, currfnbodyTree);

      CleanupFnInfo(); 
    }
    break;

  case 8:
#line 117 "parser.y"
    { is_extern = true; }
    break;

  case 9:
#line 119 "parser.y"
    { 
	CurrScope = Local; 
	fnRetType = CurrType;
	fnName = id_name;
	lptr = NULL;
  }
    break;

  case 10:
#line 128 "parser.y"
    { SymTabRecordFunInfo(true); }
    break;

  case 12:
#line 129 "parser.y"
    { SymTabRecordFunInfo(true); CleanupFnInfo(); }
    break;

  case 13:
#line 133 "parser.y"
    { 
    stptr = SymTabLookupAll((yyvsp[(1) - (4)].chptr));
    if (stptr != NULL) {
      errmsg("%s multiply declared", (yyvsp[(1) - (4)].chptr));
    }
    else {
      CurrScope = Local;
    }
 }
    break;

  case 14:
#line 145 "parser.y"
    { (yyval.idlistptr) = NULL; }
    break;

  case 15:
#line 146 "parser.y"
    { (yyval.idlistptr) = (yyvsp[(1) - (1)].idlistptr); }
    break;

  case 16:
#line 150 "parser.y"
    { lptr = Attach((yyvsp[(1) - (3)].idlistptr), (yyvsp[(3) - (3)].idlistptr)); (yyval.idlistptr) = lptr; }
    break;

  case 17:
#line 151 "parser.y"
    { (yyval.idlistptr) = (yyvsp[(1) - (1)].idlistptr); }
    break;

  case 18:
#line 155 "parser.y"
    { lptr = NewListNode((yyvsp[(2) - (2)].chptr), (yyvsp[(1) - (2)].nval), false); (yyval.idlistptr) = lptr; }
    break;

  case 19:
#line 156 "parser.y"
    { lptr = NewListNode((yyvsp[(2) - (4)].chptr), (yyvsp[(1) - (4)].nval), true); (yyval.idlistptr) = lptr; }
    break;

  case 20:
#line 161 "parser.y"
    { (yyval.nval) = CurrType = t_Int; }
    break;

  case 21:
#line 162 "parser.y"
    { (yyval.nval) = CurrType = t_Char; }
    break;

  case 22:
#line 163 "parser.y"
    { (yyval.nval) = CurrType = t_None; }
    break;

  case 26:
#line 176 "parser.y"
    {yyerrok;}
    break;

  case 28:
#line 177 "parser.y"
    {yyerrok;}
    break;

  case 31:
#line 182 "parser.y"
    { 
    if (CurrType == t_None) {
      errmsg("Illegal type [void] for variable %s", id_name);
    }
    else {
      stptr = SymTabInsert(id_name, CurrScope); 
      stptr->type = CurrType;
      stptr->formal = stptr->is_extern = false;
      stptr->elt_type = t_None;
    }
  }
    break;

  case 32:
#line 193 "parser.y"
    { 
    if (CurrType == t_None) {
      errmsg("Illegal type [void] for variable %s", id_name);
    }
    else {
      stptr = SymTabInsert(id_name, CurrScope);
      stptr->type = t_Array;
      stptr->formal = false;
      stptr->elt_type = CurrType;
      stptr->num_elts = (yyvsp[(3) - (4)].nval);
    }
  }
    break;

  case 33:
#line 207 "parser.y"
    { (yyval.nval) = atoi(yytext); }
    break;

  case 34:
#line 211 "parser.y"
    { (yyval.tptr) = mkListNode((yyvsp[(1) - (2)].tptr), (yyvsp[(2) - (2)].tptr)); }
    break;

  case 35:
#line 212 "parser.y"
    { (yyval.tptr) = NULL; }
    break;

  case 36:
#line 216 "parser.y"
    {
      if ((yyvsp[(3) - (6)].tptr)->etype != t_Bool && (yyvsp[(3) - (6)].tptr)->etype != t_Error) {
        errmsg("conditional does not have Boolean type");
      }
      (yyval.tptr) = mkSTNode(If, t_None, (yyvsp[(3) - (6)].tptr), (yyvsp[(5) - (6)].tptr), (yyvsp[(6) - (6)].tptr), NULL);
    }
    break;

  case 37:
#line 222 "parser.y"
    {
      if ((yyvsp[(3) - (5)].tptr)->etype != t_Bool && (yyvsp[(3) - (5)].tptr)->etype != t_Error) {
        errmsg("conditional does not have Boolean type");
      }
      (yyval.tptr) = mkSTNode(While, t_None, (yyvsp[(3) - (5)].tptr), (yyvsp[(5) - (5)].tptr), NULL, NULL);
    }
    break;

  case 38:
#line 228 "parser.y"
    {
      if ((yyvsp[(5) - (9)].tptr) != NULL && (yyvsp[(5) - (9)].tptr)->etype != t_Bool && (yyvsp[(5) - (9)].tptr)->etype != t_Error) {
        errmsg("conditional does not have Boolean type");
      }
      (yyval.tptr) = mkSTNode(For, t_None, (yyvsp[(3) - (9)].tptr), (yyvsp[(5) - (9)].tptr), (yyvsp[(7) - (9)].tptr), (yyvsp[(9) - (9)].tptr));
    }
    break;

  case 39:
#line 234 "parser.y"
    {
      if (currFun->ret_type != t_None) {
	if ((yyvsp[(2) - (3)].tptr) == NULL) {
	  errmsg("return with no return value in non-void function");
          (yyval.tptr) = mkErrorNode();
	}
	else if ( !((yyvsp[(2) - (3)].tptr)->etype == t_Int || (yyvsp[(2) - (3)].tptr)->etype == t_Char || (yyvsp[(2) - (3)].tptr)->etype == t_Error) ) {
	  errmsg("illegal return type");
          (yyval.tptr) = mkErrorNode();
	}
	else {
	  (yyval.tptr) = mkSTNode(Return, (yyvsp[(2) - (3)].tptr)->etype, (yyvsp[(2) - (3)].tptr), NULL, NULL, NULL);
	}
      }
      else {
	if ((yyvsp[(2) - (3)].tptr) != NULL) {    /* there is a return expression  */
	  errmsg("non-void return expression in function with no return value");
          (yyval.tptr) = mkErrorNode();
	}
	else {
	  (yyval.tptr) = mkSTNode(Return, t_None, NULL, NULL, NULL, NULL);
	}
      }
    }
    break;

  case 40:
#line 258 "parser.y"
    { (yyval.tptr) = (yyvsp[(1) - (2)].tptr); }
    break;

  case 41:
#line 259 "parser.y"
    { (yyval.tptr) = (yyvsp[(1) - (2)].tptr); }
    break;

  case 42:
#line 260 "parser.y"
    { (yyval.tptr) = (yyvsp[(1) - (1)].tptr); }
    break;

  case 43:
#line 261 "parser.y"
    { (yyval.tptr) = NULL; }
    break;

  case 44:
#line 262 "parser.y"
    { (yyval.tptr) = mkErrorNode(); }
    break;

  case 46:
#line 271 "parser.y"
    {errstate = NOSEMICOLON;}
    break;

  case 49:
#line 276 "parser.y"
    {errstate = NOCOMMA;}
    break;

  case 51:
#line 280 "parser.y"
    { (yyval.tptr) = (yyvsp[(2) - (3)].tptr); }
    break;

  case 52:
#line 284 "parser.y"
    { (yyval.tptr) = (yyvsp[(2) - (2)].tptr); }
    break;

  case 53:
#line 285 "parser.y"
    { (yyval.tptr) = NULL; }
    break;

  case 54:
#line 289 "parser.y"
    { (yyval.tptr) = (yyvsp[(1) - (1)].tptr); }
    break;

  case 55:
#line 290 "parser.y"
    { (yyval.tptr) = NULL; }
    break;

  case 56:
#line 294 "parser.y"
    { (yyval.tptr) = (yyvsp[(1) - (1)].tptr); }
    break;

  case 57:
#line 295 "parser.y"
    { (yyval.tptr) = NULL; }
    break;

  case 58:
#line 299 "parser.y"
    { (yyval.tptr) = (yyvsp[(1) - (1)].tptr); }
    break;

  case 59:
#line 300 "parser.y"
    { (yyval.tptr) = NULL; }
    break;

  case 60:
#line 304 "parser.y"
    {
    if ((yyvsp[(1) - (3)].tptr)->ntype == Error) {
      (yyval.tptr) = (yyvsp[(1) - (3)].tptr);
    }
    else if ((yyvsp[(3) - (3)].tptr)->ntype == Error) {
      (yyval.tptr) = (yyvsp[(3) - (3)].tptr);
    }
    else if (!((yyvsp[(1) - (3)].tptr)->etype == t_Int || (yyvsp[(1) - (3)].tptr)->etype == t_Char)) {
      errmsg("invalid LHS in assignment");
      (yyval.tptr) = mkErrorNode();
    }
    else if (!((yyvsp[(3) - (3)].tptr)->etype == t_Int || (yyvsp[(3) - (3)].tptr)->etype == t_Char)) {
      errmsg("invalid RHS in assignment");
      (yyval.tptr) = mkErrorNode();
    }
    else {
      (yyval.tptr) = mkExprNode(Assg, t_None, (yyvsp[(1) - (3)].tptr), (yyvsp[(3) - (3)].tptr));
    }
  }
    break;

  case 61:
#line 326 "parser.y"
    { (yyval.tptr) = SynTreeBinExp(Equals, (yyvsp[(1) - (3)].tptr), (yyvsp[(3) - (3)].tptr)); }
    break;

  case 62:
#line 327 "parser.y"
    { (yyval.tptr) = SynTreeBinExp(Neq, (yyvsp[(1) - (3)].tptr), (yyvsp[(3) - (3)].tptr)); }
    break;

  case 63:
#line 328 "parser.y"
    { (yyval.tptr) = SynTreeBinExp(Leq, (yyvsp[(1) - (3)].tptr), (yyvsp[(3) - (3)].tptr)); }
    break;

  case 64:
#line 329 "parser.y"
    { (yyval.tptr) = SynTreeBinExp(Geq, (yyvsp[(1) - (3)].tptr), (yyvsp[(3) - (3)].tptr)); }
    break;

  case 65:
#line 330 "parser.y"
    { (yyval.tptr) = SynTreeBinExp(Lt, (yyvsp[(1) - (3)].tptr), (yyvsp[(3) - (3)].tptr)); }
    break;

  case 66:
#line 331 "parser.y"
    { (yyval.tptr) = SynTreeBinExp(Gt, (yyvsp[(1) - (3)].tptr), (yyvsp[(3) - (3)].tptr)); }
    break;

  case 67:
#line 332 "parser.y"
    { (yyval.tptr) = SynTreeUnExp(LogicalNot, (yyvsp[(2) - (2)].tptr)); }
    break;

  case 68:
#line 333 "parser.y"
    { (yyval.tptr) = SynTreeBinExp(LogicalAnd, (yyvsp[(1) - (3)].tptr), (yyvsp[(3) - (3)].tptr)); }
    break;

  case 69:
#line 334 "parser.y"
    { (yyval.tptr) = SynTreeBinExp(LogicalOr, (yyvsp[(1) - (3)].tptr), (yyvsp[(3) - (3)].tptr)); }
    break;

  case 70:
#line 335 "parser.y"
    { (yyval.tptr) = (yyvsp[(2) - (3)].tptr); }
    break;

  case 71:
#line 339 "parser.y"
    { (yyval.tptr) = SynTreeUnExp(UnaryMinus, (yyvsp[(2) - (2)].tptr)); }
    break;

  case 72:
#line 340 "parser.y"
    { (yyval.tptr) = SynTreeBinExp(Plus, (yyvsp[(1) - (3)].tptr), (yyvsp[(3) - (3)].tptr)); }
    break;

  case 73:
#line 341 "parser.y"
    { (yyval.tptr) = SynTreeBinExp(BinaryMinus, (yyvsp[(1) - (3)].tptr), (yyvsp[(3) - (3)].tptr)); }
    break;

  case 74:
#line 342 "parser.y"
    { (yyval.tptr) = SynTreeBinExp(Mult, (yyvsp[(1) - (3)].tptr), (yyvsp[(3) - (3)].tptr)); }
    break;

  case 75:
#line 343 "parser.y"
    { (yyval.tptr) = SynTreeBinExp(Div, (yyvsp[(1) - (3)].tptr), (yyvsp[(3) - (3)].tptr)); }
    break;

  case 76:
#line 344 "parser.y"
    { (yyval.tptr) = (yyvsp[(1) - (1)].tptr); }
    break;

  case 77:
#line 345 "parser.y"
    { (yyval.tptr) = (yyvsp[(1) - (1)].tptr); }
    break;

  case 78:
#line 346 "parser.y"
    { (yyval.tptr) = (yyvsp[(2) - (3)].tptr); }
    break;

  case 79:
#line 347 "parser.y"
    { (yyval.tptr) = mkErrorNode(); }
    break;

  case 80:
#line 348 "parser.y"
    { (yyval.tptr) = mkConstNode(Intcon, t_Int, ival); }
    break;

  case 81:
#line 349 "parser.y"
    { (yyval.tptr) = mkConstNode(Charcon, t_Char, ival); }
    break;

  case 82:
#line 350 "parser.y"
    { yytext[strlen(yytext)-1] = '\0'; /* to remove the trailing " */
               (yyval.tptr) = mkStrNode(strdup(yytext+1)); }
    break;

  case 83:
#line 355 "parser.y"
    {
      bool err_occurred = false;
      stptr = SymTabLookupAll((yyvsp[(1) - (3)].chptr));
      if (stptr == NULL) {
	err_occurred = true;
        errmsg("%s undeclared", (yyvsp[(1) - (3)].chptr));
      }
      else {
        if (stptr->type != t_Func) {
	  err_occurred = true;
	  errmsg("%s is not a function", (yyvsp[(1) - (3)].chptr));
        }
        else {
	  err_occurred = !ActualsMatchFormals(stptr, NULL);
        }
      }

      if (!err_occurred) {
	(yyval.tptr) = mkSymTabRefNode(FunCall, stptr->ret_type, stptr, NULL);
      }
      else {
	(yyval.tptr) = mkErrorNode();
      }
    }
    break;

  case 84:
#line 379 "parser.y"
    {
      bool err_occurred = false;
      stptr = SymTabLookupAll((yyvsp[(1) - (4)].chptr));
      if (stptr == NULL) {
	err_occurred = true;
        errmsg("%s undeclared", (yyvsp[(1) - (4)].chptr));
      }
      else if (stptr->type != t_Func) {
	err_occurred = true;
        errmsg("%s is not a function", (yyvsp[(1) - (4)].chptr));
      }
      else {
	err_occurred = !ActualsMatchFormals(stptr, (yyvsp[(3) - (4)].tptr));
      }

      if (!err_occurred) {
	(yyval.tptr) = mkSymTabRefNode(FunCall, stptr->ret_type, stptr, (yyvsp[(3) - (4)].tptr));
      }
      else {
	(yyval.tptr) = mkErrorNode();
      }
    }
    break;

  case 85:
#line 401 "parser.y"
    {
      stptr = SymTabLookupAll((yyvsp[(1) - (4)].chptr));
      if (stptr == NULL) {
        errmsg("undeclared identifier %s", (yyvsp[(1) - (4)].chptr));
      }

      (yyval.tptr) = mkErrorNode();
    }
    break;

  case 86:
#line 412 "parser.y"
    {
      bool err_occurred = false;
      stptr = SymTabLookupAll((yyvsp[(1) - (3)].chptr));
      if (stptr == NULL) {
        errmsg("undeclared identifier %s", (yyvsp[(1) - (3)].chptr));
        (yyval.tptr) = mkErrorNode();
      }
      else if (stptr->type != t_Func) {
	err_occurred = true;
        errmsg("%s is not a function", (yyvsp[(1) - (3)].chptr));
      }
      else if (stptr->ret_type != t_None) {
	err_occurred = true;
	errmsg("non-VOID function %s used in a statement", (yyvsp[(1) - (3)].chptr));
      }
      else {
	err_occurred = !ActualsMatchFormals(stptr, NULL);
      }

      if (!err_occurred) {
	(yyval.tptr) = mkSymTabRefNode(FunCall, stptr->ret_type, stptr, NULL);
      }
      else {
	(yyval.tptr) = mkErrorNode();
      }
    }
    break;

  case 87:
#line 438 "parser.y"
    {
      bool err_occurred = false;
      stptr = SymTabLookupAll((yyvsp[(1) - (4)].chptr));
      if (stptr == NULL) {
        errmsg("undeclared identifier %s", (yyvsp[(1) - (4)].chptr));
        (yyval.tptr) = mkErrorNode();
      }
      else if (stptr->type != t_Func) {
	err_occurred = true;
        errmsg("%s is not a function", (yyvsp[(1) - (4)].chptr));
      }
      else if (stptr->ret_type != t_None) {
	err_occurred = true;
	errmsg("non-VOID function %s used in a statement", (yyvsp[(1) - (4)].chptr));
      }
      else {
	err_occurred = !ActualsMatchFormals(stptr, (yyvsp[(3) - (4)].tptr));
      }

      if (!err_occurred) {
	(yyval.tptr) = mkSymTabRefNode(FunCall, stptr->ret_type, stptr, (yyvsp[(3) - (4)].tptr));
      }
      else {
	(yyval.tptr) = mkErrorNode();
      }
    }
    break;

  case 88:
#line 464 "parser.y"
    {
    stptr = SymTabLookupAll((yyvsp[(1) - (4)].chptr));
    if (stptr == NULL) {
      errmsg("undeclared identifier %s", (yyvsp[(1) - (4)].chptr));
    }

    (yyval.tptr) = mkErrorNode();
  }
    break;

  case 89:
#line 475 "parser.y"
    { 
	stptr = SymTabLookupAll((yyvsp[(1) - (1)].chptr));
	if (stptr == NULL) {
	  errmsg("Undeclared variable: %s", (yyvsp[(1) - (1)].chptr));
	  (yyval.tptr) = mkErrorNode();
	}
	else {
	  (yyval.tptr) = mkSymTabRefNode(Var, stptr->type, stptr, NULL);
	}
    }
    break;

  case 90:
#line 485 "parser.y"
    {
	bool err_occurred = false;

	stptr = SymTabLookupAll((yyvsp[(1) - (4)].chptr));

	if (stptr == NULL) {
	  errmsg("Undeclared variable: %s", (yyvsp[(1) - (4)].chptr));
	  err_occurred = true;
	}
	else if (stptr->type != t_Array) {
	  errmsg("%s not declared as an array", (yyvsp[(1) - (4)].chptr));
	  err_occurred = true;
	}
	if ( !((yyvsp[(3) - (4)].tptr)->etype == t_Int || (yyvsp[(3) - (4)].tptr)->etype == t_Char) ) {
	  if ((yyvsp[(3) - (4)].tptr)->etype != t_Error) {
	    errmsg("subscript to array %s must be of type int or char", (yyvsp[(1) - (4)].chptr));
	    err_occurred = 1;
	  }
	}

	if (err_occurred) {
	  (yyval.tptr) = mkErrorNode();
	}
	else {
	  (yyval.tptr) = mkSymTabRefNode(ArraySubscript, stptr->elt_type, stptr, (yyvsp[(3) - (4)].tptr));
	}
    }
    break;

  case 91:
#line 512 "parser.y"
    {
	stptr = SymTabLookupAll((yyvsp[(1) - (4)].chptr));

	if (stptr == NULL) {
	  errmsg("Undeclared variable: %s", (yyvsp[(1) - (4)].chptr));
	}
	else if (stptr->type != t_Array) {
	  errmsg("%s not declared as an array", (yyvsp[(1) - (4)].chptr));
	}

	(yyval.tptr) = mkErrorNode();
    }
    break;

  case 92:
#line 527 "parser.y"
    { (yyval.tptr) = mkListNode((yyvsp[(1) - (3)].tptr), (yyvsp[(3) - (3)].tptr)); }
    break;

  case 93:
#line 528 "parser.y"
    { (yyval.tptr) = mkListNode((yyvsp[(1) - (1)].tptr), NULL); }
    break;

  case 94:
#line 531 "parser.y"
    { (yyval.chptr) = id_name; }
    break;


/* Line 1267 of yacc.c.  */
#line 2230 "y.tab.c"
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


#line 533 "parser.y"



