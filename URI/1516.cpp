#include <iostream>
using namespace std;

int main() {
	int n, m, a, b;
	string img[55];

	while( cin >> n >> m && n && m ) {
		for( int i=0; i<n; i++ )
			cin >> img[i];
		cin >> a >> b;
		for( int i=0; i<n; i++ )
			for( int ri=0; ri<a/n; ri++ ) {
				for( int j=0; j<m; j++ )
					for( int rj=0; rj<b/m; rj++ ) {
						cout << img[i][j];
					}
				cout << endl;
			}
		cout << endl;
	}

	return 0;
}