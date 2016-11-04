#include <bits/stdc++.h>
using namespace std;

int main() {
	int a;

	while( scanf( "%d", &a ) != EOF )
		printf( "%s\n", !( a%6 ) ? "Y" : "N" );

	return 0;
}