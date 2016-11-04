#include <cstdio>

int main() {
    int n, x, y, y_ant = 0, nc = 0;

    scanf( "%d", &n );
    while( n-- ) {
        scanf( "%d%d", &x, &y );
        if( x >= y_ant ) {
            y_ant = y;
            nc++;
        } else if( y < y_ant )
            y_ant = y;
    }
    printf( "%d\n", nc );

    return 0;
}
