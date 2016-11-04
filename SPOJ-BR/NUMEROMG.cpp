#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define lli long long int

string base_36( lli n ) {
	string b36( "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" ),
		   n_b36( "" );

	while( n > 0 ) {
		n_b36 += b36[n%36];
		n /= 36;
	}
	reverse( n_b36.begin(), n_b36.end() );

	return n_b36;
}

int main() {
	lli ad, bd;
	string a, b;

	while( cin >> a >> b && ( a != "0" || b != "0" ) ) {
		ad = strtol( (char*)a.c_str(), NULL, 36 );
		bd = strtol( (char*)b.c_str(), NULL, 36 );
		cout << base_36( ad+bd ) << endl;
	}

	return 0;
}