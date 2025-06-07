#ifndef SYMTAB_H
#define SYMTAB_H

struct ParamList;

typedef struct Symbol {
    char *name;
    struct Type *type;
    struct Symbol *next;
} Symbol;

typedef struct Scope {
    Symbol *symbols;
    struct Scope *next;
} Scope;

void push_scope();
void pop_scope();
int is_declared(const char *name);
int is_declared_current(const char *name);
struct Type* get_symbol_type(const char *name);
void add_symbol(const char *name, struct Type *type);

int add_struct_type(const char *name);
int is_struct_type(const char *name);

void begin_param_list();
void add_param(struct Type *type);
struct ParamList* end_param_list(int *count);

void add_function(const char *name, struct Type *ret, struct ParamList *params, int param_cnt);
int get_function(const char *name, struct Type **ret, struct ParamList **params, int *param_cnt);

#endif