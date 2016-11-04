#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

struct Pessoa {
	string nome, sobrenome;
	int numero;
} pessoa[105];

vector<int> G[105], temp;
map<string,int> mapa;
queue<int> fila;

bool ord( Pessoa a, Pessoa b ) {
	if( a.sobrenome == b.sobrenome ) return a.nome < b.nome;
	else return a.sobrenome < b.sobrenome;
}

int main() {
	int a, id, p, t=1;
	char c;
	string nome, sobrenome, p_aux, aux;

	while( cin >> a && a ) {
		for( int i=0; i<105; i++ ) G[i].clear();
		mapa.clear();
		mapa["P. Erdos"] = 0;
		pessoa[0].nome = "P.";
		pessoa[0].sobrenome = "Erdos";
		pessoa[0].numero = 0;
		id = 1;

		for( int i=0; i<a; i++ ) {
			do {
				cin >> nome >> sobrenome;
				c = sobrenome[ sobrenome.size()-1 ];
				sobrenome.erase( sobrenome.size()-1 );
				aux = nome + " " + sobrenome;
				if( !mapa.count( aux ) ) {
					mapa[ aux ] = id;
					pessoa[id].nome = nome;
					pessoa[id].sobrenome = sobrenome;
					pessoa[id].numero = -1;
					id++;
				}
				temp.push_back( mapa[aux] );
				for( int i=0; i<temp.size(); i++ )
					if( temp[i] != mapa[aux] ) {
						p_aux = pessoa[ temp[i] ].nome + " " + pessoa[ temp[i] ].sobrenome;

						G[ mapa[aux] ].push_back( mapa[p_aux] );
						G[ mapa[p_aux] ].push_back( mapa[aux] );
					}
			} while( c != '.' );
			temp.clear();
		}
		fila.push( 0 );
		while( !fila.empty() ) {
			p = fila.front(), fila.pop();
			
			for( int i=0, j; i<G[p].size(); i++ ) {
				j = G[p][i];
				if( pessoa[j].numero == -1 ) {
					pessoa[j].numero = pessoa[p].numero + 1;
					fila.push( j );
				}
			}
		}
		sort( &pessoa[0], &pessoa[id], ord );
		cout << "Teste " << t++ << endl;
		for( int i=0; i<id; i++ ) {
			if( pessoa[i].nome == "P." && pessoa[i].sobrenome == "Erdos" ) continue;
			cout << pessoa[i].nome + " " + pessoa[i].sobrenome << ": ";
			if( pessoa[i].numero == -1 )
				cout << "infinito\n";
			else
				cout << pessoa[i].numero << endl;
		}
		cout << endl;
	}

	return 0;
}