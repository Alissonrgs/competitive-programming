#include <bits/stdc++.h>
using namespace std;

int main() {
	int c, n;
	string nome;
	
	cin >> c;
	while( c-- ) {
		cin >> nome >> n;
		cout << ( nome == "Thor" ? "Y" : "N" ) << endl;
	}

	return 0;
}