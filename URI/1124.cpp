#include <bits/stdc++.h>
using namespace std;

int main() {
	int l, c, r1, r2;
	long double x, y, d;
	bool possivel;

	while( scanf( "%d%d%d%d", &l, &c, &r1, &r2 ) && l ) {
		possivel = false;
		if( 2*r1 <= l && 2*r1 <= c && 2*r2 <= l && 2*r2 <= c ) {
			x = l-r1-r2;
			y = c-r1-r2;
			if( (long double)(r1+r2) <= sqrtl( (long double)(x*x + y*y) ) )
				possivel = true;
		}
		printf( "%s\n", possivel ? "S" : "N" );
	}

	return 0;
}