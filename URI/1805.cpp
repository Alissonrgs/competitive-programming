#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
	ll a, b;

	scanf( "%lld%lld", &a, &b );
	printf( "%lld\n", ( a + b )*( b - a + 1 )/2 );

	return 0;
}