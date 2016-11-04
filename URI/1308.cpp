#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
	int t;
	ll n;

	scanf( "%d", &t );
	while( t-- ) {
		scanf( "%lld", &n );
		printf( "%lld\n", (ll)( -1 + sqrt( 1 + 8*n ) )/2 );
	}

	return 0;
}