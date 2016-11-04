#include <bits/stdc++.h>
using namespace std;

struct aresta {
	int v;
	double d;

	aresta( int v, double d ) {
		this->v = v;
		this->d = d;
	}
	bool operator<( aresta A ) const { return d > A.d; }
};

vector<aresta> G[505];
priority_queue<aresta> fila;
bool cor[505];

int main() {
	int c, n, x[505], y[505];
	double D;

	scanf( "%d", &c );
	while( c-- ) {
		scanf( "%d", &n );
		for( int i=0; i<n; i++ )
			scanf( "%d%d", &x[i], &y[i] ),
			G[i].clear();

		for( int i=0; i<n; i++ )
			for( int j=i+1; j<n; j++ ) {
				D = sqrt( pow( x[i]-x[j], 2 ) + pow( y[i]-y[j], 2 ) );
				G[i].push_back( aresta( j, D ) );
				G[j].push_back( aresta( i, D ) );
			}
		
		memset( cor, false, sizeof cor );
		D = 0;
		fila.push( aresta( 0, 0.0 ) );
		while( !fila.empty() ) {
			aresta A = fila.top(); fila.pop();

			if( !cor[ A.v ] ) {
	        	cor[ A.v ] = true;
	        	D += A.d;
				
				for( int i=0; i<G[A.v].size(); i++ ) {
					aresta B = G[A.v][i];

					if( !cor[ B.v ] )
						fila.push( B );
				}
			}
		}
		printf( "%.2lf\n", D/100.0 );
	}

	return 0;
}