#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y, volta = 0, distX = 0, distY = 0;

	scanf( "%d%d", &x, &y );
	while( distY - distX < y ) volta++, distX += x, distY+= y;
	printf( "%d\n", volta );

	return 0;
}