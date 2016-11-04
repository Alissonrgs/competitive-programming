#include <bits/stdc++.h>
using namespace std;

int main() {
	double l, area;

	while( scanf( "%lf", &l ) != EOF ) {
		area = l*l*sqrt(3.0)/4.0;
		//area = 12.0*area/81.0
		//q = 4.0/9.0
		printf( "%.2lf\n", area + area/3.0 + 4.0*area/15.0 );
	}

	return 0;
}