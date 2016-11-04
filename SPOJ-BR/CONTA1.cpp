#include <cstdio>

int main() {
    int n, v = 0;

    scanf( "%d", &n );

    if( n > 10 ) {
        v += 7;
        if( n > 30 ) {
            v += 20;
            if( n > 100 ) {
                v+= 140;
                if( n > 100 ) v += ( n - 100 )*5;

            } else
                v += ( n - 30 )*2;

        } else
            v += n - 10;

    } else
        v = 7;

    printf( "%d\n", v );

    return 0;
}
