#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string jogador[3] = { "Uilton", "Rita", "Ingred" };
	int n, Ui, Ri, Ii, aUi, aRi, aIi, maior, j[3], ji, q;

	while( cin >> n && n ) {
		q = j[0] = j[1] = j[2] = 0;
		while( n-- ) {
			cin >> Ui >> Ri >> Ii;

			aUi = Ui, aRi = Ri, aIi = Ii;
			maior = max( Ui, Ri );
			maior = max( maior, Ii );
			while( !(aUi&1) ) aUi = aUi >> 1;
			while( !(aRi&1) ) aRi = aRi >> 1;
			while( !(aIi&1) ) aIi = aIi >> 1;
			if( Ui != 1 && aUi == 1 ) {
				j[0]++;
				if( Ui == maior ) j[0]++;
			}
			if( Ri != 1 && aRi == 1 ) {
				j[1]++;
				if( Ri == maior ) j[1]++;
			}
			if( Ii != 1 & aIi == 1 ) {
				j[2]++;
				if( Ii == maior ) j[2]++;
			}
		}
		maior = max( j[0], j[1] );
		maior = max( maior, j[2] );
		for( int i=0; i<3; i++ )
			if( j[i] == maior )
				ji = i, q++;
		if( q > 1 )
			cout << "URI\n";
		else
			cout << jogador[ji] << endl;
	}

	return 0;
}