#include <cstdio>

#define vij( i, j ) ( 0 <= i && i < 7 ) && ( 0 <= j && j < 8 )
#define prox( i, j ) ( j+1 > 7? i+1: i ), ( j+1 > 7? 0: j+1 )

int peca[7][7],
	jogo[7][8],
	qnt;
bool np[29], possivel;

void verificar( int i, int j ) {
	if( i == 7 ) {
		possivel = true;
		for( int t=1; t<=28 && possivel; t++ )
			if( !np[t] ) possivel = false;
		if( possivel ) qnt++;
		return;
	}
	if( jogo[i][j] == -1 ) {
		verificar( prox( i, j ) );
		return;
	}
	for( int t=1, x, y; t<=2; t++ ) {
		if( t == 1 ) x = i, y = j+1;
		else x = i+1, y = j;

		if( vij( x, y ) && jogo[x][y] != -1 ) {
			int ip = jogo[i][j], jp = jogo[x][y];
			
			if( !np[ peca[ ip ][ jp ] ] ) {
				jogo[i][j] = jogo[x][y] = -1;
				np[ peca[ ip ][ jp ] ] = true;
				verificar( prox( i, j ) );
				np[ peca[ ip ][ jp ] ] = false;
				jogo[i][j] = ip, jogo[x][y] = jp;
			}
		}
	}
}

int main() {
	int n, t = 1;

	scanf( "%d", &n );
	while( n-- ) {
		qnt = 0;
		for( int i=0, p=1; i<=6; i++ )
			for( int j=i; j<=6; j++, p++ )
				peca[i][j] = peca[j][i] = p, np[p] = false;

		for( int i=0; i<7; i++ )
			for( int j=0; j<8; j++ )
				scanf( "%d", &jogo[i][j] );

		verificar( 0, 0 );

		printf( "Teste %d\n%d\n\n", t++, qnt );
	}

	return 0;
}