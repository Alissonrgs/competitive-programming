#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int a, d, b, c, A, D1, D2;

	while( scanf( "%d%d", &a, &d ) && a ) {
		A = D1 = D2 = 10005;
		for( int i=0; i<a; i++ ) {
			scanf( "%d", &b );
			A = min( A, b );
		}
		for( int i=0; i<d; i++ ) {
			scanf( "%d", &c );
			if( c < D1 ) D2 = D1, D1 = c;
			else if( c < D2 ) D2 = c;
		}
		printf( "%s\n", A < D2 ? "Y" : "N" );
	}

	return 0;
}