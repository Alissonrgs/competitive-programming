#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, s, n, t1, t2, t3, d1, d2, pi, pj[15][2], win;
    
    while( scanf( "%d%d", &p, &s ) && p ) {
        scanf( "%d%d%d", &t1, &t2, &t3 );
        scanf( "%d", &n );
        win = 0;
        pi = 1;
        memset( pj, 0, sizeof pj );
        for( int i = 0, d; i < n; i++ ) {
            scanf( "%d%d", &d1, &d2 );
            d = d1 + d2;
            
            while( pj[ pi ][1] )
                pj[ pi ][1] = 0,
                pi = ( pi+1 > p ? pi+1-p : pi+1 );
                
            pj[ pi ][0] += d;
            if( pj[ pi ][0] == t1 || pj[ pi ][0] == t2 || pj[ pi ][0] == t3 )
                pj[ pi ][1] = 1;
            if( !win && pj[ pi ][0] > s )
                win = pi;
                
            pi = ( pi+1 > p ? pi+1-p : pi+1 );
        }
        printf( "%d\n", win );
    }

    return 0;
}
