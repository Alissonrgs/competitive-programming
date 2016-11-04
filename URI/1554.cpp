#include <cstdio>
#include <cmath>

int main() {
	int c, n, bola;
	double x0, y0, x, y, d, menor;

	scanf( "%d", &c );
	while( c-- ) {
		scanf( "%d", &n );
		for( int i=0; i<=n; i++ ) {
			scanf( "%lf%lf", &x, &y );
			if( i == 0 ) {
				x0 = x, y0 = y;
				continue;
			}
			d = sqrt( pow( x-x0, 2 ) + pow( y-y0, 2 ) );
			if( i == 1 ) {
				menor = d;
				bola = 1;
				continue;
			}
			if( menor-d > 0.00001 ) {
				menor = d;
				bola = i;
			}
		}
		printf( "%d\n", bola );
	}

	return 0;
}