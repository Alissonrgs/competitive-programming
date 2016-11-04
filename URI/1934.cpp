#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000

int main() {
	int l, c, vl[105], vc[105], result, count;
	string x[105][105], aux;
	map<string,int> mapa;
	map<string,int>::iterator it;

	cin >> l >> c;
	for( int i = 0; i < l; i++ ) {
		for( int j = 0; j < c; j++ ) {
			cin >> x[i][j];
			mapa[ x[i][j] ] = INF;
		}
		cin >> vl[i];
	}
	for( int j = 0; j < c; j++ )
		cin >> vc[j];

	for( int k = 0; k < mapa.size(); k++ ) {
		for( int i = 0; i < l; i++ ) {
			aux.clear(); count = -1; result = vl[i];

			for( int j = 0; j < c; j++ ) {
				if( mapa[ x[i][j] ] != INF ) result -= mapa[ x[i][j] ];
				else if( aux.empty() ) aux = x[i][j], count = 1;
				else if( x[i][j] != aux ) {
					count = -1;
					break;
				}
				else count++;
			}
			if( count != -1 ) mapa[ aux ] = result/count;
		}

		for( int i = 0; i < c; i++ ) {
			aux.clear(); count = -1; result = vc[i];

			for( int j = 0; j < l; j++ ) {
				if( mapa[ x[j][i] ] != INF ) result -= mapa[ x[j][i] ];
				else if( aux.empty() ) aux = x[j][i], count = 1;
				else if( x[j][i] != aux ) {
					count = -1;
					break;
				}
				else count++;
			}
			if( count != -1 ) mapa[ aux ] = result/count;
		}		
	}
	for( it = mapa.begin(); it != mapa.end(); it++ )
		cout << it->first << " " << it->second << endl;

	return 0;
}