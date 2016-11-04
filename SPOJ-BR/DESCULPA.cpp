#include <cstdio>
#include <algorithm>
using std::max;

int main() {
    int c, f, n=1, nc[55], npd[55];

    while( scanf( "%d%d", &c, &f ) && c && f ) {
        for( int i=1; i<=f; i++ )
            scanf( "%d%d", &nc[i], &npd[i] );

        int t[f+1][c+1], max_pd = 0;

        for( int p=0; p<=c; p++ ) {
            t[0][p] = 0;
            for( int i=1; i<=f; i++ )
                if( nc[i] > p )
                    t[i][p] = t[i-1][p];
                else
                    t[i][p] = max( t[i-1][p], t[i-1][ p - nc[i] ] + npd[i] );
        }

        printf( "Teste %d\n%d\n\n", n++, t[f][c] );
    }

    return 0;
}
