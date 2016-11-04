#include <cstdio>
#include <algorithm>
using std::max;

int main() {
    int s, n, tam[2005], val[2005];

    scanf( "%d%d", &s, &n );
    for( int i=1; i<=n; i++ )
        scanf( "%d%d", &tam[i], &val[i] );

    int t[n+1][s+1];

    for( int p=0; p<=s; p++ ) {
        t[0][p] = 0;
        for( int i=1; i<=n; i++ )
            if( tam[i] > p )
                t[i][p] = t[i-1][p];
            else
                t[i][p] = max( t[i-1][p], t[i-1][ p - tam[i] ] + val[i] );
    }
    printf( "%d\n", t[n][s] );

    return 0;
}
