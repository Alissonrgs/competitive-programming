#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, maior;
	char c;
	bool espaco;
	string str, s[55];

	cin >> n;
	for( int i=0; i<n; i++ ) {
		maior = 0;
		for( int i=1; i<=50; i++ )
			s[i].clear();
		do {
			cin >> str && scanf( "%c", &c );
			s[ str.size() ] += ( s[ str.size() ].empty() ? "" : " " ) + str;
			maior = max( maior, (int)str.size() );
		} while( c != '\n' );

		espaco = false;
		for( int i=maior; i>=0; i-- )
			if( !s[i].empty() )
				cout << ( espaco ? " " : "" ) << s[i],
				espaco = true;
		cout << endl;
	}

	return 0;
}