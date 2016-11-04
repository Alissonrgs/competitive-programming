#include <iostream>
using namespace std;

int main() {
	int n, l, soma;
	string s;

	cin >> n;
	while( n-- ) {
		soma = 0;
		cin >> l;
		for( int i=0; i<l; i++ ) {
			cin >> s;
			for( int j=0; j<s.size(); j++ )
				soma += int( s[j] - 'A' ) + i + j;
		}
		cout << soma << endl;
	}

	return 0;
}