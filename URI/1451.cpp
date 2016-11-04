#include <bits/stdc++.h>
using namespace std;

string home_end( string texto ) {
	bool barra = false;
	string s, sb;

	s.clear(), sb.clear();
	for( int i=0; i<texto.size(); i++ ) {
		if( texto[i] == '[' ) {
			if( barra ) {
				s = sb + s;
				sb.clear();
			}
			barra = true;
			continue;
		}
		if( texto[i] == ']' ) {
			if( barra ) {
				s = sb + s;
				sb.clear();
			}
			barra = false;
			continue;
		}
		if( barra )
			sb += texto[i];
		else
			s += texto[i];
	}
	if( barra ) {
		s = sb + s;
		sb.clear();
	}
	
	return s;
}

int main() {
	string texto;

	while( cin >> texto ) {
		texto = home_end( texto );
		if( !texto.empty() )
			cout << texto << endl;
	}

	return 0;
}