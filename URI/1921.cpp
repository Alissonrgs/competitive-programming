#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	int n;
	ll b = 0;

	scanf( "%d", &n );
	for( int i = n-2; i >= 2; i-- )
		b += i;
	printf( "%lld\n", b );

	return 0;
}