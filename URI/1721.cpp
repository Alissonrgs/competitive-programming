#include <bits/stdc++.h>
using namespace std;

//http://www.informatik.uni-ulm.de/acm/Locals/2000/html/judge.html

struct point {
	double x, y;
	point() { x = y = 0.0; }
	point( double _x, double _y ) : x(_x), y(_y) {}
};

map< string, point > mapa;

double dist( point a, point b ) { return hypot( a.x - b.x, a.y - b.y ); }
double area( point a, point b, point c ) { return 0.5*abs( a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x ); }
double rCircumCircle( point a, point b, point c ) { return dist( a, b )*dist( b, c )*dist( c, a )/( 4.0*area( a, b, c ) ); }

int main() {
	string a, b, c;
	double x, y;
	int parte = 0;

	cout.precision( 0 );
	while( cin >> a ) {
		if( a == "#" ) {
			parte++;
			continue;
		}
		if( parte == 0 ) {
			cin >> x >> y;
			if( !mapa.count( a ) )
				mapa[ a ] = point( x*M_PI*6378.0/180.0, y*M_PI*6378.0/90.0 );
			continue;
		}
		if( parte == 1 ) {
			cin >> b >> c;
			if( mapa.count( a ) && mapa.count( b ) && mapa.count( c ) )
				cout << c << " is " << fixed << rCircumCircle( mapa[a], mapa[b], mapa[c] ) << " km off " << a << "/" << b << " equidistance.\n";
			else
				cout << c << " is ? km off " << a << "/" << b << " equidistance.\n";
			continue;
		}
		parte = 0;
	}

	return 0;
}