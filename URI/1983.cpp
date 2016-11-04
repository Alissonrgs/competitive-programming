#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, id, idM;
	double nota, notaM = 0.0;

	scanf( "%d", &n );
	for( int i = 0; i < n; i++ ) {
		scanf( "%d%lf", &id, &nota );
		if( notaM < nota )
			notaM = nota, idM = id;
	}
	if( notaM < 8.0 )
		printf( "Minimum note not reached\n" );
	else
		printf( "%d\n", idM );

	return 0;
}