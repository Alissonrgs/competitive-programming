#include <bits/stdc++.h>
#define NMAX 225
#define vi vector<int>
#define pb push_back
using namespace std;

int v[NMAX+1];
map<int, pair<int,int> > sum;

int main() {
    int n, k;
    
    for( int i = 0; i <= NMAX; i++ ) v[i] = i*i;

    for( int i = 0; i <= NMAX; i++ )
        for( int j = i; j <= NMAX; j++ )
            if( !sum.count( v[i] + v[j] ) )
                sum[ v[i] + v[j] ] = make_pair( i, j );
    
    scanf( "%d", &n );
    while( n-- ) {
        scanf( "%d", &k );
        
        bool e = false;
        for( int i = 0; i <= NMAX; i++ ) {
            int diff = k - v[i];
            if( sum.count( diff ) ) {
                vector<int> temp;
                temp.pb( sum[diff].first );
                temp.pb( sum[diff].second );
                temp.pb( i );
                sort( temp.begin(), temp.end() );
                for( int j : temp ) {
                    if( e ) putchar( ' ' );
                    e = true;
                    printf( "%d", j );
                }
                putchar( '\n' );
                break;
            }
        }
        if( !e )
            printf( "-1\n" );
    }

    return 0;
}
