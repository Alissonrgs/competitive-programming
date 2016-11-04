#include <cstdio>

int main() {
    int n, soma, v, t = 1;
    char c;

    while( scanf( "%d", &n ) && n ) {
        scanf( "%d", &v );
        soma = v;
        n--;
        while( n-- ) {
            scanf( "%c%d", &c, &v );
            soma += ( c == '+' ? v: -v );
        }

        printf( "Teste %d\n%d\n\n", t++, soma );
    }

    return 0;
}
