#include <bits/stdc++.h>
using namespace std;

map< pair<int,int>, int > mapa;

int main() {
	int n, v[100005], q[1000005], m, k, num, cont;

	while( scanf( "%d%d", &n, &m ) != EOF ) {
		memset( q, 0, sizeof q );
		mapa.clear();
		for( int i=0; i<n; i++ ) {
			scanf( "%d", &v[i] );
			q[ v[i] ]++;
			if( !mapa[ pair<int,int>( q[ v[i] ], v[i] ) ] )
				mapa[ pair<int,int>( q[ v[i] ], v[i] ) ] = i+1;
		}

		for( int i=0, j; i<m; i++ ) {
			scanf( "%d%d", &k, &num );
			printf( "%d\n", mapa[ pair<int,int>( k, num ) ] );
		}
	}

	return 0;
}