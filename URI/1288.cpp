#include <bits/stdc++.h>
using namespace std;

int main() {
    int teste, n, k, r, x[55], y[55], p[55][105];

	scanf( "%d", &teste );
	while( teste-- ) {
		scanf( "%d", &n );
		for( int i = 1; i <= n; i++ )
			scanf( "%d%d", &x[i], &y[i] );
		scanf( "%d%d", &k, &r );
	
		for( int peso = 0; peso <= k; peso++ ) {
			p[0][peso] = 0;
			for( int i = 1; i <= n; i++ ) {
				if( y[i] > peso )
					p[i][peso] = p[i-1][peso];
				else
					p[i][peso] = max( p[i-1][peso], p[i-1][ peso - y[i] ] + x[i] );
			}
		}
		printf( "%s\n", p[n][k] >= r ? "Missao completada com sucesso" : "Falha na missao" );
	}

    return 0;
}
