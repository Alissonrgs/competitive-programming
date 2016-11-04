#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	string texto, aux1, aux2;

	cin >> n;
	cin.ignore();
	while( n-- ) {
		getline( cin, texto );
		aux1 = string( texto.begin(), texto.begin()+( texto.size()/2 ) );
		reverse( aux1.begin(), aux1.end() );
		aux2 = string( texto.begin()+( texto.size()/2 ), texto.end() );
		reverse( aux2.begin(), aux2.end() );
		cout << aux1 + aux2 << endl;
	}

	return 0;
}