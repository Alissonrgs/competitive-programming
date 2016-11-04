#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, q, op, p, pv, pc;
	string s, v, c;

	cin >> t;
	for( int i = 1; i <= t; i++ ) {
		v.clear(), c.clear();
		pv = pc = 0;
		cin >> s >> q;
		for( int j = 0; j < s.size(); j++ ) {
			if( s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' ) {
				v += s[j];
				s[j] = 'V';
			
			} else {
				c += s[j];
				s[j] = 'C';
			}
		}
		cout << "Caso #" << i << ":\n";
		while( q-- ) {
			cin >> op;
			if( op == 0 ) {
				cin >> p;
				if( !v.empty() ) {
					pv -= p;
					while( pv < 0 ) pv += v.size();
				}
			} else if( op == 1 ) {
				cin >> p;
				if( !c.empty() ) {
					pc -= p;
					while( pc < 0 ) pc += c.size();
				}
			} else if( op == 2 ) {
				for( int j = 0; j < s.size(); j++ ) {
					if( s[j] == 'V' ) {
						cout << v[ pv++ ];
						pv %= v.size();
					} else {
						cout << c[ pc++ ];
						pc %= c.size();
					}
				}
				cout << endl;
			}
		}
	}

	return 0;
}