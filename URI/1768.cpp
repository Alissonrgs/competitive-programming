#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;

	while( scanf( "%d", &n ) != EOF ) {
		for( int i=1, j=n/2+1; i<=n; i += 2, j++ ) {
			for( int k=1; k<=j-i; k++ )
				printf( " " );
			for( int k=1; k<=i; k++ )
				printf( "*" );
			printf( "\n" );
		}
		for( int i=1, j=n/2+1; i<=3; i += 2, j++ ) {
			for( int k=1; k<=j-i; k++ )
				printf( " " );
			for( int k=1; k<=i; k++ )
				printf( "*" );
			printf( "\n" );
		}
		printf( "\n" );
	}

	return 0;
}