#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
	ll qt, n1, n2;
	string j1, p1, j2, p2;

	scanf( "%lld", &qt );
	while( qt-- ) {
		cin >> j1 >> p1 >> j2 >> p2 >> n1 >> n2;
		if( ( n1 + n2 )&1 )
			p1 == "IMPAR" ? cout << j1 : cout << j2;
		else
			p1 == "PAR" ? cout << j1 : cout << j2;
		cout << endl;
	}

	return 0;
}