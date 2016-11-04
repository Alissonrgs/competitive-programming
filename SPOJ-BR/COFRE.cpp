#include <cstdio>

int main() {
    int n, d, vj, vz, t = 1;

    while( scanf( "%d", &n ) && n ) {
        d = 0;
        printf( "Teste %d\n", t++ );
        while( n-- ) {
            scanf( "%d%d", &vj, &vz );
            if( d < 0 ) vj += d;
            else vz -= d;
            d = vj - vz;
            printf( "%d\n", d );
        }
        printf( "\n" );
    }

    return 0;
}
