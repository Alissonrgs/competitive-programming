#include <bits/stdc++.h>
using namespace std;
 
vector<int> G[2005];
bool cor[2005];
 
void DFS( int v ) {
	cor[v] = true;
 
	for( int i=0, A; i<G[v].size(); i++ ) {
		A = G[v][i];
		
		if( !cor[A] )
			DFS( A );
	}
}
 
int main() {
	int n, m, v, w, p;
	bool ir_vir;
 
	while( scanf( "%d%d", &n, &m ) && n ) {
		ir_vir = true;
		for( int i=1; i<=n; i++ ) G[i].clear();
		for( int i=0; i<m; i++ ) {
			scanf( "%d%d%d", &v, &w, &p );
			G[v].push_back( w );
			if( p == 2 ) G[w].push_back( v );
		}
 
		for( int i=1; i<=n && ir_vir; i++ ) {
			memset( cor, 0, sizeof cor );
			DFS( i );
			for( int j=1; j<=n && ir_vir; j++ )
				if( !cor[j] )
					ir_vir = false;
		}
		printf( "%d\n", ir_vir );
	}
 
	return 0;
} 