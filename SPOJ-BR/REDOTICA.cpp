#include <bits/stdc++.h>
using namespace std;

struct aresta {
	int pi, v, d;

	aresta( int pi, int v, int d ) { this->pi = pi; this->v = v; this->d = d; }
	bool operator<( aresta a ) const { return d > a.d; }
};

vector<aresta> G[105];
priority_queue<aresta> fila;
bool d[105];

int main() {
	int m, n, x, y, z, t = 1;

	while( scanf( "%d%d", &n, &m ) && n ) {
		for( int i=1; i<=n; i++ ) G[i].clear();
		for( int i=0; i<m; i++ ) {
	        scanf( "%d%d%d", &x, &y, &z );
	        G[x].push_back( aresta( 0, y, z ) );
	    	G[y].push_back( aresta( 0, x, z ) );
	    }
	    
	    memset( d, 0, sizeof d );
	    fila.push( aresta( 0, 1, 0 ) );
	    printf( "Teste %d\n", t++ );
        while( !fila.empty() ) {
            aresta A = fila.top(); fila.pop();
            
	        if( !d[ A.v ] ) {
	        	d[ A.v ] = true;
	        	if( A.pi )
	        		printf( "%d %d\n", ( A.pi > A.v ? A.v : A.pi ), ( A.pi > A.v ? A.pi : A.v ) );

	            for( int j=0; j<G[ A.v ].size(); j++ ) {
	                aresta B = G[ A.v ][j];

	                if( !d[ B.v ] )
	                    fila.push( aresta( A.v, B.v, B.d ) );
	            }
	        }
        }
        printf( "\n" );
	}

	return 0;
}