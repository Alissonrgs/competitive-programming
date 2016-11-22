#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define NMAX 100000
using namespace std;

vi G[NMAX+1];
int d[NMAX+1], visit[NMAX+1];

int main() {
    int n, m, a, b;
    memset( d, 0, sizeof d );
    memset( visit, 0, sizeof visit );
    
    scanf( "%d%d%d%d", &n, &m, &a, &b );
    for( int i = 0, u, v; i < m; i++ ) {
        scanf( "%d%d", &u, &v );
        G[u].pb( v );
        G[v].pb( u );
        d[u]++;
        d[v]++;
    }
    
    queue<int> q;
    for( int i = 1; i <= n; i++ )
        if( n-1-b < d[i] || d[i] < a )
            q.push( i );
    
    int _n = n;
    while( !q.empty() ) {
        int u = q.front(); q.pop();
        
        if( visit[u] ) continue;
        else visit[u] = 1;
        
        d[u] = 0;
        _n--;
        for( int i = 0; i < (int)G[u].size(); i++ ) {
            int v = G[u][i];
            d[v]--;
            if( _n-1-b < d[v] || d[v] < a )
                q.push( v );
        }
        if( q.empty() )
            for( int i = 1; i <= n; i++ )
                if( !visit[i] && ( _n-1-b < d[i] || d[i] < a ) )
                    q.push( i );
    }
    
    int edge = 0;
    for( int i = 1; i <= n; i++ )
        if( a <= d[i] && d[i] <= _n-1-b )
            edge++;
    printf( "%d\n", edge );
             
    return 0;
}
