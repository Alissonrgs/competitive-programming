#include <cstdio>
#include <algorithm>
using std::sort;
using std::next_permutation;

#define lli long long int

lli a[5];
bool possivel;

void calcular( lli r, int i ) {
	if( i > 4 ) {
		if( r == 23 ) possivel = true;
		return;
	}
	calcular( r+a[i], i+1 );
	calcular( r-a[i], i+1 );
	calcular( r*a[i], i+1 );
}

int main() {
	while( true ) {
		possivel = false;
		for( int i=0; i<5; i++ )
			scanf( "%lld", &a[i] );
		sort( a, a+5 );
		if( !a[0] ) break;

		do calcular( a[0], 1 );
		while( next_permutation( a, a+5 ) && !possivel );

		printf( "%s\n", ( possivel ? "Possible": "Impossible" ) );
	}

	return 0;
}