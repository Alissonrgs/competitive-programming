#include <bits/stdc++.h>
using namespace std;

#define ll long long 

ll feijoes( ll x, ll n ) {
	if( x == 1 ) return 1;
	x--;
	return 4*x*( n - x ) + 1;
}

ll ij( ll n, ll b ) {
	ll d = n*n - b + 1;
	double delta = sqrt( d );
	return ( n - delta )/2.0;
}

int main() {
	ll n, b, l, x = 1, y = 1;

	scanf( "%lld%lld", &n, &b );
	l = ij( n, b );
	x += l;
	y += l;
	l++;
	b -= feijoes( l, n );
	n = n - 2*l + 1;
	
	if( b > 0 ) {
		if( b >= n ) y += n;
		else y += b;
		b -= n;
	}

	if( b > 0 ) {
		if( b >= n ) x += n;
		else x += b;
		b -= n;
	}

	if( b > 0 ) {
		if( b >= n ) y -= n;
		else y -= b;
		b -= n;
	}

	if( b > 0 ) {
		if( b >= n ) x -= n;
		else x -= b;
	}

	printf( "%lld %lld\n", x, y );

	return 0;
}