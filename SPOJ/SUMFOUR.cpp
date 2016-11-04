#include <cstdio>
#include <algorithm>
using namespace std;

int ab[4000*4000], cd[4000*4000];

int main() {
	int n, iab, icd, qnt = 0,
		a[4001], b[4001], c[4001], d[4001];

	scanf( "%d", &n );
	for( int i=0; i<n; i++ )
		scanf( "%d%d%d%d", &a[i], &b[i], &c[i], &d[i] );
	for( int i=0; i<n; i++ )
		for( int j=0; j<n; j++ ) {
			ab[ iab++ ] = a[i] + b[j];
			cd[ icd++ ] = c[i] + d[j];
		}
	n *= n;
	sort( ab, ab+n );
	sort( cd, cd+n );

	for( int i=0, num, l, u; i<n; i++ ) {
		num = -ab[i];
		l = lower_bound( cd, cd+n, num ) - cd;
		u = upper_bound( cd, cd+n, num ) - cd;
		qnt += u-l;
	}
	printf( "%d\n", qnt );
	
	return 0;
}