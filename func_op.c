
int main(){
int *a;
int b;
int c[10];
a = 0; /* error: incompatible types for assignment operation */
a = NULL; /* OK */
a = &b; /* OK */
a = *b; /* error: indirection requires pointer operand */
&b = a; /* error: lvalue is not assignable */
b = &c; /* error: cannot take the address of an rvalue */
b = 0; /* OK */
b = *a; /* OK */
}