#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t, l, s, pa = 0, pb = 0;

	scanf( "%d%d%d", &n, &t, &l );
	for( int i=0; i<n-1; i++ ) {
		scanf( "%d", &s );
		if( i&1 )
			abs( t - s ) <= l ? pb += abs( t - s ), t = s : t = t;
		else
			abs( t - s ) <= l ? pa += abs( t - s ), t = s : t = t;
	}
	printf( "%d %d\n", pa, pb );

	return 0;
}