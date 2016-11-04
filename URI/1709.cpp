#include <bits/stdc++.h>
using namespace std;

int main() {
	int p, q, index;

	while( scanf( "%d", &p ) != EOF ) {
		q = index = 0;
		do {
			index = 2*index + 1;
			if( index > p )
				index = (index%p) - 1;
			q++;
		} while( index != 0 );
		printf( "%d\n", q );
	}

	return 0;
}