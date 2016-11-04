#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int id, toll;
    Edge( int _id, int _toll ) : id(_id), toll(_toll) {}
    bool operator<( Edge e ) const { return e.toll > toll; }
};

vector<Edge> G[255];
int n, m, c, k, d[255];

void dijkstra( Edge u ) {
    for( int i = 0; i < n; i++ ) d[i] = INT_MAX;

    priority_queue<Edge> q;
    q.push( u );
    d[u.id] = 0;

    while( !q.empty() ) {
        u = q.top(); q.pop();
        
        for( int i = 0; i < G[u.id].size(); i++ ) {
            Edge v = G[u.id][i];
            
            if( u.id < c ) {
                if( v.id != u.id + 1 ) continue;
                if( d[v.id] > d[u.id] + v.toll ) {
                    d[v.id] = d[u.id] + v.toll;
                    q.push( Edge( v.id, d[v.id] ) );
                }
                
            } else {
                if( d[v.id] > d[u.id] + v.toll ) {
                    d[v.id] = d[u.id] + v.toll;
                    q.push( Edge( v.id, d[v.id] ) );
                }
            }
        }
    }
}

int main() {
    int u, v, p;

    while( scanf( "%d%d%d%d", &n, &m, &c, &k ) && n ) {
        for( int i = 0; i < n; i++ ) G[i].clear();
        for( int i = 0; i < m; i++ ) {
            scanf( "%d%d%d", &u, &v, &p );
            G[u].push_back( Edge( v, p ) );
            G[v].push_back( Edge( u, p ) );
        }
        
        dijkstra( Edge( k, 0 ) );
        printf( "%d\n", d[c-1] );
    }

    return 0;
}
