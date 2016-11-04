#include <bits/stdc++.h>
using namespace std;

int unionFind[100005], p[100005];

int findSet( int a ) {
	return a == unionFind[a] ? a : unionFind[a] = findSet( unionFind[a] );
}

void unionSet( int a, int b ) {
	a = findSet( a );
	b = findSet( b );
	if( b < a ) swap( a, b );
	unionFind[b] = unionFind[a];
	p[b] += p[a];
	p[a] = p[b];
}

int main() {
	int n, m, q, a, b, r, vr;

	while( scanf( "%d%d", &n, &m ) && n ) {
		vr = 0;
		for( int i=1; i<=n; i++ ) {
			unionFind[i] = i;
			scanf( "%d", &p[i] );
		}
		for( int i=0; i<m; i++ ) {
			scanf( "%d%d%d", &q, &a, &b );
			if( q == 1 )
				unionSet( a, b );
			else {
				r = findSet( 1 );
				a = findSet( a );
				b = findSet( b );
				if( p[a] > p[b] && r == a )
					vr++;
				else if( p[a] < p[b] && r == b )
					vr++;
			}
		}
		printf( "%d\n", vr );
	}

	return 0;
}