#include <bits/stdc++.h>
#define NMAX 25
using namespace std;

vector<int> G[NMAX];
int n, m, d[NMAX][NMAX];

int dfs( int u ) {
    int longest = 0;
    
    for( int i = 0; i < G[u].size(); i++ ) {
        int v = G[u][i];
        
        if( !d[u][v] ) {
            d[u][v] = d[v][u] = 1;
            longest = max( longest, dfs( v )+1 );
            d[u][v] = d[v][u] = 0;
        }
    }
    return longest;
}

int main() {
    while( scanf( "%d%d", &n, &m ) && n ) {
        for( int i = 0; i < n; i++ ) G[i].clear();
        for( int i = 0, u, v; i < m; i++ ) {
            scanf( "%d%d", &u, &v );
            G[u].push_back( v );
            G[v].push_back( u );
        }
        
        memset( d, 0, sizeof d );
        int longest = 0;
        for( int i = 0; i < n; i++ )
           	longest = max( longest, dfs( i ) );
        printf( "%d\n", longest );
    }

    return 0;
}
