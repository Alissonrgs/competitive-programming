#include <iostream>
#include <algorithm>
using namespace std;

bool ord( int a, int b ) {
	return a > b;
}

int main() {
	int n, m, nota[1005], aux[1005], qnt;

	cin >> n;
	while( n-- ) {
		qnt = 0;
		cin >> m;
		for( int i=0; i<m; i++ )
			cin >> nota[i], aux[i] = nota[i];
		sort( nota, nota+m, ord );
		for( int i=0; i<m; i++ )
			if( nota[i] == aux[i] )
				qnt++;
		cout << qnt << endl;
	}

	return 0;
}