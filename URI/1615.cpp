#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, m, c[15], v, index;
	long double maior;

	scanf( "%d", &t );
	while( t-- ) {
		scanf( "%d%d", &n, &m );
		memset( c, 0, sizeof c );
		maior = 0.5;
		for( int i = 0; i < m; i++ ) {
			scanf( "%d", &v ), c[v]++;
			if( maior < (long double)c[v]/m ) {
				maior = (long double)c[v]/m;
				index = v;
			}
		}
		printf( "%d\n", maior > 0.5 ? index : -1 );
	}

	return 0;
}