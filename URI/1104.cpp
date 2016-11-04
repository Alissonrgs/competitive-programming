#include <cstdio>
#include <cstring>

int main() {
	int a, b, carta, ca[10005], cb[10005], qnt;
	bool va[100005], vb[100005];

	while( scanf( "%d%d", &a, &b ) && a ) {
		qnt = 0;
		memset( va, 0, sizeof( va ) );
		for( int i=0; i<a; i++ ) {
			scanf( "%d", &ca[i] );
			va[ ca[i] ] = 1;
		}
		memset( vb, 0, sizeof( vb ) );
		for( int i=0; i<b; i++ ) {
			scanf( "%d", &cb[i] );
			vb[ cb[i] ] = 1;
		}
		for( int i=0; i<a; i++ )
			for( int j=0; j<b; j++ )
				if( !vb[ ca[i] ] && !va[ cb[j] ] ) {
					vb[ ca[i] ] = va[ cb[j] ] = 1;
					qnt++;
					break;
				}

		printf( "%d\n", qnt );
	}

	return 0;
}