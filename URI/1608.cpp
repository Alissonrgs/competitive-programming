#include <bits/stdc++.h>
using namespace std;


int main() {
    int t, D, I, B, ing[105], bolo, q, max_bolo;
    
    scanf( "%d", &t );
    while( t-- ) {
        scanf( "%d%d%d", &D, &I, &B );
        for( int i = 0; i < I; i++ )
            scanf( "%d", &ing[i] );
        max_bolo = 0;
        for( int i = 0; i < B; i++ ) {
            scanf( "%d", &q );
            bolo = 0;
            for( int j = 0, id, total; j < q; j++ ) {
                scanf( "%d%d", &id, &total );
                bolo += total*ing[id];
            }
            max_bolo = max( max_bolo, D/bolo );
        }
        printf( "%d\n", max_bolo );
    }

    return 0;
}
