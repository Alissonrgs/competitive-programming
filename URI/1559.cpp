#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m[5][5];

	scanf( "%d", &n );
	while( n-- ) {
		bool n2048 = false;
		for( int i = 1; i <= 4; i++ )
			for( int j = 1; j <= 4; j++ ) {
				scanf( "%d", &m[i][j] );
				if( m[i][j] == 2048 )
					n2048 = true;
			}
		if( n2048 ) {
			printf( "NONE\n" );
			continue;
		}
		bool DOWN = false;
		for( int i = 1; i <= 4 && !DOWN; i++ )
			for( int j = 1; j < 4 && !DOWN; j++ )
				if( m[j][i] && ( m[j][i] == m[j+1][i] || !m[j+1][i] ) )
					DOWN = true;
		if( DOWN ) printf( "DOWN" );
		
		bool LEFT = false;
		for( int i = 1; i <= 4 && !LEFT; i++ )
			for( int j = 4; j > 1 && !LEFT; j-- )
				if( m[i][j] && ( m[i][j] == m[i][j-1] || !m[i][j-1] ) )
					LEFT = true;
		if( LEFT ) printf( "%sLEFT", DOWN ? " " : "" );
		
		bool RIGHT = false;
		for( int i = 1; i <= 4 && !RIGHT; i++ )
			for( int j = 1; j < 4 && !RIGHT; j++ )
				if( m[i][j] && ( m[i][j] == m[i][j+1] || !m[i][j+1] ) )
					RIGHT = true;
		if( RIGHT ) printf("%sRIGHT", DOWN || LEFT ? " " : "" );
		
		bool UP = false;
		for( int i = 1; i <= 4 && !UP; i++ )
			for( int j = 4; j > 1 && !UP; j-- )
				if( m[j][i] && ( m[j][i] == m[j-1][i] || !m[j-1][i] ) )
					UP = true;
		if( UP ) printf("%sUP", DOWN || LEFT || RIGHT ? " " : "" );
		
		if( !DOWN && !LEFT && !RIGHT && !UP ) printf( "NONE" );
		printf( "\n" );
	}

	return 0;
}