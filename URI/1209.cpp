#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
using namespace std;

vi g[1005], f, p, ans;

int main() {
    int n, m, k;
    
    while( ~scanf( "%d%d%d", &n, &m, &k ) ) {
        for( int i = 1; i <= n; i++ ) g[i].clear();
        f.assign( n+1, 0 );
        p.assign( n+1, 0 );
        
        for( int i = 0, u, v; i < m; i++ ) {
            scanf( "%d%d", &u, &v );
            f[u]++;
            f[v]++;
            g[u].pb( v );
            g[v].pb( u );
        }
        
        queue<int> q;
        for( int u = 1; u <= n; u++ )
            if( f[u] < k )
                p[u] = 1, q.push( u );
                
        while( !q.empty() ) {
            int u = q.front(); q.pop();
                 
            for( int v : g[u] )
                if( !p[v] && --f[v] < k )
                    p[v] = 1, q.push( v );
        }
        
        ans.clear();
        for( int u = 1; u <= n; u++ )
            if( !p[u] )
                ans.pb( u );

        bool e = false;
        if( !ans.empty() )
            for( int v : ans )
                e ? printf( " %d", v ) : printf( "%d", v ), e = true;
        else
            printf( "0" );
        printf( "\n" );
    }

    return 0;
}
