#include <cstdio>

int main() {
	int n, m, g, mg, qnt = 0;

	scanf( "%d%d", &n, &m );
	while( n-- ) {
		mg = 0;
		for( int j=0; j<m; j++ ) {
			scanf( "%d", &g );
			mg += ( g ? 1 : 0 );
		}
		if( mg == m ) qnt++;
	}
	printf( "%d\n", qnt );

	return 0;
}