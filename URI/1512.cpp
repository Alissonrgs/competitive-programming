#include <bits/stdc++.h>
using namespace std;

int gcd( int a, int b ) { return b == 0 ? a : gcd( b, a%b ); }
int lcm( int a, int b ) { return a * ( b/gcd( a, b ) ); }

int main() {
	int n, a, b;

	while( scanf( "%d%d%d", &n, &a, &b ) && n )
		printf("%d\n", n/a + n/b - n/lcm( a, b ) );

	return 0;
}