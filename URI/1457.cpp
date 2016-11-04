#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll fatK( ll N, int i, int k ) {
	if( N-i*k < 1 ) return 1;
	else return (N-i*k)*fatK( N, i+1, k );
}

int main() {
	int n, q;
	ll N;
	char k[25];

	scanf( "%d", &n );
	while( n-- ) {
		scanf( " %lld%s", &N, k );
		printf( "%lld\n", fatK( N, 0, strlen( k ) ) );
	}

	return 0;
}