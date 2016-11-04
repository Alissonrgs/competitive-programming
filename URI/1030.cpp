#include <bits/stdc++.h>
using namespace std;

int main() {
	int nc, n, k;
	queue<int> fila;
	
	scanf( "%d", &nc );
	for( int j = 1; j <= nc; j++ ) {
		scanf( "%d%d", &n, &k );
		for( int i = 1; i <= n; i++ )
			fila.push( i );
			
		while( fila.size() != 1 ) {
			for( int i = 0; i < k-1; i++ )
				fila.push( fila.front() ),
				fila.pop();
			fila.pop();
		}
		printf( "Case %d: %d\n", j, fila.front() );
		while( !fila.empty() ) fila.pop();
	}

	return 0;
}
