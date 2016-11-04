#include <iostream>
using namespace std;
 
int main() {
	int n, sa, sb, t=1;
	
	while( cin >> n && n ) {
		sa = sb = 0;
		for( int i=0, a, b; i<n; i++ ) {
			cin >> a >> b;
			sa += a;
			sb += b;
		}
		cout << "Teste " << t++ << endl
			 << ( ( sa > sb )? "Aldo": "Beto" ) << endl << endl;
	}
	return 0; 
} 