#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, _case = 1, total = 0;
	bool space;

	while( scanf( "%d", &n ) != EOF ) {
		total = ((1+n)*n)/2 + 1;
		printf( "Caso %d: %d %s\n0", _case++, total, ( total == 1 ? "numero" : "numeros" ) );
		
		if( total > 1 ) space = true;
		else space = true;
		
		for( int i = 0; i <= n; i++ )
			for( int j = 0; j < i; j++ )
				printf( "%s%d", ( space ? " " : "" ), i ), space = true;

		printf("\n\n");
	}

	return 0;
}