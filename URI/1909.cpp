#include <bits/stdc++.h>
using namespace std;

#define N 1e5
#define ll long long int

ll gcd( ll a, ll b ) { return b == 0 ? a : gcd( b, a%b ); }
ll lcm( ll a, ll b ) { return a * ( b / gcd( a, b ) ); }

int main() {
	int n;
	ll t, tempo;
	bool bola[(int)N+1];
	ll mmc;

	while( scanf( "%d%lld", &n, &t ) && n ) {
		mmc = 1;
		memset( bola, 0, sizeof bola );
		for( int i=0; i<n; i++ ) {
			scanf( "%lld", &tempo );
			bola[tempo] = true;
			mmc = lcm( mmc, tempo );
		}
		tempo = 0;
		if( mmc <= t )
			for( ll i=2; i<=t; i++ )
				if( !(t%i) && !bola[i] && lcm( mmc, i ) == t ) {
					tempo = i;
					break;
				}

		if( tempo )
			printf( "%lld\n", tempo );
		else
			printf( "impossivel\n" );
	}

	return 0;
}