#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t, smaller, index = 1;

	scanf( "%d%d", &n, &t );
	smaller = t;
	for( int i = 2; i <= n; i++ ) {
		scanf( "%d", &t );
		if( smaller > t )
			smaller = t, index = i;
	}
	printf( "%d\n", index );

	return 0;
}