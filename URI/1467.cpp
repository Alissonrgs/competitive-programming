#include <cstdio>

int main() {
    int a, b, c;

    while( scanf( "%d%d%d", &a, &b, &c ) != EOF ) {
        if( a ) {
            if( b ) {
                if( c ) printf( "*\n" );
                else printf( "C\n" );
            } else {
                if( c ) printf( "B\n" );
                else printf( "A\n" );
            }
        } else {
            if( b ) {
                if( c ) printf( "A\n" );
                else printf( "B\n" );
            } else {
                if( c ) printf( "C\n" );
                else printf( "*\n" );
            }
        }
    }

    return 0;
}
