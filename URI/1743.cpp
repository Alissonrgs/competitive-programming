#include <iostream>
using namespace std;

int main() {
	bool t[5], p;
	
	while( cin >> t[0] ) {
		p = true;
		for( int i=1; i<5; i++ )
			cin >> t[i];
		for( int i=0, t2; i<5; i++ ) {
			cin >> t2;
			if( t2 == t[i] ) p = false;	
		}
		cout << ( p? "Y": "N" ) << endl;
	}

	return 0;
}
