#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct aresta {
	int v, d;
	aresta( int v, int d ) { this->v = v; this->d = d; }
	bool operator<( aresta a ) const { return a.d > d; }
};

vector<aresta> G[1005];
priority_queue<aresta> fila;
int d[1005];

int main() {
	int n, m, s, t, b;

	cin >> n >> m;
	for( int i=0; i<m; i++ ) {
		cin >> s >> t >> b;
		G[s].push_back( aresta( t, b ) );
		G[t].push_back( aresta( s, b ) );
	}

	memset( d, -1, sizeof d );
    d[0] = 0;
    fila.push( aresta( 0, d[0] ) );

    while( !fila.empty() ) {
        aresta A = fila.top(); fila.pop();

        for( int j=0; j<G[ A.v ].size(); j++ ) {
            aresta B = G[ A.v ][j];
             
            if( d[ B.v ] == -1 || d[ B.v ] > d[ A.v ] + B.d ) {
                d[ B.v ] = d[ A.v ] + B.d;
                fila.push( aresta( B.v, d[ B.v ] ) );
            }
        }
    }
    cout << d[n+1] << endl;

	return 0;
}