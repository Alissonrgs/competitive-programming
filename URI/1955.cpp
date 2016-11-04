#include <bits/stdc++.h>
using namespace std;

int n, madj[1005][1005], cor[1005];

bool dfs( int u, int c ) {
    cor[u] = c;

    bool p = true;
    for( int i = 0; i < n && p; i++ ) {
        int v = madj[u][i];

        if( !v && u != i ) {
            if( !cor[i] )
                p = dfs( i, ( c == 1 ? 2 : 1 ) );    
            else if( cor[i] == c )
                p = false;
        }
    }
    return p;
}

int main() {
    scanf( "%d", &n );
    for( int i = 0; i < n; i++ )
        for( int j = 0; j < n; j++ )
            scanf( "%d", &madj[i][j] );

            
    memset( cor, 0, sizeof cor );
    bool p = true;
    for( int i = 0; i < n && p; i++ )
        if( !cor[i] )
            p = dfs( i, 1 );

    if( p )
        printf( "Bazinga!\n" );
    else
        printf( "Fail!\n" );

    return 0;
}
