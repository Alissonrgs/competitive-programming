#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;

	scanf( "%d%d%d", &a, &b, &c );
	if( ( a > b && b <= c ) ||
		( a < b && b < c && b - a <= c - b ) ||
		( a > b && b > c && a - b > b - c ) ||
		( a == b && b < c ) )
		printf( ":)\n" );
	else
		printf( ":(\n" );

	return 0;
}