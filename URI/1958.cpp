#include <bits/stdc++.h>
using namespace std;

#define ld long double

int main() {
    char buf[120];
    ld n;

    scanf( "%s", buf );
    sscanf( buf, "%LE", &n );
    if( buf[0] != '-' )
        putchar( '+' );
    printf( "%.4LE\n", n );

    return 0;
}
