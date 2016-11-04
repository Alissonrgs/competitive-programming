#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t;
	
	scanf( "%d", &n );
	while( n-- ) {
		scanf( "%d", &t );
		if( 2015 - t <= 0 )
			printf( "%d %s\n", t - 2015 + 1, "A.C." );
		else
			printf( "%d %s\n", 2015 - t, "D.C." );
	}

	return 0;
}
