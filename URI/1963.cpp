#include <bits/stdc++.h>
using namespace std;

int main() {
	double a, b;

	scanf( "%lf%lf", &a, &b );
	printf( "%.2lf%%\n", 100.0*( b - a )/a );

	return 0;
}