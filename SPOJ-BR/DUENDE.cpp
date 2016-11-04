#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Salao {
	int i, j, p;
};

int G[15][15];
queue<Salao> fila;

int main() {
	int n, m, t=1, menor;
	Salao s, v;

	scanf( "%d%d", &n, &m );
	menor = 1000;
	for( int i=0; i<n; i++ )
		for( int j=0; j<m; j++ ) {
			scanf( "%d", &G[i][j] );
			if( G[i][j] == 3 )
				s.i = i, s.j = j, s.p = 0;
		}
	fila.push( s );
	while( !fila.empty() ) {
		v = fila.front(), fila.pop();

		s = v;
		if( v.i-1 >= 0 ) {
			s.i--;
			if( G[s.i][s.j] == 1 )
				s.p++, fila.push( s );
			else if( G[s.i][s.j] == 0 && s.p + 1 < menor )
				menor = s.p+1;
			G[s.i][s.j] = 2;
		}
		s = v;
		if( v.i+1 < n ) {
			s.i++;
			if( G[s.i][s.j] == 1 )
				s.p++, fila.push( s );
			else if( G[s.i][s.j] == 0 && s.p + 1 < menor )
				menor = s.p+1;
			G[s.i][s.j] = 2;
		}
		s = v;
		if( v.j-1 >= 0 ) {
			s.j--;
			if( G[s.i][s.j] == 1 )
				s.p++, fila.push( s );
			else if( G[s.i][s.j] == 0 && s.p + 1 < menor )
				menor = s.p+1;
			G[s.i][s.j] = 2;
		}
		s = v;
		if( v.j+1 < m ) {
			s.j++;
			if( G[s.i][s.j] == 1 )
				s.p++, fila.push( s );
			else if( G[s.i][s.j] == 0 && s.p + 1 < menor )
				menor = s.p + 1;
			G[s.i][s.j] = 2;
		}
	}
	printf( "%d\n", menor );

	return 0;
}