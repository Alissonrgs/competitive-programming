#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int D, Vf, Vg;

    while( cin >> D >> Vf >> Vg ) {
        float distG = sqrt( 144 + D*D ), Tf, Tg;

        Tf = 12.0/Vf;
        Tg = distG/Vg;

        if( Tf >= Tg )
            cout << "S\n";
        else
            cout << "N\n";
    }

    return 0;
}
