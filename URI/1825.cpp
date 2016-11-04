#include <bits/stdc++.h>
using namespace std;

int comida, trombadas;
double d;

struct point {
	int x, y;
	point( int _x, int _y ) : x(_x), y(_y) {}
	bool operator<( const point &p ) const {
		if( x == p.x ) return y < p.y;
		return x < p.x;
	}
};
map<point,bool> mapa;

bool comer( int x, int y ) {
	d += sqrt( 2.0 );
	if( !mapa.count( point( x, y ) ) )
		mapa[ point( x, y ) ] = true;

	if( mapa[ point( x, y ) ] )
		mapa[ point( x, y ) ] = false, comida++, d = 0.0;
	else
		return 0;
	return 1;
}

int main() {
	int n, m, i, j;
	bool ns, ol;	
	string entrada;

	while( cin >> n >> m >> entrada && n && m ) {
		mapa.clear();
		d = trombadas = comida = 0;

		if( n == 1 && m == 1 ) {
			if( entrada == "Norte" ) cout << "100%         " << trombadas << " Sul\n";
			if( entrada == "Sul" ) cout << "100%         " << trombadas << " Norte\n";
			if( entrada == "Leste" ) cout << "100%         " << trombadas << " Oeste\n";
			if( entrada == "Oeste" ) cout << "100%         " << trombadas << " Leste\n";
			continue;
		}
		if( entrada == "Norte" ) i = j = 1, ns = true, ol = true;
		if( entrada == "Sul" ) i = n, j = m, ns = false, ol = false;
		if( entrada == "Leste" ) i = 1, j = m, ns = true, ol = false;
		if( entrada == "Oeste" ) i = n, j = 1, ns = false, ol = true;

		while( true ) {
			if( !comer( i, j ) ) {
				cout << "Morreu...\n";
				break;
			}
			if( ns ) {
				if( ol ) {
					if( i+1 <= n && j+1 <= m ) i++, j++;
					if( i == n || j == m ) {
						if( !comer( i, j ) ) {
							cout << "Morreu...\n";
							break;
						}
						if( i == n && j == m ) {
							cout << setw(3) << 100*comida/(n*m) << "%         " << trombadas << " Sul\n";
							break;
						}
						if( i == n ) j++, trombadas++, ns = !ns;
						else i++, trombadas++, ol = !ol;
					}

				} else {
					if( i+1 <= n && j-1 >= 1 ) i++, j--;
					if( i == n || j == 1 ) {
						if( !comer( i, j ) ) {
							cout << "Morreu...\n";
							break;
						}
						if( i == n && j == 1 ) {
							cout << setw(3) << 100*comida/(n*m) << "%         " << trombadas << " Oeste\n";
							break;
						}
						if( i == n ) j--, trombadas++, ns = !ns;
						else i++, trombadas++, ol = !ol;
					}
				}

			} else {
				if( ol ) {
					if( i-1 >= 1 && j+1 <= m ) i--, j++;
					if( i == 1 || j == m ) {
						if( !comer( i, j ) ) {
							cout << "Morreu...\n";
							break;
						}
						if( i == 1 && j == m ) {
							cout << setw(3) << 100*comida/(n*m) << "%         " << trombadas << " Leste\n";
							break;
						}
						if( i == 1 ) j++, trombadas++, ns = !ns;
						else i--, trombadas++, ol = !ol;
					}

				} else {
					if( i-1 >= 1 && j-1 >= 1 ) i--, j--;
					if( i == 1 || j == 1 ) {
						if( !comer( i, j ) ) {
							cout << "Morreu...\n";
							break;
						}
						if( i == 1 && j == 1 ) {
							cout << setw(3) << 100*comida/(n*m) << "%         " << trombadas << " Norte\n";
							break;
						}
						if( i == 1 ) j--, trombadas++, ns = !ns;
						else i--, trombadas++, ol = !ol;
					}
				}
			}
		}
	}

	return 0;
}