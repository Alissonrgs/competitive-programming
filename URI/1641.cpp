#include <bits/stdc++.h>
using namespace std;

int main() {
	double r, w, l, t = 1;

	while( scanf( "%lf", &r ) && r ) {
		scanf( "%lf%lf", &w, &l );
		r += r;
		printf("Pizza %.0lf %s on the table.\n", t++, ( r >= hypot( w, l ) ? "fits" : "does not fit" ) );
	}

	return 0;
}