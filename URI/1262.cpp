#include <bits/stdc++.h>
using namespace std;

int main() {
	int p, qr, qc;
	string s;

	while( cin >> s >> p ) {
		qc = qr = 0;
		for( int i=0; i<s.size(); i++ )
			if( s[i] == 'W' ) {
				if( qr )
					qc++, qr = 0;
				qc++;
			} else {
				qr++;
				if( qr == p )
					qc++, qr = 0;
			}
			
		if( qr )
			qc++;

		cout << qc << endl;
	}

	return 0;
}