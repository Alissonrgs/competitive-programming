#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9

struct point {
	double x, y;
	point() { x = y = 0.0; }
	point( double _x, double _y ) : x(_x), y(_y) {}
};
double dist( point p1, point p2 ) { return hypot( p1.x - p2.x, p1.y - p2.y ); }

struct square {
	point inf, sup;
	square() {}
	square( point _inf, point _sup ) : inf(_inf), sup(_sup) {}
} s1, s2;

double distS( square a, square b ) {
	if( a.inf.x > b.inf.x ) return distS( b, a );
	if( b.inf.x < a.sup.x || fabs( b.inf.x - a.sup.x ) < EPS ) {
		if( b.inf.y > a.sup.y ) return b.inf.y - a.sup.y;
		if( b.sup.y < a.inf.y ) return a.inf.y - b.sup.y;
		return 0;
	}
	if( b.inf.y > a.sup.y ) return dist( b.inf, a.sup );
	if( b.sup.y < a.inf.y )
		return dist( point( b.inf.x, b.sup.y ), point( a.sup.x, a.inf.y ) );
	return b.inf.x - a.sup.x;
}

int main() {
	int n;
	double aah, cx, cy, l;
	bool possivel = true;

	scanf( "%d%lf", &n, &aah );
	for( int i=0; i<n && possivel; i++ ) {
		scanf( "%lf%lf%lf", &cx, &cy, &l );
		s2 = square( point( cx - l/2.0, cy - l/2.0 ), point( cx + l/2.0, cy + l/2.0 ) );
		if( i )
			possivel = ( distS( s2, s1 ) <= aah );
		s1 = s2;
	}
	printf( "%s\n", possivel ? "YEAH" : "OUCH" );

	return 0;
}