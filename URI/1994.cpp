#include <bits/stdc++.h>
using namespace std;

vector<int> G[10005];
int n, d[10005], imperio, maior;

void bfs( int u ) {
	for( int i = 1; i <= n; i++ ) d[i] = INT_MAX;
    queue<int> q;
    q.push( u );
    d[u] = 0;
	
	imperio = u;
    maior = 0;
    
    while( !q.empty() ) {
        u = q.front();
        q.pop();
        
        for( int i = 0; i < G[u].size(); i++ ) {
            int v = G[u][i];
            
            if( d[v] == INT_MAX ) {
                d[v] = d[u] + 1;
                if( maior < d[v] ) {
                	imperio = v;
                	maior = d[v];
                }
                q.push( v );
            }
        }
    }
}

int main() {
    while( scanf( "%d", &n ) && n != -1 ) {
        for( int i = 1; i <= n; i++ ) G[i].clear();
        for( int i = 2, v; i <= n; i++ ) {
            scanf( "%d", &v );
            G[i].push_back( v );
            G[v].push_back( i );
        }
       	bfs( 1 );
       	bfs( imperio );

        printf( "%d\n", ( d[imperio]&1 ? d[imperio]/2 + 1 : d[imperio]/2 ) );
    }

    return 0;
}
