#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX-1

int square[105], ans[10005];

int main() {
	for( int i = 0; i <= 100; i++ ) square[i] = i*i;
	for( int i = 0; i <= 10000; i++ ) ans[i] = INF;
	ans[0] = 0;

	int t, n;
		
	scanf( "%d", &t );
	while( t-- ) {
		scanf( "%d", &n );
		
        for( int i = 1; i <= n; i++ )
        	if( ans[i] == INF )
		    	for( int j = 1; j*j <= n; j++ )
					ans[i] = min( ans[i], 1 + ( i - square[j] < 0 ? INF-1 : ans[ i - square[j] ] ) );

        printf( "%d\n", ans[n] );
	}

	return 0;
}
