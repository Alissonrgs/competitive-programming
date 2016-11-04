#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, EPR, EHD;
    string numero, curso;
    map<string, int> mapa;
    
    while( cin >> n && n ) {
        mapa["EPR"] = 0;
        mapa["EHD"] = 0;
        mapa["INTRUSOS"] = 0;
        for( int i = 0; i < n; i++ ) {
            cin >> numero >> curso;
            if( curso != "EPR" && curso != "EHD" )
                mapa["INTRUSOS"]++;
            else
                mapa[curso]++;
        }
        printf( "EPR: %d\nEHD: %d\nINTRUSOS: %d\n", mapa["EPR"], mapa["EHD"], mapa["INTRUSOS"] );
    }

    return 0;
}
