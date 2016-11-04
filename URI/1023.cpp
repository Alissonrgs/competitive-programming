#include <cstdio>
#include <cmath>
#include <map>
using namespace std;

map<int,int> mapa;
map<int,int>::iterator it;

int main() {
	int n, c = 1, x, y, qP;
	double cM;
	bool espaco, barraN = false;

	while( scanf( "%d", &n ) && n ) {
		printf( "%s", ( barraN ? "\n" : "" ) ), barraN = true;
		espaco = false;
		qP = 0;
		cM = 0.0;

		for( int i=0; i<n; i++ ) {
			scanf( "%d%d", &x, &y );
			qP += x;
			cM += y;
			if( !mapa[ y/x ] )
				mapa[ y/x ] = x;
			else
				mapa[ y/x ] += x;
		}
		printf( "Cidade# %d:\n", c++ );
		for( it = mapa.begin(); it != mapa.end(); it++ )
			printf( "%s%d-%d", ( espaco ? " " : "" ), it->second, it->first ), espaco = true;
		printf( "\nConsumo medio: %.2lf m3.\n", trunc( 100.0*cM/qP )/100.0 );
		mapa.clear();
	}

	return 0;
}