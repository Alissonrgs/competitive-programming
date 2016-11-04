#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define ll long long
using namespace std;

vi v;

int main() {
    int p, m, f, q, b, k, P[15], M[15], F[15], Q[15], B[15];
    ll total = 0;
    
    scanf( "%d", &p );
    for( int i = 0; i < p; i++ )
        scanf( "%d", P+i );
    
    scanf( "%d", &m );
    for( int i = 0; i < m; i++ )
        scanf( "%d", M+i );
    
    scanf( "%d", &f );
    for( int i = 0; i < f; i++ )
        scanf( "%d", F+i );
    
    scanf( "%d", &q );
    for( int i = 0; i < q; i++ )
        scanf( "%d", Q+i );
        
    scanf( "%d", &b );
    for( int i = 0; i < b; i++ )
        scanf( "%d", B+i );
    
    for( int pi = 0; pi < p; pi++ )
        for( int mi = 0; mi < m; mi++ )
            for( int fi = 0; fi < f; fi++ )
                for( int qi = 0; qi < q; qi++ )
                    for( int bi = 0; bi < b; bi++ )
                        v.pb( P[pi] + M[mi] + F[fi] + Q[qi] + B[bi] );
    
    sort( v.begin(), v.end(), []( int a, int b ){
        return a > b;
    });
    
    scanf( "%d", &k );
    for( int i = 0; i < k; i++ )
        total += v[i];
    printf( "%lld\n", total );

    return 0;
}
