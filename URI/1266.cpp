#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x[5005], c, qnt;

	while( scanf( "%d", &n ) && n ) {
		for( int i=0; i<n; i++ )
			scanf( "%d", &x[i] );
		qnt = c = 0;
		for( int i=0; i<2*n; i++ )
			if( !x[ i%n ] )
				c++;
			else
				qnt += c/2, c = 0;

		qnt += c/2;
		printf( "%d\n", ( qnt&1 ? qnt/2 + 1 : qnt/2 ) );
	}

	return 0;
}