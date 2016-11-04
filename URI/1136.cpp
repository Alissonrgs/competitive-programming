#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, b, B[95];
	bool bingo[95], possivel;

	while( scanf( "%d%d", &n, &b ) && n ) {
		possivel = true;
		memset( bingo, 0, sizeof bingo );
		for( int i=0; i<b; i++ )
			scanf( "%d", &B[i] ), bingo[ B[i] ] = true;

		for( int i=0; i<b; i++ )
			for( int j=i+1; j<b; j++ )
				bingo[ abs( B[i] - B[j] ) ] = true;
		
		for( int i=0; i<=n; i++ )
			if( !bingo[i] )
				possivel = false;

		printf( "%s\n", possivel ? "Y" : "N" );
	}
	
	return 0;
}