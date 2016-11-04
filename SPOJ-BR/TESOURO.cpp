#include <cstdio>

int main() {
	int x, y, n, t = 1, tesouro[105], s[105][10005], soma;

	while( scanf( "%d%d%d", &x, &y, &n ) && x && y && n ) {
		soma = 0;
		s[0][0] = 1;
		for( int i=1; i<=n; i++ ) {
			s[i][0] = 1;
			scanf( "%d", &tesouro[i] );
			soma += tesouro[i];
		}
		printf( "Teste %d\n", t++ );
		soma += x + y;
		if( soma%2 || soma/2 < x || soma/2 < y ) {
			printf( "N\n\n");
			continue;
		}
		soma /= 2;
		soma -= ( x > y ? x : y );

		for( int b=1; b<=soma; b++ ) {
			s[0][b] = 0;
			for( int i=1; i<=n; i++ )
				s[i][b] = ( tesouro[i] <= b ? ( s[i-1][b] || s[i-1][ b-tesouro[i] ] ) : s[i-1][b] );
		}

		printf( "%c\n\n", ( s[n][soma] ? 'S' : 'N' ) );
	}

    return 0;
}