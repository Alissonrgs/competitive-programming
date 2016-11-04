#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, v;
	string s;

	cin >> t;
	while( t-- ) {
		v = 1;
		cin >> s;
		for( int i=0; i<s.size(); i++ ) {
			if( s[i] == 'a' || s[i] == 'A' ||
				s[i] == 'e' || s[i] == 'E' ||
				s[i] == 'i' || s[i] == 'I' ||
				s[i] == 'o' || s[i] == 'O' ||
				s[i] == 's' || s[i] == 'S' )
				v *= 3;
			else
				v *= 2;
		}
		printf( "%d\n", v );
	}

	return 0;
}