#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, q;
	double b, B, area;

	while( scanf( "%d", &t ) && t ) {
		for( int i=1; i<=t; i++ ) {
			scanf( "%d%lf%lf", &q, &b, &B );

			area = q*( b + B )*5.0/2.0;

			printf("Size #%d:\n", i );
			printf("Ice Cream Used: %.2lf cm2\n", area );
		}
		printf( "\n" );
	}

	return 0;
}