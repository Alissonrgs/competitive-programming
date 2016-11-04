#include <bits/stdc++.h>
using namespace std;
 
#define llu long long unsigned int
#define MOD 2147483647

int main() {
    int r;
    llu x = 3, ans = 1;

    scanf( "%d", &r );
    while( r ) {
        if( r&1 )
            ans = (ans*x)%MOD;
        x = (x*x)%MOD;
        r >>= 1;
    }
    printf( "%llu\n", ans );
 
    return 0;
}