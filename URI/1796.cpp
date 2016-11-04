#include <bits/stdc++.h>
using namespace std;

int main() {
	int q, v, qnt = 0;

	scanf( "%d", &q );
	for( int i=0; i<q; i++ ) {
		scanf( "%d", &v );
		qnt += v;
	}
	printf( "%s\n", qnt >= ( q&1 ? q/2 + 1 : q/2 ) ? "N" : "Y" );

	return 0;
}