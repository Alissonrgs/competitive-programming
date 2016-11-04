#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m[105][105];

	while( scanf( "%d", &n ) != EOF ) {
		memset( m, 0, sizeof m );
		for( int i=0, k=n-1; i<n; i++, k-- ) {
			for( int j=0; j<n; j++ ) {
				if( !(n%3) && n/3 <= i && i < 2*n/3 && n/3 <= j && j < 2*n/3 )
					m[i][j] = 1;
				if( n%3 && n/3 <= i && i <= 2*n/3 && n/3 <= j && j <= 2*n/3 )
					m[i][j] = 1;

				if( i == j && !m[i][j] )
					m[i][j] = 2;
				if( k == j && !m[i][j] )
					m[i][j] = 3;
				if( i == n/2 && j == n/2 )
					m[i][j] = 4;
				printf( "%d", m[i][j] );
			}
			printf( "\n" );
		}
		printf( "\n" );
	}

	return 0;
}