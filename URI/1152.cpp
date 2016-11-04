#include <bits/stdc++.h>
using namespace std;

struct aresta {
	int v, d;

	aresta( int v, int d ) { this->v = v; this->d = d; }
	bool operator<( aresta a ) const { return d > a.d; }
};

vector<aresta> G[200005];
priority_queue<aresta> fila;
bool d[200005];

int main() {
	int m, n, x, y, z, custo;

	while( scanf( "%d%d", &m, &n ) && m ) {
		custo = 0;
		for( int i=0; i<m; i++ ) G[i].clear();
		for( int i=0; i<n; i++ ) {
	        scanf( "%d%d%d", &x, &y, &z );
	        G[x].push_back( aresta( y, z ) );
	    	G[y].push_back( aresta( x, z ) );
	    	custo += z;
	    }
	    
	    memset( d, 0, sizeof d );
	    fila.push( aresta( 0, 0 ) );
        while( !fila.empty() ) {
            aresta A = fila.top(); fila.pop();
            
	        if( !d[ A.v ] ) {
	        	d[ A.v ] = true;
	        	custo -= A.d;
	            for( int j=0; j<G[ A.v ].size(); j++ ) {
	                aresta B = G[ A.v ][j];

	                if( !d[ B.v ] )
	                    fila.push( aresta( B ) );
	            }
	        }
        }
        printf( "%d\n", custo );
	}

	return 0;
}