#include <cstdio>

int main() {
    int n, v, t = 1;

    while( scanf( "%d", &v ) && v ) {
        printf( "Teste %d\n", t++ );
        printf( "%d ", v/50 );
        v %= 50;
        printf( "%d ", v/10 );
        v %= 10;
        printf( "%d ", v/5 );
        v %= 5;
        printf( "%d\n\n", v );
    }

    return 0;
}
