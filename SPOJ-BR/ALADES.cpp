#include <iostream>
using namespace std;

int main() {
    int h[2], m[2], horas, minutos;

    while( cin >> h[0] >> m[0] >> h[1] >> m[1] && ( h[0] != 0 || m[0] != 0 || h[1] != 0 || m[1] != 0 ) ) {
        horas = minutos = 0;
        if( h[0] >= h[1] )
            horas = 24-h[0]+h[1];
        else if( h[0] < h[1] )
            horas = h[1]-h[0];

        if( m[0] > m[1] ) {
            minutos = 60-m[0]+m[1];
            horas--;
        } else if( m[0] < m[1] ) {
            minutos = m[1]-m[0];
            if( horas == 24 )
                horas = 0;
        }

        cout << ( horas*60 ) + minutos << endl;
    }

    return 0;
}
