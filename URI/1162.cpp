#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, L, l[55], qnt;

	scanf( "%d", &n );
	while( n-- ) {
		qnt = 0;
		scanf( "%d", &L );
		for( int i=0; i<L; i++ )
			scanf( "%d", &l[i] );

		for( int i=0; i<L; i++ )
			for( int j=i+1; j<L; j++ )
				if( l[i] > l[j] )
					swap( l[i], l[j] ), qnt++;
	
		printf( "Optimal train swapping takes %d swaps.\n", qnt );
	}

	return 0;
}