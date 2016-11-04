#include <bits/stdc++.h>
using namespace std;

struct point {
	int x, y;
	point() { x = y = 0; }
	point( int _x, int _y ) : x(_x), y(_y) {}
	bool operator==( const point &p ) const { return abs( x - p.x ) == 0 && abs( y - p.y ) == 0; }
} pivot;
double dist( point a, point b ) { return hypot( a.x - b.x, a.y - b.y ); }

struct vec {
	int x, y;
	vec( int _x, int _y ) : x(_x), y(_y) {}
};
vec toVec( point a, point b ) { return vec( b.x - a.x, b.y - a.y ); }
int cross( vec a, vec b ) { return a.x*b.y - a.y*b.x; }
bool ccw( point p, point q, point r ) {	return cross( toVec( p, q ), toVec( p, r ) ) >= 0; }
bool collinear( point p, point q, point r ) { return abs( cross( toVec( p, q ), toVec( p, r ) ) ) == 0; }

double area( const vector<point> &P ) {
    double result = 0.0, x1, y1, x2, y2;
    for( int i=0; i<(int)P.size()-1; i++ ) {
        x1 = P[i].x; x2 = P[i+1].x;
        y1 = P[i].y; y2 = P[i+1].y;
    	result += ( x1*y2 - x2*y1 );
    }
    return fabs(result)/2.0;
}
bool angleCmp( point a, point b ) { 
	if( collinear( pivot, a, b ) )
		return dist( pivot, a ) < dist( pivot, b );
	double d1x = a.x - pivot.x, d1y = a.y - pivot.y,
		   d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	return ( atan2( d1y, d1x ) - atan2( d2y, d2x ) ) < 0;
}
vector<point> CH( vector<point> P ) {
	int i, j, n = (int)P.size();

	if( n <= 3 ) {
		if( !( P[0] == P[n-1] ) ) P.push_back( P[0] );
		return P;
	}
	int P0 = 0;
	for( i=1; i<n; i++ )
		if( P[i].y < P[P0].y || ( P[i].y == P[P0].y && P[i].x > P[P0].x ) )
			P0 = i;

	swap( P[0], P[P0] );

	pivot = P[0];
	sort( ++P.begin(), P.end(), angleCmp );

	vector<point> S;
	S.push_back( P[n-1] ); S.push_back( P[0] );
	i = 1;
	while( i < n ) {
		j = (int)S.size()-1;
		if( ccw( S[j-1], S[j], P[i] ) ) S.push_back( P[i++] );
		else S.pop_back();
	}
	return S;
}

int main() {
	int n, x, y, camadas;
	vector<point> P, S;

	while( scanf( "%d", &n ) && n ) {
		camadas = 0;
		P.clear();
		for( int i=0; i<n; i++ ) {
			scanf( "%d%d", &x, &y );
			P.push_back( point( x, y ) );
		}
		while( P.size() > 2 ) {
			S = CH( P );
			if( area( S ) > 0.0 ) camadas++;
			for( int i=0, j; i<(int)S.size()-1; i++ ) {
				j = 0;
				while( !( S[i] == P[j] ) ) j++;
				P.erase( P.begin()+j );
			}
		}
		printf( "%s\n", camadas&1 ? "Take this onion to the lab!" : "Do not take this onion to the lab!" );
	}

	return 0;
}