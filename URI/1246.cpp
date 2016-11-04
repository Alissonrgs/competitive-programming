#include <bits/stdc++.h>
using namespace std;

struct carro {
	int placa, tam, i;

	carro( int placa, int tam, int i ) {
		this->placa = placa;
		this->tam = tam;
		this->i = i;
	}
};

vector<carro> e;
bool espaco[1005];

int main() {
	int c, n, p, q, vaga, fatura;
	char cs;

	while( scanf( "%d%d", &c, &n ) != EOF ) {
		fatura = 0;
		memset( espaco, 0, sizeof espaco );
		e.clear();
		for( int i=0; i<n; i++ ) {
			scanf( " %c", &cs );
			if( cs == 'C' ) {
				scanf( "%d%d", &p, &q );
				vaga = 0;
				for( int i=1; i<=c; i++ ) {
					if( !espaco[i] ) vaga++;
					else vaga = 0;

					if( vaga >= q ) {
						for( int j=i+1-q; j<=i; j++ )
							espaco[j] = 1;
						fatura += 10;
						e.push_back( carro( p, q, i+1-q ) );
						break;
					}
				}

			} else {
				scanf( "%d", &p );
				for( int i=0; i<e.size(); i++ ) {
					carro A = e[i];
					if( A.placa == p ) {
						for( int j=A.i; j<A.i+A.tam; j++ )
							espaco[j] = 0;
						e.erase( e.begin()+i );
						break;
					}
				}
			}
		}
		printf( "%d\n", fatura );
	}

	return 0;
}