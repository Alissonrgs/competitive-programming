#include <iostream>
using namespace std;
 
int main() {
	int m, n, fase = 8;
	string jogador = "ABCDEFGHIJKLMNOP",
	       vencedor1 = "",
	       vencedor2 = "",
	       vencedor3 = "";
	
	for( int i=0; i<16; i+=2 ) {
		cin >> m >> n;
		if( m > n )
			vencedor1 += jogador[ i ];
		else
			vencedor1 += jogador[ i+1 ];
	}
	for( int i=0; i<8; i+=2 ) {
		cin >> m >> n;
		if( m > n )
			vencedor2 += vencedor1[ i ];
		else
			vencedor2 += vencedor1[ i+1 ];
	}
	for( int i=0; i<4; i+=2 ) {
		cin >> m >> n;
		if( m > n )
			vencedor3 += vencedor2[ i ];
		else
			vencedor3 += vencedor2[ i+1 ];
	}
	cin >> m >> n;
	if( m > n )
		cout << vencedor3[ 0 ] << endl;
	else
		cout << vencedor3[ 1 ] << endl;
 
	return 0;
} 