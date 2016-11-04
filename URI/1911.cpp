#include <bits/stdc++.h>
using namespace std;

map< string, int > mapa;

int main() {
	int n, m, falsa, dif;
	string nome, assinatura[55];

	while( cin >> n && n ) {
		falsa = 0;
		mapa.clear();
		for( int i = 1; i <= n; i++ ) {
			cin >> nome >> assinatura[i];
			mapa[ nome ] = i;
		}
		cin >> m;
		while( m-- ) {
			cin >> nome >> assinatura[0];
			dif = 0;
			for( int i = 0; i <= (int)assinatura[0].size() && dif <=1; i++ )
				if( assinatura[ mapa[ nome ] ][i] != assinatura[0][i] )
					dif++;

			if( dif > 1 )
				falsa++;
		}
		printf( "%d\n", falsa );
	}

	return 0;
}