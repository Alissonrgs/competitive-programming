#include <iostream>
using namespace std;

bool allizzwell;
int n, m;
string azw = "ALLIZZWELL", p[105];

void buscar_azw( int x, int y, int c ) {
	if( allizzwell ) return;
	if( x < 0 || x >= n || y < 0 || y >= m ) return;
	if( p[x][y] != azw[c] ) return;
	if( c == azw.size()-1 ) {
		allizzwell = true;
		return;
	}
	p[x][y] = '.';
	buscar_azw( x, y-1, c+1 );
	buscar_azw( x+1, y-1, c+1 );
	buscar_azw( x+1, y, c+1 );
	buscar_azw( x+1, y+1, c+1 );
	buscar_azw( x, y+1, c+1 );
	buscar_azw( x-1, y+1, c+1 );
	buscar_azw( x-1, y, c+1 );
	buscar_azw( x-1, y-1, c+1 );
	p[x][y] = azw[c];
}

int main() {
	int t;

	cin >> t;
	while( t-- ) {
		allizzwell = false;
		cin >> n >> m;
		for( int i=0; i<n; i++ )
			cin >> p[i];

		for( int i=0; i<n && !allizzwell; i++ )
			for( int j=0; j<m && !allizzwell; j++ )
				buscar_azw( i, j, 0 );

		if( allizzwell ) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}