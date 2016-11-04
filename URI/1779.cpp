#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int t, n, nota[100005], maior, q, qnt;

	scanf( "%d", &t );
	for( int c=1; c<=t; c++ ) {
		maior = -1;
		q = qnt = 0;
		scanf( "%d", &n );
		for( int i=0; i<n; i++ ) {
			scanf( "%d", &nota[i] );
			maior = max( maior, nota[i] );
		}
		for( int i=0; i<n; i++ ) {
			if( nota[i] == maior ) {
				q++;
				qnt = max( qnt, q );
			} else
				q = 0;
		}
		printf( "Caso #%d: %d\n", c, qnt );
	}

	return 0;
}