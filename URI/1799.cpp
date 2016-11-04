#include <bits/stdc++.h>
using namespace std;

map<string,int> mapa;

vector<int> G[4005];
queue<int> fila;
int d[4005];

int main() {
	int p, l, j = 1;
	string x, y;

	cin >> p >> l;
	for( int i=0; i<l; i++ ) {
		cin >> x >> y;
		if( !mapa[x] )
			mapa[x] = j++;
		if( !mapa[y] )
			mapa[y] = j++;

		G[ mapa[x] ].push_back( mapa[y] );
		G[ mapa[y] ].push_back( mapa[x] );
	}

	memset( d, -1, sizeof d );
	d[ mapa["*"] ] = 0;
	fila.push( mapa["*"] );
	
	while( !fila.empty() ) {
		int A = fila.front(); fila.pop();

		for( int i=0; i<G[A].size(); i++ ) {
			int B = G[A][i];

			if( d[B] == -1 ) {
				d[B] = d[A] + 1;
				fila.push( B );
			}
		}
	}
	cout << d[ mapa["Entrada"] ] + d[ mapa["Saida"] ] << endl;

	return 0;
}