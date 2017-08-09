#include <bits/stdc++.h>
#define NMAX 21
#define si set<int>
using namespace std;

si G[NMAX+1];
int fire, routes, d[NMAX+1], f[NMAX+1];

void dfs( int u ) {
    if( u == fire ) {
        routes++;
        u = 1;
        bool e = false;
        while( u != -1 ) {
            if( e ) putchar( ' ' );
            e = true;
            printf( "%d", u ), u = f[u];
        }
        putchar( '\n' );
        return;
    }
    
    d[u] = 1;
    for( int v : G[u] )
        if( !d[v] ) {
            f[u] = v;
            dfs( v );
        }

    d[u] = 0;
}

int main() {
    int u, v, _case = 1;
    
    while( ~scanf( "%d", &fire ) ) {
        for( int i = 1; i <= 21; i++ ) G[i].clear();
        memset( d, 0, sizeof d );
        
        while( scanf( "%d%d", &u, &v ) && u ) {
            G[u].insert( v );
            G[v].insert( u );
        }
        
        printf( "CASE %d:\n", _case++ );
        routes = 0;
        f[fire] = -1;
        if( !G[1].empty() && !G[fire].empty() )
            dfs( 1 );
        printf( "There are %d routes from the firestation to streetcorner %d.\n", routes, fire );
    }

    return 0;
}
