#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, j1, j2, r, a;
    
    scanf( "%d%d%d%d%d", &p, &j1, &j2, &r, &a );
    int j = j1 + j2;
    
    if( r ) {
        if( a )
            printf( "Jogador 2 ganha!" );
        else
            printf( "Jogador 1 ganha!" );
    } else {
        if( a )
            printf( "Jogador 1 ganha!" );
        else {
            if( j&1 )
                printf( "Jogador %d ganha!", p ? 2 : 1 );
            else
                printf( "Jogador %d ganha!", p ? 1 : 2 );
        }
    }
    printf( "\n" );

    return 0;
}
