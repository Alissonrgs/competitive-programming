#include <cstdio>
#include <cstring>

int main() {
	int n, maior, voto[105];

	while( scanf( "%d", &n ) && n ) {
		maior = 0;
		memset( voto, 0, sizeof voto );
		for( int j=0; j<n; j++ )
			for( int i=0, v; i<n; i++ ) {
				scanf( "%d", &v );
				voto[i] += v;
				if( maior < voto[i] ) maior = voto[i];
			}
		printf( "%d\n", maior );
	}

	return 0;
}