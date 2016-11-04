#include <bits/stdc++.h>
using namespace std;
 
#define EPS 1e-9
 
struct point {
    int x, y;
    point() { x = y = 0; }
    point( int _x, int _y ) : x(_x), y(_y) {}
    bool operator==( const point &p ) const { return abs( x - p.x ) == 0 && abs( y - p.y ) == 0; }
} pivot;
double dist( point a, point b ) { return hypot( a.x - b.x, a.y - b.y ); }
 
struct vec {
    double x, y;
    vec( double _x, double _y ) : x(_x), y(_y) {}
};
vec toVec( point a, point b ) { return vec( b.x - a.x, b.y - a.y ); }
double cross( vec a, vec b ) { return a.x*b.y - a.y*b.x; }
bool ccw( point p, point q, point r ) { return cross( toVec( p, q ), toVec( p, r ) ) > 0; }
bool collinear( point p, point q, point r ) { return fabs( cross( toVec( p, q ), toVec( p, r ) ) ) < EPS; }

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
    for( i = 1; i < n; i++ )
        if( P[i].y < P[P0].y || ( P[i].y < P[P0].y && P[i].x >= P[P0].x ) )
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
double perimeter( const vector<point> &P ) {
    double result = 0.0;
    for( int i = 0; i < (int)P.size()-1; i++ )
    	result += dist( P[i], P[i+1] );
    return result;
}

int main() {
	int a, d, x, y;
	vector<point> P;

	while( scanf( "%d%d", &a, &d ) != EOF ) {
        P.clear();
		for( int i = 0; i < a; i++ ) {
			scanf( "%d%d", &x, &y );
			P.push_back( point( x, y ) );
		}
        P = CH( P );
        printf( "%.2lf\n", perimeter( P ) );
	}

	return 0;
}