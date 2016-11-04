#include <bits/stdc++.h>
using namespace std;

map<char,int> mapa;

int main() {
	mapa['W'] = 64;
	mapa['H'] = 32;
	mapa['Q'] = 16;
	mapa['E'] = 8;
	mapa['S'] = 4;
	mapa['T'] = 2;
	mapa['X'] = 1;
	int s, qj;
	string jingle;

	while( cin >> jingle && jingle != "*" ) {
		s = qj = 0;
		for( int i=1; i<jingle.size(); i++ )
			if( jingle[i] == '/' ) {
				if( s == 64 ) qj++;
				s = 0;
			} else
				s += mapa[ jingle[i] ];

		cout << qj << endl; 
	}

	return 0;
}