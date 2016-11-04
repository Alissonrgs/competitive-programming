#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, num, qm, qf, qp, caso = 1;
	char sexo, c;
	bool espaco = false;

	while( scanf( "%d", &n ) != EOF ) {
		printf( "%s", espaco ? "\n" : "" ), espaco = true;
		qm = qf = qp = 0;
		do {
			scanf( "%d %c%c", &num, &sexo, &c );
			if( num == n ) {
				qp++;
				if( sexo == 'M' ) qm++;
				else qf++;
			}
		} while( c != '\n' );
		printf( "Caso %d:\nPares Iguais: %d\nF: %d\nM: %d\n", caso++, qp, qf, qm );
	}

	return 0;
}