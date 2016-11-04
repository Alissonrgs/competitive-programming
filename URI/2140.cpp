#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, M[] = { 2, 5, 10, 20, 50, 100 }, t;
    bool possible;
    
    while( scanf( "%d%d", &n, &m ) && n ) {
        t = m - n;
        possible = false;
        
        for( int i = 0; i < 6 && !possible; i++ )
            for( int j = 0; j < 6 && !possible; j++ )
                if( t == M[i] + M[j] )
                    possible = true;
        
        printf( "%s\n", possible ? "possible" : "impossible" );
    }

    return 0;
}
