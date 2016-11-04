#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool divisao_0, exp_valida;

ll calculaPosfixa( string posf ) {
	ll a = 0, b = 0, result = 0;
	stack<ll> pilha;

	for( int i = 0; i < posf.size() && exp_valida; i++ ) {
		if( posf[i] == ' ' ) continue;

		if( isdigit( posf[i] ) )
			pilha.push( (ll)( posf[i]-'0' ) );

		else {
			if( !pilha.empty() )
				b = pilha.top(), pilha.pop();
			else
				exp_valida = false;

			if( !pilha.empty() )
				a = pilha.top(), pilha.pop();
			else
				exp_valida = false;
			
			switch( posf[i] ) {
				case '+': result = a + b;
						  break;
				case '-': result = a - b;
						  break;
				case '*': result = a * b;
						  break;
				case '/': if( b != 0 )
							  result = (ll)floor( a / b );
						  else
							  divisao_0 = true;
						  break;
			}
			pilha.push( result );
		}
	}
	if( pilha.size() == 1 )
		result = pilha.top(), pilha.pop();
	else
		exp_valida = false;

	return result;
}

int main() {
	string posf;
	int result;

	while( getline( cin, posf ) ) {
		divisao_0 = false, exp_valida = true;
		reverse( posf.begin(), posf.end() );
		result = calculaPosfixa( posf );

		if( !exp_valida )
			cout << "Invalid expression.\n";
		else if( divisao_0 )
			cout << "Division by zero.\n";
		else
			cout << "The answer is " << result << ".\n";
	}

	return 0;
}
