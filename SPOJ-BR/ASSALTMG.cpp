#include <cstdio>

int main() {
	int t, m, d, c, qm, qnt, chave;
	unsigned int diretor[25];

	scanf( "%d", &t );
	while( t-- ) {
		scanf( "%d%d", &m, &d );
		for( int i=0; i<d; i++ ) {
			diretor[i] = 0;
			scanf( "%d", &c );
			while( c-- ) {
				scanf( "%d", &chave );
				diretor[i] |= ( 1 << chave );
			}
		}
		qm = 21;
		for( int i=0; i<( 1 << d ); i++ ) {
			chave = 0;
			qnt = 0;
			for( int j=0; j<d; j++ )
				if( i & ( 1 << j ) ) {
					qnt++;
					chave |= diretor[j];
				}
			if( __builtin_popcount( chave ) >= m && qm > qnt )
				qm = qnt;
		}
		if( qm != 21 ) printf( "%d\n", qm );
		else printf( "Desastre!\n" );
	}

	return 0;
}