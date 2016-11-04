#include <cstdio>

int main() {
	int b, n, d, c, v, banco[25];
	bool bc;

	while( scanf( "%d%d", &b, &n) && b ) {
		bc = false;
		for( int i=0; i<b; i++ )
			scanf( "%d", &banco[i] );
		for( int i=0; i<n; i++ ) {
			scanf( "%d%d%d", &d, &c, &v );
			banco[d-1] -= v;
			banco[c-1] += v;
		}
		for( int i=0; i<b; i++ )
			if( banco[i] < 0 ) {
				bc = true;
				break;
			}
		printf( "%s\n", bc ? "N" : "S" );
	}

	return 0;
}