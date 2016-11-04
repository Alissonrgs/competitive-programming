#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, h, m, o;
    
    scanf( "%d", &t );
    while( t-- ) {
        scanf( "%d%d%d", &h, &m, &o );
        printf( "%02d:%02d - A porta %s!\n", h, m, ( o ? "abriu" : "fechou" ) );
    }
    
    return 0;
}
