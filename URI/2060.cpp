#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, multiplos[4] = { 0, 0, 0, 0 };
    
    scanf( "%d", &n );
    for( int i = 0; i < n; i++ ) {
        scanf( "%d", &l );
        for( int j = 0, k = 2; j < 4; j++, k++ )
            if( l%k == 0 )
                multiplos[j]++;
    }
    for( int i = 0, k = 2; i < 4; i++, k++ )
        printf( "%d Multiplo(s) de %d\n", multiplos[i], k );

    return 0;
}
