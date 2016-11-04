#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t, n;
	string str;

	cin >> t;
	while( t-- ) {
		cin >> n >> str;
		if( next_permutation( str.begin(), str.end() ) )
			cout << str << endl;
		else
			cout << "ERROR\n";
	}

	return 0;
}