#include <iostream>
using namespace std;

int main() {
	int n;
	long long qnt, b[55];

	while( cin >> n && n ) {
		qnt = 0;

		for( int i=0; i<n; i++ )
			cin >> b[i];

		for( int i=n-1; i>=0; i-- ) {
			qnt += b[i];
			for( int j=0; j<i; j++ )
				b[j] += b[i];
		}

		cout << qnt << endl;
	}
	
	return 0;
}