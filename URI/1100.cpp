#include <bits/stdc++.h>
using namespace std;

#define point pair<int,int>
#define x first
#define y second

int dp[10][10];
queue<point> fila; 

int main() {
	string pa, pb;
	point a, b, A, B;

	while( cin >> pa >> pb ) {
		while( !fila.empty() ) fila.pop();
		a = point( (int)( pa[0] - 'a' ), (int)( 8 - ( pa[1] - '0' ) ) );
		b = point( (int)( pb[0] - 'a' ), (int)( 8 - ( pb[1] - '0' ) ) );

		fila.push( a );
		memset( dp, -1, sizeof dp );
		dp[a.x][a.y] = 0;
		while( !fila.empty() ) {
			A = fila.front(), fila.pop();
			if( A == b ) break;

			if( A.x - 1 >= 0 ) {
				if( A.y - 2 >= 0 ) {
					B = point( A.x - 1, A.y - 2 );
					if( dp[B.x][B.y] == -1 ) {
						dp[B.x][B.y] = dp[A.x][A.y] + 1;
						fila.push( B );
					}
				}
				if( A.y + 2 < 8 ) {
					B = point( A.x - 1, A.y + 2 );
					if( dp[B.x][B.y] == -1 ) {
						dp[B.x][B.y] = dp[A.x][A.y] + 1;
						fila.push( B );
					}
				}
			}
			if( A.x + 1 < 8 ) {
				if( A.y - 2 >= 0 ) {
					B = point( A.x + 1, A.y - 2 );
					if( dp[B.x][B.y] == -1 )
						dp[B.x][B.y] = dp[A.x][A.y] + 1, fila.push( B );
				}
				if( A.y + 2 < 8 ) {
					B = point( A.x + 1, A.y + 2 );
					if( dp[B.x][B.y] == -1 )
						dp[B.x][B.y] = dp[A.x][A.y] + 1, fila.push( B );
				}
			}
			if( A.x - 2 >= 0 ) {
				if( A.y - 1 >= 0 ) {
					B = point( A.x - 2, A.y - 1 );
					if( dp[B.x][B.y] == -1 )
						dp[B.x][B.y] = dp[A.x][A.y] + 1, fila.push( B );
				}
				if( A.y + 1 < 8 ) {
					B = point( A.x - 2, A.y + 1 );
					if( dp[B.x][B.y] == -1 )
						dp[B.x][B.y] = dp[A.x][A.y] + 1, fila.push( B );
				}
			}	
			if( A.x + 2 < 8 ) {
				if( A.y - 1 >= 0 ) {
					B = point( A.x + 2, A.y - 1 );
					if( dp[B.x][B.y] == -1 )
						dp[B.x][B.y] = dp[A.x][A.y] + 1, fila.push( B );
				}
				if( A.y + 1 < 8 ) {
					B = point( A.x + 2, A.y + 1 );
					if( dp[B.x][B.y] == -1 )
						dp[B.x][B.y] = dp[A.x][A.y] + 1, fila.push( B );
				}
			}
		}
		cout << "To get from " << pa << " to " << pb << " takes " << dp[b.x][b.y] << " knight moves.\n";
	}

	return 0;
}