#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 100005

struct Edge {
    int id;
    ll d;
    Edge( int _id, ll _d ) : id(_id), d(_d) {}
};

vector<Edge> G[MAXN];
int n, height[MAXN], pi[MAXN];
ll d[MAXN];

ll LCA( int u, int v ) {
    ll D = 0;

    while( u != v ) {
        if( height[u] == height[v] )
            D += d[u] + d[v], u = pi[u], v = pi[v];
        
        else if( height[u] > height[v] )
            D += d[u], u = pi[u];
        
        else
            D += d[v], v = pi[v];
    }
    return D;
}

void bfs( int u ) {
    memset( pi, -1, sizeof pi );
    memset( height, -1, sizeof height );
    
    queue<int> q;
    q.push( u );
    d[u] = 0;
    
    while( !q.empty() ) {
        u = q.front(); q.pop();
        
        for( int i = 0; i < G[u].size(); i++ ) {
            Edge v = G[u][i];
            
            if( height[ v.id ] == -1 ) {
                pi[ v.id ] = u;
                height[ v.id ] = height[u] + 1;
                d[ v.id ] = v.d;
                q.push( v.id );
            }
        }
    }
}

int main() {
    int u, v, q;
    bool espaco;
    ll p;

    while( scanf( "%d", &n ) && n ) {
        for( int i = 0; i < n; i++ ) G[i].clear();
        memset( d, 0, sizeof d );

        for( int i = 1; i <= n-1; i++ ) {
            scanf( "%d%lld", &v, &p );
            G[v].push_back( Edge( i, p ) );
        }
        bfs(0);

        scanf( "%d", &q );
        espaco = false;
        for( int i = 0; i < q; i++ ) {
            scanf( "%d%d", &u, &v );
            printf( "%s%lld", ( espaco ? " " : "" ), LCA( u, v ) );
            espaco = true;
        }
        putchar('\n');
    }

    return 0;
}
