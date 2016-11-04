#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, nota[10005], media, dif, compassos;

	while( scanf( "%d", &n ) != EOF ) {
		media = 0;
		for( int i=0; i<n; i++ )
			scanf( "%d", &nota[i] ), media += nota[i];
		
		media /= n;
		dif = compassos = 0;
		for( int i=0; i<n; i++ ) {
			dif += media - nota[i];
			compassos += abs( media - nota[i] );
		}

		printf( "%d\n", dif ? -1 : compassos/2 + 1 );
	}

	return 0;
}