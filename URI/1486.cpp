#include <bits/stdc++.h>
using namespace std;

int main() {
	int p, n, c, q1, qp;
	bool m[1005][1005];

	while( scanf( "%d%d%d", &p, &n, &c ) && p ) {
		qp = 0;
		for( int i = 0; i < n; i++ )
			for( int j = 0; j < p; j++ )
				cin >> m[i][j];

		for( int j = 0; j < p; j++ ) {
			q1 = 0;
			for( int i = 0; i < n; i++ )
				if( m[i][j] )
					q1++;
				else {
					if( q1 >= c ) qp++;
					q1 = 0;
				}
				
			if( q1 >= c ) qp++;
		}
		printf( "%d\n", qp );
	}

	return 0;
}