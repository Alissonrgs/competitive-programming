#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

vector<int> G[35];
stack<int> pilha;
int cor[35];
map<string,int> mapa;
map<int,string> amigos;

bool dfs( int v ) {
	cor[v] = 1;

	for( int i=0, j; i<G[v].size(); i++ ) {
		j = G[v][i];
		if( cor[j] == 1 || ( !cor[j] && !dfs( j ) ) )
			return false;
	}
	cor[v] = 2; 
	pilha.push( v );

	return true;
}

int main() {
	int n, a, t=1;
	string nome, amigo;
	bool p, espaco;

	while( cin >> n && n ) {
		mapa.clear();
		amigos.clear();

		for( int i=0; i<n; i++ ) {
			cin >> nome;
			amigos[i] = nome;
			mapa[nome] = i;
			G[i].clear();
		}
		for( int i=0; i<n; i++ ) {
			cin >> nome >> a;
			while( a-- ) {
				cin >> amigo;
				G[ mapa[amigo] ].push_back( mapa[nome] );
			}
		}
		memset( cor, 0, sizeof cor );
		espaco = false;
		p = true;
		while( !pilha.empty() ) pilha.pop();
		for( int i=0; i<n && p; i++ )
			if( !cor[i] )
				p = dfs( i );

		cout << "Teste " << t++ << endl;
		if( p )
			while( !pilha.empty() ) {
				cout << ( espaco ? " " : "" ) << amigos[ pilha.top() ];
				espaco = true;
				pilha.pop();
			}
		else
			cout << "impossivel";
		cout << endl << endl;
	}

	return 0;
}