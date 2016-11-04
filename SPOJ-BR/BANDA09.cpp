#include <cstdio>
#include <cstring>

int musicos[105][105];

int main() {
	int n, m, m1 = 1, m2 = 2, m3 = 3, maior = 0;
	memset( musicos, 0, sizeof musicos );

	scanf( "%d %d", &n, &m );
	for( int i=1, x, y, z; i<=m; i++ ) {
		scanf( "%d %d %d", &x, &y, &z );
		musicos[x][y] = musicos[y][x] = z;
	}
	for( int i=1; i<=n; i++ )
		for( int j=i+1; j<=n; j++ )
			for( int k=j+1, nota; k<=n; k++ ) {
				nota = musicos[i][j] + musicos[i][k] + musicos[j][k];
				if( maior <= nota ) {
					maior = nota;
					m1 = i;
					m2 = j;
					m3 = k;
				}
			}

	printf( "%d %d %d\n", m1, m2, m3 );

	return 0;
}