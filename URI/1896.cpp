#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, d, h, ac[25], dc[25], hc[25], ta, td, th;
	bool prassodia = false;

	scanf( "%d%d%d%d", &n, &a, &d, &h );
	for( int i=0; i<n; i++ ) {
		scanf( "%d%d%d", &ac[i], &dc[i], &hc[i] );
		if( ac[i] > a || dc[i] > d || hc[i] > h || ( ac[i] == a && dc[i] == d && hc[i] == h ) )
			n--, i--;
	}

	for( int i=1; i<=(1<<n) && !prassodia; i++ ) {
		ta = td = th = 0;
		for( int j=0; j<n && ta <= a && td <= d && th <= h; j++ )
			if( i&(1<<j) )
				ta += ac[j], td += dc[j], th += hc[j];

		if( ta == a && td == d && th == h )
			prassodia = true;
	}
	printf( "%s\n", prassodia ? "Y" : "N" );

	return 0;
}