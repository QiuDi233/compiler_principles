/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "/root/sysy-cmake-template/src/sysy.y"


#include <iostream>
#include <memory>
#include <string>
#include "AST.h"

// 声明 lexer 函数和错误处理函数
int yylex();
void yyerror(std::unique_ptr<BaseAST> &ast, const char *s);

using namespace std;


#line 85 "/root/sysy-cmake-template/build/sysy.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_ROOT_SYSY_CMAKE_TEMPLATE_BUILD_SYSY_TAB_HPP_INCLUDED
# define YY_YY_ROOT_SYSY_CMAKE_TEMPLATE_BUILD_SYSY_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "/root/sysy-cmake-template/src/sysy.y"

  #include <memory>
  #include <string>
  #include "AST.h"

#line 134 "/root/sysy-cmake-template/build/sysy.tab.cpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    VOID = 259,
    RETURN = 260,
    CONST = 261,
    IDENT = 262,
    INT_CONST = 263,
    OR = 264,
    AND = 265,
    EQ = 266,
    NE = 267,
    LE = 268,
    GE = 269,
    IF = 270,
    ELSE = 271,
    WHILE = 272,
    BREAK = 273,
    CONTINUE = 274
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "/root/sysy-cmake-template/src/sysy.y"

  std::string *str_val;
  int int_val;
  BaseAST *ast_val;
  std::vector<std::unique_ptr<BaseAST>> *vec_val;

#line 172 "/root/sysy-cmake-template/build/sysy.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (std::unique_ptr<BaseAST> &ast);

#endif /* !YY_YY_ROOT_SYSY_CMAKE_TEMPLATE_BUILD_SYSY_TAB_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   217

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

#define YYUNDEFTOK  2
#define YYMAXUTOK   274


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,     2,     2,    35,     2,     2,
      20,    21,    33,    31,    22,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
      29,    27,    30,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    23,     2,    24,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,     2,    26,     2,     2,     2,     2,
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    53,    53,    60,    66,    72,    78,    87,    94,   109,
     114,   122,   127,   135,   142,   152,   162,   166,   174,   180,
     189,   193,   200,   207,   213,   219,   225,   231,   239,   246,
     251,   259,   266,   277,   283,   289,   298,   309,   314,   322,
     328,   340,   345,   353,   359,   364,   375,   380,   389,   397,
     409,   414,   422,   428,   435,   444,   457,   463,   468,   479,
     484,   492,   500,   507,   514,   518,   525,   529,   533,   537,
     544,   548,   555,   559,   563,   570,   574,   578,   585,   591,
     602,   608,   619,   625,   636,   642,   653,   659,   670,   676,
     687,   693,   700,   706,   718,   723,   732,   738,   744,   753,
     758,   769,   774,   782
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "VOID", "RETURN", "CONST",
  "IDENT", "INT_CONST", "OR", "AND", "EQ", "NE", "LE", "GE", "IF", "ELSE",
  "WHILE", "BREAK", "CONTINUE", "'('", "')'", "','", "'['", "']'", "'{'",
  "'}'", "'='", "';'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'!'", "$accept", "CompUnit", "CompUnitList", "FuncDef", "FuncType",
  "FuncFParams", "FuncFParam", "Block", "BlockItemList", "BlockItem",
  "Stmt", "EndStmt", "NotEndStmt", "Number", "Decl", "ConstDecl",
  "ConstDefList", "ConstDef", "ConstExpList", "ConstInitVal",
  "ConstInitValList", "ConstExp", "VarDecl", "VarDefList", "VarDef",
  "InitVal", "InitValList", "Exp", "LOROP", "LANDOP", "EQOP", "RELOP",
  "ADDOP", "MULOP", "UNARYOP", "LOrExp", "LAndExp", "EqExp", "RelExp",
  "AddExp", "MulExp", "UnaryExp", "FuncRParams", "PrimaryExp", "LVal",
  "ExpList", "BType", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      40,    41,    44,    91,    93,   123,   125,    61,    59,    60,
      62,    43,    45,    42,    47,    37,    33
};
# endif

#define YYPACT_NINF (-105)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     101,  -105,  -105,    51,    61,   101,  -105,    74,  -105,  -105,
    -105,  -105,    99,  -105,  -105,  -105,    30,    23,  -105,    -3,
      36,  -105,    16,    10,   157,    11,   110,  -105,   167,    29,
      99,  -105,    93,   -10,  -105,   112,     9,  -105,    10,  -105,
    -105,  -105,  -105,   102,  -105,    10,   120,   124,    83,    70,
      55,    81,  -105,  -105,  -105,   135,  -105,  -105,    10,   157,
      49,  -105,   137,  -105,  -105,   167,  -105,  -105,  -105,    93,
      51,   115,   176,    10,   125,   114,  -105,  -105,  -105,    10,
    -105,    10,  -105,  -105,    10,  -105,  -105,  -105,  -105,    10,
    -105,  -105,    10,  -105,  -105,  -105,    10,  -105,  -105,    67,
     126,  -105,  -105,  -105,    75,  -105,   105,  -105,  -105,   128,
    -105,  -105,     0,   130,    10,  -105,   124,    83,    70,    55,
      81,  -105,   157,  -105,  -105,   167,  -105,    10,   129,   136,
     131,   142,  -105,  -105,   110,  -105,  -105,  -105,  -105,  -105,
    -105,   144,   149,  -105,  -105,    10,  -105,   134,  -105,  -105,
     150,    10,    10,  -105,  -105,  -105,    10,  -105,  -105,  -105,
     158,   159,   153,     8,    60,  -105,  -105,   169,   166,  -105,
       8,    10,  -105,  -105,   170,    60,   174,    60
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    10,     0,     0,     2,     3,     0,     5,    34,
      35,   103,     0,     1,     4,     6,    52,     0,    50,     0,
       0,    37,     0,     0,     0,    54,     0,    49,     0,     0,
       0,    36,     0,     0,    11,     0,    99,    33,     0,    75,
      76,    77,    98,     0,    48,     0,    61,    78,    80,    82,
      84,    86,    88,    90,    97,     0,    53,    56,     0,     0,
      52,    51,     0,    39,    43,     0,    38,    16,     7,     0,
       0,    13,     0,     0,   100,     0,    41,    91,    62,     0,
      63,     0,    64,    65,     0,    68,    69,    66,    67,     0,
      70,    71,     0,    72,    73,    74,     0,    57,    59,     0,
       0,    55,    44,    46,     0,    40,     0,     8,    12,     0,
      92,    94,     0,     0,     0,    96,    79,    81,    83,    85,
      87,    89,     0,    58,    42,     0,    45,     0,     0,     0,
       0,     0,    15,    24,     0,    25,    17,    19,    20,    21,
      18,     0,    97,    14,    93,     0,   101,     0,    60,    47,
       0,     0,     0,    29,    30,    23,     0,    95,   102,    26,
       0,     0,     0,     0,     0,    22,    31,    20,     0,    28,
       0,     0,    27,    32,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -105,  -105,  -105,   189,    89,  -105,   132,   -22,  -105,  -105,
      37,  -101,    31,  -105,    -4,  -105,  -105,   175,   185,   -56,
    -105,   -15,  -105,  -105,   180,   -52,  -105,   -24,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,   138,   133,   127,   121,
     117,   -41,  -105,  -105,  -104,  -105,   210
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    33,    34,   135,   106,   136,
     137,   172,   139,    42,     8,     9,    20,    21,    25,    63,
     104,    64,    10,    17,    18,    56,    99,    44,    79,    81,
      84,    89,    92,    96,    45,    46,    47,    48,    49,    50,
      51,    52,   112,    53,    54,    74,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    15,   142,    98,    77,   138,   103,   101,    43,   105,
      68,    69,    70,   127,    75,    36,    37,    36,    37,    11,
      23,   144,   145,   128,    28,   129,   130,   131,    38,    72,
      38,    57,    73,    67,    58,    57,   133,    32,    59,    39,
      40,    39,    40,   100,    41,    26,    41,   107,   111,   113,
      22,    27,    58,    23,    11,   121,    65,    24,    30,   142,
     142,    13,   167,   169,    31,   127,   142,    36,    37,   149,
     148,   142,    23,   142,   176,   168,    24,   129,   130,   131,
      38,    16,   141,    85,    86,    67,    90,    91,   133,   122,
     147,    39,    40,   123,    82,    83,    41,   125,    57,    87,
      88,   126,   140,   150,     1,     2,    19,     3,     1,     2,
     127,     3,    36,    37,    93,    94,    95,    60,    67,    71,
     128,   157,   129,   130,   131,    38,    76,   160,   161,    78,
      67,   132,   162,   133,    80,   115,    39,    40,   109,   141,
     141,    41,    36,    37,    36,    37,   141,   174,   114,   151,
     124,   141,   143,   141,   146,    38,   152,    38,   158,   153,
      55,    97,    62,   102,    36,    37,    39,    40,    39,    40,
     154,    41,   155,    41,    36,    37,   156,    38,   159,   163,
     164,   165,    55,    36,    37,   170,   171,    38,    39,    40,
     177,   175,    62,    41,    14,   134,    38,   110,    39,    40,
     166,   173,   108,    41,    29,    66,    61,    39,    40,   120,
     119,   118,    41,    12,   117,     0,     0,   116
};

static const yytype_int16 yycheck[] =
{
      24,     5,   106,    55,    45,   106,    62,    59,    23,    65,
      32,    21,    22,     5,    38,     7,     8,     7,     8,     3,
      23,    21,    22,    15,    27,    17,    18,    19,    20,    20,
      20,    55,    23,    25,    23,    59,    28,    21,    27,    31,
      32,    31,    32,    58,    36,    22,    36,    69,    72,    73,
      20,    28,    23,    23,     3,    96,    27,    27,    22,   163,
     164,     0,   163,   164,    28,     5,   170,     7,     8,   125,
     122,   175,    23,   177,   175,    15,    27,    17,    18,    19,
      20,     7,   106,    13,    14,    25,    31,    32,    28,    22,
     114,    31,    32,    26,    11,    12,    36,    22,   122,    29,
      30,    26,   106,   127,     3,     4,     7,     6,     3,     4,
       5,     6,     7,     8,    33,    34,    35,     7,    25,     7,
      15,   145,    17,    18,    19,    20,    24,   151,   152,     9,
      25,    26,   156,    28,    10,    21,    31,    32,    23,   163,
     164,    36,     7,     8,     7,     8,   170,   171,    23,    20,
      24,   175,    24,   177,    24,    20,    20,    20,    24,    28,
      25,    26,    25,    26,     7,     8,    31,    32,    31,    32,
      28,    36,    28,    36,     7,     8,    27,    20,    28,    21,
      21,    28,    25,     7,     8,    16,    20,    20,    31,    32,
      16,    21,    25,    36,     5,   106,    20,    21,    31,    32,
     163,   170,    70,    36,    19,    30,    26,    31,    32,    92,
      89,    84,    36,     3,    81,    -1,    -1,    79
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     6,    38,    39,    40,    41,    51,    52,
      59,     3,    83,     0,    40,    51,     7,    60,    61,     7,
      53,    54,    20,    23,    27,    55,    22,    28,    27,    55,
      22,    28,    21,    42,    43,    83,     7,     8,    20,    31,
      32,    36,    50,    58,    64,    71,    72,    73,    74,    75,
      76,    77,    78,    80,    81,    25,    62,    64,    23,    27,
       7,    61,    25,    56,    58,    27,    54,    25,    44,    21,
      22,     7,    20,    23,    82,    64,    24,    78,     9,    65,
      10,    66,    11,    12,    67,    13,    14,    29,    30,    68,
      31,    32,    69,    33,    34,    35,    70,    26,    62,    63,
      58,    62,    26,    56,    57,    56,    45,    44,    43,    23,
      21,    64,    79,    64,    23,    21,    73,    74,    75,    76,
      77,    78,    22,    26,    24,    22,    26,     5,    15,    17,
      18,    19,    26,    28,    41,    44,    46,    47,    48,    49,
      51,    64,    81,    24,    21,    22,    24,    64,    62,    56,
      64,    20,    20,    28,    28,    28,    27,    64,    24,    28,
      64,    64,    64,    21,    21,    28,    47,    48,    15,    48,
      16,    20,    48,    49,    64,    21,    48,    16
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    39,    39,    40,    40,    41,
      41,    42,    42,    43,    43,    44,    45,    45,    46,    46,
      47,    47,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    49,    49,    50,    51,    51,    52,    53,    53,    54,
      54,    55,    55,    56,    56,    56,    57,    57,    58,    59,
      60,    60,    61,    61,    61,    61,    62,    62,    62,    63,
      63,    64,    65,    66,    67,    67,    68,    68,    68,    68,
      69,    69,    70,    70,    70,    71,    71,    71,    72,    72,
      73,    73,    74,    74,    75,    75,    76,    76,    77,    77,
      78,    78,    78,    78,    79,    79,    80,    80,    80,    81,
      81,    82,    82,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     5,     6,     1,
       1,     1,     3,     2,     4,     3,     0,     2,     1,     1,
       1,     1,     4,     2,     1,     1,     3,     7,     5,     2,
       2,     5,     7,     1,     1,     1,     4,     1,     3,     3,
       4,     3,     4,     1,     2,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     2,     4,     1,     2,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     2,     3,     4,     1,     3,     3,     1,     1,     1,
       2,     3,     4,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        yyerror (ast, YY_("syntax error: cannot back up")); \
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
                  Type, Value, ast); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, std::unique_ptr<BaseAST> &ast)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (ast);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, std::unique_ptr<BaseAST> &ast)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, ast);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, std::unique_ptr<BaseAST> &ast)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              , ast);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, ast); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, std::unique_ptr<BaseAST> &ast)
{
  YYUSE (yyvaluep);
  YYUSE (ast);
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
yyparse (std::unique_ptr<BaseAST> &ast)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 53 "/root/sysy-cmake-template/src/sysy.y"
                 {
    auto comp_unit = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    ast = move(comp_unit);
  }
#line 1486 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 3:
#line 60 "/root/sysy-cmake-template/src/sysy.y"
            {
    auto comp_unit = new CompUnitAST();
    auto func_def = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    comp_unit->func_def_list.push_back(move(func_def));
    (yyval.ast_val) = comp_unit;
  }
#line 1497 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 4:
#line 66 "/root/sysy-cmake-template/src/sysy.y"
                         {
    auto comp_unit = (CompUnitAST*)((yyvsp[-1].ast_val));
    auto func_def = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    comp_unit->func_def_list.push_back(move(func_def));
    (yyval.ast_val) = comp_unit;
  }
#line 1508 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 5:
#line 72 "/root/sysy-cmake-template/src/sysy.y"
         {
    auto comp_unit = new CompUnitAST();
    auto decl = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    comp_unit->decl_list.push_back(move(decl));
    (yyval.ast_val) = comp_unit;
  }
#line 1519 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 6:
#line 78 "/root/sysy-cmake-template/src/sysy.y"
                      {
    auto comp_unit = (CompUnitAST*)((yyvsp[-1].ast_val));
    auto decl = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    comp_unit->decl_list.push_back(move(decl));
    (yyval.ast_val) = comp_unit;
  }
#line 1530 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 7:
#line 87 "/root/sysy-cmake-template/src/sysy.y"
                                 {
    auto ast = new FuncDefAST();
    ast->func_type = unique_ptr<BaseAST>((yyvsp[-4].ast_val));
    ast->ident = *unique_ptr<string>((yyvsp[-3].str_val));
    ast->block = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1542 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 8:
#line 94 "/root/sysy-cmake-template/src/sysy.y"
                                             {
    auto ast = new FuncDefAST();
    ast->func_type = unique_ptr<BaseAST>((yyvsp[-5].ast_val));
    ast->ident = *unique_ptr<string>((yyvsp[-4].str_val));
    vector<unique_ptr<BaseAST>> *list = ((yyvsp[-2].vec_val));
    for (auto it = list->begin(); it != list->end(); it++)
        ast->func_f_params.push_back(move(*it));
    ast->block = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    ((BlockAST*)(ast->block).get())->func_ident = ast->ident;
    (yyval.ast_val) = ast;
  }
#line 1558 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 9:
#line 109 "/root/sysy-cmake-template/src/sysy.y"
        {
    auto ast = new FuncTypeAST();
    ast->type = "int";
    (yyval.ast_val) = ast;
  }
#line 1568 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 10:
#line 114 "/root/sysy-cmake-template/src/sysy.y"
         {
    auto ast = new FuncTypeAST();
    ast->type = "void";
    (yyval.ast_val) = ast;
  }
#line 1578 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 11:
#line 122 "/root/sysy-cmake-template/src/sysy.y"
               {
      vector<unique_ptr<BaseAST>> *list = new vector<unique_ptr<BaseAST>>;
      list->push_back(unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.vec_val) = list;
  }
#line 1588 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 12:
#line 127 "/root/sysy-cmake-template/src/sysy.y"
                               {
      vector<unique_ptr<BaseAST>> *list = ((yyvsp[-2].vec_val));
      list->push_back(unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.vec_val) = list;
  }
#line 1598 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 13:
#line 135 "/root/sysy-cmake-template/src/sysy.y"
                {
      auto ast = new FuncFParamAST();
      ast->type = FuncFParamType::var;
      ast->b_type = *unique_ptr<string>((yyvsp[-1].str_val));
      ast->ident = *unique_ptr<string>((yyvsp[0].str_val));
      (yyval.ast_val) = ast;
  }
#line 1610 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 14:
#line 142 "/root/sysy-cmake-template/src/sysy.y"
                        {
      auto ast = new FuncFParamAST();
      ast->type = FuncFParamType::arr;
      ast->b_type = *unique_ptr<string>((yyvsp[-3].str_val));
      ast->ident = *unique_ptr<string>((yyvsp[-2].str_val));
      (yyval.ast_val) = ast;
    }
#line 1622 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 15:
#line 152 "/root/sysy-cmake-template/src/sysy.y"
                          {
    auto block = new BlockAST();
    vector<unique_ptr<BaseAST>> *list = ((yyvsp[-1].vec_val));
    for (auto it = list->begin(); it != list->end(); it++)
        block->block_item_list.push_back(move(*it));
    (yyval.ast_val) = block;
  }
#line 1634 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 16:
#line 162 "/root/sysy-cmake-template/src/sysy.y"
    {
      vector<unique_ptr<BaseAST>> *list = new vector<unique_ptr<BaseAST>>;
      (yyval.vec_val) = list;
  }
#line 1643 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 17:
#line 166 "/root/sysy-cmake-template/src/sysy.y"
                            {
      vector<unique_ptr<BaseAST>> *list = ((yyvsp[-1].vec_val));
      list->push_back(unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.vec_val) = list;
  }
#line 1653 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 18:
#line 174 "/root/sysy-cmake-template/src/sysy.y"
         {
    auto ast = new BlockItemAST();
    ast->type = BlockItemType::decl;
    ast->decl = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1664 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 19:
#line 180 "/root/sysy-cmake-template/src/sysy.y"
         {
    auto ast = new BlockItemAST();
    ast->type = BlockItemType::stmt;
    ast->stmt = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1675 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 20:
#line 189 "/root/sysy-cmake-template/src/sysy.y"
            {
      auto ast = ((yyvsp[0].ast_val));
      (yyval.ast_val) = ast;
  }
#line 1684 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 21:
#line 193 "/root/sysy-cmake-template/src/sysy.y"
               {
      auto ast = ((yyvsp[0].ast_val));
      (yyval.ast_val) = ast;
  }
#line 1693 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 22:
#line 200 "/root/sysy-cmake-template/src/sysy.y"
                     {
    auto ast = new StmtAST();
    ast->type = StmtType::lval;
    ast->lval = unique_ptr<BaseAST>((yyvsp[-3].ast_val));
    ast->exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1705 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 23:
#line 207 "/root/sysy-cmake-template/src/sysy.y"
            {
    auto ast = new StmtAST();
    ast->type = StmtType::exp;
    ast->exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1716 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 24:
#line 213 "/root/sysy-cmake-template/src/sysy.y"
        {
    auto ast = new StmtAST();
    ast->type = StmtType::exp;
    ast->exp = nullptr;
    (yyval.ast_val) = ast;
  }
#line 1727 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 25:
#line 219 "/root/sysy-cmake-template/src/sysy.y"
          {
    auto ast = new StmtAST();
    ast->type = StmtType::block;
    ast->block = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1738 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 26:
#line 225 "/root/sysy-cmake-template/src/sysy.y"
                   {
    auto ast = new StmtAST();
    ast->type = StmtType::ret;
    ast->exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1749 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 27:
#line 231 "/root/sysy-cmake-template/src/sysy.y"
                                        {
      auto ast = new StmtAST();
      ast->type = StmtType::if_else;
      ast->exp = unique_ptr<BaseAST>((yyvsp[-4].ast_val));
      ast->if_stmt = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
      ast->else_stmt = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = ast;
  }
#line 1762 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 28:
#line 239 "/root/sysy-cmake-template/src/sysy.y"
                              {
    auto ast = new StmtAST();
    ast->type = StmtType::while_;
    ast->exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
    ast->while_stmt = unique_ptr<BaseAST>((yyvsp[0].ast_val));
    (yyval.ast_val) = ast;
  }
#line 1774 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 29:
#line 246 "/root/sysy-cmake-template/src/sysy.y"
              {
    auto ast = new StmtAST();
    ast->type = StmtType::break_;
    (yyval.ast_val) = ast;
  }
#line 1784 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 30:
#line 251 "/root/sysy-cmake-template/src/sysy.y"
                 {
    auto ast = new StmtAST();
    ast->type = StmtType::continue_;
    (yyval.ast_val) = ast;
  }
#line 1794 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 31:
#line 259 "/root/sysy-cmake-template/src/sysy.y"
                          {
        auto ast = new StmtAST();
        ast->type = StmtType::if_;
        ast->exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
        ast->if_stmt = unique_ptr<BaseAST>((yyvsp[0].ast_val));
        (yyval.ast_val) = ast;
    }
#line 1806 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 32:
#line 266 "/root/sysy-cmake-template/src/sysy.y"
                                             {
        auto ast = new StmtAST();
        ast->type = StmtType::if_else;
        ast->exp = unique_ptr<BaseAST>((yyvsp[-4].ast_val));
        ast->if_stmt = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
        ast->else_stmt = unique_ptr<BaseAST>((yyvsp[0].ast_val));
        (yyval.ast_val) = ast;
    }
#line 1819 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 33:
#line 277 "/root/sysy-cmake-template/src/sysy.y"
              {
    (yyval.int_val) = int((yyvsp[0].int_val));
  }
#line 1827 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 34:
#line 283 "/root/sysy-cmake-template/src/sysy.y"
              {
      auto exp = new DeclAST();
      exp->type = DeclType::cst;
      exp->const_decl_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = exp;
  }
#line 1838 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 35:
#line 289 "/root/sysy-cmake-template/src/sysy.y"
            {
      auto exp = new DeclAST();
      exp->type = DeclType::var;
      exp->var_decl_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = exp;
  }
#line 1849 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 36:
#line 298 "/root/sysy-cmake-template/src/sysy.y"
                                 {
      auto exp = new ConstDeclAST();
      exp->b_type = *unique_ptr<string>((yyvsp[-2].str_val));
      vector<unique_ptr<BaseAST>> *list = ((yyvsp[-1].vec_val));
      for (auto it = list->begin(); it != list->end(); it++)
          exp->const_def_list.push_back(move(*it));
      (yyval.ast_val) = exp;
  }
#line 1862 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 37:
#line 309 "/root/sysy-cmake-template/src/sysy.y"
             {
      vector<unique_ptr<BaseAST>> *list = new vector<unique_ptr<BaseAST>>;
      list->push_back(unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.vec_val) = list;
  }
#line 1872 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 38:
#line 314 "/root/sysy-cmake-template/src/sysy.y"
                              {
      vector<unique_ptr<BaseAST>> *list = ((yyvsp[-2].vec_val));
      list->push_back(unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.vec_val) = list;
  }
#line 1882 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 39:
#line 322 "/root/sysy-cmake-template/src/sysy.y"
                           {
      auto exp = new ConstDefAST();
      exp->ident = *unique_ptr<string>((yyvsp[-2].str_val));
      exp->const_init_val = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = exp;
  }
#line 1893 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 40:
#line 328 "/root/sysy-cmake-template/src/sysy.y"
                                        {
      auto ast = new ConstDefAST();
      ast->ident = *unique_ptr<string>((yyvsp[-3].str_val));
      vector<unique_ptr<BaseAST>> *list = ((yyvsp[-2].vec_val));
      for (auto it = list->begin(); it != list->end(); it++)
          ast->const_exp_list.push_back(move(*it));
      ast->const_init_val = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = ast;
  }
#line 1907 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 41:
#line 340 "/root/sysy-cmake-template/src/sysy.y"
                     {
      vector<unique_ptr<BaseAST>> *ast = new vector<unique_ptr<BaseAST>>;
      ast->push_back(unique_ptr<BaseAST>((yyvsp[-1].ast_val)));
      (yyval.vec_val) = ast;
  }
#line 1917 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 42:
#line 345 "/root/sysy-cmake-template/src/sysy.y"
                                  {
      vector<unique_ptr<BaseAST>> *ast = ((yyvsp[-3].vec_val));
      ast->push_back(unique_ptr<BaseAST>((yyvsp[-1].ast_val)));
      (yyval.vec_val) = ast;
  }
#line 1927 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 43:
#line 353 "/root/sysy-cmake-template/src/sysy.y"
             {
      auto exp = new ConstInitValAST();
      exp->type = ConstInitValType::const_exp;
      exp->const_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = exp;
  }
#line 1938 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 44:
#line 359 "/root/sysy-cmake-template/src/sysy.y"
            {
      auto exp = new ConstInitValAST();
      exp->type = ConstInitValType::const_exp_list;
      (yyval.ast_val) = exp;
  }
#line 1948 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 45:
#line 364 "/root/sysy-cmake-template/src/sysy.y"
                             {
      auto ast = new ConstInitValAST();
      ast->type = ConstInitValType::const_exp_list;
      vector<unique_ptr<BaseAST>> *list = ((yyvsp[-1].vec_val));
      for (auto it = list->begin(); it != list->end(); it++)
          ast->const_initval_list.push_back(move(*it));
      (yyval.ast_val) = ast;
    }
#line 1961 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 46:
#line 375 "/root/sysy-cmake-template/src/sysy.y"
                   {
        vector<unique_ptr<BaseAST>> *ast = new vector<unique_ptr<BaseAST>>;
        ast->push_back(unique_ptr<BaseAST>((yyvsp[0].ast_val)));
        (yyval.vec_val) = ast;
    }
#line 1971 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 47:
#line 380 "/root/sysy-cmake-template/src/sysy.y"
                                        {
        vector<unique_ptr<BaseAST>> *ast = ((yyvsp[-2].vec_val));
        ast->push_back(unique_ptr<BaseAST>((yyvsp[0].ast_val)));
        (yyval.vec_val) = ast;
    }
#line 1981 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 48:
#line 389 "/root/sysy-cmake-template/src/sysy.y"
        {
      auto const_exp = new ConstExpAST();
      const_exp->exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = const_exp;
  }
#line 1991 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 49:
#line 397 "/root/sysy-cmake-template/src/sysy.y"
                            { // 这里本来是BType的 但是不知道为什么CompUnitList 一加FuncDef就识别不了VarDecl了 改成和FuncDef一样的类型就好了
      auto exp = new VarDeclAST();
      // exp->b_type = *unique_ptr<string>($1);
      exp->b_type = "int";
      vector<unique_ptr<BaseAST>> *list = ((yyvsp[-1].vec_val));
      for (auto it = list->begin(); it != list->end(); it++)
          exp->var_def_list.push_back(move(*it));
      (yyval.ast_val) = exp;
  }
#line 2005 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 50:
#line 409 "/root/sysy-cmake-template/src/sysy.y"
           {
      vector<unique_ptr<BaseAST>> *list = new vector<unique_ptr<BaseAST>>;
      list->push_back(unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.vec_val) = list;
  }
#line 2015 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 51:
#line 414 "/root/sysy-cmake-template/src/sysy.y"
                          {
      vector<unique_ptr<BaseAST>> *list = ((yyvsp[-2].vec_val));
      list->push_back(unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.vec_val) = list;
  }
#line 2025 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 52:
#line 422 "/root/sysy-cmake-template/src/sysy.y"
          {
      auto exp = new VarDefAST();
      exp->type = VarDefType::ident;
      exp->ident = *unique_ptr<string>((yyvsp[0].str_val));
      (yyval.ast_val) = exp;
  }
#line 2036 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 53:
#line 428 "/root/sysy-cmake-template/src/sysy.y"
                      {
      auto exp = new VarDefAST();
      exp->type = VarDefType::ident_initval;
      exp->ident = *unique_ptr<string>((yyvsp[-2].str_val));
      exp->init_val = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = exp;
  }
#line 2048 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 54:
#line 435 "/root/sysy-cmake-template/src/sysy.y"
                       {
      auto ast = new VarDefAST();
      ast->type = VarDefType::ident;
      ast->ident = *unique_ptr<string>((yyvsp[-1].str_val));
      vector<unique_ptr<BaseAST>> *list = ((yyvsp[0].vec_val));
      for (auto it = list->begin(); it != list->end(); it++)
          ast->const_exp_list.push_back(move(*it));
      (yyval.ast_val) = ast;
  }
#line 2062 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 55:
#line 444 "/root/sysy-cmake-template/src/sysy.y"
                                   {
      auto ast = new VarDefAST();
      ast->type = VarDefType::ident_initval;
      ast->ident = *unique_ptr<string>((yyvsp[-3].str_val));
      vector<unique_ptr<BaseAST>> *list = ((yyvsp[-2].vec_val));
      for (auto it = list->begin(); it != list->end(); it++)
          ast->const_exp_list.push_back(move(*it));
      ast->init_val = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = ast;
  }
#line 2077 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 56:
#line 457 "/root/sysy-cmake-template/src/sysy.y"
        {
      auto init_val = new InitValAST();
      init_val->type = InitValType::exp;
      init_val->exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = init_val;
  }
#line 2088 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 57:
#line 463 "/root/sysy-cmake-template/src/sysy.y"
            {
      auto ast = new InitValAST();
      ast->type = InitValType::init_val_list;
      (yyval.ast_val) = ast;
    }
#line 2098 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 58:
#line 468 "/root/sysy-cmake-template/src/sysy.y"
                          {
      auto ast = new InitValAST();
      ast->type = InitValType::init_val_list;
      vector<unique_ptr<BaseAST>> *list= ((yyvsp[-1].vec_val));
      for (auto it = list->begin(); it != list->end(); it++)
          ast->init_val_list.push_back(move(*it));
      (yyval.ast_val) = ast;
    }
#line 2111 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 59:
#line 479 "/root/sysy-cmake-template/src/sysy.y"
              {
        vector<unique_ptr<BaseAST>> *ast = new vector<unique_ptr<BaseAST>>;
        ast->push_back(unique_ptr<BaseAST>((yyvsp[0].ast_val)));
        (yyval.vec_val) = ast;
    }
#line 2121 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 60:
#line 484 "/root/sysy-cmake-template/src/sysy.y"
                              {
        vector<unique_ptr<BaseAST>> *ast = ((yyvsp[-2].vec_val));
        ast->push_back(unique_ptr<BaseAST>((yyvsp[0].ast_val)));
        (yyval.vec_val) = ast;
    }
#line 2131 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 61:
#line 492 "/root/sysy-cmake-template/src/sysy.y"
           {
      auto exp = new ExpAST();
      exp->lor_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = exp;
  }
#line 2141 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 62:
#line 500 "/root/sysy-cmake-template/src/sysy.y"
       {
      string *op = new string("||");
      (yyval.str_val) = op;
  }
#line 2150 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 63:
#line 507 "/root/sysy-cmake-template/src/sysy.y"
        {
      string *op = new string("&&");
      (yyval.str_val) = op;
  }
#line 2159 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 64:
#line 514 "/root/sysy-cmake-template/src/sysy.y"
       {
      string *op = new string("==");
      (yyval.str_val) = op;
  }
#line 2168 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 65:
#line 518 "/root/sysy-cmake-template/src/sysy.y"
       {
      string *op = new string("!=");
      (yyval.str_val) = op;
  }
#line 2177 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 66:
#line 525 "/root/sysy-cmake-template/src/sysy.y"
        {
      string *op = new string("<");
      (yyval.str_val) = op;
  }
#line 2186 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 67:
#line 529 "/root/sysy-cmake-template/src/sysy.y"
        {
      string *op = new string(">");
      (yyval.str_val) = op;
  }
#line 2195 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 68:
#line 533 "/root/sysy-cmake-template/src/sysy.y"
       {
      string *op = new string("<=");
      (yyval.str_val) = op;
  }
#line 2204 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 69:
#line 537 "/root/sysy-cmake-template/src/sysy.y"
       {
      string *op = new string(">=");
      (yyval.str_val) = op;
  }
#line 2213 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 70:
#line 544 "/root/sysy-cmake-template/src/sysy.y"
        {
      string *op = new string("+");
      (yyval.str_val) = op;
  }
#line 2222 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 71:
#line 548 "/root/sysy-cmake-template/src/sysy.y"
        {
      string *op = new string("-");
      (yyval.str_val) = op;
  }
#line 2231 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 72:
#line 555 "/root/sysy-cmake-template/src/sysy.y"
        {
      string *op = new string("*");
      (yyval.str_val) = op;
  }
#line 2240 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 73:
#line 559 "/root/sysy-cmake-template/src/sysy.y"
        {
      string *op = new string("/");
      (yyval.str_val) = op;
  }
#line 2249 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 74:
#line 563 "/root/sysy-cmake-template/src/sysy.y"
        {
      string *op = new string("%");
      (yyval.str_val) = op;
  }
#line 2258 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 75:
#line 570 "/root/sysy-cmake-template/src/sysy.y"
        {
      string *op = new string("+");
      (yyval.str_val) = op;
  }
#line 2267 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 76:
#line 574 "/root/sysy-cmake-template/src/sysy.y"
        {
      string *op = new string("-");
      (yyval.str_val) = op;
  }
#line 2276 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 77:
#line 578 "/root/sysy-cmake-template/src/sysy.y"
        {
      string *op = new string("!");
      (yyval.str_val) = op;
  }
#line 2285 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 78:
#line 585 "/root/sysy-cmake-template/src/sysy.y"
            {
      auto exp = new LOrExpAST();
      exp->type = LOrExpType::land;
      exp->land_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = exp;
  }
#line 2296 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 79:
#line 591 "/root/sysy-cmake-template/src/sysy.y"
                         {
      auto exp = new LOrExpAST();
      exp->type = LOrExpType::lor_land;
      exp->op = *unique_ptr<string>((yyvsp[-1].str_val));
      exp->lor_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
      exp->land_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = exp;
  }
#line 2309 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 80:
#line 602 "/root/sysy-cmake-template/src/sysy.y"
          {
      auto exp = new LAndExpAST();
      exp->type = LAndExpType::eq;
      exp->eq_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = exp;
  }
#line 2320 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 81:
#line 608 "/root/sysy-cmake-template/src/sysy.y"
                         {
      auto exp = new LAndExpAST();
      exp->type = LAndExpType::land_eq;
      exp->op = *unique_ptr<string>((yyvsp[-1].str_val));
      exp->land_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
      exp->eq_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = exp;
  }
#line 2333 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 82:
#line 619 "/root/sysy-cmake-template/src/sysy.y"
           {
      auto exp = new EqExpAST();
      exp->type = EqExpType::rel;
      exp->rel_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = exp;
  }
#line 2344 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 83:
#line 625 "/root/sysy-cmake-template/src/sysy.y"
                      {
      auto exp = new EqExpAST();
      exp->type = EqExpType::eq_rel;
      exp->op = *unique_ptr<string>((yyvsp[-1].str_val));
      exp->eq_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
      exp->rel_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = exp;
  }
#line 2357 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 84:
#line 636 "/root/sysy-cmake-template/src/sysy.y"
           {
      auto exp = new RelExpAST();
      exp->type = RelExpType::add;
      exp->add_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = exp;
  }
#line 2368 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 85:
#line 642 "/root/sysy-cmake-template/src/sysy.y"
                        {
      auto exp = new RelExpAST();
      exp->type = RelExpType::rel_add;
      exp->op = *unique_ptr<string>((yyvsp[-1].str_val));
      exp->rel_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
      exp->add_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = exp;
  }
#line 2381 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 86:
#line 653 "/root/sysy-cmake-template/src/sysy.y"
           {
      auto add_exp = new AddExpAST();
      add_exp->type = AddExpType::mul;
      add_exp->mul_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = add_exp;
  }
#line 2392 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 87:
#line 659 "/root/sysy-cmake-template/src/sysy.y"
                        {
      auto add_exp = new AddExpAST();
      add_exp->type = AddExpType::add_mul;
      add_exp->op = *unique_ptr<string>((yyvsp[-1].str_val));
      add_exp->add_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
      add_exp->mul_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = add_exp;
  }
#line 2405 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 88:
#line 670 "/root/sysy-cmake-template/src/sysy.y"
             {
      auto mul_exp = new MulExpAST();
      mul_exp->type = MulExpType::unary;
      mul_exp->unary_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = mul_exp;
  }
#line 2416 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 89:
#line 676 "/root/sysy-cmake-template/src/sysy.y"
                          {
      auto mul_exp = new MulExpAST();
      mul_exp->type = MulExpType::mul_unary;
      mul_exp->op = *unique_ptr<string>((yyvsp[-1].str_val));
      mul_exp->mul_exp = unique_ptr<BaseAST>((yyvsp[-2].ast_val));
      mul_exp->unary_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = mul_exp;
  }
#line 2429 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 90:
#line 687 "/root/sysy-cmake-template/src/sysy.y"
               {
      auto unary_exp = new UnaryExpAST();
      unary_exp->type = UnaryExpType::primary;
      unary_exp->primary_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = unary_exp;
  }
#line 2440 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 91:
#line 693 "/root/sysy-cmake-template/src/sysy.y"
                     {
      auto unary_exp = new UnaryExpAST();
      unary_exp->type = UnaryExpType::unary;
      unary_exp->unary_op = *unique_ptr<string>((yyvsp[-1].str_val));
      unary_exp->unary_exp = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = unary_exp;
  }
#line 2452 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 92:
#line 700 "/root/sysy-cmake-template/src/sysy.y"
                 {
      auto unary_exp = new UnaryExpAST();
      unary_exp->type = UnaryExpType::func;
      unary_exp->ident = *unique_ptr<string>((yyvsp[-2].str_val));
      (yyval.ast_val) = unary_exp;
  }
#line 2463 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 93:
#line 706 "/root/sysy-cmake-template/src/sysy.y"
                              {
      auto unary_exp = new UnaryExpAST();
      unary_exp->type = UnaryExpType::func;
      unary_exp->ident = *unique_ptr<string>((yyvsp[-3].str_val));
      vector<unique_ptr<BaseAST>> *list = ((yyvsp[-1].vec_val));
      for (auto it = list->begin(); it != list->end(); it++)
        unary_exp->func_r_params.push_back(move(*it));
      (yyval.ast_val) = unary_exp;
  }
#line 2477 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 94:
#line 718 "/root/sysy-cmake-template/src/sysy.y"
        {
      vector<unique_ptr<BaseAST>> *ast = new vector<unique_ptr<BaseAST>>;
      ast->push_back(unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.vec_val) = ast;
  }
#line 2487 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 95:
#line 723 "/root/sysy-cmake-template/src/sysy.y"
                        {
      vector<unique_ptr<BaseAST>> *ast = ((yyvsp[-2].vec_val));
      ast->push_back(unique_ptr<BaseAST>((yyvsp[0].ast_val)));
      (yyval.vec_val) = ast;
  }
#line 2497 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 96:
#line 732 "/root/sysy-cmake-template/src/sysy.y"
                {
      auto primary_exp = new PrimaryExpAST();
      primary_exp->type = PrimaryExpType::exp;
      primary_exp->exp = unique_ptr<BaseAST>((yyvsp[-1].ast_val));
      (yyval.ast_val) = primary_exp;
  }
#line 2508 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 97:
#line 738 "/root/sysy-cmake-template/src/sysy.y"
         {
      auto primary_exp = new PrimaryExpAST();
      primary_exp->type = PrimaryExpType::lval;
      primary_exp->lval = unique_ptr<BaseAST>((yyvsp[0].ast_val));
      (yyval.ast_val) = primary_exp;
  }
#line 2519 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 98:
#line 744 "/root/sysy-cmake-template/src/sysy.y"
           {
      auto primary_exp = new PrimaryExpAST();
      primary_exp->type = PrimaryExpType::number;
      primary_exp->number = ((yyvsp[0].int_val));
      (yyval.ast_val) = primary_exp;
  }
#line 2530 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 99:
#line 753 "/root/sysy-cmake-template/src/sysy.y"
          {
      auto ast = new LValAST();
      ast->ident = *unique_ptr<string>((yyvsp[0].str_val));
      (yyval.ast_val) = ast;
  }
#line 2540 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 100:
#line 758 "/root/sysy-cmake-template/src/sysy.y"
                  {
      auto ast = new LValAST();
      ast->ident = *unique_ptr<string>((yyvsp[-1].str_val));
      vector<unique_ptr<BaseAST>> *list = ((yyvsp[0].vec_val));
      for (auto it = list->begin(); it != list->end(); it++)
          ast->exp_list.push_back(move(*it));
      (yyval.ast_val) = ast;
  }
#line 2553 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 101:
#line 769 "/root/sysy-cmake-template/src/sysy.y"
                {
      vector<unique_ptr<BaseAST>> *ast = new vector<unique_ptr<BaseAST>>;
      ast->push_back(unique_ptr<BaseAST>((yyvsp[-1].ast_val)));
      (yyval.vec_val) = ast;
  }
#line 2563 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 102:
#line 774 "/root/sysy-cmake-template/src/sysy.y"
                        {
      vector<unique_ptr<BaseAST>> *ast = ((yyvsp[-3].vec_val));
      ast->push_back(unique_ptr<BaseAST>((yyvsp[-1].ast_val)));
      (yyval.vec_val) = ast;
  }
#line 2573 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;

  case 103:
#line 782 "/root/sysy-cmake-template/src/sysy.y"
        {
      string *type = new string("int");
      (yyval.str_val) = type;
  }
#line 2582 "/root/sysy-cmake-template/build/sysy.tab.cpp"
    break;


#line 2586 "/root/sysy-cmake-template/build/sysy.tab.cpp"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
      yyerror (ast, YY_("syntax error"));
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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
        yyerror (ast, yymsgp);
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
                      yytoken, &yylval, ast);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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
                  yystos[yystate], yyvsp, ast);
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
  yyerror (ast, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, ast);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, ast);
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
#line 790 "/root/sysy-cmake-template/src/sysy.y"





void yyerror(unique_ptr<BaseAST> &ast, const char *s) {
  cerr << "error: " << s << endl;
}
