#include <stdlib.h>
#include <string.h>
#include "symtab.h"
#include "subc.h"

static Scope *scope_stack = NULL;

typedef struct StructType {
    char *name;
    struct StructType *next;
} StructType;

typedef struct FuncParam {
    Type *type;
    struct FuncParam *next;
} FuncParam;

typedef struct FuncInfo {
    char *name;
    Type *ret;
    FuncParam *params;
    int param_cnt;
    struct FuncInfo *next;
} FuncInfo;

static StructType *struct_list = NULL;
static FuncInfo *func_list = NULL;

static ParamList *curr_params = NULL;
static ParamList *param_tail = NULL;

Type *make_basic(TypeKind kind) {
    Type *t = (Type*)malloc(sizeof(Type));
    t->kind = kind;
    t->base = NULL;
    t->struct_name = NULL;
    return t;
}

Type *make_pointer(Type *base) {
    Type *t = make_basic(TYPE_PTR);
    t->base = base;
    return t;
}

Type *make_array(Type *base) {
    Type *t = make_basic(TYPE_ARRAY);
    t->base = base;
    return t;
}

Type *make_struct(const char *name) {
    Type *t = make_basic(TYPE_STRUCT);
    t->struct_name = strdup(name);
    return t;
}

void push_scope() {
    Scope *s = (Scope *)malloc(sizeof(Scope));
    s->symbols = NULL;
    s->next = scope_stack;
    scope_stack = s;
}

void pop_scope() {
    if (!scope_stack) return;
    Symbol *sym = scope_stack->symbols;
    while(sym) {
        Symbol *tmp = sym->next;
        free(sym->name);
        free(sym);
        sym = tmp;
    }
    Scope *tmp = scope_stack;
    scope_stack = scope_stack->next;
    free(tmp);
}

int is_declared(const char *name) {
    for(Scope *s = scope_stack; s; s = s->next) {
        for(Symbol *sym = s->symbols; sym; sym = sym->next) {
            if(strcmp(sym->name, name) == 0) return 1;
        }
    }
    return 0;
}

int is_declared_current(const char *name) {
    if(!scope_stack) return 0;
    for(Symbol *sym = scope_stack->symbols; sym; sym = sym->next) {
        if(strcmp(sym->name, name) == 0) return 1;
    }
    return 0;
}

Type* get_symbol_type(const char *name) {
    for(Scope *s = scope_stack; s; s = s->next) {
        for(Symbol *sym = s->symbols; sym; sym = sym->next) {
            if(strcmp(sym->name, name) == 0) return sym->type;
        }
    }
    return NULL;
}

void add_symbol(const char *name, Type *type) {
    if(!scope_stack) push_scope();
    Symbol *sym = (Symbol *)malloc(sizeof(Symbol));
    sym->name = strdup(name);
    sym->type = type;
    sym->next = scope_stack->symbols;
    scope_stack->symbols = sym;
}

int add_struct_type(const char *name) {
    for(StructType *s = struct_list; s; s = s->next) {
        if(strcmp(s->name, name) == 0) return 0;
    }
    StructType *st = (StructType*)malloc(sizeof(StructType));
    st->name = strdup(name);
    st->next = struct_list;
    struct_list = st;
    return 1;
}

int is_struct_type(const char *name) {
    for(StructType *s = struct_list; s; s = s->next) {
        if(strcmp(s->name, name) == 0) return 1;
    }
    return 0;
}

void begin_param_list() {
    curr_params = NULL;
    param_tail = NULL;
}

void add_param(Type *type) {
    ParamList *p = (ParamList*)malloc(sizeof(ParamList));
    p->type = type;
    p->next = NULL;
    if(!curr_params) curr_params = p;
    else param_tail->next = p;
    param_tail = p;
}

ParamList *end_param_list(int *count) {
    int c = 0;
    for(ParamList *p = curr_params; p; p = p->next) c++;
    if(count) *count = c;
    ParamList *ret = curr_params;
    curr_params = param_tail = NULL;
    return ret;
}

void add_function(const char *name, Type *ret, ParamList *params, int param_cnt) {
    FuncInfo *f = (FuncInfo*)malloc(sizeof(FuncInfo));
    f->name = strdup(name);
    f->ret = ret;
    f->params = (FuncParam*)params; /* reuse struct */
    f->param_cnt = param_cnt;
    f->next = func_list;
    func_list = f;
}

int get_function(const char *name, Type **ret, ParamList **params, int *param_cnt) {
    for(FuncInfo *f = func_list; f; f = f->next) {
        if(strcmp(f->name, name) == 0) {
            if(ret) *ret = f->ret;
            if(params) *params = (ParamList*)f->params;
            if(param_cnt) *param_cnt = f->param_cnt;
            return 1;
        }
    }
    return 0;
}