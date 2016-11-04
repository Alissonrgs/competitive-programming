#include <bits/stdc++.h>
using namespace std;

map<char,int> mapa;

int main() {
	int n, t, s, p;
	char q;
	string julg;

	while( cin >> n && n ) {
		s = p = 0;
		mapa.clear();
		for( int i=0; i<n; i++ ) {
			cin >> q >> t >> julg;
			if( !mapa[q] )
				mapa[q] = 0;

			if( julg == "incorrect" )
				mapa[q] += 20;
			else
				s++, p += mapa[q] + t;
		}
		cout << s << " " << p << endl;
	}

	return 0;
}