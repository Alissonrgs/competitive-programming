#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m[30][30], d, px, py;

	while( cin >> n && n ) {
		px = n/2;
		py = px;
		d = 2;
		memset( m, 0, sizeof m );
		while( true ) {
			m[px][py] = 1;

			for( int i = 0; i < n; i++ ) {
				for( int j = 0; j < n; j++ )
					cout << ( i == px && j == py ? 'X' : 'O' );
				cout << endl;
			}
			cout << "@\n";
			if( px == n-1 && py == n-1 ) break;

			if( d == 0 ) {
				if( !m[px][py-1] )
					py--, d = 1;
				else
					px--;
			
			} else if( d == 1 ) {
				if( !m[px+1][py] )
					px++, d = 2;
				else
					py--;
			
			} else if( d == 2 ) {
				if( !m[px][py+1] )
					py++, d = 3;
				else
					px++;
			
			} else if( d == 3 ) {
				if( !m[px-1][py] )
					px--, d = 0;
				else
					py++;
			}
		}
	}

	return 0;
}