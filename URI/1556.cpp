#include <bits/stdc++.h>
using namespace std;

map<string,bool> mapa;
map<string,bool>::iterator it;
string s, aux;
vector<string> subs;

int main() {
	while( cin >> s ) {
		mapa.clear();
		subs.clear();
		for( int i = 0, size; i < (int)s.size(); i++ ) {
			size = subs.size();
			aux = s[i];
			subs.push_back( aux );
			mapa[ aux ] = true;
			for( int j = 0; j < size; j++ )
				if( !mapa[ subs[j] + aux ] ) {
					subs.push_back( subs[j] + aux );
					mapa[ subs[j] + aux ] = true;
				}
		}
		for( it = mapa.begin(); it != mapa.end(); it++ )
			cout << it->first << endl;
		cout << endl;
	}

	return 0;
}