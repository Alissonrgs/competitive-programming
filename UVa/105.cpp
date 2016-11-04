#include <cstdio>

int main() {
	int x1, y, x2, qnt = 0, x[10005] = { 0 };

	while( scanf( "%d%d%d", &x1, &y, &x2 ) != EOF )
		for( int i=x1; i<x2; i++ )
			if( y > x[i] ) x[i] = y;

	y = 0;
	bool espaco = false;
	for( int i=0; i<10005; i++ )
		if( x[i] != y ) {
			if( espaco ) printf( " " );
			else espaco = true;

			y = x[i];
			printf( "%d %d", i, x[i] );
		}
	printf( "\n" );

	return 0;
}