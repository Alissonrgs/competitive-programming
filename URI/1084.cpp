#include <bits/stdc++.h>
using namespace std;

stack<char> pilha;

int main() {
	string D;
	int n, d,qnt;
	char digito;

	while( scanf( "%d%d", &n, &d ) && n ) {
		D = "";
		for( int i=0; i<n; i++ ) {
			scanf( " %c", &digito );
			while( !pilha.empty() && pilha.top() < digito && d > 0 )
				pilha.pop(), d--;
			pilha.push( digito );
		}
		while( !pilha.empty() && d > 0 )
			pilha.pop(), d--;
		
		while( !pilha.empty() )
			D += pilha.top(), pilha.pop();
		
		reverse( D.begin(), D.end() );
		cout << D << endl;
	}

	return 0;
}