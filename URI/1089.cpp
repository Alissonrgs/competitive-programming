#include <cstdio>

int main() {
	int n, h[10005], qnt;
	bool pico = false;

	while( scanf( "%d", &n ) && n ) {
		qnt = 0;
		for( int i=0; i<n; i++ )
			scanf( "%d", &h[i] );

		for( int i=0; i<n; i++ ) {
			if( i == 0 ) {
				if( ( h[n-1] < h[i] && h[i] > h[i+1] ) || ( h[n-1] > h[i] && h[i] < h[i+1] ) )
					qnt++;
			} else if( i == n-1 ) {
				if( ( h[i-1] < h[i] && h[i] > h[0] ) || ( h[i-1] > h[i] && h[i] < h[0] ) )
					qnt++;
			} else
				if( ( h[i-1] < h[i] && h[i] > h[i+1] ) || ( h[i-1] > h[i] && h[i] < h[i+1] ) )
					qnt++;
		}
		printf( "%d\n", qnt );
	}

	return 0;
}