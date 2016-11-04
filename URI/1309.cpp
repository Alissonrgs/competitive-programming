#include <bits/stdc++.h>
using namespace std;

int main() {
	int casas;
	string dolares, centavos;

	while( cin >> dolares >> centavos ) {
		casas = dolares.size()%3;
		if( !casas ) casas += 3;
		cout << "$";
		for( int i=0; i<dolares.size(); i++ ) {
			if( i == casas )
				cout << ",", casas += 3;
			cout << dolares[i]; 
		}
		cout << ".";
		if( centavos.size() == 1 ) cout << "0";
		for( int i=0; i<centavos.size(); i++ )
			cout << centavos[i];
		cout << endl;
	}

	return 0;
}