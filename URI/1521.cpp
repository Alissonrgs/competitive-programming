#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, v[55], a;
    
    while( scanf( "%d", &n ) && n ) {
        for( int i = 1; i <= n; i++ )
            scanf( "%d", &v[i] );
        scanf( "%d", &a );
        while( v[a] != a )
            a = v[a];
        printf( "%d\n", a );
    }

    return 0;
}
