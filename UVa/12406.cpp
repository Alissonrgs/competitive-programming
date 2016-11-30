#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

ll nmin, nmax, p, q, q2;
map<ll, bool> m;
vector<ll> v[18];

ll pot( ll n, ll x ) {
    ll ans = 1;
    while( x ) {
        if( x&1 ) ans *= n;
        n *= n;
        x >>= 1;
    } 
    return ans;
}

void comb( string n, int i ) {
    ll lln = stoll( n, NULL, 10 );
    if( !m[lln] ) {
        m[lln] = true;
        v[p].pb( lln );
    }
    
    if( i >= (int)n.size() ) return;
    
    comb( n, i+1 );
    n[i] = '2';
    comb( n, i+1 );
    n[i] = '1';
}

int main() {
    int t, _case = 1;
    string n;
    
    scanf( "%d", &t );
    while( t-- ) {
        m.clear();
        n.clear();
        
        scanf( "%Ld%Ld", &p, &q );
        for( int i = 0; i < p; i++ ) n += '1';
        q2 = pot( 2, q );
        nmin = LLONG_MAX, nmax = 0;
        
        if( v[p].empty() )
            comb( n, 0 );

        for( int i = 0; i < (int)v[p].size(); i++ )
            if( v[p][i]%q2 == 0 )
                nmin = min( nmin, v[p][i] ),
                nmax = max( nmax, v[p][i] );
        
        printf( "Case %d: ", _case++ );
        if( nmin == LLONG_MAX && nmax == 0 )
            printf( "impossible\n" );
        else if( nmin == nmax )
            printf( "%Ld\n", nmax );
        else
            printf( "%Ld %Ld\n", nmin, nmax );
    }

    return 0;
}
