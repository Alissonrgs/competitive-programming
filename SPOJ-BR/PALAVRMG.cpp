#include <iostream>
#include <cctype>

using namespace std;

bool palavra_ord( string str ) {
	str[0] = tolower( str[0] );
	for( int i=1; i<str.length(); i++ ) {
		str[i] = tolower( str[i] );
		if( str[i-1] >= str[i] )
			return false;
	}
	return true;
}

int main() {
	int P;
	string palavra;

	cin >> P;
	while( P-- && cin >> palavra )
		cout << palavra << ": " << ( palavra_ord( palavra )? 'O': 'N' ) << endl;

	return 0;
}