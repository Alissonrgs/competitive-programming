#include <bits/stdc++.h>
using namespace std;

int main() {
	int nc, n, h[235];

	scanf( "%d", &nc );
	while( nc-- ) {
		memset( h, 0, sizeof h );
		scanf( "%d", &n );
		for( int i=0, j; i<n; i++ ) {
			scanf( "%d", &j );
			h[j]++;
		}
		espaco = false;
		for( int i=20; i<=230; i++ ) {
			while( h[i]-- )
				printf( "%s%d", ( espaco ? " " : "" ), i ), espaco = true;
		}
		printf( "\n" );
	}

	return 0;
}