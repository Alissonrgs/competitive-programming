#include <bits/stdc++.h>
using namespace std;

string cg = "", NOP = "NOP";

int codigo_genetico( int n ){
    if( n > 5005 ) return 1;
 
    for( int i=0; i<3; i++ ) {
        cg += NOP[i];
        bool p = true;

        for( int j=1; j*2 <= cg.size() && p; j++ )
            if( cg.substr( cg.size()-j, j ) == cg.substr( cg.size()-2*j, j ) )
            	p = false;

        if( p && codigo_genetico( n+1 ) )
        	return 1;

        cg.erase( cg.end()-1 );
    }
 
    return 0;
}

int main() {
	int n;
	//codigo_genetico( 1 );
	cg = "NONPNOPNPONOPNONPNOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPONPNONPONOPNONPNOPNPONPNONPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPOPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNPOPNONPNOPNPONOPNONPNOPNPOPNONPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNPOPNONPNOPNPONOPNONPNOPNPOPNONPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPOPNOPONOPNONPNOPNPONOPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPONPNONPONOPNONPNOPNPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPOPNONPNOPNPONOPNONPNOPNPOPNONPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNPOPNONPNOPNPONOPNONPNOPNPOPNONPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPOPNONPNOPNPONOPNONPNOPNPOPNONPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONPNONPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPONPNONPONOPNONPNOPNPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPOPNONPNOPNPONOPNONPNOPNPOPNONPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNPOPNONPNOPNPONOPNONPNOPNPOPNONPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPOPNONPNOPNPONOPNONPNOPNPOPNONPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONPNONPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPOPNOPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNOPNPONOPNONPNOPNPONOPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPONPNONPONOPNONPNOPNPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPOPNONPNOPNPONOPNONPNOPNPOPNONPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNPOPNONPNOPNPONOPNONPNOPNPOPNONPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPOPNONPNOPNPONOPNONPNOPNPOPNONPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONPNONPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPONPNONPONOPNONPNOPNPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPOPNOPONOPNONPNOPNPONOPNONPNOPONOPNONPONOPNPONPNONPONOPNONPNOPNPONOPNONPONOPNPONPNONPONOPNONPNOPONOPNONPONOPNPOPNONPNOPNPONOPNONPNOPNPOPNONPNOP";

	while( scanf( "%d", &n ) && n )
		cout << cg.substr( 0, n ) << endl;

	return 0;
}