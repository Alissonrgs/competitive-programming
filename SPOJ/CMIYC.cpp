#include <cstdio>

int main() {
	int t;
	long long n;

	scanf( "%d", &t );
	while( t-- ) {
		scanf( "%lld", &n );
		if( n%3 == 0 ) printf( "%lld\n", n/3 );
		else printf( "0\n" );
	}

	return 0;
}