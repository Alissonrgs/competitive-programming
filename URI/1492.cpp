#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll c_uns[55];

ll count_uns( ll n ) {
	ll q_uns = 0;

	while( n ) {
		q_uns += n&1;
		n >>= 1;
	}

	return q_uns;
}

ll soma_uns( ll n ) {
	int i = 1;
	ll q_uns = count_uns( n ), soma = 0;

	while( n ) {
		if( n&1 ) {
			soma += c_uns[i] + ( q_uns - 1 )*( (ll)1 << i-1 );
			q_uns--;
		}
		n >>= 1;
		i++;
	}

	return soma;
}

int main() {
	ll a, b;

	c_uns[1] = 1;
	for( int i=1; i<55; i++ )
		c_uns[i+1] = 2*( c_uns[i] - 1 ) + ( (ll)1 << i-1 ) + 1;

	while( scanf( "%lld%lld", &a, &b ) != EOF )
		printf( "%lld\n", soma_uns( b ) - soma_uns( a ) + count_uns( a ) );

	return 0;
}