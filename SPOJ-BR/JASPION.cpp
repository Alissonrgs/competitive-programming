#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map<string,string> dicionario;

int main() {
	int t, m, n;
	string p, s;

	cin >> t;
	while( t-- ) {
		dicionario.clear();
		cin >> m >> n;
		cin.ignore();
		for( int i=0; i<m; i++ ) {
			getline( cin, p );
			getline( cin, s );
			dicionario[p] = s;
		}

		char c;
		for( int i=0; i<n; i++ ) {
			while( cin >> p ) {
				c = getchar();
				if( c == '\n' ) {
					if( dicionario[p] != "" ) cout << dicionario[p] << c;
					else cout << p << c;
					break;
				}
				if( c == ' ' ) {
					if( dicionario[p] != "" ) cout << dicionario[p] << c;
					else cout << p << c;
				}
			}
		}
	}
	
	return 0;
}