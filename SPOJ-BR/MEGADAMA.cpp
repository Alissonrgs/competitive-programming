#include <cstdio>
#include <algorithm>
using std::swap;

int tab[25][25], aux[25][25], n, m;

int salto( int i, int j ) {
	int qm = 0, qnt;

	if( ( i-2 >= 0 && j-2 >= 0 ) && aux[i-1][j-1] == 2 && aux[i-2][j-2] == 0 ) {
		aux[i][j] = 0;
		aux[i-1][j-1] = 0;
		aux[i-2][j-2] = 1;
		qnt = 1 + salto( i-2, j-2 );
		if( qm < qnt ) qm = qnt;

		aux[i][j] = tab[i][j];
		aux[i-1][j-1] = tab[i-1][j-1];
		aux[i-2][j-2] = tab[i-2][j-2];
	} 
	if( ( i+2 < n && j-2 >= 0 ) && aux[i+1][j-1] == 2 && aux[i+2][j-2] == 0 ) {
		aux[i][j] = 0;
		aux[i+1][j-1] = 0;
		aux[i+2][j-2] = 1;
		qnt = 1 + salto( i+2, j-2 );
		if( qm < qnt ) qm = qnt;

		aux[i][j] = tab[i][j];
		aux[i+1][j-1] = tab[i+1][j-1];
		aux[i+2][j-2] = tab[i+2][j-2];
	}
	if( ( i-2 >= 0 && j+2 < m ) && aux[i-1][j+1] == 2 && aux[i-2][j+2] == 0 ) {
		aux[i][j] = 0;
		aux[i-1][j+1] = 0;
		aux[i-2][j+2] = 1;
		qnt = 1 + salto( i-2, j+2 );
		if( qm < qnt ) qm = qnt;

		aux[i][j] = tab[i][j];
		aux[i-1][j+1] = tab[i-1][j+1];
		aux[i-2][j+2] = tab[i-2][j+2];
	}
	if( ( i+2 < n && j+2 < m ) && aux[i+1][j+1] == 2 && aux[i+2][j+2] == 0 ) {
		aux[i][j] = 0;
		aux[i+1][j+1] = 0;
		aux[i+2][j+2] = 1;
		qnt = 1 + salto( i+2, j+2 );
		if( qm < qnt ) qm = qnt;

		aux[i][j] = tab[i][j];
		aux[i+1][j+1] = tab[i+1][j+1];
		aux[i+2][j+2] = tab[i+2][j+2];
	}

	return qm;
}

int main() {
	int qm, qnt;

	while( scanf( "%d %d", &n, &m ) && n && m ) {
		qm = 0;
		for( int i=0, j=n-1, mi=m-1, k, e; i<n*m; i+=2 ) {
			scanf( "%d", &e );
			k = i%m;
			if( i > mi ) {
				j--;
				mi += m;
			}
			tab[j][k] = e;
			if( i+1 > mi ) {
				j--;
				mi += m;
			}
			if( j < 0 ) break;
			tab[j][k+1] = 0;		
			if( m%2 == 0 && j%2 == 0 ) swap( tab[j][k], tab[j][k+1] );
		}
		for( int i=0; i<n; i++ )
			for( int j=0; j<m; j++ )
				aux[i][j] = tab[i][j];

		for( int i=0; i<n; i++ )
			for( int j=0; j<m; j++ )
				if( tab[i][j] == 1 ) {
					qnt = salto( i, j );
					if( qm < qnt ) qm = qnt;
				}
		printf( "%d\n", qm );
	}

	return 0;
}