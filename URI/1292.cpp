#include <cstdio>
#include <cmath>

int main() {
	long double f, k = sin(108*M_PI/180.0)/sin(63*M_PI/180.0);

	while( scanf( "%Lf", &f ) != EOF )
		printf( "%.10LF\n", f*k );

	return 0;
}