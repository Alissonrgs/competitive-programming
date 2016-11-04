#include <iostream>
using namespace std;

int main() {
	int num[9], soma, b1, b2;
	char c;

	while( cin >> c ) {
		num[0] = c - '0';
		for( int i=1; i<9; i++ )
			cin >> c, num[i] = c - '0';
		
		soma = 0;
		for( int i=0, k=1; i<9; i++, k++ )
			soma += k*num[i];
		b1 = soma%11 == 10 ? 0 : soma%11;
		
		soma = 0;
		for( int i=0, k=9; i<9; i++, k-- )
			soma += k*num[i];
		b2 = soma%11 == 10 ? 0 : soma%11;

		for( int i=0; i<9; i++ )
			cout << num[i] << ( i == 2 || i == 5 ? "." : "" );
		cout << "-" << b1 << b2 << endl;
	}

	return 0;
}