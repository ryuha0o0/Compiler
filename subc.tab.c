/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 6 "subc.y"


/* Prologue section */

#include "subc.h"

int   yylex ();
int   yyerror (char* s);
int   get_lineno();
extern char* file_name;

void error_assignable(void);
void error_incompatible(void);
void error_null(void);
void error_subscript(void);
void error_incomplete(void);
void error_return(void);
void error_function(void);
void error_arguments(void);
void error_comparable(void);
void error_binary(void);
void error_unary(void);
void error_addressof(void);
void error_indirection(void);
void error_array(void);
void error_struct(void);
void error_member(void);
void error_strurctp(void);

static int in_struct = 0;


#line 104 "subc.tab.c"

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

#include "subc.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_3_ = 3,                         /* ','  */
  YYSYMBOL_4_ = 4,                         /* '='  */
  YYSYMBOL_5_ = 5,                         /* '+'  */
  YYSYMBOL_6_ = 6,                         /* '-'  */
  YYSYMBOL_7_ = 7,                         /* '*'  */
  YYSYMBOL_8_ = 8,                         /* '/'  */
  YYSYMBOL_9_ = 9,                         /* '%'  */
  YYSYMBOL_10_ = 10,                       /* '!'  */
  YYSYMBOL_11_ = 11,                       /* '&'  */
  YYSYMBOL_12_ = 12,                       /* '['  */
  YYSYMBOL_13_ = 13,                       /* ']'  */
  YYSYMBOL_14_ = 14,                       /* '('  */
  YYSYMBOL_15_ = 15,                       /* ')'  */
  YYSYMBOL_16_ = 16,                       /* '.'  */
  YYSYMBOL_STRUCT = 17,                    /* STRUCT  */
  YYSYMBOL_RETURN = 18,                    /* RETURN  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_FOR = 20,                       /* FOR  */
  YYSYMBOL_BREAK = 21,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 22,                  /* CONTINUE  */
  YYSYMBOL_SYM_NULL = 23,                  /* SYM_NULL  */
  YYSYMBOL_TYPE = 24,                      /* TYPE  */
  YYSYMBOL_IF = 25,                        /* IF  */
  YYSYMBOL_ELSE = 26,                      /* ELSE  */
  YYSYMBOL_CHAR_CONST = 27,                /* CHAR_CONST  */
  YYSYMBOL_STRING = 28,                    /* STRING  */
  YYSYMBOL_LOGICAL_AND = 29,               /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_OR = 30,                /* LOGICAL_OR  */
  YYSYMBOL_RELOP = 31,                     /* RELOP  */
  YYSYMBOL_EQUOP = 32,                     /* EQUOP  */
  YYSYMBOL_INCOP = 33,                     /* INCOP  */
  YYSYMBOL_DECOP = 34,                     /* DECOP  */
  YYSYMBOL_STRUCTOP = 35,                  /* STRUCTOP  */
  YYSYMBOL_INTEGER_CONST = 36,             /* INTEGER_CONST  */
  YYSYMBOL_ID = 37,                        /* ID  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_ext_def_list = 43,              /* ext_def_list  */
  YYSYMBOL_ext_def = 44,                   /* ext_def  */
  YYSYMBOL_type_specifier = 45,            /* type_specifier  */
  YYSYMBOL_struct_specifier = 46,          /* struct_specifier  */
  YYSYMBOL_47_1 = 47,                      /* $@1  */
  YYSYMBOL_func_decl = 48,                 /* func_decl  */
  YYSYMBOL_49_2 = 49,                      /* $@2  */
  YYSYMBOL_50_3 = 50,                      /* $@3  */
  YYSYMBOL_pointers = 51,                  /* pointers  */
  YYSYMBOL_param_list = 52,                /* param_list  */
  YYSYMBOL_param_decl = 53,                /* param_decl  */
  YYSYMBOL_def_list = 54,                  /* def_list  */
  YYSYMBOL_def = 55,                       /* def  */
  YYSYMBOL_compound_stmt = 56,             /* compound_stmt  */
  YYSYMBOL_57_4 = 57,                      /* $@4  */
  YYSYMBOL_stmt_list = 58,                 /* stmt_list  */
  YYSYMBOL_stmt = 59,                      /* stmt  */
  YYSYMBOL_expr_e = 60,                    /* expr_e  */
  YYSYMBOL_expr = 61,                      /* expr  */
  YYSYMBOL_binary = 62,                    /* binary  */
  YYSYMBOL_unary = 63,                     /* unary  */
  YYSYMBOL_args = 64                       /* args  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   253

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  150

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   278


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    10,     2,     2,     2,     9,    11,     2,
      14,    15,     7,     5,     3,     6,    16,     8,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
       2,     4,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    12,     2,    13,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    81,    81,    85,    86,    90,    96,   103,   104,   108,
     110,   115,   115,   120,   128,   128,   135,   135,   145,   147,
     152,   153,   157,   166,   179,   180,   184,   194,   208,   208,
     212,   213,   217,   218,   223,   224,   225,   226,   227,   228,
     229,   230,   234,   235,   239,   247,   251,   258,   266,   272,
     278,   284,   290,   296,   297,   303,   312,   313,   314,   315,
     316,   317,   323,   329,   335,   341,   347,   353,   358,   364,
     370,   380,   390,   400,   406,   412,   416,   417
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "','", "'='", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'!'", "'&'", "'['", "']'", "'('", "')'",
  "'.'", "STRUCT", "RETURN", "WHILE", "FOR", "BREAK", "CONTINUE",
  "SYM_NULL", "TYPE", "IF", "ELSE", "CHAR_CONST", "STRING", "LOGICAL_AND",
  "LOGICAL_OR", "RELOP", "EQUOP", "INCOP", "DECOP", "STRUCTOP",
  "INTEGER_CONST", "ID", "';'", "'{'", "'}'", "$accept", "program",
  "ext_def_list", "ext_def", "type_specifier", "struct_specifier", "$@1",
  "func_decl", "$@2", "$@3", "pointers", "param_list", "param_decl",
  "def_list", "def", "compound_stmt", "$@4", "stmt_list", "stmt", "expr_e",
  "expr", "binary", "unary", "args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-129)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-15)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -129,     4,    -3,  -129,   -22,  -129,  -129,    12,   -13,     7,
      31,  -129,    -2,  -129,  -129,  -129,  -129,    -7,  -129,  -129,
      42,    57,  -129,    -3,    -4,    70,    77,    -3,    12,  -129,
    -129,    75,  -129,    52,  -129,    12,    64,  -129,    67,   159,
     159,   159,   159,   159,   159,    91,    92,    69,    72,  -129,
     104,  -129,  -129,   159,   159,  -129,  -129,  -129,  -129,  -129,
    -129,    81,    33,   185,  -129,    85,    -3,  -129,    -6,   209,
     209,   209,   209,   108,    14,    87,   159,   159,  -129,  -129,
     159,   209,   209,  -129,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   144,    89,  -129,  -129,    90,
     122,  -129,   100,  -129,  -129,  -129,  -129,   124,   102,  -129,
     126,    36,   209,    36,  -129,  -129,  -129,   202,   197,   155,
      68,  -129,   129,  -129,  -129,    65,  -129,  -129,   109,   139,
     110,   159,   110,  -129,   159,  -129,   140,   118,  -129,   119,
     142,  -129,  -129,  -129,   159,   110,   160,  -129,   110,  -129
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,     0,     9,     3,    19,    10,     0,
      13,    18,     0,     7,    28,     8,    11,     0,    25,    25,
       0,    16,     5,    31,     0,     0,     0,     0,    19,    10,
      24,     0,    12,     0,    15,    19,     0,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
       0,    59,    60,     0,     0,    58,    61,    36,    29,    37,
      30,     0,    45,    53,     6,     0,     0,    17,     0,    62,
      69,    63,    68,     0,    53,     0,     0,    43,    34,    35,
       0,    66,    67,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    64,    65,     0,
      22,    21,     0,    26,    56,    57,    33,     0,     0,    42,
       0,    48,    53,    49,    50,    51,    52,    54,    55,    46,
      47,    44,     0,    74,    76,     0,    71,    72,     0,     0,
       0,    43,     0,    70,     0,    73,     0,     0,    40,     0,
      38,    77,    23,    27,    43,     0,     0,    39,     0,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,  -129,  -129,     0,   172,  -129,  -129,  -129,  -129,
     -11,  -129,   113,   157,  -129,   174,  -129,  -129,   -61,  -128,
     -43,   161,   -31,  -129
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     6,    28,    29,    19,     9,    26,    27,
      12,    36,    37,    23,    30,    59,    18,    31,    60,   108,
      61,    62,    63,   125
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,    75,     7,   139,     3,    20,   102,    21,    69,    70,
      71,    72,    74,     4,     4,    10,   146,    38,    93,    11,
       5,     5,    81,    82,    65,    13,    94,    35,    95,   105,
      96,    22,   103,   107,   109,    17,    32,   110,    84,    85,
      86,    87,    88,    86,    87,    88,    14,    97,    98,    99,
     121,   122,   124,   112,   112,   112,   112,   112,   112,   112,
     112,   112,    89,    90,    91,    92,    35,    66,   134,   138,
      16,   140,   -14,    84,    85,    86,    87,    88,    25,    67,
     135,    39,    40,    33,   147,    41,    42,   149,   109,    43,
      64,   141,    34,    44,    45,    46,    47,    48,    49,    91,
      50,   109,    51,    52,    68,    76,    77,    78,    53,    54,
      79,    55,    56,    57,    14,    58,    39,    40,    80,    83,
      41,    42,   100,   104,    43,   106,   126,   127,    44,    45,
      46,    47,    48,    49,   128,    50,   129,    51,    52,   130,
     131,   132,   133,    53,    54,   136,    55,    56,    57,    14,
      39,    40,   137,   142,    41,    42,   143,   144,    43,   123,
      84,    85,    86,    87,    88,    39,    40,    49,   145,    41,
      42,    51,    52,    43,     8,   148,    24,    53,    54,   101,
      55,    56,    49,    15,     0,     0,    51,    52,     0,    93,
       0,     0,    53,    54,     0,    55,    56,    94,     0,    95,
       0,    96,    84,    85,    86,    87,    88,    84,    85,    86,
      87,    88,     0,     0,     0,     0,     0,     0,    97,    98,
      99,    94,     0,    95,     0,    96,    89,     0,    91,    92,
       0,     0,     0,    91,    92,     0,     0,     0,     0,     0,
       0,     0,    97,    98,    99,   111,   113,   114,   115,   116,
     117,   118,   119,   120
};

static const yytype_int16 yycheck[] =
{
      43,    44,     2,   131,     0,    12,    12,    14,    39,    40,
      41,    42,    43,    17,    17,    37,   144,    28,     4,     7,
      24,    24,    53,    54,    35,    38,    12,    27,    14,    15,
      16,    38,    38,    76,    77,    37,    40,    80,     5,     6,
       7,     8,     9,     7,     8,     9,    39,    33,    34,    35,
      93,    94,    95,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    29,    30,    31,    32,    66,     3,     3,   130,
      39,   132,    15,     5,     6,     7,     8,     9,    36,    15,
      15,     6,     7,    13,   145,    10,    11,   148,   131,    14,
      38,   134,    15,    18,    19,    20,    21,    22,    23,    31,
      25,   144,    27,    28,    37,    14,    14,    38,    33,    34,
      38,    36,    37,    38,    39,    40,     6,     7,    14,    38,
      10,    11,    37,    15,    14,    38,    37,    37,    18,    19,
      20,    21,    22,    23,    12,    25,    36,    27,    28,    15,
      38,    15,    13,    33,    34,    36,    36,    37,    38,    39,
       6,     7,    13,    13,    10,    11,    38,    38,    14,    15,
       5,     6,     7,     8,     9,     6,     7,    23,    26,    10,
      11,    27,    28,    14,     2,    15,    19,    33,    34,    66,
      36,    37,    23,     9,    -1,    -1,    27,    28,    -1,     4,
      -1,    -1,    33,    34,    -1,    36,    37,    12,    -1,    14,
      -1,    16,     5,     6,     7,     8,     9,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    12,    -1,    14,    -1,    16,    29,    -1,    31,    32,
      -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    84,    85,    86,    87,    88,
      89,    90,    91,    92
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    42,    43,     0,    17,    24,    44,    45,    46,    48,
      37,     7,    51,    38,    39,    56,    39,    37,    57,    47,
      12,    14,    38,    54,    54,    36,    49,    50,    45,    46,
      55,    58,    40,    13,    15,    45,    52,    53,    51,     6,
       7,    10,    11,    14,    18,    19,    20,    21,    22,    23,
      25,    27,    28,    33,    34,    36,    37,    38,    40,    56,
      59,    61,    62,    63,    38,    51,     3,    15,    37,    63,
      63,    63,    63,    61,    63,    61,    14,    14,    38,    38,
      14,    63,    63,    38,     5,     6,     7,     8,     9,    29,
      30,    31,    32,     4,    12,    14,    16,    33,    34,    35,
      37,    53,    12,    38,    15,    15,    38,    61,    60,    61,
      61,    62,    63,    62,    62,    62,    62,    62,    62,    62,
      62,    61,    61,    15,    61,    64,    37,    37,    12,    36,
      15,    38,    15,    13,     3,    15,    36,    13,    59,    60,
      59,    61,    13,    38,    38,    26,    60,    59,    15,    59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    45,
      45,    47,    46,    46,    49,    48,    50,    48,    51,    51,
      52,    52,    53,    53,    54,    54,    55,    55,    57,    56,
      58,    58,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    60,    60,    61,    61,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     4,     7,     2,     2,     1,
       1,     0,     6,     2,     0,     6,     0,     7,     1,     0,
       1,     3,     3,     6,     2,     0,     4,     7,     0,     5,
       2,     0,     2,     3,     2,     2,     1,     1,     5,     7,
       5,     9,     1,     0,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       4,     3,     3,     4,     3,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 5: /* ext_def: type_specifier pointers ID ';'  */
#line 91 "subc.y"
      {
        Type *t = (Type*) (yyvsp[-3].typeVal); if((yyvsp[-2].intVal)) t = make_pointer(t);
        if(is_declared_current((yyvsp[-1].stringVal))) error_redeclaration();
        else add_symbol((yyvsp[-1].stringVal), t);
      }
#line 1272 "subc.tab.c"
    break;

  case 6: /* ext_def: type_specifier pointers ID '[' INTEGER_CONST ']' ';'  */
#line 97 "subc.y"
      {
        Type *t = (Type*) (yyvsp[-6].typeVal); if((yyvsp[-5].intVal)) t = make_pointer(t);
        t = make_array(t);
        if(is_declared_current((yyvsp[-4].stringVal))) error_redeclaration();
        else add_symbol((yyvsp[-4].stringVal), t);
      }
#line 1283 "subc.tab.c"
    break;

  case 8: /* ext_def: func_decl compound_stmt  */
#line 104 "subc.y"
                            { set_current_return(NULL); pop_scope(); }
#line 1289 "subc.tab.c"
    break;

  case 9: /* type_specifier: TYPE  */
#line 109 "subc.y"
      { (yyval.typeVal) = make_basic((yyvsp[0].intVal)==0 ? TYPE_INT : TYPE_CHAR); }
#line 1295 "subc.tab.c"
    break;

  case 10: /* type_specifier: struct_specifier  */
#line 111 "subc.y"
      { (yyval.typeVal) = (yyvsp[0].typeVal); }
#line 1301 "subc.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 115 "subc.y"
                  { if(is_struct_type((yyvsp[-1].stringVal))) error_redeclaration(); in_struct=1; start_struct((yyvsp[-1].stringVal)); }
#line 1307 "subc.tab.c"
    break;

  case 12: /* struct_specifier: STRUCT ID '{' $@1 def_list '}'  */
#line 116 "subc.y"
      {
        int ok; Type *t = end_struct(&ok); in_struct=0;
        (yyval.typeVal) = t ? t : make_struct((yyvsp[-4].stringVal));
      }
#line 1316 "subc.tab.c"
    break;

  case 13: /* struct_specifier: STRUCT ID  */
#line 121 "subc.y"
      {
        if(!is_struct_type((yyvsp[0].stringVal))) error_incomplete();
        (yyval.typeVal) = make_struct((yyvsp[0].stringVal));
      }
#line 1325 "subc.tab.c"
    break;

  case 14: /* $@2: %empty  */
#line 128 "subc.y"
                                   { push_scope(); begin_param_list(); }
#line 1331 "subc.tab.c"
    break;

  case 15: /* func_decl: type_specifier pointers ID '(' $@2 ')'  */
#line 129 "subc.y"
      {
        int cnt; ParamList *ps = end_param_list(&cnt);
        Type *ret = (Type*) (yyvsp[-5].typeVal); if((yyvsp[-4].intVal)) ret = make_pointer(ret);
        if(!add_function((yyvsp[-3].stringVal), ret, ps, cnt)) error_redeclaration();
        set_current_return(ret);
      }
#line 1342 "subc.tab.c"
    break;

  case 16: /* $@3: %empty  */
#line 135 "subc.y"
                                   { push_scope(); begin_param_list(); }
#line 1348 "subc.tab.c"
    break;

  case 17: /* func_decl: type_specifier pointers ID '(' $@3 param_list ')'  */
#line 136 "subc.y"
      {
        int cnt; ParamList *ps = end_param_list(&cnt);
        Type *ret = (Type*) (yyvsp[-6].typeVal); if((yyvsp[-5].intVal)) ret = make_pointer(ret);
        if(!add_function((yyvsp[-4].stringVal), ret, ps, cnt)) error_redeclaration();
        set_current_return(ret);
      }
#line 1359 "subc.tab.c"
    break;

  case 18: /* pointers: '*'  */
#line 146 "subc.y"
      { (yyval.intVal) = 1; }
#line 1365 "subc.tab.c"
    break;

  case 19: /* pointers: %empty  */
#line 148 "subc.y"
      { (yyval.intVal) = 0; }
#line 1371 "subc.tab.c"
    break;

  case 22: /* param_decl: type_specifier pointers ID  */
#line 158 "subc.y"
      {
        Type *t = (Type*) (yyvsp[-2].typeVal);
        if((yyvsp[-1].intVal)) t = make_pointer(t);
        if(is_declared_current((yyvsp[0].stringVal))) error_redeclaration();
        else add_symbol((yyvsp[0].stringVal), t);
        add_param(t);
        (yyval.typeVal) = t;
      }
#line 1384 "subc.tab.c"
    break;

  case 23: /* param_decl: type_specifier pointers ID '[' INTEGER_CONST ']'  */
#line 167 "subc.y"
      {
        Type *t = (Type*) (yyvsp[-5].typeVal);
        if((yyvsp[-4].intVal)) t = make_pointer(t);
        t = make_array(t);
        if(is_declared_current((yyvsp[-3].stringVal))) error_redeclaration();
        else add_symbol((yyvsp[-3].stringVal), t);
        add_param(t);
        (yyval.typeVal) = t;
      }
#line 1398 "subc.tab.c"
    break;

  case 26: /* def: type_specifier pointers ID ';'  */
#line 185 "subc.y"
      {
        Type *t = (Type*) (yyvsp[-3].typeVal); if((yyvsp[-2].intVal)) t = make_pointer(t);
        if(in_struct) {
          add_field((yyvsp[-1].stringVal), t);
        } else {
          if(is_declared_current((yyvsp[-1].stringVal))) error_redeclaration();
          else add_symbol((yyvsp[-1].stringVal), t);
        }
      }
#line 1412 "subc.tab.c"
    break;

  case 27: /* def: type_specifier pointers ID '[' INTEGER_CONST ']' ';'  */
#line 195 "subc.y"
      {
        Type *t = (Type*) (yyvsp[-6].typeVal);; if((yyvsp[-5].intVal)) t = make_pointer(t);
        t = make_array(t);
        if(in_struct) {
          add_field((yyvsp[-4].stringVal), t);
        } else {
          if(is_declared_current((yyvsp[-4].stringVal))) error_redeclaration();
          else add_symbol((yyvsp[-4].stringVal), t);
        }
      }
#line 1427 "subc.tab.c"
    break;

  case 28: /* $@4: %empty  */
#line 208 "subc.y"
        { push_scope(); }
#line 1433 "subc.tab.c"
    break;

  case 29: /* compound_stmt: '{' $@4 def_list stmt_list '}'  */
#line 208 "subc.y"
                                                 { pop_scope(); }
#line 1439 "subc.tab.c"
    break;

  case 33: /* stmt: RETURN expr ';'  */
#line 219 "subc.y"
      {
        Type *rt = get_current_return();
        if(rt && !same_type(rt, (yyvsp[-1].typeVal)->type)) error_return();
      }
#line 1448 "subc.tab.c"
    break;

  case 44: /* expr: unary '=' expr  */
#line 240 "subc.y"
      {
        if(!(yyvsp[-2].typeVal)->type || !(yyvsp[0].typeVal)->type) { (yyval.typeVal) = make_ext(NULL,0); }
        else if(!(yyvsp[-2].typeVal)->lvalue) { error_assignable(); (yyval.typeVal) = make_ext((yyvsp[-2].typeVal)->type,0); }
        else if((yyvsp[0].typeVal)->type->kind==TYPE_NULL && !is_pointer((yyvsp[-2].typeVal)->type)) { error_null(); (yyval.typeVal)=make_ext((yyvsp[-2].typeVal)->type,0); }
        else if(!same_type((yyvsp[-2].typeVal)->type,(yyvsp[0].typeVal)->type)) { error_incompatible(); (yyval.typeVal)=make_ext((yyvsp[-2].typeVal)->type,0); }
        else (yyval.typeVal) = make_ext((yyvsp[-2].typeVal)->type,0);
      }
#line 1460 "subc.tab.c"
    break;

  case 45: /* expr: binary  */
#line 247 "subc.y"
           { (yyval.typeVal) = (yyvsp[0].typeVal); }
#line 1466 "subc.tab.c"
    break;

  case 46: /* binary: binary RELOP binary  */
#line 252 "subc.y"
      {
        if(!(yyvsp[-2].typeVal)->type || !(yyvsp[0].typeVal)->type) (yyval.typeVal)=make_ext(NULL,0);
        else if(is_numeric((yyvsp[-2].typeVal)->type) && is_numeric((yyvsp[0].typeVal)->type) && same_type((yyvsp[-2].typeVal)->type,(yyvsp[0].typeVal)->type))
            (yyval.typeVal) = make_ext(make_basic(TYPE_INT),0);
        else { error_comparable(); (yyval.typeVal)=make_ext(NULL,0); }
      }
#line 1477 "subc.tab.c"
    break;

  case 47: /* binary: binary EQUOP binary  */
#line 259 "subc.y"
      {
        if(!(yyvsp[-2].typeVal)->type || !(yyvsp[0].typeVal)->type) (yyval.typeVal)=make_ext(NULL,0);
        else if((is_numeric((yyvsp[-2].typeVal)->type)&&is_numeric((yyvsp[0].typeVal)->type)) ||
                (is_pointer((yyvsp[-2].typeVal)->type)&&is_pointer((yyvsp[0].typeVal)->type)&&same_type((yyvsp[-2].typeVal)->type,(yyvsp[0].typeVal)->type)))
            (yyval.typeVal) = make_ext(make_basic(TYPE_INT),0);
        else { error_comparable(); (yyval.typeVal)=make_ext(NULL,0); }
      }
#line 1489 "subc.tab.c"
    break;

  case 48: /* binary: binary '+' binary  */
#line 267 "subc.y"
      {
        if(!(yyvsp[-2].typeVal)->type || !(yyvsp[0].typeVal)->type) (yyval.typeVal)=make_ext(NULL,0);
        else if(is_integer((yyvsp[-2].typeVal)->type) && is_integer((yyvsp[0].typeVal)->type)) (yyval.typeVal) = make_ext((yyvsp[-2].typeVal)->type,0);
        else { error_binary(); (yyval.typeVal)=make_ext(NULL,0); }
      }
#line 1499 "subc.tab.c"
    break;

  case 49: /* binary: binary '-' binary  */
#line 273 "subc.y"
      {
        if(!(yyvsp[-2].typeVal)->type || !(yyvsp[0].typeVal)->type) (yyval.typeVal)=make_ext(NULL,0);
        else if(is_integer((yyvsp[-2].typeVal)->type) && is_integer((yyvsp[0].typeVal)->type)) (yyval.typeVal) = make_ext((yyvsp[-2].typeVal)->type,0);
        else { error_binary(); (yyval.typeVal)=make_ext(NULL,0); }
      }
#line 1509 "subc.tab.c"
    break;

  case 50: /* binary: binary '*' binary  */
#line 279 "subc.y"
      {
        if(!(yyvsp[-2].typeVal)->type || !(yyvsp[0].typeVal)->type) (yyval.typeVal)=make_ext(NULL,0);
        else if(is_integer((yyvsp[-2].typeVal)->type) && is_integer((yyvsp[0].typeVal)->type)) (yyval.typeVal) = make_ext((yyvsp[-2].typeVal)->type,0);
        else { error_binary(); (yyval.typeVal)=make_ext(NULL,0); }
      }
#line 1519 "subc.tab.c"
    break;

  case 51: /* binary: binary '/' binary  */
#line 285 "subc.y"
      {
        if(!(yyvsp[-2].typeVal)->type || !(yyvsp[0].typeVal)->type) (yyval.typeVal)=make_ext(NULL,0);
        else if(is_integer((yyvsp[-2].typeVal)->type) && is_integer((yyvsp[0].typeVal)->type)) (yyval.typeVal) = make_ext((yyvsp[-2].typeVal)->type,0);
        else { error_binary(); (yyval.typeVal)=make_ext(NULL,0); }
      }
#line 1529 "subc.tab.c"
    break;

  case 52: /* binary: binary '%' binary  */
#line 291 "subc.y"
      {
        if(!(yyvsp[-2].typeVal)->type || !(yyvsp[0].typeVal)->type) (yyval.typeVal)=make_ext(NULL,0);
        else if(is_integer((yyvsp[-2].typeVal)->type) && is_integer((yyvsp[0].typeVal)->type)) (yyval.typeVal) = make_ext((yyvsp[-2].typeVal)->type,0);
        else { error_binary(); (yyval.typeVal)=make_ext(NULL,0); }
      }
#line 1539 "subc.tab.c"
    break;

  case 53: /* binary: unary  */
#line 296 "subc.y"
                                   { (yyval.typeVal) = (yyvsp[0].typeVal); }
#line 1545 "subc.tab.c"
    break;

  case 54: /* binary: binary LOGICAL_AND binary  */
#line 298 "subc.y"
      {
        if(!(yyvsp[-2].typeVal)->type || !(yyvsp[0].typeVal)->type) (yyval.typeVal)=make_ext(NULL,0);
        else if(is_integer((yyvsp[-2].typeVal)->type) && is_integer((yyvsp[0].typeVal)->type)) (yyval.typeVal) = make_ext(make_basic(TYPE_INT),0);
        else { error_binary(); (yyval.typeVal)=make_ext(NULL,0); }
      }
#line 1555 "subc.tab.c"
    break;

  case 55: /* binary: binary LOGICAL_OR binary  */
#line 304 "subc.y"
      {
        if(!(yyvsp[-2].typeVal)->type || !(yyvsp[0].typeVal)->type) (yyval.typeVal)=make_ext(NULL,0);
        else if(is_integer((yyvsp[-2].typeVal)->type) && is_integer((yyvsp[0].typeVal)->type)) (yyval.typeVal) = make_ext(make_basic(TYPE_INT),0);
        else { error_binary(); (yyval.typeVal)=make_ext(NULL,0); }
      }
#line 1565 "subc.tab.c"
    break;

  case 56: /* unary: '(' expr ')'  */
#line 312 "subc.y"
                                 { (yyval.typeVal) = (yyvsp[-1].typeVal); }
#line 1571 "subc.tab.c"
    break;

  case 57: /* unary: '(' unary ')'  */
#line 313 "subc.y"
                                 { (yyval.typeVal) = (yyvsp[-1].typeVal); }
#line 1577 "subc.tab.c"
    break;

  case 58: /* unary: INTEGER_CONST  */
#line 314 "subc.y"
                                 { (yyval.typeVal) = make_ext(make_basic(TYPE_INT), 0); }
#line 1583 "subc.tab.c"
    break;

  case 59: /* unary: CHAR_CONST  */
#line 315 "subc.y"
                                 { (yyval.typeVal) = make_ext(make_basic(TYPE_CHAR),0); }
#line 1589 "subc.tab.c"
    break;

  case 60: /* unary: STRING  */
#line 316 "subc.y"
                                 { (yyval.typeVal) = make_ext(make_pointer(make_basic(TYPE_CHAR)),0); }
#line 1595 "subc.tab.c"
    break;

  case 61: /* unary: ID  */
#line 318 "subc.y"
      {
        if(is_declared((yyvsp[0].stringVal))) { Type *t=get_symbol_type((yyvsp[0].stringVal)); (yyval.typeVal)=make_ext(t,t->kind!=TYPE_ARRAY); }
        else if(is_function((yyvsp[0].stringVal))) { (yyval.typeVal)=make_ext(make_basic(TYPE_FUNC),0); (yyval.typeVal)->name=(yyvsp[0].stringVal); }
        else { error_undeclared(); (yyval.typeVal)=make_ext(NULL,0); }
      }
#line 1605 "subc.tab.c"
    break;

  case 62: /* unary: '-' unary  */
#line 324 "subc.y"
      {
        if(!(yyvsp[0].typeVal)->type) (yyval.typeVal)=make_ext(NULL,0);
        else if(!is_numeric((yyvsp[0].typeVal)->type)) { error_unary(); (yyval.typeVal)=make_ext(NULL,0); }
        else (yyval.typeVal) = make_ext((yyvsp[0].typeVal)->type,0);
      }
#line 1615 "subc.tab.c"
    break;

  case 63: /* unary: '!' unary  */
#line 330 "subc.y"
      {
        if(!(yyvsp[0].typeVal)->type) (yyval.typeVal)=make_ext(NULL,0);
        else if(!is_numeric((yyvsp[0].typeVal)->type)) { error_unary(); (yyval.typeVal)=make_ext(NULL,0); }
        else (yyval.typeVal) = make_ext(make_basic(TYPE_INT),0);
      }
#line 1625 "subc.tab.c"
    break;

  case 64: /* unary: unary INCOP  */
#line 336 "subc.y"
      {
        if(!(yyvsp[-1].typeVal)->type) (yyval.typeVal)=make_ext(NULL,0);
        else if(!(yyvsp[-1].typeVal)->lvalue || !is_numeric((yyvsp[-1].typeVal)->type)) { error_unary(); (yyval.typeVal)=make_ext(NULL,0); }
        else (yyval.typeVal) = make_ext((yyvsp[-1].typeVal)->type,0);
      }
#line 1635 "subc.tab.c"
    break;

  case 65: /* unary: unary DECOP  */
#line 342 "subc.y"
      {
        if(!(yyvsp[-1].typeVal)->type) (yyval.typeVal)=make_ext(NULL,0);
        else if(!(yyvsp[-1].typeVal)->lvalue || !is_numeric((yyvsp[-1].typeVal)->type)) { error_unary(); (yyval.typeVal)=make_ext(NULL,0); }
        else (yyval.typeVal) = make_ext((yyvsp[-1].typeVal)->type,0);
      }
#line 1645 "subc.tab.c"
    break;

  case 66: /* unary: INCOP unary  */
#line 348 "subc.y"
      {
        if(!(yyvsp[0].typeVal)->type) (yyval.typeVal)=make_ext(NULL,0);
        else if(!(yyvsp[0].typeVal)->lvalue || !is_numeric((yyvsp[0].typeVal)->type)) { error_unary(); (yyval.typeVal)=make_ext(NULL,0); }
        else (yyval.typeVal) = make_ext((yyvsp[0].typeVal)->type,0);
      }
#line 1655 "subc.tab.c"
    break;

  case 67: /* unary: DECOP unary  */
#line 354 "subc.y"
      {
        if(!(yyvsp[0].typeVal)->lvalue || !is_numeric((yyvsp[0].typeVal)->type)) error_unary();
        (yyval.typeVal) = make_ext((yyvsp[0].typeVal)->type,0);
      }
#line 1664 "subc.tab.c"
    break;

  case 68: /* unary: '&' unary  */
#line 359 "subc.y"
      {
        if(!(yyvsp[0].typeVal)->type) (yyval.typeVal)=make_ext(NULL,0);
        else if(!(yyvsp[0].typeVal)->lvalue || (yyvsp[0].typeVal)->type->kind==TYPE_ARRAY) { error_addressof(); (yyval.typeVal)=make_ext(NULL,0); }
        else { (yyval.typeVal) = make_ext(make_pointer((yyvsp[0].typeVal)->type),0); }
      }
#line 1674 "subc.tab.c"
    break;

  case 69: /* unary: '*' unary  */
#line 365 "subc.y"
      {
        if(!(yyvsp[0].typeVal)->type) (yyval.typeVal)=make_ext(NULL,0);
        else if((yyvsp[0].typeVal)->type->kind!=TYPE_PTR) { error_indirection(); (yyval.typeVal)=make_ext(NULL,0); }
        else { (yyval.typeVal) = make_ext((yyvsp[0].typeVal)->type->base, (yyvsp[0].typeVal)->type->base->kind!=TYPE_ARRAY); }
      }
#line 1684 "subc.tab.c"
    break;

  case 70: /* unary: unary '[' expr ']'  */
#line 371 "subc.y"
      {
        if(!(yyvsp[-3].typeVal)->type || !(yyvsp[-1].typeVal)->type) { (yyval.typeVal)=make_ext(NULL,0); }
        else {
            if(!is_numeric((yyvsp[-1].typeVal)->type)) { error_subscript(); (yyval.typeVal)=make_ext(NULL,0); }
            else if((yyvsp[-3].typeVal)->type->kind==TYPE_ARRAY || (yyvsp[-3].typeVal)->type->kind==TYPE_PTR)
                (yyval.typeVal) = make_ext((yyvsp[-3].typeVal)->type->base, (yyvsp[-3].typeVal)->type->base->kind!=TYPE_ARRAY);
            else { error_array(); (yyval.typeVal)=make_ext(NULL,0); }
        }
      }
#line 1698 "subc.tab.c"
    break;

  case 71: /* unary: unary '.' ID  */
#line 381 "subc.y"
      {
        if(!(yyvsp[-2].typeVal)->type) (yyval.typeVal)=make_ext(NULL,0);
        else if((yyvsp[-2].typeVal)->type->kind!=TYPE_STRUCT) { error_struct(); (yyval.typeVal)=make_ext(NULL,0); }
        else {
            Type *ft=get_struct_field_type((yyvsp[-2].typeVal)->type->struct_name,(yyvsp[0].stringVal));
            if(!ft) { error_member(); (yyval.typeVal)=make_ext(NULL,0); }
            else (yyval.typeVal)=make_ext(ft, ft->kind!=TYPE_ARRAY);
        }
      }
#line 1712 "subc.tab.c"
    break;

  case 72: /* unary: unary STRUCTOP ID  */
#line 391 "subc.y"
      {
        if(!(yyvsp[-2].typeVal)->type) (yyval.typeVal)=make_ext(NULL,0);
        else if((yyvsp[-2].typeVal)->type->kind!=TYPE_PTR || (yyvsp[-2].typeVal)->type->base->kind!=TYPE_STRUCT) { error_strurctp(); (yyval.typeVal)=make_ext(NULL,0); }
        else {
            Type *ft=get_struct_field_type((yyvsp[-2].typeVal)->type->base->struct_name,(yyvsp[0].stringVal));
            if(!ft) { error_member(); (yyval.typeVal)=make_ext(NULL,0); }
            else (yyval.typeVal)=make_ext(ft, ft->kind!=TYPE_ARRAY);
        }
      }
#line 1726 "subc.tab.c"
    break;

  case 73: /* unary: unary '(' args ')'  */
#line 401 "subc.y"
      {
        if(!(yyvsp[-3].typeVal)->type) (yyval.typeVal)=make_ext(NULL,0);
        else if((yyvsp[-3].typeVal)->type->kind!=TYPE_FUNC || !(yyvsp[-3].typeVal)->name) { error_function(); (yyval.typeVal)=make_ext(NULL,0); }
        else { Type *ret; ParamList *ps; int cnt; get_function((yyvsp[-3].typeVal)->name,&ret,&ps,&cnt); if(arg_count((yyvsp[-1].argVal))!=cnt){ error_arguments(); (yyval.typeVal)=make_ext(NULL,0);} else { ParamList *p=ps; ArgList *a=(yyvsp[-1].argVal); int ok=1; while(p&&a){ if(!same_type(p->type,a->val->type)) ok=0; p=p->next; a=a->next;} if(!ok) error_arguments(); (yyval.typeVal)=make_ext(ret,0); } }
      }
#line 1736 "subc.tab.c"
    break;

  case 74: /* unary: unary '(' ')'  */
#line 407 "subc.y"
      {
        if(!(yyvsp[-2].typeVal)->type) (yyval.typeVal)=make_ext(NULL,0);
        else if((yyvsp[-2].typeVal)->type->kind!=TYPE_FUNC || !(yyvsp[-2].typeVal)->name) { error_function(); (yyval.typeVal)=make_ext(NULL,0); }
        else { Type *ret; ParamList *ps; int cnt; get_function((yyvsp[-2].typeVal)->name,&ret,&ps,&cnt); if(cnt!=0) { error_arguments(); (yyval.typeVal)=make_ext(NULL,0); } else (yyval.typeVal)=make_ext(ret,0); }
      }
#line 1746 "subc.tab.c"
    break;

  case 75: /* unary: SYM_NULL  */
#line 412 "subc.y"
                                 { (yyval.typeVal) = make_ext(make_basic(TYPE_NULL),0); }
#line 1752 "subc.tab.c"
    break;

  case 76: /* args: expr  */
#line 416 "subc.y"
                          { (yyval.argVal) = make_arg((yyvsp[0].typeVal)); }
#line 1758 "subc.tab.c"
    break;

  case 77: /* args: args ',' expr  */
#line 417 "subc.y"
                          { (yyval.argVal) = append_arg((yyvsp[-2].argVal), (yyvsp[0].typeVal)); }
#line 1764 "subc.tab.c"
    break;


#line 1768 "subc.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 420 "subc.y"


/* Epilogue section */

// Print the preamble of error message.
void error_preamble(void) {
  if(!file_name) file_name = "stdin";
  printf("%s:%d: error: ", file_name, get_lineno());
}

void error_incompatible(void) {
  error_preamble();
  printf("incompatible types for assignment operation\n");
}

void error_undeclared(void) {
  error_preamble();
  printf("use of undeclared identifier\n");
}

void error_redeclaration(void) {
  error_preamble();
  printf("redeclaration\n");
}

void error_assignable(void) {
  error_preamble();
  printf("lvalue is not assignable\n");
}

void error_null(void) {
  error_preamble();
  printf("cannot assign 'NULL' to non-pointer type\n");
}
void error_subscript(void) {
  error_preamble();
  printf("array subscript is not an integer\n");
}

void error_incomplete(void) {
  error_preamble();
  printf("incomplete type\n");
}

void error_return(void) {
  error_preamble();
  printf("incompatible return types\n");
}

void error_function(void) {
  error_preamble();
  printf("not a function\n");
}

void error_arguments(void) {
  error_preamble();
  printf("incompatible arguments in function call\n");
}

void error_comparable(void) {
  error_preamble();
  printf("types are not comparable in binary expression\n");
}

void error_binary(void) {
  error_preamble();
  printf("invalid operands to binary expression\n");
}

void error_unary(void) {
  error_preamble();
  printf("invalid argument type to unary expression\n");
}

void error_addressof(void) {
  error_preamble();
  printf("cannot take the address of an rvalue\n");
}

void error_indirection(void) {
  error_preamble();
  printf("indirection requires pointer operand\n");
}

void error_array(void) {
  error_preamble();
  printf("subscripted value is not an array\n");
}

void error_struct(void) {
  error_preamble();
  printf("member reference base type is not a struct\n");
}

void error_member(void) {
  error_preamble();
  printf("no such member in struct\n");
}

void error_strurctp(void) {
  error_preamble();
  printf("member reference base type is not a struct pointer\n");
}


int yyerror(char* s) {
  fprintf(stderr, "%s at line %d\n", s, get_lineno());
  return 0;
}
