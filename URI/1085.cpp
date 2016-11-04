#include <bits/stdc++.h>
#define vi vector<int>
#define MAXN 4005
using namespace std;

struct Edge {
    int id, d;
    char work;
    
    Edge( int _id, int _d, char _work ) : id(_id), d(_d), work(_work) {}
    int ctoi() { return (int)( work - 'a' ); };
    bool operator<( Edge e ) const { return d > e.d; }
};

vector<Edge> G[MAXN];
int d[MAXN][26];
map< string, int > mapa;

void dijkstra( Edge u ) {
    priority_queue<Edge> pqueue;
    for( int i = 0; i < 26; i++ )
        d[u.id][i] = 0;
    pqueue.push( u );
    
    while( !pqueue.empty() ) {
        u = pqueue.top(), pqueue.pop();

        if( u.work != '?' && u.d > d[u.id][u.ctoi()] ) continue;

        for( int i = 0; i < (int)G[u.id].size(); i++ ) {
            Edge v = G[u.id][i];

            if( u.work == '?' && d[v.id][v.ctoi()] > v.d ) {
                d[v.id][v.ctoi()] = v.d;
                pqueue.push( Edge( v.id, d[v.id][v.ctoi()], v.work ) );

            } else if( u.work != v.work && d[v.id][v.ctoi()] > d[u.id][u.ctoi()] + v.d ) {
                d[v.id][v.ctoi()] = d[u.id][u.ctoi()] + v.d;
                pqueue.push( Edge( v.id, d[v.id][v.ctoi()], v.work ) );
            }
        }
    }
}

int main() {
    int m, edge;
    string in, out, u, v, work;
    
    while( cin >> m && m ) {
        mapa.clear();
        for( int i = 1; i < MAXN; i++ ) {
            G[i].clear();
            for( int j = 0; j < 26; j++ )
                d[i][j] = INT_MAX;
        }
        edge = 1;
        
        cin >> in >> out;
        mapa[in] = edge++;
        mapa[out] = edge++;
        
        for( int i = 0; i < m; i++ ) {
            cin >> u >> v >> work;
            if( !mapa[u] ) mapa[u] = edge++;
            if( !mapa[v] ) mapa[v] = edge++;
            
            G[ mapa[u] ].push_back( Edge( mapa[v], (int)work.size(), work[0] ) );
            G[ mapa[v] ].push_back( Edge( mapa[u], (int)work.size(), work[0] ) );
        }
        dijkstra( Edge( 1, 0, '?' ) );
        
        int ans = INT_MAX;
        for( int i = 0; i < 26; i++ )
            ans = min( ans, d[2][i] );

        if( ans == INT_MAX )
            cout << "impossivel" << endl;
        else
            cout << ans << endl;
    }

    return 0;
}
