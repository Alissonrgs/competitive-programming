#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, l, c, p, qnt;
	string cpv[55], cpo[55], palavra;

	cin >> t;
	while( t-- ) {
		cin >> l >> c;
		for( int i=0; i<c; i++ ) cpv[i].clear();
		for( int i=0; i<l; i++ ) {
			cin >> cpo[i];
			for( int j=0; j<c; j++ )
				cpv[j] += cpo[i][j];
		}
		cin >> p;
		for( int i=0; i<p; i++ ) {
			qnt = 0;
			cin >> palavra;
			if( palavra.size() != 1 ) {
				for( int j=0; j<l; j++ )
					for( int k=0; k<c-palavra.size()+1; k++ ) {
						bool igual = true;
						for( int id=0, chave=k; id<palavra.size(); id++, chave++ )
							if( palavra[id] != cpo[j][chave] ) {
								igual = false;
								break;	
							}
						if( igual ) qnt++;
					}
				for( int j=0; j<c; j++ )
					for( int k=0; k<l-palavra.size()+1; k++ ) {
						bool igual = true;
						for( int id=0, chave=k; id<palavra.size(); id++, chave++ )
							if( palavra[id] != cpv[j][chave] ) {
								igual = false;
								break;	
							}
						if( igual ) qnt++;
					}
			} else {
				for( int j=0; j<l; j++ )
					for( int k=0; k<c; k++ )
						if( palavra[0] == cpo[j][k] )
							qnt++;
			}
			cout << qnt << endl;
		}
	}

	return 0;
}