#include <bits/stdc++.h>
using namespace std;

int g( int n ) {
    if( n < 10 ) return n;
    int sum = 0;
    while( n ) {
        sum += n%10;
        n /= 10;
    }
    return g( sum );
}

int main() {
    int n;
    
    while( scanf( "%d", &n ) && n )
        printf( "%d\n", g( n ) );

    return 0;
}
