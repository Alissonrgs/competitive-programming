#include <bits/stdc++.h>
using namespace std;

stack<int> pilha;

int main() {
	int n, v, i, t;
	bool possivel;

	while( scanf( "%d", &n ) && n ) {
		v = 1;
		while( v ) {
			i = n;
			t = 1;
			possivel = true;

			while( i-- && scanf( "%d", &v ) && v ) {
				if( pilha.empty() )
					pilha.push( t++ );
				
				while( v != pilha.top() && t <= n )
					pilha.push( t++ );

				if( v != pilha.top() )
					possivel = false;
				else
					pilha.pop();
			}
			if( !pilha.empty() ) {
				while( !pilha.empty() )
					pilha.pop();
				possivel = false;
			}

			if( v )
				printf( "%s\n", ( possivel ? "Yes" : "No" ) );
		}
		printf( "\n" );
	}

	return 0;
}