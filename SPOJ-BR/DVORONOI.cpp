#include <bits/stdc++.h>
using namespace std;

struct point {
	double x, y, z;
	point() {}
	point( double _x, double _y, double _z ) : x(_x), y(_y), z(_z) {}
};

struct vec {
	double x, y, z;
	vec() {}
	vec( double _x, double _y, double _z ) : x(_x), y(_y), z(_z) {}
};
vec toVec( point a, point b ) { return vec( b.x - a.x, b.y - a.y, b.z - a.z ); }

int main() {
	int t;
	double x, y, z;
	point P[4];
	vec V[4];

	scanf( "%d", &t );
	while( t-- ) {
		for( int i = 0; i < 4; i++ ) {
			scanf( "%lf%lf%lf", &x, &y, &z );
			P[i] = point( x, y, z );
		}
		for( int i = 1; i < 4; i++ )
			V[i] = toVec( P[0], P[i] );
		printf( "%lf\n", fabs( V[1].x*( V[2].y*V[3].z - V[2].z*V[3].y ) + V[1].y*( V[2].z*V[3].x - V[2].x*V[3].z ) + V[1].z*( V[2].x*V[3].y - V[2].y*V[3].x ) )/6.0 );
	}

	return 0;
}