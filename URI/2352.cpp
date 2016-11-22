#include <bits/stdc++.h>
#define NMAX 100000
using namespace std;

int v[NMAX+1];

int main() {
    int n, k, total = 0;
    
    scanf( "%d%d", &n, &k );
    for( int i = 0; i < n; i++ ) {
        scanf( "%d", v+i );
        total += v[i];
    }
    
    priority_queue<int> pq;
    int e = n/(k+1), x1, x2 = n;
    while( e ) {
        x1 = e*(k+1) - 1;
        for( int i = x1; i < x2; i++ )
            pq.push( v[i] );
        total -= pq.top();
        pq.pop();
        x2 = x1;
        e--;
    }
    printf( "%d\n", total );

    return 0;
}
