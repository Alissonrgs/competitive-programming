#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define EPS 1e-9

ll n_zeros( int n, int base ) {
	ll zero = INT_MAX;
	ll fator_n, fator_b;

	for( int i = 2; i <= base; i++ ) {
		if( base%i != 0 ) continue;
		fator_n = fator_b = 0;
		while( base%i == 0 && base != 0 ) {
		    fator_b++;
		    base /= i;
		}
		for( ll j = i; j <= n; j *= i )
		    fator_n += n/j;
		
		zero = min( zero, fator_n/fator_b );
	}
	return zero;
}

ll n_digitos( int n, int base ) {
	double log_fat = 0.0, log_base = log( base );
	
	for( int i = 2; i <= n; i++ )
	    log_fat += log( i );

	return (ll)floor( log_fat / log_base + EPS ) + 1LL;
}

int main() {
    int n, b;
    
    while( scanf( "%d%d", &n, &b ) != EOF )
        printf( "%lld %lld\n", n_zeros( n, b ), n_digitos( n, b ) );

    return 0;
}
