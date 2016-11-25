#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, c, m;
    
    scanf( "%d", &t );
    for( int i = 1; i <= t; i++ ) {
        scanf( "%d", &n );
        m = 0;
        while( n-- )
            scanf( "%d", &c ), m = max( m, c );
        printf( "Case %d: %d\n", i, m );
    }

    return 0;
}
