#include <bits/stdc++.h>
using namespace std;

struct point {
	double x, y;
	point() { x = y = 0.0; }
	point( double _x, double _y ) : x(_x), y(_y) {}
} Pa, Pb, Pc;

struct vec {
	double x, y;
	vec() {}
	vec( double _x, double _y ) : x(_x), y(_y) {}
} V;
vec toVec( point a, point b ) { return vec( b.x - a.x, b.y - a.y ); }

struct reta {
	double a, b;
	reta() {}
	reta( double _x, double _y ) : x(_x), y(_y) {}
} rab, rob, rbc;

int main() {
	double A, B, delta;

	while( scanf( "%lf%lf%lf%lf%lf%lf", &Pa.x, &Pa.y, &V.x, &V.y, &A, &B ) != EOF ) {
		a = V.y/V.x;
		b = Pa.y - a*Pa.x;
		rab = reta( a, b );
		cout << "Y = " << a << "X + " << b << endl;
		
		delta = 4*( A*A*A*A*a*a*b*b - ( B*B + A*A*a*a )*( A*A*b*b - A*A*B*B ) );
		cout << "d: " << delta << endl;

		Pb.x = ( -2*A*A*a*b - sqrt( delta ) ) / ( 2*( B*B + A*A*a*a ) );
		Pb.y = a*Pb.x + b;
		cout << Pb.x << " " << Pb.y << endl;
		
		Pb.x = ( -2*A*A*a*b + sqrt( delta ) ) / ( 2*( B*B + A*A*a*a ) );
		Pb.y = a*Pb.x + b;
		cout << Pb.x << " " << Pb.y << endl;

		a = Pb.y/Pb.x;
		b = 0;
		rob = reta( a, b );
		cout << "Y = " << a << "X + " << b << endl;

		double angle = fabs( ( a - rab.a ) / ( 1 - a*rab ) );
	}

	return 0;
}