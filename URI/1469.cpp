#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

vector<int> G[505];
int idade[505];
bool cor[505];

int dfs( int V, bool m ) {
	int menor = m ? 101 : idade[V];
	
	cor[V] = true;
	for( int i=0, j; i<G[V].size(); i++ ) {
		j = G[V][i];
		if( !cor[j] )
			menor = min( menor, dfs( j, 0 ) );
	}

	return menor;
}

int main() {
	int N, M, I, X, Y, E, menor;
	char inst;

	while( cin >> N >> M >> I ) {
		for( int i=0; i<N; i++ ) {
			G[i].clear();
			cin >> idade[i];
		}
		for( int i=0; i<M; i++ ) {
			cin >> X >> Y;
			G[Y-1].push_back( X-1 );
		}
		while( I-- ) {
			cin >> inst;
			if( inst == 'P' ) {
				cin >> E;
				memset( cor, 0, sizeof cor );
				menor = dfs( E-1, 1 );
				if( menor == 101 ) cout << "*\n";
				else cout << menor << endl;

			} else {
				cin >> X >> Y;
				swap( G[X-1], G[Y-1] );
				for( int i=0; i<N; i++ )
					for( int j=0; j<G[i].size(); j++ ) {
						if( G[i][j] == X-1 ) G[i][j] = Y-1;
						else if( G[i][j] == Y-1 ) G[i][j] = X-1;
					}
			}
		}
	}

	return 0;
}