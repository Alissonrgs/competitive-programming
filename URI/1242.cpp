#include <bits/stdc++.h>
using namespace std;

bool check( char a, char b ) {
    return ( a == 'B' && b == 'S' ) || ( a == 'S' && b == 'B' ) || ( a == 'C' && b == 'F' ) || ( a == 'F' && b == 'C' );
}

int main() {
    int c, index;
    string rnaa, crnaa;
    
    while( cin >> crnaa ) {
        c = 0;
        
        bool p = true;
        while( p ) {
            p = false;
            index = -1;
            rnaa = crnaa;
            crnaa.clear();
            for( int i = 1; i < rnaa.size(); i++ ) {
                if( check( rnaa[i-1], rnaa[i] ) )
                    c++, index = i++, p = true;
                else
                    crnaa += rnaa[i-1];
            }
            if( index != rnaa.size()-1 )
                crnaa += rnaa[ rnaa.size()-1 ];
        }
        printf( "%d\n", c );
    }

    return 0;
}
