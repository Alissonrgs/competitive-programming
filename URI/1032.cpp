#include <bits/stdc++.h>
using namespace std;

#define ll long long int

vector<ll> primo, p;
ll ep[50005];

void crivo() {
	for( ll i=2; i<=50000; i++ )
		if( ep[i] ) {
			primo.push_back( i );
			for( ll j=i*i; j<=50000; j += i )
				ep[j] = 0;
		}
}

int main() {
	memset( ep, 1, sizeof ep );
	crivo();

	int n, id, ip;

	while( scanf( "%d", &n ) && n ) {
		ip = id = 0;
		for( int i=1; i<=n; i++ )
			p.push_back( i );
		while( p.size() > 1 ) {
			id = ( id-1 + primo[ip++] )%p.size();
			p.erase( p.begin() + id );
		}
		printf( "%lld\n", p[0] );
		p.clear();
	}

	return 0;
}