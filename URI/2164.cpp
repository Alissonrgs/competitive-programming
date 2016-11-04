#include <bits/stdc++.h>
#define ld long double
using namespace std;

ld _pow( ld x, int n ) {
    ld ans = 1;
    while( n ) {
        if( n&1 )
            ans *= x;
        x *= x;
        n >>= 1;
    }
    return ans;
}

int main() {
    int n;
    ld r5 = sqrt(5.0), ans; 
    
    scanf( "%d", &n );
    ans = ( _pow( ( (1.0 + r5) / 2.0 ), n ) - _pow( ( (1.0 - r5) / 2.0 ), n ) ) / r5;
    printf( "%.1Lf\n", ans );

    return 0;
}
