#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, c, v[200005], menor, maior, solucao = 0;

	scanf( "%d%d", &n, &c );
	for( int i=0; i<n; i++ )
		scanf( "%d", &v[i] );

	menor = maior = v[0];
	for( int i=1; i<n; i++ ) {
		if( v[i] > maior ) maior = v[i];
		if( v[i] < maior - c || v[i] < menor )
			solucao += ( maior - menor - c > 0 ? maior - menor - c : 0 ), menor = maior = v[i];
	}
	solucao += ( maior - menor - c > 0 ? maior - menor - c : 0 ); 
	printf( "%d\n", solucao );

	return 0;
}