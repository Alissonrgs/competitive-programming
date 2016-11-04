#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, tomada = 0;

	for( int i = 0; i < 4; i++ ) {
		scanf( "%d", &t );
		tomada += t;
	}
	printf( "%d\n", tomada-3 );
	
	return 0;
}