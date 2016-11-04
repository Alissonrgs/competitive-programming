#include <bits/stdc++.h>
using namespace std;

int c, p;
bool G[55][55];
bool cor[55];

void DFS( int V ) {
	cor[V] = true;

	for( int i=1; i<=c; i++ )
		if( G[V][i] && !cor[i] )
			DFS( i );
}

int main() {
	int x, y, pontes;

	while( scanf( "%d%d", &c, &p ) != EOF ) {
		pontes = 0;
		memset( G, false, sizeof G );
		for( int i=0; i<p; i++ ) {
			scanf( "%d%d", &x, &y );
			G[x][y] = G[y][x] = true;
		}
		for( int i=1; i<=c; i++ )
			for( int j=i+1; j<=c; j++ )
				if( G[i][j] ) {
					G[i][j] = G[j][i] = false;
					memset( cor, 0, sizeof cor );
					DFS( i );
					for( int k=1; k<=c; k++ )
						if( !cor[k] ) {
							pontes++;
							break;
						}
					G[i][j] = G[j][i] = true;
				}

		printf( "%d\n", pontes );
	}

	return 0;
}