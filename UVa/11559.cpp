#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, b, h, w, p, e, pmin, emax;
    
    while( ~scanf( "%d%d%d%d", &n, &b, &h, &w ) ) {
        pmin = INT_MAX;
        
        for( int i = 0; i < h; i++ ) {
            scanf( "%d", &p );
            
            emax = 0;
            for( int j = 0; j < w; j++ ) {
                scanf( "%d", &e );
                emax = max( emax, e );
            }
            if( emax >= n && b >= p*n )
                pmin = min( pmin, p*n );
        }
                
        if( pmin == INT_MAX )
            printf( "stay home\n" );
        else
            printf( "%d\n", pmin );
    }

    return 0;
}
