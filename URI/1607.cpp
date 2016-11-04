#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, op;
	string a, b;

	cin >> t;
	while( t-- ) {
		op = 0;
		cin >> a >> b;
		for( int i=0; i<a.size(); i++ ) {
			if( a[i] > b[i] )
				op += (int)( 'z' - a[i] + b[i] - 'a' + 1 );
			if( a[i] < b[i] )
				op += (int)( b[i] - a[i] );
		}
		cout << op << endl;
	}

	return 0;
}