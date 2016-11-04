#include <iostream>
#include <map>
using namespace std;

map<string,float> mapa;

int main() {
	int n, m, p, qnt;
	float preco, valor;
	string fruta;

	cin >> n;
	while( n-- ) {
		valor = 0;
		cin >> m;
		for( int i=0; i<m; i++ ) {
			cin >> fruta >> preco;
			if( !mapa[fruta] )
				mapa[fruta] = preco;
		}
		cin >> p;
		for( int i=0; i<p; i++ ) {
			cin >> fruta >> qnt;
			valor += mapa[fruta]*qnt;
		}
		cout.precision(2);
		cout << "R$ " << fixed << valor << endl;
		mapa.clear();
	}

	return 0;
}