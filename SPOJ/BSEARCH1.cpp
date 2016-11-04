#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, q, v[100005];

	scanf( "%d%d", &n, &q );
	for( int i=0; i<n; i++ )
		scanf( "%d", &v[i] );
	sort( v, v+n );

	for( int i=0, query, p; i<q; i++ ) {
		scanf( "%d", &query );
		p = lower_bound( v, v+n, query ) - v;
		printf( "%d\n", ( ( query != v[p] )? -1: p ) );
	}

	return 0;
}