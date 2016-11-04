#include <bits/stdc++.h>
using namespace std;

#define vher vector<her>

struct her {
	int h, e, r, lazy;
	her() { h = e = r = lazy = 0; }
	her( int _h, int _e, int _r ) : h(_h), e(_e), r(_r) { lazy = 0; }
	void up( int _h, int _e, int _r ) { h = _h, e = _e, r = _r; }
};

class SegmentTree {
	private:
		vher st;
		int n;
		int left( int p ) { return p << 1; }
		int right( int p ) { return ( p << 1 ) + 1; }

		void build( int p, int L, int R ) {
			if( L == R )
				st[p].h = 1;
			else {
				build( left(p), L, ( L + R )/2 );
				build( right(p), ( L + R )/2 + 1, R );
				st[p].h = st[ left(p) ].h + st[ right(p) ].h;
			}
		}
		void update( int p, int L, int R, int i, int j ) {
			if( st[p].lazy != 0 ) {
				if( L != R ) {
					st[ left(p) ].lazy = ( st[ left(p) ].lazy + st[p].lazy )%3;
					st[ right(p) ].lazy = ( st[ right(p) ].lazy + st[p].lazy )%3;
				}
				while( st[p].lazy )
					st[p].up( st[p].r, st[p].h, st[p].e ), st[p].lazy--;
			}
			if( i > R || j < L ) return;
			if( L >= i && R <= j ) {
				st[p].up( st[p].r, st[p].h, st[p].e );
				if( L != R ) {
					st[ left(p) ].lazy = ( st[ left(p) ].lazy + 1 )%3;
					st[ right(p) ].lazy = ( st[ right(p) ].lazy + 1 )%3;
				}
				return;
			}
			update( left(p), L, ( L+R )/2, i, j );
			update( right(p), ( L+R )/2 + 1, R, i, j );
			her p1 = st[ left(p) ], p2 = st[ right(p) ];


			st[p].up( p1.h + p2.h, p1.e + p2.e, p1.r + p2.r );
		}
		her rmq( int p, int L, int R, int i, int j ) {
			if( i > R || j < L ) return her( -1, -1, -1 );
			if( st[p].lazy != 0 ) {
				if( L != R ) {
					st[ left(p) ].lazy = ( st[ left(p) ].lazy + st[p].lazy )%3;
					st[ right(p) ].lazy = ( st[ right(p) ].lazy + st[p].lazy )%3;
				}
				while( st[p].lazy )
					st[p].up( st[p].r, st[p].h, st[p].e ), st[p].lazy--;
			}
			if( L >= i && R <= j ) return st[p];
			her p1 = rmq( left(p), L, ( L + R )/2, i, j );
			her p2 = rmq( right(p), ( L + R )/2 + 1, R, i, j );
			if( p1.h == -1 ) return p2;
			if( p2.h == -1 ) return p1;

			return her( p1.h + p2.h, p1.e + p2.e, p1.r + p2.r );
		}

	public:
		SegmentTree( int _n ) {
			n = _n;
			st.assign( 4*n, her( 0, 0, 0 ) );
			build( 1, 0, n-1 );
		}
		her rmq( int i, int j ) { return rmq( 1, 0, n-1, i, j ); }
		void update( int i, int j ) { update( 1, 0, n-1, i, j ); }
		void print() {
			for( int i = 1; i < 2*n; i++ ) printf( "%d|%d ", st[i].h, st[i].lazy ); printf( "\n" );
			for( int i = 1; i < 2*n; i++ ) printf( "%d|%d ", st[i].e, st[i].lazy ); printf( "\n" );
			for( int i = 1; i < 2*n; i++ ) printf( "%d|%d ", st[i].r, st[i].lazy ); printf( "\n" );
			printf( "\n" );
		}
};

int main() {
	int n, m, j, k;
	char c;

	while( scanf( "%d%d", &n, &m ) != EOF ) {
		SegmentTree st( n );
		for( int i = 0; i < m; i++ ) {
			scanf( " %c%d%d", &c, &j, &k );
			if( c == 'C' ) {
				her p = st.rmq( j-1, k-1 );
				printf( "%d %d %d\n", p.h, p.e, p.r );
				//st.print();
			
			} else
				st.update( j-1, k-1 );//, st.print();
		}
		printf( "\n" );
	}

	return 0;
}