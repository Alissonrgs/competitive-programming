#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, g, r, s, p, qd, d[100005];

	while( scanf( "%d%d", &n, &g ) != EOF ) {
		qd = p = 0;
		for( int i=0; i<n; i++ ) {
			scanf( "%d%d", &s, &r );
			if( s > r )
				p += 3;
			else if( s == r ) {
				if( g > 0 )
					p += 3, g--;
				else
					p++;
			} else
				d[ qd++ ] = r-s;
		}
		sort( d, d+qd );
		for( int i=0; i<qd; i++ )
			if( g >= d[i] ) {
				if( g == d[i] )
					g -= d[i], p++;
				else
					g -= d[i]+1, p += 3;
			
			} else
				break;

		printf( "%d\n", p );
	}

	return 0;
}