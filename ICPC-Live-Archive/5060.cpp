#include <iostream>
#include <cmath>

#include <queue>
#include <vector>
using namespace std;

typedef struct Lutador {
	int id, forca, fi;
	vector<int> adv;
	Lutador() {};
	Lutador( int i ) { id = i; };
} Lutador;

int main() {
	int t, n, k;
	queue<Lutador> lutador;

	cin >> t;
	while( t-- ) {
		cin >> n >> k;
		for( int i=0; i<pow( 2, n ); i++ ) {
			Lutador lt( i+1 );
			cin >> lt.forca;
			lt.fi = lt.forca;
			lutador.push( lt );
		}
		while( lutador.size() > 1 ) {
			Lutador l1, l2;

			l1 = lutador.front();
			lutador.pop();
			l2 = lutador.front();
			lutador.pop();

			if( l1.forca == l2.forca ) {
				if( l1.id < l2.id ) {
					l1.adv.push_back( l2.id );
					l1.forca = k;
					if( l1.forca > l1.fi ) l1.forca = l1.fi;
					lutador.push( l1 );
				} else {
					l2.adv.push_back( l1.id );
					l2.forca = k;
					if( l2.forca > l2.fi ) l2.forca = l2.fi;
					lutador.push( l2 );
				}
			
			} else if( l1.forca > l2.forca ) {
				l1.adv.push_back( l2.id );
				l1.forca += -l2.forca + k;
				if( l1.forca > l1.fi ) l1.forca = l1.fi;
				lutador.push( l1 );

			} else {
				l2.adv.push_back( l1.id );
				l2.forca += -l1.forca + k;
				if( l2.forca > l2.fi ) l2.forca = l2.fi;
				lutador.push( l2 );
			}
		}
		Lutador vencedor = lutador.front();
		lutador.pop();

		cout << vencedor.id << endl << vencedor.adv[0];
		for( int i=1; i<vencedor.adv.size(); i++ )
			cout << " " << vencedor.adv[i];
		cout << endl;
	}

	return 0;
}