#include <iostream>
using namespace std;

int main() {
	int n;
	bool t;
	string texto, aux;

	cin >> n;
	getline( cin, texto );
	while( n-- ) {
		getline( cin, texto );
		t = true;
		aux = "";
		for( int i=0; i<texto.size(); i++ ) {
			if( texto[i] != ' ' ) {
				if( t )
					aux += texto[i], t = false;
			} else
				t = true;
		}
		cout << aux << endl;
	}

	return 0;
}