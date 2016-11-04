#include <cstdio>

int main() {
    int n, tam, qnt, qm;

    while( scanf( "%d", &n ) && n ) {
        qm = 0;
        while( n-- ) {
            scanf( "%d%d", &tam, &qnt );
            qm += ( qnt&1 ? qnt-1: qnt );
        }

        printf( "%d\n", qm/4 );
    }

    return 0;
}
