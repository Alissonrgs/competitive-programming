#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, m, tempo;
	char c;
	
	while( scanf( "%d %c%d", &h, &c, &m ) != EOF ) {
		tempo = h*60 + m;
		printf( "Atraso maximo: " );
		if( tempo > 8*60 )
			printf( "%d\n", tempo-8*60+60 );
		else
			printf( "%d\n", 8*60-tempo-60 < 0 ? abs(8*60-tempo-60) : 0 );
	}

	return 0;
}
