#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, i, j, x, y, d[1005], m, r, t;

	while( scanf( "%d", &n ) && n ) {
		m = t = 0;
		for( i = 0; i < n; i++ )
			scanf( "%d.%d", &x, &y ),
			d[i] = 100*x + y,
			m += d[i];

		sort( d, d+n );
		r = m%n;
		m /= n;
		for( i = n-1, j = 0; i >= 0 && j < r; i--, j++ )
			t += abs( d[i] - ( m + 1 ) );
		for( ; i >= 0 ; i-- )
			t += abs( d[i] - m );
		printf( "$%.2lf\n", t/200.0 );
	}

	return 0;
}