#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ultra_p, largada[30], chegada[30];

    while( cin >> n ) {
        ultra_p = 0;
        for( int i = 0; i < n; i++ )
            cin >> largada[i];
        for( int i = 0; i < n; i++ )
            cin >> chegada[i];

        for( int i = n-1, t; i >= 0; i-- ) {
            if( largada[i] != chegada[i] ) {
                for( int j = 0; j < n; j++ )
                    if( largada[i] == chegada[j] ) {
                        t = j;
                        break;
                    }
                    
                while( largada[i] != chegada[i] ) {
                    if( t > i ) {
                        swap( chegada[t], chegada[t-1] );
                        t--;
                    
                    } else {
                        swap( chegada[t], chegada[t+1] );
                        t++;
                    }
                    ultra_p++;
                }
            }
        }
        cout << ultra_p << endl;
    }

    return 0;
}
