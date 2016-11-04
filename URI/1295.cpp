#include <bits/stdc++.h>
using namespace std;

#define INF 10000.0

struct ponto {
    double x, y;
    bool operator<( ponto a ) const { return x < a.x; }
} P[10005];

int main() {
	int n;
	double dis;

	while( scanf( "%d", &n ) && n ) {
		dis = INF;
		for( int i=0; i<n; i++ )
			scanf( "%lf%lf", &P[i].x, &P[i].y );
		
		sort( P, P+n );

		for( int i=0; i<n; i++ )
			for( int j=i+1; j<n; j++ )
				if( P[j].x - P[i].x < dis )
					dis = min( dis, sqrt( ( P[j].x-P[i].x )*( P[j].x-P[i].x ) + ( P[j].y-P[i].y )*( P[j].y-P[i].y ) ) );
				else
					break;

		dis < INF ? printf( "%.4lf\n", dis ) : printf( "INFINITY\n" );
	}

	return 0;
}