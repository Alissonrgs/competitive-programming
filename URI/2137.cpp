#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, v[1005];
    
    while( scanf( "%d", &n ) != EOF ) {
        for( int i = 0; i < n; i++ )
            scanf( "%d", v+i );
        sort( v, v+n );
        
        for( int i = 0; i < n; i++ )
            printf( "%04d\n", v[i] );
    }
    return 0;
}
