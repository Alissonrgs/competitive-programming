#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, high, low, wall[50];
    
    scanf( "%d", &t );
    for( int _case = 1; _case <= t; _case++ ) {
        high = low = 0;
        scanf( "%d", &n );
        for( int i = 0; i < n; i++ ) {
            scanf( "%d", &wall[i] );
            if( i > 0 ) {
                high = ( wall[i] > wall[i-1] ? high+1 : high );
                low = ( wall[i] < wall[i-1] ? low+1 : low );
            }
        }
        printf( "Case %d: %d %d\n", _case, high, low );
    }

    return 0;
}
