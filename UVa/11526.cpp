#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll _H( ll n ) {
    ll res = 0;

    for( ll i = 1; i <= n; i++ ) {
        res += n/i;
    }
    return res;
}

ll H( ll n ) {
    ll res = n + ( n&1 && n != 1 ? n/2 + 1 : n/2 );
    ll raiz = sqrt( n );

    for( ll i = 2; i <= raiz; i++ ) {
        res += n/i;
        if( n/(i+1) >= raiz )
            res += ( n/i - n/(i+1) )*i;
    }
    return res;
}

int main() {
    int t;
    ll n;

    scanf( "%d", &t );
    while( t-- ) {
        scanf( "%lld", &n );
        printf( "%lld\n", n < 0 ? 0 : H(n) );
    }

    return 0;
}
