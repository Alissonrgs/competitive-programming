#include <bits/stdc++.h>
using namespace std;

#define LIM 1000000
#define ll long long

bool isprime[LIM+5];
bool gemeo[LIM+5];
vector<int> prime;

void crivo() {
    isprime[1] = false;
    memset( isprime, true, sizeof isprime );
	prime.push_back(2);

	for( ll j = 2; j < LIM; j += 2 )
	    isprime[j] = false;

	for( ll i = 3; i < LIM; i += 2 )
		if( isprime[i] ) {
			prime.push_back(i);
		    for( ll j = i*i; j < LIM; j += i )
		    	isprime[j] = false;
		}
}

int main() {
    crivo();
    memset( gemeo, false, sizeof gemeo );
    for( int i = 1; i < prime.size(); i++ )
        if( abs( prime[i-1] - prime[i] ) == 2 )
            gemeo[prime[i-1]] = true, gemeo[prime[i]] = true;

    int q, x, y, i, gemeos;
    
    scanf( "%d", &q );
    while( q-- ) {
        scanf( "%d%d", &x, &y );
        if( x > y )
            swap( x, y );
        gemeos = 0;
        for( int i = x; i <= y; i++ )
            gemeos += ( gemeo[i] ? 1 : 0 );
        cout << gemeos << endl;
    }

    return 0;
}
