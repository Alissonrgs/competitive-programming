#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, v[10], v2[10];
    printf( "Lumberjacks:\n" );
    
    scanf( "%d", &n );
    while( n-- ) {
        for( int i = 0; i < 10; i++ )
            scanf( "%d", &v[i] ), v2[i] = v[i];
            
        sort( v, v+10 );
        
        bool e = true;
        for( int i = 0; i < 10 && e; i++ )
            if( v[i] != v2[i] )
                e = false;

        if( !e ) {
            e = true;
            for( int i = 0, j = 9; i < 10 && j >= 0 && e; i++, j-- )
                if( v[i] != v2[j] )
                    e = false;
        }
        printf( "%s\n", e ? "Ordered" : "Unordered" );
    }

    return 0;
}
