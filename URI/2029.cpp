#include <bits/stdc++.h>
using namespace std;

int main() {
	double v, d, r, a, h;

	while( scanf( "%lf%lf", &v, &d ) != EOF ) {
		r = d/2.0;
		a = 3.14*r*r;
		h = v/a;
		printf( "ALTURA = %.2lf\nAREA = %.2lf\n", h, a );
	}

	return 0;
}