#include <bits/stdc++.h>
using namespace std;

#define min3( a, b, c ) min( a, min( b, c ) )

int main() {
	int a, b, c, aux, media;

	while( scanf( "%d%d", &a, &b ) && a ) {
		c = min3( ( a + b )/2, 2*b - a, 2*a - b );
		printf( "%d\n", c );
	}

	return 0;
}