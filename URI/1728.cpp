#include <bits/stdc++.h>
using namespace std;

int main() {
	int n1, n2, r, j;
	string exp;

	do {
		cin >> exp;
		j = 0;
		reverse( exp.begin(), exp.end() );
		for( int i=0; i<exp.size(); i++ ) {
			if( exp[i] == '=' ) {
				r = stoi( exp.substr( j, i ), NULL, 10 );
				j = i+1;
			}
			if( exp[i] == '+' ) {
				n2 = stoi( exp.substr( j, i ), NULL, 10 );
				j = i+1;
			}
		}
		n1 = stoi( exp.substr( j, exp.size() ), NULL, 10 );
		cout << ( n1 + n2 == r ? "True" : "False" ) << endl;
	} while( exp != "0=0+0" );

	return 0;
}