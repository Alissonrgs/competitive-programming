#include <cstdio>
#include <cmath>

int v0, k1, k2;

double cal_pontos( double alfa ) {
	double x, y;
	x = pow( v0, 2 )*sin( 2*alfa )/10.0;
	y = pow( v0, 2 )*pow( sin( alfa ), 2 )/( 2*10.0 );
	return x*k1 + y*k2;
}

double buscar_alfa( double inicio, double final ) {
	double alfa = ( inicio + final )/2;
	if( final - inicio < 0.000000001 )
		return alfa;
	if( cal_pontos( inicio ) > cal_pontos( final ) )
		buscar_alfa( inicio, alfa );
	else
		buscar_alfa( alfa, final );
}

int main() {
	int t;
	double alfa;

	scanf( "%d", &t );
	while( t-- ) {
		scanf( "%d%d%d", &v0, &k1, &k2 );
		alfa = buscar_alfa( 0, acos(-1)/2 );
		printf( "%.3lf %.3lf\n", alfa, cal_pontos( alfa ) );
	}

	return 0;
}