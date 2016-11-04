#include <bits/stdc++.h>
using namespace std;

vector<int> G[30];
bool cor[30];
string grafo = " abcdefghijklmnopqrstuvwxyz", visitados;

void DFS( int v ) {
	cor[v] = true;
	visitados += grafo[v];

	for( int i=0; i<G[v].size(); i++ )
		if( !cor[ G[v][i] ] )
			DFS( G[v][i] );
}

int main() {
	int n, v, e, x, y, cc;
	char a, b;

	scanf( "%d", &n );
	for( int t=1; t<=n; t++ ) {
		cc = 0;
		scanf( "%d%d", &v, &e );

		for( int i=1; i<=v; i++ ) G[i].clear();
		for( int i=0; i<e; i++ ) {
			scanf( " %c %c", &a, &b );
			x = grafo.find( a );
			y = grafo.find( b );
			G[x].push_back( y );
			G[y].push_back( x );
		}
		memset( cor, false, sizeof cor );
		printf( "Case #%d:\n", t );
		for( int i=1; i<=v; i++ ) {
			visitados = "";

			if( !cor[i] )
				DFS( i ), cc++;

			if( visitados != "" ) {
				sort( visitados.begin(), visitados.end() );
				for( int j=0; j<visitados.size(); j++ )
					printf( "%c,", visitados[j] );
				printf( "\n" );
			}
		}
		printf( "%d connected components\n\n", cc );
	}

	return 0;
}