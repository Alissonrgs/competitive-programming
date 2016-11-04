#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Edge {
    int m[2][4];
    pair<ll, ll> id;
    ll d;

    Edge() {}
    void gerar_id() {
        id.first = (ll)m[0][0] + (ll)m[0][1]*1000 + (ll)m[0][2]*1000000 + (ll)m[0][3]*1000000000;
        id.second = (ll)m[1][0] + (ll)m[1][1]*1000 + (ll)m[1][2]*1000000 + (ll)m[1][3]*1000000000;
    }
    bool operator<( Edge e ) const { return d > e.d; }
    bool equal( Edge u ) {
        bool e = true;
        for( int i = 0; e && i < 2; i++ )
            for( int j = 0; e && j < 4; j++ )
                e = ( m[i][j] == u.m[i][j] );
        return e;
    }
};

Edge U, V;
map< pair<int,int> , int> d;

ll dijkstra() {
    priority_queue<Edge> pq;
    pq.push(U);
    
    while( !pq.empty() ) {
        Edge u = pq.top();
        pq.pop();
        
        if( u.equal( V ) ) {
            return d[u.id];
        }
        
        Edge f[10];
        for( int i = 0; i < 10; i++ )
            f[i] = u;
        
        for( int i = 0; i < 4; i++ ) {
            swap( f[i].m[0][i], f[i].m[1][i] );
            f[i].d += f[i].m[0][i] + f[i].m[1][i];
            f[i].gerar_id();
        }
        for( int i = 4, j = 1; j < 4; j++, i++ ) {
            swap( f[i].m[0][j-1], f[i].m[0][j] );
            f[i].d += f[i].m[0][j-1] + f[i].m[0][j];
            f[i].gerar_id();
            
            swap( f[i+3].m[1][j-1], f[i+3].m[1][j] );
            f[i+3].d += f[i+3].m[1][j-1] + f[i+3].m[1][j];
            f[i+3].gerar_id();
        }
        
        for( int i = 0; i < 10; i++ ) {
            Edge v = f[i];

            if( !d[v.id] || d[v.id] > v.d ) {
                d[v.id] = v.d;
                pq.push( v );
            }
        }
    }
}

int main() {
    for( int i = 0; i < 2; i++ )
        for( int j = 0; j < 4; j++ )
            scanf( "%d", &U.m[i][j] );
    for( int i = 0; i < 2; i++ )
        for( int j = 0; j < 4; j++ )
            scanf( "%d", &V.m[i][j] );
    
    printf( "%lld\n", dijkstra() );

    return 0;
}
