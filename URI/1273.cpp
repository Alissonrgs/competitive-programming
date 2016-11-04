#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	int n, maior;
	bool espaco = false;
	string palavra[55];

	while( cin >> n && n ) {
		maior = 0;
		cout << ( espaco ? "\n" : "" ), espaco = true;
		for( int i=0; i<n; i++ ) {
			cin >> palavra[i];
			maior = max( maior, (int)palavra[i].size() );
		}
		for( int i=0; i<n; i++ )
			cout << setw( maior ) << palavra[i] << endl;
	}

	return 0;
}