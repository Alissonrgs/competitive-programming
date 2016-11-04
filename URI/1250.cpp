#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, t, tiro[55], qnt;
	char kiloman;

	scanf( "%d", &n );
	while( n-- ) {
		qnt = 0;
		scanf( "%d", &t );
		for( int i=0; i<t; i++ )
			scanf( "%d", &tiro[i] );
		for( int i=0; i<t; i++ ) {
			scanf( " %c", &kiloman );
			if( kiloman == 'J' && tiro[i] > 2 ) qnt++;
			else if( kiloman == 'S' && tiro[i] <= 2 ) qnt++;
		}

		printf( "%d\n", qnt );
	}

	return 0;
}