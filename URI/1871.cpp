#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
	ll n, m, soma, p;

	while( scanf( "%lld%lld", &n, &m ) && n ) {
		soma = n + m;
		p = m = 0;
		while( soma ) {
			n = soma%10;
			if( n != 0 )
				m += n*pow( 10, p++ );
			soma /= 10;
		}
		printf( "%lld\n", m );
	}

	return 0;
}