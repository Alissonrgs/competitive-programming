#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, prev_V = 0, V;
    
    scanf( "%d", &n );
    for( int i = 1; i <= n; i++ ) {
        scanf( "%d", &V );
        if( V < prev_V ) {
            printf( "%d\n", i );
            return 0;
        }
        prev_V = V;
    }
    printf( "0\n" );

    return 0;
}
