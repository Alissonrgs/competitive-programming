#include <cstdio>

int main() {
	int n, t = 1, a[25], aluno, qm; 
	bool p;

	while( scanf( "%d", &n ) && n ) {
		qm = 0;
		
		for( int i=0; i<n; i++ ) {
			a[i] = 0;
			while( scanf( "%d", &aluno ) && aluno )
				a[i] |= ( 1 << aluno-1 );
		}

		for( int i=1; i<( 1 << n ); i++ ) {
			p = true;
			for( int j=0; j<n && p; j++ )
				if( i & ( 1 << j ) && ( i & a[j] ) )
					p = false;

			if( p && qm < __builtin_popcount( i ) )
				qm = __builtin_popcount( i );
		}
				
		printf( "Teste %d\n%d\n\n", t++, qm );
	}

	return 0;
}
