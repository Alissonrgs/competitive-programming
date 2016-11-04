#include <cstdio>
#include <cmath> 
using std::abs;

int main() {
	int n, doce[10005], media, min;

	while( scanf( "%d", &n ) && n != -1 ) {
		media = min = 0;
		for( int i=0, d; i<n; i++ ) {
			scanf( "%d", &doce[i] );
			media += doce[i];
		}
		media = ( media%n == 0 )? media/n: -1;
		if( media != -1 ) {
			for( int i=0; i<n; i++ )
				min += abs( media-doce[i] ); 
			printf( "%d\n", min/2 );

		} else
			printf( "-1\n" );
	}

	return 0;
}