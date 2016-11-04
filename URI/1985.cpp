#include <bits/stdc++.h>
using namespace std;

map<int,double> mapa;

int main() {
	int p, id, q;
	double valor = 0.0;

	mapa[1001] = 1.5;
	mapa[1002] = 2.5;
	mapa[1003] = 3.5;
	mapa[1004] = 4.5;
	mapa[1005] = 5.5;

	scanf( "%d", &p );
	for( int i = 0; i < p; i++ )
		scanf( "%d%d", &id, &q ), valor += q*mapa[id];
	printf( "%.2lf\n", valor );

	return 0;
}