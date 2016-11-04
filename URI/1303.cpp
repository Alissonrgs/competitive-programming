#include <bits/stdc++.h>
using namespace std;

struct time {
	int pontos, insc;
	double cestas_m, cestas_r;

	time() { pontos = cestas_m = cestas_r = 0; }
	void clear() { pontos = cestas_m = cestas_r = 0; }
	bool operator<( const time &t ) const {
		if( pontos == t.pontos ) {
			double cesta_average = ( cestas_r ? cestas_m/cestas_r : cestas_m ),
				   t_cesta_average = ( t.cestas_r ? t.cestas_m/t.cestas_r : t.cestas_m );
			if( cesta_average == t_cesta_average ) {
				if( cestas_m == t.cestas_m )
					return insc < t.insc;
				return cestas_m > t.cestas_m;
			}
			return cesta_average > t_cesta_average;
		}
		return pontos > t.pontos;
	}
} t[105];

int main() {
	int n, x, z, inst = 1;
	double y, w;
	bool barraN = false;

	while( scanf( "%d", &n ) && n ) {
		printf( "%s", barraN ? "\n" : "" ), barraN = true;
		for( int i=1; i<=n; i++ ) t[i].clear(), t[i].insc = i;
		for( int i=0; i<n*(n-1)/2; i++ ) {
			scanf( "%d%lf%d%lf", &x, &y, &z, &w );

			if( y > w ) t[x].pontos += 2, t[z].pontos++;
			else t[z].pontos += 2, t[x].pontos++;

			t[x].cestas_m += y;
			t[x].cestas_r += w;
			t[z].cestas_m += w;
			t[z].cestas_r += y;
		}
		sort( t+1, t+n+1 );
		printf( "Instancia %d\n", inst++ );
		bool espaco = false;
		for( int i=1; i<=n; i++ )
			printf( "%s%d", ( espaco ? " " : "" ), t[i].insc ), espaco = true;
		printf( "\n" );
	}

	return 0;
}