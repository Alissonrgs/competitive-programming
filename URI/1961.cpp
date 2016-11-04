#include <bits/stdc++.h>
using namespace std;

int main() {
	int p, n, prev, next;
	bool consegue = true;
	
	scanf( "%d%d", &p, &n );
	scanf( "%d", &prev );
	for( int i = 1; i < n; i++ ) {
		scanf( "%d", &next );
		if( abs(prev-next) > p )
			consegue = false;
		prev = next;
	}
	printf( "%s\n", consegue ? "YOU WIN" : "GAME OVER" );

	return 0;
}
