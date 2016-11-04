#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define LSOne(s) ( s & (-s) )

class FenwickTree {
	private:
		vi ft;
	public:
		FenwickTree( int n ) { ft.assign( n + 1, 0 ); }
		int rsq( int b ) {
			int sum = 0;
			for( ; b; b -= LSOne( b ) ) sum += ft[b];
			return sum;
		}
		int rsq( int a, int b ) {
			return rsq( b ) - ( a == 1 ? 0 : rsq( a - 1 ) );
		}
		void adjust( int k, int v ) {
			for( ; k<(int)ft.size(); k += LSOne( k ) )
				ft[k] += v;
		}
};

int main() {
	int n, v;
	char c;

	scanf( "%d", &n );
	FenwickTree ft( n );
	for( int i=0; i<n; i++ )
		scanf( "%d", &v ), ft.adjust( i+1, v );
	while( scanf( " %c%d", &c, &v ) != EOF ) {
		if( c == 'a' )
			ft.adjust( v, -ft.rsq( v, v ) );
		else
			printf( "%d\n", v == 1 ? 0 : ft.rsq( v-1 ) );
	}

	return 0;
}