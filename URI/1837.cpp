#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, q, r;

	scanf( "%d%d", &a, &b );
	q = a/b;
	r = a%b;

	if( r < 0 )
		for( r = 0; r <= abs(b); r++ ) {
			q = ( a-r )/b;
			if( a == b*q + r )
				break;
		}

	printf( "%d %d\n", q, r );

	return 0;
}