#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using std::swap;

int main() {
	int w, h, n, qm, qnt;
	
	while( scanf( "%d %d %d", &w, &h, &n ) && ( ( w && h ) || n ) ) {
		bool t[w+1][h+1];
		memset( t, 0, sizeof t );
		qm = w*h;
		qnt = 0;
		
		for( int i=0, x1, y1, x2, y2; i<n; i++ ) {
			scanf( "%d %d %d %d", &x1, &y1, &x2, &y2 );
			if( x1 > x2 ) swap( x1, x2 );
			if( y1 > y2 ) swap( y1, y2 );
			for( int x=x1; x<=x2; x++ )
				for( int y=y1; y<=y2; y++ )
					if( !t[x][y] ) {
						t[x][y] = 1;
						qnt++;
					}
		}
		if( qm-qnt == 0 )
			printf( "There is no empty spots.\n" );
		else if( qm-qnt == 1 )
			printf( "There is one empty spot.\n" );
		else
			printf( "There are %d empty spots.\n", qm-qnt );
	}

	return 0;
}
