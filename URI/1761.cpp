#include <bits/stdc++.h>
using namespace std;

#define PI 3.141592654

int main() {
	double a, b, c;

	while( scanf( "%lf%lf%lf", &a, &b, &c ) != EOF )
		printf( "%.2lf\n", 5.0*( b*tan( a*PI/180.0 ) + c ) );

	return 0;
}