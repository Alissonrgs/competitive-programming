#include <bits/stdc++.h>
using namespace std;

#define INF (int)1e9

struct robo {
	int xa, ya, xb, yb, xc, yc, d;
	robo() { xa = ya = xb = yb = xc = yc = -1, d = 0; }
	robo( int _xa, int _ya, int _xb, int _yb, int _xc, int _yc, int _d )
		: xa(_xa), ya(_ya), xb(_xb), yb(_yb), xc(_xc), yc(_yc), d(_d) {}
};

int dp[15][15][15][15][15][15], vx[] = { -1, 1, 0, 0 }, vy[] = { 0, 0, -1, 1 };
queue<robo> fila;

int main() {
	int t, n;
	char mapa[15][15];

	scanf( "%d", &t );
	for( int k = 1; k <= t; k++ ) {
		robo R, X;
	 	scanf( "%d", &n );
		for( int j = 0; j <= n+1; j++ ) mapa[0][j] = '#';
		for( int i = 1; i <= n; i++ ) {
			mapa[i][0] = '#';
			for( int j = 1; j <= n; j++ ) {
				scanf( " %c", &mapa[i][j] );
				if( mapa[i][j] == 'A' ) R.xa = i, R.ya = j;
				else if( mapa[i][j] == 'B' ) R.xb = i, R.yb = j;
				else if( mapa[i][j] == 'C' ) R.xc = i, R.yc = j;
				else if( mapa[i][j] == 'X' && X.xa == -1 ) X.xa = i, X.ya = j;
				else if( mapa[i][j] == 'X' && X.xb == -1 ) X.xb = i, X.yb = j;
				else if( mapa[i][j] == 'X' && X.xc == -1 ) X.xc = i, X.yc = j;
			}
			mapa[i][n+1] = '#';
		}
		for( int j = 0; j <= n+1; j++ ) mapa[n+1][j] = '#';

		memset( dp, 0, sizeof dp );
		dp[X.xa][X.ya][X.xb][X.yb][X.xc][X.yc] = INF;
		dp[X.xa][X.ya][X.xc][X.yc][X.xb][X.yb] = INF;
		dp[X.xb][X.yb][X.xa][X.ya][X.xc][X.yc] = INF;
		dp[X.xb][X.yb][X.xc][X.yc][X.xa][X.ya] = INF;
		dp[X.xc][X.yc][X.xa][X.ya][X.xb][X.yb] = INF;
		dp[X.xc][X.yc][X.xb][X.yb][X.xa][X.ya] = INF;

		fila.push( R );
		while( !fila.empty() ) {
			R = fila.front(); fila.pop();
			if( dp[R.xa][R.ya][R.xb][R.yb][R.xc][R.yc] == INF ) break;
			if( !dp[R.xa][R.ya][R.xb][R.yb][R.xc][R.yc] ) {
				dp[R.xa][R.ya][R.xb][R.yb][R.xc][R.yc] = 1;
				dp[R.xa][R.ya][R.xc][R.yc][R.xb][R.yb] = 1;
				dp[R.xb][R.yb][R.xa][R.ya][R.xc][R.yc] = 1;
				dp[R.xb][R.yb][R.xc][R.yc][R.xa][R.ya] = 1;
				dp[R.xc][R.yc][R.xa][R.ya][R.xb][R.yb] = 1;
				dp[R.xc][R.yc][R.xb][R.yb][R.xa][R.ya] = 1;
			} else
				continue;

			R.d++;
			for( int i = 0; i < 4; i++ ) {
				if( mapa[ R.xa + vx[i] ][ R.ya + vy[i] ] == '#' ) mapa[R.xa][R.ya] = '#';
				if( mapa[ R.xb + vx[i] ][ R.yb + vy[i] ] == '#' ) mapa[R.xb][R.yb] = '#';
				if( mapa[ R.xc + vx[i] ][ R.yc + vy[i] ] == '#' ) mapa[R.xc][R.yc] = '#';
				if( mapa[ R.xa + vx[i] ][ R.ya + vy[i] ] != '#' ) {
					if( mapa[ R.xb + vx[i] ][ R.yb + vy[i] ] != '#' ) {
						if( mapa[ R.xc + vx[i] ][ R.yc + vy[i] ] != '#' )
							fila.push( robo( R.xa + vx[i], R.ya + vy[i], R.xb + vx[i], R.yb + vy[i], R.xc + vx[i], R.yc + vy[i], R.d ) );
						else
							fila.push( robo( R.xa + vx[i], R.ya + vy[i], R.xb + vx[i], R.yb + vy[i], R.xc, R.yc, R.d ) );
					} else {
						if( mapa[ R.xc + vx[i] ][ R.yc + vy[i] ] != '#' )
							fila.push( robo( R.xa + vx[i], R.ya + vy[i], R.xb, R.yb, R.xc + vx[i], R.yc + vy[i], R.d ) );
						else
							fila.push( robo( R.xa + vx[i], R.ya + vy[i], R.xb, R.yb, R.xc, R.yc, R.d ) );
					}
				} else {
					if( mapa[ R.xb + vx[i] ][ R.yb + vy[i] ] != '#' ) {
						if( mapa[ R.xc + vx[i] ][ R.yc + vy[i] ] != '#' )
							fila.push( robo( R.xa, R.ya, R.xb + vx[i], R.yb + vy[i], R.xc + vx[i], R.yc + vy[i], R.d ) );
						else
							fila.push( robo( R.xa, R.ya, R.xb + vx[i], R.yb + vy[i], R.xc, R.yc, R.d ) );
					} else
						if( mapa[ R.xc + vx[i] ][ R.yc + vy[i] ] != '#' )
							fila.push( robo( R.xa , R.ya, R.xb, R.yb, R.xc + vx[i], R.yc + vy[i], R.d ) );
				}
				mapa[R.xa][R.ya] = '.';
				mapa[R.xb][R.yb] = '.';
				mapa[R.xc][R.yc] = '.';
			}
		}
		while( !fila.empty() ) fila.pop();
		printf( "Case %d: ", k );
		if( dp[R.xa][R.ya][R.xb][R.yb][R.xc][R.yc] == INF )
			printf( "%d\n", R.d );
		else
			printf( "trapped\n" );
	}

	return 0;
}