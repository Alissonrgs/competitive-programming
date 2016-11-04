#include <bits/stdc++.h>
using namespace std;

bool check21( int n ) {
	if( n%21 == 0 ) return true;
	
	bool _21 = false;
	while( n ) {
		if( n%100 == 21 ) _21 = true;
		n /= 10;
	}
	return _21;
}

int main() {
	int n, v;
	
	cin >> n;
	for( int i = 0; i < n; i++ ) {
		cin >> v;
		cout << ( check21(v) ? "The streak is broken!" : "The streak lives still in our heart!" ) << endl;
	}
	
    return 0;
}
