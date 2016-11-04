#include <bits/stdc++.h>
using namespace std;

#define max3( a, b, c ) max( a, max( b, c ) )

int main() {
	int c, gols, R, G, B, m;
	char t1, t2;

	scanf( "%d", &c );
	while( c-- ) {
		scanf( "%d", &gols );
		R = G = B = 0;
		while( gols-- ) {
			scanf( " %c %c", &t1, &t2 );
			if( t1 == 'R' ) {
				if( t2 == 'G' ) R += 2;
				else R++;
			
			} else if( t1 == 'G' ) {
				if( t2 == 'B' ) G += 2;
				else G++;

			} else {
				if( t2 == 'R' ) B += 2;
				else B++;
			}
		}
		m = max3( R, G, B );
		if( R == G && G == B )
			printf( "trempate\n" );
		else if( ( R == G && R == m ) || ( G == B && G == m ) || ( B == R && B == m ) )
			printf( "empate\n" );
		else {
			if( R == m ) printf( "red\n" );
			else if( G == m ) printf( "green\n" );
			else printf( "blue\n" );
		}
	}

	return 0;
}