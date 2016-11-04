#include <bits/stdc++.h>
using namespace std;
  
#define INF 100000000.0
  
struct point {
    double x, y;
    point() { x = y = 0.0; }
    point( double _x, double _y ) : x(_x), y(_y) {}
} p[105];
double dist( point p1, point p2 ) { return hypot( p1.x - p2.x, p1.y - p2.y ); }
  
struct vec {
    double x, y;
    vec( double _x, double _y ) : x(_x), y(_y) {}
};
vec toVec( point a, point b ) { return vec( b.x - a.x, b.y - a.y ); }
 
double norm( vec v ) { return sqrt( v.x*v.x + v.y*v.y ); }
double cross( vec a, vec b ) { return a.x*b.y - a.y*b.x; }
 
int main() {
    int n;
    double norma, diff, D;
 
    while( scanf( "%d", &n ) && n ) {       
        diff = INF;     
        for( int i=0; i<n; i++ )
            scanf( "%lf%lf", &p[i].x, &p[i].y );
         
        for( int i=0; i<n; i++ ) {
            for( int j=i+1; j<n; j++ ) {
                vec ab = toVec( p[i], p[j] );
                norma = norm( ab );
                D = 0.0;
 
                for( int k=0; k<n; k++ )
                    D += cross( ab, toVec( p[i], p[k] ) )/norma;
 
                diff = min( diff, abs( D ) );
            }
        }
        printf( "%.3lf\n", diff );  
    }
 
    return 0;
}