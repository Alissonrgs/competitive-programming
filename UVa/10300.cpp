#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, sum;
    
    scanf( "%d", &t );
    while( t-- ) {
        scanf( "%d", &n );
        
        sum = 0;
        for( int i = 0, m2, a, ef; i < n; i++ )
            scanf( "%d%d%d", &m2, &a, &ef ), sum += ef*m2;
            
        printf( "%d\n", sum );
    }

    return 0;
}
