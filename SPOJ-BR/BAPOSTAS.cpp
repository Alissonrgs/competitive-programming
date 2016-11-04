#include <cstdio>

int main() {
    int n, v, sm, soma;

    while( scanf( "%d", &n ) && n ) {
        sm = soma = 0;
        for( int i=0; i<n; i++ ) {
            scanf( "%d", &v );
            soma += v;
            if( soma < 0 ) soma = 0;
            if( sm < soma ) sm = soma;
        }
        if( sm <= 0 ) printf( "Losing streak.\n" );
        else printf( "The maximum winning streak is %d.\n", sm );
    }

    return 0;
}
