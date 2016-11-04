#include <iostream>
using namespace std;

int main() {
    int num_a, num_v, teste = 1;

    while( cin >> num_a >> num_v && ( num_a && num_v ) ) {
        int aero[num_a], maior = 0;

        for( int i=0; i<num_a; i++ )
            aero[i] = 0;

        for( int i=0, x, y; i<num_v; i++ ) {
            cin >> x >> y;
            aero[x-1]++;
            aero[y-1]++;
            if( maior < aero[x-1] )
                maior = aero[x-1];
            if( maior < aero[y-1] )
                maior = aero[y-1];
        }

        bool p = false;
        cout << "Teste " << teste++ << endl;
        for( int i=0; i<num_a; i++ )
            if( aero[i] == maior ) {
                if( p ) cout << " ";
                cout << i+1;
                p = true;

            }
        cout << endl << endl;
    }

    return 0;
}
