#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, pot;

	while( scanf( "%d%d%d", &a, &b, &c ) && a ) {
		pot = a*b*c;
		printf( "%d\n", (int)trunc( pow( (double)pot, 1.0/3.0 ) ) );
	}

	return 0;
}