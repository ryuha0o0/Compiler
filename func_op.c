
int main(){
int a;
char b;
int* c;
char d[10];
struct temp { int a;} e;
a++;
--a;
b++;
c++; /* error: invalid argument type to unary expression*/
--d; /* error: invalid argument type to unary expression*/
++e; /* error: invalid argument type to unary expression*/
}