#include <bits/stdc++.h>
using namespace std;

struct carro {
	int c, s;
	carro( int _c, int _s ) : c(_c), s(_s) {}
};

stack<carro> pilha;

int main() {
	int n, k, c, s;
	bool possivel;

	while( scanf( "%d%d", &n, &k ) && n ) {
		possivel = true;
		for( int i = 0; i < n; i++ ) {
			scanf( "%d%d", &c, &s );
			while( !pilha.empty() && c >= pilha.top().s ) pilha.pop();
			if( pilha.empty() || ( pilha.size() < k && s < pilha.top().s ) )
				pilha.push( carro( c, s ) );
			else
				possivel = false;
		}
		while( !pilha.empty() ) pilha.pop();
		printf( "%s\n", possivel ? "Sim" : "Nao" );
	}

	return 0;
}