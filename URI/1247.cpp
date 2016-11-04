#include <cstdio>
#include <cmath>

int main() {
	int D, VF, VG;
	double d;

	while( scanf( "%d%d%d", &D, &VF, &VG ) != EOF ) {
		d = sqrt( 144 + D*D );
		printf( "%s\n", ( 12.0/VF >= (double)d/VG ? "S" : "N" ) );
	}

	return 0;
}