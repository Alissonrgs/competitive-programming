#include <cstdio>
#include <cstring>

int main() {
	int n, m, bilhete, qnt;
	bool b[10005], r[10005];

	while( scanf( "%d%d", &n, &m ) && n ) {
		qnt = 0;
		memset( b, 0, sizeof b );
		memset( r, 0, sizeof r );
		for( int i=0; i<m; i++ ) {
			scanf( "%d", &bilhete );
			if( !b[ bilhete ] )
				b[ bilhete ] = 1;
			else if( !r[bilhete] )
				r[ bilhete ] = 1, qnt++;
		}
		printf( "%d\n", qnt );
	}

	return 0;
}