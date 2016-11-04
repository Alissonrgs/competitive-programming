#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
 
vector<int> G[55];
queue<int> fila;
int p[55];
 
int main() {
	int C, E, L, P, cidade, t=1;
	bool espaco;
	
	while( scanf( "%d%d%d%d", &C, &E, &L, &P ) && C ) {
		espaco = false;
		memset( p, -1, sizeof p );
		for( int i=0; i<=50; i++ )
			G[i].clear();
		for( int i=0, X, Y; i<E; i++ ) {
			scanf( "%d%d", &X, &Y );
			G[X].push_back( Y );
			G[Y].push_back( X );
		}
		fila.push( L );
		p[L] = 0;
		while( !fila.empty() ) {
			cidade = fila.front(), fila.pop();
			
			if( p[cidade] < P  )
				for( int i=0; i<G[cidade].size(); i++ ) {
					int r = G[cidade][i];
					if( p[r] == -1 ) {
						p[r] = p[cidade] + 1;
						fila.push( G[cidade][i] );
					}
				}
		}
		printf( "Teste %d\n", t++ );
		for( int i=0; i<=C; i++ )
			if( i != L && p[i] != -1 )
				printf( "%s%d", ( espaco ? " " : "" ), i ), espaco = true;
		printf( "\n\n" );
	}
 
	return 0;
}