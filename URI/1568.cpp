#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

typedef unsigned long long int lli;

bool isprime[1000001];
lli prime[1000010], prime_cont = 0, lim = 750000;

void crivo() {
	prime[ prime_cont++ ] = 2;

	memset( isprime, true, sizeof( isprime ) );
	for( lli i=3; i<=lim; i+=2 ) {
		if( isprime[i] )
			prime[ prime_cont++ ] = i;

		for( lli j=i*i; j<=lim; j+=i )
			isprime[j] = false;
	}
}

int main() {
	crivo();
	lli n, div_imp, vezes, i;

	while( cin >> n ) {
		div_imp = ( n != 0 )? 1: 0;

		for( i=0; prime[i] <= n && i < prime_cont; i++ ) {
			vezes = 0;

			while( n%prime[i] == 0 ) {
				n /= prime[i];
				vezes++;
			}
			if( i > 0 ) div_imp *= vezes+1;
		}
		if( n > 1 ) div_imp *= 2;
		cout << div_imp << endl;
	}

	return 0;
}

