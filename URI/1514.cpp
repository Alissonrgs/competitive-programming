#include <cstdio>
#include <cstring>
 
int main() {
    int n, m, crt, p, l[105], c[105];
 
    while( scanf( "%d%d", &n, &m ) && n ) {
        memset( l, 0, sizeof l );
        memset( c, 0, sizeof c );
        crt = 4;
        for( int i=0; i<n; i++ )
            for( int j=0; j<m; j++ ) {
                scanf( "%d", &p );
                if( p )
                    l[i]++, c[j]++;
            }
        for( int i=0; i<n; i++ )
            if( l[i] == m ) {
                crt--;
                break;
            }
        for( int i=0; i<n; i++ )
            if( l[i] == 0 ) {
                crt--;
                break;
            }
        for( int i=0; i<m; i++ )
            if( c[i] == n ) {
                crt--;
                break;
            }
        for( int i=0; i<m; i++ )
            if( c[i] == 0 ) {
                crt--;
                break;
            }
        printf( "%d\n", crt );
    }
 
    return 0;
}