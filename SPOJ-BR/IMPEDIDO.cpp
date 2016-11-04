#include <cstdio>
#include <algorithm>
using std::sort;

int main() {
	int a, d, menor_da, menor_dd, def[10001], qnt_d;

	while( scanf( "%d%d", &a, &d ) && ( a && d ) ) {
		qnt_d = 0;
		for( int i=0, dist; i<a; i++ ) {
			scanf( "%d", &dist );
			if( i == 0 )
				menor_da = dist;
			else if( dist < menor_da )
				menor_da = dist;
		}
		for( int i=0; i<d; i++ )	
			scanf( "%d", &def[i] );
		sort( &def[0], &def[d] );

		if( menor_da < def[1] )
			printf( "Y\n" );
		else
			printf( "N\n" );
	}

	return 0;
}