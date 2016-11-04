#include <iostream>
using namespace std;

int main() {
	int t = 1;
	long long int custo, p;
	string palavra;

	while( cin >> palavra ) {
		custo = 0;
		p = 1;
		for( int i=palavra.size()-1; i>=0; i--, p <<= 1 )
			if( palavra[i] == 'b' ) custo += p;
		cout << "Palavra " << t++ << endl << custo << endl << endl;
	}

	return 0;
}