#include <cstdio>

int letra[1048577];

int main() {
	int s, n, soma, id, qnt;

	scanf( "%d", &s );
	while( s-- ) {
		qnt = id = soma = 0;
		scanf( "%d", &n );
		for( int i=0; i<n; i++ ) {
			scanf( "%d", &letra[i] );
			soma += letra[i];
			while( soma >= 42 ) {
				if( soma == 42 ) {
					soma = 0;
					qnt++;
					id = i+1;
					break;
				}
				soma -= letra[id++];
			}
		}
		printf( "%d\n", qnt );
	}

	return 0;
}