/*
 * File Name    : subc.y
 * Description  : a skeleton bison input
 */

%{

/* Prologue section */

#include "subc.h"

int   yylex ();
int   yyerror (char* s);
int   get_lineno();
extern char* file_name;

%}

/* Bison declarations section */

/* yylval types */
%union {
  int   intVal;
  char  *stringVal;
  ExtType *typeVal;
}

/* Precedences and Associativities */
%left   ','
%right  '='
%left   LOGICAL_OR
%left   LOGICAL_AND
%left   EQUOP
%left   RELOP
%left   '+' '-'
%left   '*' '/' '%'
%right  '!' '&' INCOP DECOP
%left   '[' ']' '(' ')' '.' STRUCTOP

%precedence IF
%precedence ELSE

/* Tokens and Types */
%token STRUCT RETURN WHILE FOR BREAK CONTINUE SYM_NULL
%token<intVal> TYPE
%token IF ELSE
%token CHAR_CONST STRING
%token LOGICAL_AND LOGICAL_OR RELOP EQUOP INCOP DECOP STRUCTOP
%token<intVal> INTEGER_CONST
%token<stringVal> ID // identifier name

%type<intVal> pointers
%type<typeVal> type_specifier struct_specifier expr unary binary param_decl func_decl
%type<typeVal> param_list

/* Grammar rules */
%%
program
  : ext_def_list 
  ;

ext_def_list
  : ext_def_list ext_def 
  | %empty 
  ;

ext_def
  : type_specifier pointers ID ';'
      {
        Type *t = $1; if($2) t = make_pointer(t);
        if(is_declared_current($3)) error_redeclaration();
        else add_symbol($3, t);
      }
  | type_specifier pointers ID '[' INTEGER_CONST ']' ';'
      {
        Type *t = $1; if($2) t = make_pointer(t);
        t = make_array(t);
        if(is_declared_current($3)) error_redeclaration();
        else add_symbol($3, t);
      }
  | struct_specifier ';'
  | func_decl compound_stmt { pop_scope(); }
  ;

type_specifier
  : TYPE
      { $$ = make_basic($1==0 ? TYPE_INT : TYPE_CHAR); }
  | struct_specifier
      { $$ = $1; }
  ;

struct_specifier
  : STRUCT ID '{' def_list '}'
      {
        if(!add_struct_type($2)) error_redeclaration();
        $$ = make_struct($2);
      }
  | STRUCT ID
      {
        if(!is_struct_type($2)) error_incomplete();
        $$ = make_struct($2);
      }
  ;

func_decl
  : type_specifier pointers ID '(' { push_scope(); begin_param_list(); } ')'
      {
        int cnt; ParamList *ps = end_param_list(&cnt);
        Type *ret = $1; if($2) ret = make_pointer(ret);
        add_function($3, ret, ps, cnt);
      }
  | type_specifier pointers ID '(' { push_scope(); begin_param_list(); } param_list ')' 
      {
        int cnt; ParamList *ps = end_param_list(&cnt);
        Type *ret = $1; if($2) ret = make_pointer(ret);
        add_function($3, ret, ps, cnt);
      }
  ;

pointers
  : '*'
      { $$ = 1; }
  | %empty
      { $$ = 0; }
  ;

param_list  
  : param_decl 
  | param_list ',' param_decl 
  ;		

param_decl
  : type_specifier pointers ID
      {
        Type *t = $1;
        if($2) t = make_pointer(t);
        if(is_declared_current($3)) error_redeclaration();
        else add_symbol($3, t);
        add_param(t);
        $$ = t;
      }
  | type_specifier pointers ID '[' INTEGER_CONST ']'
      {
        Type *t = $1;
        if($2) t = make_pointer(t);
        t = make_array(t);
        if(is_declared_current($3)) error_redeclaration();
        else add_symbol($3, t);
        add_param(t);
        $$ = t;
      }
  ;

def_list    
  : def_list def 
  | %empty 
  ;

def
  : type_specifier pointers ID ';'
      {
        Type *t = $1; if($2) t = make_pointer(t);
        if(is_declared_current($3)) error_redeclaration();
        else add_symbol($3, t);
      }
  | type_specifier pointers ID '[' INTEGER_CONST ']' ';'
      {
        Type *t = $1; if($2) t = make_pointer(t);
        t = make_array(t);
        if(is_declared_current($3)) error_redeclaration();
        else add_symbol($3, t);
      }
  ;

compound_stmt
  : '{' { push_scope(); } def_list stmt_list '}' { pop_scope(); }
  ;

stmt_list
  : stmt_list stmt 
  | %empty 
  ;

stmt
  : expr ';' 
  | RETURN expr ';' 
  | BREAK ';' 
  | CONTINUE ';' 
  | ';' 
  | compound_stmt 
  | IF '(' expr ')' stmt 
  | IF '(' expr ')' stmt ELSE stmt 
  | WHILE '(' expr ')' stmt 
  | FOR '(' expr_e ';' expr_e ';' expr_e ')' stmt 
  ;

expr_e
  : expr 
  | %empty 
  ;

expr
  : unary '=' expr 
  | binary 
  ;

binary
  : binary RELOP binary 
  | binary EQUOP binary 
  | binary '+' binary 
  | binary '-' binary 
  | binary '*' binary 
  | binary '/' binary 
  | binary '%' binary 
  | unary %prec '=' 
  | binary LOGICAL_AND binary 
  | binary LOGICAL_OR binary 
  ;

unary
  : '(' expr ')' 
  | '(' unary ')' 
  | INTEGER_CONST 
  | CHAR_CONST 
  | STRING
  | ID { if(!is_declared($1)) error_undeclared(); }
  | '-' unary %prec '!' 
  | '!' unary 
  | unary INCOP %prec STRUCTOP 
  | unary DECOP %prec STRUCTOP 
  | INCOP unary %prec '!' 
  | DECOP unary %prec '!' 
  | '&' unary 
  | '*' unary %prec '!' 
  | unary '[' expr ']' 
  | unary '.' ID 
  | unary STRUCTOP ID 
  | unary '(' args ')' 
  | unary '(' ')' 
  | SYM_NULL 
  ;

args
  : expr 
  | args ',' expr 
  ;

%%

/* Epilogue section */

// Print the preamble of error message.
void error_preamble(void) {
  if(!file_name) file_name = "stdin";
  printf("%s:%d: error: ", file_name, get_lineno());
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

void error_incompatible(void) {
  error_preamble();
  printf("incompatible types for assignment operation\n");
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

int yyerror(char* s) {
  fprintf(stderr, "%s at line %d\n", s, get_lineno());
  return 0;
}