#include <bits/stdc++.h>
using namespace std;

int m[5][5], pd[5][5];

int bfs( int i, int j ) {
	if( i == 4 && j == 4 ) return pd[i][j] = 1;
	if( pd[i][j] ) return pd[i][j];

	if( i-1 >= 0 && !m[i-1][j] ) {
		m[i][j] = 1;
		pd[i][j] = max( pd[i][j], bfs( i-1, j ) );
		m[i][j] = 0;
	}
	if( i+1 <  5 && !m[i+1][j] ) {
		m[i][j] = 1;
		pd[i][j] = max( pd[i][j], bfs( i+1, j ) );
		m[i][j] = 0;
	}
	if( j-1 >= 0 && !m[i][j-1] ) {
		m[i][j] = 1;
		pd[i][j] = max( pd[i][j], bfs( i, j-1 ) );
		m[i][j] = 0;
	}
	if( j+1 <  5 && !m[i][j+1] ) {
		m[i][j] = 1;
		pd[i][j] = max( pd[i][j], bfs( i, j+1 ) );
		m[i][j] = 0;
	}

	return pd[i][j];
}

int main() {
	int t;

	scanf( "%d", &t );
	while( t-- ) {
		for( int i=0; i<5; i++ )
			for( int j=0; j<5; j++ ) {
				pd[i][j] = 0;
				scanf( "%d", &m[i][j] );
			}

		printf( "%s\n", bfs( 0, 0 ) ? "COPS" : "ROBBERS" );
	}

	return 0;
}