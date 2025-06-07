/*
 * File Name    : subc.h
 * Description  : A header file for the subc program.
 */

#ifndef __SUBC_H__
#define __SUBC_H__

#include <stdio.h>
#include <string.h>
#include "symtab.h"

typedef enum {
    TYPE_INT,
    TYPE_CHAR,
    TYPE_PTR,
    TYPE_ARRAY,
    TYPE_STRUCT,
    TYPE_FUNC,
    TYPE_NULL
} TypeKind;

typedef struct Field {
    char *name;
    struct Type *type;
    struct Field *next;
} Field;

typedef struct Type {
    TypeKind kind;
    struct Type *base;
    char *struct_name; /* for struct */
    Field *fields;     /* for struct */
} Type;

typedef struct ExtType {
    Type *type;
    int lvalue; /* 1 if expression can appear on LHS */
    char *name;  /* for function identifiers */
} ExtType;

// Global file name for error messages
extern char *file_name;

// Helper to retrieve current line number from lexer
int get_lineno();

// Print error message preamble
void error_preamble(void);
void error_undeclared(void);
void error_redeclaration(void);

/* symbol table helpers */
void add_symbol(const char *name, Type *type);
int is_declared(const char *name);
int is_declared_current(const char *name);
Type *get_symbol_type(const char *name);

/* struct type helpers */
int add_struct_type(const char *name);
int is_struct_type(const char *name);

/* function helpers */
typedef struct ParamList {
    Type *type;
    struct ParamList *next;
} ParamList;

void begin_param_list();
void add_param(Type *type);
ParamList *end_param_list(int *count);

int get_function(const char *name, Type **ret, ParamList **params, int *param_cnt);

/* type constructors */
Type *make_basic(TypeKind kind);
Type *make_pointer(Type *base);
Type *make_array(Type *base);
Type *make_struct(const char *name);

/* helpers for extended types */
ExtType *make_ext(Type *t, int lvalue);
int same_type(Type *a, Type *b);
int is_numeric(Type *t);
int is_pointer(Type *t);

/* struct field helpers */
void start_struct(const char *name);
void add_field(const char *name, Type *type);
Type *end_struct(int *ok);
Type *get_struct_field_type(const char *struct_name, const char *field);

/* function related helpers */
int add_function(const char *name, Type *ret, ParamList *params, int param_cnt);
int is_function(const char *name);
void set_current_return(Type *t);
Type *get_current_return();


#endif