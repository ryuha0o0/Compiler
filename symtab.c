#include <stdlib.h>
#include <string.h>
#include "symtab.h"
#include "subc.h"

/* scope stack for variables */
static Scope *scope_stack = NULL;

/* struct definitions */
typedef struct StructInfo {
    char *name;
    Field *fields;
    struct StructInfo *next;
} StructInfo;

/* function info */
typedef struct FuncInfo {
    char *name;
    Type *ret;
    ParamList *params;
    int param_cnt;
    struct FuncInfo *next;
} FuncInfo;

static StructInfo *struct_list = NULL;
static FuncInfo *func_list = NULL;
static ParamList *curr_params = NULL;
static ParamList *param_tail = NULL;
static StructInfo *curr_struct = NULL;
static Type *curr_func_ret = NULL;

/*---------------- type constructors ----------------*/
Type *make_basic(TypeKind kind) {
    Type *t = (Type*)malloc(sizeof(Type));
    t->kind = kind;
    t->base = NULL;
    t->struct_name = NULL;
    t->fields = NULL;
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

ExtType *make_ext(Type *t, int lv) {
    ExtType *e = (ExtType*)malloc(sizeof(ExtType));
    e->type = t;
    e->lvalue = lv;
    e->name = NULL;
    return e;
}

/*---------------- scope management ----------------*/
void push_scope() {
    Scope *s = (Scope*)malloc(sizeof(Scope));
    s->symbols = NULL;
    s->next = scope_stack;
    scope_stack = s;
}

void pop_scope() {
    if(!scope_stack) return;
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

static Symbol *find_symbol(const char *name) {
    for(Scope *s = scope_stack; s; s = s->next) {
        for(Symbol *sym = s->symbols; sym; sym = sym->next) {
            if(strcmp(sym->name, name) == 0) return sym;
        }
    }
    return NULL;
}

int is_declared(const char *name) { return find_symbol(name)!=NULL; }

int is_declared_current(const char *name) {
    if(!scope_stack) return 0;
    for(Symbol *sym = scope_stack->symbols; sym; sym = sym->next) {
        if(strcmp(sym->name, name)==0) return 1;
    }
    return 0;
}

Type *get_symbol_type(const char *name) {
    Symbol *s = find_symbol(name);
    return s ? s->type : NULL;
}

void add_symbol(const char *name, Type *type) {
    if(!scope_stack) push_scope();
    Symbol *sym = (Symbol*)malloc(sizeof(Symbol));
    sym->name = strdup(name);
    sym->type = type;
    sym->next = scope_stack->symbols;
    scope_stack->symbols = sym;
}

/*---------------- struct management ----------------*/
void start_struct(const char *name) {
    curr_struct = (StructInfo*)malloc(sizeof(StructInfo));
    curr_struct->name = strdup(name);
    curr_struct->fields = NULL;
    curr_struct->next = NULL;
}

void add_field(const char *name, Type *type) {
    if(!curr_struct) return;
    Field *f = (Field*)malloc(sizeof(Field));
    f->name = strdup(name);
    f->type = type;
    f->next = curr_struct->fields;
    curr_struct->fields = f;
}

Type *end_struct(int *ok) {
    if(!curr_struct) return NULL;
    for(StructInfo *s=struct_list; s; s=s->next) {
        if(strcmp(s->name,curr_struct->name)==0) {
            if(ok) *ok = 0;
            /* discard */
            Field *f=curr_struct->fields; while(f){Field*tmp=f->next;free(f->name);free(f);f=tmp;}
            free(curr_struct->name); free(curr_struct); curr_struct=NULL;
            return NULL;
        }
    }
    curr_struct->next = struct_list;
    struct_list = curr_struct;
    if(ok) *ok = 1;
    Type *t = make_struct(curr_struct->name);
    t->fields = curr_struct->fields;
    curr_struct=NULL;
    return t;
}

int is_struct_type(const char *name) {
    for(StructInfo *s=struct_list; s; s=s->next) if(strcmp(s->name,name)==0) return 1;
    return 0;
}

Type *get_struct_field_type(const char *struct_name, const char *field) {
    for(StructInfo *s=struct_list; s; s=s->next) {
        if(strcmp(s->name,struct_name)==0) {
            for(Field *f=s->fields; f; f=f->next) {
                if(strcmp(f->name,field)==0) return f->type;
            }
        }
    }
    return NULL;
}

/*---------------- function management ----------------*/
void begin_param_list() { curr_params = param_tail = NULL; }

void add_param(Type *type) {
    ParamList *p=(ParamList*)malloc(sizeof(ParamList));
    p->type=type; p->next=NULL;
    if(!curr_params) curr_params=p; else param_tail->next=p;
    param_tail=p;
}

ParamList *end_param_list(int *count) {
    int c=0; for(ParamList *p=curr_params;p;p=p->next) c++; if(count) *count=c;
    ParamList *ret=curr_params; curr_params=param_tail=NULL; return ret;
}

int add_function(const char *name, Type *ret, ParamList *params, int param_cnt) {
    for(FuncInfo *f=func_list; f; f=f->next) {
        if(strcmp(f->name,name)==0) return 0;
    }
    FuncInfo *fi=(FuncInfo*)malloc(sizeof(FuncInfo));
    fi->name=strdup(name); fi->ret=ret; fi->params=params; fi->param_cnt=param_cnt;
    fi->next=func_list; func_list=fi; return 1;
}

int get_function(const char *name, Type **ret, ParamList **params, int *cnt) {
    for(FuncInfo *f=func_list; f; f=f->next) {
        if(strcmp(f->name,name)==0) {
            if(ret) *ret=f->ret; if(params) *params=f->params; if(cnt) *cnt=f->param_cnt; return 1;
        }
    }
    return 0;
}

int is_function(const char *name) { return get_function(name,NULL,NULL,NULL); }

void set_current_return(Type *t) { curr_func_ret=t; }
Type *get_current_return() { return curr_func_ret; }

/*---------------- argument list helpers ----------------*/
ArgList *make_arg(ExtType *v) {
    ArgList *a=(ArgList*)malloc(sizeof(ArgList));
    a->val=v; a->next=NULL; return a;
}

ArgList *append_arg(ArgList *list, ExtType *v) {
    ArgList *a=make_arg(v); if(!list) return a; ArgList *p=list; while(p->next)p=p->next; p->next=a; return list;
}

int arg_count(ArgList *a) { int c=0; while(a){c++; a=a->next;} return c; }

/*---------------- type utilities ----------------*/
int same_type(Type *a, Type *b) {
    if(!a||!b) return 0;
    if(a->kind!=b->kind) return 0;
    switch(a->kind){
        case TYPE_INT:
        case TYPE_CHAR:
        case TYPE_NULL:
            return 1;
        case TYPE_PTR:
        case TYPE_ARRAY:
            return same_type(a->base,b->base);
        case TYPE_STRUCT:
            return strcmp(a->struct_name,b->struct_name)==0;
        default: return 0;
    }
}

int is_numeric(Type *t) { return t&& (t->kind==TYPE_INT || t->kind==TYPE_CHAR); }
int is_pointer(Type *t) { return t && t->kind==TYPE_PTR; }