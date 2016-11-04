#include <bits/stdc++.h>
using namespace std;

map<string,bool> mapa;
map<string,bool>::iterator it;

int main() {
	string texto, aux;

	while( getline( cin, texto ) ) {
		aux.clear();
		for( int i=0; i<texto.size(); i++ )
			if( isalpha( texto[i] ) )
				aux += tolower( texto[i] );
			else if( !aux.empty() ) {
				if( !mapa[ aux ] )
					mapa[ aux ] = true;
				aux.clear();
			}

		if( !aux.empty() && !mapa[ aux ] )
			mapa[ aux ] = true;
	}
	for( it=mapa.begin(); it!=mapa.end(); it++ )
		cout << it->first << endl;

	return 0;
}