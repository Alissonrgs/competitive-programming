#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, s, c, r, v[100005];
    double tempo;
    
    scanf( "%d", &t );
    while( t-- ) {
        scanf( "%d%d%d", &s, &c, &r );
        for( int i = 0; i < s; i++ )
            scanf( "%d", &v[i] );
        sort( &v[0], &v[s] );
        
        tempo = 0.0;
        for( int i = 0; i < c; i++ )
            tempo += 1.0 / ( v[i] + r );
        for( int i = c; i < s; i++ )
            tempo += 1.0 / v[i];
        printf( "%.2lf\n", tempo );
    }

    return 0;
}
