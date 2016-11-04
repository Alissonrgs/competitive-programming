#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t;
	bool p;
	size_t pn, pinv;
	string proibida, str_n, str_inv;

	cin >> t;
	while( t-- ) {
		p = true;

		cin >> proibida >> str_n;
		
		while( str_n.size() < proibida.size() )
			str_n += str_n;
		str_n += str_n;
		str_inv = str_n;
		reverse( str_inv.begin(), str_inv.end() );

		pn = str_n.find( proibida );
		pinv = str_inv.find( proibida );
		
		if( pn == string::npos && pinv == string::npos ) p = false;
		cout << ( p ? "S": "N" ) << endl;
	}

	return 0;
}