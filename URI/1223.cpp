#include <bits/stdc++.h>
using namespace std;

#define INF 100000000.0

struct point {
	double x, y;
	point() { x = y = 0.0; }
	point( double _x, double _y ) : x(_x), y(_y) {}
} pI[1005], pF[1005];
double dist( point p1, point p2 ) { return hypot( p1.x - p2.x, p1.y - p2.y ); }

struct vec {
	double x, y;
	vec( double _x, double _y ) : x(_x), y(_y) {}
};

vec toVec( point a, point b ) { return vec( b.x - a.x, b.y - a.y ); }
double dot( vec a, vec b ) { return a.x*b.x + a.y*b.y; }
double norm_sq( vec v ) { return v.x*v.x + v.y*v.y; }
double norm( vec v ) { return sqrt( v.x*v.x + v.y*v.y ); }
double cross( vec a, vec b ) { return abs( a.x*b.y - a.y*b.x ); }

double distToLineSegment( point p, point a, point b ) {
	vec ap = toVec( a, p ), ab = toVec( a, b );
	double u = dot( ap, ab )/norm_sq( ab );
	if( u < 0.0 )
		return dist( p, a );
	if( u > 1.0 )
		return dist( p, b );

	return cross( ap, ab )/norm( ab );
}

int main() {
	int n, L, H;
	double D;

	while( scanf( "%d", &n ) != EOF ) {
		D = INF;

		scanf( "%d%d", &L, &H );
		for( int i=1; i<=n; i++ ) {
			pI[i].x = ( i&1 ? 0 : L );
			scanf( "%lf%lf%lf", &pI[i].y, &pF[i].x, &pF[i].y );

			D = min( D, i&1 ? L - pF[i].x : pF[i].x );
			if( i > 1 )
				D = min( D, distToLineSegment( pF[i-1], pI[i], pF[i] ) );
		}
		printf( "%.2lf\n", D );
	}

	return 0;
}