#include <iostream>
using namespace std;

int main() {
	int n, a, ano, tempo;
	string p, planeta;

	while( cin >> n && n ) {
		a = 2115;
		while( n-- ) {
			cin >> planeta >> ano >> tempo;
			if( ano - tempo < a ) a = ano - tempo, p = planeta;
		}
		cout << p << endl;
	}

	return 0;
}