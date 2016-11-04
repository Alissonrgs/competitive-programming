#include <bits/stdc++.h>
using namespace std;

vector<int> G[10005];
int cor[10005], loop;

void DFS( int v ) {
	cor[v] = 1;

	for( int i=0; i<G[v].size() && !loop; i++ )
		if( cor[ G[v][i] ] == 0 )
			DFS( G[v][i] );
		else if( cor[ G[v][i] ] == 1 )
			loop = true;

	cor[v] = 2;
}

int main() {
	int t, n, m, a, b;

	scanf( "%d", &t );
	while( t-- ) {
		scanf( "%d%d", &n, &m );
		for( int i=1; i<=n; i++ ) G[i].clear();
		for( int i=0; i<m; i++ ) {
			scanf( "%d%d", &a, &b );
			G[a].push_back( b );
		}
		loop = false;
		memset( cor, 0, sizeof cor );
		for( int i=1; i<=n && !loop; i++ )
			if( cor[i] != 1 )
				DFS( i );

		printf( "%s\n", ( loop ? "SIM" : "NAO" ) );
	}

	return 0;
}