#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9

struct point {
   	int x, y;
   	point() { x = y = 0.0; }
   	point( int _x, int _y ) : x(_x), y(_y) {}
};

struct vec {
   	int x, y;
   	vec( int _x, int _y ) : x(_x), y(_y) {}
};
vec toVec( point a, point b ) { return vec( b.x - a.x, b.y - a.y ); }

int cross( vec a, vec b ) { return a.x*b.y - a.y*b.x; }
bool ccw( point p, point q, point r ) { return cross( toVec( p, q ), toVec( p, r ) ) > 0; }
bool nccw( point p, point q, point r ) { return cross( toVec( p, q ), toVec( p, r ) ) < 0; }

struct parede {
	point a, b;
	parede() {}
	parede( point _a, point _b ) : a(_a), b(_b) {}
} p[1005];

int main() {
	int n, d, a, b;

	scanf( "%d", &n );
	for( int i=0; i<=n; i++ ) {
		scanf( "%d%d%d", &d, &a, &b );
		p[i].a = point( d, a );
		p[i].b = point( d, b );
	}

	int cima = 0, baixo = 0;
	bool passa = true;
	for( int j=1; j<n && passa; j++ ) {
		if( ccw( point( 0, 0 ), p[cima].b, p[j].a ) ) passa = false;
		if(	nccw( point( 0, 0 ), p[cima].b, p[j].b ) ) {
			cima = j;
			if( ccw( point( 0, 0 ), p[cima].b, p[j].a ) ) passa = false;
		}

		if( nccw( point( 0, 0 ), p[baixo].a, p[j].b ) ) passa = false;
		if( ccw( point( 0, 0 ), p[baixo].a, p[j].a ) ) {
			baixo = j;
			if( nccw( point( 0, 0 ), p[baixo].a, p[j].b ) ) passa = false;
		}
	}
	if( passa ) {
		if( ccw( point( 0, 0 ), p[cima].b, p[n].a ) ) passa = false;
		if( nccw( point( 0, 0 ), p[baixo].a, p[n].b ) ) passa = false;
	}
	printf( "%s\n", passa ? "Y" : "N" );

	return 0;
}