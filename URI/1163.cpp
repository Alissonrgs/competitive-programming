#include <bits/stdc++.h>
#define ld long double
using namespace std;

int main() {
    int n;
    ld g = 9.80665, pi = 3.14159, h, p1, p2, a, Vo, Vx, Vy, H, t1, t2, y;
    
    while( scanf( "%Lf", &h ) != EOF ) {
        scanf( "%Lf%Lf", &p1, &p2 );
        scanf( "%d", &n );
        for( int i = 0; i < n; i++ ) {
            scanf( "%Lf%Lf", &a, &Vo );
            a = a * pi / 180.0;
            Vx = Vo * cos( a );
            Vy = Vo * sin( a );
            t1 = Vy / g;
            H = Vy * Vy / ( 2.0 * g );
            t2 = sqrt( (2.0 * ( H + h )) / g );
            y = Vx * ( t1 + t2 );
            printf( "%.5Lf -> %s\n", y, ( p1 <= y && y <= p2 ? "DUCK" : "NUCK" ) );
        }
    }

    return 0;
}
