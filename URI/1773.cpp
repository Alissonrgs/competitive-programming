#include <bits/stdc++.h>
using namespace std;

vector<int> G[1005], k[1005];
int n, m, d[1005], key[1005], numV;

int bfs( int u ) {
    memset( d, -1, sizeof d );
    memset( key, 0, sizeof key );
    
    queue<int> q;
    q.push( u );
    key[u] = 1;
    
    int numV = 0;
    while( !q.empty() ) {
        u = q.front(); q.pop();
        
        if( d[u] == 1 ) continue;
        
        d[u] = 1;
        numV++;

        for( int i = 0; i < k[u].size(); i++ ) {
            key[ k[u][i] ] = 1;
            if( d[ k[u][i] ] == 0 )
                q.push( k[u][i] );
        }
  
        for( int i = 0; i < G[u].size(); i++ ) {
            int v = G[u][i];
            
            if( d[v] == -1 )
                d[v] = 0;
            
            if( d[v] <= 0 && key[v] )
                q.push( v );
        }
    }
    return numV;
}

int main() {
    while( scanf( "%d%d", &n, &m ) != EOF ) {
        for( int i = 1; i <= n; i++ ) G[i].clear(), k[i].clear();
        for( int i = 0, a, b; i < m; i++ ) {
            scanf( "%d%d", &a, &b );
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        for( int i = 2, j; i <= n; i++ ) {
            scanf( "%d", &j );
            k[j].push_back( i );
        }
        printf( "%s\n", bfs( 1 ) == n ? "sim" : "nao" );
    }

    return 0;
}
