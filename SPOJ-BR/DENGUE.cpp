#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

vector<int> G[105];
int tarifa[105];
queue<int> fila;

int main() {
	int n, x, y, t=1,
		v, taxa, vila, menor_t;

	while( scanf( "%d", &n ) != EOF ) {
		for( int i=0; i<105; i++ ) G[i].clear();
		menor_t = 1000;

		for( int i=0; i<n-1; i++ ) {
			scanf( "%d%d", &x, &y );
			G[x-1].push_back( y-1 );
			G[y-1].push_back( x-1 );
		}
		for( int i=0; i<n; i++ ) {
			memset( tarifa, -1, sizeof tarifa );
			tarifa[i] = taxa = 0;

			fila.push( i );
			while( !fila.empty() ) {
				v = fila.front(), fila.pop();

				for( int j=0, k; j<G[v].size(); j++ ) {
					k = G[v][j];
					if( tarifa[k] == -1 ) {
						tarifa[k] = tarifa[v] + 1;
						if( taxa < tarifa[k] ) taxa = tarifa[k];
						fila.push( k );
					}
				}
			}
			if( taxa < menor_t ) menor_t = taxa, vila = i;
		}
		printf( "Teste %d\n%d\n\n", t++, vila+1 );
	}

	return 0;
}