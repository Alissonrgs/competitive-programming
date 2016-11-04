#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<int> G[105];
bool cor[105];

void dfs( int v ) {
	cor[v] = true;

	for( int i=0, j; i<G[v].size(); i++ ) {
		j = G[v][i];
		if( !cor[j] )
			dfs( j );
	}
}

int main() {
	int e, l, x, y, t = 1;
	bool transm;

	while( scanf( "%d%d", &e, &l ) && e ) {
		transm = true;
		for( int i=0; i<e; i++ ) G[i].clear();

		for( int i=0; i<l; i++ ) {
			scanf( "%d%d", &x, &y );
			G[x-1].push_back( y-1 );
			G[y-1].push_back( x-1 );
		}

		for( int i=0; i<e && transm; i++ ) {
			memset( cor, 0, sizeof cor );
			dfs( i );
			for( int j=0; j<e && transm; j++ )
				if( !cor[j] )
					transm = false;
		}
		printf( "Teste %d\n%s\n\n", t++, ( transm ? "normal" : "falha" ) );
	}

	return 0;
}