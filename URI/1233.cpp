#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>

bool isprime[55000];
vi prime;
ll crivo_size = 46350;

void crivo() {
	memset( isprime, true, sizeof isprime );

	prime.push_back( 2 );
	for( ll j = 4; j <= crivo_size; j += 2 )
		isprime[j] = false;
	
	for( ll i = 3; i <= crivo_size; i += 2 )
		if( isprime[i] ) {
			prime.push_back( i );
			for( ll j = i*i; j <= crivo_size; j += i )
				isprime[j] = false;
		}
}

ll EulerPhi( ll N ) {
	ll PF_idx = 0, PF = prime[PF_idx], ans = N;
	while( PF*PF <= N ) {
		if( N%PF == 0 ) ans -= ans/PF;
		while( N%PF == 0 ) N /= PF;
		PF = prime[++PF_idx];
	}
	if( N != 1 ) ans -= ans/N;
	return ans;
}

int main() {
	int n;
	crivo();

	while( scanf( "%d", &n ) != EOF )
		printf( "%lld\n", EulerPhi( n )/2 );

	return 0;
}