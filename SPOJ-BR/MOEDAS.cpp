#include <cstdio>
#include <algorithm>
using namespace std;

#define inf 1000000000

int main() {
	int m, n, moeda[105], qm[50005];

	while( scanf( "%d", &m ) && m ) {
		scanf( "%d", &n );
		for( int i=0; i<n; i++ )
			scanf( "%d", &moeda[i] );
		
		qm[0] = 0;
		for( int i=1; i<=m; i++ ) {
		    qm[i] = inf;
		    for( int j=0; j<n; j++ )
		        if( i-moeda[j] >= 0 )
		            qm[i] = min( qm[i], qm[ i-moeda[j] ]+1 );
		}
		
		if( qm[m] == inf )
			printf( "Impossivel\n" );
		else
			printf( "%d\n", qm[m] );
	}

	return 0;
}