#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, p[105], P, qnt;

	while( scanf( "%d%d", &n, &k ) && n ) {
		memset( p, 0, sizeof p );
		qnt = 0;
		for( int i=0; i<n; i++ ) {
			scanf( "%d", &P );
			p[P]++;
			if( p[P] == k )
				qnt++;
		}
		printf( "%d\n", qnt );
	}

	return 0;
}