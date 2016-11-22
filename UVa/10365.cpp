#include <bits/stdc++.h>
#define NMAX 1000
using namespace std;

int v[NMAX+1];

void process() {
    for( int n = 1, ans; n <= NMAX; n++ ) {
        v[n] = INT_MAX;
        for( int a = 1; a*a <= n; a++ ) {
            if( n%a != 0 ) continue;
            for( int b = 1; b*b <= n/a; b++ ) {
                if( (n/a)%b != 0 ) continue;
                int c = (n/a)/b;
                v[n] = min( v[n], 2*( a*b + b*c + c*a ) );
            }
        }
    }
}

int main() {
    process();
    
    int c, n;
    
    scanf( "%d", &c );
    while( c-- ) {
        scanf( "%d", &n );
        printf( "%d\n", v[n] );
    }

    return 0;
}
