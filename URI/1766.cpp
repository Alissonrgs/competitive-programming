#include <bits/stdc++.h>
using namespace std;

struct rena {
	string nome;
	int peso, idade;
	double altura;
	rena( string _nome, int _peso, int _idade, double _altura ) : nome(_nome), peso(_peso), idade(_idade), altura(_altura) {};
};

vector<rena> v;

bool ord( rena ra, rena rb ) {
	if( ra.peso == rb.peso ) {
		if( ra.idade == rb.idade ) {
			if( ra.altura == rb.altura ) {
				return ra.nome < rb.nome;
			} else
				return ra.altura < rb.altura;
		} else
			return ra.idade < rb.idade; 
	} else
		return ra.peso > rb.peso;
}

int main() {
	int t, n, m, peso, idade;
	double altura;
	string nome;
	
	cin >> t;
	for( int c = 1; c <= t; c++ ) {
		cin >> n >> m;
		
		for( int i = 0; i < n; i++ ) {
			cin >> nome >> peso >> idade >>altura; 
			v.push_back( rena( nome, peso, idade, altura ) );
		}
		sort( v.begin(), v.end(), ord );
		cout << "CENARIO {" << c << "}\n";
		for( int i = 0; i < m; i++ )
			cout << i+1 << " - " << v[i].nome << endl;
		v.clear();
	}

	return 0;
}
