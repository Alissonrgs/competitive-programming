#include <cstdio>
#include <cstring>

int m[105][105], aux[105][105];

int main() {
	int n, k, xt, yt, qnt = 0;
	memset( m, 0, sizeof m );
	memset( aux, 0, sizeof aux );

	scanf( "%d %d", &n, &k );
	for( int i=0, x, y, z; i<k; i++ ) {
		scanf( "%d %d %d", &x, &y, &z );
		m[x][y] = z;
		aux[x][y] = -1;
	}

	for( int i=0; i<n; i++ )
		for( int j=0, d; j<n; j++ )
			if( m[i][j] > 0 ) {
				d = m[i][j];
				for( int x=i-d, y=0; x<=i+d; x++ ) {
					if( 0 <= x && x < n ) {
						if( 0 <= j-y && j-y < n && aux[x][j-y] != -1 ) {
							aux[x][j-y] += 1;
							if( aux[x][j-y] == k ) {
								xt = x;
								yt = j-y;
								qnt++;
							}
						}
						if( y != 0 && 0 <= j+y && j+y < n && aux[x][j+y] != -1 ) {
							aux[x][j+y] += 1;
							if( aux[x][j+y] == k ) {
								xt = x;
								yt = j+y;
								qnt++;
							}
						}
					}
					y += ( x < i )? 1: -1;
				}
			}

	if( qnt == 1 )
		printf( "%d %d\n", xt, yt );
	else
		printf( "-1 -1\n" );

	return 0;
}