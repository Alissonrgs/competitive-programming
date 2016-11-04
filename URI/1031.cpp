#include <bits/stdc++.h>
using namespace std;

queue<int> fila;

int main() {
	int n, id;

	while( scanf( "%d", &n ) && n ) {
		for( int i=1; i<=300; i++ ) {
			while( !fila.empty() ) fila.pop();
			for( int j=1; j<=n; j++ )
				fila.push( j );

			while( !fila.empty() ) {
				id = fila.front(); fila.pop();
				for( int j=0; j<i-1; j++ )
					fila.push( fila.front() ), fila.pop();
			}
			if( id == 13 ) {
				printf( "%d\n", i );
				break;
			}
		}
	}

	return 0;
}