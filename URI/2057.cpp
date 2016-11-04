#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, t, f;
    
    scanf( "%d%d%d", &s, &t, &f );
    s += t + f;
    if( s < 0 )
        s += 24;
    if( s == 24 )
        s = 0;
    if( s > 24 )
        s -= 24;
    
    printf( "%d\n", s );

    return 0;
}
