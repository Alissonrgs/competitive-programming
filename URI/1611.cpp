#include <bits/stdc++.h>
using namespace std;

bool ord( int a, int b ) {
    return a > b;
}

int main() {
    int t, n, c, m, a[50005], tempo;
    
    scanf( "%d", &t );
    while( t-- ) {
        scanf( "%d%d%d", &n, &c, &m );
        for( int i = 0; i < m; i++ )
            scanf( "%d", &a[i] );
        sort( &a[0], &a[m], ord );
        
        tempo = 0;
        for( int i = 0; i < m; i++ ) {
            int andar = -1; 
            for( int j = i; j < i + c && j < m; j++ )
                andar = max( andar, a[j] );
            tempo += 2*andar;
            i += c - 1;
        }
        printf( "%d\n", tempo );
    }

    return 0;
}
