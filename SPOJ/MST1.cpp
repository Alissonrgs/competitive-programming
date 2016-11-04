#include <bits/stdc++.h>
using namespace std;

#define MAX 20000000

int dp[MAX+5];

int main() {
	int t, n;

	dp[0] = dp[1] = 0;
	for( int i=2; i<=MAX; i++ ) {
		dp[i]= dp[i-1] + 1;
		if( !( i&1 ) )
			dp[i] = min( dp[i], dp[ i>>1 ] + 1 );
		if( !( i%3 ) )
			dp[i]= min( dp[i], dp[i/3] + 1 );
	}

	scanf( "%d", &t );
	for( int i=1; i<=t; i++ ) {
		scanf( "%d", &n );
		printf( "Case %d: %d\n", i, dp[n] );
	}

	return 0;
}