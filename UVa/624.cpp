#include <cstdio>

int main() {
	int n, nf, faixa[25], id, sm, soma, qm, qnt;

	while( scanf( "%d", &n ) != EOF ) {
		id = qm = sm = 0;
		scanf( "%d", &nf );
		for( int i=0; i<nf; i++ )
			scanf( "%d", &faixa[i] );

		for( int i=1; i<( 1 << nf ); i++ ) {
			soma = 0;
			for( int j=0; j<nf; j++ )
				if( i & ( 1 << j ) )
					soma += faixa[j], qnt++;
			if( sm <= soma && soma <= n && qm <= qnt )
				sm = soma, qm = qnt, id = i;
		}

		for( int i=0; i<nf; i++ )
			if( id & ( 1 << i ) )
				printf( "%d ", faixa[i] );
		printf( "sum:%d\n", sm );
	}

	return 0;
}