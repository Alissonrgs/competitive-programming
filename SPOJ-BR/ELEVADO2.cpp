#include <cstdio>

int main() {
    int n, c, s, e, qnt = 0;
    bool ce = false;

    scanf( "%d%d", &n, &c );
    while( n-- ) {
        scanf( "%d%d", &s, &e );
        qnt += -s + e;
        if( qnt > c ) ce = true;
    }

    if( ce ) printf( "S\n" );
    else printf( "N\n" );

    return 0;
}
