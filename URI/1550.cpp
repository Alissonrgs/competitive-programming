#include <bits/stdc++.h>
using namespace std;

struct aresta {
	int a, aperto;

	aresta( int a = 0, int aperto = 0 ) {
		this->a = a;
		this->aperto = aperto;
	}
};

queue<aresta> fila;
bool cor[10005];

int inversao( int n ) {
	int a = 0;
	
	while( n > 0 ) {
		a *= 10;
		a += n%10;
		n /= 10;
	}
	return a;
}

int main() {
	int t, a, a_inv, b, aperto;
	aresta n;

	scanf( "%d", &t );
	while( t-- ) {
		scanf( "%d%d", &a, &b );

		while( !fila.empty() ) fila.pop();
		fila.push( aresta( a, 0 ) );
		memset( cor, 0, sizeof cor );

		while( !fila.empty() ) {
			n = fila.front(); fila.pop();
			a = n.a, aperto = n.aperto+1;

			if( a > 10000 ) continue;
			a_inv = inversao( a );
			if( !cor[a_inv] ) {
				if( a_inv == b ) break;
				cor[a_inv] = 1;
				fila.push( aresta( a_inv, aperto ) );
			}
			if( !cor[a+1] ) {
				if( a+1 == b ) break;
				cor[a+1] = 1;
				fila.push( aresta( a+1, aperto ) );
			}
		}

		printf( "%d\n", aperto );
	}

	return 0;
}