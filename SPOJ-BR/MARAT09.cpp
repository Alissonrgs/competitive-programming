#include <cstdio>

int main() {
    int n, m, p[10005];
    bool c = true;

    scanf( "%d%d", &n, &m );
    p[n] = 42195;
    for( int i=0; i<n; i++ ) {
        scanf( "%d", &p[i] );
        if( i != 0 && p[i] - p[i-1] > m ) c = false;
    }
    if( p[n] - p[n-1] > m ) c = false;
    printf( "%c\n", ( c ? 'S': 'N' ) );

    return 0;
}
