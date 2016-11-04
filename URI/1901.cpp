#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, i, j, k[205][205], qnt;
	bool borboleta[1005];

	while( scanf( "%d", &n ) != EOF ) {
		qnt = 0;
		memset( borboleta, 0, sizeof borboleta );
		for( i=1; i<=n; i++ )
			for( j=1; j<=n; j++ )
				scanf( "%d", &k[i][j] );
		n <<= 1;
		while( n-- ) {
			scanf( "%d%d", &i, &j );
			if( !borboleta[ k[i][j] ] )
				borboleta[ k[i][j] ] = 1, qnt++;
		}
		printf( "%d\n", qnt );
	}

	return 0;
}