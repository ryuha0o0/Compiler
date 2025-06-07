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

static int in_struct = 0;

%}

/* Bison declarations section */

/* yylval types */
%union {
  int   intVal;
  char  *stringVal;
  ExtType *typeVal;
  ArgList *argVal;
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
%type<argVal> args

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
  | func_decl compound_stmt { set_current_return(NULL); pop_scope(); }
  ;

type_specifier
  : TYPE
      { $$ = make_basic($1==0 ? TYPE_INT : TYPE_CHAR); }
  | struct_specifier
      { $$ = $1; }
  ;

struct_specifier
  : STRUCT ID '{' { if(is_struct_type($2)) error_redeclaration(); in_struct=1; start_struct($2); } def_list '}'
      {
        int ok; Type *t = end_struct(&ok); in_struct=0;
        $$ = t ? t : make_struct($2);
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
        if(!add_function($3, ret, ps, cnt)) error_redeclaration();
        set_current_return(ret);
      }
  | type_specifier pointers ID '(' { push_scope(); begin_param_list(); } param_list ')'
      {
        int cnt; ParamList *ps = end_param_list(&cnt);
        Type *ret = $1; if($2) ret = make_pointer(ret);
        if(!add_function($3, ret, ps, cnt)) error_redeclaration();
        set_current_return(ret);
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
        if(in_struct) {
          add_field($3, t);
        } else {
          if(is_declared_current($3)) error_redeclaration();
          else add_symbol($3, t);
        }
      }
  | type_specifier pointers ID '[' INTEGER_CONST ']' ';'
      {
        Type *t = $1; if($2) t = make_pointer(t);
        t = make_array(t);
        if(in_struct) {
          add_field($3, t);
        } else {
          if(is_declared_current($3)) error_redeclaration();
          else add_symbol($3, t);
        }
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
      {
        Type *rt = get_current_return();
        if(rt && !same_type(rt, $2->type)) error_return();
      }
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
      {
        if(!$1->type || !$3->type) { $$ = make_ext(NULL,0); }
        else if(!$1->lvalue) { error_assignable(); $$ = make_ext($1->type,0); }
        else if($3->type->kind==TYPE_NULL && !is_pointer($1->type)) { error_null(); $$=make_ext($1->type,0); }
        else if(!same_type($1->type,$3->type)) { error_incompatible(); $$=make_ext($1->type,0); }
        else $$ = make_ext($1->type,0);
      }
  | binary { $$ = $1; }
  ;

binary
  : binary RELOP binary
      {
        if(!$1->type || !$3->type) $$=make_ext(NULL,0);
        else if(is_numeric($1->type) && is_numeric($3->type)) $$ = make_ext(make_basic(TYPE_INT),0);
        else { error_comparable(); $$=make_ext(NULL,0); }
      }
  | binary EQUOP binary
      {
        if(!$1->type || !$3->type) $$=make_ext(NULL,0);
        else if((is_numeric($1->type)&&is_numeric($3->type)) || (is_pointer($1->type)&&is_pointer($3->type)))
            $$ = make_ext(make_basic(TYPE_INT),0);
        else { error_comparable(); $$=make_ext(NULL,0); }
      }
  | binary '+' binary
      {
        if(!$1->type || !$3->type) $$=make_ext(NULL,0);
        else if(is_numeric($1->type) && is_numeric($3->type)) $$ = make_ext($1->type,0);
        else { error_binary(); $$=make_ext(NULL,0); }
      }
  | binary '-' binary
      {
        if(!$1->type || !$3->type) $$=make_ext(NULL,0);
        else if(is_numeric($1->type) && is_numeric($3->type)) $$ = make_ext($1->type,0);
        else { error_binary(); $$=make_ext(NULL,0); }
      }
  | binary '*' binary
      {
        if(!$1->type || !$3->type) $$=make_ext(NULL,0);
        else if(is_numeric($1->type) && is_numeric($3->type)) $$ = make_ext($1->type,0);
        else { error_binary(); $$=make_ext(NULL,0); }
      }
  | binary '/' binary
      {
        if(!$1->type || !$3->type) $$=make_ext(NULL,0);
        else if(is_numeric($1->type) && is_numeric($3->type)) $$ = make_ext($1->type,0);
        else { error_binary(); $$=make_ext(NULL,0); }
      }
  | binary '%' binary
      {
        if(!$1->type || !$3->type) $$=make_ext(NULL,0);
        else if(is_numeric($1->type) && is_numeric($3->type)) $$ = make_ext($1->type,0);
        else { error_binary(); $$=make_ext(NULL,0); }
      }
  | unary %prec '='                { $$ = $1; }
  | binary LOGICAL_AND binary
      {
        if(!$1->type || !$3->type) $$=make_ext(NULL,0);
        else if(is_numeric($1->type) && is_numeric($3->type)) $$ = make_ext(make_basic(TYPE_INT),0);
        else { error_binary(); $$=make_ext(NULL,0); }
      }
  | binary LOGICAL_OR binary
      {
        if(!$1->type || !$3->type) $$=make_ext(NULL,0);
        else if(is_numeric($1->type) && is_numeric($3->type)) $$ = make_ext(make_basic(TYPE_INT),0);
        else { error_binary(); $$=make_ext(NULL,0); }
      }
  ;

unary
  : '(' expr ')'                 { $$ = $2; }
  | '(' unary ')'                { $$ = $2; }
  | INTEGER_CONST                { $$ = make_ext(make_basic(TYPE_INT), 0); }
  | CHAR_CONST                   { $$ = make_ext(make_basic(TYPE_CHAR),0); }
  | STRING                       { $$ = make_ext(make_pointer(make_basic(TYPE_CHAR)),0); }
  | ID
      {
        if(is_declared($1)) { Type *t=get_symbol_type($1); $$=make_ext(t,t->kind!=TYPE_ARRAY); }
        else if(is_function($1)) { $$=make_ext(make_basic(TYPE_FUNC),0); $$->name=$1; }
        else { error_undeclared(); $$=make_ext(NULL,0); }
      }
  | '-' unary %prec '!'
      {
        if(!$2->type) $$=make_ext(NULL,0);
        else if(!is_numeric($2->type)) { error_unary(); $$=make_ext(NULL,0); }
        else $$ = make_ext($2->type,0);
      }
  | '!' unary
      {
        if(!$2->type) $$=make_ext(NULL,0);
        else if(!is_numeric($2->type)) { error_unary(); $$=make_ext(NULL,0); }
        else $$ = make_ext(make_basic(TYPE_INT),0);
      }
  | unary INCOP %prec STRUCTOP
      {
        if(!$1->type) $$=make_ext(NULL,0);
        else if(!$1->lvalue || !is_numeric($1->type)) { error_unary(); $$=make_ext(NULL,0); }
        else $$ = make_ext($1->type,0);
      }
  | unary DECOP %prec STRUCTOP
      {
        if(!$1->type) $$=make_ext(NULL,0);
        else if(!$1->lvalue || !is_numeric($1->type)) { error_unary(); $$=make_ext(NULL,0); }
        else $$ = make_ext($1->type,0);
      }
  | INCOP unary %prec '!'
      {
        if(!$2->type) $$=make_ext(NULL,0);
        else if(!$2->lvalue || !is_numeric($2->type)) { error_unary(); $$=make_ext(NULL,0); }
        else $$ = make_ext($2->type,0);
      }
  | DECOP unary %prec '!'
      {
        if(!$2->lvalue || !is_numeric($2->type)) error_unary();
        $$ = make_ext($2->type,0);
      }
  | '&' unary
      {
        if(!$2->type) $$=make_ext(NULL,0);
        else if(!$2->lvalue || $2->type->kind==TYPE_ARRAY) { error_addressof(); $$=make_ext(NULL,0); }
        else { $$ = make_ext(make_pointer($2->type),0); }
      }
  | '*' unary %prec '!'
      {
        if(!$2->type) $$=make_ext(NULL,0);
        else if($2->type->kind!=TYPE_PTR) { error_indirection(); $$=make_ext(NULL,0); }
        else { $$ = make_ext($2->type->base, $2->type->base->kind!=TYPE_ARRAY); }
      }
  | unary '[' expr ']'
      {
        if(!$1->type || !$3->type) { $$=make_ext(NULL,0); }
        else {
            if(!is_numeric($3->type)) { error_subscript(); $$=make_ext(NULL,0); }
            else if($1->type->kind==TYPE_ARRAY || $1->type->kind==TYPE_PTR)
                $$ = make_ext($1->type->base, $1->type->base->kind!=TYPE_ARRAY);
            else { error_array(); $$=make_ext(NULL,0); }
        }
      }
  | unary '.' ID
      {
        if(!$1->type) $$=make_ext(NULL,0);
        else if($1->type->kind!=TYPE_STRUCT) { error_struct(); $$=make_ext(NULL,0); }
        else {
            Type *ft=get_struct_field_type($1->type->struct_name,$3);
            if(!ft) { error_member(); $$=make_ext(NULL,0); }
            else $$=make_ext(ft, ft->kind!=TYPE_ARRAY);
        }
      }
  | unary STRUCTOP ID
      {
        if(!$1->type) $$=make_ext(NULL,0);
        else if($1->type->kind!=TYPE_PTR || $1->type->base->kind!=TYPE_STRUCT) { error_strurctp(); $$=make_ext(NULL,0); }
        else {
            Type *ft=get_struct_field_type($1->type->base->struct_name,$3);
            if(!ft) { error_member(); $$=make_ext(NULL,0); }
            else $$=make_ext(ft, ft->kind!=TYPE_ARRAY);
        }
      }
  | unary '(' args ')'
      {
        if(!$1->type) $$=make_ext(NULL,0);
        else if($1->type->kind!=TYPE_FUNC || !$1->name) { error_function(); $$=make_ext(NULL,0); }
        else { Type *ret; ParamList *ps; int cnt; get_function($1->name,&ret,&ps,&cnt); if(arg_count($3)!=cnt){ error_arguments(); $$=make_ext(NULL,0);} else { ParamList *p=ps; ArgList *a=$3; int ok=1; while(p&&a){ if(!same_type(p->type,a->val->type)) ok=0; p=p->next; a=a->next;} if(!ok) error_arguments(); $$=make_ext(ret,0); } }
      }
  | unary '(' ')'
      {
        if(!$1->type) $$=make_ext(NULL,0);
        else if($1->type->kind!=TYPE_FUNC || !$1->name) { error_function(); $$=make_ext(NULL,0); }
        else { Type *ret; ParamList *ps; int cnt; get_function($1->name,&ret,&ps,&cnt); if(cnt!=0) { error_arguments(); $$=make_ext(NULL,0); } else $$=make_ext(ret,0); }
      }
  | SYM_NULL                     { $$ = make_ext(make_basic(TYPE_NULL),0); }
  ;

args
  : expr                  { $$ = make_arg($1); }
  | args ',' expr         { $$ = append_arg($1, $3); }
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
