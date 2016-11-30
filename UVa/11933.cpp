#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    
    while( scanf( "%d", &n ) && n ) {
        int a = 0, b = 0;
        bool l = 0;
        for( int i = 0; n; i++ ) {
            if( n&1 ) {
                if( !l )
                    a |= (1 << i);
                else
                    b |= (1 << i);
                l = !l;
            }
            n >>= 1;
        }
        printf( "%d %d\n", a, b );
    }
    
    return 0;
}
