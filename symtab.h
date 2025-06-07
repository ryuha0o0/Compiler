#ifndef SYMTAB_H
#define SYMTAB_H

struct ParamList;
struct Field;

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

void start_struct(const char *name);
void add_field(const char *name, struct Type *type);
struct Type *end_struct(int *ok);
int is_struct_type(const char *name);
struct Type *get_struct_field_type(const char *struct_name, const char *field);

void begin_param_list();
void add_param(struct Type *type);
struct ParamList* end_param_list(int *count);

int add_function(const char *name, struct Type *ret, struct ParamList *params, int param_cnt);
int get_function(const char *name, struct Type **ret, struct ParamList **params, int *param_cnt);
int is_function(const char *name);
void set_current_return(struct Type *t);
struct Type *get_current_return();

typedef struct ArgList {
    struct ExtType *val;
    struct ArgList *next;
} ArgList;

ArgList *make_arg(struct ExtType *v);
ArgList *append_arg(ArgList *list, struct ExtType *v);
int arg_count(ArgList *list);

#endif