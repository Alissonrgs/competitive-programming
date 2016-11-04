#include <bits/stdc++.h>
using namespace std;

#define llu long long unsigned int

int main() {
	int r;
	llu x = 3, ans = 1;

	scanf( "%d", &r );
	while( r ) {
		if( r&1 )
			ans *= x;
		x *= x;
		r >>= 1;
	}
	printf( "%llu\n", ans );

	return 0;
}