#include <bits/stdc++.h>
using namespace std;

int main() {
	long double a, x, y, z;

	while( scanf( "%Lf", &a ) != EOF ) {
		x = a*a*( 1.0 - sqrt( 3.0 )/4.0 - M_PI/6.0 );
		y = a*a*( 1.0 - M_PI/4.0 ) - 2.0*x;
		z = a*a - 4.0*x - 4.0*y;
		printf("%.3Lf %.3Lf %.3Lf\n", z, 4.0*y, 4.0*x );
	}

	return 0;
}