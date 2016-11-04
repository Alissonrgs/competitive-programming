#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, pontos, mp;
	string time;

	while( cin >> t >> n && t ) {
		mp = 0;
		for( int i=0; i<t; i++ ) {
			cin >> time >> pontos;
			mp += pontos;
		}
		printf( "%d\n", 3*n - mp );
	}

	return 0;
}