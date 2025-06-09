int main(){
int a[5];
int b;
char c;
b = a[1];
a[1] = b;
a[1] = b[1]; /* error: subscripted value is not an array */
a[b];
a[c]; /* error: array subscript is not an integer */
}
