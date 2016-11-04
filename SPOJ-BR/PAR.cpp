#include <iostream>
using namespace std;
 
int main() {
	int n, t=1;
	string nome[2];
	
	while( cin >> n && n ) {
		cin >> nome[0] >> nome[1];
		cout << "Teste " << t++ << endl;
		
		for( int i=0, x, y; i<n; i++ ) {
			cin >> x >> y;
			x += y;
			cout << ( ( x&1 )? nome[1]: nome[0] ) << endl;
		}
		cout << endl;
	}
	
	return 0; 
} 