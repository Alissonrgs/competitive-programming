#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<int> G[2005];
bool cor[2005];

void dfs( int v ) {
	cor[v] = true;

	for( int i=0, j; i<G[v].size(); i++ ) {
		j = G[v][i];
		if( !cor[j] )
			dfs( j );
	}
}

int main() {
	int n, m, v, w, p;
	bool ir_vir;

	while( scanf( "%d%d", &n, &m ) && n ) {
		ir_vir = true;
		for( int i=0; i<n; i++ ) G[i].clear();

		for( int i=0; i<m; i++ ) {
			scanf( "%d%d%d", &v, &w, &p );
			G[v-1].push_back( w-1 );
			if( p == 2 ) G[w-1].push_back( v-1 );
		}

		for( int i=0; i<n && ir_vir; i++ ) {
			memset( cor, 0, sizeof cor );
			dfs( i );
			for( int j=0; j<n && ir_vir; j++ )
				if( !cor[j] )
					ir_vir = false;
		}
		printf( "%d\n", ir_vir );
	}

	return 0;
}