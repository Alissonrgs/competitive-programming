#include <bits/stdc++.h>
using namespace std;

int marrecos[100005];

int qcm( int m ) {
	if( m <= 3 || marrecos[m] != 0 ) return marrecos[m];
	int c = m/3 + ( m%3 == 1 || m%3 == 2 ? 1 : 0 );
	return marrecos[m] = c + qcm( c );
}

int main() {
	int m;

	memset( marrecos, 0, sizeof marrecos );
	marrecos[0] = 0;
	marrecos[1] = 0;
	marrecos[2] = 1;
	marrecos[3] = 1;
	while( scanf( "%d", &m ) && m )
		printf( "%d\n", qcm( m ) );

	return 0;
}