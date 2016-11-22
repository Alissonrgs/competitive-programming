#include <bits/stdc++.h>
using namespace std;

map<int, int> mapa;

int maior_numero_com_digitos_de( int X ) {
    int v[4] = {0}, k = 0;
    
    while( X ) {
        v[k++] = X%10;
        X /= 10;
    }
    sort( v, v+4, []( int a, int b ) { return a > b; } );
    
    X = 0;
    for( int i = 0, j = 3; i < 4; i++, j-- )
        X += v[i]*pow( 10, j );
    return X;
}

int menor_numero_com_digitos_de( int X ) {
    int v[4] = {0}, k = 0;
    
    while( X ) {
        v[k++] = X%10;
        X /= 10;
    }
    sort( v, v+4 );

    X = 0;
    for( int i = 0, j = 3; i < 4; i++, j-- )
        X += v[i]*pow( 10, j );
    return X;
}

int krapekar( int X ) {
    int cnt = 0;
    mapa.clear();
    
    while( X != 6174 ) {
        if( !mapa[X] )
            mapa[X] = true;
        else
            return -1;
        
        int maior = maior_numero_com_digitos_de(X);
        int menor = menor_numero_com_digitos_de(X);
        X = maior - menor;
        cnt = cnt + 1;
    }

    return cnt;
}

int main() {
    int t, X;
    
    scanf( "%d", &t );
    for( int i = 1; i <= t; i++ ) {
        scanf( "%d", &X );
        printf( "Caso #%d: %d\n", i, krapekar( X ) );
    }

    return 0;
}
