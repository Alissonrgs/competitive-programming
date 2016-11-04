#include <cstdio>
#include <cmath>
#include <algorithm>
using std::sort;

bool troca( int a, int b ) {
    return abs( a ) < abs( b );
}

int main() {
    int p, n, andar[50005], qnt;

    scanf( "%d", &p );
    while( p-- ) {
        qnt = 1;
        scanf( "%d", &n );
        for( int i=0; i<n; i++ )
            scanf( "%d", &andar[i] );

        sort( &andar[0], &andar[n], troca );

        for( int i=1; i<n; i++ )
            if( ( andar[i-1] < 0 && andar[i] > 0 ) || ( andar[i-1] > 0 && andar[i] < 0 ) ) qnt++;
        if( n == 0 ) qnt = 0;
        printf( "%d\n", qnt );
    }

    return 0;
}
