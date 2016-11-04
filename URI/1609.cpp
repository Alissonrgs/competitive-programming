#include <bits/stdc++.h>
using namespace std;

#define ll long long int

map<ll,bool> mapa;

int main() {
	int t, n, qnt;
	ll c;

	scanf( "%d", &t );
	while( t-- ) {
		scanf( "%d", &n );
		qnt = 0;
		mapa.clear();
		for( int i=0; i<n; i++ ) {
			scanf( "%lld", &c );
			if( !mapa[ c ] ) {
				mapa[ c ] = true;
				qnt++;
			}
		}
		printf( "%d\n", qnt );
	}

	return 0;
}