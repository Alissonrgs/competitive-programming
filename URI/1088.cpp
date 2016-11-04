#include <cstdio>
#define lli long long int

int v[200005], base[200005], inv;

void merge( int inicio, int meio, int fim ) {
    int i = inicio, j = meio+1, k = 0;

    while( i <= meio && j <= fim )
        if( v[i] <= v[j] )
            base[k++] = v[i++];
        else {
            base[k++] = v[j++];
            inv += meio-i+1;
        }

    while( i <= meio )
        base[k++] = v[i++];
    while( j <= fim )
        base[k++] = v[j++];

    for( i=inicio; i<=fim; i++ )
        v[i] = base[ i-inicio ];
}

void mergeSort( int inicio, int fim ) {
    if( inicio < fim ) {
        int meio = ( inicio+fim )/2;

        mergeSort( inicio, meio );
        mergeSort( meio+1, fim );
        merge( inicio, meio, fim );
    }
}

int main() {
    int n;

    while( scanf( "%d", &n ) && n ) {
        inv = 0;
        for( int i=0; i<n; i++ )
            scanf( "%d", &v[i] );
        mergeSort( 0, n-1 );

        printf( "%s\n", inv&1 ? "Marcelo": "Carlos" );
    }

    return 0;
}