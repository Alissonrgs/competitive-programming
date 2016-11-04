#include <bits/stdc++.h>
using namespace std;

int main() {
	long double l, i;

	while( scanf( "%LF", &l ) && (int)l ) {
		i = 3 + 2*( l - 3 );
		printf( "%.6Lf\n", (long double)( i - l )/l );
	}

	return 0;
}