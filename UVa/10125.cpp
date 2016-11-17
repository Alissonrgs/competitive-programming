#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define I first
#define J second
using namespace std;

ll v[1005];
map<ll, vector< pair<int,int> > > sum;

int main() {
    int s;
    
    while( scanf( "%d", &s ) && s ) {
        sum.clear();
        for( int i = 0 ; i < s; i++ )
            scanf( "%Ld", &v[i] );
            
        sort( v, v+s );
        
        for( int i = 0; i < s; i++ )
            for( int j = i+1; j < s; j++ ) {
                ll t = v[i] + v[j];
                sum[ t ].pb( make_pair( i, j ) );
            }
        
        ll e = -LLONG_MAX;
        for( int i = s-1; i >= 0; i-- )
            for( int j = i-1; j >= 0; j-- ) {
                ll t = v[i] - v[j];
                
                if( sum.count( t ) )
                    for( int k = 0; k < (int)sum[t].size(); k++ ) {
                        if( sum[t][k].I != i && sum[t][k].I != j &&
                            sum[t][k].J != i && sum[t][k].J != j )
                            e = max( e, v[i] );
                    }
            }
        
        if( e != -LLONG_MAX )
            printf( "%Ld\n", e );
        else
            printf( "no solution\n" );
    }

    return 0;
}
