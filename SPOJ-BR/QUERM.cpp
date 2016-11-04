#include <iostream>
using namespace std;
 
int main() {
	int n, v, t=1;
	
	while( cin >> n && n ) {
		for( int i=0, x; i<n; i++ ) {
			cin >> x;
			if( x == i+1 )
				v = i+1;
		}
		cout << "Teste " << t++ << endl
			 << v << endl << endl;
	}
	
	return 0;
} 