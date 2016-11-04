#include <bits/stdc++.h>
using namespace std;

int main() {
	int m, count, maior, mapa[256];
	string texto;

	while( cin >> m && m ) {
		memset( mapa, 0, sizeof mapa );
		count = maior = 0;
		cin.ignore();
		getline( cin, texto );

		for( int i=0, j=0; i<texto.size(); i++ ) {
			mapa[texto[i]]++;
			if( mapa[texto[i]] == 1 ) {
				count++;
				while( count > m ) {
					if( --mapa[texto[j]] == 0 )
						count--;
					j++;
				}
			}
			maior = max( maior, i - j + 1 );
		}
		cout << maior << endl;
	}

	return 0;
}