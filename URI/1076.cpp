#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, v, a, v1, v2, mov, aresta[50][50];
    
    scanf( "%d", &t );
    while( t-- ) {
        scanf( "%d%d%d", &n, &v, &a );
        memset( aresta, false, sizeof aresta );
        mov = 0;
        
        while( a-- ) {
            scanf( "%d%d", &v1, &v2 );
            if( !aresta[v1][v2] && !aresta[v2][v1] )
                aresta[v1][v2] = aresta[v2][v1] = true, mov += 2;
        }
        printf( "%d\n", mov );
    }

    return 0;
}
