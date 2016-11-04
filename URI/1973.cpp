#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int n, sheep[1000005], visited[1000005], tfarm = 0;
	ll tsheep = 0;

	scanf( "%d", &n );
	for( int i = 0; i < n; i++ ) {
		scanf( "%d", &sheep[i] );
		tsheep += sheep[i];
	}
	memset( visited, 0, sizeof visited );
	int i = 0;
	while( true ) {
		if( i < 0 || i == n ) break;
		if( !visited[i] )
			visited[i] = 1, tfarm++;

		if( sheep[i]&1 ) {
			if( sheep[i] > 0 )
				sheep[i]--, tsheep--;
			i++;

		} else {
			if( sheep[i] > 0 )
				sheep[i]--, tsheep--;
			i--;
		}
	}
	printf( "%d %lld\n", tfarm, tsheep );

	return 0;
}