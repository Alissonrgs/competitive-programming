#include <bits/stdc++.h>
using namespace std;

double dp[5000][5000];

int main() {
	int s;
	
	scanf( "%d", &s );
	
	dp[1][1] = 100.0;
	for( int i = 2; i <= s; i++ ) {
		for( int j = 1; j <= i+1; j++ ) {
			if( j == 1 )
				dp[i][j] = dp[i-1][j]/2.0;
			else if( j == i+1 )
				dp[i][j] = dp[i-1][j-1]/2.0;
			else
				dp[i][j] = dp[i-1][j-1]/2.0 + dp[i-1][j]/2.0;
		}
	}
	printf( "%.2lf\n", dp[s][s/2 + 1] );

	return 0;
}
