#include <bits/stdc++.h>
using namespace std;

int main() {
	double r, n;
	int c = 1;

	while( scanf( "%lf%lf", &r, &n ) ) {
		if( r == 0 ) break;
		r -= n;
		r = ceil( r/n );
		if( r > 26 )
			printf( "Case %d: impossible\n", c++ );
		else
			printf( "Case %d: %d\n", c++, (int)r );
	}

	return 0;
}