#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y, i, j;
	char mapa[105][105], d;
	
	scanf( "%d%d", &y, &x );
	for( i = 0; i < x; i++ )
		for( j = 0; j < y; j++ )
			scanf( " %c", &mapa[i][j] );
	
	i = j = 0;
	d = mapa[i][j];
	while( mapa[i][j] != '*' && mapa[i][j] != '0' ) {
		d = ( mapa[i][j] != '.' && mapa[i][j] != '*' && mapa[i][j] != '0' ? mapa[i][j] : d );
		mapa[i][j] = '0';
		switch( d ) {
			case '>':
				j = ( j+1 < y ? j+1 : j );
				break;
			case '<':
				j = ( j-1 >= 0 ? j-1 : j );
				break;
			case 'v':
				i = ( i+1 < x ? i+1 : i );
				break;
			case '^':
				i = ( i-1 >= 0 ? i-1 : i );
				break;
		}
	}
	printf( "%s\n", mapa[i][j] == '*' ? "*" : "!" );
	 
	return 0;
}
